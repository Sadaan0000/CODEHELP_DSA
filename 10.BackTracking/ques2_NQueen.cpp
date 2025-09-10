#include<iostream>
#include<vector>
using namespace std;

void printSolution(vector<vector<char>> &board,int n){
    int count = 0;
    for(int i=0;i<n;i++ ){
        for( int j=0;j<n;j++ ){
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    count++;
}

bool isSafe(int row, int col, vector<vector<char>> &board, int n){
    //check krna chahte hain ki current cell mein queen rkh skte hain ki nhin
    int i = row;
    int j = col;

    //check row 
    while( j>=0 ){
        if( board[i][j] == 'Q' ){
            return false;
        }
        j--;
    }

    i = row;
    j = col;
    //check upperleft diagonal
    while( i>=0 && j>=0 ){
        if( board[i][j] == 'Q' ){
            return false;
        }
        i--;
        j--;
    }

    i = row;
    j = col;
    //check bottomleft diagonal
    while( i<n && j>=0 ){
        if( board[i][j] == 'Q' ){
            return false;
        }
        i++;
        j--;
    }

    // khin parbhi queen nhin mili 
    //iska matlb ye position safe hai 
    return true;
}

void solve(vector<vector<char>> &board, int col, int n){
    //base case
    if( col>=n ){
        printSolution(board,n);
        return;
    }

    // 1 case solve krna hai baaki recursion sambhaal lega 
    for(int row=0;row<n;row++ ){
        if(isSafe(row,col,board,n )){
            //rakh do
            board[row][col] = 'Q';

            //recursion solution ladega 
            solve(board,col+1,n);

            //backtracking
            board[row][col] = '-';
        }
    }
}

int main(){
    int n = 7;
    vector<vector<char>> board(n,vector<char>(n,'-'));
    int col = 0;

    solve(board,col,n);

    return 0;
}