class Solution {
public:
    bool uniformArray(vector<int>& nums1)
     {
         int counteven=0;int countodd=0;int n=nums1.size();
        for(int i=0; i<n; i++){if(nums1[i] % 2 == 0) counteven++;else countodd++;}
        if( counteven == n || countodd == n) return true;
        countodd=0;  int odd=INT_MAX;
        for( int i=0; i<n; i++){ if(nums1[i] %2 !=0)odd= min(nums1[i],odd);}
        for( int i=0; i<n; i++)
        {if( nums1[i] % 2 != 0)countodd++;
        else  if( (nums1[i]- odd) %2 != 0 && (nums1[i] - odd) >= 1) countodd++;}
        if( countodd == n) return true;  else  return false; 
    }
};