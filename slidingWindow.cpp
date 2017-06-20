#include <bits/stdc++.h>
typedef  long long ll;
using namespace std;

int main(){
    ios::sync_with_stdio(false);
        int n,value;
        cin>>n>>value;
        int arr[n];
        for(int i=0;i<n;++i){
            cin>>arr[i];
        }
        int i=0,j=-1;
        int ans=INT_MIN,sum=0;
        while(j+1<n&&i<n){
            if(sum+arr[j+1]>value){
                if(sum!=0){
                    sum-=arr[i++];
                }else{
                    i++;j++;
                }
            }else{
                sum+=arr[++j];
                ans=max(ans,sum);
            }
        }
        cout<<ans<<endl;
    return 0;
}
