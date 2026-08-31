class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int mini =*min_element(nums.begin() , nums.end());
        int maxi =*max_element( nums.begin() , nums.end());

        int index1;
        int index2;
        int size =nums.size();
        for( int i=0; i<size;i++)
        {
            if(nums[i] == mini) index1=i+1;
            if(nums[i]==maxi) index2=i+1;
        }
        // i need to cgeck whether they will be removed from the same sides
        int total1=max(index1,index2);
        int total2=max(size-index1+1, size-index2+1);
        
        int total=0;
        if( index1 <= size-index1 ) {total+=index1;}
        else {total+=(size-index1+1);}
        cout<<total<<endl;
        if( index2 <= size-index2) {total+=index2;}
        else {total+=(size-index2+1);}
        cout<<total;
       return min(total , min(total1,total2));

        

        
    }
};