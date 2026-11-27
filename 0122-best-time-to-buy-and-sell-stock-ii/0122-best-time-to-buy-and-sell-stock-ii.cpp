class Solution {
public:
    int maxProfit(vector<int>& prices) {
       // tabulation --> bottom up approach 
       // start from the base case 
       // copy the recurrence.

       int n = prices.size();
    //    vector<vector<int>>dp( n+1 , vector<int>(2,0));
       int sell= 0;
       int khareedlo =0;
        // int ans = 0;
       for( int index = n-1; index>=0; index--){
        int profit = 0;
        for( int buy = 0; buy <= 1; buy++){
            if(buy){
                profit = max(-1*prices[index] + sell , khareedlo );
            }
            else{
                profit = max(prices[index] +khareedlo , sell);
            }
           if(buy) khareedlo = profit;
           else sell = profit;
        //    ans = profit;
        }
       }
       return khareedlo;
     }
};