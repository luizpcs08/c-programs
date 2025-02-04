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

//global matrix for board
int board[I_BOARD][J_BOARD];

//global vector for storing pieces
P pieces[(I_BOARD * J_BOARD)];

//global variable for pieces vector size
int n_pieces = 0;

/*Returns a piece by giving its x and y position on the
  board*/
P get_p(int x, int y){

    //loops pieces vector
    for(int i = 0; i < n_pieces; i++){

        //gets the piece that has the same x and y coordinates
        if( (pieces[i].x == x) && (pieces[i].y == y) ){
            return pieces[i];
        }

    }

}


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
//in scanf and stores it in p_name parameter.
void get_p_name(int aux, char p_name[]){
    switch (aux){

        case 1:
            strcpy(p_name, "Dama(s)");
        break;
        
        default:
    }
}

/*Returns the attack type of a piece. Can have 3 outputs
  1: diagonal attack only (bishop)
  2: vertical and horizontal attack (rook)
  3: type 1 and 2 (queen)*/
int attack_type(P p){
    switch (p.type){

    case 1:
        return 3;
    break;
    
    default:
        //
    break;
    }

    return 0;
}

/*Checks if piece 1 can attack piece two in its horizontal
  Returns 1 if piece 1 can attack piece 2*/
int horizontal_attack(P p1, P p2){

    //checks if they are in the same x coordinate and if p1 
    //can attack horizontally
    if((p1.x == p2.x) && (attack_type(p1) > 1)){

        //guarantees that p1 is on the left
        if(p1.y > p2.y){
            P aux = p1;
            p1 = p2;
            p2 = aux;
        }

        //checks if the path between p1 and p2 is clear
        for(int y = p1.y + 1; y < p2.y; y++){
            
            //if there is a piece blocking the attack, return 0
            if(board[p1.x][y] != 0){
                return 0;
            }

        }

        //if the path is clear, returns 1
        return 1;

    }
    else{
        return 0;
    }
}


/*Receives the board and a piece. Has 2 different outputs:
  1: This piece is not attacking and not being attacked by any 
  other piece in its horizontal line
  0: This piece is attacking or being attacked by other piece
  in its horizontal */ 
int checks_pacific_horizontal(int board[][8], P p){

}




//Receives the board and inserts a queen on the first square
//where it doesnt attack any other piece
void insert_pacific_q(int board[][8]){

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

    //gets the P name by using the aux variable
    char p_name[P_NAME_MAX];
    get_p_name(aux, p_name);

    //prints informative text to user 
    printf("Você quer que o programa insira um número inicial de %s no tabuleiro? Se sim, digite o número desejado. Se não, digite 0.\n Número máximo de %s que podem ser inseridos: \n", p_name, p_name);
    int n; //stores ammounth of initial pieces that will be on the board
    scanf("%d", &n);

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