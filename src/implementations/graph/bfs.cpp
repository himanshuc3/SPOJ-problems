/**
 * Problem: BFS.
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
            cout<<endl<<"============"<<endl;
            cout<<"================"<<endl;
        }
        
        // Give node to start from visiting.
        void bfs(T src){
            
            queue<T> q;
            map<T, bool> visited;
            
            q.push(src);
            visited[src] = true;
            
            while(!q.empty()){
                // Output current node value.
                T current = q.front();
                cout<<current<<" ";
                q.pop();
                // Iterate over neighbours of current node.
                for(auto neighbour:adj_list[current]){
                    
                    // Push into queue if not visited
                    if(!visited[neighbour]){
                        q.push(neighbour);
                        visited[neighbour] = true;
                    }
                }
            }
            
            
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
    g.bfs(0);
    
    
	return 0;
}