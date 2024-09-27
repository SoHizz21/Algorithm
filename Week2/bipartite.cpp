#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector <int> level;
vector <bool> discover;
bool idBipart = true;

void BFS(int a,vector <int> adjlist[]){
	queue <int> q;
	level[a]=0;
	q.push(a); 
	while(!q.empty()){
		int u = q.front();
		int len = adjlist[u].size();
		for(int i=0;i<len;i++){
			int V=adjlist[u][i];
			if(!discover[V]){
				discover[V]=true;
				level[V]=level[u]+1;
				q.push(V); 
			}else if(discover[V]&&level[V]==level[u]){
				idBipart = false;
				break;
			}
		}
		q.pop();
	}
}

int main(){
	int V ,E;
	cin >> V >> E;
	
	int v,u;
	vector <int>adjlist[V+1];

	for(int i=0;i<E;i++){
		cin >> v >> u;
		adjlist[v].push_back(u);
		adjlist[u].push_back(v);  
	}
	for(int j=1;j<=V+1;j++){
		discover.push_back(false);
		level.push_back(-1); 
	}
	BFS(v,adjlist);
	if(idBipart){
		cout << "YES";
	}else{
		cout << "NO";
	}
	return 0;
}
