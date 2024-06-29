
#include <iostream>
#include "mech.hpp"

using namespace std; 

int main(){

    srand(time(0)); 

    GRID test_grid = init_grid();

    rand_cell(&test_grid);
    rand_cell(&test_grid);
    print_grid(&test_grid);

    shift_cell_down(&test_grid);
    print_grid(&test_grid);

    shift_cell_up(&test_grid);
    print_grid(&test_grid);

    shift_cell_left(&test_grid);
    print_grid(&test_grid);

    shift_cell_right(&test_grid);
    print_grid(&test_grid);
    // cout << "x: " << test_grid.playing_grid[1][2].coord.x << "y: " << test_grid.playing_grid[1][2].coord.y << endl;
    // cout << "value: " << test_grid.playing_grid[1][2].value << endl;
    // cout << "2 or 4" << endl << two_or_four() << endl;

    

    return 0;
}