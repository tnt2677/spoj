#include <bits/stdc++.h>
#define MAX 10005ll
typedef  long long ll;
using namespace std;

ll calculate(int arr1[],int arr2[],int n1,int n2){
    ll ans=0,sum1=0,sum2=0;
    int i=0,j=0;
    while(i<n1&&j<n2){
        if(arr1[i]==arr2[j]){
            if(sum1>sum2)
                ans+=sum1;
            else
                ans+=sum2;
            ans+=arr1[i];
            sum1=sum2=0;
            i++;j++;
        }else if(arr1[i]>arr2[j]){
            sum2+=arr2[j++];
        }else if(arr1[i]<arr2[j]){
            sum1+=arr1[i++];
        }
    }
    while(i<n1)
        sum1+=arr1[i++];
    while(j<n2)
        sum2+=arr2[j++];
    if(sum1>sum2)
        ans+=sum1;
    else
        ans+=sum2;
    return ans;
}
int main(){
    ios::sync_with_stdio(false);
    int n1,n2;
    cin>>n1;
    while(n1){
        int arr1[n1];
        for(int i=0;i<n1;++i)
            cin>>arr1[i];
        cin>>n2;
        int arr2[n2];
        for(int i=0;i<n2;++i)
            cin>>arr2[i];
        cout<<(ll)calculate(arr1,arr2,n1,n2)<<endl;
        cin>>n1;
    }
    return 0;
}
