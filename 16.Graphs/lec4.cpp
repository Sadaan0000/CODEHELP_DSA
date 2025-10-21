#include<iostream>
#include<queue>
#include<stack>
#include<unordered_map>
#include<list>
#include<vector>
#include<limits>
#include<set>
using namespace std;


class Graph{
	public:
	unordered_map<int, list<pair<int,int> > > adjList;

	void addEdge(int u, int v, int wt, bool direction) {
		//direction = 1 -> undirected graph
		//direction => 0 -> directed graph;
		adjList[u].push_back({v,wt});
		if(direction == 1 ) {
			adjList[v].push_back({u,wt});
		}
	}

	void printAdjList() {
		for(auto i: adjList) {
			cout << i.first <<"-> ";
			for(auto j: i.second) {
				cout << "(" << j.first<<", "<<j.second<<"), ";
			}
			cout << endl;
		}
	}

    void shortestPathBfs( int src, int dest ){
        queue<int> q;
        unordered_map<int,bool> visited;
        unordered_map<int,int> parent;

        // initial steps for src
        q.push(src);
        visited[src] = 1;
        parent[src] = -1;

        while( !q.empty() ){
            int fNode = q.front();
            q.pop();

            for( auto nbr : adjList[fNode] ) {
                if( !visited[nbr.first] ) {
                    q.push(nbr.first);
                    visited[nbr.first] = 1;
                    parent[nbr.first] = fNode;
                }
            }
        }

        vector<int> ans;
        int node = dest;

        while( node != -1 ) {
            ans.push_back(node);
            node = parent[node];
        }

        reverse(ans.begin(),ans.end());

        cout << "Printing Ans : ";
        for ( auto i : ans ) {
            cout << i << ", ";
        }cout << endl;

    }

    void topoSortDFS( int src, unordered_map<int,bool> &visited, stack<int> &ans ) {

        visited[src] = true;
        for( auto nbr:adjList[src] ) {
            if( !visited[nbr.first] ){
                topoSortDFS(nbr.first, visited,ans);
            }
        }

        // while returning store the node in stack
        ans.push(src);
    } 

    void shortestpathDfs( int dest, stack<int> topOrder, int n ) {
        vector<int> dist(n,INT_MAX);

        int src = topOrder.top();
        topOrder.pop();
        dist[src] = 0;

        for( auto nbr : adjList[0] ) {
            if( dist[0] + nbr.second < dist[nbr.first] ) {
                dist[nbr.first] = dist[0] + nbr.second;
            }
        }
      

        while( !topOrder.empty() ){

            int topElement = topOrder.top();
            topOrder.pop();

            if( dist[topElement] != INT_MAX ) {
                for( auto nbr : adjList[topElement] ) {
                    if( dist[topElement] + nbr.second < dist[nbr.first] ) {
                        dist[nbr.first] = dist[topElement] + nbr.second;
                    }
                }
            }
        }

        cout << "Printing Ans: " << endl;
        for( int i=0; i<n; i++ ) {
            cout << i <<" -> " <<  dist[i] << endl;
        }

    }
    
    void DijktrasAlgorithm(int src, int n){
        vector<int> dist(n,INT_MAX);
        set<pair<int,int> > st;

        // initialize steps
        dist[src] = 0;
        st.insert(make_pair(0,src));

        while( !st.empty() ) {
            // fetch the smallest or first element from the set 
            auto top = *(st.begin());
            int nodeDistance = top.first;
            int node = top.second;

            // pop from set
            st.erase(st.begin());

            // neighbhour traverse
            for( auto nbr : adjList[node] ) {
                if( nodeDistance + nbr.second < dist[nbr.first] ) {
                    // mujhe update krna hai 
                    // finding entry in set
                    auto result = st.find(make_pair(dist[nbr.first],nbr.first));
                    // if found then remove
                    if( result != st.end() ) {
                        st.erase(result);
                    }
                    // updation indistance array and set
                    dist[nbr.first] = nodeDistance + nbr.second;
                    st.insert(make_pair(dist[nbr.first],nbr.first));

                }
            }

        }
        cout << " printing ans : " << endl;
        for( int i=0; i<n; i++ ){
            cout << dist[i] << endl;
        }cout << endl;
    }

};

int main(){
    Graph g;

    // g.addEdge(0,1,5,0);
    // g.addEdge(0,2,3,0);
    // g.addEdge(2,1,2,0);
    // g.addEdge(1,3,3,0);
    // g.addEdge(2,3,5,0);
    // g.addEdge(2,4,6,0);
    // g.addEdge(4,3,1,0);

    // g.addEdge(6,7,1,0);
    // g.addEdge(7,8,1,0);
    // g.addEdge(8,4,1,0);

    // g.printAdjList();
    // cout << endl; 
    
    // int src = 0;
	// int dest = 3;

    // stack<int> topOrder;
    // unordered_map<int,bool> visited;
    // g.topoSortDFS(0,visited,topOrder);

    // g.shortestpathDfs(3,topOrder,5);

	// g.shortestPathBfs(src, dest);

    g.addEdge(6,3,2,1);
	g.addEdge(6,1,14,1);
	g.addEdge(3,1,9,1);
	g.addEdge(3,2,10,1);
	g.addEdge(1,2,7,1);
	g.addEdge(2,4,15,1);
	g.addEdge(4,3,11,1);
	g.addEdge(6,5,9,1);
	g.addEdge(4,5,6,1);

    g.printAdjList();
    cout << endl; 

    g.DijktrasAlgorithm(6,7);


    return 0;
} 