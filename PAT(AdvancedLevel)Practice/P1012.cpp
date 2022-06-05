#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    vector<string> id;
    vector<int> c;
    vector<int> m;
    vector<int> e;
    vector<int> a;
    int n, q;
    cin >> n >> q;
    string k1;
    int k2, k3, k4, k5;
    for (int i = 0; i < n;++i){
        cin >> k1 >> k2 >> k3 >> k4;
        k5 = (k4 + k2 + k3) / 3;
        id.push_back(k1);
        c.push_back(k2);
        m.push_back(k3);
        e.push_back(k4);
        a.push_back(k5);
    }
    vector<string> temp;
    string p;
    for (int i = 0; i < q;++i){
        cin >> p;
        temp.push_back(p);
    }


     vector<int> c1, m1, e1, a1;
    for (int i = 0; i < n;++i){
        c1.push_back(c[i]);
        m1.push_back(m[i]);
        e1.push_back(e[i]);
        a1.push_back(a[i]);
    }

    sort(c1.rbegin(), c1.rend());
    sort(m1.rbegin(), m1.rend());
    sort(e1.rbegin(), e1.rend());
    sort(a1.rbegin(), a1.rend());
    
    for (int i = 0; i < q;++i){
        int rankc, rankm, ranke, ranka;
       
        int j = 0;
        for ( j ; j < n;++j){
            if(temp[i]==id[j]){
                for (int k = 0; k < n;++k){
                     if(c1[k]==c[j])
                         rankc = k + 1;
                     if(m1[k]==m[j])
                         rankm = k + 1;
                    if(e1[k]==e[j])
                        ranke = k + 1;
                    if(a1[k]==a[j])
                        ranka = k + 1;
                }
                

                if(ranka<=rankc&&ranka<=ranke&&ranka<=rankm)
                    cout << ranka << " "
                         << "A"<<endl;
                if(rankc<=rankm&&rankc<=ranke&&rankc < ranka)
                    cout << rankc << " "
                         << "C"<<endl;
                if(rankm<rankc&&rankm<=ranke&&rankm<ranka)
                    cout << rankm << " "
                         << "M"<<endl;
                if(ranke<rankc&&ranke<rankm&&ranke<ranka)
                    cout << ranke << " "
                         << "E"<<endl;

                break;
            }
        }
        if(j==n)
            cout << "N/A"<<endl;
      
     

    }
}

/**
 * @brief 
 * 
 * 
 * 
5 6
310101 90 98 98
310102 97 82 98
310103 80 96 96
310104 90 95 95
310105 94 90 94
310101
310102
310103
310104
310105
999999

 * 
 */