class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        int evenNum=2;
        int oddNum=1;
        int even=0;
        int odd=0;
       
        while(n--)
        {
            even+=evenNum;
            odd+=oddNum;
            evenNum+=2;
            oddNum+=2;
        }
        
        return gcd(odd,even);
        
    }
};