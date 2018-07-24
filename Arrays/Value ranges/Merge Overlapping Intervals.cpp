/****************,QUESTION,**************

Given a collection of intervals, merge all overlapping intervals.

For example:

Given [1,3],[2,6],[8,10],[15,18],

return [1,6],[8,10],[15,18].

Make sure the returned intervals are sorted.

/***************,APPROACH,*************
As per the question, we first sort the vector as per start sorted order.
We then try to see if any overlapping range exists. 
To do so, we use double ended queue as an intermediate data structure. We use this deque as stack first, and then queue.
1) Compare the top element with the next element to see if they are overlapping. 
   In case of overlapping, we modify the top of stack with the merged interval. 
   If not overlapping, we keep pushing the next element
   We keep repeating this process for all elements in the vector
2) The obtained deque elements are the actual merged interval. 
   We now use the deque as a queue and insert them all to our answer vector in FIFO order. 

*/
	
/***************,SOLUTION,*************/

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */

bool byStart(const Interval &a, const Interval&b)
{
    return a.start < b.start;
}

vector<Interval> Solution::merge(vector<Interval> &intervals) 
{
    //Sort the vector based on the element sort, using comparator method
    sort(intervals.begin(), intervals.end(), byStart);
    //Take a double ended queue, initially for stack operation, later for queue operation
    deque<Interval>dq;
    //Push first element to the stack
    int i = 0;
    dq.push_back(intervals[i++]);
    for(;i<intervals.size(); i++)
    {
        //While top of stack is not overlapping with next interval, push next interval to stack
        Interval sTop = dq.back();
        if(sTop.end < intervals[i].start)
        {
            dq.push_back(intervals[i]);
        }
        //If top of stack is overlapping with next interval, 
            //update the TOS with new interval and push it back
        else if(sTop.end < intervals[i].end)
        {
            sTop.end = intervals[i].end;
            dq.pop_back();
            dq.push_back(sTop);
        }
    }
    //Now, stack has all elements in reverse order. Get all elements in FIFO order as in Q
    vector<Interval>answer;
    while(!dq.empty())
    {
        answer.push_back(dq.front());
        dq.pop_front();
    }
    return answer;
}
