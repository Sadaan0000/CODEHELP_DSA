#include<iostream>
#include<vector>
using namespace std;

void wavePrintMatrixCol(vector<vector<int>> v){
    int c = v.size();
    int r = v[0].size();
    for(int startCol=0;startCol<r;startCol++){
        //even no of col
        if((startCol & 1) == 0){
            for(int i=0;i<c;i++){
                cout << v[i][startCol] << " ";
            }
        }
        else{
            //odd no of column
            for(int i=c-1;i>=0;i--){
                cout << v[i][startCol] << " ";
            }
        }
    }
}
void wavePrintMatrixRow(vector<vector<int>> v){
    int r = v.size();
    int c = v[0].size();
    for(int startrow=0;startrow<r;startrow++){
        //even no of row
        if((startrow & 1) == 0){
            for(int i=0;i<c;i++){
                cout << v[startrow][i] << " ";
            }
        }
        else{
            //odd no of row
            for(int i=c-1;i>=0;i--){
                cout << v[startrow][i] << " ";
            }
        }
    }
}
int main(){
    vector<vector<int>> v{
        {1,2,3,4},
        {5,6,7,8},
        {9,10,11,12},
        {13,14,15,16}
    };
    // wavePrintMatrixCol(v);
    wavePrintMatrixRow(v);
    return 0;
}