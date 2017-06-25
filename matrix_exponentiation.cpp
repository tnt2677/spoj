#include <bits/stdc++.h>
#define MAX 10005ll
#define MOD 1000000007
typedef  long long ll;
using namespace std;

ll fib(ll n){
    if(n==0||n==1)return n;
    ll x=n-1;
    ll ans[2][2]={{1,0},{0,1}};
    ll temp[2][2];
    ll arr[2][2]={{1,1},{1,0}};
    while(x>0){
        if(x%2){
            memset(temp,0,sizeof(temp));
            for(int i=0;i<2;++i)
                for(int j=0;j<2;++j)
                    for(int k=0;k<2;++k){
                        temp[i][j]+=((ans[i][k]%MOD)*(arr[k][j]%MOD))%MOD;
                        temp[i][j]=temp[i][j]%MOD;
                    }
            for(int i=0;i<2;++i)
                for(int j=0;j<2;++j)
                    ans[i][j]=temp[i][j];
        }
        x/=2;
        memset(temp,0,sizeof(temp));
        for(int i=0;i<2;++i)
            for(int j=0;j<2;++j)
                for(int k=0;k<2;++k){
                        temp[i][j]+=((arr[i][k]%MOD)*(arr[k][j]%MOD))%MOD;
                        temp[i][j]=temp[i][j]%MOD;
                    }
        for(int i=0;i<2;++i)
            for(int j=0;j<2;++j)
                arr[i][j]=temp[i][j];
    }
    return (ans[0][0]%MOD);
}
int main(){
    ios::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        ll m,n;
        cin>>m>>n;
        cout<<(fib(n+2)%MOD-fib(m+1)%MOD+MOD)%MOD<<"\n";
    }
    return 0;
}
