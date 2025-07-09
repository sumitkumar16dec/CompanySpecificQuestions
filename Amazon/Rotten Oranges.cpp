Question: https://leetcode.com/problems/rotting-oranges/

Input: grid = [[2,1,1],[1,1,0],[0,1,1]]
Output: 4

TC: O(n*m), SC: O(n*m)

Using BFS:
#include<bits/stdc++.h>
using namespace std;

int bfs(vector<vector<int>> &grid){
    queue<pair<pair<int,int>, int>> q;   // {{r,c},t}
    int n= grid.size(), m= grid[0].size();
    int maxt=0, cntFresh=0, cnt=0;
    int vis[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]==2){
                vis[i][j]=1;
                q.push({{i,j},0});
            }
            else vis[i][j]=0;
            if(grid[i][j]==1) cntFresh++;
        }
    }
    
    while(!q.empty()){
        int row= q.front().first.first;
        int col= q.front().first.second;
        int t= q.front().second;
        q.pop();
        maxt= max(maxt, t);
        
        int drow[4]= {-1,0,1,0};
        int dcol[4]= {0,1,0,-1};
        for(int i=0;i<4;i++){
            int nrow= row+drow[i];
            int ncol= col+dcol[i];
            
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && vis[nrow][ncol]==0 && grid[nrow][ncol]==1){
                vis[nrow][ncol]=1;
                q.push({{nrow,ncol},t+1});
                cnt++;
            }
        }
    }
    if(cntFresh!=cnt) return -1;
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<m;j++){
    //         if(vis[i][j]!=1 && grid[i][j]==1) return -1;
    //     }
    // }
    return maxt;
}

int main(){
    vector<vector<int>> grid= {
        {0, 1, 2},
        {0, 1, 2},
        {2, 1, 1}
    };
    int t= bfs(grid);
    cout<<t;
    
    return 0;
}
