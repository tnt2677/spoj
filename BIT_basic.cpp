#include <bits/stdc++.h>
#define SIZE 10

using namespace std;
//bit: holds binary indexed tree
//indexing starts with 1
int bit[SIZE+1];

//add: adds "value" to given index 
void add(int indx,int value){
    //as we are moving forward check that indx is within the ranges
    while(indx<SIZE+1){
        //increase the sum of current index
        bit[indx]+=value;
        //move to the next index given by
        //indx=indx+(last set bit of indx)
        indx+=(indx&(-indx));
    }
}

//sum: returns sum from 1st index to indx
int sum(int indx){
    //initialize ans by 0
    //ans will hold the final result
    int ans=0;
    //while indx is not equal to 0
    while(indx){
        //increment ans by value of BIT[current]
        ans+=bit[indx];
        //update the index
        indx-=(indx&(-indx));
    }
    return ans;
}
//query: queries a given range
int  query(int from,int to){
    return sum(to)-sum(from-1);
}

int main() {
    memset(bit,0,sizeof(bit));
    //make BIT by add(indx,value)
    return 0;
}
