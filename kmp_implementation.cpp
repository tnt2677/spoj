#include <bits/stdc++.h>
typedef unsigned int long long ll;
using namespace std;

void convert(string &str,int arr[]){
    int i=1;
    int j=0;
    arr[j]=0;
    while(i<str.length()){
        if(str[i]==str[j])
            arr[i++]=++j;
        else{
            if(j!=0)
                j=arr[j-1];
            else
                arr[i++]=0;
        }
    }
}
void calculate(string &str,string &text){
    int m=str.size();
    int n=text.size();
    int i=0,j=0;
    int lps[m];
    convert(str,lps);
    while(i<n){
        if(str[j]==text[i]){
            i++;j++;
            if(j==m){
                cout<<(i-j)<<endl;
                j=lps[j-1];
            }
        }else if(j>0)j=lps[j-1];
        else i++;
    }
}
int main(){
    ios::sync_with_stdio(false);
    int n;
    string text,str;
    while(cin>>n>>str>>text){
        if(n<text.length()){
            calculate(str,text);
        }
           cout<<endl;
    }
    return 0;
}
