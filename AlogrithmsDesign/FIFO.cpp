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
    cout << "内存大小:";
    cin >> mem_size;
    cout << "内存块大小:";
    cin >> block_size;
    cout << "内存块数量:";
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
    cout << "进程个数:";
    cin >> n;
    processes.resize(n);
    for (int i = 0; i < n;++i){
        processes[i].process_id = ('A' + i);
        cout << "请输入进程" << processes[i].process_id << "的段数:";
        int t;
        cin >> t;
        processes[i].segmants.resize(t);
        for (int j = 0; j < t;++j){
            cout << "请输入第" << j << "段的页的数量:";
            int k;
            cin >> k;
            processes[i].segmants[j].page_num = k;
        }
        cout << endl;
    }
}
void allocate_process(){
    cout << "待分配进程:";

}

void menu(){
    cout << "---------段页式存储管理的分配与回收（FIFO置换算法）" << endl<< endl;
    cout << "---------1.初始化内存大小、内存块的大小和数量" << endl;
    cout << "---------2.初始化进程的个数、每个进程的段数和段内页的个数" << endl;
    cout << "---------3.分配" << endl;
    cout << "---------4.回收" << endl;
    cout << "---------0.退出" << endl;
    cout << "请输入选项:";
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
模拟当某进程提出申请内存空间的大小后，能够判定是否能满足申请；并显示进程在内存的存储情况；
显示每次完成分配或回收后内存空间的使用情况。
*/


int main(){
    menu();
}
