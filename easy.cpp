#include <bits/stdc++.h>
typedef  long long ll;
using namespace std;
//can be done in O(n)......try it

int main(){
    ios::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        int n,m,d;
        cin>>n>>m>>d;
        priority_queue<int> pq;
        for(int i=0;i<n;++i){
            int x;
            cin>>x;
            pq.push(x);
        }
        for(int i=0;i<m;++i){
            int max_value=pq.top();pq.pop();
            max_value-=d;
            if(max_value>0)
                pq.push(max_value);
        }
        if(pq.size()==n)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
    return 0;
}
