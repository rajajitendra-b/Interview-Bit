/**************** QUESTION **************

Given an unsorted integer array, find the first missing positive integer.

Example:

Given [1,2,0] return 3,

[3,4,-1,1] return 2,

[-8, -7, -6] returns 1

Your algorithm should run in O(n) time and use constant space.

/*************** APPROACH *************
To find first missing integer, we should mark what all integers already present.
For that, we need markers. Having array size markers(first missing integer is always <= arraySize+1) is like using O(n) space.
In order to have space recycling, and because we have 1 to n+1 as answer range, it would be better if we can reuse array elements.
To do that, we DO NOT need -ve numbers and numbers > arraySize. 
We isolate -ve numbers first, and then, we mark exising number by making the number index as -ve. 
So, to get 1st missing integer, when we find first +ve number after separating initial -ve numbers.

 */
	
/*************** SOLUTION *************/

//To ignore -ve numbers, we move all -ves to the starting and process only +ve part of the array
int partition(vector<int> &A)
{
    int j = 0;
    for(int i = 0; i < A.size(); i++)
       if (A[i] <= 0)
           swap(A[i], A[j++]);
    return j;
}

int Solution::firstMissingPositive(vector<int> &A) 
{
    int n = A.size();
    bool atleastOnePositive = false;
    int positiveStart = partition(A);
    //Check only +ve numbers
    for(int i = positiveStart; i < n; i++)
    {
    	//abs required as we can get already marked element
        int ind = abs(abs(A[i])-1+positiveStart);
        if(ind < n)
        {
            A[ind] = -(abs(A[ind]));
            atleastOnePositive = true;
        }
        //Else, ind is not in range of answer, we ignore such cases.
    }
    //Find the 1st positive number
    for(int i = positiveStart; i < n; i++)
    {
        if(A[i] >= 0)
            return i-positiveStart+1;
    }
    //We did not return till now, which means, either all 1 to n are present, or none of them are present. 
    //To identify, we check if atleast one +ve number is found. 
    if(atleastOnePositive)
        return n+1;
    return 1;
}