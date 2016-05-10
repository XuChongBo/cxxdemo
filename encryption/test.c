#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#define _XOPEN_SOURCE

int main(void)
{
    char *passwd;
    char key[] = "123456";
    passwd = crypt(key, "$6$y9cP0qlmDYgBk6OZ$");
    printf("password: %s\n", passwd);
    return 0;
}

