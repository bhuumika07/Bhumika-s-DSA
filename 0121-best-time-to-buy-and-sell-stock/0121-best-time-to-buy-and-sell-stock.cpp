class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int>minis(n,0);
        vector<int>maxis(n,0);
        minis[0] = prices[0];
        for(int i=1;i<n;i++){
            minis[i] = min(minis[i-1] , prices[i]);
        }  
        maxis[n-1] = prices[n-1];
        for(int i=n-2;i>=0;i--){
            maxis[i] = max( maxis[i+1] , prices[i]);
        }
        int maxi = 0;
        for(int i=0; i<n-1;i++){
            maxi = max( maxi , maxis[i+1] - minis[i]);
        }
        return maxi;
    }
};