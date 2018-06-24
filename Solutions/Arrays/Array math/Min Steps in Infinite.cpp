/**************** QUESTION **************

You are in an infinite 2D grid where you can move in any of the 8 directions :

 (x,y) to 
    (x+1, y), 
    (x - 1, y), 
    (x, y+1), 
    (x, y-1), 
    (x-1, y-1), 
    (x+1,y+1), 
    (x-1,y+1), 
    (x+1,y-1) 
You are given a sequence of points and the order in which you need to cover the points. Give the minimum number of steps in which you can achieve it. You start from the first point.

Example :

Input : [(0, 0), (1, 1), (1, 2)]
Output : 2
It takes 1 step to move from (0, 0) to (1, 1). It takes one more step to move from (1, 1) to (1, 2).

This question is intentionally left slightly vague. Clarify the question by trying out a few cases in the “See Expected Output” section.

*/


/*************** APPROACH *************
 In an Infinite grid, moving from (x1, y1) to (x2, y2) is shortest when moving through diagonals. 
 As we have a diagonal spet, moving through diagonals takes either x difference or y difference, whichever is the maximum
 */
	
/*************** SOLUTION *************/

int Solution::coverPoints(vector<int> &A, vector<int> &B) 
{
    if(A.size() != B.size())
        return -1;
    int answer = 0;
    for(int x = 1; x < A.size(); x++)
    {
    	//Measuring the diagonal path, x difference or y difference, whichever is the maximum
        answer += max(abs(A[x]-A[x-1]) , abs(B[x]-B[x-1]));
    }
    return answer;
}