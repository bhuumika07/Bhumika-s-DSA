class Solution {
public:
    static inline vector<long long> odd;
    static inline vector<long long> even;
    static inline bool initialized= 0;
    void operations( )
    {
        if( initialized ) return ;
         for( int i = 1 ; i<=100000; i++)
        {
            int n = i;
            string s= to_string(n);
            string r=s;
            string evenlen , oddlen;
        
            if( i >=0 && i <= 9)
            {
                if( i %2==0) even.push_back( i );
                else odd.push_back(i);
                oddlen = s;
                evenlen = s+s;
            }
            else
            {
                reverse( r.begin() , r.end());
                string nmu = s;
                nmu.pop_back();
                evenlen = s + r;
                oddlen = nmu + r;
            }
            long long e = stoll(evenlen);
            long long o = stoll(oddlen);
            if( e %2 == 0) even.push_back(e);
            else odd.push_back(e);

            if( o%2 ==0) even.push_back(o);
            else odd.push_back(o);

        }

        sort( even.begin() , even.end());
        sort( odd.begin() , odd.end());

        initialized=1;
    }
        long long minOperations(vector<int>& nums) {
        operations();
        long long ans = 0;
        for( int i=0; i<nums.size(); i++)
        {
            long long num;
            if( nums[i]%2==0)
            {
                auto it = lower_bound( even.begin() , even.end() , nums[i]);
                if( it == even.end() )
                {
                    int last = even.size();
                    ans += (nums[i] - even[last-1])/2;
                    continue;
                }
                long long num = it - even.begin();
                if( even[num] - nums[i] != 0 )
                {
                    long long curr = even[num] - nums[i];
                    if( num > 0 && nums[i]-even[num-1] < curr) ans += (nums[i] - even[num-1])/2;
                    else ans+=(curr)/2;
                }
            }
            else
            {
                auto it = lower_bound( odd.begin() , odd.end() , nums[i]);
                if( it == odd.end())
                {
                    int last = odd.size();
                    ans += (nums[i] - odd[last-1])/2;
                    continue;
                }
                long long  num = it - odd.begin();
                if( odd[num] - nums[i] != 0)
                {
                    long long curr = odd[num] -nums[i];
                    if( num > 0 && nums[i] - odd[num-1] < curr) ans+=(nums[i] - odd[num-1])/2;
                    else ans+=(curr)/2;
                }
            }
        }
        return ans;
        
    }
};