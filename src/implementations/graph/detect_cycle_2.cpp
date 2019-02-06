/**
 * Problem: Cycle Detection in Directed Graph using DFS.
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
        
        bool isCyclicHelper(T node, map<T, bool> &visited, map<T, bool> &inStack){
            
            // Processing the current node
            visited[node] = true;
            inStack[node] = true;
            
            // DFS meatball.
            for(auto neighbour: adj_list[node]){
                // 1. If this neighbour is already in stack, that means it is already visited also, so cyclic.
                // 2. If this neighbour is not visited but we get cycle down that branch, return true.
                if(inStack[neighbour] || (!visited[neighbour] && isCyclicHelper(neighbour, visited, inStack))){
                    return true;
                }
            }
            
            // Backtracking.
            // Pop this node off stack.
            // Return false since popping and cycle not present.
            inStack[node] = false;
            return false;
        }
        
        // Checking if cycle exists using DFS.
        // Not passing a src node since we may not be able to traverse the complete 
        // graph from that node since a directed graph.
        bool isCyclicDFS(){
            
            map<T, bool> visited;
            // Kind of like stack, but not really.
            // Detects a back path/edge from descendant to ancestor.
            map<T, bool> inStack;
            
            // To check for cycle in each DFS tree.
            // Basically checking each node.
            for(auto i:adj_list){
                T node = i.first;
                if(!visited[node]){
                    // if not visited check if cycle exists from this node onwards if we do 
                    // dfs traversal.
                    bool isCyclePresent = isCyclicHelper(node, visited, inStack);
                    if(isCyclePresent){
                        return true;
                    }
                }
    
            }
            
            return false;
            
        }
        
        
        
        
        
};





 
int main() {
    Graph<int> g;
    g.addEdge(0,2, false);
    g.addEdge(0,1,false);
    g.addEdge(2,3,false);
    g.addEdge(2,4,false);
    // g.addEdge(3,0,false);
    g.addEdge(4,5,false);
    g.addEdge(1,5,false);
    
    g.separator();
    bool is = g.isCyclicDFS();
    (is)?cout<<"Cyclic":cout<<"Not Cyclic";
    
    
	return 0;
}