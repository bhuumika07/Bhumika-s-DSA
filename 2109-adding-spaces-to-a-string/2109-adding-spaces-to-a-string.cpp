class Solution {
public:
    string addSpaces(string s, vector<int>& spaces)
    {
        string str="";
        int j=0;
        for( int i=0; i<s.size();i++)
        {
            if(j<spaces.size() && i== spaces[j])
            {
                str+=" ";
                j++;
            }
            str+=s[i];
          
        }
        return str;
    }
};