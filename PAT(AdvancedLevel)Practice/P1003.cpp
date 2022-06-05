
#include<iostream>
#include<vector>

using namespace std;
bool visted[500] = {false};
vector<int> r;
vector<int> t;
int c1, c2;
struct city
{
  int num;
  int teams;
};

struct Graph {
	int AdjMatrix[500][500]; // 邻接矩阵
	city citys[500]; // 顶点数组
	int cityNum; // 顶点个数
	int roads;//边数
};

void createGraph(Graph &G){ 
  int n, m;
  cin >> n >> m >> c1 >> c2;
  G.cityNum = n;
  G.roads = m;
  int temp;
  for (int i = 0; i < n;++i){
    cin >> temp;
    G.citys[i].num = i;
    G.citys[i].teams = temp;
  }
  int c3, c4 ,d;
  for (int i = 0; i < m;++i){
    cin >> c3 >> c4 >> d;
    G.AdjMatrix[c3][c4] = d;
    G.AdjMatrix[c4][c3] = d;
  }
}


void DFS(int b,int index,Graph& m_Graph,int& totalterm,int& toltal_distance) {
        visted[index] = true;
        totalterm += m_Graph.citys[index].teams;
  if (index == b) {
    r.push_back(toltal_distance);
    t.push_back(totalterm);
    totalterm -= m_Graph.citys[index].teams;
	  visted[index] = false;
    return;
	}

	for (int i = 0; i < m_Graph.cityNum; ++i) {

		if (i == index || visted[i]) continue;

		if (m_Graph.AdjMatrix[index][i] != 0) {
   
      toltal_distance += m_Graph.AdjMatrix[index][i];
      DFS(b, i, m_Graph,totalterm,toltal_distance);
      toltal_distance -= m_Graph.AdjMatrix[index][i];

		}

	}
       totalterm -= m_Graph.citys[index].teams;
	     visted[index] = false;
}


void DFSTraverse(Graph& G,int c1,int c2){
  int totalterm = 0, toltal_distance = 0;
  DFS(c1, c2, G,totalterm, toltal_distance);
	

}
int main(){
  Graph G;
  createGraph(G);

 /* for (int i = 0; i < G.cityNum;++i){
    for (int j = 0; j < G.cityNum;++j){
      cout << G.AdjMatrix[i][j]<<' ';
    }
    cout << endl;
  }

  cout << c1 << " " << c2 << endl;
*/
  DFSTraverse(G, c1, c2);

  int n = r.size();
  int minroad=INT_MAX;
  for (int i = 0; i < n;++i){
    minroad = min(minroad, r[i]);
  }
  int maxterm=0;
  int count = 0;
  for (int i = 0; i < n;++i){
    if(r[i]==minroad)
      maxterm = max(maxterm, t[i]),count++;
  }
  cout<<count << " " << maxterm;

}

