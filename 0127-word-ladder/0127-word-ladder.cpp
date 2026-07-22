class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string>st( wordList.begin() , wordList.end());
        queue<pair<string,int>>q;
        q.push({beginWord, 1});
        st.erase(beginWord);

        while(!q.empty())
        {
            auto it = q.front();
            string word = it.first;
            int steps= it.second;
            q.pop();
            if( word == endWord) return steps;
            for( int i=0; i<word.size();i++)
            {
                char original =word[i];
                for( char c='a'; c <='z'; c++)
                {
                    word[i]=c;
                    if( st.find(word) != st.end())
                    {
                        q.push({word, steps+1});
                        st.erase(word);
                    }
                }
                word[i]=original;
            }
        }
        return 0;
        

        
    }
};