#include <iostream>
#include <vector>
#include <algorithm>
using namespace std; 

bool compare(const vector<int>& a,const vector<int>& b){
    return a[1]<b[1];
}

int binarySearch(const vector<vector<int>>& intervals,int index){
    int low=0,high = index-1;
    while(low <= high){
        int mid = (low+high)/2;
        if (intervals[mid][1] <= intervals[index][0]){
            if (intervals[mid+1][1] <= intervals[index][0]){
                low = mid+1;
            }else{
                return mid;
            }
        }else{
            high = mid-1;
        }
    }
    return -1;
}

vector<vector<int>> WIS(const vector<vector<int>>& intervals){
    vector<vector<int>> result;
    if (intervals.empty()){
        return result;
    }

    vector<vector<int>> W = intervals;
    sort(W.begin(),W.end(),compare);

    int n = W.size();
    vector<int> T(n,0);
    vector<int> select;

    for(int i = 0; i < n; ++i){
        int j = binarySearch(W,i);
        if (j != -1){
            T[i] = max(T[i-1],W[i][2]+T[j]);
        }else{
            T[i] = max(T[i-1],W[i][2]);
        }
    }

    int i = n-1;
    while(i >= 0){
        if (i == 0 || T[i] != T[i-1]){
            select.push_back(i);
            i = binarySearch(W,i);
        }else{
            --i;
        }
    }

    for(int index :select){
        result.push_back(W[index]);
    }
    return result;
}

int main(){
	int n,s,f,w;
	
	cin >> n;
	vector<vector<int>> keep(n,vector<int>(3));

    for(int i = 0; i < n; i++){
        cin >> s >> f >> w;
        keep[i] ={s,f,w};
    }
    
	vector<vector<int>> selectedJob = WIS(keep);
	
	int size = selectedJob.size();
	int sum=0;
	for(int i=0;i<size;i++){
		sum += selectedJob[i][2];
	}
	
	cout << sum << endl;
}
