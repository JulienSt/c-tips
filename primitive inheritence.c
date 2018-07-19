#include <stdio.h>

#define sA struct A
#define sB struct B

// https://en.wikipedia.org/wiki/Type_punning#Sockets_example

sA{
    int a;
    float b;
};

sB{ //inherits from A
    int a;
    float b;
    int c;
};

int main()
{
    sA bla;
    bla.a = 5;
    bla.b = 4.4;
    
    sB* blubb;
    blubb = (sB*)&bla; // this is where the magic happens
    
    printf("%x \n", blubb->a);
    printf("%f \n", blubb->b);

    return 0;
}
