/**
 * Problem: Snakes and ladders.
 * Solution: Using bfs. Assuming standing at 0, to reach 36 and a roll of dice results in [1,6].
 *           Nodes in Graph = [0,36];
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
        
        // Calculates shortest path from src to each node.
        // Works on bfs.
        // Stops when destination reached though.
        int sssp(T src, T dest){
            
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
                        // Here parent is usefull, for tracking the path.
                        parent[neighbour] = current;
                    }
                }
            }
            
            // Print path from src to node using parent map to backtrack from dest.
            T temp = dest;
            while(parent[temp]!=temp){
                cout<<temp<<"<--";
                temp = parent[temp];
            }
            cout<<src;
            
            
            // Distance from src to dest.
            return distance[dest];
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
        
        void setBoard(int board[]){
            // A positive represents a jump of that many steps from specified index aka a ladder.
            // Similarly, for snakes.
            // Example: From 2 we have a ladder to 15.
            board[2] = 13;
            board[5] = 2;
            board[9] = 18;
            board[18] = 11;
            board[17] = -13;
            board[20] = -14;
            board[24] = -8;
            board[25] = -10;
            board[32] = -2;
            board[34] = -22;
        }

};




 
int main() {
    Graph<int> g;
    
    // Setting snakes and ladders.
    int board[50] = {0};
    g.setBoard(board);
    
    // Construct the graph. 
    // A few edge cases not handled and therfore extra edges added like 36 -> [37,42].
    // Doesn't affect the solution because we specify dest in find sssp.
    for(int u=0;u<=36;u++){
        // At every node you can throw a dice
        // NOTE: Sometimes overshooting board edge limit for v, i.e., 36.
        for(int dice=1;dice<=6;dice++){
            int v = u + dice + board[u+dice];
            g.addEdge(u,v,false);
        }
    }
    
    g.separator();
    g.sssp(0,36);
    
    
	return 0;
}