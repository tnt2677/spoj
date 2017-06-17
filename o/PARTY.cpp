#include <bits/stdc++.h>
typedef int long long ll;

using namespace std;
int main(){
    ios::sync_with_stdio(false);
    int budget,n;
    cin>>budget>>n;
    while(budget&&n){
        int fee[n],profit[n];
        for(int i=0;i<n;++i){
            cin>>fee[i]>>profit[i];
        }
        int arr[n+1][budget+1];
        memset(arr,0,sizeof(arr));
        for(int i=1;i<n+1;++i){
            for(int j=1;j<budget+1;++j){
                if(j<fee[i-1]){
                    arr[i][j]=arr[i-1][j];
                }else{
                    arr[i][j]=max(arr[i-1][j],arr[i-1][j-fee[i-1]]+profit[i-1]);
                }
            }
        }
        int j=budget;
        while(arr[n][j]==arr[n][budget])j--;
        cout<<j+1<<" "<<arr[n][budget]<<endl;
        cin>>budget>>n;
    }
    return 0;
}
