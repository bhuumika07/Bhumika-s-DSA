class Solution {
public:
    long long countValidSubstrings(string s) {
        int lastb =-1;int lasta=-1;
        unordered_map<int,int>mpp;
        long long count = 0;
        int left = 0;
        int right=0;
        while( right < s.size()){
            if(s[right] =='a' ) {lasta = right;}
            if(s[right] == 'b') {mpp[right] = lasta; lastb= right;}
        
            if(s[right] == 'c')
            {
                if( lastb != -1){
                    int a = mpp[lastb];
                    if(a!=-1) left = a + 1;
                }
            }

            count += (right-left+1);
            right++;
        }
        return count;
    }
};