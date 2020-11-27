class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& suc, int start, int end) {
        
        vector<vector<pair<int,double>>> adj(n);
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back({edges[i][1],suc[i]});
            adj[edges[i][1]].push_back({edges[i][0],suc[i]});
        }
        vector<double> dis(n,0.0);
        dis[start]=1.0;
        queue<int> pq;
        pq.push(start);
        
        while(!pq.empty()){
            int p=pq.front();
            pq.pop();
            for(auto x:adj[p]){
                
                if(dis[p]*x.second>dis[x.first]){
                    
                    dis[x.first]=dis[p]*x.second;
                    pq.push(x.first);
                }
            }
            
        }
        return dis[end];
    }
};
