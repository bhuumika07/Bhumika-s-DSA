class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& seats) {
        int count=0;
        unordered_map< int , vector<int> > mpp;
        for(int i=0; i<seats.size(); i++)
        {
            mpp[ seats[i][0] ].push_back( seats[i][1]);
        }
        int ans=0;
        int s=mpp.size();
        n=n-s;
        ans=n*2;
        for( auto it : mpp)
        {
            int first=1;
            int second=1;
            int third=1;
            for( int x : it.second)
            {
                if( x == 2 || x==3 || x==4 || x==5) first=0;
                if( x==4 || x==5 || x ==6 || x == 7) second=0;
                if(x==6 || x==7 || x==8 || x==9) third=0;
            }
            if( first && third ) count+=2;
            else if( first||second || third) count+=1;
        }

        // long long total = 1LL*n*2;
        return ans + count;
        
    }
};