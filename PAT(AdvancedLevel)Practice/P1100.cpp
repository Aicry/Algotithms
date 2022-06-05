#include<iostream>
#include<vector>
#include<stdio.h>
using namespace std;
/*
tam, hel, maa, huh, tou, kes, hei, elo, syy, lok, mer, jou
*/

/*"tret,jan, feb, mar, apr, may, jun, jly, aug, sep, oct, nov, dec"*/
vector<string> Mnum;

bool h_digit(string a){
    if(a=="tam"||a=="hel"||a=="maa"||a=="huh"||a=="tou"||a=="kes"
    ||a=="hei"||a=="elo"||a=="syy"||a=="lok"||a=="mer"||a=="jou")
        return true;
    return false;
}
int main(){
    int n;
    cin >> n;
    for (int i = 0; i < n;++i){
        string a;
        cin >> a;
        Mnum.push_back(a);
        if(h_digit(a)){
            string b;
            cin >> b;
            Mnum.push_back(b);
        }      
    }

    for (int i = 0; i < Mnum.size();++i){
        cout << Mnum[i] << " ";
    }
}