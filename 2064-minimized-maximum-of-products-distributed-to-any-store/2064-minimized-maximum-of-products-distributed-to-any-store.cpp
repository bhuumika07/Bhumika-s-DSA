class Solution {
public:
    int check( vector<int>&quantities , int maxi){
        int count = 0;
        for( int i=0; i<quantities.size(); i++){
            if( quantities[i] > maxi){
                count+=( quantities[i] /maxi);
                if(quantities[i]%maxi !=0) count++;
            }
            else count++;
        }
        return count;
    }
    int minimizedMaximum(int n, vector<int>& quantities) {
        int low = 1;
        int high = *max_element(quantities.begin() , quantities.end()); int ans = -1;
        while( low <= high){
            int mid = low + ( high - low)/2;
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