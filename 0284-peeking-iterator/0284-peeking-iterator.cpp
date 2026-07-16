/*
 * Below is the interface for Iterator, which is already defined for you.
 * **DO NOT** modify the interface for Iterator.
 *
 *  class Iterator {
 *		struct Data;
 * 		Data* data;
 *  public:
 *		Iterator(const vector<int>& nums);
 * 		Iterator(const Iterator& iter);
 *
 * 		// Returns the next element in the iteration.
 *		int next();
 *
 *		// Returns true if the iteration has more elements.
 *		bool hasNext() const;
 *	};
 */

class PeekingIterator : public Iterator {
public:
    int nxt;
    bool available;
	PeekingIterator(const vector<int>& nums) : Iterator(nums) {
	    if( Iterator:: hasNext())
        {
            nxt= Iterator:: next();
            available=1;
        }
        else available=false;
	    
	}
	
    // Returns the next element in the iteration without advancing the iterator.
	int peek() {
        return nxt;
	}
	
	// hasNext() and next() should behave the same as in the Iterator interface.
	// Override them if needed.
	int next() {
        int ans =nxt;
        if(Iterator:: hasNext())
        {
            nxt=Iterator::next();
        }
        else
        {
            available=0;
        }
        return ans;
	    
	}
	
	bool hasNext() const {
        return available;
	    
	}
};