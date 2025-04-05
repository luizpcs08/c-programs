#include <stdio.h>
#include <stdlib.h>

#define L 9

//retorna aleatorio x tal que a <= x <= b
int aleatorio(int a, int b){
    return( arc4random_uniform(b - a) + a);
}

int main(){
    int a, b;
    scanf("%d %d", &a, &b);
    printf("%d", aleatorio(a, b));

    return 0;
}
