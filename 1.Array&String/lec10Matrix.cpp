#include<iostream>
#include<vector>
using namespace std;

void printVector(const vector<int> &v) {
    for (int x : v) {
        cout << x << " ";
    }
    cout << endl;
}

void printMatrix(vector<vector<int>> &arr){
    for( int i=0; i<=arr.size()-1; i++ ){
        for( int j=0; j<arr[i].size(); j++ ){
            cout << arr[i][j] << " ";
        }
        cout << endl; 
    }
}

void transposeMatrix(vector<vector<int>> &arr, vector<vector<int>> &brr){
    int rows = arr.size();
    int cols = arr[0].size();

    //resize brr for transpose colsxrows
    brr.assign(cols, vector<int>(rows));

    for(int i=0;i<=arr.size()-1;i++){
        for(int j=0;j<arr[i].size();j++){
            brr[j][i] = arr[i][j] ;
        }
    }
}

int maxIntOfMatrix(vector<vector<int>> &arr){
    int ans = arr[0][0];

    for(int i=0;i<arr.size();i++){
        for(int j=0;j<arr[i].size();j++){
            if(arr[i][j] > ans){
                ans = arr[i][j];
            }
        }
    }
    return ans;
}

int mixIntOfMatrix(vector<vector<int>> &arr){
    int ans = arr[0][0];

    for(int i=0;i<arr.size();i++){
        for(int j=0;j<arr[i].size();j++){
            if(arr[i][j] < ans){
                ans = arr[i][j];
            }
        }
    }
    return ans;
}

bool isPresent(vector<vector<int>> &arr, int k){
    for(int i=0;i<arr.size();i++){
        for(int j=0;j<arr[i].size();j++){
            if(arr[i][j] == k){
                return true;
            }
        }
    }
    return false;
}

vector<int> printsumColWise(vector<vector<int>> &arr){
    vector<int> ans;
    int rows = arr.size();
    int cols = arr[0].size();

    for (int col = 0; col < cols; col++) {
        int sum = 0;
        for (int row = 0; row < rows; row++) {
            sum += arr[row][col];
        }
        ans.push_back(sum);
    }
    return ans;
}

vector<int> printsumRowWise(vector<vector<int>> &arr){
    vector<int> ans;

    for(int row=0;row<arr.size();row++ ){
        int sum=0;
        for(int col=0;col<arr[row].size();col++ ){
            sum += arr[row][col];
        }
        ans.push_back(sum);
    }
    return ans;
}

int main()
{

    vector<vector<int>> arr;
    vector<vector<int>> brr;

    arr.push_back({11,22,-3,11});
    arr.push_back({41,59,67,12});
    arr.push_back({7,-86,95,13});

    printMatrix(arr);
    cout << endl;

    //transpose
    transposeMatrix(arr,brr);
    printMatrix(brr);

    //MAX & MIN of a Matrix
    // cout << "Maximum Integer of the Matrix is :  " << maxIntOfMatrix(arr) << endl;
    // cout << "Minimum Integer of the Matrix is :  " << mixIntOfMatrix(arr) << endl;

    //Item present in the matrix 
    // if(isPresent(arr,5)){
    //     cout << " Found in the Matrix..";
    // }
    // else{
    //     cout << " Not Found in the Matrix..";
    // }

    //print sum column wise
    // vector<int> colSums = printsumColWise(arr);
    // cout << "Column-wise sums: ";
    // printVector(colSums);

    //print sum row wise 
    // vector<int> rowSums = printsumRowWise(arr);
    // cout << "Row-wise sums: ";
    // printVector(rowSums);
    
    return 0;
}