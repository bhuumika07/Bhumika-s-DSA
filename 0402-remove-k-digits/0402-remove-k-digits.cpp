class Solution {
public:
    string removeKdigits(string num, int k) {
      stack<int>st;
      for( int i = 0; i< num.size(); i++)
      {
         while(k && !st.empty() && st.top() > num[i])  {k--; st.pop();} 
         if( st.empty() && num[i]=='0') continue;
         else st.push(num[i]);
      }
      while( k-- > 0 && !st.empty()) st.pop(); 
      if( st.empty()) return "0";
      string ans="";
      while(!st.empty())
      {
        ans+=st.top();
        st.pop();
      }
      reverse( ans.begin() , ans.end());
      return ans;
        
    }
};