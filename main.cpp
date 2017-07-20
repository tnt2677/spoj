#include <bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define ii pair<int,int>

using namespace std;

class union_find{
private:
    vi p,Rank;
public:
    union_find(int n){
        Rank.assign(n,0);
        p.assign(n,0);
        for(int i=0;i<n;++i){
            p[i]=i;
        }
    }
    int find_set(int i){
        return p[i]==i? i: p[i]=find_set(p[i]);
        }
    bool if_same(int i,int j){
        return find_set(i)==find_set(j);
    }
    void union_set(int i,int j){
        if(!if_same(i,j)){
            int x=find_set(i), y=find_set(j);
            if(Rank[x]<Rank[y]){
                p[x]=y;
                Rank[y]+=Rank[x];
            }else{
                p[y]=x;
                Rank[x]+=Rank[y];
            }
        }
    }
};

int main() {
    ios::sync_with_stdio(false);
    int t;cin>>t;
    while(t--){
        int p; cin>>p;
        int n,m;cin>>n>>m;
        vector< pair<int,ii> > edge_list;
        for(int i=0;i<m;++i){
            int x,y,z;
            cin>>x>>y>>z;
            edge_list.push_back({z,{x,y}});
        }
        sort(edge_list.begin(),edge_list.end());
        int min_cost=0;
        union_find uf(n+1);
        for(int i=0;i<m;++i){
            pair<int,ii> current_edge=edge_list[i];
            if(!uf.if_same(current_edge.second.first,current_edge.second.second)){
                min_cost+=current_edge.first;
                uf.union_set(current_edge.second.first,current_edge.second.second);
            }
        }
        cout<<(ll)min_cost*p<<endl;
    }
    return 0;
}
