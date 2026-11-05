class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int count = 0;
        sort(arr2.begin() , arr2.end());
        for(int i =0; i<arr1.size(); i++)
        {
            int low = 0;
            int high = arr2.size()-1;
            bool check = 1;
            while( low <= high ){
                int mid = low + (high-low)/2;
                int diff = abs(arr2[mid] - arr1[i]);
                if( diff <= d){ check = 0; break;}
                if( arr2[mid] < arr1[i]){
                    low = mid + 1;
                }
                else {
                    high = mid - 1;
                }

            }
            if( check ) count++;
        }
        return count;
        
    }
};