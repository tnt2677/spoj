#include <bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define ii pair<int,int>

using namespace std;
//minimum spanning tree using kruskal's greedy algorithm
//union_find ds
class union_find{
private: vi p,Rank;
public:
    union_find(int n){ Rank.assign(n,0);
        p.assign(n,0);
        for(int i=0;i<n;++i) p[i]=i; }
    int find_set(int i){ return p[i]==i? i: p[i]=find_set(p[i]); }
    bool if_same(int i,int j){
        return find_set(i)==find_set(j); }
    void union_set(int i,int j){
        if(!if_same(i,j)){
            int x=find_set(i), y=find_set(j);
            if(Rank[x]<Rank[y]){
                p[x]=y;
            else
                p[y]=x;
            if(Rank[x]==Rank[y])Rank[y]++;
         }
    }
};

int main() {
    ios::sync_with_stdio(false);
    //t: test cases
    int t;cin>>t;
    while(t--){
        //p: cost of 1 unit
        int p; cin>>p;
        //n: no. of nodes,m: no. of edges
        int n,m;cin>>n>>m;
        //storing graph as an edge list
        //ie. < weight, pair<u,v> >
        vector< pair<int,ii> > edge_list;
        //taking graph as input
        for(int i=0;i<m;++i){
            //x: u, y: v, z: weight
            int x,y,z;
            cin>>x>>y>>z;
            edge_list.push_back({z,{x,y}});
        }
        //sorting the edge list
        //O(E*Log2E)
        sort(edge_list.begin(),edge_list.end());
        //min_cost: cost of minimum spanning tree formed
        int min_cost=0;
        //as 1 based indexing is used union_find of 0,1,...,N is formed
        union_find uf(n+1);
        //pick the minimum cost edge if it doesen't form a cycle add it to the tree
        for(int i=0;i<m;++i){
            //pick the next minimum edge
            pair<int,ii> current_edge=edge_list[i];
            //if not forming loop ie. not in the same set
            if(!uf.if_same(current_edge.second.first,current_edge.second.second)){
                //add the cost to mst
                min_cost+=current_edge.first;
                //join the two sets
                uf.union_set(current_edge.second.first,current_edge.second.second);
            }
        }
        //the net price is product of cost & mst
        cout<<(ll)min_cost*p<<endl;
    }
    return 0;
}
