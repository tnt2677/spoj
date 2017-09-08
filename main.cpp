#include <bits/stdc++.h>
using namespace std;
//ref:https://www.quora.com/How-can-the-problem-Ones-and-zeros-on-SPOJ-be-solved-using-BFS#
map<int,string> mp;
//returns modulos in biginteger
int mod(const string & str,int n){
    int ans=0;
    for(int i=0;i<(int)str.size();++i){
        ans=(ans*10+(str[i]-'0'))%n;
    }
    return ans;
}
//returns first no. containing only of ones and zero's
//say str%n gives "i"
//if i has been seen earlier then ignore as it can't possibly give the right answer
//else mark current stste as visited
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
