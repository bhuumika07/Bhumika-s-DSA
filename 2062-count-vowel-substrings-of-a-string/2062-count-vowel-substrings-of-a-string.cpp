class Solution {
public:
    int countVowelSubstrings(string word) {
        unordered_set<char>vowels; 
        vowels.insert('a'); vowels.insert('e'); vowels.insert('i'); vowels.insert('o');vowels.insert('u');
       
        int size=word.size();
        unordered_map<char,int>checkit;
        int left=0;
        int right=0;
        int count=0;
        vector<int>index;

        for( int i=0; i<size;i++)
        {
            if( vowels.find(word[i]) == vowels.end())
            {
                index.push_back(i);
            }
        }
        int j=0;
        while( right < word.size())
        {
            if(vowels.find(word[right]) != vowels.end() ) checkit[word[right]]++;
            else {left=right+1;
            checkit.clear();}
            while( checkit.size() == vowels.size())
            {
                int last=0;
                while(j<index.size() && index[j] < right) j++;
               if (j >= index.size()) last = size;
               else last = index[j];
                count+=((last-right));
                if(checkit.find(word[left]) != checkit.end()) checkit[word[left]]--;
                if( checkit[word[left]] == 0) checkit.erase(word[left]);
                left++;
            }
            right++;
        }
        return count;
        
        
    }
};