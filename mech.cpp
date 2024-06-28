
#include <cstdlib>
#include <iostream>
#include <ctime> 
#include "mech.hpp"

using namespace std; 

int two_or_four(){

    srand(time(0));  
    int random=rand()%10;
    if(random<5){
        return 2;
    }
    else{
        return 4;
    }
}

GRID init_grid(){
    GRID inited_grid;
    for (int i(0); i<4; i++){
        for (int j(0); j<4; j++){
            inited_grid.playing_grid[i][j].value=0;
            inited_grid.playing_grid[i][j].coord.x=i;
            inited_grid.playing_grid[i][j].coord.y=j;
        }
    }
    return inited_grid;
}

void rand_cell(GRID* grid){
    srand(time(0));  
    CELL random_cell;
    

    random_cell.coord.x=rand()%4;
    random_cell.coord.y=rand()%4;
    while((grid->playing_grid)[random_cell.coord.x][random_cell.coord.y].value!=0){
        random_cell.coord.x=rand()%4;
        random_cell.coord.y=rand()%4;
    }
    random_cell.value=two_or_four();
    (grid->playing_grid)[random_cell.coord.x][random_cell.coord.y]=random_cell;
}

void print_grid(GRID*grid){
    for (int i(0); i<4; i++){
        for (int j(0); j<4; j++){
            cout << grid->playing_grid[i][j].value << "  ";
        }
        cout << endl;
    }
}