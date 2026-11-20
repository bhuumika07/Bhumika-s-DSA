class Solution {
public:
    int maximumSwap(int num) {
        string s = to_string(num);
       for( int i = 0; i<s.size();i++){
        int index = i;
        for( int j = i; j<s.size(); j++){
            if(s[index] - '0' <= s[j] - '0') index = j;
        }
        if( index != i && s[index] != s[i]){
            swap(s[index] , s[i]);
            break;
        }
       }

       return stoi(s);

    }
};