#include <bits/stdc++.h>
#define MAX 5005
#define MOD 1000000007
#define inf 1000005LL
#define ii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>
#define endl "\n"
typedef long long ll;
using namespace std;
int arr[MAX];
int temp[MAX],Arr[MAX];

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
    for(int i=0;i<n;++i){cin>>arr[i];Arr[i]=arr[i];}
    int ans=sort_count(0,n-1);
    int t;cin>>t;
    while(t--){
        int i,j;cin>>i>>j;
        int num=(j-i+1)*(j-i)/2;
        //reverse(Arr+i-1,Arr+j);
        //for(int k=i-1;k<=j-1;++k)arr[k]=Arr[k];int x=num-sort_count(i-1,j-1);
        ans=(ans%2+num%2)%2;
        if(ans%2==0)cout<<"even"<<endl;
        else cout<<"odd"<<endl;
    }
    return 0;
}
//use ctrl+j for , forb
// alt + home ,alt+ end
