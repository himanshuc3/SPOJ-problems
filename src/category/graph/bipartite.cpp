/**
 * Problem: Bipartite Graph implementation.
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
        void addEdge(int u, int v, bool bidir=true){
            l[u].push_back(v);
            if(bidir){
                l[v].push_back(u);
            }
        }
        
        // Bipartite graph means the color can be colored/separated into 2 parts 
        // such that 2 nodes having same color cannot be connected.
        bool isBipartite(int src){
            
            queue<int> q;
            int *colors = new int[V];
            
            for(int i=0;i<V;i++){
                colors[i]=-1; // Means not visited
            }
            
            bool ans = true;
            
            q.push(src);
            colors[src] = 1;
            
            while(!q.empty()){
                // Output current node value.
                int current = q.front();
                q.pop();
                // Iterate over neighbours of current node.
                for(auto neighbour:l[current]){
                    
                    // Push into queue if not visited
                    if(colors[neighbour]==-1){
                        colors[neighbour] = 1- colors[current];
                        q.push(neighbour);
                    }else if(colors[neighbour]==colors[current]){
                        return false;
                    }
                }
            }
            return true;
            
            
        }
};





 
int main() {
    // int vertex;
    // cin>>vertex;
    Graph g(4);
    g.addEdge(0,1);
    g.addEdge(0,3);
    g.addEdge(0,2);
    g.addEdge(1,3);
    g.addEdge(2,3);
    if(g.isBipartite(0)){
        cout<<"Bipartite";
    }else{
        cout<<"Not bipartite";
    }
    
    
	return 0;
}