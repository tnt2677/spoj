#include <bits/stdc++.h>
typedef  long long ll;
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;++i){
        cin>>arr[i];
    }
    int k,i=1;
    cin>>k;
    deque<pair<int,int> > q;
    q.push_back(make_pair(arr[0],0));
    while(i<k){
        if(arr[i]>q.front().first){
            q.push_front(make_pair(arr[i],i));
        }else{
            while(!q.empty()&&arr[i]>q.back().first){
                q.pop_back();
            }
            q.push_back(make_pair(arr[i],i));
        }
        i++;
    }
    for(i;i<n;++i){
        while(q.front().second<(i-k))q.pop_front();
        cout<<q.front().first<<" ";
        if(arr[i]>q.front().first){
            q.push_front(make_pair(arr[i],i));
        }else{
            while(!q.empty()&&arr[i]>q.back().first){
                q.pop_back();
            }
            q.push_back(make_pair(arr[i],i));
        }
    }
    while(q.front().second<(i-k))q.pop_front();
        cout<<q.front().first<<endl;
    return 0;
}
