#include <bits/stdc++.h>
#define SIZE 10
using namespace std;
int bit[SIZE+1];
void add(int i,int value){
    while(i<SIZE+1){
        bit[i]+=value;
        i+=(i&(-i));
    }
}
int sum(int indx){
    int ans=0;
    while(indx){
        ans+=bit[indx];
        indx-=(indx&(-indx));
    }
    return ans;
}
int  query(int from,int to){
    return sum(to)-sum(from-1);
}
int main() {
    memset(bit,0,sizeof(bit));
    for(int i=0;i<10;++i)
        add(i+1,i+1);
    cout<<sum(10)<<endl;
    cout<<query(5,8);
    return 0;
}
