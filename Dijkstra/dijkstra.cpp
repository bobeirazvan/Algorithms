#include <fstream>
#include <vector>
#include <queue>

using namespace std;

ifstream fin("dijkstra.in");
ofstream fout("dijkstra.out");

const int max_size = 50005 ;

class heap {

public :
        int nod ;
        int price ;
       
        bool operator < (const heap & other_node ) const { // operator overloading to obtain a min_heap
        
        return this->price > other_node.price; // to create a min_heap in function of price

        }

};

struct edge
{
 int node , cost;
};


int main()
{ 
  int Nrnodes , Nredges ;
  
  fin >> Nrnodes >> Nredges;
  
  std::vector < edge > v[max_size] ; 
  priority_queue < heap > pq ;
  std::vector <int> dist(max_size,0x7fffffff);  // distances from source to other nodes 
  
  for(int i = 0 ; i < Nredges ; ++i){
      int x , y , cost;
      fin >> x >> y >> cost ; // read edge and cost of the edge
      v[x].push_back(edge{y,cost});  // add to the adjacency list
  }
 
  pq.push(heap{1,dist[1] = 0});  // push source and cost of source to source which is zero
 
  while(pq.empty()==0) {  // while pq has elements
        
        int costmin = pq.top().price; 
        int nodul = pq.top().nod;  // node with lowest cost
        pq.pop();  // erase node with lowest cost
        if(costmin == dist[nodul]) { // to check if node is not already visited
 
           for(int i = 0 ; i < (int)v[nodul].size() ; i++)
               if(costmin + v[nodul][i].cost < dist[v[nodul][i].node]) {  // if we get a lowest cost we update node dist 
                  dist[v[nodul][i].node] = costmin + v[nodul][i].cost ;
                  pq.push(heap{v[nodul][i].node,dist[v[nodul][i].node]});  // we add to heap, to update dist of other nodes
               }
       }
  }
   for(int i = 2 ; i <= Nrnodes ; i++) 
     dist[i] == 0x7fffffff ? fout << 0 << " " : fout << dist[i] << " " ;
    return 0;
}
