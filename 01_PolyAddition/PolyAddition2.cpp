#include <iostream>
#include <vector>
using namespace std;

struct poly{
public: 
    long long int coef;
    long long int expo;
};

vector<poly> readPoly(long long int terms);
vector<poly> polynomialAddition(vector<poly> poly1, vector<poly> poly2, long long int maxExpo);
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

    long long int maxExpo = poly1[0].expo > poly2[0].expo ? poly1[0].expo : poly2[0].expo;

    vector<poly> resP = polynomialAddition(poly1, poly2, maxExpo);
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

vector<poly> polynomialAddition(vector<poly> p1, vector<poly> p2, long long int maxExpo){
    vector<poly> resP;
    for(long long int i = 0, expo = maxExpo ; i <= maxExpo ; i++, expo--){
        poly newPoly;
        newPoly.coef = 0;
        newPoly.expo = expo;
        resP.push_back(newPoly);
    }

    for(long long int i = 0, curP1 = 0, curP2 = 0 ; i <= maxExpo ; i++){
        // cout << "coef: " << resP[i].coef << " " << p1[i].coef << " " << p2[i].coef << endl;
        // cout << "expo: " << resP[i].expo << " " << p1[i].expo << " " << p2[i].expo << endl;

        if(curP1 == terms1 && curP2 == terms2)
            break;

        if(resP[i].expo == p1[curP1].expo && curP1 < terms1)
            resP[i].coef += p1[curP1++].coef;
                
        if(resP[i].expo == p2[curP2].expo && curP2 < terms2)
            resP[i].coef += p2[curP2++].coef;
        
    
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