#include<bits/stdc++.h>
#include<thread>
#include<mutex>
#include<vector>
using namespace std;

 vector<int> arr(100,1);
 long long finalsum=0;
 mutex m;
void print(std::string s){
    cout<<"hello "<<s<<endl;
    return ;
}
void sum(int n,int order){
    m.lock();
   
    long long s=0;

    cout<<"Hi "<<order<<endl;
    for(int idx=order*(100/n);idx<n;idx++){
        s+=arr[idx];
    }
    finalsum+=s;
    m.unlock();
    cout<<s<<endl;
}
int main(){
    int i=10;
    vector<thread> th(10);
    for(int j=0;j<i;j++){
        th[j] = thread(sum,i,j);
    }
    for(auto &idx:th){
        idx.join();
    }
    return 0;
}