#include<iostream>
#include<queue>
#include<stack>
#include<unordered_map>
#include<list>
using namespace std;
template <typename T>

class Graph{
    public:
    unordered_map<T, list<T> > adjlist; 

    void addEdge(T u, T v, bool direction) {
        //direction = 0 -> undirected graph
        //direction = 1 -> directed graph
        //create an edge from u to v
        adjlist[u].push_back(v);
        if(direction == 0 && u!=v )
        {
        //undirected edge
        //create an edge from v to u
        adjlist[v].push_back(u);
        }
    }

    void printAdjacencyList() {
        for(auto node: adjlist) {
            cout << node.first << "-> " ;
            for(auto neighbour: node.second) {
                cout <<neighbour<<", ";
            }
            cout << endl;
        }
    }

    void bfs(int src, unordered_map<int, bool>& visited) {
    queue<int> q;
    
    q.push(src);
    visited[src] = true;

    while(!q.empty()) {
      int frontNode= q.front();
      q.pop();
      cout << frontNode << ", ";

      //insert neighbours
      for(auto neighbour: adjlist[frontNode]) {
        if(!visited[neighbour] ) {
          q.push(neighbour);
          visited[neighbour] = true;
        }
      }
    }
  }

    void dfs(int src, unordered_map<int, bool>& visited) {
    cout << src << ", ";
    visited[src] = true;

    for(auto neighbour: adjlist[src]) {
      if(!visited[neighbour] ) {
        dfs(neighbour, visited);
      }
    }
  }

    void topoSortDFS( int src, unordered_map<int,bool> &visited, stack<int> &ans ) {

        visited[src] = true;
        for( auto nbr:adjlist[src] ) {
            if( !visited[nbr] ){
                topoSortDFS(nbr, visited,ans);
            }
        }

        // while returning store the node in stack
        ans.push(src);
    } 

    void topoLogicalSortBFS(int n, vector<int> &ans ) {
        queue<int> q;
        unordered_map<int,int> indegree;

        // indegree calculate
        for ( auto i:adjlist ) {
            int src = i.first;
            for( auto nbr : i.second ) {
                indegree[nbr]++;
            }
        }

        // put all nodes inside queue, which has indegree = 0
        for( int i=0; i<n; i++ ){
            if( indegree[i] == 0 ){
                q.push(i);
            }
        }

        // bfs logic 
        while( !q.empty() ){
            int fNode = q.front();
            q.pop();
            ans.push_back(fNode);

            // cout << fNode << " ";

            for( auto nbr:adjlist[fNode] ){
                indegree[nbr]--;
                // check for zero again
                if( indegree[nbr] == 0 ){
                    q.push(nbr);
                }
            }
        }
    }

};



int main(){
    Graph<int> g;

    //n -> number of nodes in graph
    int n = 8;
    g.addEdge(2,4,1);
    g.addEdge(2,5,1);
    g.addEdge(4,6,1);
    g.addEdge(5,3,1);
    g.addEdge(3,7,1);
    g.addEdge(6,7,1);
    g.addEdge(7,0,1);
    g.addEdge(7,1,1);

    g.printAdjacencyList();
    cout << endl;  

    vector<int> ans;
    
    g.topoLogicalSortBFS(n,ans);
    
    cout << " Topological sort " << endl;
    for( auto i:ans ){
        cout << i << " ";
    }cout << endl;

    // unordered_map<int,bool> visited;
    // stack<int> ans;
    // for( int i=0; i<n; i++ ){
    //     if( !visited[i] ){
    //         g.topoSortDFS(i,visited,ans);
    //     }
    // }
    // cout << "Topological Sort : ";
    // while( !ans.empty() ){
    //     cout << ans.top() << " ";
    //     ans.pop();
    // }

    return 0;
}          