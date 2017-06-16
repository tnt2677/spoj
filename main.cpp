#include <iostream>
#include<stdio.h>
typedef int long long ll;

using namespace std;

struct node{
    ll prefix,suffix,sum,max_sum;
};
void build(int lo ,int hi, int node_num,int arr[],node seg_tree[]){
    if(lo==hi){
      seg_tree[node_num].sum = arr[lo];
      seg_tree[node_num].prefix = arr[lo];
      seg_tree[node_num].suffix = arr[lo];
      seg_tree[node_num].max_sum = arr[lo];
      return;
    }
    int mid = (lo+hi)/2;
    build(lo,mid,node_num*2,arr,seg_tree);
    build(mid+1,hi,node_num*2+1,arr,seg_tree);
    node left=seg_tree[node_num*2];
    node right=seg_tree[node_num*2+1];
    seg_tree[node_num].sum = left.sum + right.sum;
    seg_tree[node_num].prefix = max( left.prefix , left.sum + right.prefix);
    seg_tree[node_num].suffix = max( right.suffix , right.sum + left.suffix);
    seg_tree[node_num].max_sum = max( max( left.max_sum , right.max_sum ) , left.suffix + right.prefix );
}
node null;
node query(int l,int r,int s,int e,int node_num,node seg_tree[]){
    if(s>r || e<l){
        return null;
    }else if(s>=l && e<=r){
        return seg_tree[node_num];
    }else{
        int m = (s+e)/2;
        node lft = query(l ,r ,s ,m ,node_num*2 ,seg_tree);
        node rgt = query(l ,r ,m+1 ,e ,node_num*2+1 ,seg_tree);
        node ans;
        ans.max_sum = max( max( lft.max_sum , rgt.max_sum), lft.suffix + rgt.prefix);
        ans.suffix = max( rgt.suffix , rgt.sum + lft.suffix);
        ans.prefix = max( lft.prefix,lft.sum + rgt.prefix);
        ans.sum = lft.sum + rgt.sum;
        return ans;
    }
}
int main(){
    int n;
    scanf("%d",&n);
    null.prefix=null.suffix=null.max_sum=-15008;
    null.sum=0;
    node seg_tree[4*n];
    int arr[n+1];
    arr[0]=0;
    for(int i=1;i<=n;++i){
        scanf("%d",&arr[i]);
    }
    build(1,n,1,arr,seg_tree);
    int q;scanf("%d",&q);
    while(q--){
        int i,j;
        scanf("%d%d",&i,&j);
        ll ans=(ll)query(i,j,1,n,1,seg_tree).max_sum;
        printf("%lli\n",ans);
    }
    return 0;
}
