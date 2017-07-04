#include <bits/stdc++.h>
#define MAX (ll)200005
#define SIZE 30005
#define COUNT 1000005
typedef long long ll;

using namespace std;

struct node{
    int l,r,qno,ans;
};
int cnt[COUNT],arr[SIZE],n;
node query[MAX];

bool comparator( const node &lhs,const node &rhs){
    int temp=sqrt(n);
    if(int(lhs.l/temp)==int(rhs.l/temp))
        return lhs.r < rhs.r;
    else
        return (int)(lhs.l/temp) < (int)(rhs.l/temp);
}
void Add(int position,int i){
    cnt[arr[position]]++;
    if(cnt[arr[position]]==1)
        query[i].ans++;
}
void Remove(int position,int i){
    cnt[arr[position]]--;
    if(cnt[arr[position]]==0)
        query[i].ans--;
}
bool comparator1(const node&lhs,const node& rhs){
    return lhs.qno<rhs.qno;
}
int main(){
    //ios::sync_with_stdio(false);
    memset(cnt,0,sizeof(cnt));
    scanf("%d",&n);
    for(int i=1;i<=n;++i)
        scanf("%d",arr+i);
    int q; scanf("%d",&q);
    for(int i=0;i<q;++i){
        scanf("%d%d",&query[i].l,&query[i].r);
        query[i].qno=i;
        query[i].ans=0;
    }
    sort(query,query+q,comparator);
    int currentl=0,currentr=0;
    for(int i=0;i<q;++i){
        int l=query[i].l;
        int r=query[i].r;
        if(i!=0){
            query[i].ans=query[i-1].ans;
        }
        while(currentr<r){
            Add(++currentr,i);
        }
        while(currentr>r){
            Remove(currentr,i);
            currentr--;
        }
        while(currentl<l){
            Remove(currentl,i);
            currentl++;
        }
        while(currentl>l){
            Add(--currentl,i);
        }
    }
    sort(query,query+q,comparator1);
    for(int i=0;i<q;++i){
        printf("%d\n",query[i].ans);
    }
    return 0;
}
