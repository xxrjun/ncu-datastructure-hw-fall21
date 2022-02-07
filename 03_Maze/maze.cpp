#include <iostream>
#define MAX_STACK_SIZE 1001
#define SIZE 1001
using namespace std;

typedef struct{
    long long int vert;
    long long int horiz;
}offsets;

offsets moves[4];

typedef struct{
    long long int row;
    long long int col;
    long long int dir;
}elements;

elements stack[MAX_STACK_SIZE];
long long int top = 0;

void read_maze(int maze[][SIZE], int mark[][SIZE], long long int row, long long int col);
void path(int maze[][SIZE], int mark[][SIZE], long long int EXIT_ROW, long long int EXIT_COL);
void add(elements position);
elements pop();

int maze[SIZE][SIZE];
int mark[SIZE][SIZE];

int main(){

    moves[0].vert = -1;
    moves[0].horiz = 0;
    moves[1].vert = 0;
    moves[1].horiz = 1;
    moves[2].vert = 1;
    moves[2].horiz = 0;
    moves[3].vert = 0;
    moves[3].horiz = -1;
    int row = 0, col = 0;
    
    cin >> row >> col;
    read_maze(maze, mark, row, col);
    path(maze, mark, row, col);

}

void path(int maze[][SIZE], int mark[][SIZE], long long int EXIT_ROW, long long int EXIT_COL){
    int row, col, next_row, next_col, dir;
    elements position;
    mark[1][1] = 1;
    bool found = false;
    top = 0;
    stack[0].row = 1, stack[0].col = 1, stack[0].dir = 1;

    while(top > - 1 && !found){
        position = pop();
        row = position.row; 
        col = position.col;
        dir = position.dir;
        while(dir < 4 && !found){
            next_row = row + moves[dir].vert;
            next_col = col + moves[dir].horiz;
            if(next_row == EXIT_ROW && next_col == EXIT_COL){
                found = true;
            }
            else if (!maze[next_row][next_col] && !mark[next_row][next_col]){
                mark[next_row][next_col] = 1;
                position.row = row;
                position.col = col;
                position.dir = ++dir;
                add(position);
                row = next_row; col = next_col; dir = 0;
            }
            else
                ++dir;
        }
    }

    if(found){
        for(int i = 0 ; i <= top ; i++){
            cout << "(" << stack[i].row - 1<< "," << stack[i].col - 1<< ") ";
        }
        cout << "(" << row - 1<< "," << col - 1<< ") ";
        cout << "(" << EXIT_ROW - 1<< "," << EXIT_COL - 1<< ")" << endl;
    }
    else{
        cout << "Can't reach the exit!" << endl;
    }
}

elements pop(){
    return stack[top--];
}

void add(elements position){
    stack[++top].row = position.row;
    stack[top].col = position.col;
    stack[top].dir = position.dir;
}

void read_maze(int maze[][SIZE], int mark[][SIZE], long long int row, long long int col){
    for(int i = 0 ; i < col + 2 ; i++){
        maze[0][i] = 1;
        maze[row + 1][i] = 1;

        mark[0][i] = 1;
        mark[row + 1][i] = 1;
    }
    for(int i = 1 ; i < row + 1; i++){
        maze[i][0] = 1;
        maze[i][col + 1] = 1;

        mark[i][0] = 1;
        mark[i][col + 1] = 1;
    }

    for(int i = 1 ; i <= row ; i++){
        for(int j = 1 ; j <= col ; j++){
            cin >> maze[i][j];
            mark[i][j] = maze[i][j];
        }
    }
}