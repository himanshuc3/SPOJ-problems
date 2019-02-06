/**
 * Problem: Detecting cycle using BFS in undirected graph.
 * 
 */
#include<bits/stdc++.h>
using namespace std;

template<typename T>
class Graph{
        map<T,list<T> > adj_list;
        
    public:
        
        // Add edge from u to v.
        // By default, since bidir is true, make an edge from v to u.
        void addEdge(T u, T v, bool bidir=true){
            adj_list[u].push_back(v);
            if(bidir){
                adj_list[v].push_back(u);
            }
        }
        
        void separator(){
            cout<<endl<<"================"<<endl;
            cout<<"================"<<endl;
        }
        
        // Checking if cycle exists using BFS.
        // Undirected graph. Therefore, need for maintaining parent.
        // In directed graph, no need for parent. Just check if it was
        // visited before or not.
        bool isCyclicBFS(T src){
            
            queue<T> q;
            map<T, bool> visited;
            map<T, T> parent;
            
            // Initializing
            q.push(src);
            parent[src] = src;
            visited[src] = true;
            
            while(!q.empty()){
                // Output current node value.
                T current = q.front();
                q.pop();
                // Iterate over neighbours of current node.
                for(auto neighbour:adj_list[current]){
                    
                    if(visited[neighbour]&&parent[current]!=neighbour){
                        return true;
                    }
                    
                    // Push into queue if not visited
                    if(!visited[neighbour]){
                        q.push(neighbour);
                        visited[neighbour] = true;
                        parent[neighbour] = current;
                    }
                }
            }
            
            return false;
            
            
        }
        
        
        
        
        
};





 
int main() {
    Graph<int> g;
    g.addEdge(1,2);
    g.addEdge(1,4);
    g.addEdge(4,3);
    g.addEdge(2,3);
    
    g.separator();
    bool is = g.isCyclicBFS(1);
    (is)?cout<<"Cyclic":cout<<"Not Cyclic";
    
    
	return 0;
}