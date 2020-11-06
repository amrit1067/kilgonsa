class Solution {
public:
    static const int MAXM=100000;
    vector<int> adj[MAXM];
    //int c=0;
    void dfs(int s,bool vis[]){
        vis[s]=1;
        for(int u:adj[s]){
            //c++;
            if(!vis[u]){
                dfs(u,vis);
            }
        }
    }
    void create(vector<vector<int>>& con){
        for(int i=0;i<con.size();i++){
            adj[con[i][0]].push_back(con[i][1]);
            adj[con[i][1]].push_back(con[i][0]);
        }
    }
    int makeConnected(int n, vector<vector<int>>& con) {
        bool vis[n+1];
        memset(vis,0,sizeof(vis));
        if(con.size()<n-1) return -1;
        create(con);
        int cnt=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i,vis);
                cnt++;
            }
        }
        return cnt-1;
    }
};
