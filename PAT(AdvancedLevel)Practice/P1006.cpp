#include<iostream>
#include<vector>
using namespace std;

struct io
{
    string id;
    int h, hh, m, mm, s, ss;
};

int intime_cmp(io a,io b)
{
     if(a.h!=b.h)
     {
         if(a.h>b.h)
             return 1;
         else
             return 0;
          }
    else {

       if(a.m!=b.m)
       {
           if(a.m>b.m)
               return 1;
            else
                return 0;
       }

       else
       {
            if(a.s>b.s)
                return 1;
            else
                return 0;
       }
        

    }
    
    

}
int outtime_cmp(io a,io b)
{
     if(a.hh!=b.hh)
     {
         if(a.hh>b.hh)
             return 1;
         else
             return 0;
          }
    else {

       if(a.mm!=b.mm)
       {
           if(a.mm>b.mm)
               return 1;
            else
                return 0;
       }

       else
       {
            if(a.ss>b.ss)
                return 1;
            else
                return 0;
       }
        

    }
    
    

}
int main(){
    int n;
    cin >> n;
    vector<io> r(n);
    char no;
    for (int i = 0; i < n;++i){
        cin >> r[i].id >> r[i].h >> no >> r[i].m >> no >> r[i].s >> r[i].hh >> no >> r[i].mm >> no >> r[i].ss;
    }
    string fir, las;
    io temp;
    temp.h = 25, temp.m = 61, temp.s = 61;
    temp.hh = 0, temp.mm = 0, temp.ss = 0;
    for (int i = 0; i < n;++i){
         if(!intime_cmp(r[i],temp)){
             temp.h = r[i].h;
             temp.m = r[i].m;
             temp.s = r[i].s;
             fir = r[i].id;
         }
          if(outtime_cmp(r[i],temp)){
             temp.hh = r[i].hh;
             temp.mm = r[i].mm;
             temp.ss = r[i].ss;
             las = r[i].id;
         }
    }
    cout << fir << " " << las;
}