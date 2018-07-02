/**************** QUESTION **************

Given an integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.

Example:

Given n = 3,

You should return the following matrix:

[
  [ 1, 2, 3 ],
  [ 8, 9, 4 ],
  [ 7, 6, 5 ]
]

*/


/*************** APPROACH *************
Keep lower and upper limits for column and row. 
Traverse through the spiral order while keeping track of limits after every turn.
 */
	
/*************** SOLUTION *************/

vector<vector<int> > Solution::generateMatrix(int A) 
{
	//4 limits for row and column: r and rn are min and max rows, c and cn are min and max cols
    int r = 0, rn = A-1;
    int c = 0, cn = rn;
    int i = 0, count = 1;
    vector <vector<int>> answer (A, vector<int>(A,0));
    while(r <= rn && c <= cn)
    {
    	//Fill first possible row
        for(i = c; i <= cn; i++)
        {
            answer[r][i] = count++;
        }
        //Update lower row limit
        r++;
    	//Fill last possible column
        for(i = r; i <= rn; i++)
        {
            answer[i][cn] = count++;
        }
        //Update upper column limit
        cn--;
    	//Fill last possible row
        for(i = cn; i >= c; i--)
        {
            answer[rn][i] = count++;
        }
        //Update upper row limit
        rn--;
    	//Fill first possible column
        for(i = rn; i>=r; i--)
        {
            answer[i][c] = count++;
        }
        //Update lower column limit
        c++;
        //Repeat until row and column collapses to the spiral nucleus
    }
    return answer;
}