class Solution {
public:
    bool checkString(string s) {

        int b = 0;
        for( int i = 0;  i< s.size(); i++)
        {
            if(s[i]=='a' && b>0) return 0; 
            if(s[i]=='b') b++;
        }
        return 1;
        
    }
};