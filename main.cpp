#include <bits/stdc++.h>
#define MAX (ll)200005
#define SIZE 30005
#define COUNT 1000005
typedef long long ll;

using namespace std;

bool is_prefix(string &str1,string &str2){
    int s1=str1.size();
    int s2=str2.size();
    if(s1>s2)return is_prefix(str2,str1);
    for(int i=0;i<s1;++i)
        if(str1[i]!=str2[i])
            return false;
    return true;
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        string arr[n];
        bool ans=true;
        for(int i=0;i<n;++i)
            cin>>arr[i];
         sort(arr,arr+n);
        for(int i=0;i<n;++i){
            for(int j=i+1;j<n;++j){
                if(arr[i][0]<arr[j][0])break;
                if(is_prefix(arr[i],arr[j])){
                    ans=false;
                    break;
                }
            }
            if(!ans)
                break;
        }
        if(ans)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
