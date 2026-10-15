class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
      long long s = 0;
      if( num == 1 && sum >= 10) return "";
      if( num ==  1) return to_string(sum);
      string ans = "";
      int count = 0;
      while( count < num)
      {
        count++;
        int diff = sum - s;
            if( diff < 9)
            {
                ans += ( diff + '0');
                s+= diff;
            } 
            else
            {
                ans += '9';
                s+=9;
            }
      }
      if( s != sum) return "";
      return ans;
    }
};