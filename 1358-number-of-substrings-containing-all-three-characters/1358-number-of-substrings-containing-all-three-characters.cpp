class Solution {
public:
    int numberOfSubstrings(string s) {
        int a=0;
        int b=0;
        int c=0;
        int ans=0;
        int size=s.size();
        int left=0; int right=0;
        while(right < size)
        {
            if(s[right]=='a') a++;
            else if(s[right]=='b') b++;
            else c++;
            while( a>=1 && b>=1 && c>=1)
            {
                ans += (size-right);
                if(s[left]=='a')a--;
                else if(s[left]=='b') b--;
                else c--;
                left++;
            }
            right++;
        }
        return ans;
        
    }
};