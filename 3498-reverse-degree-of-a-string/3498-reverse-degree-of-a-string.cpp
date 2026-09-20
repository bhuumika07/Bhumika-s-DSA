class Solution {
public:
    int reverseDegree(string s) {
        int prod=0;
        for(int i=0; i<s.size(); i++)
        {
            int t= s[i]- 'a';
            int p= 26 - t;
            prod += ( p *(i+1));
        }
        return prod;
        
    }
};