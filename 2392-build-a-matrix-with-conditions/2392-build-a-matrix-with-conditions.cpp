class Solution {
public:
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rows, vector<vector<int>>& cols) {
        int r=0;
        vector<vector<int>>graph(k);
        vector<int>inorder(k);
        vector<int>row;
        for( int i=0; i<rows.size(); i++)
        {
            graph[ rows[i][0] - 1].push_back( rows[i][1]-1);
            inorder[rows[i][1] - 1]++;
        }
        queue<int>q;
        for( int i=0; i<k;i++)
        {
            if( inorder[i] == 0) q.push(i);
        }
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            row.push_back(node);
            for( auto it : graph[node])
            {
                inorder[it]--;
                if( inorder[it]==0) q.push(it);
            }
        }
        if(row.size() != k) return {};
        vector<vector<int>>graph1(k);
        vector<int>indegree(k);
        for( int i=0; i<cols.size();i++)
        {
            graph1[ cols[i][0]-1].push_back( cols[i][1]-1);
            indegree[ cols[i][1] - 1]++;
        }
        for( int i=0; i<k;i++)
        {
            if( indegree[i]==0) q.push(i);
        }

        unordered_map<int,int>store;
        int count = 0;
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            store[node]=count;
            count++;
            for( int it : graph1[node])
            {
                indegree[it]--;
                if( indegree[it]==0) q.push(it);
            }
        }
        if( store.size() < k) return {};
        vector<vector<int>>ans( k , vector<int>( k, 0));
        for(int i=0; i<k; i++)
        {
            int coll = store[ row[i] ];
            ans[i][coll]= row[i]+1;
        }
        return ans;
        
    }
};