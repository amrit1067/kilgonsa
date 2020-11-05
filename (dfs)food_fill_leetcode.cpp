class Solution {
public:
    //bool vis[52][52];
    void dfs(int i,int j,int newcolor,vector<vector<int>> &image,int old){
        if(i<0||i>=image.size()||j<0||j>=image[0].size()||image[i][j]!=old){
            return;
        }
        //vis[i][j]=1;
        image[i][j]=newcolor;
        dfs(i+1,j,newcolor,image,old);
        dfs(i-1,j,newcolor,image,old);
        dfs(i,j+1,newcolor,image,old);
        dfs(i,j-1,newcolor,image,old);
        
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newcolor) {
        if(image[sr][sc]==newcolor){
            return image;
        }
        //memset(vis,0,sizeof(vis));
        dfs(sr,sc,newcolor,image,image[sr][sc]);
        return image;
    }
};
