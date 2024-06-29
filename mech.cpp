
#include <cstdlib>
#include <iostream>
#include <ctime> 
#include "mech.hpp"

using namespace std; 

int two_or_four(){
 
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
    cout << endl;
}

void shift_cell_down(GRID* grid){
    int move;
    do {
        move = 0;
        for (int i = 2; i >= 0; i--) {
            for (int j = 0; j < 4; j++) {
                if (grid->playing_grid[i+1][j].value == 0 && grid->playing_grid[i][j].value != 0) {
                    grid->playing_grid[i+1][j].value = grid->playing_grid[i][j].value;
                    grid->playing_grid[i][j].value = 0;
                    move++;
                }
                else if (grid->playing_grid[i+1][j].value == grid->playing_grid[i][j].value && grid->playing_grid[i][j].value != 0) {
                    grid->playing_grid[i+1][j].value *= 2;
                    grid->playing_grid[i][j].value = 0;
                    move++;
                }
            }
        }
    } while (move != 0);
    rand_cell(grid);
}

void shift_cell_up(GRID* grid){
    int move;
    do {
        move = 0;
        for (int i = 1; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                if (grid->playing_grid[i-1][j].value == 0 && grid->playing_grid[i][j].value != 0) {
                    grid->playing_grid[i-1][j].value = grid->playing_grid[i][j].value;
                    grid->playing_grid[i][j].value = 0;
                    move++;
                }
                else if (grid->playing_grid[i-1][j].value == grid->playing_grid[i][j].value && grid->playing_grid[i][j].value != 0) {
                    grid->playing_grid[i-1][j].value *= 2;
                    grid->playing_grid[i][j].value = 0;
                    move++;
                }
            }
        }
    } while (move != 0);
    rand_cell(grid);
}

void shift_cell_left(GRID* grid){
    int move;
    do {
        move = 0;
        for (int i = 0; i < 4; i++) {
            for (int j = 1; j < 4; j++) {
                if (grid->playing_grid[i][j-1].value == 0 && grid->playing_grid[i][j].value != 0) {
                    grid->playing_grid[i][j-1].value = grid->playing_grid[i][j].value;
                    grid->playing_grid[i][j].value = 0;
                    move++;
                }
                else if (grid->playing_grid[i][j-1].value == grid->playing_grid[i][j].value && grid->playing_grid[i][j].value != 0) {
                    grid->playing_grid[i][j-1].value *= 2;
                    grid->playing_grid[i][j].value = 0;
                    move++;
                }
            }
        }
    } while (move != 0);
    rand_cell(grid);
}

void shift_cell_right(GRID* grid){
    int move;
    do {
        move = 0;
        for (int i = 0; i < 4; i++) {
            for (int j = 2; j >=0; j--) {
                if (grid->playing_grid[i][j+1].value == 0 && grid->playing_grid[i][j].value != 0) {
                    grid->playing_grid[i][j+1].value = grid->playing_grid[i][j].value;
                    grid->playing_grid[i][j].value = 0;
                    move++;
                }
                else if (grid->playing_grid[i][j+1].value == grid->playing_grid[i][j].value && grid->playing_grid[i][j].value != 0) {
                    grid->playing_grid[i][j+1].value *= 2;
                    grid->playing_grid[i][j].value = 0;
                    move++;
                }
            }
        }
    } while (move != 0);
    rand_cell(grid);
}