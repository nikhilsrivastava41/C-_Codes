#include<iostream>
using namespace std;

template<typename T>

T square(T x){
    return x*x;
}
// double square(double x){
//     return x*x;
// }
template<typename T>
class Bovector{
    int size=0;
    public:
    T arr[1000];
    void push(T x){
        arr[size]=x;
        size++;
    }
    int getSize(){
        return size;
    }
    T get(int idx){
        return arr[idx];
    }
    void print(){
        for(int i=0;i<size;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
};
template<typename T>

Bovector<T> operator*(Bovector<T> arr1, Bovector<T> arr2){
    Bovector<T> arr;
    for(int i=0;i<arr1.getSize();i++){
        arr.push(arr1.get(i)*arr2.get(i));
    }
    return arr;
}
int main(){

    //****template****
    int area = square<int>(3);
    double  areaD= square<double>(3.3);     //not necessary to provide the datatype incase of function template
    cout<<area<<"\t"<<areaD<<endl;

    Bovector<int> bv;       //mentioning the datatype for a class template is necessary
    bv.push(2);
    bv.push(3);
    bv.push(4);
    bv.push(5);
    bv.print();
    bv = square(bv);
    bv.print();

    //****template****

    //****lambda functions****

    cout<< [](int x,int y){return x+y;}(3,4)<<endl;
    auto f = [](int x,int y){return x+y;};
    cout<<f(3,4)<<endl;

    //****lambda functions****

    return 0;
}