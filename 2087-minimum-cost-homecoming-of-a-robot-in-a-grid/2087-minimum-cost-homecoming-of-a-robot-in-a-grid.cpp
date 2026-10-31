class Solution {
public:
    int minCost(vector<int>& startPos, vector<int>& homePos, vector<int>& rowCosts, vector<int>& colCosts) {
        int cost = 0;
        // if the starting points differ.
        int startR = startPos[0];
        int homeR = homePos[0];
        if( startR < homeR)
            for( int i = startR +1 ; i<=homeR; i++) cost +=rowCosts[i];
        else if( startR > homeR)
            for(int i = homeR; i<startR; i++) cost+=rowCosts[i];
        
        int startC = startPos[1];
        int homeC = homePos[1];
        if(startC < homeC)
            for( int i = startC+1; i<=homeC;i++) cost += colCosts[i];
        else if(startC > homeC)
            for( int i = homeC; i<startC; i++) cost+=colCosts[i];

        return cost;
    }
};