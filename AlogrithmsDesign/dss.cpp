#include<stdio.h>
#include<math.h>
double a, b, c;
double f(double x){
    return a * x * x + b * x + c;
}
int main(){
    scanf("%lf%lf%lf", &a, &b, &c);
    double x1, x2, m;//����[x1,x2]
    scanf("%lf%lf%lf", &x1, &x2, &m);
    int n;
    scanf("%d", &n);
    while(fabs(x2-x1)>m){
        double t = fabs(x2 - x1) / (n + 1);//�ֳ�n+1��
        double min = INT_MAX;//min��Ϊ�������
        int k;
        for (int i = 1; i <= n;++i){
            if (f(x1 + i * t) < min)
            {
                min = f(x1 + i * t);
                k = i; //�ҵ���Сֵ��Ӧ��i
            }
        }
        x1 = x1 + t * (k - 1);//��������
        x2 = x1 + t * (k + 1);
    }
    printf("%lf\n", x1);
    printf("%lf\n", x2);
    printf("%lf\n", (x1 + x2) / 2);
    printf("%lf", f((x1 + x2) / 2));
}