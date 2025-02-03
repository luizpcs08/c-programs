/*This program ...*/

#include <stdio.h>

#define I_BOARD 8
#define J_BOARD 8

//define the type p(piece)
typedef struct{
    int type, x, y;
}p;

int board[I_BOARD][J_BOARD];

void print_board(){
    //loops the board
    for(int i = 0; i <= 7; i++){
        for(int j = 0; j <= 7; j++){

            if(board[i][j] == 0){
                printf("# ");
            }
            else{

            }

        }
        printf("\n");
    }
}

void function_selector(int aux){
    switch(aux){

        case 1:
            tabuleiro_da_paz();
        break;

        default:
    }
}   

void tabuleiro_da_paz(){
    
}

int main(){

    //fill all board spaces with 0
    for(int i = 0; i <= 7; i++){
        for(int j = 0; j <= 7; j++){
            board[i][j] = 0;
        }
    }
    
    printf("
    selecione uma função pra chamar purfavô:\n
    1: tabuleiro da paz\n");

    int aux;
    scanf("%d", &aux);
    

    return 0;
}