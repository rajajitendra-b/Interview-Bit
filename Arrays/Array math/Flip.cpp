/**************** QUESTION **************
You are given a binary string(i.e. with characters 0 and 1) S consisting of characters S1, S2, …, SN. In a single operation, you can choose two indices L and R such that 1 ≤ L ≤ R ≤ N and flip the characters SL, SL+1, …, SR. By flipping, we mean change character 0 to 1 and vice-versa.

Your aim is to perform ATMOST one operation such that in final string number of 1s is maximised. If you don’t want to perform the operation, return an empty array. Else, return an array consisting of two elements denoting L and R. If there are multiple solutions, return the lexicographically smallest pair of L and R.

Notes:

Pair (a, b) is lexicographically smaller than pair (c, d) if a < c or, if a == c and b < d.
For example,

S = 010

Pair of [L, R] | Final string
_______________|_____________
[1 1]          | 110
[1 2]          | 100
[1 3]          | 101
[2 2]          | 000
[2 3]          | 001

We see that two pairs [1, 1] and [1, 3] give same number of 1s in final string. So, we return [1, 1].
Another example,

If S = 111

No operation can give us more than three 1s in final string. So, we return empty array [].

*/


/*************** APPROACH *************

	We need to maximise the continuous 0s. 
	If we assume 0s as +ves and 1 as corresponding -ves, the problem boils down to finding maximum contiguous sub-array
	In such case, we may apply Kadane's algorithm to solve this problem. 
	We can consider 1s as -1 and 0s as +1 (or -2 and +2, or -x ans +x).
 */
	
/*************** SOLUTION *************/


vector<int> Solution::flip(string A) 
{
    vector<int> answer(2, 0);
    int currSum = 0, maxSum = INT_MIN, start = 0, end = 0;
    for(int i = 0; i < A.length(); i++)
    {
    	//Consider 0 as +ve as we wanted maximum contiguous 0s to be flipped.
        if(A[i] == '0')
            currSum += 1;
        else //1 as -ve 
            currSum -= 1;
        if(currSum < 0)
        {
            currSum = 0;
            start = end = i+1;//Mark start and end index to the newly pointed value. +1 because answer is expected not to be zero based indexing
        }
        else
        {
            end++;
            if(maxSum < currSum)
            {
                maxSum = currSum;
                answer = {start+1, end};//When sum reaches maximum, update start and end index
            }
        }
    }
    //In case start is not updated, which means we don't want to flip, return empty array
    if(!answer[0])
        answer.clear();
    return answer;
}