#include<iostream>
#include<vector>
using namespace std;

int binarySearch( vector<int> &arr, int start, int end, int key){
    //base case
    if( start>end ) return -1;

    int mid = start + (end-start) /2;

    //if key found at mid 
    if( arr[mid] == key ){
        return mid;
    }

    //mid<key -> do right search
    if( arr[mid]<key ){
        return binarySearch( arr, mid+1, end, key);
    }
    //mid>key -> do left search
    else{
        return binarySearch(arr, start, mid-1, key);
    }
    
}


int main(){
    vector<int> arr{1,2,3,4,5,6,7,8,9};
    int start=0;
    int end=arr.size()-1;
    int key=3;
    int ans = binarySearch(arr,start,end,key);
    if( ans != -1 ){
        cout << " key Found at "<< ans << endl;
    }
    else{
        cout << " Key not found." << endl;
    }

    return 0;
}