class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& ed, int K) {
        vector<vector<int>> dis(n,vector<int>(n,INT_MAX/2));
        for(int i=0;i<n;i++) dis[i][i]=0;
        
        for(auto &e:ed){
            int x=e[0];
            int y=e[1];
            int w=e[2];
            dis[x][y]=w;
            dis[y][x]=w;
        }
        
        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(dis[i][j]>dis[i][k]+dis[k][j]) dis[i][j]=dis[i][k]+dis[k][j];
                }
            }
        }
        
        int cnt=0;
        int ans=-1;
        int mn=INT_MAX;
        
        for(int i=0;i<n;i++){
            cnt=0;
            for(int j=0;j<n;j++){
                if(i==j) continue;
                if(dis[i][j]<=K) cnt++;
            }
            if(mn>=cnt){
                mn=cnt;
                ans=i;
            }
        }
        
        return ans;
    }
};
