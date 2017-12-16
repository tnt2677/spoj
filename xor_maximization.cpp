#include <bits/stdc++.h>
#define MAX 10009
using namespace std;
//dp[n][number]
//i.e. if upto element "n" are we able to make "number"
bool dp[MAX][1024];
int arr[MAX];
int fun(int n,int k){
    memset(dp,0,sizeof dp);
    dp[0][0]=true;
    for(int i=1;i<=n;++i){
        for(int j=0;j<1025;++j)
            //Most imp part
            // dp[i,j] can only be present if either dp[i-1,j] is true or
            // we can make j using arr[i] 
            dp[i][j]=dp[i-1][j]|dp[i-1][j^arr[i]];
    }
    int ans=0;
    for(int i=0;i<=1024;++i)
        if(dp[n][i])ans=max(ans,k^i);
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
