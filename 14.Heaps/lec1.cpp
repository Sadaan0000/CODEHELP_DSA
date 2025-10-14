#include<iostream>
using namespace std;

class Heap {
    public:
    int arr[101];
    int size;

    Heap(){
        size = 0;
    }

    void insert(int value){
        // value insert kro end mein

        size = size+1;
        int index = size;
        arr[index] = value;

        // is value ko sahi jagah position pe rkhna hai 
        while( index > 1 ){
            int parentIndex = index/2;

            if( arr[index] > arr[parentIndex]){
                swap(arr[index], arr[parentIndex]);
                index = parentIndex;
            }
            else{
                break;
            }
        }
    }

    int deleteNode(){
        int ans = arr[1];
        // replace root node value with last node data
        arr[1] = arr[size];
        size--;

        // place root node ka data on its correct position
        int index = 1;
        while( index < size ){
            int left = 2*index;
            int right = 2*index+1;

            int largest = index;
            
            if( left < size && arr[largest] < arr[left] ){
                largest = left;
            }

            if( right < size && arr[largest] < arr[right] ){
                largest = right;
            }

            if( largest == index ){
                // value is at its correct position
                break;
            }
            else{
                swap(arr[index],arr[largest]);
                index = largest;
            }
        }
        return ans;
    }

};

    void heapify(int arr[], int n, int i){
        int index = i;
        int leftIndex = 2*i;
        int rightIndex = 2*i+1;

        int largest = index;

        if( leftIndex <= n && arr[largest] < arr[leftIndex] ){
            largest = leftIndex;
        }
        if( rightIndex <= n && arr[largest] < arr[rightIndex] ){
            largest = rightIndex;
        }

        if( index != largest ){
            // left ya right child me se koi > hogaya hai currrentNode se 
            swap(arr[index], arr[largest] );
            index = largest;
            heapify(arr,n,index);
        }
    }

    void buildHeap(int arr[], int n){
        for( int i=n/2; i>0; i-- ){
            heapify(arr,n,i);
        }
    }    

    void heapSort(int arr[], int n){
        int index = n;
        while( n != 1 ){
            swap(arr[1], arr[n--]);
            
            // heapify
            heapify(arr,n,1);
        }
    }
    
int main(){
    Heap h;
    // h.arr[0] =  -1;
    // h.arr[1] =  100;
    // h.arr[2] =  50;
    // h.arr[3] =  60;
    // h.arr[4] =  40;
    // h.arr[5] =  45;
    // h.size =  6;

    // h.insert(100);
    // h.insert(50);
    // h.insert(60);
    // h.insert(40);
    // h.insert(50);
    // h.insert(110);

    int arr[] = {-1,12,15,13,11,14};
    int n = 5;
    buildHeap(arr,n);
    h.size = n;

    for (int i = 1; i <= n; i++) {
        h.arr[i] = arr[i];
    }

    cout << "Printing the heap " << endl;
    for( int i=1; i<=n; i++ ){
        cout << arr[i] << " ";
    }
    cout << endl;

    heapSort(arr,n);

    // h.insert(20);
    // // h.deleteNode();
    cout << "Printing the heap " << endl;
    for( int i=0; i<n; i++ ){
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}