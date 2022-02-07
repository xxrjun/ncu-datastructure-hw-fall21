#include <iostream>
#include <vector>
#define SIZE 1001

using namespace std;

struct term{
    int row;
    int col;
    int value;
};

int matrix1[SIZE][SIZE], matrix2[SIZE][SIZE];
vector<term> res_matrix;

int countResRow = 0;

void readMatrix(int (*matrix)[SIZE], const int row, const int column);
void multiplyMatrix(int (*matrix1)[SIZE], int (*matrix2)[SIZE], const int row1, const int row2, const int column2);
void printMatrix(int (*matrix)[SIZE], const int row, const int column);
void printResMatrix(const int row);

int main(){

    int row1, column1;
    int row2, column2;
    
    cin >> row1 >> column1;
    readMatrix(matrix1, row1, column1);
    cin >> row2 >> column2;
    readMatrix(matrix2, row2, column2);

    // printMatrix(matrix1, row1, column1);
    // printMatrix(matrix2, row2, column2);
    if(column1 == row2){    
        multiplyMatrix(matrix1, matrix2, row1, row2, column2);
        cout << row1 << " " << column2 << " " << countResRow << endl;
        printResMatrix(countResRow);
    }
    else{
        return 0;
    }
}

void printResMatrix(const int row){
     for(int i = 0 ; i < row ; i++){
        cout << res_matrix[i].row << " " << res_matrix[i].col << " " << res_matrix[i].value << endl; 
    }
}

void multiplyMatrix(int (*matrix1)[SIZE], int (*matrix2)[SIZE], const int row1, const int row2, const int column2){
    for(int i = 0 ; i < row1 ; i++){
        for(int j = 0 ; j < column2 ; j++){
            int tmpValue = 0;
            for(int k = 0 ; k < row2 ; k++){
                while(matrix1[i][k] == 0 || matrix2[k][j] == 0){
                    k++;
                    if(k == row2)
                        break;
                }      
                tmpValue += matrix1[i][k] * matrix2[k][j];
            }
            if(tmpValue != 0){
                term newTerm;
                newTerm.row = i;
                newTerm.col = j;
                newTerm.value = tmpValue;
                res_matrix.push_back(newTerm);
                countResRow++;
            }
        }
    }
}

void readMatrix(int (*matrix)[SIZE], const int row, const int column){
    for(int i = 0 ; i < row ; i++){
        for(int j = 0 ; j < column ; j++){
            cin >> matrix[i][j];
        }
    }
}

void printMatrix(int (*matrix)[SIZE], const int row, const int column){
    for(int i = 0 ; i < row ; i++){
        for(int j = 0 ; j < column ; j++){
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}