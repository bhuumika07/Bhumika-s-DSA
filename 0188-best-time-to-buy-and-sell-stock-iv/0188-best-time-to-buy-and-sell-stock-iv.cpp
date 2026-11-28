class Solution {
public:
    int dp[1001][201];
    int doit(vector<int>&prices , int buysLeft ,  int index){
        if(index >= prices.size() || buysLeft == 0) return 0;
        if(dp[index][buysLeft] != -1) return dp[index][buysLeft];
        int profit = 0;
        if(buysLeft % 2 == 0){
            profit = max(-1*prices[index] + doit(prices, buysLeft-1, index+1) , doit(prices , buysLeft , index+1));
        }
        else{
            profit = max(prices[index] + doit(prices ,buysLeft - 1 , index+1) , doit(prices , buysLeft , index+1));
        }
        return dp[index][buysLeft] = profit;
    }
    int maxProfit(int k, vector<int>& prices) {
        memset(dp,-1,sizeof(dp));
       return doit(prices , k*2 , 0); 
    }
};