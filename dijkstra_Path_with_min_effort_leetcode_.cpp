class Solution {
    struct comp{ 
        bool operator()(const pair<int,pair<int, int>>& p1, const pair<int,pair<int,int>>& p2) {
            
            // return the bigger probability pair
            return p1.second.second > p2.second.second;
        }
    };
public:
    int minimumEffortPath(vector<vector<int>>& edges) {
        int n=edges.size();
        int h=edges[0].size();
        vector<vector<int>> ef(n,vector<int>(h,INT_MAX));
        ef[0][0]=0;
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,comp> pq;
        pq.push({0,{0,0}});
        while(!pq.empty()){
            auto a=pq.top();
            int u=a.first;
            int v=a.second.first;
            int w=a.second.second;
            pq.pop();
            if(u+1<n){
                if(ef[u+1][v]>max(ef[u][v],abs(edges[u][v]-edges[u+1][v]))){
                    ef[u+1][v]=max(ef[u][v],abs(edges[u][v]-edges[u+1][v]));
                    pq.push({u+1,{v,ef[u+1][v]}});
                }
            }
            if(u-1>=0){
                if(ef[u-1][v]>max(ef[u][v],abs(edges[u][v]-edges[u-1][v]))){
                    ef[u-1][v]=max(ef[u][v],abs(edges[u][v]-edges[u-1][v]));
                    pq.push({u-1,{v,ef[u-1][v]}});
                }
            }
            if(v+1<h){
                if(ef[u][v+1]>max(ef[u][v],abs(edges[u][v]-edges[u][v+1]))){
                    ef[u][v+1]=max(ef[u][v],abs(edges[u][v]-edges[u][v+1]));
                    pq.push({u,{v+1,ef[u][v+1]}});
                }
            }
            if(v-1>=0){
                if(ef[u][v-1]>max(ef[u][v],abs(edges[u][v]-edges[u][v-1]))){
                    ef[u][v-1]=max(ef[u][v],abs(edges[u][v]-edges[u][v-1]));
                    pq.push({u,{v-1,ef[u][v-1]}});
                }
            }
        }
        return ef[n-1][h-1];
    }
};
