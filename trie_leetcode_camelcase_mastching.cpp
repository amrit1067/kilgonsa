class Solution {
    struct trie{
        unordered_map<char,trie*> mp;
        bool isEnd =false;
        trie(){}
        
        void insert(string &key){
            trie* curr=this;
            for(const auto &c: key){
                if(!curr->mp.count(c)){
                    curr->mp[c]=new trie();
                }
                curr=curr->mp[c];
            }
            curr->isEnd=true;
        }
        bool search(string &key){
            trie* curr=this;
            for(const auto &c: key){
                if(!curr->mp.count(c)){
                    if(isupper(c)) return false;
                    continue;
                }
                curr=curr->mp[c];
            }
            return curr->isEnd;
        }
    };
public:
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        trie* root=new trie();
        root->insert(pattern);
        vector<bool> ans;
        for(auto & x: queries){
            ans.push_back(root->search(x));
        }
        return ans;
    }
};
