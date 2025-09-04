#include<iostream>
#include<vector>
using namespace std;

void merge(vector<int> &arr, int start, int end, int mid){
    int len1 = mid-start+1;
    int len2 = end-mid;

    //temporary arrays
    vector<int> left(len1), right(len2);
    
    //copy data
    for( int i=0;i<len1;i++ ){
        left[i] = arr[start+i];
    }
    for( int i=0;i<len2;i++ ){
        right[i] = arr[mid+1+i];
    }

    //merge logic
    int leftIndex = 0;
    int rightIndex = 0;
    int mainArrayIndex = start;

    while( leftIndex<len1 && rightIndex<len2 ){
        if( left[leftIndex] < right[rightIndex]){
            arr[mainArrayIndex++] = left[leftIndex++];
        }
        else{
            arr[mainArrayIndex++] = right[rightIndex++];
        }
    }

    //copy logic for left array
    while( leftIndex<len1){
        arr[mainArrayIndex++] = left[leftIndex++];
    }

    //copy logic of right array
    while( rightIndex<len2 ){
        arr[mainArrayIndex++] = right[rightIndex++];
    }

}

void mergeSort(vector<int> &arr, int start, int end){
    //base case 
    // start should be less than end 
    if( start>=end ){
        return;
    }

    //calculate mid
    int mid = (start+end)/2;

    //left part ko sort krdo
    mergeSort(arr,start,mid);

    //right part ko sort krdo
    mergeSort(arr,mid+1,end);

    //merge krdo
    merge(arr,start,end,mid);
    
}

int main(){
    vector<int> arr{9,8,7,6,5,4,3,4,2,1};
    int start =  0;
    int end = arr.size()-1;

    for( int i:arr ){
        cout << i << " ";
    }
    cout << endl;

    mergeSort(arr,start,end);

    for( int i:arr ){
        cout << i << " ";
    }

    return 0;
}