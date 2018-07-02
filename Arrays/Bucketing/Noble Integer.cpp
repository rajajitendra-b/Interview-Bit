/**************** QUESTION **************

Given an integer array, find if an integer p exists in the array such that the number of integers greater than p in the array equals to p
If such an integer is found return 1 else return -1.

*/

/*************** APPROACH *************
	Sort the array so that the index will lead to the number of element greater than itself. 
	Try to be cautious about repetitive elements
 */
	
/*************** SOLUTION *************/

int Solution::solve(vector<int> &A) 
{
	//Sort the array
    sort(A.begin(), A.end());
    for(int i = 0; i < A.size(); i++)
    {
    	//If number of elements greater than the element equals the element itself
        if(A.size()-i-1 == A[i])
        {
        	//Check for repeated elements, zero being an exception
            if(i < A.size()-1 && A[i] < A[i+1])
                return 1;
            else if (i == A.size()-1 && !A[i])
                return 1;
        }
    }
    return -1;
}