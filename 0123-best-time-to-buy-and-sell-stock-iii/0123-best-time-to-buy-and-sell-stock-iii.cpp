//3D Dp can be coverted into 2D Dp , by combining the 2 states -->
// 0 -> first buy
// 1-> first sell
// 2 -> second buy
// 3 -> second sell
class Solution {
public:
    int maxProfit(vector<int>& prices) {
     // tabulation approach
     // start from the base case.
     int n = prices.size();
     vector<vector<int>>dp(n+1, vector<int>(5 , 0));
     dp[n][4] = 0;
     for( int index = n-1; index>= 0;index--){
        int profit = 0;
        for( int opr = 3; opr >= 0 ; opr--){
            if( opr%2 == 0 ){
            profit = max( -1 * prices[index] + dp[index+1][opr+1] , dp[index+1][opr]);
        }
        else{
            // need to sell.
            profit = max( prices[index] + dp[index+1][opr+1] , dp[index+1][opr]);
        }
        dp[index][opr] = profit;
        } 
     }
     return dp[0][0];
    }
};