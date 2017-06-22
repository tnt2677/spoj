#include <bits/stdc++.h>
#define MAX 50008ll
typedef  long long ll;
using namespace std;

struct Node{
    ll sum,max_sum,max_prefix,max_suffix;
};
Node seg_tree[4*MAX], null;
int arr[MAX];
void build_tree(int node,int tl,int tr){
    if(tl==tr){
        seg_tree[node].max_prefix=arr[tl];
        seg_tree[node].max_suffix=arr[tl];
        seg_tree[node].max_sum=arr[tl];
        seg_tree[node].sum=arr[tl];
        return;
    }else{
        int tm=(tl+tr)/2;
        build_tree(node*2,tl,tm);
        build_tree(node*2+1,tm+1,tr);
        Node left=seg_tree[node*2];
        Node right=seg_tree[node*2+1];
        seg_tree[node].max_prefix = max(left.max_prefix,left.sum + right.max_prefix);
        seg_tree[node].max_suffix = max(right.max_suffix, right.sum + left.max_suffix);
        seg_tree[node].sum = left.sum + right.sum;
        seg_tree[node].max_sum = max(right.max_prefix + left.max_suffix , max(left.max_sum , right.max_sum));
    }
}
Node query_tree(int node,int tl,int tr,int l,int r){
    if(tr<l||r<tl)
        return null;
    else if(tl>=l&&tr<=r)
        return seg_tree[node];
    else{
        int tm=(tr+tl)/2;int lt=node<<1;int rt=lt+1;
        Node left=query_tree(lt,tl,tm,l,r);
        Node right=query_tree(rt,tm+1,tr,l,r);
        Node temp;
        temp.max_prefix = max(left.max_prefix ,left.sum + right.max_prefix);
        temp.max_suffix = max(right.max_suffix,right.sum + left.max_suffix);
        temp.sum = left.sum + right.sum;
        temp.max_sum = max(right.max_prefix + left.max_suffix ,max(left.max_sum ,right.max_sum));
        return temp;
    }
}
void update_tree(int node,int tl,int tr,int index,int value){
    if(tl==tr&&tr==index){
        seg_tree[node].max_prefix = seg_tree[node].max_suffix = seg_tree[node].max_sum = seg_tree[node].sum=value;
    }else{
        int tm=(tl+tr)/2;
        if(index<=tm)update_tree(node*2,tl,tm,index,value);
        else update_tree(node*2+1,tm+1,tr,index,value);
        Node left=seg_tree[node*2];
        Node right=seg_tree[node*2+1];
        seg_tree[node].max_prefix = max(left.max_prefix,left.sum + right.max_prefix);
        seg_tree[node].max_suffix = max(right.max_suffix, right.sum + left.max_suffix);
        seg_tree[node].sum = left.sum + right.sum;
        seg_tree[node].max_sum = max(right.max_prefix + left.max_suffix , max(left.max_sum , right.max_sum));
    }
}
int main(){
    ios::sync_with_stdio(false);
    memset(arr,0,sizeof(arr));
    memset(seg_tree,0,sizeof(seg_tree));
    null.max_prefix=null.max_suffix=null.max_sum=-10999;
    null.sum=0;
    int n,m;
    cin>>n;
    for(int i=1;i<=n;++i)
        cin>>arr[i];
    build_tree(1,1,n);
    cin>>m;
    while(m--){
        bool type; cin>>type;
        if(!type){
            int index,value; cin>>index>>value;
            update_tree(1,1,n,index,value);
        }else{
            int x,y; cin>>x>>y;
            cout<< (ll)query_tree(1,1,n,x,y).max_sum <<endl;
        }
    }
    return 0;
}
