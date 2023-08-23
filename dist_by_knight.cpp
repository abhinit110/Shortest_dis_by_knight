class Solution 
{
    public:
    //Function to find out minimum steps Knight needs to reach target position.
    void bfs(vector<vector<int>>&vis,int i,int j,vector<vector<int>>&dis,int N)
    {
        int m=N,n=N;
        queue<pair<pair<int,int>,int>>q;
        vis[i][j]=1;
        q.push({{i,j},0});
        while(!q.empty())
        {
            pair<pair<int,int>,int>f=q.front();
            q.pop();
            pair<int,int>ind=f.first;
            int wt=f.second;
            i=ind.first;
            j=ind.second;
            if(i-1>=0 && j-2>=0)
            {
                if(vis[i-1][j-2]==0 && dis[i-1][j-2]>wt+1)
                {
                    vis[i-1][j-2]=1;
                    q.push({{i-1,j-2},wt+1});
                    dis[i-1][j-2]=wt+1;
                }
            }
            if(i-1>=0 && j+2<m)
            {
                if(vis[i-1][j+2]==0 && dis[i-1][j+2]>wt+1)
                {
                    vis[i-1][j+2]=1;
                    q.push({{i-1,j+2},wt+1});
                    dis[i-1][j+2]=wt+1;
                }
            }
            if(i+1<n && j+2<m)
            {
                if(vis[i+1][j+2]==0 && dis[i+1][j+2]>wt+1)
                {
                    vis[i+1][j+2]=1;
                    q.push({{i+1,j+2},wt+1});
                    dis[i+1][j+2]=wt+1;
                }
            }
            if(i+1<n && j-2<m)
            {
                if(vis[i+1][j-2]==0 && dis[i+1][j-2]>wt+1)
                {
                    vis[i+1][j-2]=1;
                    q.push({{i+1,j-2},wt+1});
                    dis[i+1][j-2]=wt+1;
                }
            }
            if(i+2<n && j+1<m)
            {
                if(vis[i+2][j+1]==0 && dis[i+2][j+1]>wt+1)
                {
                    vis[i+2][j+1]=1;
                    q.push({{i+2,j+1},wt+1});
                    dis[i+2][j+1]=wt+1;
                }
            }
            if(i+2<n && j-1<m)
            {
                if(vis[i+2][j-1]==0 && dis[i+2][j-1]>wt+1)
                {
                    vis[i+2][j-1]=1;
                    q.push({{i+2,j-1},wt+1});
                    dis[i+2][j-1]=wt+1;
                }
            }
            if(i-2>=0 && j+1<m)
            {
                if(vis[i-2][j+1]==0 && dis[i-2][j+1]>wt+1)
                {
                    vis[i-2][j+1]=1;
                    q.push({{i-2,j+1},wt+1});
                    dis[i-2][j+1]=wt+1;
                }
            }
            if(i-2>=0 && j-1<m)
            {
                if(vis[i-2][j-1]==0 && dis[i-2][j-1]>wt+1)
                {
                    vis[i-2][j-1]=1;
                    q.push({{i-2,j-1},wt+1});
                    dis[i-2][j-1]=wt+1;
                }
            }
        }
    }
	int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int N)
	{
	    
	    vector<vector<int>>vis(N,vector<int>(N,0));
	    vector<vector<int>>dis(N,vector<int>(N,INT_MAX));
	    bfs(vis,KnightPos[0]-1,KnightPos[1]-1,dis,N);
	    if(KnightPos[0]==TargetPos[0] && KnightPos[1]==TargetPos[1])
	    return 0;
	    return dis[TargetPos[0]-1][TargetPos[1]-1];
	    
	}
};
