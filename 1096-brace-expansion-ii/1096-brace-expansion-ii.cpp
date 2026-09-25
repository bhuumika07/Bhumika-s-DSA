class Solution {
public:

    set<string> parse(string &expression, int &i) {

        set<string> result;
        set<string> current = {""};

        while (i < expression.size() && expression[i] != '}') {

            if (expression[i] == ',') {
                for (auto &s : current)
                    result.insert(s);

                current = {""};
                i++;
            }

            else if (expression[i] == '{') {
                i++;

                set<string> inside = parse(expression, i);

                set<string> temp;

                for (auto &a : current) {
                    for (auto &b : inside) {
                        temp.insert(a + b);
                    }
                }

                current = temp;
                i++;
            }

            else {
                string ch(1, expression[i]);

                set<string> temp;

                for (auto &s : current)
                    temp.insert(s + ch);

                current = temp;

                i++;
            }
        }

        for (auto &s : current)
            result.insert(s);

        return result;
    }

    vector<string> braceExpansionII(string expression) {

        int i = 0;

        set<string> ans = parse(expression, i);

        return vector<string>(ans.begin(), ans.end());
    }
};