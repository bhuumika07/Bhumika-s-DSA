class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int,int>freq;
        for( auto x : answers) freq[x]++;
        int count=0;
        for( auto it : freq)
        {
            int x = it.first;
            int y = it.second;
            // if( x == 0) count+=y;
            // else if( y <= x) count+= x+1;
            // else
            // {
               if( y%(x+1) == 0) count+=y;
               else
               {
                int rem = y%(x+1);
                count+= y + (x+1-rem);
               }
            // }
            
        }
        return count;
        
    }
};