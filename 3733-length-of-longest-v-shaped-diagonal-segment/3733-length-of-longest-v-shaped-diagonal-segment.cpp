class Solution {
public:

    int row[4]={1,1,-1,-1};
    int col[4]={1,-1,-1,1};

    int helper(int x,int y,int k,vector<vector<int>>& grid,vector<vector<vector<int>>>& dp,int dir){
        int m=grid.size(),n=grid[0].size();
        if(dp[k][dir][n*x+y]!=-1) return dp[k][dir][n*x+y];
        int ans=0;
        int nx=x+row[dir],ny=y+col[dir];
        if(grid[x][y]==1){
            if(nx<m && ny<n && ny>=0 && nx>=0 && grid[nx][ny]==2){
                ans=max(ans,1+helper(nx,ny,k,grid,dp,dir));
            }
        }
        else if(grid[x][y]==2){
            if(nx<m && ny<n && ny>=0 && nx>=0 && grid[nx][ny]==0){
                ans=max(ans,1+helper(nx,ny,k,grid,dp,dir));
            }
            if(k==0){
                nx=x+row[(dir+1)%4],ny=y+col[(dir+1)%4];
                if(nx<m && ny<n && ny>=0 && nx>=0 && grid[nx][ny]==0){
                    ans=max(ans,1+helper(nx,ny,1,grid,dp,(dir+1)%4));
                }
            }
        }
        else{
            if(nx<m && ny<n && ny>=0 && nx>=0 && grid[nx][ny]==2){
                ans=max(ans,1+helper(nx,ny,k,grid,dp,dir));
            }
            if(k==0){
                nx=x+row[(dir+1)%4],ny=y+col[(dir+1)%4];
                if(nx<m && ny<n && ny>=0 && nx>=0 && grid[nx][ny]==2){
                    ans=max(ans,1+helper(nx,ny,1,grid,dp,(dir+1)%4));
                }
            }
        }
        
        return dp[k][dir][n*x+y]=ans;
    }

    int lenOfVDiagonal(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        int ans=0;
        vector<vector<vector<int>>> dp(2,vector<vector<int>> (4,vector<int> (m*n,-1)));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    ans=max(1+helper(i,j,0,grid,dp,0),ans);
                    ans=max(1+helper(i,j,0,grid,dp,1),ans);
                    ans=max(1+helper(i,j,0,grid,dp,2),ans);
                    ans=max(1+helper(i,j,0,grid,dp,3),ans);
                }
            }
        }
        return ans;
    }
};