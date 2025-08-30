#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void selectionSort(vector<int> v){
    for( int i=0; i<v.size()-1; i++ ){
        int minIndex = i;
        for( int j=i+1; j<=v.size()-1; j++ ){
            if(v[j] < v[minIndex])
                minIndex = j;
        }
        swap(v[i],v[minIndex]);
    }
}
int main()
{
    vector<int> v{2,5,3,9,7};
    selectionSort(v);
    for(int i : v){
        cout << i << " ";
    }
    return 0;
}