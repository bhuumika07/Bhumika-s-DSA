class Solution {
public:
    vector<vector<int>> ans;
    void doit( vector<int>&candidates , int target , int index , int sum , vector<int>temp){
        if( sum > target) return;
        if( sum == target){
            ans.push_back(temp);
            return;
        }
        if(index >= candidates.size()) return;

        temp.push_back(candidates[index]);
        doit(candidates , target , index , sum + candidates[index] , temp);
        temp.pop_back();
        doit( candidates , target , index + 1 , sum , temp);
        // temp.pop_back();
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int>temp;
        sort(candidates.begin() , candidates.end());
        doit(candidates , target , 0 , 0 , temp);
        return ans;
    }
};