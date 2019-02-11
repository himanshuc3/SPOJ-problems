/**
 * Problem: Journey To the moon
 * 
 */
#include<bits/stdc++.h>
using namespace std;

class Graph{
        // Number of vertices
        long long V;
        // For reference: http://www.cplusplus.com/reference/list/list/
        // These basically have doubly-linked list as their underlying implementation.
        // Since this is a polong longer, it acts as long long* arr = new arr[5]
        // Dynamic allocation because number of vertices known at runtime.
        list<long long> *l;
        
    public:
        Graph(long long V){
            this->V = V;
            // Basically makes V linked lists at runtime and returns reference to first one(0).
            l = new list<long long>[V];
        }
        
        // Add edge from u to v.
        // By default, since bidir is true, make an edge from v to u.
        void addEdge(long long u, long long v, bool bidir=true){
            l[u].push_back(v);
            if(bidir){
                l[v].push_back(u);
            }
        }
        
        void separator(){
            cout<<endl<<"================"<<endl;
            cout<<"================"<<endl;
        }
        
        // Meat ball of DFS
        void dfsHelper(long long node, bool *visited, long long &country_size){
            if(visited[node]){
                return;
            }
            
            country_size++;
            visited[node] = true;
            
            for(auto neighbour: l[node]){
                
                if(!visited[neighbour]){
                    dfsHelper(neighbour,visited, country_size);
                }
            }
            
            
        }
        
        
        // DFS initializing.
        // Total ways: VC2 - sum(country_sizeC2)
        long long dfs(){
            // false by default
            bool *visited = new bool[V];
            for(long long i=0;i<V;i++){
                visited[i] = false;
            }
            long long total_ways = V*(V-1)/2;
            for(long long i=0;i<V;i++){
                if(!visited[i]){
                    long long country_size = 0;
                    dfsHelper(i,visited, country_size);
                    total_ways -= (country_size)*(country_size-1)/2;
                }
            }
            
           return total_ways; 
        }
};





 
int main() {
    long long vertex,p;
    long long v1,v2;
    cin>>vertex;
    cin>>p;
    Graph g(vertex);
    for(long long i=0;i<p;i++){
        cin>>v1;
        cin>>v2;
        g.addEdge(v1,v2);
    }
    long long ways = g.dfs();
    cout<<ways;
    
	return 0;
}