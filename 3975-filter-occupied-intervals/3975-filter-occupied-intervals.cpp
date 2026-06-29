class Solution {
public:
    vector<vector<int>> filterOccupiedIntervals(vector<vector<int>>& inter, int freeStart, int freeEnd) {
        sort(inter.begin(), inter.end());
        vector<int> merge;
        int start= inter[0][0];
        int end = inter[0][1];
        for( int i=1; i<inter.size();i++)
            {
                if( inter[i][0]  <= end +1)
                {
                   if (inter[i][1] > end) end=inter[i][1];
                }
                else
                {
                    merge.push_back(start);
                    merge.push_back(end);
                    start=inter[i][0];
                    end=inter[i][1];
                }
            }
        merge.push_back(start);
        merge.push_back(end);
        vector<int>temp;
        for( int i=0; i< merge.size();i+=2)
            {
                int l = merge[i];
                int r = merge[i + 1];

                if(r < freeStart || l > freeEnd)
                {
                    temp.push_back(l);
                    temp.push_back(r);
                }
                 else if(freeStart <= l && r <= freeEnd)
                {
                    continue;
                }
                 else if(l < freeStart && r <= freeEnd)
                {
                    temp.push_back(l);
                    temp.push_back(freeStart - 1);
                }
                  else if(freeStart <= l && freeEnd < r)
                 {
                    temp.push_back(freeEnd + 1);
                    temp.push_back(r);
                  }
                  else
                 {
                    temp.push_back(l);
                    temp.push_back(freeStart - 1);

                    temp.push_back(freeEnd + 1);
                    temp.push_back(r);
                }
        }
        merge=temp;
        // if( merge[ merge.size()-1] <= freeEnd) 
        vector<vector<int>> ans;

        for( int i=0; i<temp.size(); i+=2)
            {
                if( merge[i]>0 && merge[i+1] >0)
                {
                    ans.push_back( {merge[i], merge[i+1]});
                    
                }
            }
        return ans;
    }
};