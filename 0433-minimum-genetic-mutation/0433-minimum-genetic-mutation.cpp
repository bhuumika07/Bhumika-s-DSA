class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        unordered_set<string>st(bank.begin(), bank.end());
        queue<pair<string,int>>q;
        q.push({startGene,0});
        char valid[4]={'A', 'C', 'G', 'T'};

        while(!q.empty())
        {
            auto it = q.front();
            string word = it.first;
            int steps= it.second;
            q.pop();
            if( word == endGene) return steps;
            for( int i=0; i<word.size();i++)
            {
                char org = word[i];
                for( int j=0; j<4;j++)
                {
                    word[i]=valid[j];
                    if( st.find(word) != st.end())
                    {
                        q.push({ word , steps+1});
                        st.erase(word);
                    }
                }
                word[i]=org;
            }
        }
        return -1;
        
    }
};