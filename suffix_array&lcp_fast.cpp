#include <bits/stdc++.h>
#define MAX 50005
#define ii pair<int,int>
typedef long long ll;
using namespace std;
struct node{
    int index;
    ii ra;
};
//cmp to sort according to (ii)ra
bool cmp(const node &lhs,const node &rhs){
    return lhs.ra<rhs.ra;
}
node arr[MAX];int temp[MAX];
void func(char *str,int n){
    for(int i=0;i<n;++i){
        arr[i].index=i;
        arr[i].ra.first=str[i];
        arr[i].ra.second=(i+1<n)?str[i+1]:-1;
    }
    sort(arr,arr+n,cmp);
    for(int k=2;k<n;k<<=1){
        int rank=0,prev=arr[0].ra.first;
        arr[0].ra.first=rank;temp[arr[0].index]=0;
        for(int i=1;i<n;++i){
            if(arr[i].ra.first==prev&&arr[i].ra.second==arr[i-1].ra.second){
                prev=arr[i].ra.first;
                arr[i].ra.first=rank;
            }else{
                prev=arr[i].ra.first;
                arr[i].ra.first=++rank;
            }
            temp[arr[i].index]=i;
        }
        for(int i=0;i<n;++i){
            int nxtrnk=k+arr[i].index;
            arr[i].ra.second=nxtrnk<n?arr[temp[nxtrnk]].ra.first:-1;
        }
        sort(arr,arr+n,cmp);
    }
}
int lcp[MAX];
ll calculate(char* str ,int n){
    ll ans=0;
    for(int i=0,k=0;i<n;++i,k?k--:0){
        if(temp[i]==n-1){k=0;continue;}
        int j=arr[temp[i]+1].index;
        while(i+k<n&&j+k<n&&str[i+k]==str[j+k])k++;
        lcp[temp[i]]=k;ans+=k;
    }
    return ans;
}
int main(){
    int t;scanf("%d",&t);
    while(t--){
        char str[MAX];
        scanf("%s",str);int n=strlen(str);
        func(str,n);ll x=calculate(str,n);
        ll ans=((n*(n+1))/2LL)-x;
        printf("%lld\n",ans);
    }
	return 0;
}
