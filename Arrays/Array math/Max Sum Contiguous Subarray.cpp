/**************** QUESTION **************
Find the contiguous subarray within an array (containing at least one number) which has the largest sum.

For example:

Given the array [-2,1,-3,4,-1,2,1,-5,4],

the contiguous subarray [4,-1,2,1] has the largest sum = 6.

For this problem, return the maximum sum.

*/


/*************** APPROACH *************
	Following Kadane's algorithm:
		Keep calculating max while parsing through the array. 
		While doing so, keep track of maximum till now
 */
	
/*************** SOLUTION *************/
int Solution::maxSubArray(const vector<int> &A) 
{
    int currMax = 0, maxSum = INT_MIN;
    for(int i = 0; i < A.size(); i++)
    {
    	//Keep calculating sum. Whenever sum becomes -ve, start fresh from next element
        currMax += A[i];
        if(currMax < 0)
            currMax = 0;
        else
        {
        	//Keep track of maximum sum till now
            if(maxSum < currMax)
                maxSum = currMax;
        }
    }
    // In case of no elements or all -ve elements, get maximum element as answer
    if(maxSum < 0)
        return *(max_element(A.begin(), A.end()));
    return maxSum;
}