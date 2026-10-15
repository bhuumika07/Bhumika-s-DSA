class MedianFinder {
public:
// i need to push elemets in such a way that i get the two middle values 
// now for that the order  i am going to pick will be descending order or could be ascending order
// i need the two middle values always.
//in max heap i will push the smaller half , so it gives me its highest.
// in min heap i will push the greater half so it gives me its -smallest.
//now the problem is how will i decide where the element goes , on what basis?
// i guess we will do that on the basis of both pq's top only , if it is smaller than max heap top element then it goes there otherwise it goes into the min heap.
// now we also have to maintain the size ratio , so that the elements in both the queues should not differ more than one.

    priority_queue<int>max;
    priority_queue< int , vector<int> , greater<int>> min;
    int count ;
    MedianFinder() {
        count = 0;
    }
    
    void addNum(int num) {
        // will push the first element randomly.
       if( max.empty() && min.empty()) {max.push( num );return;}
       // now if both the queue sizes are equal , where will the elemnt go ?
       // it will again depend on the top element -- if its smaller than max heap top->it goes into the max heap , otherwise it goes into the min heap.
       if( max.top() >= num) max.push( num);
       else min.push( num );

       // now will decide if thr sizes got fucked
       if( abs( (int)max.size() - (int)min.size() ) > 1)
       {
        if( max.size() > min.size())
        {
            int t = max.top();
            max.pop();
            min.push( t );
        }
        else
        {
            int t = min.top();
            min.pop();
            max.push( t );
        }
       }
       
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