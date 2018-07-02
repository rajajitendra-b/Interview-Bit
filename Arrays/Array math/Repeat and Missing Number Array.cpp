/**************** QUESTION **************
You are given a read only array of n integers from 1 to n.

Each integer appears exactly once except A which appears twice and B which is missing.

Return A and B.

Note: Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

Note that in your output A should precede B.

Example:

Input:[3 1 2 5 3] 

Output:[3, 4] 

A = 3, B = 4

*/


/*************** APPROACH *************
	We need to find A, which appears twice, and B, which is missing. 
	A can be found out by using a boolean array, while B can be found using SUM.

	If we can modify the vector, we could have solved this by making use of the information that, 
	the numbers are from 1 to n.
	We know that the array index is also from 0 to n-1 or, from 1 to n. 
	We read each element and mark them as -ve. If a number is already -ve, we found A. 
	B can be found using SUM.

 */
	
/*************** SOLUTION *************/

vector<int> Solution::repeatedNumber(const vector<int> &A) 
{
    vector<int> answer;
    vector<bool> present(A.size(), false);
    long long sum = 0;
    for(int i = 0; i < A.size(); i++)
    {
        if(present[A[i]-1])
            answer.push_back(A[i]);//We get A here
        else
            present[A[i]-1] = true;
        sum += A[i]-i-1;//Will get A-B here
    }
    answer.push_back(answer[0]-sum);//We get B as A-(A-B)
    return answer;
}