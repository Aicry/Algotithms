#include<iostream>
#include<iomanip>
using namespace std;
int main(){
    double a[10];
    for (int i = 0; i < 9;++i){
        cin >> a[i];
    }
    double res[3];
    char wtl[3];
    int k = 0;
    for (int i = 0; i < 9;i+=3){
       if(a[i]>a[i+1]&&a[i]>a[i+2]){
           res[k] = a[i];
           wtl[k] = 'W';
       }
        if(a[i+1]>a[i]&&a[i+1]>a[i+2]){
           res[k] = a[i+1];
           wtl[k] = 'T';
       }
        if(a[i+2]>a[i+1]&&a[i+2]>a[i]){
           res[k] = a[i+2];
           wtl[k] = 'L';
       }
       k++;
    }
    
    cout << wtl[0] << " " << wtl[1] << " " << wtl[2] <<" "<<fixed<<setprecision(2)<< (res[0] * res[1] * res[2] * 0.65 - 1) * 2;
}