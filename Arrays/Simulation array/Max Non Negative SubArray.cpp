/**************** QUESTION **************

Find out the maximum sub-array of non negative numbers from an array.
The sub-array should be continuous. That is, a sub-array created by choosing the second and fourth element and skipping the third element is invalid.

Maximum sub-array is defined in terms of the sum of the elements in the sub-array. Sub-array A is greater than sub-array B if sum(A) > sum(B).

Example:

A : [1, 2, 5, -7, 2, 3]
The two sub-arrays are [1, 2, 5] [2, 3].
The answer is [1, 2, 5] as its sum is larger than [2, 3]
NOTE: If there is a tie, then compare with segment's length and return segment which has maximum length
NOTE 2: If there is still a tie, then return the segment with minimum starting index

*/


/*************** APPROACH *************

Check through each element of an array and keep the sum until we get a -ve number.
Once we get -ve number, reset our variable and record the maximum. Also, keep master variables updated for the answer

 */
	
/*************** SOLUTION *************/

vector<int> Solution::maxset(vector<int> &A) 
{
    long long maxSubArray = INT_MIN, currMaxSubArray = 0;
    vector<int> answer;
    vector<int> currMaxArr;
    for(int i = 0; i < A.size(); i++)
    {
        if(A[i]>=0)
        {
            currMaxArr.push_back(A[i]);
            currMaxSubArray += A[i];
        }
        if(A[i] < 0 || i+1 == A.size())
        {
            if(currMaxSubArray > maxSubArray)
            {
                answer.clear();
                answer = currMaxArr;
                maxSubArray = currMaxSubArray;
            }
            else if(currMaxSubArray == maxSubArray)
            {
                //If there is a tie, then compare with segment's length 
                //and return segment which has maximum length
                if(currMaxArr.size() > answer.size())
                {
                    answer.clear();
                    answer = currMaxArr;
                }
                //Else, both are equal size, 
                //If there is still a tie, then 
                //return the segment with minimum starting index, which is already with maxSubArray
            }
            else
            {
                //We already have maximum, so leave it
            }
            currMaxArr.clear();
            currMaxSubArray = 0;
        }
    }
    return answer;
}