#include<bits/stdc++.h>
//spoj:phone list
//use trie for better performance

using namespace std;

//checks if str1 is prefix of str2
bool is_prefix(string &str1,string &str2){
    //s1 & s2 contains the size of str1 & str2 
    int s1=str1.size();
    int s2=str2.size();
    
    //if s1 > s2 check : if str2 is prefix of str1
    if(s1>s2)return is_prefix(str2,str1);
    
    //check if str1 is prefix of str2
    //if mis-match : return false
    for(int i=0;i<s1;++i)
        if(str1[i]!=str2[i])
            return false;
    
    //else return true
    return true;
}
int main(){
    //t-->no of test cases
    int t; scanf("%d",&t);
    
    while(t--){
        //n--> no of strings to be checked
        int n; scanf("%d",&n);
        
        //arr-->contains the input pno.s
        string arr[n];
        
        //holds the ans :initially true(doesn't contain prefix)
        bool ans=true;
        for(int i=0;i<n;++i)
            cin>>arr[i];
        
        //sorting to reduce the search space
        sort(arr,arr+n);
        
        //checking all the possible test cases
        for(int i=0;i<n;++i){
            for(int j=i+1;j<n;++j){
                
                //if first elemnt is greater than the string than no need to further check
                if(arr[i][0]<arr[j][0])break;
                
                //if i or j is prefix of the other than break  
                if(is_prefix(arr[i],arr[j])){
                    ans=false;
                    break;
                }
            }
            
            //if ans is false break:as it contains a prefix
            if(!ans)
                break;
        }
        
        //output the answer
        if(ans)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
