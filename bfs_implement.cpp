#include <bits/stdc++.h>
#define MAX 10005ll
typedef  long long ll;
using namespace std;

vector<pair<int,vector<int> >  > prime(MAX);
bool arr[MAX];
void sieve(){
    memset(arr,0,sizeof(arr));
    arr[0]=arr[1]=true;
    for(int i=2;i<MAX;++i){
        if(!arr[i]){
            for(int j=i*i;j<=MAX;j+=i){
                arr[j]=true;
            }
            if(i>=1000){
                vector<int> temp;
                prime[i]={i,temp};
            }
        }
    }
}
void calculate(){
    for(int i=1000;i<prime.size();++i){
        int p=prime[i].first;
        if(p){
            int d1=p%10,d2=(p%100)/10,d3=(p%1000)/100,d4=p/1000;
            for(int k=0;k<=9;++k){
                if(!arr[d4*1000+d3*100+d2*10+k]&&d4*1000+d3*100+d2*10+k!=p)(prime[i].second).push_back(d4*1000+d3*100+d2*10+k);
            }
            for(int k=0;k<=9;++k){
                if(!arr[d4*1000+d3*100+k*10+d1]&&d4*1000+d3*100+k*10+d1!=p)(prime[i].second).push_back(d4*1000+d3*100+k*10+d1);
            }
            for(int k=0;k<=9;++k){
                if(!arr[d4*1000+k*100+d2*10+d1]&&d4*1000+k*100+d2*10+d1!=p)(prime[i].second).push_back(d4*1000+k*100+d2*10+d1);
            }
            for(int k=1;k<=9;++k){
                if(!arr[k*1000+d3*100+d2*10+d1]&&k*1000+d3*100+d2*10+d1!=p)(prime[i].second).push_back(k*1000+d3*100+d2*10+d1);
            }
        }
    }
}
void bfs(int start,int value){
    int visited[MAX];bool ans=false;
    memset(visited,0,sizeof(visited));
    queue<int> q;
    q.push(start);
    visited[start]=0;
    while(!q.empty()){
        int top=q.front();q.pop();
        vector<int > &p=prime[top].second;
        for(auto i:p){
            if(!visited[i]){
                visited[i]=visited[top]+1;
                if(i==value){
                    cout<<visited[i]<<endl;ans=true;
                }
                q.push(i);
            }
        }
    }
    if(!ans)cout<<"Impossible."<<endl;
}
int main(){
  ios::sync_with_stdio(false);
    sieve();
    calculate();
    int t;
    cin>>t;
    while(t--){
        int x,y; cin>>x>>y;
        if(x!=y)
            bfs(x,y);
        else
            cout<<0<<endl;
    }
    return 0;
}
