/**************** QUESTION **************

Given an array A of integers, find the maximum of j - i subjected to the constraint of A[i] <= A[j].

If there is no solution possible, return -1.

Example :

A : [3 5 4 2]

Output : 2 
for the pair (3, 4)

*/

/*************** APPROACH *************
	What we are asked for is, essentially, the maximum distance of any two elements in sorted order. 
	If we maintain minimum and maximum till now at each position throught the array, our job becomes simpler.
	If we have such arrays, all we need to do is, get the distance and find the maximum distance.
	This algorithm takes O(2n) space and O(n) time. 
 */
	
/*************** SOLUTION *************/


int Solution::maximumGap(const vector<int> &A) 
{
    if(A.size()<2)
        return 0;
    vector<int> leftMinimum(A.size(), INT_MAX);
    vector<int> rightMaximum(A.size(), INT_MIN);
    leftMinimum[0] = A[0];
    rightMaximum[A.size()-1] = A[A.size()-1];
    //Maintain minimum till now as an array
    for(int i = 1; i < A.size(); i++)
    {
        leftMinimum[i] = min(leftMinimum[i-1], A[i]);
    }
    //Maintain minimum till now from behind, as an array
    for(int i = A.size()-2; i>=0; i--)
    {
        rightMaximum[i] = max(rightMaximum[i+1], A[i]);
    }
    int i = 0, j = 0, maxDiff = -1;
    //Get the distance of eligible candidates and compute max distance
    while(j < A.size() && i < A.size())
    {
        if(leftMinimum[i] <= rightMaximum[j])
        {
            maxDiff = max(maxDiff, j-i);
            j = j+1;
        }
        else
            i = i+1;
    }
    return maxDiff;
}