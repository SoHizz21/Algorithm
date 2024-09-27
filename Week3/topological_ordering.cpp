#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector <int> indegree0;
queue <int> q;

vector <int> topological(vector <int> G[]){
	vector <int> S;
	while(!q.empty()){
		int u = q.front();
		S.push_back(u); 
		q.pop();
		int size = G[u].size();
		for(int i=0;i<size;i++){
			int V = G[u][i];
			indegree0[V]--;
			if(indegree0[V]==0){
				q.push(V); 
			}
		}
	}
	return S;
}

int main(){
	int V,E;
	cin >> V >> E;
	indegree0.assign(V+1,0); 
	
	int n_1,m_2;
	vector <int> G[V+1];
	for(int i=0;i<E;i++){
		cin >> n_1 >> m_2;
		G[n_1].push_back(m_2);
		indegree0[m_2]++;
	}
	
	for(int i=1;i<=V;i++){
		if(indegree0[i]==0){
			q.push(i);
		}
	}
	vector <int> Ans = topological(G);
	
	int size = Ans.size();
	if(size == V){
		for(int i=0;i<size;i++){
			cout << Ans[i] << endl;
		}	
	}else{
		cout << "NO";
	}
}
