/**************** QUESTION **************

Given an m x n matrix of 0s and 1s, if an element is 0, set its entire row and column to 0.

Do it in place.

Example

Given array A as

1 0 1
1 1 1 
1 1 1
On returning, the array A should be :

0 0 0
1 0 1
1 0 1
Note that this will be evaluated on the extra memory used. Try to minimize the space and time complexity.

/*************** APPROACH *************

To make all zeroes in row/column when we encounter o is a specific position, 
	we cannot directly set to zero as it would lead to zero matrix eventually.
We need markers in the first traversal, and, based on markers, we can set the matrix to 0.
To have markers. we need at least (rows + columns) number of markers. 
To reuse space, we can make use of 1st row and 1st column for this purpose. 
The problem of 1st row/column zero case can be solved using two boolean variables respectively.

 */
	
/*************** SOLUTION *************/

void Solution::setZeroes(vector<vector<int> > &A) 
{
    bool rowZero = false, colZero = false;
    /* Check the zero elements and mark the corresponding 0th row and 0th column as 0 for future reference.
     * To avoid confusion with zeroes in 1st row or column, 
     * we have two variables rowZero and colZero to represent corresponding row/column zero
     */
    for(int i = 0; i < A.size(); i++)
    {
        for(int j = 0; j < A[0].size(); j++)
        {
            if(!i && !A[i][j])
                rowZero = true;
            if(!j && !A[i][j])
                colZero = true;
            if((i && j) && !A[i][j])
                A[0][j] = A[i][0] = 0;
        }
    }
    //Based on the markers of first row, set the corresponding columns 0
    for(int i = 1; i < A.size(); i++)
    {
        if(!A[i][0])
            for(int j = 1; j < A[0].size(); j++)
                A[i][j] = 0;
    }
    //Based on the markers of first column, set the corresponding rows 0
    for(int j = 1; j < A[0].size(); j++)
    {
        if(!A[0][j])
            for(int i = 1; i < A.size(); i++)
                A[i][j] = 0;
    }
    //Based on first row/column marker, set zeroes accordingly
    if(rowZero)
        for(int j = 0; j < A[0].size(); j++)
            A[0][j] = 0;
    if(colZero)
        for(int i = 0; i < A.size(); i++)
            A[i][0] = 0;

    return;
}
