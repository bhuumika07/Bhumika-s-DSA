class Solution {
public:
    vector<int> toggleLightBulbs(vector<int>& bulbs) {
       vector<bool>switched(101 ,0); 
       for( int i = 0; i<bulbs.size(); i++){
            switched[bulbs[i]] = !switched[bulbs[i]];
       }
       vector<int>ans;
       for( int i = 1; i<=100; i++){
        if(switched[i]) ans.push_back(i);
       }
       return ans;
    }
};