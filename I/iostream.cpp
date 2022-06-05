#include<iostream>
#include<string>
#include<string.h>

using namespace std;
int main(){
    string str;
	cout<<"cin的测试："<<endl;
	cin>>str;
	cout<<str<<endl;
	cin>>str;
	cout<<str<<endl;


    string str;
	cout<<"cin的测试："<<endl;
	cin>>str;
	cin.sync();
	cout<<str<<endl;
	cin>>str;
	cout<<str<<endl;

    char ch1[10],ch2[10];
	cout<<"输入两个字符串："<<endl;
	cin>>ch1;
	cin>>ch2;
	cout<<"两个字符串分别为："<<endl;
	cout<<ch1<<endl;
	cout<<ch2<<endl;

    char ch1,ch2;
    cout<<"请输入两个字符："<<endl;
    cin.get(ch1);//或ch1 = cin.get();
    cin.get(ch2);
    cout<<ch1<<" "<<ch2<<endl;
    cout<<(int)ch1<<" "<<(int)ch2<<endl;

    char ch1,ch2[10];
    cout<<"请输入字符串："<<endl;
    cin.get(ch2,6);//在不遇到结束符的情况下，最多可接收6-1=5个字符到ch2中，注意结束符为默认Enter
    cin.get(ch1);//或ch1 = cin.get();
    cout<<ch2<<endl;
    cout<<ch1<<"\n"<<(int)ch1<<endl;
   
     char ch1,ch2[10];
    cout<<"请输入字符串："<<endl;
    cin.get(ch2,6);//在不遇到结束符的情况下，最多可接收6-1=5个字符到ch2中
    cin.get();//注意：前面两句可以写到一块：cin.get(ch2,6).get();
    cin.get(ch1);//或ch1 = cin.get();
    cout<<ch2<<endl;
    cout<<ch1<<"\n"<<(int)ch1<<endl;
 
    char ch1,ch2[10];
     cout<<"请输入字符串："<<endl;
    cin.getline(ch2,6);//在不遇到结束符的情况下，最多可接收6-1=5个字符到ch2中
    cin>>ch1;
    cout<<ch2<<endl;
    cout<<ch1<<"\n"<<(int)ch1<<endl;
   
 string str;
    cout<<"请输入string内容："<<endl;
    getline(cin,str,'a');
    cout<<str<<endl; 

    char ch[10];
    cout<<"请输入char*内容："<<endl;
    gets(ch);
    cout<<ch<<endl;



}
