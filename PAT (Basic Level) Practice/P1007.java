import java.util.Scanner;

public class P1007 {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int N = in.nextInt();
        in.close();
        int[] primes = new int[N+1];
        int count = 0;
        for (int i = 2; i <= N; i++) {
            if (primes[i] == 0) 
                primes[count++] = i;
            for (int j = 2 * i; j <= N; j+=i)
                primes[j] = 1;      
        } 
        int res = 0;
        for (int i = 0; i < count - 1; i++) {
          //  System.out.println(primes[i]);
            if ((primes[i + 1] - primes[i]) == 2)
                res++;
        }
       System.out.println(res);  
    }
}


/*
#include<stdio.h>
#define MAX 100
int s;
int a[MAX];
void prime()
{
    s=1;
    for(int i=0;i<=MAX;i++)
        a[i]=1;
    a[0]=a[1]=0;
    for(int i=2;i<=MAX;i++)
    {
        if(a[i])
            a[s++]=i;
        for(int j=i*2;j<=MAX;j+=i)
            a[j]=0;
    }
}
int main()
{
    prime();
    for(int i=1;i<s;i++)
        printf("%d\n",a[i]);
    return 0;
}
 */