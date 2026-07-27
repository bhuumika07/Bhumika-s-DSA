class Solution {
public:
    vector<vector<int>> aggregateTimeSeries(vector<vector<int>>& series1, vector<vector<int>>& series2) {

        vector<vector<int>>ans;
        int left=0;
        int right=0;
        int lmover=0;
        int emover=0;
        while( left < series1.size() && right < series2.size())
            {
                // int tleft=
              if( series1[left][0] == series2[right][0]) 
              {
                  int sum = series1[left][1] + series2[right][1];
                  ans.push_back( {series1[left][0] , sum});
                  left++;
                  right++;
                
              }
                else if( series1[left][0] < series2[right][0] )
                {
                    ans.push_back({series1[left][0],
                    series1[left][1] + series2[right][1]});
                
                    left++;
                }
                else 
                {
                    ans.push_back({series2[right][0],
                    series1[left][1] + series2[right][1]});
                    right++;
                    
                }
            }

        while( left < series1.size())
        {
            ans.push_back( { series1[left][0] , series1[left][1]});
            left++;
        }
        while( right < series2.size())
        {
            ans.push_back( { series2[right][0] , series2[right][1]});
            right++;
        }

        return ans;
    }
};