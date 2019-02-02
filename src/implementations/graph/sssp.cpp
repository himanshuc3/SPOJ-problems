/**
 * Problem: Single Source shortest path.
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
        
        // Single Source shortest path from given node.
        void sssp(T src){
            queue<T> q;
            map<T,int> distance;
            // parent not really needed here.
            map<T,T> parent;
            
            // initializing each node's distance to infinity
            for(auto i: adj_list){
                distance[i.first] = INT_MAX;
            }
            q.push(src);
            distance[src] = 0;
            parent[src] = src;
            
            while(!q.empty()){
                // Output current node value.
                T current = q.front();
                q.pop();
                
                
                // Iterate over neighbours of current node.
                for(auto neighbour:adj_list[current]){
                    
                    // Push into queue if not visited
                    if(distance[neighbour]==INT_MAX){
                        q.push(neighbour);
                        distance[neighbour] = distance[current] + 1;
                        parent[neighbour] = current;
                    }
                }
            }
            
            //Print the distances to all nodes
            for(auto i:adj_list){
                cout<<"Distance of "<<i.first<<": "<<distance[i.first];
                cout<<endl;
            }
        }
        
        void printGraph(){
            for(auto row:adj_list){
                cout<<row.first<<"->";
                
                // row.second is linked list
                for(auto entry:row.second){
                    cout<<entry<<", ";
                }
                cout<<endl;
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
    g.sssp(0);
    
    
	return 0;
}