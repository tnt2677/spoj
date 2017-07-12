#include <bits/stdc++.h>
#define MAX (ll)1000005

using namespace std;
//arr contains the precomputed wins or loses of A/B
bool arr[MAX];

int main(){
    ios::sync_with_stdio(false);
    //for 0'th position always loss,
    //for 1'st position one can always win
    arr[0]=0; arr[1]=1;
    
    //k & l contains other possible moves:1 coin/ k coins/ l coins
    int k,l,n; cin>>k>>l>>n;
    
    //precomputing ans
    for(int i=2;i<MAX;++i){
        //win of current positon posible only if
        //we can move to a losing position in any possible moves
        if(!arr[i-1])
            arr[i]=true;
        else if(i>=k&&!arr[i-k])
            arr[i]=true;
        else if(i>=l&&!arr[i-l])
            arr[i]=true;
        //if we can't move to a losing position current position is also losing
        else arr[i]=false;
    }
    
    //printing the ans
    for(int i=0;i<n;++i){
        int x; cin>>x;
        arr[x]?cout<<"A":cout<<"B";
    }
    return 0;
}
