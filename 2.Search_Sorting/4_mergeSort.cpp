#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void mergeSort(vector<int> &v){
    
}

int main() {
    vector<int> v{16,25,81,442,59,26,70,23,19,10};

    // insertionSort(v);  
    mergeSort(v);
    
    for (int i : v) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}