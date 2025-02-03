/*This program ...

For implementing more pacific pieces challenges, need to add
the piece type in check diagonal/horizontal/vertical functions 
conditions*/

#include <stdio.h>
#include <string.h>

#define I_BOARD 8
#define J_BOARD 8
#define P_NAME_MAX 64

//define the type P(piece)
typedef struct{
    int type, x, y;
}P;

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

void end_message(){
    printf("Obrigado por usar! :D\n");
    return;
}

//Gets the piece name using the numeric option that was inserted
//in scanf.
void get_p_name(int aux, char[]* p_name){
    char name[P_NAME_MAX];
    switch aux{

        case 1:
            name = "Dama(s)";
            strcopy(p_name, &name);
        break;
        
        default:
    }
}

/*Receives the board and a piece. Has 2 different outputs:
  1: This piece is not attacking and not being attacked by any 
  other piece in its horizontal line
  0: This piece is attacking or being attacked by other piece
  in its horizontal */ 
int checks_pacific_horizontal(int[][8] board, P p){
    //loops all squares in p horizontal that p is not on
    for(int y = 0; y <= J_BOARD; y++){
        //checks if p is not on the square
        if(y != p.y){
            //checks if there is a piece on the square
            if(board[p.x][y] != 0){
                //checks condition related to output 0
                if( (board[p.x][y] == 1) || (p.type) )
            }

        }

    }

}


//Receives the board and inserts a queen on the first square
//where it doesnt attack any other piece
insert_pacific_q(int[][8] board){

}

void tabuleiro_da_paz(){
    printf("Selecione o tipo da peça:\n 1: Dama\n");

    //stores users input and piece type that will be used
    int aux;
    scanf("%d", &aux);

    //reads user input
    switch(aux){
        case -1: 
            function_selector();
            return;
        break;

        case 0:
        end_message();
        return;
        break;

        case 1:
            printf("Dama?... interessante huahauhauaha\n");
        break;

        default:
            printf("Tá difícil... vou te dar outra chance!\n");
            tabuleiro_da_paz();
            return;
    }

    //gets the P name by using the aux variable and prints 
    //informative text to user
    char p_name[P_NAME_MAX] = get_p_name(aux, &p_name);
    printf("Você quer que o programa insira um número inicial de %s no tabuleiro? Se sim, digite o número desejado. Se não, digite 0.\n Número máximo de %s que podem ser inseridos: \n", get_p_name(aux), get_p_name(aux));
    int n; //stores ammounth of initial pieces that will be on the board
    scanf("%d", &i);

    //fill the board with n ammounth of the choosed piece in a "pacific" way
    for(int i = 0; i < n; i++){
        


    }



}

void function_selector(){

    printf("Selecione uma função pra chamar purfavô:\n (Digite 0 para encerrar o programa)\n 1: tabuleiro da paz\n");

    int aux;
    scanf("%d", &aux);

    //reads user input
    switch(aux){
        case 0:
            end_message();
            return;
        break;

        case 1:
            printf("Esse programa adiciona algumas peças no tabuleiro de xadrez, e pede para que você adicione mais peças de forma que elas não se ataquem.\n (Digite 0 para encerrar o programa e -1 para voltar a seleção de funções)\n");
            tabuleiro_da_paz();
        break;

        default:
            printf("Você não sabe ler? Digita um numéro válido!!\n\n");
            function_selector();
    }
}   

int main(){

    //fill all board spaces with 0
    for(int i = 0; i <= 7; i++){
        for(int j = 0; j <= 7; j++){
            board[i][j] = 0;
        }
    }
    
    function_selector();
    
    return 0;
}