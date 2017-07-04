/* spoj:DQUERY
 * user:tnt2677
 * dated:04/07/2017
 */
#include <bits/stdc++.h>
#define MAX (ll)200005
#define SIZE 30005
#define COUNT 1000005
typedef long long ll;

using namespace std;

//node holds: l-->left index, r-->right index, qno-->query no, ans-->final answer for the given query
struct node{
    int l,r,qno,ans;
};
//cnt--> frequencies of element
//arr--> contains the original array
int cnt[COUNT],arr[SIZE],n;

//query-->stores the query
node query[MAX];

//main logic : first sort by l/root(n) later by r
bool comparator( const node &lhs,const node &rhs){
    int temp=sqrt(n);
    if(int(lhs.l/temp)==int(rhs.l/temp))
        return lhs.r < rhs.r;
    else
        return (int)(lhs.l/temp) < (int)(rhs.l/temp);
}
//add the position
void Add(int position,int i){
    cnt[arr[position]]++;
    if(cnt[arr[position]]==1)
        query[i].ans++;
}
//remove the position
void Remove(int position,int i){
    cnt[arr[position]]--;
    if(cnt[arr[position]]==0)
        query[i].ans--;
}
//comparator for final query sorting
bool comparator1(const node&lhs,const node& rhs){
    return lhs.qno<rhs.qno;
}
int main(){
    //initialize the count array
    memset(cnt,0,sizeof(cnt));
    
    //n--> no of elements in array
    scanf("%d",&n);
    
    //taking the input
    for(int i=1;i<=n;++i)
        scanf("%d",arr+i);
    
    //q-->no of queries to be processed
    int q; scanf("%d",&q);
    
    //storing the queries
    for(int i=0;i<q;++i){
        scanf("%d%d",&query[i].l,&query[i].r);
        //storing the current query for future reordering
        query[i].qno=i;
        //initializing the answer
        query[i].ans=0;
    }
    
    //sorting to apply sqrt decomposition
    sort(query,query+q,comparator);
    
    //initializing currentl,currentr
    int currentl=0,currentr=0;
    
    //processing the queries
    for(int i=0;i<q;++i){
        //next query to be processed
        int l=query[i].l;
        int r=query[i].r;
        //if not the first query than pass the last answer
        if(i!=0){
            query[i].ans=query[i-1].ans;
        }
        //First move the right pointer,than left pointer
        //first increment later add
        while(currentr<r){
            Add(++currentr,i);
        }
        //first remove than decrement
        while(currentr>r){
            Remove(currentr--,i);
        }
        //first remove than increment
        while(currentl<l){
            Remove(currentl++,i);
        }
        //first decrement than add new element
        while(currentl>l){
            Add(--currentl,i);
        }
    }
    //reording the queries to follow the original ordering
    sort(query,query+q,comparator1);
    //output the answer
    for(int i=0;i<q;++i){
        printf("%d\n",query[i].ans);
    }
    return 0;
}
