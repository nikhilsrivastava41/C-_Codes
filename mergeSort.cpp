#include<bits/stdc++.h>
using namespace std;
void merge(vector<int> &v,int s,int e){
    int mid = (s+e)/2;
    int len1 = mid-s+1;
    int len2 = e-mid; //as we included the mid element in the first half
    int idx = s;
    vector<int> v1(len1);
    vector<int> v2(len2);
    for(int i=0;i<len1;i++){
        v1[i] = v[idx++];
    }
    for(int i=0;i<len2;i++){
        v2[i] = v[idx++];
    }
    idx=s;
    int i1=0;
    int i2=0;
    while(i1<len1 && i2<len2){
        if(v1[i1]<v2[i2]){
            v[idx++] = v1[i1++];
        }
        else{
            v[idx++] = v2[i2++];
        }
    }
    while(i1<len1){
        v[idx++] = v1[i1++];
    }
    while(i2<len2){
        v[idx++] = v2[i2++];
    }
    return;
}
void mergeSort(vector<int> &v,int s,int e){
    if(s>=e){
        return;
    }
    int mid = (s+e)/2;
    //sort the left half
    mergeSort(v,s,mid);
    //sort the right half
    mergeSort(v,mid+1,e);

    merge(v,s,e);
}
int main(){
    vector<int> v;
    for(int i=0;i<6;i++){
        v.push_back(6-i);
    }
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
    mergeSort(v,0,v.size()-1);
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
    return 0;
}
