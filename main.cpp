#include <bits/stdc++.h>
typedef int long long ll;
using namespace std;

int n;
int arr[2000];
int ans[2000][2000];
int calculate(int i,int j){
    if(ans[i][j]!=-1)
        return ans[i][j];
    int time=n-(j-i);
    if(i==j){
        ans[i][j]=arr[i]*time;
        return ans[i][j];
    }
    ans[i][j]=max(calculate(i+1,j)+arr[i]*time,calculate(i,j-1)+arr[j]*time);
    return ans[i][j];
}
int main(){
    ios::sync_with_stdio(false);
    cin>>n;
    memset(ans,-1,sizeof(ans));
    for(int i=0;i<n;++i){
        cin>>arr[i];
    }
    cout<<calculate(0,n-1)<<endl;
    return 0;
}
