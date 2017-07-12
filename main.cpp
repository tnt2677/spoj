#include <bits/stdc++.h>
#define MAX (ll)1000005
#define SIZE 30005
#define COUNT 1000005
typedef long long ll;

using namespace std;
bool arr[MAX];

int main(){
    ios::sync_with_stdio(false);
    arr[0]=0;
    arr[1]=1;
    int k,l,n;
    cin>>k>>l>>n;
    for(int i=2;i<MAX;++i){
        if(!arr[i-1])
            arr[i]=true;
        else if(i>=k&&!arr[i-k])
            arr[i]=true;
        else if(i>=l&&!arr[i-l])
            arr[i]=true;
        else arr[i]=false;
    }
    for(int i=0;i<n;++i){
        int x;cin>>x;
        arr[x]?cout<<"A":cout<<"B";
    }
    return 0;
}
