//peerapat saengphoem 6530300376
#include <iostream>
#include <algorithm>
using namespace std;

struct record{
	int link_S;
	int link_F;
};

bool compare(struct record a,struct record b){
	return a.link_F < b.link_F;
}

int main(){
	int in1;
	int count=0;
	int time=-1;
	
	cin >> in1;
	
	struct record *F_L = new struct record[in1];
	for(int i=0;i<in1;i++){
		cin >> F_L[i].link_S;
		cin >> F_L[i].link_F;
	}
	
	sort(F_L,F_L+in1,compare);
	
	for(int j=0;j<in1;j++){ 
		if(F_L[j].link_S>time){ //chance >= /> 
			time = F_L[j].link_F;
			count++;
		}
	}
	cout << count;
}
