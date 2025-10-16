#include<iostream>
#include<queue>
using namespace std;

int getKthSmallestElement(vector<int> &arr, int n, int k ){
    // create max heap 
    priority_queue<int> pq;
    // insert initial k elements of array
    for( int i=0; i<k; i++ ){
        pq.push(arr[i]);
    }

    // for remianing elements push only if they are less than top 
    for( int i=k; i<n; i++ ){
        int element = arr[i];
        if( element < pq.top() ){
            pq.pop();
            pq.push(element);
        }
    }

    int ans = pq.top();
    return ans;
}

int getKthGreatestElement(vector<int> &arr, int n, int k ){
    // create min heap 
    priority_queue<int, vector<int>, greater<int>> pq;
    // insert initial k elements of array
    for( int i=0; i<k; i++ ){
        pq.push(arr[i]);
    }

    // for remianing elements push only if they are large than top 
    for( int i=k; i<n; i++ ){
        int element = arr[i];
        if( element > pq.top() ){
            pq.pop();
            pq.push(element);
        }
    }

    int ans = pq.top();
    return ans;
}

bool solve(){

}

int main(){
    // max heap
    // priority_queue<int> pq;
    // pq.push(3);
    // pq.push(4);
    // pq.push(5);
    // pq.push(9);
    // pq.push(1);
    // pq.push(90);
    // cout << pq.top() << endl;
    // pq.pop();
    // cout << pq.top() << endl;
    // cout << pq.empty();
    // cout << pq.size();
    // min heap
    // priority_queue<int,vector<int>,greater<int>> pq;
    // pq.push(3);
    // pq.push(4);
    // pq.push(5);
    // pq.push(9);
    // pq.push(1);
    // cout << pq.top() << endl;

    // vector<int> arr = {10,5,20,4,15};
    // int n = 5;
    // int k = 1;
    // // int ans = getKthSmallestElement(arr, n, k);
    // int ans = getKthGreatestElement(arr, n, k);
    // cout << ans;
    

    

    return 0;
}