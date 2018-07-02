/**************** QUESTION **************

Implement the next permutation, which rearranges numbers into the numerically next greater permutation of numbers.

If such arrangement is not possible, it must be rearranged as the lowest possible order ie, sorted in an ascending order.

The replacement must be in-place, do not allocate extra memory.

Examples:

1,2,3 → 1,3,2

3,2,1 → 1,2,3

1,1,5 → 1,5,1

20, 50, 113 → 20, 113, 50
Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.

 Warning : DO NOT USE LIBRARY FUNCTION FOR NEXT PERMUTATION. Use of

/*************** APPROACH *************

	For any random integer order, the next permutation has a specific pattern. 
	Ex: 3 2 4 8 7 1 ===next=permutation===> 3 2 7 1 4 8
	If we observe carefully, the last 3 digits 8 7 1 are already in reverse order. So, we ran out of moves until digit 8.
	So, we find the next lowest digit 4 and see where it can be replaced for the next permutation. 
	Doing so is nothing but, finding a place for the first element after reverse order and 
			swap with its corresponding position in reverse order sub array.
	This approach is fairly simple once we understand.

 */
	
/*************** SOLUTION *************/

void Solution::nextPermutation(vector<int> &A) 
{
    int i = A.size()-1;
    //From back, find the element until which reverse sorted order continues
    while(i > 0 && A[i]<=A[i-1])
    {
        i--;
    }
    if(i>0)
    {
    	//Find the place to swap the (i-1)th number for the next permutation
        int j = 0;
        for(j = A.size()-1; j>=0 && A[i-1]>=A[j];j--);
        	swap(A[i-1], A[j]);
    }
    //Reverse the subarray for the next permutation
    reverse(A.begin()+i, A.end());
    return;
}