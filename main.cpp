#include <bits/stdc++.h>
typedef  long long ll;
using namespace std;

int sum_value(int i,int j,int sum[]){
    if(!i)return sum[j]%100;
    return (sum[j]-sum[i-1])%100;
}
ll calculate(int arr[],int n){
    ll matrix[n][n];
    memset(matrix,0,sizeof(matrix));
    int sum[n];sum[0]=arr[0];
    for(int i=1;i<n;++i){
        sum[i]=sum[i-1]+arr[i];
    }
    for(int s=1;s<n;s++){
        for(int i=0;s+i<n;++i){
            int j=i+s;
            matrix[i][j]=INT_MAX;
            for(int k=i;k<j;k++)
                matrix[i][j]=min(matrix[i][j],(matrix[i][k]+matrix[k+1][j]+sum_value(i,k,sum)*sum_value(k+1,j,sum)));
        }
    }
    return matrix[0][n-1];
}
int main(){
        ios::sync_with_stdio(false);
        int n;
        while(cin>>n){
            int arr[n];
            for(int i=0;i<n;++i){
                cin>>arr[i];
            }
            cout<<(ll)calculate(arr,n)<<endl;
        }
    return 0;
}
