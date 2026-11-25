class Solution {
public:
    string multiply(string num1, string num2) {

        int m = num1.size();
        int n = num2.size();

        if(num1 == "0" || num2 == "0") return "0";

        vector<int> ans(m+n, 0);

        for(int i = m-1; i >= 0; i--)
        {
            for(int j = n-1; j >= 0; j--)
            {
                int mul = (num1[i]-'0') * (num2[j]-'0');

                int pos = i+j+1;

                int sum = mul + ans[pos];

                ans[pos] = sum % 10;

                ans[pos-1] += sum / 10;
            }
        }

        string res = "";

        for(int x : ans)
        {
            if(res.empty() && x == 0) continue;

            res += to_string(x);
        }

        return res;
    }
};