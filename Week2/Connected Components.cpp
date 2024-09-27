#include <iostream>
#include <vector>

using namespace std;

vector <bool> explored;

void DFS(int a ,vector <int> adjlist[]){
	explored[a] = true;
	int len = adjlist[a].size();
	for(int i=0;i<len;i++){
		int V=adjlist[a][i];
		if(!explored[V]){
			DFS(V,adjlist);
		}
	}
}


int main(){
	int V ,E,count=0;
	cin >> V >> E;
	
	int v,u;
	vector <int>adjlist[V+1];
	
	for(int i=0;i<E;i++){
		cin >> v >> u;
		adjlist[v].push_back(u);
		adjlist[u].push_back(v);  
	}
	for(int j=1;j<V+1;j++){
		explored.push_back(false);
	}
	
	for(int k=1;k<=V;k++){
		if(!explored[k]){
			DFS(k,adjlist);
			count++;			
		}
	}
	
	cout << count;
}
