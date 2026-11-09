class Solution {
public:
    bool canRemoveAll(vector<int>& types, vector<int>& colors, vector<int>& groupSize) {
        stack< pair<int, pair<int,int>> > st;
        st.push({types[0] , { 1, colors[0]}});
        for( int i = 1; i<types.size(); i++){
            if(!st.empty() && st.top().first == types[i] && st.top().second.second == colors[i]){
                if((st.top().second.first + 1 )% groupSize[types[i]] == 0)st.pop();
                else {
                   st.top().second.first++;
                }
            }
            else {
                if(groupSize[types[i]] == 1) continue;
                else st.push({types[i] , {1 , colors[i]}});}
        }
        
        if(!st.empty()&& (st.top().second.first % groupSize[st.top().first]) == 0) st.pop();
        if(st.empty()) return 1;
        return st.empty();
    }
};