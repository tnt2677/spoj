#include <bits/stdc++.h>
#define MAX (ll)100005
typedef long long ll;

using namespace std;
struct node{
    ll max1;
    ll max2;
};
//seg_tree: contains the segment tree
node seg_tree[MAX*4],null;
//arr: contains the elements
//n: no. of inputs
ll arr[MAX],n=0;
//construct_tree: constructs the tree
void construct_tree(ll node_num,ll lo,ll hi){
    if(hi==lo){
        seg_tree[node_num].max1=arr[lo];
        seg_tree[node_num].max2=INT_MIN;
        return;
    }
    ll mid=(hi+lo)/2;
    construct_tree(node_num*2,lo,mid);
    construct_tree(node_num*2+1,mid+1,hi);
    node left=seg_tree[node_num*2];
    node right=seg_tree[node_num*2+1];
    ll temp[4]; temp[0]=left.max1;temp[1]=left.max2;
    temp[2]=right.max1;temp[3]=right.max2;
    sort(temp,temp+4);
    seg_tree[node_num].max1=temp[3];
    seg_tree[node_num].max2=temp[2];
}
//Query: returns the node containing max1 & max2 of the required range
node query(ll node_num,ll tlo,ll thi,ll lo,ll hi){
    if(lo>hi||tlo>hi||lo>thi){
        return null;
    }
    if(lo<=tlo&&hi>=thi){
        return seg_tree[node_num];
    }
    ll tmid = (thi+tlo)/2;
    node left=query(node_num*2,tlo,tmid,lo,hi);
    node right=query(node_num*2+1,tmid+1,thi,lo,hi);
    ll temp[4]; temp[0]=left.max1;temp[1]=left.max2;
    temp[2]=right.max1;temp[3]=right.max2;
    sort(temp,temp+4);
    node x;x.max1=temp[3];x.max2=temp[2];
    return x;
}
//update_tree: point update for the tree 
void update_tree(ll node_num,ll lo,ll hi,ll x,ll value){
    if(hi==lo){
        seg_tree[node_num].max1=value;
        seg_tree[node_num].max2=INT_MIN;
        return;
    }
    ll mid=(hi+lo)/2;
    if(mid<x)
        update_tree(node_num*2+1,mid+1,hi,x,value);
    else
        update_tree(node_num*2,lo,mid,x,value);
    node left=seg_tree[node_num*2];
    node right=seg_tree[node_num*2+1];
    ll temp[4]; temp[0]=left.max1;temp[1]=left.max2;
    temp[2]=right.max1;temp[3]=right.max2;
    sort(temp,temp+4);
    seg_tree[node_num].max1=temp[3];
    seg_tree[node_num].max2=temp[2];
}

int main(){
    ios::sync_with_stdio(false);
    null.max1=INT_MIN;
    null.max2=INT_MIN;
    cin>>n;
    memset(arr,0,sizeof(arr));
    for(int i=1;i<=n;++i){
        cin>>arr[i];
    }
    construct_tree(1,1,n);
    int x;
    cin>>x;
    while(x--){
        char c; cin>>c;
        if(c=='Q'){
            int i,j;cin>>i>>j;
            if(i<=j){
                node ans=query(1,1,n,i,j);
                cout<<ans.max1+ans.max2<<endl;
            }else
            cout<<0<<endl;
        }else{
            int i,value;cin>>i>>value;
            update_tree(1,1,n,i,value);
        }
    }
    return 0;
}
