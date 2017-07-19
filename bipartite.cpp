#include <bits/stdc++.h>
typedef  long long ll;
using namespace std;

//geeks algo
//bipartite matching
bool check_bfs(vector< set<int>> &graph,bool visited[],int start){
    //stores the color if red then true else false
    bool red[graph.size()]={0};
    //ans: true if bipartie else false
    queue<int> q;bool ans=true;
    //push the start node into the queue
    q.push(start);
    //initiate the strting node with red color
    //mark as visited
    red[start]=true;visited[start]=true;
    //bfs
    while(!q.empty()){
        //top: contains the top node 
        int top=q.front();q.pop();
        //for all the adajcent nodes of top
        for(auto i:graph[top]){
            //if the current node is not visited
            if(!visited[i]){
                //enqueue the current node
                q.push(i);
                //mark as visited
                visited[i]=true;
                //color it alternately
                red[i]=!red[top];
            }
            //if same color set ans as false
            if(visited[i]&&red[i]==red[top])
                ans=false;
        }
    }
    //return whether bipartite or not
    return ans;
}
bool calculate(vector< set<int > > graph){
    bool visited[graph.size()]={0};
    bool ans=true;
    //if graph is in parts,then call for all nodes
    //check bipartite graph
    for(int i=1;i<graph.size();++i){
        if(visited[i]==false){
            ans=ans&check_bfs(graph,visited,i);
        }
    }
    return ans;
}
int main(){
    ios::sync_with_stdio(false);
    //test cases in t
    int t,cnt=0;
    cin>>t;
    while(t--){
        int n,m; cin>>n>>m;
        //a vector of sets as graph[0....n]
        vector<set<int> > graph(n+1);
        for(int i=0;i<m;++i){
            int x,y; cin>>x>>y;
            //inserting in graph
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
