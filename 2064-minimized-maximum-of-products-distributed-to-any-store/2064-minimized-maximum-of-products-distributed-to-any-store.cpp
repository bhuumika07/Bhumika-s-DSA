class Solution {
public:
    int check( vector<int>&quantities , long long maxi){
        int count = 0;

        for( int i=0; i<quantities.size(); i++){
            if( quantities[i] > maxi){
                count+=( quantities[i] /maxi);
                if(quantities[i]%maxi !=0) count++;
            }
            else count++;
        }
        // if(prev!=0) count++;
        return count;
    }
    int minimizedMaximum(int n, vector<int>& quantities) {
        long long low = 1;
        long long high = 0; int ans = -1;
        for( int x :quantities) high += x;
        while( low <= high){
            long long mid = low + ( high - low)/2;
            int log  = check(quantities , mid);
            if( log > n) low = mid+1;
            else{
                ans = mid;
                high =mid-1;
            }
        }
        return ans;
    }
};