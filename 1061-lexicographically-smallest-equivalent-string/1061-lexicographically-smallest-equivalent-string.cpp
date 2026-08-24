class Disjoint {
    public:
    vector<char>parent;
    Disjoint( int n)
    {
        parent.resize(n);
        for( int i='a'; i<='z';i++)
        {
            parent[i-'a']=i;
        }
    }
    int findParent( char letter )
    {
        if( letter == parent[letter - 'a']) return letter;
        return parent[ letter-'a'] = findParent( parent[letter-'a']);
    }

    void unionByorder( char a , char b)
    {
        char ulp_a = findParent( a );
        char ulp_b = findParent( b );
        if ( ulp_a == ulp_b ) return;
        if(ulp_a < ulp_b )
        {
            parent[ulp_b-'a'] = ulp_a;
        }
        else
        {
            parent[ulp_a-'a']=ulp_b;
        }
    }

};
class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
       Disjoint dj(26);

       // firstly i will do the union or made chunks of the related charcaters.
       for( int i = 0; i<s1.size(); i++)
       {
        dj.unionByorder(s1[i] , s2[i]);
       }
        string ans="";
        for( int i=0; i<baseStr.size(); i++)
        {
            char possibility = dj.findParent( baseStr[i]);
            if( possibility < baseStr[i]) ans+=possibility;
            else ans+=baseStr[i];
        }
        return ans;
    }
};