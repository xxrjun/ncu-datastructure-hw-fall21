#include <iostream>
#include <vector>
using namespace std;

struct poly{
    long long int coef;
    long long int expo;
};

vector<poly> readPoly(long long int terms);
vector<poly> polynomialAddition(vector<poly> poly1, vector<poly> poly2);
void printPoly(vector<poly> polynomial);

long long int terms1 = 0;
long long int terms2 = 0;

int main(){   

    vector<poly> poly1;
    vector<poly> poly2; 
    
    cin >> terms1;
    poly1 = readPoly(terms1);

    cin >> terms2;
    poly2 = readPoly(terms2);

    // printPoly(poly1, terms1);
    // printPoly(poly2, terms2);

    vector<poly> resP = polynomialAddition(poly1, poly2);
    printPoly(resP);

}

vector<poly> readPoly(long long int terms){
    vector<poly> p;
    for(long long int i = 0; i < terms ; i++){
        poly newPoly;
        cin >> newPoly.coef >> newPoly.expo;
        p.push_back(newPoly);  
    }

    return p;
}

vector<poly> polynomialAddition(vector<poly> p1, vector<poly> p2){
    vector<poly> resP;
    long long int start1 = 0, start2 = 0;
    long long int stop1 = 0, stop2 = 0;

    while(start1 < terms1 || start2 < terms2){
        poly tmp;

        // p1 and p2 are end
        if(stop1 == 1 && stop2 == 1)
            break;
        
        if((p1[start1].expo > p2[start2].expo || stop2 == 1) && stop1 != 1){
            //only add poly1's elements
            tmp.expo = p1[start1].expo;
            tmp.coef = p1[start1].coef;

            if(start1 == (terms1 - 1))
                stop1 = 1;
            else
                start1++;
        }
        else if ((p1[start1].expo < p2[start2].expo || stop1 == 1) && stop2 != 1){
            //only add poly2's elements
            tmp.expo = p2[start2].expo;
            tmp.coef = p2[start2].coef;
            

            if(start2 == (terms2 - 1))
                stop2 = 1;
            else
                start2++;
        }
        else if((p1[start1].expo == p2[start2].expo) && (stop1 != 1 && stop2 != 1)){
            //only add poly1's and poly2's elements
            tmp.expo = p1[start1].expo;
            tmp.coef = p1[start1].coef + p2[start2].coef;
            
            if(start1 == (terms1 - 1))
                stop1 = 1;
            else
                start1++;

            if(start2 == (terms2 - 1))
                stop2 = 1;
            else
                start2++;
        }

        resP.push_back(tmp);
    }


    return resP;
}

void printPoly(vector<poly> p){
    long long int i = 0;

    for(; i < p.size() - 1; i++){
        if(p[i].coef != 0)
            cout << p[i].coef << " " << p[i].expo << " ";
    }
    if(p[i].coef != 0)
        cout << p[i].coef << " " << p[i].expo << endl;
}