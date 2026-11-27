class Solution {
public:
    int dp[30004][2];
    int doit( vector<int>&prices , bool buy , int index){
        if( index >= prices.size() ) return 0;
        if(dp[index][buy] != -1) return dp[index][buy];
        int option1 = 0;
        int option2 =0;
        if( buy ){
            // either i will buy or i will not
            option1 = max( -1*prices[index] + doit(prices , 0 , index+1) , doit(prices , 1 , index+1));
        }
        else{
            // either i will sell or i will not
            option2 = max( prices[index] + doit(prices , 1, index+1) , doit(prices , 0 , index+1));
        }

        return dp[index][buy] = max(option1 , option2);
    }
    int maxProfit(vector<int>& prices) {
        memset(dp,-1,sizeof(dp));
        return doit(prices , 1 , 0);
    }
};