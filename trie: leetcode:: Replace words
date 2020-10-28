class Solution {
    struct Trienode{
        Trienode* child[26] = {nullptr};
        bool isEnd=false;
        Trienode(){}
        
        void insert(string &str){
            Trienode* curr=this;
            for(int i=0;i<(int)str.size();i++){
                int ind=str[i]-'a';
                if(curr->child[ind]==NULL)
                    curr->child[ind]=new Trienode();
                curr=curr->child[ind];
            }
            curr->isEnd=true;
        }
        bool search(string &str){
            Trienode* curr= this;
            string ans="";
            
            for(int i=0;i<(int)str.size();i++){
                int ind=str[i]-'a';
                if(curr->isEnd){
                    str=ans;
                    return true;
                }
                if(curr->child[ind]==NULL){
                    return false;
                }
                ans=ans+str[i];
                curr=curr->child[ind];
            }
            if(curr->isEnd) str=ans;
            return curr->isEnd;
        }
    };
public:
    string replaceWords(vector<string>& d, string s) {
        
        Trienode* root=new Trienode();
        for(int i=0;i<d.size();i++){
            root->insert(d[i]);
        }
        
        string ans="";
        string word;
        stringstream iss(s);
        while(iss>>word){
            string k="";
            root->search(word);
            ans+=word+" ";
        }
        ans.pop_back();
        return ans;
    }
};
