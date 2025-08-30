#include<iostream>
#include<queue>
#include<stack>
using namespace std;

void solve( int arr[], int n, int k){
        deque<int> q;

        //process first window of size k 
        for( int i=0; i<k; i++){
            if(arr[i] < 0){
                q.push_back(i);
            }
        }

        //remaining window to process
        for(int i=k; i<n; i++){
            //answer dedo purani window ko
            if(q.empty()){
                cout << 0 << " ";
            }
            else{
                cout << arr[q.front()] << " ";
            }
            //out of window elements ko rmeove krdo 
            while((!q.empty()) && (i - q.front() >= k)){
                q.pop_front();

            }
            //check curren elemnt for insertion
            if(arr[i] < 0){
                q.push_back(i);
            }
        }
        //answer print kro for list window
        if(q.empty()){
            cout << 0 << " ";
        }
        else{
            cout << arr[q.front()] << " "; 
        }
}

int main(){
cout << endl;

    int arr[] = {12,-1,-7,8,-15,30,12,56};
    int size = 8;
    int k =3;

    solve(arr,size,k);


    
    
cout << endl;   
return 0;
}