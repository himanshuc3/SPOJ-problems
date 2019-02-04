/**
 * Problem: Modifying DFS to print all nodes of a disconnected graph containing multiple components.
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
            
            // Atleast one component exist.
            int component=1;
            for(auto i:adj_list){
                if(!visited[i.first]){
                    dfsHelper(i.first,visited);
                    component++;
                }
            }
            
            cout<<endl<<"No. of components: "<<component;
            
        }
};





 
int main() {
    Graph<string> g;

    // Andaman and Nicobar is disconnected to other states/cities.
    g.addEdge("Amritsar","Jaipur");
    g.addEdge("Amritsar","Delhi");
    g.addEdge("Delhi", "Jaipur");
    g.addEdge("Mumbai", "Jaipur");
    g.addEdge("Mumbai", "Bhopal");
    g.addEdge("Delhi", "Bhopal");
    g.addEdge("Mumbai", "Bangalore");
    g.addEdge("Agra", "Delhi");
    g.addEdge("Andaman", "Nicobar");
    
    g.separator();
    g.dfs("Amritsar");
    
    
	return 0;
}