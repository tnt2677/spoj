#include <bits/stdc++.h>
#define MAX (ll)30005
#define ii pair<int,int>
#define vii vector<ii>
#define SIZE 105
#define vi vector<int>
typedef long long ll;
using namespace std;

int graph[SIZE][SIZE];
ll shortest_path(int s,int n,int t){
    vi dist(n,1111111LL);dist[s]=0;
    priority_queue<ii,vector<ii>,greater<ii> > pq; pq.push(ii(0,s));
    while(!pq.empty()){
        ii front = pq.top();pq.pop();
        int d = front.first; int u = front.second;
        if(d>dist[u])continue;
        for(int i=0;i<n;i++){
                if(graph[u][i]==-1)graph[u][i]=111111LL;
            if(dist[u]+graph[u][i]<dist[i]){
                dist[i]=dist[u]+graph[u][i];
                pq.push(ii(dist[i],i));
            }
        }
    }
    ll ans=0;
    for(auto x:dist){
        if(t>=x)ans++;
    }
    return ans;
}
int main(){
    ios::sync_with_stdio(false);
    memset(graph,-1,sizeof graph);
    int n;cin>>n;
    int s;cin>>s;
    int t;cin>>t;
    int m;cin>>m;
    for(int i=0;i<m;++i){
        int x,y,data;cin>>x>>y>>data;
        graph[y-1][x-1]=data;graph[x-1][x-1]=graph[y-1][y-1]=0;
    }
    cout<<shortest_path(s-1,n,t)<<endl;
    return 0;
}
