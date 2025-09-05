#include<iostream>
#include<vector>
using namespace std;

bool isSafe(int x, int y, int n, vector<vector<int>> &maze, vector<vector<bool>> &visited){
    if( (x>=0 && x<n) && (y>=0 && y<n) && (maze[x][y] == 1) && (visited[x][y] == false) ){
        return true;
    }
    else{
        return false;
    }
}

void solveMaze(vector<vector<int>> &maze, int n, int srcx, int srcy, vector<vector<bool>> &visited, vector<string> &path, string output ){

    // base case -> reached destination
    if(srcx == n-1 && srcy == n-1){
        path.push_back(output);
        return;
    }

    // Down -> i+1, j
    if(isSafe(srcx+1, srcy, n, maze, visited)){
        visited[srcx+1][srcy] = true;
        solveMaze(maze, n, srcx+1, srcy, visited, path, output+'D');
        
        // backtrack
        visited[srcx+1][srcy] = false; 
    }

    // Left -> i, j-1
    if(isSafe(srcx, srcy-1, n, maze, visited)){
        visited[srcx][srcy-1] = true;
        solveMaze(maze, n, srcx, srcy-1, visited, path, output+'L');
        
        // backtrack
        visited[srcx][srcy-1] = false;
    }

    // Right -> i, j+1
    if(isSafe(srcx, srcy+1, n, maze, visited)){
        visited[srcx][srcy+1] = true;
        solveMaze(maze, n, srcx, srcy+1, visited, path, output+'R');
        
        // backtrack
        visited[srcx][srcy+1] = false;
    }

    // Up -> i-1, j
    if(isSafe(srcx-1, srcy, n, maze, visited)){
        visited[srcx-1][srcy] = true;
        solveMaze(maze, n, srcx-1, srcy, visited, path, output+'U');
        
        // backtrack
        visited[srcx-1][srcy] = false;
    }
}

int main(){
    int n = 4; 

    
    vector<vector<int>> maze = {
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {1, 1, 0, 0},
        {0, 1, 1, 1}
    };

    vector<vector<bool>> visited(n, vector<bool>(n, false));
    vector<string> path;

    if(maze[0][0] == 0){
        cout << "No path exists.";
        return 0;
    }

    visited[0][0] = true;
    solveMaze(maze, n, 0, 0, visited, path, "");

    if(path.empty()){
        cout << "No path exists.";
    } else {
        cout << "Paths:\n";
        for(auto &p : path){
            cout << p << "\n";
        }
    }

    return 0;
}
