#include <stdio.h>

// https://en.wikipedia.org/wiki/Type_punning#Sockets_example

typedef struct{
    int a;
    float b;
}A;

typedef struct{ //inherits from A
    int a;
    float b;
    int c;
}B;

int main()
{
    A bla;
    bla.a = 5;
    bla.b = 4.4;
    
    B* blubb;
    blubb = (B*)&bla; // this is where the magic happens
    
    printf("%x \n", blubb->a);
    printf("%f \n", blubb->b);

    return 0;
}
