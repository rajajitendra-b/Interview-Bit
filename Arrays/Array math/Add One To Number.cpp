/**************** QUESTION **************
Given a non-negative number represented as an array of digits,

add 1 to the number ( increment the number represented by the digits ).

The digits are stored such that the most significant digit is at the head of the list.

Example:

If the vector has [1, 2, 3]

the returned vector should be [1, 2, 4]

as 123 + 1 = 124.

 NOTE: Certain things are intentionally left unclear in this question which you should practice asking the interviewer.
For example, for this problem, following are some good questions to ask :
Q : Can the input have 0’s before the most significant digit. Or in other words, is 0 1 2 3 a valid input?
A : For the purpose of this question, YES
Q : Can the output have 0’s before the most significant digit? Or in other words, is 0 1 2 4 a valid output?
A : For the purpose of this question, NO. Even if the input has zeroes before the most significant digit.

*/


/*************** APPROACH *************
	Reverse the array, add one to the first element and fall through carry.
	In case there is no number, append one to the answer
 */
	
/*************** SOLUTION *************/

vector<int> Solution::plusOne(vector<int> &A) 
{
    int i = 0;
    //Reverse the vector
    reverse(A.begin(), A.end());
    //For the numbers with 9, carry needs to be appended. 
    while(i < A.size() && A[i] == 9)
    {
        A[i++] = 0;
    }
    //Append new integer 1 as carry
    if(i == A.size())
        A.push_back(1);
    else//Otherwise, add one to the first number
    {
        A[i]++;
        i++;
    }
    //Reverse it back
    reverse(A.begin(), A.end());
    //Remove trailing zeroes, if any
    for(i = 0; i < A.size() && !A[i];)
    {
        A.erase(A.begin());
    }
    return A;
}