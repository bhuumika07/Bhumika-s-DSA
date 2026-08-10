class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int>diff(n+1,0);
        for(int i=0; i<bookings.size();i++)
        {
            int first =bookings[i][0]-1;
            int second = bookings[i][1];
            int seats = bookings[i][2];
            diff[first]+=seats;
            diff[second]-=seats;
        }
        vector<int>ans;
        ans.push_back( diff[0]);
        for( int i=1; i<n;i++)
        {
            ans.push_back( ans[i-1] + diff[i]);
        }
        return ans;
    }
};