class Solution {
public:
    int networkDelayTime(vector<vector<int>>& t, int N, int K) {
        vector<vector<pair<int,int>>> adj(N+1);
        
        for(int i=0;i<t.size();i++){
            adj[t[i][0]].push_back({t[i][1],t[i][2]});
        }
        priority_queue<int,vector<int>,greater<int>> q;
        vector<int> dis(N+1,INT_MAX);
        dis[0]=0;
        dis[K]=0;
        q.push(K);
        while(!q.empty()){
            int v=q.top();
            q.pop();
            for(auto x:adj[v]){
                if(dis[x.first]>dis[v]+x.second){
                    dis[x.first]=dis[v]+x.second;
                    q.push(x.first);
                }
            }
        }
        int mx=*max_element(dis.begin(),dis.end());
        return mx==INT_MAX ? -1: mx;
    }
};
