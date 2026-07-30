class Solution {
public:
  
    int minimumPushes(string word) {
        unordered_map<char,int>store;
        string str="";
        for( int i=0; i<word.size();i++)
        {
            if(store.find( word[i]) == store.end()) str+=word[i];
            store[word[i]]++;
        }
        vector<int>vec;
        for( auto it : store )
        {
            vec.push_back(it.second);
        }
        sort( vec.begin(), vec.end(), greater<int>());
        int count=0;
        int n=1;
        int c=0;
        for( auto it : vec)
        {
            count += it*n;
            c++;
            if( c==8)
            {
                c=0;
                n++;
            }
        }
        return count;
        
    }
};