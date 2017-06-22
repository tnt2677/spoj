#include <bits/stdc++.h>

typedef  long long ll;
using namespace std;

int gcd(int a,int b){
    if(b==0)return a;
    else
        return gcd(b,a%b);
}
void gcd_temp(string a,int b){
    if(b==0)cout<<a;
    else{
        int ans=0;
        for(auto i:a){
            ans=(ans*10+(i-'0'))%b;
        }
        cout<<gcd(b,ans);
    }
}
int main(){
   ios::sync_with_stdio(false);
   int t;
   cin>>t;
   while(t--){
    int a;
    string str;
    cin>>a>>str;
    gcd_temp(str,a);
    cout<<endl;
   }
    return 0;
}
