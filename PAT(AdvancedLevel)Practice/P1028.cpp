#include<iostream>
#include<string>
#include<string.h>
#include<vector>
#include<algorithm>
#include<iomanip>
using namespace std;
struct student
{
    int id; 
    string name;
    int grade;
};

bool cmp1(student& a,student& b){
    return a.id < b.id;
}
bool cmp2(student& a,student& b){
    if(a.name.compare(b.name)<0)
        return true;
    if(a.name.compare(b.name)>0)
        return false;
    if(a.name.compare(b.name)==0)
        return cmp1(a, b);
    return false;
}
bool cmp3(student& a,student& b){
    if(a.grade==b.grade)
        return cmp1(a, b);
    else
        return a.grade < b.grade;
}

int main(){
    int n,c;
    cin >> n >> c;
    int k = n;
    vector<student> students;
    student temp;
    while(k--){
        cin >> temp.id >> temp.name >> temp.grade;
        students.push_back(temp);
    }
    if(c==1)
        sort(students.begin(), students.end(),cmp1);
    if(c==2)
        sort(students.begin(), students.end(),cmp2);
    if(c==3)
        sort(students.begin(), students.end(),cmp3);
    for (int i = 0; i < n;++i){
        cout << setw(6)<<setfill('0')<<students[i].id << " " << students[i].name << " " << students[i].grade << endl;
    }
}
