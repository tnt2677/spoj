#include <bits/stdc++.h>
typedef int long long ll;

using namespace std;

int calculate(string &str){
    int n=str.size();
    int arr[n+1][n+1];
    memset(arr,0,sizeof(arr));
    for(int s=1;s<n;s++){
        for(int i=1;i<=(n-s);++i){
            int j=i+s;
            if(i+1==j&&str[i-1]==str[j-1]){
                arr[i][j]=0;
                continue;
            }
            if(str[i-1]==str[j-1]){
                arr[i][j]=arr[i+1][j-1];
            }else{
                arr[i][j]=min(arr[i+1][j],arr[i][j-1])+1;
            }
        }
    }
    return arr[1][n];
}
int main(){
    ios::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        cout<<calculate(str)<<endl;
    }
    return 0;
}
