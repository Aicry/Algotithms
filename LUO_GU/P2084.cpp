#include <iostream>
using namespace std;

//48 57

int main(){
    int m;
    string n;
    cin >> m;
    cin >> n;
    int size=n.size();
    int mark = 0;
    for (int i = size-1; i >= 0 ;--i){
        if(n[i]!='0'){
            mark = i;
            break;
        }
    }
    for (int i = 0; i < size;++i){
        if(n[i]!='0'&&i!=mark){
            cout << n[i] - '0' << '*' << m << '^' << size - i-1 << '+';
        }
       else if(n[i]!='0'&&i==mark){
           cout << n[i] - '0' << '*' << m << '^' << size - i-1;
       }
    }
}