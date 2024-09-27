#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int checkmin(vector <vector<int>> &keep, int N){
	vector<int> T(N+1,INT_MAX);
	T[0]=0;
	
	int Ksize = keep.size();
	for(int i=1;i<=N;i++){
		for(int j=0;j<Ksize;j++){
			int Ni = keep[j][0];
			int Pi = keep[j][1];
			
			if(i >= Ni && T[i-Ni] != INT_MAX){
				T[i] = min(T[i],T[i-Ni]+Pi);
			}
		}
	}
	return T[N];
}

int main(){
	vector <vector<int>> keep(3,vector <int>(2));
	
	for(int i=0;i<3;i++){
		int n , p;
		cin >> n >> p;
		keep[i]={n,p};
	}
	
	int n=0;
	cin >> n;
	
	for(int i=0;i<3;i++){
		if(keep[i][1] >= n){
			cout << keep[i][1];
			return 0;
		}
	}
	int ans = checkmin(keep,n);
	cout << ans;
}
