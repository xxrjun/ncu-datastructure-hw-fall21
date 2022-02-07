#include <iostream>
#include <vector>
using namespace std;

typedef struct{
    int col;
    int row;
    int value;
} term;

vector<term> readMatrix(const int row, const int col);
void multiplyMatrix(vector<term> m1, vector<term> m2, vector<term> &res_ma);
void transpose(vector<term> matrix, vector<term> &tmatrix);
void printMatrix(vector<term> matrix);
void storesum(vector<term> &ma, int *count, const int row, const int col, int *sum);
int COMPARE(const int a, const int b);

int main(){

    vector<term> matrix1;
    vector<term> tmp_matrix2;
    vector<term> matrix2;
    vector<term> res_ma;

    long long int row1 = 0, col1 = 0;
    long long int row2 = 0, col2 = 0;

    cin >> row1 >> col1;
    matrix1 = readMatrix(row1, col1);
    cin >> row2 >> col2;
    tmp_matrix2 = readMatrix(row2, col2);
    
    transpose(tmp_matrix2, matrix2);

    // add last row
    term lastTerm1;
    lastTerm1.row = row1;
    lastTerm1.col = 0;
    lastTerm1.value = 0;
    matrix1.push_back(lastTerm1);
    term lastTerm2;
    lastTerm2.row = col2;
    lastTerm2.col = 0;
    lastTerm2.value = 0;
    matrix2.push_back(lastTerm2);

    printMatrix(matrix1);
    printMatrix(matrix2);

    multiplyMatrix(matrix1, matrix2, res_ma);
    printMatrix(res_ma);

}

void multiplyMatrix(vector<term> m1, vector<term> m2, vector<term> &res_ma){

    int totalm1 = m1[0].value, totalm2 = m2[0].value;
    int count = 0; // how many terms be added to res_ma
    int row_begin = 1, row = m1[1].row;
    int column;
    int sum = 0;

    for(int i = 1 ; i <= totalm1 ; ){
        column = m2[1].row;
        for(int j = 1 ; j <= totalm2 + 1;){
            if(m1[i].row != row){
                // row end in a
                if(sum != 0){
                    storesum(res_ma, &count, row, column, &sum);
                } 
                i = row_begin;
                for( ; m2[j].row == column ;j++);
                column = m2[j].row;
            }
            else if (m2[j].row != column){
                // col end in m2(T)
                if(sum != 0){
                    storesum(res_ma, &count, row, column, &sum);
                } 
                i = row_begin;
                column = m2[j].row;
            }
            else switch(COMPARE(m1[i].col, (m2[j].col))){
                case -1: /* go to next term in m1 */
                    i++; break;
                case 0: /* add terms, go to next term in m1 and m2 */
                    sum += m1[i++].value * m2[j++].value;
                    break;
                case 1: /* go to next term in m2 */
                    j++;
            }

              
        }
        for(; m1[i].row == row ; i++);  
        row_begin = i;
        row = m1[i].row;
    }

    term firstTerm;
    firstTerm.row = m1[0].row;
    firstTerm.col = m2[0].col;
    firstTerm.value = count;
    res_ma.insert(res_ma.begin(), firstTerm);
  
}

void transpose(vector<term> ma, vector<term> &tma){
    tma.push_back(ma[0]);
    ma.erase(ma.begin());
	while(ma.size() > 0){
		int min = ma[0].col;
		int min_index = 0;
		
		for(int j = 1 ; j < ma.size(); j++){
			if(ma[j].col < min){
				min = ma[j].col;
			 	min_index = j;
			}
		}
		
		term temp;
		temp.row = ma[min_index].col;
		temp.col = ma[min_index].row;
		temp.value = ma[min_index].value;
		
		tma.push_back(temp);
		ma.erase(ma.begin() + min_index);
	}
}


void storesum(vector<term> &ma, int *count, const int row, const int col, int *sum){   
    if(*sum != 0){
        term newTerm;
        newTerm.row = row;
        newTerm.col = col;
        newTerm.value = *sum;
        ma.push_back(newTerm);
        *sum = 0;
        *count += 1;
    }
}

vector<term> readMatrix(const int row, const int col){
    vector<term> matrix;
    int count = 0;
    for(long long int i = 0 ; i < row ; i++){
        for(long long int j = 0 ; j < col ; j++){
            int tmpVal = 0;
            cin >> tmpVal;
            if(tmpVal != 0){
                term newTerm;
                newTerm.row = i;
                newTerm.col = j;
                newTerm.value = tmpVal;
                matrix.push_back(newTerm);
                count++;
            }
            
        }
    }
    term firstTerm;
    firstTerm.row = row;
    firstTerm.col = col;
    firstTerm.value = count;
    matrix.insert(matrix.begin(), firstTerm);
    return matrix;
}

void printMatrix(vector<term> matrix){
    long long int len = matrix.size();
    for(long long int i = 0 ; i < len ; i++){
        cout << matrix[i].row << " " << matrix[i].col << " " << matrix[i].value << endl;
    }
}

int COMPARE(const int a, const int b){
    if(a < b)
        return -1;
    else if (a == b)
        return 0;
    else
        return 1;
}