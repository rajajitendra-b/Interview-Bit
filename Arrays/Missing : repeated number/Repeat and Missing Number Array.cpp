/**************** QUESTION **************

You are given a read only array of n integers from 1 to n.

Each integer appears exactly once except A which appears twice and B which is missing.

Return A and B.

Note: Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

Note that in your output A should precede B.

Example:

Input:[3 1 2 5 3] 

Output:[3, 4] 

A = 3, B = 4

Please take extra care to make sure that you are type-casting your ints to long properly and at all places. 
Try to verify if your solution works if number of elements is as large as 10^5
Even though it might not be required in this problem, in some cases, you might be required to order the operations cleverly so that the numbers do not overflow. 
For example, if you need to calculate n! / k! where n! is factorial(n), one approach is to calculate factorial(n), factorial(k) and then divide them. 
Another approach is to only multiple numbers from k + 1 ... n to calculate the result. 
Obviously approach 1 is more susceptible to overflows.

/*************** APPROACH *************
From the questoin, we know the range of integers as 1 to n.
We have to find 2 unknowns (A which appears twice and B which is missing), so we need 2 equations to solve. 
We can find sum of all n and sum of squares of all n. 
Sum of all elements - sum of all 1 to n ===> gives A - B
Sum of all element squares - sum of all 1 to n squares ===> gives A^2 - B^2 = (A+B)(A-B)
Solving the equations we can get both A and B

 */
	
/*************** SOLUTION *************/

vector<int> Solution::repeatedNumber(const vector<int> &A) 
{
    long long sum = 0, squareSum = 0;
    for (long long i = 0; i < A.size(); i++) 
    {
        sum += (long long)A[i] - (i+1);//To get A-B
        squareSum += ((long long)A[i] * (long long)A[i]) - ((i+1)*(i+1));//To get (A+B)(A-B)
    }
    squareSum /= sum; //We get A+B here
    int twice = (int)((sum + squareSum)>>1);
    int missing = (int)(squareSum - twice);
    vector<int> answer({twice, missing});
    return answer;
}
