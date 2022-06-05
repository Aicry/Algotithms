#include<iostream>
using namespace std;

 bool isPalindrome(int x) {
    if(x<0)return false;
     long  temp=x;
     int k=0;
     long res=0;
         while(x){
               k=x%10;
              res=res*10+k;
              x=x/10; 
         }
         if(temp==res)return true;
         return false;
    }

int main(){
    isPalindrome(121);
}