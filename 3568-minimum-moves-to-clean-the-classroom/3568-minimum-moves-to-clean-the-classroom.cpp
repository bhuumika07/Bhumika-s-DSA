class Solution {
public:
    int minMoves(vector<string>& room, int energy) {
        int rows[]={-1,0,1,0};
        int cols[]={0,-1,0,1};
        int rsize = room.size();
        int csize = room[0].size();
        int a;int b;
        vector<vector<int>>ids(rsize , vector<int>(csize,-1));
        int cnt=0;
        for( int i=0; i<rsize;i++)
        {
            for( int j=0;j<csize;j++)
            {
                if(room[i][j] == 'S')
                {
                    a=i;
                    b=j;
                }
                else if( room[i][j] =='L') ids[i][j] = cnt++;
            }
        }
        if( cnt == 0) return 0;
        int maskedNum = (1 << cnt ) - 1;
       vector<vector<vector<vector<bool>>>> visited(
        rsize,
        vector<vector<vector<bool>>>(csize,
        vector<vector<bool>>(
            energy + 1,
            vector<bool>(1 << cnt, false)
        )
    )
);

        queue< tuple<int , int , int , int> > q;
        q.push( {a,b,energy,0});

        int cost=0;
        while(!q.empty())
        {
            int s = q.size();
            for(int i=0;i<s;i++)
            {
                auto [r1,c1, energyLeft ,collected] = q.front();
                q.pop();
                if( collected == maskedNum) return cost;
                if(energyLeft == 0) continue;
                for( int i=0;i<4;i++)
                {
                    int nrow = r1 + rows[i];
                    int ncol = c1 + cols[i];

                    if( nrow >=0 && nrow < rsize && ncol >=0 && ncol < csize)
                    {
                        int newmask=collected;
                        int newenergy = energyLeft-1;
                        if( room[nrow][ncol] == 'R') newenergy = energy;
                        else if( room[nrow][ncol] == 'L')
                        {
                            int id = ids[nrow][ncol];
                            newmask = (newmask) | ( 1 << id);
                        }
                        else if( room[nrow][ncol] =='X') continue;
                        if( visited[nrow][ncol][newenergy][newmask]) continue;
                        q.push( {nrow , ncol , newenergy, newmask});
                        visited[nrow][ncol][newenergy][newmask]=1;
                    }
                }
               
            }
            cost++;
        }
    return -1;
    }
};