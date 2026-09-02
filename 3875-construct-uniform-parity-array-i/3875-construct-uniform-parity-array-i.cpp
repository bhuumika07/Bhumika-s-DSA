class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int counteven=0;
        int countodd=0;
        int n=nums1.size();
        for(int i=0; i<n; i++)
        {
            if(nums1[i] % 2 == 0) counteven++;
            else countodd++;
        }
        if( counteven == n || countodd == n) return true;
        countodd=0;
        for( int i=0; i<n; i++)
        {
            if( nums1[i] % 2 != 0) countodd++;
            else
            {
                for( int j=0; j<n; j++)
                {
                    if( i != j && (nums1[i]- nums1[j]) %2 != 0 )
                    {
                        countodd++;
                        break;
                    }
            
                }

            }
            
        }
        if( countodd == n) return true;
        else  return false;
        
    }
};