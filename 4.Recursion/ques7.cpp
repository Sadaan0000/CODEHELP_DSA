#include<iostream>
#include<vector>
using namespace std;

void merge(vector<int> &arr, int start, int end, int mid){
    //calculate length of left and right part of array 
    int len1 = mid-start+1;
    int len2 = end-mid;

    //form temporary arrays
    vector<int> left(len1), right(len2);

    //copy data 
    for( int i=0;i<len1;i++ ){
        left[i] = arr[start+i];
    }
    for( int i=0;i<len2;i++ ){
        right[i] = arr[mid+1+i];
    }

    //merge logic
    int leftIndexArray = 0;
    int rightIndexArray = 0;
    int mainIndexArray = start;

    while( leftIndexArray<len1 && rightIndexArray<len2 ){
        if( left[leftIndexArray] < right[rightIndexArray] ){
            arr[mainIndexArray++] = left[leftIndexArray++];
        }
        else{
            arr[mainIndexArray++] = right[rightIndexArray++];
        }
    }
    //copy logic for remaining array for remaining left and right part of the array
        while( leftIndexArray<len1 ){
            arr[mainIndexArray++] = left[leftIndexArray++];
        }
        while( rightIndexArray<len2 ){
            arr[mainIndexArray++] = right[rightIndexArray++];
        }
}

void mergeSort(vector<int> &arr, int start, int end){
    //base case 
    // if start >=end then it's a single element in the array
    if( start>=end ){
        return;
    }

    //calculate mid
    int mid = (start+end)/2;

    //left part of array ko sort krdo
    mergeSort(arr,start,mid);

    //right part of array ko sort krdo
    mergeSort(arr,mid+1,end);

    //left aur right part ko merge krdo 
    merge(arr,start,end,mid);
}

int main(){
    vector<int> arr = {9,8,7,6,5,4,3,2,1,0};
    
    for( int i:arr ){
        cout << i << " ";
    }

    cout << endl;
    mergeSort(arr, 0, arr.size()-1);

    for( int i:arr ){
        cout << i << " ";
    }
    
    return 0;
}