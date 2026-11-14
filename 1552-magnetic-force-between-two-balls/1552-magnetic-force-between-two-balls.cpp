class Solution {
public:
    // see if at this min difference -. can we place the balls
    int checkit( vector<int>&position , int mini){
        int count = 1;
        int prev = 0;
        for( int i = 1; i<position.size(); i++){
            if(abs(position[prev] - position[i]) >= mini){
                count++;
                prev=i;
            }
        }
        return count;
    }
    int maxDistance(vector<int>& position, int m) {
        int size = position.size();
        vector<int>temp = position;
        sort(temp.begin() , temp.end());
        long long mini = temp[0];
        long long maxi = temp[size-1];
        long long low = 1;
        long long high = maxi - temp[0];

        int ans = -1;
        while( low <= high){
            long long mid =  low + ( high - low)/2;
            int placed = checkit(temp , mid);
            if( placed >= m){
                low = mid+1;
                ans=mid;
            }
            else {high = mid-1;}
        }
        return ans;
        
        
    }
};