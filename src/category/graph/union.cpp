/**
 * Problem: Disjoint set algorithm ( union-find ).
 *          TO-DO: not working: Segmentation fault.
 * 
 */
#include<bits/stdc++.h>
using namespace std;

class Edge{
    public:
    int src,dest;
};

class Graph{
    public:
    int V,E;
    Edge* edges;
    
    Graph(int V,int E){
        this->V = V;
        this->E = E;
        edges = new Edge[E];
    }
    
    // find parent of i vertex
    int find(int parent[],int i){
        if(parent[i]==-1)
            return i;
        return find(parent,parent[i]);
    }
    
    // Union x and y if possible
    void Union(int parent[], int x,int y){
        int xset = find(parent,x);
        int yset = find(parent,y);
        if(xset!=yset)
            parent[xset] = yset;
    }
    
    // Check for cycle detection
    bool isCycle(){
        int *parent = new int[V];
        for(int i=0;i<V;i++){
            parent[i] = i;
        }
        
        for(int i=0;i<E;i++){
            int x = edges[i].src;
            int y = edges[i].dest;
            
            if(x==y){
                return true;
            }
            
            Union(parent,x,y);
        }
        return false;
    }
    
};



int main() {
    Graph g(3,3);
    g.edges[0].src = 0;
    g.edges[0].dest = 1;
    
    g.edges[1].src = 1;
    g.edges[1].dest = 2;
    
    g.edges[2].src = 0;
    g.edges[2].dest = 2;
    
    if(g.isCycle()){
        cout<<"It contains cycle";
    }else{
        cout<<"No cycle";
    }
    
   
	return 0;
}