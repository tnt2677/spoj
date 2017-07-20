#include <bits/stdc++.h>
#define vi vector<int>
#define ii pair<int>

using namespace std;

//union-find data structure:
//~ O(1): find_set=> returns the root of the index ie. returns representative element 
//~ O(1): if_same=> returns if two indexes belong to the same set
//~ O(1): union_set=> merges two sets

class union_find{
    //uses union by rank & path compression techniques to achieve fast processing
private:
    //p: holds the parent of every node
    //if p[i]=i: ith node is the root node
    //Rank: holds the ranks
    vi p,Rank;
    
public:
    //union_find: constructor for initializing the ds
    //if zero based indexing is used: use union_find(n)
    //if 1 based indexing is to be used: use union_set(n+1)
    union_find(int n){
        //initializes Rank with 0's
        Rank.assign(n,0);
        //initializes p with 0's
        p.assign(n,0);
        //initially all nodes are the roots ie. each set is distinct
        for(int i=0;i<n;++i){
            p[i]=i;
        }
    }
    
    //find_set: returns the representative element of current node
    int find_set(int i){
        return p[i]==i? i: p[i]=find_set(p[i]);
        }
    
    //returns true if both belong to the same set,false other-wise
    bool if_same(int i,int j){
        return find_set(i)==find_set(j);
    }
    
    //merges two sets: i & j
    void union_set(int i,int j){
        //if both don't belong to the same set
        if(!if_same(i,j)){
            //find the roots
            int x=find_set(i), y=find_set(j);
            //if : rank of x< rank of y
            //attach x's tree to y's tree
            if(Rank[x]<Rank[y]){
                p[x]=y;
                Rank[y]+=Rank[x];
            }else{
            //else vice-versa
                p[y]=x;
                Rank[x]+=Rank[y];
            }
        }
    }
};

int main() {
    return 0;
}
