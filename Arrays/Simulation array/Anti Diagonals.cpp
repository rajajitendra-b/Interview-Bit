/**************** QUESTION **************

Give a N*N square matrix, return an array of its anti-diagonals. Look at the example for more details.

Example:

		
Input: 	

1 2 3
4 5 6
7 8 9

Return the following :

[ 
  [1],
  [2, 4],
  [3, 5, 7],
  [6, 8],
  [9]
]


Input : 
1 2
3 4

Return the following  : 

[
  [1],
  [2, 3],
  [4]
]


*/


/*************** APPROACH *************
	To traverse through the diagonal, we just have to go to next column, previous row, keeping track of the limits.
	Once the current diagonal is done, update starting position
 */
	
/*************** SOLUTION *************/
vector<vector<int> > Solution::diagonal(vector<vector<int> > &A) 
{
    vector<vector<int>>answer;
    vector<int> curr;
    int startX = 0, startY = 0, xLimit = A[0].size()-1, yLimit = A.size()-1;
    int i = startX, j = startY;
    while(i !=xLimit || j != yLimit)
    {
    	//Parse through the diagonal
        while(i >=0 && j>=0 && j<=yLimit && i<=xLimit)
        {
            curr.push_back(A[i][j]);
            i++, j--;
        }
        //Save the current diagonal to the answer
        answer.push_back(curr);
        curr.clear();
        //Update the staring positions. 
        if(startY < yLimit)
            startY++;
        else
            startX++;
        i = startX, j = startY;
    }
    curr.push_back(A[i][j]);
    answer.push_back(curr);
    return answer;
}