#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool isSafe(int x, int y, int n, vector<vector<int>> &maze, vector<vector<bool>> &visited){
    return (x>=0 && x<n && y>=0 && y<n && maze[x][y] == 1 && !visited[x][y]);
}

void solveMaze(vector<vector<int>> &maze, int n, int srcx, int srcy, vector<vector<bool>> &visited, vector<string> &path, string output ){

    // base case -> reached destination
    if(srcx == n-1 && srcy == n-1){
        path.push_back(output);
        return;
    }

    // movement directions: D, L, R, U
    int dx[4] = {1, 0, 0, -1};
    int dy[4] = {0, -1, 1, 0};
    char dirChar[4] = {'D', 'L', 'R', 'U'};

    for(int k=0; k<4; k++){
        int newx = srcx + dx[k];
        int newy = srcy + dy[k];

        if(isSafe(newx, newy, n, maze, visited)){
            
            visited[newx][newy] = true;

            solveMaze(maze, n, newx, newy, visited, path, output + dirChar[k]);

            // backtrack
            visited[newx][newy] = false;
        }
    }
}

int main(){
    int n = 3;  // Fixed size
    vector<vector<int>> maze = { {1, 0, 0}, {1, 1, 0}, {1, 1, 1} };

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
        //lexicographical order
        sort(path.begin(), path.end());

        cout << "Paths:\n";
        for(auto &p : path){
            cout << p << "\n";
        }
    }

    return 0;
}
