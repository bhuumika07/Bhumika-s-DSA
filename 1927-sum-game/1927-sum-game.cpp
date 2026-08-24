class Solution {
public:
    bool sumGame(string s) {
        long long first = 0;
        long long second = 0;
        int size =s.size();
        int front=0; int back=0;
        for( int i=0; i<size; i++)
        {
            if(s[i] == '?') {
                if( i < size/2) front++;
                else back++;
                continue;
            }
            if( i <size/2 ) first+=(s[i]-'0');
            else second+=(s[i]-'0'); 
        }
        
        int count=0;
        while( front+back > 0)
        {
            if( count % 2 == 0)
            {
                // alice will try to increase the differnce as much as she can .
                if( first > second )
                {
                    if( front > 0)
                    {
                        first+=9;
                        front--;
                    }
                    else{
                        int diff = first - second;
                        if( diff < 9) second+=9;
                        back--; 
                    }
                }
                else
                {
                    if( back > 0)
                    {
                        second+=9;
                        back--;
                    }
                    else
                    {
                        int diff = second - first;
                        if( diff <9) first+=9;
                        front--;
                    }
                }
            }
            else
            {
                if( first > second )
                {
                    int diff = first - second ;
                    if( back > 0)
                    {
                        // if( front > 0 ) second+=9;
                        if( diff <= 9) second+=diff;
                        else if( diff > 9) second+=9;
                        back--;
                    }
                    else
                    {
                        front--;
                    }
                }
                else
                {
                  int diff = second - first;
                  if( front > 0)
                  {
                    // if( back > 0) first+=9;
                    if( diff <= 9) first+=diff;
                    else if( diff > 9) first+=9;
                    front--;
                  }  
                  else back--; 
                }
            }
            count++;
        }
        if( first != second) return 1;
        return 0;
    }
};