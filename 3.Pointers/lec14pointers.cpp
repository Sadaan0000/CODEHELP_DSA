#include<iostream>
using namespace std;

void solve(int arr[]){
    cout << "size outside main function " << sizeof(arr) << endl;

    cout<< "arr "<< arr << endl;
    cout<< "&arr "<< &arr << endl;

    arr[0]=50;
}


int main(){  
    
    int arr[4]={12,14,16,18};

    // cout<<arr<<endl;
    // cout<<arr[0]<<endl;
    // cout<<&arr<<endl;
    // cout<<&arr[0]<<endl;     //*arr depicts the value present at the base address of the array arr.

    // int *p=arr;
    // cout<<&p<<endl;

    // cout<<*arr<<endl;
    // cout<<*arr+1<<endl;  
    // cout<<*(arr+1)<<endl;
    // cout<<*(arr+2)<<endl;
    // cout<<*(arr+3)<<endl;
    // cout<<*(arr+4)<<endl;

    // int i=0; 
    // cout<<arr[i]<<endl;
    // cout<<i[arr]<<endl;


    // cout<<*(arr+2)<<endl;

    // cout << sizeof(arr) << endl;

    // int* p = arr;
    // cout << sizeof(p) << endl;

    // cout << sizeof(*p) << endl;

    // char ch[10]="babbar";
    // char* c=ch;
    
    // cout << ch << endl;
    // cout << &ch << endl;
   
    // cout << &c << endl;
    // cout << *c << endl;
    // cout << c+2 << endl;
    // cout << c+1 << endl;
    // cout << c+4 << endl;

    // cout << "size of main inside main function " << sizeof(arr) << endl; 
    // cout<<arr<<endl;
    // cout<<&arr<<endl;
    // for(int i=0; i<5; i++){
    //     cout << arr[i] << endl;
    // }


    // cout << "-----------------------------" << endl; 
  
    // solve(arr);

    // //printing array inside main
    // for(int i=0; i<5; i++){
    //     cout << arr[i] << endl;
    // }

    



    return 0;
}