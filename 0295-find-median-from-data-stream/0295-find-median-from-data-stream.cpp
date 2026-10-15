class MedianFinder {
public:
    priority_queue<int>max;
    priority_queue< int , vector<int> , greater<int>> min;
    MedianFinder() {}
    
    void addNum(int num) {
       if( max.empty() || max.top() >= num) max.push( num);
       else min.push( num );
        if( max.size() > min.size() + 1){
            int t = max.top();  max.pop();  min.push( t );}
        else if( min.size() > max.size() + 1) {
            int t = min.top();  min.pop(); max.push( t );}
    }
    
    double findMedian() {
        if( max.size() != min.size())
        {
            if( max.size() > min.size()) return (double)max.top();
            return (double)min.top();
        }
        else
        {
            double x =(double) min.top(); double y = (double)max.top();
            return (x+y)/2.00000;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */