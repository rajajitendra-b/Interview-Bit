/**************** QUESTION **************

You are given an n x n 2D matrix representing an image.

Rotate the image by 90 degrees (clockwise).

You need to do this in place.

Note that if you end up using an additional array, you will only receive partial score.

Example:

If the array is

[
    [1, 2],
    [3, 4]
]
Then the rotated array becomes:

[
    [3, 1],
    [4, 2]
]

/*************** APPROACH *************
Two approaches possible, choose whichever is easier for you. Both are inplace algorithms. 
1) Transpose the matric and reverse the rows gives a new matrix which is 90 clockwise rotation
	For a sample matrix
	1 2 3  
	4 5 6  
	7 8 9
	Transpose the matrix folowed by reversal gives 
	1 4 7 -- reverse --> 7 4 1
	2 5 8 -- reverse --> 8 5 2
	3 6 9 -- reverse --> 9 6 3
	Time Complexity : O(n*n)
2) Use 4-way swapping:
	To rotate a matrix, if we observe rotation carefully, an element replaces the corresponding 90 deg clock wise element.
	Also, the replaced element is in turn replaced by further 90 clock wise element. 
	This happens for all 4 sides and hence we call it 4-way swap. 
	We do such a 4-way swap on outer boundary ring of a matrix in first loop, then the penultimate outer ring and so on.
	Time Complexity : O(n)
 */
	
/*************** SOLUTION *************/

void Solution::rotate(vector<vector<int> > &A) {
    int n = (A.size());
    int i = 0, j = 0;
    int temp = 0;

    for(i = 0; i < n/2; i++)
    {
    	//Loop for outermost possible layer
        for(j = i; j < n-i-1; j++)
        {
        	//4 way swap: 
            temp = A[i][j];
            A[i][j] = A[n-j-1][i];
            A[n-j-1][i] = A[n-i-1][n-j-1]; 
            A[n-i-1][n-j-1] = A[j][n-i-1];
            A[j][n-i-1] = temp;
        }
    }
    return;
}
