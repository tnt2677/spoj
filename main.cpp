#include <bits/stdc++.h>
typedef  long long ll;
using namespace std;

ll lazy[4 * 1000000],seg_tree[4 * 1000000];

ll Query(ll node,ll tl,ll tr,ll l,ll r){
    if(lazy[node]>0){
        seg_tree[node]+=(tr-tl+1)*lazy[node];
        if(tl!=tr){
            lazy[node*2]+=lazy[node];
            lazy[node*2+1]+=lazy[node];
        }
        lazy[node]=0;
    }
    if(tr<l||tl>r||tr<tl)
        return 0;
    if(tl>=l&&tr<=r){
        return seg_tree[node];
    }else{
        ll tm=(tl+tr)/2;
        return Query(node*2,tl,tm,l,r) + Query(node*2+1,tm+1,tr,l,r);
    }
}
void Update(ll node,ll tl,ll tr,ll l,ll r,ll value){
    if(lazy[node]>0){
        seg_tree[node]+=(tr-tl+1)*lazy[node];
        if(tl!=tr){
            lazy[node*2]+=lazy[node];
            lazy[node*2+1]+=lazy[node];
        }
        lazy[node]=0;
    }
    if(tr<l||tl>r||tr<tl)
        return;
    if(tl>=l&&tr<=r){
        seg_tree[node]+=(tr-tl+1)*value;
        if(tl!=tr){
            lazy[node*2]+=value;
            lazy[node*2+1]+=value;
        }
        return;
    }else{
        ll tm = (tl+tr)/2;
        Update(node*2,tl,tm,l,r,value);
        Update(node*2+1,tm+1,tr,l,r,value);
        seg_tree[node]=seg_tree[node*2]+seg_tree[node*2+1];
    }
}
int main(){
    ios::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        int n,c;
        memset(seg_tree,0,sizeof(seg_tree));
        memset(lazy,0,sizeof(lazy));
        cin>>n>>c;
        while(c--){
            bool type;
            cin>>type;
            if(type){
                int x,y;
                cin>>x>>y;
                cout<<(ll)Query(1,1,n,x,y)<<endl;
            }else{
                int x,y,value;
                cin>>x>>y>>value;
                Update(1,1,n,x,y,value);
            }
        }
    }
    return 0;
}
