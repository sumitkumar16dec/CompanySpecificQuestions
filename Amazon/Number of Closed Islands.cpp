Question/Answer: https://youtu.be/W29P4Z9ZQdQ?si=xM475sYNtfdylx7Q

Input :
{{1,1,1,1,1,1,1,0},
{1,0,0,0,0,1,1,0},
{1,0,1,0,1,1,1,0},
{1,0,0,0,0,1,0,1},
{1,1,1,1,1,1,1,0}};

Output: 2

TC: O(n*m) (Traversing each element of 2D matrix), SC: O(n*m) (Recursion Stack Space)

#include<bits/stdc++.h>
using namespace std;

void dfs(int i, int j, vector<vector<int>> &grid){
    int n= grid.size(), m= grid[0].size();
    //base condition
    if(i<0 || i>=n || j<0 || j>=m || grid[i][j]!=0) return;
    
    grid[i][j]=1;
    int drow[4]= {-1,0,1,0};
    int dcol[4]= {0,1,0,-1};
    
    for(int k=0;k<4;k++){
        int row= i+drow[k];
        int col= j+dcol[k];
        dfs(row, col, grid);
    }
}

int main(){
    vector<vector<int>> grid={
        {1,1,1,1,1,1,1,0},
        {1,0,0,0,0,1,1,0},
        {1,0,1,0,1,1,1,0},
        {1,0,0,0,0,1,0,1},
        {1,1,1,1,1,1,1,0}
    };
    
    int n= grid.size(), m= grid[0].size();
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if((i==0 || j==0 || i==n-1 || j==m-1) && grid[i][j]==0){
                dfs(i, j, grid);
            }
        }
    }
    
    int cnt=0;
    for(int i=1;i<n-1;i++){
        for(int j=1;j<m-1;j++){
            if(grid[i][j]==0){
                cnt++;
                dfs(i, j, grid);
            }
        }
    }
    cout<<cnt;
    
    return 0;
}
