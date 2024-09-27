#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(const pair<pair<int, int>, int>& a, const pair<pair<int, int>, int>& b) {
    return a.second < b.second;
}

int find(int i,vector <int> &parent) {
    if (parent[i]!=i) {
        parent[i]=find(parent[i],parent);
    }
    return parent[i];
}

void Sum_set(int u, int v,vector <int> &parent,vector <int> &rank) {
    int Root_U = find(u,parent);
    int Root_V = find(v,parent);
    if (Root_U != Root_V) {
        if (rank[Root_U] < rank[Root_V]) {
            parent[Root_U] = Root_V;
        }else if(rank[Root_U] > rank[Root_V]) {
            parent[Root_V] = Root_U;
        }else{
            parent[Root_U] = Root_V;
            rank[Root_V]++;
        }
    }
}


int kruskal(vector <pair <pair <int,int>,int>>& G, int n) {
	int sum=0;
    sort(G.begin(), G.end(), compare);

	vector <int> parent;
	vector <int> rank;
    parent.resize(n+1,0);
    rank.resize(n+1,0);
    
    for (int i=1; i<=n; i++){
    	parent[i] = i;
	}

    for (int i = 0; i < G.size(); i++) {
        int u = G[i].first.first;
        int v = G[i].first.second;
        
        if (find(u,parent) != find(v,parent)) {
            Sum_set(u,v,parent,rank);
            sum += G[i].second;
        }
    }
    
    int first = find(1,parent);
    for(int i=2;i<=n;i++){
    	if(first!=find(i,parent)){
    		sum=-1;
    		return sum;
		}
	}
    return sum;
}

int main(){
	int N,M;
	cin >> N >> M;
	
	vector <pair <pair <int,int>,int>> G;
	for(int i=0;i<M;i++){
		int u,v,w;
		cin >> u >> v >> w;
		
		G.push_back(make_pair (make_pair (u,v),w));
	}
	int ans = kruskal(G,N);
	
	cout << ans;
}
