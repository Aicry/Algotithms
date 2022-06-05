#include<iostream>
#include<time.h>
#include<windows.h>
#define N 1000000
using namespace std;
/*double aprod(double a[],int n){
    int i;
    double x, y, z;
    double r = 1;
    for (i = 0; i < n - 2;i+=3){
        x = a[i];
        y = a[i + 1];
        z = a[i + 2];
        //r = r * x * y * z;//1
        //r = ((r * x) * y) * z;//0
        //r = r * ((x * y) * z);//0
        // r = r * (x * (y * z));//1
        //r = (r * x) * (y * z);//0
    }
    for (; i < n;i++)
        r *= a[i];
    return r;
}

*/

int main(){
    double a[N];
    LARGE_INTEGER nFreq;
    LARGE_INTEGER t1;
    LARGE_INTEGER t2;
    double dt;

    QueryPerformanceFrequency(&nFreq);
    QueryPerformanceCounter(&t1);


    //for (int i = 0; i < N;i++){
    //      a[i] = i;
    //}
   // aprod(a, N); //计时代码段
    Sleep(5);
    QueryPerformanceCounter(&t2);
    dt = (t2.QuadPart - t1.QuadPart)/(double)nFreq.QuadPart;

    cout <<"run time:"<< dt*1000000;
}