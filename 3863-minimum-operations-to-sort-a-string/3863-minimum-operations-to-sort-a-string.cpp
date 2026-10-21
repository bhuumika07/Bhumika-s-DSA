class Solution {
public:
    int minOperations(string s) {
        string sorted = s;
        int n = s.size();

        sort(sorted.begin(), sorted.end());

        if(s == sorted) return 0;
        if(n == 2) return -1;

        char mini = sorted[0];
        char maxi = sorted[n-1];

        if(mini == s[0] || maxi == s[n-1])
            return 1;

        if(s[0] == maxi && s[n-1] == mini &&
           count(s.begin(), s.end(), mini) == 1 &&
           count(s.begin(), s.end(), maxi) == 1)
            return 3;

        return 2;
    }
};