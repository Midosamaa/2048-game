
#include <iostream>
#include "mech.hpp"

using namespace std; 

int main(){

    srand(time(0)); 

    GRID test_grid = init_grid();

    rand_cell(&test_grid);
    rand_cell(&test_grid);
    print_grid(&test_grid);

    char move;
    cout << "what is your move?" << endl;
    scanf("%c", &move);
    while(ongoing_game(&test_grid)){
        if (move == 'w'){
            shift_cell_up(&test_grid);
            print_grid(&test_grid);

        }
        else if (move == 'a'){
            shift_cell_left(&test_grid);
            print_grid(&test_grid);        
        }
        else if (move == 's'){
            shift_cell_down(&test_grid);
            print_grid(&test_grid);
        }
        else if (move == 'd'){
            shift_cell_right(&test_grid);
            print_grid(&test_grid); 
        }
        else{
            cout << "please enter a valid direction (wasd)" << endl;
        }
        scanf("%c", &move);
    }
    print_grid(&test_grid);
    cout << "game over!" << endl;
    return 0;
}