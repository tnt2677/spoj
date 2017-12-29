#include <bits/stdc++.h>
#define MAX 5005

using namespace std;
int arr[MAX],temp[MAX];

int merge_count(int lo,int mid,int hi){
    int ans=0,i=lo,j=mid+1,k=lo;
    while(i<=mid&&j<=hi)
        if(arr[i]<=arr[j])temp[k++]=arr[i++];
        else{
            ans+=mid-i+1;
            temp[k++]=arr[j++];
        }
    while(i<=mid)temp[k++]=arr[i++];
    while(j<=hi)temp[k++]=arr[j++];
    for(int i=lo;i<=hi;++i)arr[i]=temp[i];
    return ans;
}
int sort_count(int lo,int hi){
    if(hi<=lo)return 0;
    int mid=lo+(hi-lo)/2;
    return sort_count(lo,mid)+ sort_count(mid+1,hi)+merge_count(lo,mid,hi);
}
int main(){
    ios::sync_with_stdio(false);
    cout.tie(NULL);cin.tie(NULL);
    int n;cin>>n;
    for(int i=0;i<n;++i)cin>>arr[i];
    int ans=sort_count(0,n-1);
    cout<<ans<<endl;
    return 0;
}
