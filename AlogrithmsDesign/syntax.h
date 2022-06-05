#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
using namespace std;


/*
S→id = E
E→T E'
E'→ + T E'|ε
T→F T'
T'→*FT'|ε
F→id | (E)|num
*/
#define ADVANCE() (idx<CNT-1? ++idx : threshold=1)
int threshold = 0;
int ERROR = 0, CNT = 0;
int idx = 0;
void S(vector<int> Sym);
void E(vector<int> Sym);
void E1(vector<int> Sym);
void T(vector<int> Sym);
void T1(vector<int> Sym);
void F(vector<int> Sym);

void S(vector<int> Sym) {
    if (Sym[idx] != 7) { ERROR == -1; return; }
    else {
        ADVANCE();
        if(Sym[idx]!=4) { ERROR == -1; return; }
        else {
            ADVANCE();
            E(Sym);
        }
    }
}
void E(vector<int> Sym) { //E→TE'
    T(Sym); E1(Sym);
}
void E1(vector<int> Sym) { //E'→+TE'|-TE'|ε
    if (ERROR == -1)return;
    if(Sym[idx] == 2) { // 当前Sym为"+ -"
        ADVANCE();
        T(Sym); E1(Sym);
    } 
    else if (Sym[idx] != 24 && threshold != 1) { //Sym不为")"或idx超过表达式长度
        ERROR = -1; return;
    }
}
void T(vector<int> Sym) { //T→FT'
    if (ERROR == -1)return;
    F(Sym); T1(Sym);
}
void T1(vector<int> Sym) { //T'→*FT'|/FT'|ε
    if (ERROR == -1)return;
    if(Sym[idx] == 3) { // 当前Sym为"* /"
        ADVANCE();
        F(Sym); T1(Sym);
    } 
    else if (Sym[idx] != 24 && Sym[idx] != 2 && threshold != 1) {
        //Sym不为")"或"+"或"-"或idx超过表达式长度
        ERROR = -1; return;
    }

}
void F(vector<int> Sym) { //F→(E)|id|num
    if (ERROR == -1)return;
    if(Sym[idx]==7 || Sym[idx]==8) { // 当前Sym为标识符, 常数
        ADVANCE();
    } 
    else if (Sym[idx] == 23) {
        ADVANCE();
        E(Sym);
        if (Sym[idx] == 24)ADVANCE();
        else { ERROR = -1; return; }
    }
    else {
        ERROR = -1; return;
    }
}
void SyntaxAnalysis(vector<int> Sym) {
    CNT = Sym.size();
    S(Sym);
    if(ERROR == -1 || !threshold)
        fout<<" wrong";
    else
       fout<<"correct";
}
