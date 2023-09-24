#include <stdio.h>

int main() {
#if defined __STDC_VERSION__
    long version = __STDC_VERSION__;
    if (version == 199901L) {
        printf("C99\n");
    } else if (version == 201112L) {
        printf("C11\n");
    } else if (version == 201710L) {
        printf("C18\n");
    }
#else
    printf("C90\n");
#endif
    return 0;
}
