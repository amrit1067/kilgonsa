class Solution {
public:
    struct comp{
        bool operator() (pair<int, int> const& a, 
        pair<int, int> const& b){
            return a.second > b.second;
        }
    };
    int findCheapestPrice(int n, vector<vector<int>>& f, int src, int dst, int K) {

        vector<pair<int,int>> adj[n];
        for(int i=0;i<(int)f.size();i++){
            adj[f[i][0]].push_back({f[i][1],f[i][2]});
        }
        int ans=INT_MAX;
        queue<pair<int,int>> q;
        q.push({src,0});
        
        while(!q.empty()&&K-->=-1){
            int n=q.size();
            while(n--){
                auto p=q.front();
                q.pop();
                int u=p.first;
                int w=p.second;
                
                if(u==dst){
                    ans=min(ans,w);
                    continue;
                }
                
                for(auto x:adj[u]){
                    if(ans>x.second+w)
                    q.push({x.first,x.second+w});
                }
            }
        }
        return ans==INT_MAX ? -1:ans;
    }
};
