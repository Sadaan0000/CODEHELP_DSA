#include<iostream>
using namespace std;

void findMax(int arr[], int n, int i, int& max){
    //base case
    if( i>=n ){
        return;
    }
    //1 case solve krna hai 
    if( arr[i] > max ){
        max = arr[i];

    }
 
    findMax(arr, 7, i+1, max);
}

void findMin(int arr[], int n, int i, int& min){
    //base case
    if( i>=n ){
        return;
    }
    //1 case solve krna hai 
    if( arr[i] < min ){
        min = arr[i];

    }
 
    findMin(arr, 7, i+1, min);
}

int main(){
    int arr[] = { 10,30,21,40,76,3,78};
    int n = 7;
    int max = INT_MIN;
    int min = INT_MAX;
    int i = 0;

    findMax(arr,n,i,max);
    cout << "max number is : " << max << endl; 

     findMin(arr,n,i,min);
    cout << "min number is : " << min << endl; 

    return 0;
}