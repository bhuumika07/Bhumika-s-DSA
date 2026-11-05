class Solution {
public:
    int maxProfit(vector<int>& prices) {
       int maxi = 0;
       int bought = prices[0];
       for(int i=1; i < prices.size();i++){
        maxi = max( maxi , prices[i] -bought);
        if(prices[i] < bought) bought = prices[i];
       }
       return maxi;
    }
};