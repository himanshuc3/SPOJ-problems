/**
 * Problem: Detecting cycle using BFS and DFS in undirected graph.
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
        
        bool isCyclicHelper(T node, map<T, bool> &visited,T parent){
            
            visited[node] = true;
            
            for(auto neighbour: adj_list[node]){
                if(!visited[neighbour]){
                    bool isCycle = isCyclicHelper(neighbour, visited, node);
                    if(isCycle){
                        return true;
                    }
                }
                if(visited[neighbour] && neighbour!=parent){
                    return true;
                }
            }
            
            return false;
        }
        
        // DFS cyclic undirected graph
        bool isCyclicDFS(){
            map<T, bool> visited;
            
            
            for(auto i: adj_list){
                if(!visited[i.first]){
                    bool isCyclic = isCyclicHelper(i.first,visited, i.first);
                    if(isCyclic){
                        return true;
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
    
    bool is = g.isCyclicDFS();
    (is)?cout<<"Cyclic":cout<<"Not Cyclic";
    g.separator();
    is = g.isCyclicBFS(1);
    (is)?cout<<"Cyclic":cout<<"Not Cyclic";
    
    
	return 0;
}