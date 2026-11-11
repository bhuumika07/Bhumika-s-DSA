class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        // cost for getting 2 is -> cost1 + cost2 or costBoth
        // thats what i need to decide which is chotta.
        long long ans = 0;
        if(cost1 + cost2 >= costBoth){
            ans = 1LL*costBoth*(min(need1,need2));
            if( need1 > need2){
                ans+=( 1LL*(need1-need2)*min(cost1,costBoth));
            }
            else if(need1 < need2){
                ans+=( 1LL*(need2- need1)*min(cost2,costBoth));
            }
            return ans;
        }
        return 1LL*cost1*need1 + 1LL*cost2*need2;
    }
};