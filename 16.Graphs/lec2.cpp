#include<iostream>
#include<queue>
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

    bool isCyclicBFS(int src, unordered_map<int,bool> &visited ){
            queue<int> q;
            unordered_map<int,int> parent;

            q.push(src);
            visited[src] = true;
            parent[src] = -1;

            while(!q.empty()){
                int frontNode = q.front();
                q.pop();

                for( auto nbr:adjlist[frontNode] ){
                    if(!visited[nbr]){
                        q.push(nbr);
                        visited[nbr] = true;
                        parent[nbr] = frontNode;
                    }
                    else{
                        // already visited
                        if( nbr != parent[frontNode])
                            // cycle present
                            return true;
                    }
                }
            }

            return false;

        }

    bool isCyclicDFS(int src, unordered_map<int,bool> &visited, int parent ){
        visited[src] = true;

        for( auto nbr:adjlist[src] ){
            if( !visited[nbr] ){
                bool checkAAgeKaAnswer = isCyclicDFS(nbr, visited, src );
                if( checkAAgeKaAnswer == true ){
                    return true;
                }

                if( visited[nbr] && nbr != parent ){
                    // cycle present
                    return true;
                }
            }
        }
        return false;
    }




};



int main(){
    Graph<int> g;

    //n -> number of nodes in graph
    int n = 5;
    g.addEdge(0,1,0);
    g.addEdge(1,2,0);
    g.addEdge(2,3,0);
    g.addEdge(3,4,0);
    g.addEdge(4,4,0);

    g.printAdjacencyList();
    cout << endl;

    bool ansBFS = false;
    unordered_map<int, bool> visitedBFS;

    //run a loop for all nodes
    for(int i=0; i<n; i++) {
        if(!visitedBFS[i]) {
            ansBFS = g.isCyclicBFS(i,visitedBFS);
            if( ansBFS == true )
                break;
        }
    }

    if( ansBFS == true ){
        cout << "Cycle is present. " << endl;
    }
    else{
        cout << "Cycle is not present. " << endl;
    }

    


    bool ansDFS = false;
    unordered_map<int, bool> visitedDFS;

    //run a loop for all nodes
    for(int i=0; i<n; i++) {
        if(!visitedDFS[i]) {
            ansDFS = g.isCyclicDFS(i,visitedDFS, -1);
            if( ansDFS == true )
                break;
        }
    }

    if( ansDFS == true ){
        cout << "Cycle is present. " << endl;
    }
    else{
        cout << "Cycle is not present. " << endl;
    }

    return 0;
}