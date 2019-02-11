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
    
        list<int>* getList(){
            return this->l;
        }
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
        
         // Give node to start from visiting.
        void bfs(int src,int &count){
            
            queue<int> q;
            bool *visited= new bool[V];
            
            q.push(src);
            visited[src] = true;
            
            while(!q.empty()){
                // Output current node value.
                int current = q.front();
                count++;
                q.pop();
                // Iterate over neighbours of current node.
                for(auto neighbour:l[current]){
                    
                    // Push into queue if not visited
                    if(!visited[neighbour]){
                        q.push(neighbour);
                        visited[neighbour] = true;
                    }
                }
            }
            
            
        }
        
        Graph reverseEdges(){
            Graph g(V);
            
            for(int i=0;i<V;i++){
                for(auto k:l[i]){
                    g.addEdge(k,i,false);
                }
            }
            return g;
        }
        
        // Kosaraju's algorithm
        // Algorithm: 1. Count number of node using bfs
        //               If less than no. of vertices, return false.
        //            2. Reverse edges of graph and count no. of nodes.
        //               If less than no. of vertices, return false.
        //            3. Otherwise Return true.
        bool isStronglyConnected(int src){
            int count = 0;
            bfs(src,count);
            if(count!=V){
                return false;
            }
            
            Graph g = reverseEdges();
            list<int>* l2 = g.getList();
            count = 0;
            
            queue<int> q;
            bool *visited= new bool[V];
            
            q.push(src);
            visited[src] = true;
            
            while(!q.empty()){
                // Output current node value.
                int current = q.front();
                count++;
                q.pop();
                // Iterate over neighbours of current node.
                for(auto neighbour:l2[current]){
                    
                    // Push into queue if not visited
                    if(!visited[neighbour]){
                        q.push(neighbour);
                        visited[neighbour] = true;
                    }
                }
            }
            if(count!=V){
                return false;
            }
            return true;
        }
};





 
int main() {
    // int vertex;
    // cin>>vertex;
    Graph g(3);
    g.addEdge(0,1,false);
    g.addEdge(1,2,false);
    g.addEdge(2,0,false);
    
    bool is = g.isStronglyConnected(0);
    (is)?cout<<"Strongly Connected":cout<<"Not Strongly Connected";
    
    
    
	return 0;
}