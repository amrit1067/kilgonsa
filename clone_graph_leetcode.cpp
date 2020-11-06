
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/
// dfs
class Solution {
public:
   unordered_map<Node*,Node*> mp; 
    Node* cloneGraph(Node* node) {
        if(!node) return NULL;
        if(mp.find(node)==mp.end()){
            mp[node]=new Node(node->val,{});
            for(Node* n:node->neighbors){
                mp[node]->neighbors.push_back(cloneGraph(n));
            }
        }
        return mp[node];
    }
};
//bfs
class Solution {
public:
   
    Node* cloneGraph(Node* node) {
        if(!node) return NULL;
        unordered_map<Node*,Node*> mp;
        queue<Node*> q;
        q.push(node);
        Node* temp=new Node(node->val);
        mp.insert({node,temp});
        while(!q.empty()){
            auto curr=q.front();
            q.pop();
            vector<Node*> nbr;
            for(auto n:curr->neighbors){
                if(mp.count(n)){
                    nbr.push_back(mp[n]);
                }else{
                    temp=new Node(n->val);
                    mp[n]=temp;
                    q.push(n);
                    nbr.push_back(temp);
                }
            }
            mp[curr]->neighbors=nbr;
        }
        return mp[node];
    }
};
//alter dfs
class Solution {
public:
    Node* graph[101]={0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    void dfs(Node* node){
        if(!graph[node->val]){
            graph[node->val]=new Node(node->val);
        }
        for(auto n:node->neighbors){
            if(!graph[n->val]){
                dfs(n);
            }
            graph[node->val]->neighbors.push_back(graph[n->val]);
        }
    }
    Node* cloneGraph(Node* node) {
        if(node) dfs(node);
        return graph[1];
    }
};
