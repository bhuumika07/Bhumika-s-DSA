class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five =0;
        int ten=0;
        // sort( bills.begin(), bills.end());
        for( int i=0; i< bills.size(); i++)
        {
            if( bills[i]==5) five++;
            else 
            {
                if( bills[i]==10) {
                    if(five >= 1) 
                    {
                        five--;
                        ten++;
                    } else return 0;
                }
                
                else if( bills[i]==20 )
                {
                  
                    if (five>=1 && ten >=1)
                    {
                        five--;
                        ten--;
                    }
                    else if( (five >=3) )
                    {
                        five-=3;
                    }
                    else return 0;
                }
                
            }
        }
        return 1;
        
    }
};