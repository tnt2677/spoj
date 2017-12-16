#include <bits/stdc++.h>
#define MAX 10009
#define SIZE 100009
#define inf 1000005LL
#define ii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>
typedef long long ll;
using namespace std;
bool dp[MAX][1025];
int arr[MAX];
int fun(int n,int k){
    memset(dp,0,sizeof dp);
    dp[0][0]=true;cout<<dp[0][1024]<<endl;
    for(int i=1;i<=n;++i){
        for(int j=0;j<1025;++j){
            dp[i][j]=dp[i-1][j]|dp[i-1][j^arr[i]];
            if(dp[i][j])cout<<j<<" "<<arr[i]<<" "<< int(j^arr[i]) <<endl;
            }
    }
    int ans=0;
    for(int i=0;i<=1024;++i)
        if(dp[n][i])cout<<i<<" ";//ans=max(ans,k^i);
    return ans;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;cin>>t;
    while(t--){
        int n,k;cin>>n>>k;
        memset(arr,0,sizeof arr);
        for(int i=1;i<=n;++i){
            cin>>arr[i];
        }
        cout<<fun(n,k)<<endl;
    }
    return 0;
}
