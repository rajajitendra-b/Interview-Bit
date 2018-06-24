/**************** QUESTION **************
Given a matrix of m * n elements (m rows, n columns), return all elements of the matrix in spiral order.

Example:

Given the following matrix:

[
    [ 1, 2, 3 ],
    [ 4, 5, 6 ],
    [ 7, 8, 9 ]
]
You should return

[1, 2, 3, 6, 9, 8, 7, 4, 5]

*/


/*************** APPROACH *************
	Run through the limits on all 4 directions. When it hits border, change direction
	Here, we follow all four directions as per the spiral order and repeat in the while loop
 */
	
/*************** SOLUTION *************/
vector<int> Solution::spiralOrder(const vector<vector<int> > &A)
{
    vector<int> answer;
    int leftLimit = 0, rightLimit = A[0].size()-1;
    int topLimit = 0, bottomLimit = A.size()-1;
    int i = leftLimit, j = topLimit;
    while(leftLimit <= rightLimit && topLimit <= bottomLimit)
    {
    	//Left to right of first possible row
        for(j = leftLimit; j<=rightLimit;j++)
        {
            answer.push_back(A[topLimit][j]);
        }
        //Change direction to down, top row is done now, so change top limit
        topLimit++;
        //To to bottom of last possible column
        for(i = topLimit; i<=bottomLimit; i++)
        {
            answer.push_back(A[i][rightLimit]);
        }
        //Change direction to left, last column is done now, so change right limit
        rightLimit--;
        //Check for base case
        if(topLimit <= bottomLimit)
        {
        	//To to left from right, of the last possible row
            for(j = rightLimit; j>=leftLimit; j--)
            {
                answer.push_back(A[bottomLimit][j]);
            }
            //Change direction to up, last row is done now, so change bottom limit
            bottomLimit--;
        }
        //Check for base case
        if(leftLimit <= rightLimit)
        {
        	//To to left from right, of the last possible row
            for(i = bottomLimit; i>=topLimit; i--)
            {
                answer.push_back(A[i][leftLimit]);
            }
            //Change direction to up, first column is done now, so change left limit
            leftLimit++;
        }
    }

    return answer;
}