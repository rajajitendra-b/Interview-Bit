/**************** QUESTION **************

You are given an array of N integers, A1, A2 ,…, AN. Return maximum value of f(i, j) for all 1 ≤ i, j ≤ N.
f(i, j) is defined as |A[i] - A[j]| + |i - j|, where |x| denotes absolute value of x.

For example,

A=[1, 3, -1]

f(1, 1) = f(2, 2) = f(3, 3) = 0
f(1, 2) = f(2, 1) = |1 - 3| + |1 - 2| = 3
f(1, 3) = f(3, 1) = |1 - (-1)| + |1 - 3| = 4
f(2, 3) = f(3, 2) = |3 - (-1)| + |2 - 3| = 5

So, we return 5.

*/


/*************** APPROACH *************
	We can calculate all possible values of |A[i] - A[j]| + |i - j|
	However, it will be of O(n-square) complexity. 
	If we expand f(i, j), with all combinations (as it is mod, we will get 4 combinations), 
	we will realize that monitoring maximum and minimum of 2 combinations are sufficient. 
	In fact, the 4 combinations possible will reduce to 2, the other 2 being redundant. 
 */
	
/*************** SOLUTION *************/

int Solution::maxArr(vector<int> &A) 
{
    int maxAdd = INT_MIN, minAdd = INT_MAX;
    int minSub = INT_MAX, maxSub = INT_MIN;
    for(int i = 0; i < A.size(); i++)
    {
    	// Adding 1 because we array is 0 indexed, but we need 1 indexed difference
        maxAdd = max(maxAdd, (A[i] + (i+1)));
        minAdd = min(minAdd, (A[i] + (i+1)));
        maxSub = max(maxSub, (A[i] - (i+1)));
        minSub = min(minSub, (A[i] - (i+1)));
    }
    //The difference between maximum gap from the two combinations gives the answer
    return (max(abs(maxAdd - minAdd), abs(maxSub - minSub)));
}