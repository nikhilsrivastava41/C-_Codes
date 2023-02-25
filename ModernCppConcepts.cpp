#include<iostream>
#include<string>
#include<memory>
using namespace std;

//****template****
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
//****template****

//****UserDefinedLiterals****
    long double operator"" _m(long double x){return x*1000;}
    long double operator"" _cm(long double x){return x*10;}
    long double operator"" _mm(long double x){return x;}
    /*
    all these still takes time at run time, to reduce that we can make these as constexpr so 
    that it happens at compile time
    */
    //constexpr long double operator"" _m(long double x){return x*1000;}
    
//****UserDefinedLiterals****

class Dog{
    Dog();      //constructor
    Dog(const Dog&);        //copy constructor
    Dog& operator=(const Dog&);     //copy assignment operator
    ~Dog();         //Destructor
    
    //if any of the above is written the move constructor cannot be made

    //Dog(&&Dog);     //move constructor
    //Dog& operator=(Dog&&);    //move assignment operator

};
class Cat{
    string name_;
    public:
    Cat(string x){
        cout<<"Cat is created "<<x<<endl;
        name_=x;
    }
    ~Cat(){
        cout<<"Cat is destroyed "<<name_<<endl;
    }
    void bark(){
        cout<<"meow  "<<name_<<endl;
    }
};
void foo(){
    Cat* c1 = new Cat("Ruby");

    shared_ptr<Cat> c2(new Cat("Lucy"));
    shared_ptr<Cat> c3=make_shared<Cat>("Taylor");  //this is faster and exception safe
    c1->bark();
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

    //****UserDefinedLiterals****
    long double height=3.4_cm;
    cout<<height<<endl;
    cout<< height + 5.6 + 12.0_m<<endl;
    //****UserDefinedLiterals****

    foo();
    return 0;
}