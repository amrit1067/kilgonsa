struct Trienode{
        Trienode *child[26];
        bool isEnd;
        Trienode(){
            isEnd=false;
            for(int i=0;i<26;i++){
                child[i]=NULL;
            }
        }
        void insert(string &key){
            Trienode *curr=this;
            
            for(int i=0;i<key.size();i++){
                int ind=key[i]-'a';
                if(curr->child[ind]==NULL){
                    curr->child[ind]=new Trienode();
                }
                curr=curr->child[ind];
            }
            curr->isEnd=true;
        }
        bool search(string &key){
            Trienode* curr=this;
            for(int i=0;i<key.size();i++){
                int ind=key[i]-'a';
                if(curr->child[ind]==NULL||!curr->child[ind]->isEnd) return false;
                curr=curr->child[ind];
            }
            return curr->isEnd;
        }
    };
    string longestWord(vector<string>& words) {
        Trienode *root = new Trienode();
        
        for(int i=0;i<words.size();i++){
            root->insert(words[i]);
        }
        
        string ans="";
        
        for(int i=0;i<(int)words.size();i++){
            
            if(root->search(words[i])){
                
                if(words[i].size()==ans.size()){
                    ans=min(ans,words[i]);
                    cout<<words[i]<<" ";
                }else if(words[i].size()>ans.size()){
                    ans=words[i];
                    
                }
            }
        }
        return ans;
    }
