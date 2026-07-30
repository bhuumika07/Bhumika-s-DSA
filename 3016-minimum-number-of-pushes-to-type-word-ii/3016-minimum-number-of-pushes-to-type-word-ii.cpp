class Solution {
public:
   static bool cmp(const pair<char, int>& it1, const pair<char, int>& it2)
{
    return it1.second > it2.second;
}
    int minimumPushes(string word) {
        unordered_map<char,int>store;
        string str="";
        for( int i=0; i<word.size();i++)
        {
            if(store.find( word[i]) == store.end()) str+=word[i];
            store[word[i]]++;
        }
        vector<pair<char,int>>vec;
        for( auto it : store )
        {
            vec.push_back( { it.first , it.second});
        }
        sort( vec.begin(), vec.end(), cmp);
        int count=0;
        int n=1;
        int c=0;
        for( auto it : vec)
        {
            count += it.second*n;
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