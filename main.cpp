#include <bits/stdc++.h>
#define MAX (ll)100005
#define SIZE 1005
#define vi vector<int>
#define inf (ll)11111111
#define ii pair<int ,int>
#define mp make_pair
#define vii vector<ii>
#define pb push_back
typedef long long ll;

using namespace std;
char graph[SIZE][SIZE];
int R=0,C=0;
int Best_x,Best_y;
int dr[]={0,1,0,-1};
int dc[]={1,0,-1,0};

int Search(int x,int y){
    int last=0,best=0;
    int best_x=x,best_y=y;
    if(graph[x][y]=='.'){
        graph[x][y]='x';
        for(int d=0;d<4;++d){
            last=Search(x+dr[d],y+dc[d]);
            if(last>best){best=last,best_x=Best_x,best_y=Best_y;}
        }
        Best_x=best_x,Best_y=best_y;
        return best+1;
    }
    return 0;
}
int main(){
    ios::sync_with_stdio(false);
    int t; cin>>t;
    while(t--){
        cin>>C>>R;
        for(int i=0;i<R;++i)cin>>graph[i];
        int x=1,y=1;
        while(graph[x][y]=='#'){
            if(x<C-1)x++;
            else{
                x=1;y++;
            }
        }
        Search(x,y);
        for(int i=0;i<R;i++)for(int j=0;j<C;++j)if(graph[i][j]=='x')graph[i][j]='.';else if(graph[i][j]=='.')cout<<"error";
        cout<<"Maximum rope length is "<<   Search(Best_x,Best_y)-1<<".\n";
    }
    return 0;
}
