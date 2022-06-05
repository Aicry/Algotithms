#include<iostream>

using namespace std;

int gcb(int a,int b){
    return b == 0 ? a : gcb(b, a % b);
} 


int main(){

    int count = 0;
    for (int i = 1; i <= 2020;++i){
        for (int j = 1; j <= 2020;++j){
            if(gcb(i,j)==1)
                count++;
        }
    }
    cout << count;
}