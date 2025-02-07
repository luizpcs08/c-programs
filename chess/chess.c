/*my first backtracking program :D

  The initial idea of this program was to code some chess problems
  solutions, in a way that user could select which problem would
  be solved.
  
  But at the end, I've just code the N_Queen problem. Because of 
  it, I've made the stuct of the code in a way that inserting
  new piece types or new problems would be easier*/

#include <stdio.h>
#include <string.h>

#define I_BOARD 8
#define J_BOARD 8

//define the type P(piece)
typedef struct{
    int type, x, y;
}P;

P pieces[I_BOARD];
int n_pieces;

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

    //If the piece couldnt be found (some error happened)
    printf("ERROR: piece couldnt be find in get_p function\n");
    return &(P) {.type = -1};
}

//Returns 1 if there is a piece on that coordinate; 0 if there isnt
int check_coordinates(int x, int y){
    //loops pieces vector
    for(int i = 0; i < n_pieces; i++){

        if( (pieces[i].x == x) && (pieces[i].y == y) ){
             return 1;
        }
    }

    return 0;
}


void print_board(){
    //loops the board
    for(int x = 0; x < I_BOARD; x++){
        for(int y = 0; y < J_BOARD; y++){

            if(check_coordinates(x, y)){
                printf("Q ");
            }
            else{
                printf("# ");
            }

        }
        printf("\n");
    }
    printf("\n\n");
}

//Gets the piece name stores it in p_name parameter.
void get_p_name(int aux, char p_name[]){
    switch (aux){

        case 1:
            strcpy(p_name, "Dama(s)");
        break;
        
        default:
    }
}

/*Returns 1 if piece 1 can attack piece 2 in its horizontal*/
int horizontal_attack(P p1, P p2){

    //checks if they are in the same x
    if(p1.x == p2.x){

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

/*Returns 1 if piece 1 can attack piece 2 in its vertical*/
int vertical_attack(P p1, P p2){

    //checks if they are in the same y coordinate 
    if(p1.y == p2.y){

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


/*Returns 1 if piece 1 can attack piece 2 in its diagonal*/
int diagonal_attack(P p1, P p2){

    //calculates the rise and run of p1 and p2 coordinates 
    int rise = p1.y - p2.y;
    int run = p1.x - p2.x;
    int slope = 0;

    //calculates slope 
    if(run != 0 && rise % run == 0){
        slope = rise/run;
    }

    //checks if p1 and p2 are in the same diagonal and if p1 
    //can attack diagonally
    if(slope == 1 || slope == -1){
        
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


/*Returns 1 if piece 1 can attack piece 2 in some way*/
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

/*Returns 1 if a piece on a square cannot attack or be attacked by any other piece*/
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

    return 1;
}

//fill all pieces vector with type 0 pieces (empty)
void place_pieces(){
    n_pieces = 0;
    for(int i = 0; i < I_BOARD * J_BOARD; i++){
        P p = {.type = 0, .y = -1};
        pieces[i] = p;
    }
}

/*Recursive function that solves N queen problem*/
void problem_solver(int x){

    //base case
    if(x == I_BOARD){
        printf("A solution was found!\n\n");
        return;
    }
    else if(x < 0){
        printf("ERROR: a new solution couldnt be founded.\nRestarting the board...\n\n");
        place_pieces();
        problem_solver(0);
        return;
    }
   
    //Gets piece of the row or creates it if it doesnt exists
    P* p = &pieces[x];
    p -> x = x;

    if(p -> type == 0){
        p -> y = -1;
        p -> type = 1;
    }
    

    //loops squares on the x row
    for(int y = (p -> y) + 1; y <= J_BOARD; y++){

        //if overflow, go to previous line
        if(y == J_BOARD){
            delete_p(p);
            n_pieces--;
            problem_solver(x - 1);
            break;
        }

        move_p(p, x, y);

        //try to moves queen to next possible square on the row
        if(check_pacific_square(p)){
            n_pieces++;
            problem_solver(x + 1);
            break;
        }
    }
}

void n_queen_problem(int x){
    printf("Solving N queen problem...\n");
    problem_solver(x);
}

int main(){
    place_pieces();
    
    int check = 0;
    do{
        printf("Solving N_Queen problem...\n");
        (check == 0) ? problem_solver(0) : problem_solver(I_BOARD - 1);
        print_board();
        printf("Do you want another solution? (Type 1 or 0))\n");
        scanf("%d", &check);
    }
    while (check);

    printf("Thank you for using my code! ;D\n");
    return 0;
}