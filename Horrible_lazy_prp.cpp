#include <bits/stdc++.h>
typedef  long long ll;
using namespace std;

//lazy: holds changes,seg_tree: holds the actual segment tree
//if n is a perfect power of 2 than only 2n nodes will be required
//but if n is 2^k-1 ,in this case 2*(2^k+1) nodes will be required
//hence to be on the safer side 4*n nodes are declared
ll lazy[4 * 1000000],seg_tree[4 * 1000000];

//returns the query (i,j)
//node: the current node,
//l: holds the starting index ie. i,r: holds the end index for query ie. j,
//range of the values current node is responsible for
//tl: lower bound of index responsible, tr: upper bound of index responsible
ll Query(ll node,ll tl,ll tr,ll l,ll r){
    //if some changes are needed to be propogated
    //ie. lazy[current node] is not zero
    if(lazy[node]>0){
        //update the value of seg_tree by adding the value stored in lazy tree
        seg_tree[node]+=(tr-tl+1)*lazy[node];
        //if not the leaf node then propogate the changes down further
        if(tl!=tr){
            //pass down to the left tree
            lazy[node*2]+=lazy[node];
            //pass down to the right tree
            lazy[node*2+1]+=lazy[node];
        }
        //reset the lazy node of current to zero
        lazy[node]=0;
    }
    // actual query
    //if not in range ie. tl---tr.....l----r OR l----r.....tl----tr OR invalid index ie.tr<tl
    //return 
    if(tr<l||tl>r||tr<tl)
        return 0;
    //if completely in the range ie. l...tl-----tr....r
    //return the value stored in seg_tree[current node]
    if(tl>=l&&tr<=r){
        return seg_tree[node];
    }else{
        //else it implies the range of the node and query partially overlap
        //find the mid say tm = left + right/2
        ll tm=(tl+tr)/2;
        //query the sub trees,return the sum
        return Query(node*2,tl,tm,l,r) + Query(node*2+1,tm+1,tr,l,r);
    }
}

//update the range ie. adds the "value" to the range: [l,r]
//node: current node
//tl: starting index of range for which node is responsible for,
//tr: ending index of the above range
//l: starting index of range to be modified
//r: end index of the same,value: value to be added to the give range
void Update(ll node,ll tl,ll tr,ll l,ll r,ll value){
    //similar to query
    if(lazy[node]>0){
        seg_tree[node]+=(tr-tl+1)*lazy[node];
        if(tl!=tr){
            lazy[node*2]+=lazy[node];
            lazy[node*2+1]+=lazy[node];
        }
        lazy[node]=0;
    }
    //if current range not includes the range[l,r]
    //return
    if(tr<l||tl>r||tr<tl)
        return;
    //if complete overlap
    //update the current node with value
    if(tl>=l&&tr<=r){
        seg_tree[node]+=(tr-tl+1)*value;
        //if not a leaf node:
        //set the child nodes for the lazy update,by setting the lazy node of the childs nodes to value
        if(tl!=tr){
            lazy[node*2]+=value;
            lazy[node*2+1]+=value;
        }
        return;
    }else{
        //else pass down the updates in case of partial overlap
        ll tm = (tl+tr)/2;
        Update(node*2,tl,tm,l,r,value);
        Update(node*2+1,tm+1,tr,l,r,value);
        //now update the current node as well
        seg_tree[node]=seg_tree[node*2]+seg_tree[node*2+1];
    }
}
int main(){
    ios::sync_with_stdio(false);
    //t: no of test cases
    int t; cin>>t;
    while(t--){
        //initialize the seg_tree & lazy with 0
        memset(seg_tree,0,sizeof(seg_tree));
        memset(lazy,0,sizeof(lazy));
        int n,c; cin>>n>>c;
        while(c--){
            bool type; cin>>type;
            if(type){
                int x,y; cin>>x>>y;
                //query
                cout<<(ll)Query(1,1,n,x,y)<<endl;
            }else{
                int x,y,value; cin>>x>>y>>value;
                //updation
                Update(1,1,n,x,y,value);
            }
        }
    }
    return 0;
}
