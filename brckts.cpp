#include <bits/stdc++.h>
#define MAX (ll)30005
typedef long long ll;

//In this problem, we are given a string containing parenthesis (open and closed), which requires making updates to individual parenthesis (changing an open parenthesis to closed or vice versa), and checking if the whole string represents a correct parenthesization.
//Only 2 things are needed in each segment tree node:

//The number of unmatched open parenthesis in this range.
//The number of unmatched closed parenthesis in this range.
//When we merge the counts, we need to find the minimum of the open brackets on left subtree, and closed brackets on the right subtree.

//Then, we add the open and closed counts, and subtract the minimum count found above.

using namespace std;
//count_open:unbalanced open brackets
//count_closed:unbalanced closed brackets
struct node{
    ll count_open;
    ll count_close;
};
node seg_tree[MAX*4];
string str;
void construct_tree(ll node_num,ll lo,ll hi){
    if(hi==lo){
        seg_tree[node_num].count_open=str[lo-1]=='('?1:0;
        seg_tree[node_num].count_close=str[lo-1]==')'?1:0;
        return;
    }
    ll mid=(hi+lo)/2;
    construct_tree(node_num*2,lo,mid);
    construct_tree(node_num*2+1,mid+1,hi);
    int change=min(seg_tree[(node_num<<1)].count_open,seg_tree[(node_num<<1)+1].count_close);
    seg_tree[node_num].count_close=seg_tree[(node_num<<1)].count_close+seg_tree[(node_num<<1)+1].count_close-change;
    seg_tree[node_num].count_open=seg_tree[(node_num<<1)].count_open+seg_tree[(node_num<<1)+1].count_open-change;
}
inline bool query(void){
    return !seg_tree[1].count_close&&!seg_tree[1].count_open;
}
void update_tree(ll node_num,ll lo,ll hi,ll x){
    if(x<lo||hi<x)return;
    if(hi==lo){
        seg_tree[node_num].count_close=!seg_tree[node_num].count_close;
        seg_tree[node_num].count_open=!seg_tree[node_num].count_open;
        return;
    }
    ll mid=(hi+lo)/2;
    update_tree(node_num*2,lo,mid,x);
    update_tree(node_num*2+1,mid+1,hi,x);
    int change=min(seg_tree[(node_num<<1)].count_open,seg_tree[(node_num<<1)+1].count_close);
    seg_tree[node_num].count_close=seg_tree[(node_num<<1)].count_close+seg_tree[(node_num<<1)+1].count_close-change;
    seg_tree[node_num].count_open=seg_tree[(node_num<<1)].count_open+seg_tree[(node_num<<1)+1].count_open-change;
}
int main(){
    ios::sync_with_stdio(false);
    for(int i=1;i<=10;++i){
        int n;cin>>n;
        memset(seg_tree,0,sizeof(seg_tree));
        str.clear();cin>>str;
        construct_tree(1,1,n);
        int q;cin>>q;
        cout<<"Test "<<i<<":\n";
        while(q--){
            int v;cin>>v;
            if(!v)query()?cout<<"YES\n":cout<<"NO\n";
            else{
                update_tree(1,1,n,v);
            }
        }
    }
    return 0;
}
