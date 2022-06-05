#include <iostream>
#include <string.h>
#include <vector>
#include <stack>
#include <math.h>
using namespace std;

int main()
{
  cout << pow(169, (float)1 / 3);
  // vector<int> a = {1, 2, 3};
  // vector<int> b = a;
  // a[2] = 1;
  //  cout << b[2];
  // char a;

  //  cin >> a;
  /// cout << a<<" ";
  // cout << -(int)a;
  //string a;
  //string b;
  // cin >> a >> b;
  //  cout<<a.find(b[0]);
  // stack<int> s;
  //if(s.top()==1)
  //   cout << 1;
}

#define ADVANCE() (idx<CNT-1? ++idx : threshold=1)
int threshold = 0;
int ERROR = 0, CNT = 0;
int idx = 0;
void S(vector<pair<string, string>> Sym);
void G(vector<pair<string, string>> Sym);
void E(vector<pair<string, string>> Sym);
void E1(vector<pair<string, string>> Sym);
void T(vector<pair<string, string>> Sym);
void T1(vector<pair<string, string>> Sym);
void F(vector<pair<string, string>> Sym);

void S(vector<pair<string, string>> Sym) {

}


void G(vector<pair<string, string>> Sym) {
    if (Sym[idx].num != 7) { ERROR = -1; return; }
    else {
        ADVANCE();
        if (Sym[idx].num != 4) { ERROR = -1; return; }
        else {
            ADVANCE();
            E(Sym);
        }
    }
}
void E(vector<pair<string, string>> Sym) { //E→TE'
    T(Sym); E1(Sym);
}
void E1(vector<pair<string, string>> Sym) { //E'→+TE'|-TE'|ε
    if (ERROR == -1)return;
    if (Sym[idx].num == 2) { // 当前Sym为"+ -"
        ADVANCE();
        T(Sym); E1(Sym);
    }
    else if (Sym[idx].num != 24 && threshold != 1) { //Sym不为")"或idx超过表达式长度
        ERROR = -1; return;
    }
}
void T(vector<pair<string, string>> Sym) { //T→FT'
    if (ERROR == -1)return;
    F(Sym); T1(Sym);
}
void T1(vector<pair<string, string>> Sym) { //T'→*FT'|/FT'|ε
    if (ERROR == -1)return;
    if (Sym[idx].num == 3) { // 当前Sym为"* /"
        ADVANCE();
        F(Sym); T1(Sym);
    }
    else if (Sym[idx].num != 24 && Sym[idx].num != 2 && threshold != 1) {
        //Sym不为")"或"+"或"-"或idx超过表达式长度
        ERROR = -1; return;
    }

}
void F(vector<pair<string, string>> Sym) { //F→(E)|id|num
    if (ERROR == -1)return;
    if (Sym[idx].num == 7 || Sym[idx].num == 8) { // 当前Sym为标识符, 常数
        ADVANCE();
    }
    else if (Sym[idx].num == 23) {
        ADVANCE();
        E(Sym);
        if (Sym[idx].num == 24)ADVANCE();
        else { ERROR = -1; return; }
    }
    else {
        ERROR = -1; return;
    }
}
void SyntaxAnalysis(vector<pair<string, string>> Sym) {
    CNT = Sym.size();
    G(Sym);
    if (ERROR == -1 || !threshold)
        fout << " wrong";
    else
        fout << "correct";
}
