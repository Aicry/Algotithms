#include<iostream>
#include<string>
#include<vector>
#include<list>
#include<queue>
using namespace std;
int mem_size, block_size, mem_num;
struct block
{
    int block_id;
    int status;
    string process_id;
};
struct segmant
{
    int segment_id;
    int page_num;
    int page_address;
};
struct page
{
    int page_id;
    int block_id;
};
struct process
{
    string process_id;
    vector<segmant> segmants;
};

vector<block> blocks;
vector<page> pages;
vector<process> processes;
queue<process> run_process;
void initial(){
    cout << "�ڴ��С:";
    cin >> mem_size;
    cout << "�ڴ���С:";
    cin >> block_size;
    cout << "�ڴ������:";
    mem_num = mem_size / block_size;
    cout << mem_num;
    blocks.resize(mem_num);
    for (int i = 0; i < mem_num;++i){
        blocks[i].block_id = i;
    }
        cout << endl;
}
void process_initial(){
    int n;
    cout << "���̸���:";
    cin >> n;
    processes.resize(n);
    for (int i = 0; i < n;++i){
        processes[i].process_id = ('A' + i);
        cout << "���������" << processes[i].process_id << "�Ķ���:";
        int t;
        cin >> t;
        processes[i].segmants.resize(t);
        for (int j = 0; j < t;++j){
            cout << "�������" << j << "�ε�ҳ������:";
            int k;
            cin >> k;
            processes[i].segmants[j].page_num = k;
        }
        cout << endl;
    }
}
void allocate_process(){
    cout << "���������:";

}

void menu(){
    cout << "---------��ҳʽ�洢����ķ�������գ�FIFO�û��㷨��" << endl<< endl;
    cout << "---------1.��ʼ���ڴ��С���ڴ��Ĵ�С������" << endl;
    cout << "---------2.��ʼ�����̵ĸ�����ÿ�����̵Ķ����Ͷ���ҳ�ĸ���" << endl;
    cout << "---------3.����" << endl;
    cout << "---------4.����" << endl;
    cout << "---------0.�˳�" << endl;
    cout << "������ѡ��:";
    int i;
    cin >> i;
    cout << endl;
    switch (i)
    {
    case 1:
        initial();
        break;
    case 2:
        process_initial();
        break;
    case 3:
        break;
    case 4:
        break;
    case 5:
        break;
    case 0:
        break;
    default:
        break;
    }
    if(i!=0)
        menu();
}
/*
ģ�⵱ĳ������������ڴ�ռ�Ĵ�С���ܹ��ж��Ƿ����������룻����ʾ�������ڴ�Ĵ洢�����
��ʾÿ����ɷ������պ��ڴ�ռ��ʹ�������
*/


int main(){
    menu();
}
