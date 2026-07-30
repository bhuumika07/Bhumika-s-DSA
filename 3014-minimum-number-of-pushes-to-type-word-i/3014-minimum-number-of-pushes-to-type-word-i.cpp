class Solution {
public:
    int minimumPushes(string word) {
        int n=1;
        int count=0;
        int ans=0;
        for( int i=0; i<word.size();i++)
        {
            ans+=n;
            count++;
            if( count >= 8){ n++; count=0;}
        }
        return ans;

        
    }
};