#include <bits/stdc++.h>
#define SIZE 1005

using namespace std;

char graph[SIZE][SIZE];
//R: rows of matrix
//C: columns of matrix
int R=0,C=0;
//to be used on second pass
int Best_x,Best_y;
//for aiding in finding adjacent nodes in implicit graph
int dr[]={0,1,0,-1};
int dc[]={1,0,-1,0};
//ie U,R,D,L
//returns the length of diameter
int Search(int x,int y){
    //x,y: contains the starting index
    //last: stores the longest path
    //best: stores the overall longest path
    int last=0,best=0;
    //holds the local longest path
    int best_x=x,best_y=y;
    //if called from a valid node
    if(graph[x][y]=='.'){
        //mark as visited
        graph[x][y]='x';
        //check all the neighbouring cells
        for(int d=0;d<4;++d){
            //computes the nearby valid cells
            last=Search(x+dr[d],y+dc[d]);
            //if a better path is found 
            //update the older path 
            if(last>best){best=last,best_x=Best_x,best_y=Best_y;}
        }
        //set the best path 
        Best_x=best_x,Best_y=best_y;
        //return 
        return best+1;
    }
    return 0;
}
int main(){
    ios::sync_with_stdio(false);
    int t; cin>>t;
    while(t--){
        cin>>C>>R;
        //taking input from string
        for(int i=0;i<R;++i)cin>>graph[i];
        int x=1,y=1;
        //findiong the first non-wall cell 
        while(graph[x][y]=='#'){
            if(x<C-1)x++;
            else{
                x=1;y++;
            }
        }
        //search from here
        //it sets the value of global Best_x & Best_y
        Search(x,y);
        //checks if all are connected & resets the path
        for(int i=0;i<R;i++)for(int j=0;j<C;++j)if(graph[i][j]=='x')graph[i][j]='.';else if(graph[i][j]=='.')cout<<"error";
        //calls the dfs again from Best_x,Best_y
        //print answer
        cout<<"Maximum rope length is "<<   Search(Best_x,Best_y)-1<<".\n";
    }
    return 0;
}
