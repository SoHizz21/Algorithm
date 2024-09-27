#include <iostream>
#include <vector>
#include <queue>
using namespace std;
void BFS(vector <int> *Node,int Start_N,int N){
	vector <int> day;
	vector <int> level;
	vector <bool> discover;
	
	discover.resize(N,false); 
	level.resize(N,-1); 
	day.resize(N,0); 

	queue <int> q;
	level[Start_N]=0;
	q.push(Start_N);
	discover[Start_N]=true;
	
	
	while(!q.empty()){
		int u = q.front();
		int size = Node[u].size();
		for(int i=0;i<size;i++){
			int V=Node[u][i];
			if(!discover[V]){
				discover[V]=true;
				level[V]=level[u]+1;
				day[level[V]]++;
				q.push(V); 
			}
		}
		q.pop();
	}
	
	int size_day= day.size();
	int max=0;
	int index;
	for(int i=0;i<size_day;i++){
		if(max<day[i]){
			max=day[i];
			index=i;
		}
	}
	
	cout << max << " "<< index << endl;
}


int main(){
	int N;
	cin >> N;
	
	vector <int> node[N];

	for(int i=0;i<N;i++){
		int edge;
		cin>> edge;
		
		for(int j=0;j<edge;j++){
			int n;
			cin >> n;
			node[i].push_back(n);
		}
	}
	
	int c_case;
	cin>> c_case;
	for(int i=0;i<c_case;i++){
		int check;
		cin >> check;
		
		if(node[check].empty()){
			cout << "0" << endl;
			continue;
		}
		
		BFS(node,check,N);
	}		

//	for(int i=0;i<N;i++){
//		int size = node[i].size();
//		for(int j=0;j<size;j++){
//			cout << node[i][j] << " ";
//		}
//		cout << endl;
//	}
//6
//2 1 2
//2 3 4
//3 0 4 5
//1 4
//0
//2 0 2
//3
//0
//4
//5
}
