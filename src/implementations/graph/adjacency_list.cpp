/**
 * Problem: Implementation of graph as adjacency list.
 * Example: 0 -> 1,2
 *          1 -> 2,3
 *          2 -> 0
 *          3 -> NULL
 * Assumption: if v = 4, vertices are [0,1,2,3] i.e. 0-indexed.
 * Those Who forgot are condemned to repeat (TWFACTP => TFACT)
 * TFACT: this->V & V are same for in class member functions. 
 * 
 */
#include<bits/stdc++.h>
using namespace std;

class Graph{
        // Number of vertices
        int V;
        // For reference: http://www.cplusplus.com/reference/list/list/
        // These basically have doubly-linked list as their underlying implementation.
        // Since this is a pointer, it acts as int* arr = new arr[5]
        // Dynamic allocation because number of vertices known at runtime.
        list<int> *l;
        
    public:
        Graph(int V){
            this->V = V;
            // Basically makes V linked lists at runtime and returns reference to first one(0).
            l = new list<int>[V];
        }
        
        // Add edge from u to v.
        // By default, since bidir is true, make an edge from v to u.
        void addEdge(int u, int v, int bidir=true){
            l[u].push_back(v);
            if(bidir){
                l[v].push_back(u);
            }
        }
        
        void printGraph(){
            for(int i=0;i<V;i++){
                cout<<i<<"->";
                for(int vertex: l[i]){
                    cout<<vertex<<", ";
                    
                }
                cout<<endl;
            }
        }
};





 
int main() {
    // int vertex;
    // cin>>vertex;
    Graph g(5);
    g.addEdge(0,1);
    g.addEdge(0,4);
    g.addEdge(4,3);
    g.addEdge(1,4);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(1,3);
    
    g.printGraph();
    
    
	return 0;
}