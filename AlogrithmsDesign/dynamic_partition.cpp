#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<algorithm>
#include<deque>
#include<iomanip>
#include<limits>
using namespace std;

int memory_size, process_num;
struct mem_block
{
	string pro="NULL";
	int id=0;
	int start=0;
	int size=0;
	mem_block* front=NULL;
	mem_block* next=NULL;
};
struct process
{
	string pro="";
	int size = 0;
};
//1 1000 10 100 200 100 200 300 100 200 100
deque<process> processes;
deque<process>::iterator it;
queue<mem_block> runing_pro;
mem_block* head = new mem_block;
void initial();
void allocate_process();
void menu();
void display();
void first_fit(process* t);
void best_fit(process* t);
void worst_fit(process* t);
void recycle();
void initial() {
	cout << "内存大小:";
	cin >> memory_size;
	mem_block* fir = new mem_block;
	fir->pro = "NULL";
	fir->id = 0;
	fir->start = 0;
	fir->size = memory_size;
	fir->front = head;
	fir->next = NULL;
	head->front = NULL;
	head->next = fir;
	head->pro = "head";
	cout << "进程数量:";
	cin >> process_num;
	processes.resize(process_num);

	for (int i = 0; i < process_num; ++i)
	{
		cout << "进程" << (char)('A'+i) << "大小:";
		cin >> processes[i].size;
		processes[i].pro = (char)('A' + i);
	}
	cout << endl;
}

void allocate_process() {
	display();
	process* t = &processes.front();
	cout << endl;
	cout << "1.最先适应法" << endl
		<< "2.最佳适应法" << endl
		<< "3.最坏适应法" << endl;
	cout << "请选择分配方法:";
	int i;
	cin >> i;
	switch (i)
	{
	case 1:
		first_fit(t);
		break;
	case 2:
		best_fit(t);
		break;
	case 3:
		worst_fit(t);
		break;
	default:
		break;
	}
}

void menu() {
	cout << "---------1.初始化内存大小、进程的个数和大小" << endl;
	cout << "---------2.分配" << endl;
	cout << "---------3.回收" << endl;
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
		if (processes.size() != 0)allocate_process();
		else cout << "进程队列中无进程" << endl;
		break;
	case 3:
		recycle();
		break;
	case 0:
		break;
	default:
		break;
	}
	if (i != 0)
		menu();
}

void display()
{
	cout << "内存状态" << endl;
	mem_block* block = new mem_block;
	block = head->next;
	cout << "内存块id    块中进程   起始地址   块大小" << endl;
	int i = 0;
	while (block != NULL)
	{
		block->id = i;
		cout <<  block->id <<setw(16)<<setfill(' ')<<block->pro <<setw(12) << setfill(' ') << block->start << setw(12) << setfill(' ') << block->size << endl;
		if (block->next)block->next->start = block->start + block->size;
		block = block->next;
		i++;
	}
	cout << "待分配进程队列:";
	for (it = processes.begin(); it != processes.end(); ++it) {
		cout << "->" << it->pro << "(" << it->size << ")";
	}
	cout << endl;
	delete block;
}
void first_fit(process* t)
{
	mem_block* block = new mem_block;
	block = head->next;

	int flag = 0;

	while (block != NULL) {
		if (block->size > t->size && block->pro == "NULL")
		{
			mem_block* fir = block->front;
			mem_block* las = block->next;

			mem_block* a = new mem_block;
			a->size = t->size;
			a->pro = t->pro;

			mem_block* b = new mem_block;
			b->size = block->size - t->size;
			b->pro = "NULL";

			fir->next = a;
			a->front = fir;

			a->next = b;
			b->front = a;

			b->next = las;
			if(las)las->front = b;

			flag = 1;
			break;
		}

		else if (block->size == t->size && block->pro == "NULL")
		{
			block->pro = t->pro;
			flag = 1;
			break;
		}
		else
			block = block->next;
	}

	if (flag) {
		cout << "分配成功" << endl;
		processes.pop_front();
		display();
	}
	else {
		cout << "内存空间不足" << endl;
		menu();
	}

}
void best_fit(process* t) {
	mem_block* block = new mem_block;
	mem_block* blo = new mem_block;
	block = head->next;
	int flag = 0;
	int n = INT_MAX;
	while (block != NULL) {
		
		if (block->size > t->size && block->pro == "NULL") {
			if ((block->size - t->size) < n) {
				n = block->size - t->size;
				blo = block;
				flag = 1;
			}
		}
		else if (block->size == t->size && block->pro == "NULL") {
			flag = 1;
			blo = block;
			break;
		}
		block = block->next;
	}
	
		if (blo->size > t->size && blo->pro == "NULL")
		{
			mem_block* fir = blo->front;
			mem_block* las = blo->next;

			mem_block* a = new mem_block;
			a->size = t->size;
			a->pro = t->pro;

			mem_block* b = new mem_block;
			b->size = blo->size - t->size;
			b->pro = "NULL";

			fir->next = a;
			a->front = fir;

			a->next = b;
			b->front = a;

			b->next = las;
			if (las)las->front = b;		
		}

		else if (block!=NULL&&blo->size == t->size && block->pro == "NULL")
		{
			block->pro = t->pro;
			flag = 1;			
		}
	if (flag) {
		cout << "分配成功" << endl;
		processes.pop_front();
		display();
	}
	else {
		cout << "内存空间不足" << endl;
		menu();
	}
}
void worst_fit(process* t) {
	mem_block* block = new mem_block;
	mem_block* blo = new mem_block;
	block = head->next;
	int flag = 0;
	int n = INT_MIN;
	while (block != NULL) {

		if (block->size >= t->size && block->pro == "NULL") {
			if ((block->size - t->size) > n) {
				n = block->size - t->size;
				blo = block;
				flag = 1;
			}
		}
		block = block->next;
	}

	if (flag&&blo->size > t->size && blo->pro == "NULL")
	{
		mem_block* fir = blo->front;
		mem_block* las = blo->next;

		mem_block* a = new mem_block;
		a->size = t->size;
		a->pro = t->pro;

		mem_block* b = new mem_block;
		b->size = blo->size - t->size;
		b->pro = "NULL";
		fir->next = a;
		a->front = fir;

		a->next = b;
		b->front = a;

		b->next = las;
		if (las)las->front = b;
	}
	else if (flag&&blo->size == t->size && blo->pro == "NULL")
	{
		blo->pro = t->pro;
		flag = 1;
	}

	if (flag) {
		cout << "分配成功" << endl;
		processes.pop_front();
		display();
	}
	else {
		cout << "内存空间不足" << endl;
		menu();
	}
}
void recycle() {
	mem_block* block = new mem_block;
	block = head->next;
	cout << "内存块id    块中进程   起始地址   块大小" << endl;
	while (block != NULL)
	{	
		cout << block->id << setw(12) << setfill(' ') << block->pro << setw(12) << setfill(' ') << block->start << setw(12) << setfill(' ') << block->size << endl;
		block = block->next;	
	}
	cout << "请输入要回收的进程" << endl;
	string t;
	cin >> t;
	block = head->next;
	while (block != NULL) {
		if (block->pro == t)break;
		block = block->next;
	}
	if (block!=NULL&&block->next != NULL ) {

		if (block->next->pro == "NULL" && block->front->pro == "NULL") {
			mem_block* temp = block->next->next;
			block->front->size = block->front->size + block->size + block->next->size;
			block->front->next = temp;
			block->front->pro = "NULL";
			if (temp)temp->front = block->front;
		}

		else if (block->next->pro == "NULL"&&block->front->pro!="NULL") {
			mem_block* temp = block->next->next;
			block->size = block->size + block->next->size;
			block->next = temp;
			block->pro = "NULL";
			if (temp)temp->front = block;
		}
		else if (block->next->pro != "NULL" && block->front->pro != "NULL") {
			block->pro = "NULL";
		}
		else if (block->next->pro != "NULL" && block->front->pro == "NULL") {
			block->front->size += block->size;
			block->front->next = block->next;
			if (block->next)block->next->front = block->front;
		}
	}
	else 
	{
		if (block != NULL && block->front->pro != "NULL")
			block->pro = "NULL";
		if (block != NULL && block->front->pro == "NULL") {
			block->front->size += block->size;
			block->front->next = NULL;
		}
	}
	display();
}
int  main()
{
	cout << "     动态分区管理      " << endl << endl;
	menu();
	return 0;
}