#include <bits/stdc++.h>
#define MAX 55
#define ii pair<int,int >
#define vi vector<int>
#define vii vector<pair<int,int> >
typedef long long ll;
using namespace std;

map<int,string> mp;
int mod(const string & str,int n){
    int ans=0;
    for(int i=0;i<(int)str.size();++i){
        ans=(ans*10+(str[i]-'0'))%n;
    }
    return ans;
}
string func(int n){
    queue<string> q;q.push("1");
    mp.clear();
    while(true){
        string top=q.front();q.pop();
        int r=mod(top,n);
        if(!r)return top;
        if(mp.find(r)==mp.end()){
            q.push(top+'0');q.push(top+'1');
            mp[r]=top;
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        cout<<func(n)<<"\n";
    }
    return 0;
}
