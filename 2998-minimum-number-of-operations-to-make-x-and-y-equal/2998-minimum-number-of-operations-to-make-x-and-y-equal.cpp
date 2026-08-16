class Solution {
public:
    int minimumOperationsToMakeEqual(int x, int y) {
      queue<int>q;
      q.push(x);
      int step=0;
      unordered_set<int>check;
      while(!q.empty())
      {
        int size = q.size();
        for( int i=0; i<size;i++)
        {
            int num = q.front();
            q.pop();
            if( num == y) return step;
            if( num%11==0 && check.find(num/11) == check.end()){
                q.push( num/11);
                check.insert(num/11);
            } 
            if( num%5==0 && check.find(num/5) == check.end()){
                q.push(num/5);
                check.insert(num/5);
            } 
            if( check.find(num-1) == check.end()) {q.push(num-1); check.insert(num-1);}
             if( check.find(num+1) == check.end()){q.push(num+1); check.insert(num+1);}
        }
        step++;
      }
        return -1;
    }
};