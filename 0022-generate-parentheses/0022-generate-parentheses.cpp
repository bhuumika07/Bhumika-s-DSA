class Solution {
public:
    void solve( int n , vector<string> &ans , string &temp , int open , int close)
    {
        if( temp.size() == 2*n)
        {
            ans.push_back( temp );
            return;
        }

        if(open < n ){
            temp.push_back( '(');
            solve( n , ans , temp , open+1 , close);
            temp.pop_back();
            }
        if( close < open)
        {
             temp.push_back(')');
             solve( n ,ans , temp, open , close+1);
             temp.pop_back();
        }
       
    }
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        string temp="";
        solve( n , ans , temp , 0 , 0);
        return ans;
    }
};