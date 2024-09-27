#include <iostream>
#include <vector>
using namespace std;

int MergeSort(vector<int> &N,int l,int mid,int r){
    int count=0;
    vector <int> LN(mid-l+1);
    vector <int> RN(r-mid);
    
    for(int i=0;i<LN.size();i++){
        LN[i]=N[l+i];
    }
    
    for(int i=0;i<RN.size();i++){
        RN[i]=N[mid+1+i];
    }
    
    int i=0;
    int j=0;
    int k=l;
    while(i<LN.size() && j<RN.size()){
        if(LN[i] <= RN[j]){
            N[k] = LN[i];
            i++;
        }else{
            N[k] = RN[j];
            j++;
            count += (mid-l+1-i);
        }
        k++;
    }
    
    while(i<LN.size()){
        N[k]= LN[i];
        i++;
        k++;
    }
    
    while(j<RN.size()){
        N[k]= RN[j];
        j++;
        k++;
    }
    
    return count;
}
    

int Merge_Count(vector<int> &N,int l,int r){
    int count=0;
    if(l<r){
        int mid = l+(r-l)/2;
        count += Merge_Count(N,l,mid);
        count += Merge_Count(N,mid+1,r);
        
        count += MergeSort(N,l,mid,r); 
    }    
    return count;
}

int inversions(vector<int> &N){
    return Merge_Count(N,0,N.size()-1);
}

int main(){
    int n;
    cin >> n;
    
    vector <int> inNum;
    for(int i=0;i<n;i++){
        int Num;
        cin >> Num;
        inNum.push_back(Num);
    }
    
    int count = inversions(inNum);
    cout << count; 
}
