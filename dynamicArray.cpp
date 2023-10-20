#include<bits/stdc++.h>
using namespace std;
class DynamicArray{
    private:
        int capacity;
        int lastindex;
        int *ptr;
    public:
        DynamicArray(int);
        void dynamicArray();
        void append(int);
        bool isFull();
        bool isEmpty();
        int count();
        int get(int);
        void printArray();
        int size();
};
DynamicArray::DynamicArray(int cap){
    capacity = cap;
    lastindex = -1;
    ptr = new int[capacity];
}
void DynamicArray::dynamicArray(){
    int *temp = new int [2*capacity];
    for(int i =0;i<=lastindex; i++){
        temp[i] = ptr[i];
    }
    delete[]ptr;
    ptr = temp;
    capacity*=2;
}
void DynamicArray::append(int data){
    if(isFull()){
        dynamicArray();
    }
    lastindex++;
    ptr[lastindex] = data;
}
bool DynamicArray::isEmpty(){
    return lastindex == -1;
}
bool DynamicArray::isFull(){
    return lastindex == capacity-1;
}
int DynamicArray::count(){
    return lastindex+1;
}
int DynamicArray::get(int index){
    if(index<0 || index> capacity-1){
        std::cout<<"Invalid index"<<::endl;
    }
    return ptr[index];
}
void DynamicArray::printArray(){
    int i;
    for(i=0;i<count(); i++){
        std::cout<<get(i)<<::endl;
    }
}
int DynamicArray::size(){
    return capacity;
}
// Deriver Program for Checking the working of code
int main(){
    int n,b;
    std::cout<<"Enter the size for Dynamic Array"<<::endl;
    std::cin>>n;
    DynamicArray a(n);
    std::cout<< "Size of Array is "<< a.size()<<::endl;
    for(int i =0; i<n; i++){
        cin>>b;
        a.append(b);
    }
    a.append(6);
    a.append(8);
    std::cout<<"Element inside a Dynamic Array is "<<::endl;
    a.printArray();
    return 0;
} 