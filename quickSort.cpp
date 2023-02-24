#include<bits/stdc++.h>
using namespace std;
int partition(vector<int> &v,int s,int e){
    int pivot = v[s];
    int count=0;
    // put the pivot in its right place
    for(int i=s+1;i<=e;i++){
        if(v[i]<=pivot){
            count++;
        }
    }
    int pivotIdx = s + count;
    swap(v[pivotIdx],v[s]);
    // put all elements less than pivot at its left
    int i = s;
    int j=e;
    while(i<pivotIdx && j> pivotIdx){
        while(v[i]<=pivot){
            i++;
        }
        while(v[j]>=pivot){
            j--;
        }
        swap(v[i],v[j]);
        i++;
        j--;
    }
    return pivotIdx;
}
void quickSort(vector<int> &v, int s ,int e){
    if(s>=e)
        return;

    int pidx = partition(v,s,e);
    quickSort(v,s,pidx-1);
    quickSort(v,pidx+1,e);
}
int main(){
    vector<int> v(6);
    v[0] = 100;
    v[1] = 0;
    v[2] = 200;
    v[3] = -100;
    v[4] = 2;
    v[5] = -20;
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
    quickSort(v,0,v.size()-1);
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
    return 0;
}
