//3D Dp can be coverted into 2D Dp , by combining the 2 states -->
// 0 -> first buy
// 1-> first sell
// 2 -> second buy
// 3 -> second sell
class Solution {
public:
    int dp[100001][4];
    int doit( vector<int>&prices , int index ,int opr){
        if(opr > 3) return 0;
        if( index >= prices.size()) return 0;
        if(dp[index][opr] != -1) return dp[index][opr];
        int profit = 0;
        if( opr%2 == 0 ){
            profit = max( -1 * prices[index] + doit(prices , index+1 , opr+1) , doit(prices , index+1,  opr));
        }
        else{
            // need to sell.
            profit = max( prices[index] + doit(prices , index+1, opr+1) , doit(prices , index+1, opr));
        }
        return dp[index][opr] = profit;

    }
    int maxProfit(vector<int>& prices) {
        // func( arr , index , count , buy);
        memset(dp,-1,sizeof(dp));
        return doit(prices , 0 , 0);
    }
};