/**
 * Problem: Topological sort. Kind of like dependency graph.
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
        // Only 1 line added at the bottom of this function for topological sort.
        // Bottom Up Approach 
        void dfsHelper(T node, map<T,bool> &visited, list<T> &ordering){
            
            // Below commented lines could be added so that it becomes the base case.
            // But anyway, the algorithm would work even without base case.
            // if(adj_list[node].empty()){
            //     visited[node] = true;
            //     ordering.push_front(node);
            //     return;
            // }
            
            visited[node] = true;
            
            for(auto neighbour: adj_list[node]){
                
                if(!visited[neighbour]){
                    dfsHelper(neighbour,visited,ordering);
                }
            }
            
            ordering.push_front(node);
            
            
        }
        
        // 1 important difference from dfs is that
        // this algorithm doesn't need src node to start from.
        // Requirement for algorithm to work: DAG (Directed Acyclic Graph)
        void dfsTopologicalSort(){
            // false by default
            map<T, bool> visited;
            list<T> ordering;
            
            
            for(auto i:adj_list){
                // i is pair of (node, list of nodes)
                if(!visited[i.first]){
                    dfsHelper(i.first,visited,ordering);
                }
            }
            
            // Print ordering list
            for(auto i:ordering){
                cout<<i<<"->";
            }
        }

        // BFS approach to topological sort.
        // Basically, we maintain a queue and indegree.
        // We visit each node in queue and push its neighbour only when
        // its indegree becomes 0, aka, all nodes on which it is dependent has
        // been printed.
        void topologicalSort(){
            queue<T> q;
            // Not really need visited map because visited each node 
            // equal to its indegree and pushing it into queue only 
            // when its indegree becomes 0.
            // map<T, bool> visited;
            map<T, int> indegree;
            
            // Set default values
            for(auto i:adj_list){
                T node = i.first;
                indegree[node] = 0;
                // visited[node] = false;
            }
            
            //Initialize indegrees
            for(auto i:adj_list){
                
                for(auto neighbour:i.second){
                    indegree[neighbour]++;
                }
            }
            
            // Find out nodes with 0 indegree and push them into queue.
            for(auto i:adj_list){
                T node = i.first;
                if(!indegree[node]){
                    q.push(node);
                }
            }
            
            while(!q.empty()){
                T node = q.front();
                cout<<node<<"->";
                q.pop();
                
                for(auto neighbour:adj_list[node]){
                    indegree[neighbour]--;
                    if(!indegree[neighbour]){
                        q.push(neighbour);
                    }
                }
            }
            
        }
        
        
        
};





 
int main() {
    Graph<string> g;
    g.addEdge("English","Programming Logic", false);
    g.addEdge("Maths","Programming Logic", false);
    g.addEdge("Programming Logic", "HTML", false);
    g.addEdge("Programming Logic", "Python", false);
    g.addEdge("Programming Logic", "Java", false);
    g.addEdge("Programming Logic", "JS", false);
    g.addEdge("HTML", "CSS", false);
    g.addEdge("CSS", "JS", false);
    g.addEdge("JS", "Web Dev", false);
    g.addEdge("Java", "Web Dev", false);
    g.addEdge("Python", "Web Dev", false);
    
    g.separator();
    g.dfsTopologicalSort();

    g.separator();
    g.topologicalSort();
    
    
	return 0;
}