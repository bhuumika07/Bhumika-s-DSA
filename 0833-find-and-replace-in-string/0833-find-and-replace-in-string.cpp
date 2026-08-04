class Solution {
public:
    static bool cmp( pair<int,pair<string,string>>&a, pair<int,pair<string,string>>&b)
    {
        return a.first < b.first;
    }
    string findReplaceString(string s, vector<int>& indices, vector<string>& sources, vector<string>& targets) {
        string ans="";
        vector<pair<int,pair<string , string>>> collection;
        for( int i=0; i<indices.size();i++)
        {
            collection.push_back( { indices[i] , { sources[i] , targets[i]}});
        }
        sort( collection.begin() , collection.end() , cmp);
        int j=0;

        for( int i=0; i<s.size();i++)
        {
            bool okay=0;
            while( j < indices.size() && i == collection[j].first)
            {
                int size = collection[j].second.first.size();
                string match= s.substr( i , size);
                if( match == collection[j].second.first)
                {
                    ans+=collection[j].second.second;
                    i+=(size-1);
                    okay=1;
                    j++;
                    break;
                }
                j++;
            }
            if(!okay){ans+=s[i];okay=0;}
        }
        return ans;
        
    }
};