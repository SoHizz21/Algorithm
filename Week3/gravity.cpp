#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;
int main(){
	
	int in1;
	cin >> in1;
	
	int n_1,n_2,l;
	int u_min,v_min,d_min;
	
	stack<int> S;
	priority_queue< int,vector<int>,greater<int> > pq;
	int V,E,S_Node;
	
	for(int i=0;i<in1;i++){
		
		cin >> V >> E >> S_Node;
		
		vector <int> G[V];
		int len[V][V];
		int count[V];
		bool Check[V];
		
		for(int i=0;i<V;i++){
			count[i] = 0;
        }
		
		for(int i=0;i<E;i++){
			cin >> n_1 >> n_2 >> l;
			G[n_1].push_back(n_2);
			len[n_1][n_2] = l;
			count[n_1]++;
			
			G[n_2].push_back(n_1);
			len[n_2][n_1] = l;
			count[n_2]++;
		}
		
		int d[V];
		stack<int> tt,kk;
		    
		for(int i = 0 ; i < V ; i++){
            d[i] = 10000;
            Check[i] = false;
            tt.push(1);
        }
        
        S.push(S_Node);
    	Check[S_Node] = true;
    	d[S_Node] = 0;
    	int o = 0;
    	
    	u_min=v_min=d_min=-1;
    	int mindv = 10000;
    	while(o < V-1){
    		kk=S;
    		mindv = 10000;
    		while(!kk.empty()){
    			n_1 = kk.top();
    			kk.pop();
    			for(int j=0;j<count[n_1];j++){
    				n_2 = G[n_1][j];
    				if(d[n_1]+len[n_1][n_2]<mindv && !Check[n_2] && Check[n_1]){
                        u_min = n_1;
                        v_min = n_2;
                        mindv = d[n_1]+len[n_1][n_2];
                    }
				}
			}
			if(!Check[v_min] && Check[u_min]){
                n_1 = u_min;
                n_2 = v_min;
                S.push(n_2);
                d[n_2] = d[n_1]+len[n_1][n_2];
                Check[n_2] = true;
            }
            o++;
		}
   		pq.push(S.top());
        S.pop();
        
        while (!S.empty()){
            if(d[pq.top()] == d[S.top()]){
                pq.push(S.top());
                S.pop();
            }else{
                break;
            }
        } 
        while(!pq.empty()){
            cout << pq.top() << " ";
            pq.pop();
        }
        cout << endl;	
	}
}
