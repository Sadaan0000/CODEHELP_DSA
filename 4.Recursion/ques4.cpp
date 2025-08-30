#include<iostream>
#include<vector>
using namespace std;

bool isSortedArray( vector<int> &arr, int i ){
    if( i == arr.size()-1 ) return true;

    if( arr[i] > arr[i+1] ) return false;
    
    return isSortedArray( arr, i+1 );
}

int main(){
    vector<int> arr{5,6,7,4,8,9};
    int i=0;

    if( isSortedArray(arr,i) ) {
        cout << "Array is Sorted" << endl;
    }
    else{
        cout << "Array is not sorted." << endl;
    }

    return 0;
}