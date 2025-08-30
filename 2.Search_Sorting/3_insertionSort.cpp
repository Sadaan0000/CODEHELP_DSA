#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void insertionSort(vector<int> &v){
    for(int i=1;i<v.size();i++){
        int temp = v[i];
        int j=i-1;
        for(;j>=0;j--){
            if(v[j] > temp){
                v[j+1] = v[j];
            }
            else{
                break;
            }
        }
        v[j+1] = temp;
    }
}

void reverseArray(vector<int> &v){
    int l=0;
    int h=v.size()-1;
    while(l<h){
        swap(v[l],v[h]);
        l++;
        h--;
    }
}
int main() {
    vector<int> v{1,2,3,4,5,6,7,8,9,0};

    // insertionSort(v);  
    reverseArray(v);
    
    for (int i : v) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}