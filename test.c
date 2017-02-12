#include <stdio.h>

#define GET_INT(...)    int __VA_ARGS__

int main(void)
{
    GET_INT(a, b, c = 2, d, e, f, g);
}