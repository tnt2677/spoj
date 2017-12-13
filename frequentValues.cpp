#include <bits/stdc++.h>
#define MAX 1000009
#define SIZE 100009
#define inf 1000005LL
#define ii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>
typedef long long ll;
using namespace std;

int seg_tree[MAX*4];
vi arr,temp,freq;
void construct_tree(int node_num,int lo,int hi){
    if(hi==lo){
        seg_tree[node_num]=arr[lo];
        return;
    }
    int mid=(hi+lo)/2;
    construct_tree(node_num*2,lo,mid);
    construct_tree(node_num*2+1,mid+1,hi);
    int left=seg_tree[node_num*2];
    int right=seg_tree[node_num*2+1];
    seg_tree[node_num]=max(left,right);
}
int query(int node_num,int tlo,int thi,int lo,int hi){
    if(lo>hi||tlo>hi||lo>thi)
        return INT_MIN;
    if(lo<=tlo&&hi>=thi)
        return seg_tree[node_num];
    int tmid =(thi+tlo)/2;
    int left=query(node_num*2,tlo,tmid,lo,hi);
    int right=query(node_num*2+1,tmid+1,thi,lo,hi);
    int x=max(left,right);
    return x;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;cin>>n;
    while(n){
        int t,y;cin>>t>>y;
        freq.clear();arr.clear();temp.clear();
        freq.push_back(0);arr.push_back(0);temp.push_back(0);
        arr.push_back(1);temp.push_back(y),freq.push_back(y);
        for(int i=2;i<=n;++i){
            int y;cin>>y;freq.push_back(y);
            if(temp.back()==y)arr[arr.size()-1]++;
            else temp.push_back(y),arr.push_back(1);
        }
        construct_tree(1,1,arr.size()-1);
        map<int,int> mp;
        for(int i=1;i<(int)arr.size();++i)
            mp[temp[i]]=i;
        while(t--){
            int i,j;cin>>i>>j;
            if(freq[j]==freq[i])cout<<j-i+1<<endl;
            else if(mp[freq[i]]+1==mp[freq[j]]){
                    auto y=upper_bound(freq.begin()+i,freq.begin()+j+1,freq[i]);
                    int k=y-freq.begin();
                    int ans=max(k-i,j-k+1);
                    cout<<ans<<endl;
            }else{
                int v1=query(1,1,arr.size()-1,mp[freq[i]]+1,mp[freq[j]]-1);
                auto y=upper_bound(freq.begin()+i,freq.begin()+j+1,freq[i]);
                auto y1=lower_bound(freq.begin()+i,freq.begin()+j+1,freq[j]);
                int k=y-freq.begin();
                int ans=max(k-i,v1);
                k=y1-freq.begin();
                cout<<max(ans,j-k+1)<<endl;
            }
        }
        cin>>n;
    }
    return 0;
}
