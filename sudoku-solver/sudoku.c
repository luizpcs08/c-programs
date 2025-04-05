#include <stdio.h>
#include <stdlib.h>

#define L 9

int board[L][L];

//retorna aleatorio x tal que a <= x <= b
int aleatorio(int a, int b){
    return( arc4random_uniform(b - a) + a);
}

//retorna 1 se o inteiro 'a' pode ser inserido em board[i][j]
int testa_insercao(int a, int i, int j){

    //testa se *p está vazio
    if(board[i][j] != -1){
        return 0;
    }

    //testa area do quadrado 3x3
    for(int i0 = i - (i%3); i0 <= i + (2 - i%3); i0++) {

        for(int j0 = j - (j%3); j0 <= j + (2 - j%3); j0++){
            
            if( (i0 != i || j0 != j) && board[i0][j0] == a ){
                return 0;
            }
        }
    }

    //testa coluna acima do quadrado 3x3
    for(int i0 = i -1 -(i%3); i0 >=0; i0--){

        if(board[i0][j] == a){
            return 0;
        }
    }
    
    //testa coluna abaixo do quadrado 3x3
    for(int i0 = i +(3 - i%3); i0 < L; i0++){

        if(board[i0][j] == a){
            return 0;
        }
    }

    //testa linha na esquerda do quadrado 3x3
    for(int j0 = j - 1-(j%3); j0 >= 0; j0--){

        if(board[i][j0] == a){
            return 0;
        }
    }

    //testa linha na direita do quadrado 3x3
    for(int j0 = j + (3 - j%3); j0 < L; j0++){

        if(board[i][j0] == a){
            return 0;
        }
    }

    return 1;
}

//tenta inserir uma dica em board. Se conseguir, retorna 1
int inserir_dica(){

    int dica = aleatorio(1, 9);
    int i = aleatorio(0, L);
    int j = aleatorio(0, L);

    if(testa_insercao(dica, i, j)){
        board[i][j] = dica;
        return 1;
    }
    else{
        return 0;
    }
}

void printa_tabuleiro(){
    for(int i = 0; i < L; i++){

        for(int j = 0; j < L; j++){
            board[i][j] == -1 ? printf("# ") : printf("%d ", board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int main(){

    printf("Criando tabuleiro...\n");
    //inicializa board com -1
    for(int i = 0; i < L; i++){
        
        for(int j = 0; j < L; j++){
            board[i][j] = -1;
        }  
    }

    int n_dicas = aleatorio(17, 30);

    printf("Inserindo %d dicas...\n", n_dicas);
    int cont = 0, testes = 0;
    while(cont <  n_dicas){

        inserir_dica() ? cont++ : testes++;

    }
    testes += cont;
    
    printf("Inserido %d dicas após %d testes\n\n", n_dicas, testes);
    printa_tabuleiro();

}
