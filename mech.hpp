#ifndef MECH_HPP_INCLUDED
#define MECH_HPP_INCLUDED

typedef struct CELL CELL;
typedef struct GRID GRID;
typedef struct COORD COORD;

struct COORD{
    int x;
    int y;
};


struct CELL{
    int value; //if the cell is empty it contains "0"
    //coordinates of the cell within the grid
    COORD coord;
};

struct GRID{
    CELL playing_grid [4][4];
};

int two_or_four();
GRID init_grid();
void rand_cell(GRID* grid);
void print_grid(GRID*grid);

#endif