class BusBooking {
public:
    vector<vector<int> > ans;
    int totaltime = 0;
    int mintime=0;
    BusBooking(int n) {
       ans.resize( n , vector<int>(4,0)); 
    }
    void toggle(string seat) {
        char s = seat[0];
        string srow = "";
        for( int i=1; i<seat.size(); i++) srow += seat[i];
        int row = stoi(srow)-1;
        if( !ans[row][s- 65] )
        {
            if( s ==  'B' || s == 'C') {
                ans[row][s-65]++; 
                totaltime++;
                 mintime++;
            }
            else {
                if( (s == 'A' && ans[row][1]) || ( s == 'D'  && ans[row] [2]) ){ 
                    totaltime+=3;
                    mintime+=1;
                    ans[row][s-65]+=3;
                }
                else {ans[row][s-65]++;totaltime++; mintime++;}
            }
        }
        else {
            if( s == 'B' || s =='C') {ans[row][s-65]--; mintime--; totaltime--;}
            else
            {
                totaltime-= ans[row][s-65];;
                mintime--;
                ans[row][s-65] = 0;
            }
            }
    }
    
    int getTotalTime() {
        return totaltime;
    }
    
    int getMinTime() {
        return mintime;
    }
};

/**
 * Your BusBooking object will be instantiated and called as such:
 * BusBooking* obj = new BusBooking(n);
 * obj->toggle(seat);
 * int param_2 = obj->getTotalTime();
 * int param_3 = obj->getMinTime();
 */