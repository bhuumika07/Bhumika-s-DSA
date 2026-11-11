class Solution {
public:
    long long countValidSubstrings(string s) {
        int lasta = -1;
        int lastb =-1;
        unordered_map<int,int>mpp;
        for(int i = 0; i<s.size();i++){
            if(s[i] =='a' ) lasta = i;
            if(s[i] == 'b') {mpp[i] = lasta; lastb=i;}
            if(s[i] == 'c') {mpp[i] = lastb;}
        }
        long long count = 0;
        int left = 0;
        int right=0;
        while( right < s.size()){
            if(s[right] == 'c')
            {
                if(mpp[right] != -1){
                    int a = mpp[mpp[right]];
                    if(a!=-1) left = a + 1;
                }
            }

            count += (right-left+1);
            right++;
        }
        return count;
    }
};