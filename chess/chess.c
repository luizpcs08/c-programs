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



P pieces[(I_BOARD * J_BOARD)];

int n_pieces = 0;

/*Returns a piece pointer by giving its x and y position on the
  board*/
P* get_p(int x, int y){

    //loops pieces vector
    for(int i = 0; i < n_pieces; i++){

        //gets the piece that has the same x and y coordinates
        if( (pieces[i].x == x) && (pieces[i].y == y) ){
            
            return &pieces[i];
        }
    }
}

//Returns 1 if there is a piece on that coordinate; 0 if it doesnt
int check_coordinates(int x, int y){
    //loops pieces vector
    for(int i = 0; i < n_pieces; i++){
        //gets the piece that has the same x and y coordinates
        if( (pieces[i].x == x) && (pieces[i].y == y) ){
             return 1;
        }
    }

    return 0;
}


void print_board(){
    //loops the board
    for(int x = 0; x <= I_BOARD; x++){
        for(int y = 0; y <= J_BOARD; y++){

            if(check_coordinates(x, y)){
                P* p = get_p(x, y);
                switch(p -> type){
                    case 1: 
                        printf("Q ");
                    break;

                    default:
                        printf("! ");
                }
            }
            else{
                printf("# ");
            }

        }
        printf("\n");
    }
    printf("\n\n");
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

/*Returns the attack type of a piece by receiving a piece.
  Can have 3 outputs
  1: diagonal attack only (bishop)
  2: vertical and horizontal attack (rook)
  3: type 1 and 2 (queen)*/
int attack_type(P p){
    switch (p.type){

    case 1:
        return 3;
    break;
    
    default:
        printf("Error: couldnt identify piece attack type\n");
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

        //guarantees that p1 is to the left of p2
        if(p1.y > p2.y){
            P aux = p1;
            p1 = p2;
            p2 = aux;
        }

        //checks if the path between p1 and p2 is clear
        for(int y = p1.y + 1; y < p2.y; y++){
            
            //if there is a piece blocking the attack, return 0
            if(check_coordinates(p1.x, y)){
                return 0;
            }

        }

        return 1;

    }
    else{
        return 0;
    }
}

/*Checks if piece 1 can attack piece two in its vertical
  Returns 1 if piece 1 can attack piece 2 and 0 if it cant attack*/
int vertical_attack(P p1, P p2){

    //checks if they are in the same y coordinate and if p1 
    //can attack vertically
    if((p1.y == p2.y) && (attack_type(p1) > 1)){

        //guarantees that p1 is above p2
        if(p1.x > p2.x){
            P aux = p1;
            p1 = p2;
            p2 = aux;
        }

        //checks if the path between p1 and p2 is clear
        for(int x = p1.x + 1; x < p2.x; x++){
            
            //if there is a piece blocking the attack, return 0
            if(check_coordinates(x, p1.y)){
                return 0;
            }

        }

        return 1;

    }
    else{
        return 0;
    }
}


/*Checks if piece 1 can attack piece two in its diagonal
  Returns 1 if piece 1 can attack piece 2 and 0 if it cant attack*/
int diagonal_attack(P p1, P p2){

    //calculates the rise and run of p1 and p2 coordinates 
    int rise = p1.y - p2.y;
    int run = p1.x - p2.x;
    int slope = 0;

    //calculates slope if run is not 0 (avoiding errors)
    if(run != 0){
        slope = rise/run;
    }

    //checks if p1 and p2 are in the same diagonal and if p1 
    //can attack diagonally
    if( (slope == 1 || slope == -1) && (attack_type(p1) == 3 || attack_type(p1) == 1) ){
        
        //guarantees that p1 is to the left of p2
        if(p1.y > p2.y){
            P aux = p1;
            p1 = p2;
            p2 = aux;
        }

        //checks if the path between p1 and p2 is clear
        for(int x = p1.x + slope, y = p1.y + 1; y < p2.y; x += slope, y++){
                
            //if there is a piece blocking the attack, return 0
            if(check_coordinates(x, y)){
                return 0;
            }

        }
        return 1;

        }
        else{
            return 0;
    }
}


/*Receives two pieces. Has 2 different outputs:
  1: Piece 1 can attack piece 2.
  0: Piece 1 cannot attack piece 2
  Note: Does not specify how piece 1 can attack piece 2 
  (horizontal, diagonal or vertical) */ 
int check_attack(P p1, P p2){
    return( vertical_attack(p1, p2) ||
            horizontal_attack(p1, p2)||
            diagonal_attack(p1, p2) );
}

/*Receives a pointer of a piece and move it to new coordinates*/
void move_p(P* p, int x, int y){
    p -> x = x;
    p -> y = y;
    return;

}

/*Deletes a piece from pieces vector and board matrix*/
void delete_p(P* p){
    p -> type = 0;
    return;
}

/*Receives coordinates of a square and piece type. Returns
  if the square is pacific to the piece that is there. 
  Outputs:
  0 - Piece can attack or is being attacked
  1 - piece is on a pacific square*/
int check_pacific_square(P* p){

    //loops all pieces
    for(int i = 0; i < n_pieces; i++){
        
        //checks if the selected piece exists and its not the same address
        if( (pieces[i].type != 0) && (&pieces[i] != p) ){

            //checks if this piece can attack or be attacked
            if(check_attack(*p, pieces[i]) || check_attack(pieces[i], *p)){
                return 0;
               }
            
        }
    }
    
    //if the program didnt find any piece that satisfy condition
    //related to output 0, returns 1
    return 1;

}

/*Recursive function
  Insert 8 queens on the board in a way that they dont attack
  themselves
  x parameter stores the row that a queen will be inserted,
  moved or deleted*/
void insert_pacific_q(int x){
    printf("Função chamada para x = %d\n",x);

    //base case
    if(x == I_BOARD){
        return;
    }
   
    //Gets piece of the row or creates it if it doesnt exists
    P* p = &pieces[x];

    if(p -> type == 0){
        p -> x = x;
        p -> y = -1;
        p -> type = 1;
    }

    //loops squares to the right of p
    for(int y = (p -> y) + 1; y <= J_BOARD; y++){

        //if overflow, go to previous line
        if(y == J_BOARD){
            delete_p(p);
            n_pieces--;
            printf("peça em x = %d deletada\n", x);
            insert_pacific_q(x - 1);
            return;
        }

        move_p(p, x, y);

        //try to moves queen to next possible square on the row
        if(check_pacific_square(p)){
            printf("peça em x = %d movida para y = %d\n", x, p -> y);
            n_pieces++;
            insert_pacific_q(x + 1);
            return;
        }

        
    }
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
    printf("Inserindo o máximo de %s possível \n", p_name);

    //call insert function and print board
    insert_pacific_q(0);
    print_board();

    printf("Selecione a próxima ação:\n1: Voltar ao seletor de funções\n0: Encerrar programa\n");
    scanf("%d", &aux);

    switch(aux){
        case 1:
            function_selector();
            return;
        break;

        case 0:
            end_message();
            return;
        break;

        default:
            return;
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

    //fill all pieces vector with type 0 pieces (empty)
    for(int i = 0; i < I_BOARD * J_BOARD; i++){
        P p = {.type = 0};
        pieces[i] = p;
    }
    
    function_selector();
    
    return 0;
}