class Solution {
public:
    int ladderLength(string beginword, string endword, vector<string>& wordlist) {
        if(beginword==endword) return 0;
        unordered_set<string> dict(wordlist.begin(),wordlist.end());
        if(dict.find(endword)==dict.end()) return 0;
        
        int c=0;
        queue<string> q;
        q.push(beginword);
        
        while(!q.empty()){
            c++;
            int len=q.size();
            
            for(int i=0;i<len;i++){
                string word=q.front();
                q.pop();
                
                for(int j=0;j<beginword.size();j++){
                    char curr=word[j];
                    
                    for(char ch='a';ch<='z';ch++){
                        word[j]=ch;
                        
                        if(word==endword) return c+1;
                        if(dict.find(word)==dict.end()) continue;
                        
                        dict.erase(word);
                        q.push(word);
                    }
                    word[j]=curr;
                }
            }
        }
        
        return 0;
    }
};
