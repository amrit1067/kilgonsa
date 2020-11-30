class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& ed, int K) {
        vector<vector<pair<int,int>>> adj(n);
        for(int i=0;i<ed.size();i++){
            adj[ed[i][0]].push_back({ed[i][1],ed[i][2]});
            adj[ed[i][1]].push_back({ed[i][0],ed[i][2]});
        }
        
        //vector<int> dist(n,0);
        priority_queue<int,vector<int>,greater<int>>pq;
        vector<int> dist(n);
        int mn=INT_MAX;
        int cnt=0;
        int ans=0;
        for(int i=0;i<n;i++){
            pq.push(i);
            for(int j=0;j<n;j++) dist[j]=INT_MAX;
            
            dist[i]=0;
            cnt=0;
            while(!pq.empty()){
                int s=pq.top();
                pq.pop();
                
                for(auto x: adj[s]){
                    int u=x.first;
                    int w=x.second;
                    if(dist[s]+w<dist[u]){
                        dist[u]=dist[s]+w;
                        pq.push(u);
                    }
                    
                }
            }
            for(int j=0;j<n;j++){
                if(j!=i&&dist[j]<=K) cnt++;
            }
            if(mn>=cnt){
                mn=cnt;
                ans=i;
            }
            
            //cout<<cnt<<" "<<i<<endl;
        }
        
        return ans;
    }
};
