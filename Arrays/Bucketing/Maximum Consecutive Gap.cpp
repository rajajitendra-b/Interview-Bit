/****************,QUESTION,**************

Given an unsorted array, find the maximum difference between the successive elements in its sorted form.

Try to solve it in linear time/space.

Example :

Input : [1, 10, 5]
Output : 5 
Return 0 if the array contains less than 2 elements.

You may assume that all the elements in the array are non-negative integers and fit in the 32-bit signed integer range.
You may also assume that the difference will not overflow.

/***************,APPROACH,*************

Pegion hole principle states that, if n items are put into m containers, with n < m, then at least one container must be empty.
In this problem, we need to find maximum consecutive gap in its sorted form. 
If we have n-1 buckets (of average size form max to min element), n being the size of array, 
	there will be at least one container empty if there is a gap. 
Ex; 1 3 4 6 7 9 (n is 6, max is 9, min is 1).
 	If we have to make 5 buckets of equal range (max-min)/5, we get 8/5 = 1.6
 	Which means, bucket interval for 5 buckets becomes 
 	 Bucket-1    Bucket-2    Bucket-3    Bucket-4    Bucket-5
 	[1.0, 2.6), [2.6, 4.2), [4.2, 5.8), [5.8, 7.4), [7.4, 9.0)
 	                3 4                     6 7                  ===> Elements in corresponding buckets, excluding min & max
 	            bucktet max            bucktet min
 	                 4                       6
 	                 \______________________/
 	                            |
 	                 Max gap in sorted order 2

,*/
	
/***************,SOLUTION,*************/

int Solution::maximumGap(const vector<int> &A) 
{
    int mini = INT_MAX, maxi = INT_MIN, n = A.size();
    if(A.size() < 2)
        return 0;
    //Find and minimum and maximum element from the given vector
    for(int i = 0; i < n; i++)
    {
        if(A[i] > maxi)
            maxi = A[i];
        if(A[i] < mini)
            mini = A[i];
    }
    //By Pegion Hole principle, have n-1 buckets with equal range. 
    vector<int>bucketMaxima(n-1, INT_MIN);
    vector<int>bucketMinima(n-1, INT_MAX);
    float range = (float)(maxi-mini)/(float)(n-1);
    for(int i = 0; i < n; i++)
    {
        if(A[i] == mini || A[i] == maxi)
            continue;
        //Count the number of values in each bucket.
        int bucketIndex = (int)((float)(A[i]-mini)*(n-1)/(float)(maxi-mini));
        bucketMinima[bucketIndex] = min(bucketMinima[bucketIndex], A[i]);
        bucketMaxima[bucketIndex] = max(bucketMaxima[bucketIndex], A[i]);
    }

    //Now find maximum consecutive vacant buckets
    int maxGap = 0, prevMaxima = mini;
    for(int i = 0; i < n-1; i++)
    {
        if(bucketMinima[i] == INT_MAX && bucketMaxima[i] == INT_MIN)
            continue;
        maxGap = max(maxGap, bucketMinima[i] - prevMaxima);
        prevMaxima = bucketMaxima[i];
    }
    
    maxGap = max(maxGap, maxi - prevMaxima);
    return maxGap;
}