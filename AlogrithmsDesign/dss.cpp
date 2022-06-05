#include<stdio.h>
#include<math.h>
double a, b, c;
double f(double x){
    return a * x * x + b * x + c;
}
int main(){
    scanf("%lf%lf%lf", &a, &b, &c);
    double x1, x2, m;//区间[x1,x2]
    scanf("%lf%lf%lf", &x1, &x2, &m);
    int n;
    scanf("%d", &n);
    while(fabs(x2-x1)>m){
        double t = fabs(x2 - x1) / (n + 1);//分成n+1份
        double min = INT_MAX;//min设为最大整数
        int k;
        for (int i = 1; i <= n;++i){
            if (f(x1 + i * t) < min)
            {
                min = f(x1 + i * t);
                k = i; //找到最小值对应的i
            }
        }
        x1 = x1 + t * (k - 1);//更新区间
        x2 = x1 + t * (k + 1);
    }
    printf("%lf\n", x1);
    printf("%lf\n", x2);
    printf("%lf\n", (x1 + x2) / 2);
    printf("%lf", f((x1 + x2) / 2));
}