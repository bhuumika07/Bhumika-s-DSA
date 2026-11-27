class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int smaller = prices[0];
        int ans = 0;
        for( int i = 0; i<prices.size(); i++){
            if(prices[i] > smaller) ans = max( ans , prices[i] - smaller);
            smaller = min(smaller , prices[i]);
        }
        return ans;
    }
};