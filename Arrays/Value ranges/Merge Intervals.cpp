/****************,QUESTION,**************

Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).

You may assume that the intervals were initially sorted according to their start times.

Example 1:

Given intervals [1,3],[6,9] insert and merge [2,5] would result in [1,5],[6,9].

Example 2:

Given [1,2],[3,5],[6,7],[8,10],[12,16], insert and merge [4,9] would result in [1,2],[3,10],[12,16].

This is because the new interval [4,9] overlaps with [3,5],[6,7],[8,10].

Make sure the returned intervals are also sorted.

/***************,APPROACH,*************
To merge a new interval to the existing intervals, we first insert the new interval to intervals vector, as per start sorted order.
We then try to see if any overlapping range exists. 
To do so, we use double ended queue as an intermediate data structure. We use this deque as stack first, and then queue.
1) Compare the top element with the next element to see if they are overlapping. 
   In case of overlapping, we modify the top of stack with the merged interval. 
   If not overlapping, we keep pushing the next element
   We keep repeating this process for all elements in the vector
2) The obtained deque elements are the actual merged interval. 
   We now use the deque as a queue and insert them all to our answer vector in FIFO order. 

,*/
	
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

vector<Interval> Solution::insert(vector<Interval> &intervals, Interval newInterval) 
{
    bool elementInserted = false;
    //Insert the new interval into the intervals, order by start index
    for(int i = 0; i < intervals.size(); i++)
    {
        if(intervals[i].start >= newInterval.start)
        {
            intervals.insert(intervals.begin()+i, newInterval);
            elementInserted = true;
            break;
        }
    }
    if(!elementInserted)
        intervals.push_back(newInterval);
    //Take a double ended queue, initially for stack operation, later for queue operation
    deque<Interval>dq;
    //Push first element to the stack
    int i = 0;
    dq.push_back(intervals[i++]);
    for(; i < intervals.size(); i++)
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
    vector<Interval> answer;
    while(!dq.empty())
    {
        answer.push_back(dq.front());
        dq.pop_front();
    }
    return answer;
}
