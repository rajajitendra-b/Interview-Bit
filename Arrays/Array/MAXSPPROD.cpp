/****************,QUESTION,**************

You are given an array A containing N integers. The special product of each ith integer in this array is defined as the product of the following:<ul>

LeftSpecialValue: For an index i, it is defined as the index j such that A[j]>A[i] (i>j). If multiple A[j]’s are present in multiple positions, the LeftSpecialValue is the maximum value of j. 

RightSpecialValue: For an index i, it is defined as the index j such that A[j]>A[i] (j>i). If multiple A[j]s are present in multiple positions, the RightSpecialValue is the minimum value of j.

Write a program to find the maximum special product of any integer in the array.

Input: You will receive array of integers as argument to function.

Return: Maximum special product of any integer in the array modulo 1000000007.

Note: If j does not exist, the LeftSpecialValue and RightSpecialValue are considered to be 0.

Constraints 1 <= N <= 10^5 1 <= A[i] <= 10^9

/***************,APPROACH,*************

The leftSpecialValue of i means, when we iterate to left from i, the index of the next greater element(NGE).
Same is the case for rightSpecialValue. 
To get the next greater index, we use stack to find it. 
As we push and pop each element only once, complexity is O(n).

To find NGE of each element, we need to find the non-decreasing order
We first push 1st element to stack. 
Then, for each element in the vector, we compare with TOS. 
For all greater elements, we mark it as NGE. Otherwise, we push to the stack. 
If we put it on paper, we are only skipping the smaller elements. 
Whenever an element greater than the current index is seen, we get NGE. 

*/
	
/***************,SOLUTION,*************/

#define MOD 1000000007

int Solution::maxSpecialProduct(vector<int> &A) 
{
    vector<int> leftSpecial(A.size(), 0);
    vector<int> rightSpecial(A.size(), 0);
    unsigned long long maxProd = 0;
    //Using vector as stack, pushing 1st element
    vector<int>stk;
    stk.push_back(0);
    //For right special, we move right
    for(int i = 1; i < A.size(); i++)
    {
        if(stk.empty())
            stk.push_back(i);
        else
        {
        	//If element A[i] is greater than TOS, we mark this element as NGE for TOS.
            while(!stk.empty() && A[stk.back()] < A[i])
                rightSpecial[stk.back()] = i, stk.pop_back();
            stk.push_back(i);
        }
    }
    
    //For left special, we move left, using the same vector as stack
    stk.clear();
    stk.push_back(A.size()-1);
    for(int i = A.size()-2; i >= 0; i--)
    {
        if(stk.empty())
            stk.push_back(i);
        else
        {
        	//If element A[i] is greater than TOS, we mark this element as NGE for TOS.
            while(!stk.empty() && A[stk.back()] < A[i])
                leftSpecial[stk.back()] = i, stk.pop_back();
            stk.push_back(i);
        }
    }

    //Once we get all all the NGE on both sides, we compute max product. 
    //As it can overflow, we get left and right separately
    unsigned long long maxP = 0;
    int l = 0, r = 0;
    for(int i = 0; i < A.size(); i++)
    {
        if(leftSpecial[i] && rightSpecial[i] && maxP < (leftSpecial[i] * rightSpecial[i]))
        {
            maxP = leftSpecial[i] * rightSpecial[i];
            l = leftSpecial[i];
            r = rightSpecial[i];
        }
    }
    return ((l%MOD)*(r%MOD))%MOD;
}
/*
 * Brute force solution *

#define MOD 1000000007

int Solution::maxSpecialProduct(vector<int> &A) 
{
    long long maxVal = 0, prod = 1;
    for(int i = 1; i < A.size()-1; i++)
    {
        int left = i-1, right = i+1;
        while(left > 0 && A[left] <= A[i])
            left--;
        while(right < A.size() && A[right] <= A[i])
            right++;
        if(left>0 && right < A.size())
        {
            prod = left * right;
            if(maxVal < prod)
                maxVal = prod;
        }
    }
    return (maxVal%MOD);
}
*/