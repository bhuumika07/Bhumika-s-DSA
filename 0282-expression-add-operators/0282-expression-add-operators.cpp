class Solution {
public:
    vector<string> ans;

    void solve(string &num, int target, int idx,
               long long value,
               long long last,
               string expr) {

        if (idx == num.size()) {
            if (value == target)
                ans.push_back(expr);
            return;
        }

        long long cur = 0;

        for (int i = idx; i < num.size(); i++) {

            // Skip numbers with leading zero
            if (i > idx && num[idx] == '0')
                break;

            cur = cur * 10 + (num[i] - '0');
            string part = num.substr(idx, i - idx + 1);

            if (idx == 0) {
                solve(num, target, i + 1, cur, cur, part);
            }
            else {

                solve(num, target, i + 1,
                      value + cur,
                      cur,
                      expr + "+" + part);

                solve(num, target, i + 1,
                      value - cur,
                      -cur,
                      expr + "-" + part);

                solve(num, target, i + 1,
                      value - last + last * cur,
                      last * cur,
                      expr + "*" + part);
            }
        }
    }

    vector<string> addOperators(string num, int target) {
        solve(num, target, 0, 0, 0, "");
        return ans;
    }
};