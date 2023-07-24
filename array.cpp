#include<iostream>
using namespace std;
class Array{
    private:
        int capacity;
        int lastindex;
        int *ptr;
    public:
        Array(int); // creating a constructor, constructor is same name as class name in program
        void append(int); // function it is used for add element inside an arrays
        int get(int);
        int count();
        void printarray();
        int size();
        void insert(int,int);
        bool isEmpty();
        bool isFull();
        void edit(int,int);
        int find(int);
        void del(int);
        ~Array();
};
void Array::del(int index){
    int i;
    if(isEmpty()){
        cout<<endl<<"Array is Empty";
    }
    else if(index<0 || index>lastindex){
        cout<<endl<<"Invalid index";
    }
    else{
        for(i=index;i<lastindex;i++){
            ptr[i]=ptr[i+1];
        }
        lastindex--;
    }
}
int Array::find(int data){
    int i;
    for(i=0;i<=lastindex;i++){
        if(ptr[i]==data)
            return i;
    }
    return -1;
}
Array::~Array(){
    delete []ptr;
}
void Array::edit(int index,int data){
    if(index<0 || index>capacity){
         cout<<"Invalid index"<<endl;
    }
    else{
        ptr[index]=data;
    }
}
Array::Array(int cap){
    capacity=cap;
    lastindex=-1;
    ptr = new int[capacity];
}
void Array::append(int data){
    if(capacity==lastindex+1){
        cout<<"Array is Already Full"<<endl;
    }
    else{
        lastindex++;
        ptr[lastindex]=data;
    }
}
int Array::get(int index){
    if(index<0 && index>capacity-1)
         cout<<"Invalid Index"<<endl;
    return ptr[index];
}
int Array::count(){
    return lastindex+1;
}
void Array::printarray(){
    for(int i=0;i<count();i++){
        cout<<get(i)<<" ";
    }
    cout<<endl;
}
int Array::size(){
    return capacity;
}
void Array::insert(int index,int data){
    if(index<0 && index>capacity-1){
        cout<<"Invalid index"<<endl;
    }
    else{
        ptr[index]=data;
    }
}
bool Array::isEmpty(){
    return lastindex==-1;
}
bool Array::isFull(){
    return lastindex==capacity-1;
}
int main(){
    // creating an object for class Array
    Array a1(5);
    cout<<a1.count()<<endl;
    a1.append(25);
    a1.append(32);
    a1.append(89);
    a1.append(22);
    a1.append(70);
    cout<<endl;
    a1.printarray();
    cout<<endl;
    a1.insert(2,20);
    a1.printarray();
    cout<<a1.find(22)<<endl;
    return 0;
}
