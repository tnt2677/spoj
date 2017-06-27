#include <bits/stdc++.h>
using namespace std;


int main() {
    int n;
    cin>>n;
    int ans=0;
    vector<int> arr;
    for(int i=0;i<n;++i){
        int temp;
        cin>>temp;
        arr.push_back(temp);
    }
    stack<int> value,start;
    value.push(arr[0]);
    start.push(0);

    for(int i=1;i<arr.size();++i){
        if(arr[i]>value.top()||value.empty()){
            start.push(i);
            value.push(arr[i]);
        }else if(arr[i]<value.top()){
            ans=max(ans,value.top()*(i-start.top()));
            value.pop();
            while(!value.empty()&&value.top()>=arr[i]){
                start.pop();
                ans=max(ans,value.top()*(i-start.top()));
                value.pop();
            }
            value.push(arr[i]);
        }
    }
    int i=arr.size();
    while(!value.empty()){
         ans=max(ans,value.top()*(i-start.top()));
         value.pop();
         start.pop();
    }
    cout<<ans<<endl;
    return 0;
}
