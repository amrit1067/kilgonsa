class Solution {
public:
    vector<int> par;
    vector<int> rank;
    int find(int x){
        if(par[x]==x) return x;
        par[x]=find(par[x]);
        return par[x];
    }
    bool unionly(int x,int y){
        int a=find(x);
        int b=find(y);
        if(a==b) return true;
        if(rank[a]<rank[b]) par[a]=b;
        else par[b]=a;
        if(rank[a]==rank[b]) rank[a]++;
        return false;
    }
    int makeConnected(int n, vector<vector<int>>& edges) {
        par=vector<int> (n);
        rank=vector<int> (n);
        for(int i=0;i<n;i++) par[i]=i,rank[i]=0;
        int extra=0,cnt=0;
        for(auto &ed:edges){
            extra+=unionly(ed[0],ed[1]);
        }
        for(int i=0;i<n;i++){
            cnt+=(par[i]==i);
        }
        return extra>=cnt-1? cnt-1:-1;
    }
};
