/******************************************************************************
https://blog.noctua-software.com/c-lambda.html
*******************************************************************************/

#include <stdio.h>
#define LAMBDA(c_) ({ c_ _;})

void func(int nb, void (*f)(int)) {
    int i;
    for (i = 0; i < nb; i++) f(i);
}

int main()
{
    func(4, 
         LAMBDA(
             void _(int v){
                printf("%d\n", v);
                
             }
         )
    );
    
    func(4, 
         LAMBDA(
             void _(int v){
                v += 15;
                printf("%d\n", v);
             }
         )
    );
    
}