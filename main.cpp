#include <bits/stdc++.h>
typedef  long long ll;
using namespace std;

bool check_bfs(vector< set<int>> &graph,bool visited[],int start){
    bool red[graph.size()]={0};
    queue<int> q;bool ans=false;
    q.push(start);
    red[start]=true;
    visited[start]=true;
    while(!q.empty()){
        int top=q.front();q.pop();
        for(auto i:graph[top]){
            if(!visited[i]){
                q.push(i);
                visited[i]=true;
                red[i]=!red[top];
            }
            if(visited[i]&&red[i]==red[top])
                ans=true;
        }
    }
    return !ans;
}
bool calculate(vector< set<int > > graph){
    bool visited[graph.size()]={0};
    bool ans=true;
    for(int i=1;i<graph.size();++i){
        if(visited[i]==false){
            //cout<<"calling with values "<<i<<" "<< check_bfs(graph,visited,i)<<endl;
            ans=ans&check_bfs(graph,visited,i);
        }
    }
    return ans;
}
int main(){
    ios::sync_with_stdio(false);
    int t,cnt=0;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<set<int> > graph(n+1);
        for(int i=0;i<m;++i){
            int x,y;
            cin>>x>>y;
            graph[x].insert(y);
            graph[y].insert(x);
        }
        cout<<"Scenario #"<<++cnt<<":"<<endl;
        if(!calculate(graph))
            cout<<"Suspicious bugs found!"<<endl;
        else
            cout<<"No suspicious bugs found!"<<endl;
    }
    return 0;
}
