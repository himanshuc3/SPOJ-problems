/**
 * Problem: DFS. Recursive way of traversing graph.
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
        
        // Meat ball of DFS
        void dfsHelper(T node, map<T,bool> &visited){
            if(visited[node]){
                return;
            }
            
            cout<<node<<" ";
            visited[node] = true;
            
            for(auto neighbour: adj_list[node]){
                
                if(!visited[neighbour]){
                    dfsHelper(neighbour,visited);
                }
            }
            
            
        }
        
        
        // DFS initializing.
        void dfs(T src){
            // false by default
            map<T, bool> visited;
            dfsHelper(src,visited);
            
        }
};





 
int main() {
    Graph<int> g;
    g.addEdge(0,1);
    g.addEdge(0,4);
    g.addEdge(2,1);
    g.addEdge(2,4);
    g.addEdge(3,2);
    g.addEdge(3,4);
    g.addEdge(3,5);
    
    g.separator();
    g.dfs(0);
    
    
	return 0;
}