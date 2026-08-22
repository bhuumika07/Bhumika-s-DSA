class Solution {
public:
    bool checkDivisibility(int n) {
        int sum=0;
        int pro=1;
        int dup=n;
        while(dup>0)
        {
            int t=dup%10;
            sum+=t;
            pro*=t;
            dup=dup/10;
        }
        if(n%(sum+pro) == 0)
        {
            return true;
        }
        return false;
        
    }
};