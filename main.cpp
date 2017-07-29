#include <bits/stdc++.h>
#define MAX (ll)100005
#define SIZE 55
#define vi vector<int>
#define inf (ll)11111111
#define ii pair<int ,int>
#define mp make_pair
#define vii vector<ii>
typedef long long ll;

using namespace std;
int djikstra_path(vector<vii> &adj_list,int s,int v,int dest){
    vi dist(v+1,INT_MAX);
    dist[s]=0;
    priority_queue<ii,vector<ii>,greater<ii> > pq;
    pq.push(ii(0,s));
    while(!pq.empty()){
        ii front = pq.top(); pq.pop();
        int d=front.first,u=front.second;
        if(d>dist[u])continue;
        for(int j=0;j<(int)adj_list[u].size();j++){
            ii v = adj_list[u][j];
            if(dist[u]+v.second< dist[v.first]){
                dist[v.first] = dist[u]+v.second;
                pq.push(ii(dist[v.first],v.first));
            }
        }
    }
    return dist[dest];
}
int main(){
    ios::sync_with_stdio(false);
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        map<string,int> mp;
        vector<vii> adj_list(n+1);
        for(int i=1;i<=n;++i){
            string str; cin>>str;
            mp[str]=i;
            int p;cin>>p;
            while(p--){
                int index; cin>>index;
                int wt; cin>>wt;
                adj_list[i].push_back(ii(index,wt));
            }
        }
        int x; cin>>x;
        while(x--){
            string s1,s2;
            cin>>s1>>s2;
            cout<<djikstra_path(adj_list,mp[s1],n,mp[s2])<<"\n";
        }
    }
    return 0;
}
