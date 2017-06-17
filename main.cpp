#include <bits/stdc++.h>
typedef int long long ll;
using namespace std;
bool arr[182][182];
int ans[182][182];

void calculate(int i,int j,int row,int column){
    bool visited[row][column];
    memset(visited,0,sizeof(visited));
    queue<pair<int,int> > q;
    q.push(make_pair(i,j));
    visited[i][j]=true;
    while(!q.empty()){
        pair<int,int> top=q.front();q.pop();
        int x=top.first; int y=top.second;
        if(x!=0&&!arr[x-1][y]&&!visited[x-1][y]){
            if(ans[x-1][y]){
                ans[x-1][y]=min(ans[x-1][y],abs(x-1-i)+abs(y-j));
            }else{
                ans[x-1][y]=abs(x-1-i)+abs(y-j);
            }
            q.push(make_pair(x-1,y));visited[x-1][y]=true;
        }
        if(x!=row-1&&!arr[x+1][y]&&!visited[x+1][y]){
            if(ans[x+1][y]){
                ans[x+1][y]=min(ans[x+1][y],abs(x+1-i)+abs(y-j));
            }else{
                ans[x+1][y]=abs(x+1-i)+abs(y-j);
            }
            q.push(make_pair(x+1,y));visited[x+1][y]=true;
        }
        if(y!=0&&!arr[x][y-1]&&!visited[x][y-1]){
            if(ans[x][y-1]){
                ans[x][y-1]=min(ans[x][y-1],abs(x-i)+abs(y-1-j));
            }else{
                ans[x][y-1]=abs(x-i)+abs(y-1-j);
            }
            q.push(make_pair(x,y-1));visited[x][y-1]=true;
        }
        if(y!=column-1&&!arr[x][y+1]&&!visited[x][y+1]){
            if(ans[x][y+1]){
                ans[x][y+1]=min(ans[x][y+1],abs(x-i)+abs(y+1-j));
            }else{
                ans[x][y+1]=abs(x-i)+abs(y+1-j);
            }
            q.push(make_pair(x,y+1));visited[x][y+1]=true;
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        int row,column;
        cin>>row>>column;
        memset(arr,0,sizeof(arr));
        for(int i=0;i<row;i++){
            string str;
            cin>>str;
            for(int j=0;j<column;j++){
                arr[i][j]=str[j]-'0';
            }
            str.clear();
        }
        memset(ans,0,sizeof(ans));
        for(int i=0;i<row;i++){
            for(int j=0;j<column;++j){
                if(arr[i][j]){
                    calculate(i,j,row,column);
                    ans[i][j]=0;
                }
            }
        }
        for(int i=0;i<row;i++){
            for(int j=0;j<column;++j){
                cout<<ans[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
