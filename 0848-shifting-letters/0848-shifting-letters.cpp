class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        int size = s.size();
        vector<long long>diff(size+1, 0);
        for(int i=0;i<shifts.size();i++)
        {
            diff[0]+=shifts[i];
            diff[i+1]-=shifts[i];
        }
        long long last=0;

        for( int i=0; i<size;i++)
        {
            last+=diff[i];
            int shift = last%26;
            s[i] ='a'+(s[i]-'a'+shift) % 26;
        }
        return s;
        


        
    }
};