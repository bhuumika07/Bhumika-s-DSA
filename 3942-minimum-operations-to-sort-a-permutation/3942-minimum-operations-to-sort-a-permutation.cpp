class Solution {
public:
    int minOperations(vector<int>& nums) {
       int n = nums.size();
       if( n == 2 ){
        if( nums[0] == 0 && nums[1] == 1) return 0;
        return 1;
       }
       int direction = (nums[0] == 0) ? 1 : -1;
       bool flag = 0;
       for( int i=0; i<n;i++)
       {
        if( direction == 1 && nums[i] != i || (( direction == -1 && nums[i] != n-1-i) )){ 
            flag = 1; break;}
       }
       int ans = -1;
       if( !flag ) ans = direction == 1 ? 0 : 1;
       if( ans != -1) return ans;


       int diff = n-1;
       for( int i = 0; i< n-1; i++)
       {
        int prev ;
        if( i == 0) prev = abs( nums[n-1] - nums[0]);
        else prev = abs(nums[i] - nums[i-1]);
        int next = abs( nums[i] - nums[i+1]);
        if( prev != 1 && prev != diff ) return -1;
        if( next != 1 && next != diff) return -1;
       }

        if( nums[n-1] == 0)
        {
            if( nums[n-2] == 1) return 1;
            else
            {
                if(n-1 < 3) return n-1;
                else return 3;
            }
        }
       // i will find the occurence of 0.
       int index = -1;
       for( int i=0; i<n; i++)
       {
        if( nums[i] == 0) { index = i; break;}
       }
       
       if( index > 0 )
       {
        if( nums[index-1] == 1 ) {
            return min(index+2 , n-index);
        }
        else {
            if( index == 1) return 1;
            else return min( index , n-index+2);
        }
       }
       else
       {
         return 2;
       }
       return 2;

    }
};