class Solution {
public:
    bool isValid(string &temp)
    {
        int count=0;
        for(int i=0; i<temp.size();i++)
        {
            if(temp[i] == '(') count++;
            else count--;
            if( count < 0) return 0;
        }
        return count==0;
    }
    void solve( int n , vector<string> &ans , string temp)
    {
        if( temp.size() == 2*n)
        {
            if( isValid( temp )) ans.push_back( temp );
            // temp.pop_back();
            return;
        }

        temp.push_back( '(');
        solve( n , ans , temp);
        temp.pop_back();
        temp.push_back(')');
        solve( n ,ans , temp);
    }
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        solve( n , ans , "");
        return ans;
    }
};