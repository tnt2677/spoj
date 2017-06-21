#include <bits/stdc++.h>
typedef  long long ll;
using namespace std;

void print(string &str,int cnt){
    int i=0;
    while(i<2)
        cout<<str[i++];
    cout<<" ";
    while(i<10)
        cout<<str[i++];
    cout<<" ";
    while(i<14)
        cout<<str[i++];
    cout<<" ";
    while(i<18)
        cout<<str[i++];
    cout<<" ";
    while(i<22)
        cout<<str[i++];
    cout<<" ";
    while(i<str.size())
        cout<<str[i++];
    cout<<" ";
    cout<<cnt<<endl;
}
int main(){
        ios::sync_with_stdio(false);
        int t;
        cin>>t;
        while(t--){
            int n;
            cin>>n;
            vector<string> arr(n);
            for(int i=0;i<n;++i){
                for(int j=1;j<=6;++j){
                    string temp;
                    cin>>temp;
                    arr[i]+=temp;
                }
            }
            sort(arr.begin(),arr.end());
            string temp=arr[0];
            int cnt=1;
            for(int i=1;i<arr.size();++i){
                if(arr[i]!=temp){
                    print(temp,cnt);
                    temp.clear();
                    temp+=arr[i];
                    cnt=1;
                }else{
                    cnt++;
                }
            }
            print(temp,cnt);
            cout<<endl;
        }
    return 0;
}
