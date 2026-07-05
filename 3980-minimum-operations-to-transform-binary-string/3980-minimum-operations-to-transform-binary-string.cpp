class Solution {
public:
    int minOperations(string s1, string s2) {
        int count=0;
        for( int i=0; i<s1.size();i++)
            {
                if(s1[i] != s2[i])
                {
                    if(s1[i]=='0')
                    {
                        s1[i]='1';
                        count++;
                    }
                    else
                    {
             if( i+1 < s1.size() && s1[i+1]!=s2[i+1])
                        {
                            if(s1[i+1] == '1')
                            {
                                s1[i]='0';
                                s1[i+1]='0';
                                count++; 
                            }
                            else
                            {
                                s1[i]='0';
                                count+=2;
                            }
                            
                        }
                else if( i > 0 && s1[i-1]!=s2[i-1])
                        {
                            if(s1[i-1]=='1')
                            {
                            s1[i]='0';
                            s1[i-1]='0';
                            count++;                            
                            }
                            else
                            {
                                s1[i]='0';
                                count+=2;
                            }

                        }
                 else if( i+1 <s1.size() && s1[i+1]==s2[i+1] )
                        {
                            if(s1[i+1]=='1')
                            {
                                s1[i]='0';
                                count+=2;
                            }
                            else
                            {
                                s1[i]='0';
                                count+=2;
                            }
                            
                        }
               else if( i>0 && s1[i-1]==s2[i-1])
                        {
                            if(s1[i-1]=='1')
                            {
                                s1[i]='0';
                                count+=2;
                            }
                            else
                            {
                                s1[i]='0';
                                count+=2;
                            }
                        }
                else
               {
                   return -1;
               }
                    }
                }
            }
        return count;
        
    }
};