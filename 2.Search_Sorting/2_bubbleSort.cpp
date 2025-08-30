// #include<iostream>
// #include<vector>
// #include<algorithm>
// using namespace std;
// void bubbleSort(vector<int> &v){
//     for(int i=0;i<v.size()-1;i++){
//         for(int j=0;j<v.size()-1-i;j++){
//             if(v[j] > v[j+1]){
//                 swap(v[j],v[j+1]);
//             }
//         }
//     }
    
// }
// int main()
// {
//     vector<int> v{2,5,3,9,7};
//     bubbleSort(v);
//     for(int i : v){
//         cout << i << " ";
//     }
//     return 0;
// }

#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono> // for timing

using namespace std;
using namespace chrono;

void bubbleSort(vector<int>& v) {
    for (int i = 0; i < v.size() - 1; i++) {
        for (int j = 0; j < v.size() - 1 - i; j++) {
            if (v[j] > v[j + 1]) {
                swap(v[j], v[j + 1]);
            }
        }
    }
}

int main() {
    vector<int> v{2, 5, 3, 9, 7,4,6,2,0,9,8,7,6,5,4,3,2,1,1,2,5,3,4,2,90};

    bubbleSort(v);  
    
    for (int i : v) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
