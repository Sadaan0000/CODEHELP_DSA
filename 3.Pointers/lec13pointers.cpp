#include<iostream>
using namespace std;

int main(){

    // int a=5;             /* pointer size remains same because it stores the address of a variable
    // int b=5;              and the address of any type of variable remains the same. */
    // cout<<a<<endl;       // segmentation fault is when u try to access a memory location
    // cout<<&a<<endl;      // which is not created
    // cout<<&b<<endl;          //bad practice  int* ptr;
    
    int a=5;
    int *ptr =&a;
    // cout<<*ptr<<endl;

    cout<<"address of a : "<<&a<<endl;
    cout<<"value stored at ptr : "<<ptr<<endl;
    cout<<"value ptr is pointing at : "<<*ptr<<endl;
    cout<<"address of ptr  : "<<&ptr<<endl;
     
    // int a =5;
    // int *p=&a;
    // cout<<sizeof(p)<<endl;

    // // char c ='a';
    // // char *ch=&c;
    // // cout<<sizeof(ch)<<endl;
    
    // //good practice by creation of null pointer   
    // int* ptr =0;    
    // cout<<*ptr<<endl;

    // int a=5;
    // int* p=&a;
    // //doosra pointer copy kiya hai
    // int* c=p;
    // cout<<*p<<endl;
    // cout<<*c<<endl;
    // *p=*p+1;
    // cout<<*p<<endl;
    // cout<<p<<endl;
    // cout<<&a<<endl;
    // cout<<&p<<endl;
    // cout<<*p<<endl;
    // cout<<p<<endl;
    // cout<<&a<<endl;
    // cout<<&p<<endl;
    // cout<<(*p*2)<<endl;

    

    



    return 0;
}