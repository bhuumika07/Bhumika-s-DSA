class Solution {
public:
    double minPrice(vector<int>& prices, vector<int>& discounts) {
        sort( prices.begin(),prices.end(), greater<int>());
        sort( discounts.begin(), discounts.end(), greater<int>());
        int left=0;
        int right=0;
        double sum=0;
        while( left < prices.size() && right < discounts.size())
        {
            double dis = (prices[left]*(100-discounts[right]))/100.00;
            sum+=dis;
            left++;
            right++;
        }
        while( left < prices.size())
        {
            sum+=prices[left];
            left++;
        }
        return sum;
        
    }
};