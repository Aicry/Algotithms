#include<iostream>
using namespace std;

struct stu
{
    /* data */
    string name;
    string gender;
    string id;
    int grade;

};


int main(){
    int n;
    cin >> n;
    stu f, m;
    f.grade = -1;
    m.grade = 101;
    for (int i = 0; i < n;++i){
        stu t;
        cin >> t.name >> t.gender >> t.id >> t.grade;
        if(t.gender=="F"){
            if(t.grade>f.grade)
                f = t;
        }
       if(t.gender=="M"){
            if(t.grade<m.grade)
                m = t;
        }
    }
    if(f.grade!=-1&&m.grade!=101){
        cout << f.name << " " << f.id << endl;
        cout << m.name << " " << m.id << endl;
        cout << f.grade - m.grade;
    }
    else if(f.grade==-1&&m.grade!=101){
        cout <<"Absent" << endl;
        cout << m.name << " " << m.id << endl;
        cout << "NA";
    }
    else if(f.grade!=-1&&m.grade==101){
        cout << f.name << " " << f.id << endl;
        cout <<"Absent" << endl;
        cout << "NA";
    }
    else
    {
        cout << "Absent" << endl;
        cout << "Absent" << endl;
        cout << "NA";
    }
    
}