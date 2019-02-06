/**
 * Problem: Dijkstra's Algorithm for finding minimum distance from src to every other node having
 *          positive edge weights.
 * 
 */
#include<bits/stdc++.h>
using namespace std;

template<typename T>
class Graph{
    // Can use either of map or unordered_map 
    unordered_map<T, list<pair<T,int> > > adj_list;
        
    public:
        
        // Add edge from u to v.
        // By default, since bidir is true, make an edge from v to u.
        void addEdge(T u, T v, int dist, bool bidir=true){
            adj_list[u].push_back(make_pair(v,dist));
            if(bidir){
                adj_list[v].push_back(make_pair(u,dist));
            }
        }
        
        void print(){
            for(auto i:adj_list){
                T node = i.first;
                cout<<node<<"->";
                for(auto l: adj_list[node]){
                    cout<<"("<<l.first<<", "<<l.second<<")";
                }
                cout<<endl;
            }
        }
        
        void separator(){
            cout<<endl<<"================"<<endl;
            cout<<"================"<<endl;
        }
        
        void dijkstraSSSP(T src){
            unordered_map<T, int> dist;
            // Set to find minimum node at each iteration
            // First parameter int, because by default set sorts according 
            // to first parameter.
            // Like a queue in BFS.
            // But since if gives min node in O(1), it is time efficient.
            set<pair<int, T> > s;
            
            // Initialize all distances to infinity
            for(auto i: adj_list){
                dist[i.first] = INT_MAX;
            }
            
            
            // Initialize
            dist[src] = 0;
            s.insert(make_pair(0,src));
            
            while(!s.empty()){
                // Find the pair at the front because that is the smallest distance
                // at this particular point
                
                // s.begin() is a pointer to front. We dereference it.
                
                auto smallest = *(s.begin());
                T node = smallest.second;
                int nodeDistance = smallest.first;
                s.erase(s.begin());
                
                // iterate over neighbours of current node
                for(auto child:adj_list[node]){
                    if(nodeDistance + child.second < dist[child.first]){
                        dist[child.first] = nodeDistance + child.second;
                        // In the set updation is not possible. So, find, erase and push.
                        auto f = s.find(make_pair(dist[child.first],child.first));
                        if(f!=s.end()){
                            s.erase(f);
                        }
                        
                        // Insert new pair
                        s.insert(make_pair(dist[child.first],child.first));
                        
                    }
                }
            }
            
            // Print all minimum distances.
            for(auto d:dist){
                cout<<d.first<<" is located at "<<d.second<<" distance away from "<<src<<endl;
            }
        }
        
};





 
int main() {
    Graph<int> g;
    g.addEdge(1,2,1);
    g.addEdge(1,3,4);
    g.addEdge(2,3,1);
    g.addEdge(3,4,2);
    g.addEdge(1,4,7);
    // g.print();
    g.dijkstraSSSP(1);
    
    
	return 0;
}