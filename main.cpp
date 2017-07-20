#include <bits/stdc++.h>
#define vi vector<int>
#define ii pair<int>
#define SIZE 1005

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
    union_find uf(10);
    uf.union_set(0,1);
    uf.union_set(1,2);
    uf.union_set(2,3);
    uf.union_set(3,4);
    uf.union_set(4,5);
    while(true){
        int x,y; cin>>x>>y;
        uf.if_same(x,y)?cout<<"yes\n":cout<<"no\n";
    }
    return 0;
}
