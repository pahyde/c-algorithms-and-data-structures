#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>

typedef struct BufHdr {
    size_t len;
    size_t cap;
    char buf[0];
} BufHdr;

#define max(a,b) (a > b ? a : b)

#define buf__hdr(b) ((BufHdr *)((char *)b - offsetof(BufHdr, buf)))
#define buf__fits(b,n) (buf_len(b) + n <= buf_cap(b))
#define buf__fit(b,n) (buf__fits(b,n) ? 0 : (b = buf__grow(b,buf_len(b) + n,buf_cap(b), sizeof(*b))))

#define buf_len(b) (b ? buf__hdr(b)->len : 0)
#define buf_cap(b) (b ? buf__hdr(b)->cap : 0)
#define buf_push(b,x) (buf__fit(b,1), b[buf_len(b)] = x, (buf__hdr(b)->len)++)
#define buf_free(b) (b ? free(buf__hdr(b)) : 0)

void *buf__grow(const void *b, size_t new_len, size_t cap, size_t elem_size) {
    size_t new_cap = max(cap * 2 + 1, new_len);
    size_t new_size = offsetof(BufHdr, buf) + new_cap * elem_size;
    BufHdr *new_bufh;
    if (b) {
        new_bufh = realloc(buf__hdr(b), new_size);
    } else {
        new_bufh = malloc(new_size);
        new_bufh->len = 0;
    }
    new_bufh->cap = new_cap;
    return new_bufh->buf;
}

void buf_show(const int *b) {
    for (int i = 0; i < buf_len(b) - 1; i++) 
      printf("%d, ", b[i]);
    printf("%d\n", b[buf_len(b) - 1]);
}

int main() {
    int *buf = NULL;
    
    //push ints 0 - 10 to buffer
    for (int i = 0; i < 10; i++) buf_push(buf, i);
    
    //buffer is now: 0, 1, 2, 3, 4, 5, 6, 7, 8, 9
    buf_show(buf);

    buf_free(buf);
}