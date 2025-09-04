#include<iostream>
#include<vector>
using namespace std;

int partition(vector<int> &arr, int start, int end){
    //step1: choose pivot element 
    int pivotIndex = start;
    int pivotElement = arr[start];

    //step2: find right position for pivot elemnt and place it there
    int count = 0;
    for( int i=start+1;i<=end;i++ ){
        if( arr[i] <= pivotElement ){
            count++;
        }
    }

    //jab main loop se bahar hoon toh mere paas pivot ki right position ka index ready hai
    int rightIndex = start+count;
    swap( arr[pivotIndex], arr[rightIndex] );
    pivotIndex = rightIndex;

    //step3: left mein small and right mein small
    int i = start;
    int j = end;

    while( i<pivotIndex && j>pivotIndex ){
        while(arr[i] <= pivotElement ){
            i++;
        }
        while(arr[j] > pivotElement ){
            j--;
        }

        //2 case hoskte hain 
        //A-> you found the elements to swap
        //B-> no need to swap
        if( i<pivotIndex && j>pivotIndex ){
            swap(arr[i],arr[j]);
        }
    }
    return pivotIndex;
}

void quickSort(vector<int> &arr, int start, int end){
    //base case
    if( start >= end ){
        return;
    }

    //partition logic return pivot element 
    int p = partition(arr,start,end);

    //recursive calls
    //pivot element -> left
    quickSort(arr, start, p-1);

    //pivot element -> right
    quickSort(arr, p+1, end);

}

int main(){
    vector<int> arr{9,8,7,6,5,4,3,4,2,2,2,2,2,0,0,1};
    int start =  0;
    int end = arr.size()-1;

    for( int i:arr ){
        cout << i << " ";
    }
    cout << endl;

    quickSort(arr,start,end);

    for( int i:arr ){
        cout << i << " ";
    }

    return 0;
}