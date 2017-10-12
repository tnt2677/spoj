#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll dp[12][2][83],k; //dp[index][smaller][remainder]
//For integers, the sum of digits can't be greater than 82

ll dp_solve(string & s,int index,bool smaller,int mod1){
	//base case the no is constructed
	if(index==s.length())return(mod1==0);
	//if memoized return ans
  	if(dp[index][smaller][mod1]!=-1)return dp[index][smaller][mod1];
        //set initial limit as 9 ; if no. is still equal set upper limit as S[index] 
        limit=smaller?s[index]-'0':9;
	//count stores ans
        dp[index][smaller][mod1]=0;
        for(int i=0;i<=limit;i++){
            bool ns;
            if(i<s[index]-'0')ns=0;
            else ns=smaller;
            dp[index][smaller][mod1]+=dp_solve(s, index+1, ns,(mod1+i)%k);
        }
        return dp[index][smaller][mod1];
}
int main(){
      //Find numbers between A and B whose sum of digits is divisible by K
      int a,b; cin>>a>>b>>k;
      //If A and B are ints, then the sum of the digits can't be greater than 82
        if(k>82)cout<<"0\n";
        string s=to_string(a-1);
        string s2=to_string(b);
        memset(dp,-1,sizeof(dp));
        ll a1=dp_solve(s,0,1,0); //Solving for a-1
        memset(dp,-1,sizeof(dp));
        ll a2=dp_solve(s2, 0, 1, 0); //Solving for b
        cout<<a2-a1<<endl;
    return 0;
}
