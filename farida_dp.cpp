#include <bits/stdc++.h>
typedef int long long ll;

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    int t;
    cin>>t;
    int cnt=0;
    while(t--){
        cnt++;
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;++i)
            cin>>arr[i];
        ll ans[n+1];
        ans[0]=0;
        ans[1]=arr[0];
        for(int i=2;i<=n;++i)
            ans[i]=max(ans[i-1],ans[i-2]+(ll)arr[i-1]);
        cout<<"Case "<<cnt<<": "<<ans[n]<<endl;
    }
    return 0;
}
