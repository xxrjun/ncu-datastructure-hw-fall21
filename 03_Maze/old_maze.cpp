#include <iostream>
#define SIZE 100
using namespace std;

typedef struct{
    int x;
    int y;
}Point;

Point pt(int x, int y){
    Point p = {x, y};
    return p;
}

void read_maze(int maze[][SIZE], const int row, const int col);
int visit(int maze[][SIZE], Point start, Point end);
void print_process(int maze[][SIZE], const int row, const int col);
void print_maze(int maze[][SIZE], const int row, const int col);


int main(){
    int row = 0, col = 0;
    int maze[SIZE][SIZE];
    cin >> row >> col;
    read_maze(maze, row, col);
   
    Point start = pt(0, 0);
    Point end = pt(row - 1, col - 1);
    
    if(maze[end.x][end.y] == 1 || (maze[end.x - 1][end.y] == 1 && maze[end.x][end.y - 1] == 1))
        cout << "Can't reach the exit!" << endl;
    else{
        if(visit(maze, start, end) == 2){
            // print_maze(maze, row, col);
            print_process(maze, row, col);
            
        }
        else
            cout << "Can't reach the exit!" << endl;
    }
  
}

void read_maze(int maze[][SIZE], const int row, const int col){
    for(int i = 0 ; i < row ; i++){
        for(int j = 0 ; j < col ; j++){
            cin >> maze[i][j];
        }
    }
}

int visit(int maze[][SIZE], Point start, Point end){
    // print_process(process);
   
    if(!maze[start.x][start.y]){
        maze[start.x][start.y] = 2;

        if(!maze[end.x][end.y] && 
                !(visit(maze, pt(start.x , start.y + 1), end) ||
                visit(maze, pt(start.x + 1, start.y), end) ||
                visit(maze, pt(start.x, start.y - 1), end) || 
                visit(maze, pt(start.x - 1, start.y), end) )
            ){
          
                maze[start.x][start.y] = 0;
        }
    }

    return maze[end.x][end.y];
}

void print_process(int maze[][SIZE], const int row, const int col){
    int cur_col = 0;
    for(int x = 0 ; x < row ; ){
        for(int y = cur_col ; y < col ; y++){
            if(maze[x][y] == 2){
                cout << "(" << x << "," << y++ << ") ";
                while(maze[x][y] == 2){
                    cur_col++;
                    cout << "(" << x << "," << y++ << ") ";
                }
                x++;
            }
            else
                x++;
                break;
                
        }
    }
}

void print_maze(int maze[][SIZE], const int row, const int col){
    for(int i = 0 ; i < row ; i++){
        for(int j = 0 ; j < col ; j++){
            cout << maze[i][j] << " ";
        }
        cout << endl;
    }
}