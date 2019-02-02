/**
 * Problem: Generic Implementation of a graph using hasmap simulating adjacency list.
 * Pros:    Easier, faster and recommended implmentation.
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
    // int vertex;
    // cin>>vertex;
    Graph<string> g;
    g.addEdge("Putin","Trump", false);
    g.addEdge("Putin","Modi", false);
    g.addEdge("Putin","Pope", false);
    g.addEdge("Modi","Trump", true);
    g.addEdge("Modi","Yogi", true);
    g.addEdge("Yogi","Prabhu", false);
    
    g.printGraph();
    
    
	return 0;
}