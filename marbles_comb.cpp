#include <bits/stdc++.h>
typedef unsigned int long long ll;
using namespace std;
ll calculate(int n,int k){
    ll ans=1;
    k=k>n-k?n-k:k;
    int j=1;
    for(;j<=k;j++,n--){
        if(n%j==0){
            ans*=n/j;
        }else
        if(ans%j==0){
            ans=ans/j*n;
        }else{
            ans=(ans*n)/j;
        }
    }
    return ans;
}
int main(){
    ios::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
     int n,k;
     cin>>n>>k;
    cout<<calculate(n-1,n-k)<<endl;
    }
    return 0;
}
