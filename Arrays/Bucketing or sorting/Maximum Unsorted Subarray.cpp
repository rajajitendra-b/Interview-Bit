/**************** QUESTION **************

You are given an array (zero indexed) of N non-negative integers, A0, A1 ,…, AN-1.
Find the minimum sub array Al, Al+1 ,…, Ar so if we sort(in ascending order) that sub array, then the whole array should get sorted.
If A is already sorted, output -1.

Example :

Input 1:

A = [1, 3, 2, 4, 5]

Return: [1, 2]

Input 2:

A = [1, 2, 3, 4, 5]

Return: [-1]
In the above example(Input 1), if we sort the subarray A1, A2, then whole array A should get sorted.

*/

/*************** APPROACH *************
We need to find maximum unsorted sub array, which, when sorted, makes the entire array sorted. 
Do do so, we can find the first and last locations in unsorted array. 
However, we are not complete yet. 
	Reason: If we take an example array as 1 2 4 6 3 7 9
	Finding deviation of sortedness gives indices 3 and 4 as limits (numbers 6-3 and 3-7 are deviations).
	But, they are not the maximum unsorted array. 
To get that, we find the minimum of maximum of the obtained indices and find their corresponding locations to get the answer
 */
	
/*************** SOLUTION *************/

vector<int> Solution::subUnsort(vector<int> &A) 
{
    vector<int> answer;
    int mini = INT_MAX, maxi = INT_MIN;
    int start = 0, end = A.size()-1;
    //Find the indices of deviations from sortedness
    while(start < end)
    {
        if(start <= end && A[start] <= A[start+1])
            start++;
        else if(end >= start && A[end] >= A[end-1])
            end--;
        else
            break;
    }
    //From obtained sub array, find the minimum and maximum to get the max unsorted subarray
    for(int i = start; i <=end; i++)
    {
        mini = min(mini, A[i]);
        maxi = max(maxi, A[i]);
    }
    //Find the starting position of unsortedness
    for(int i = 0; i <=start; i++)
    {
        if(A[i] > mini)
        {
            start = i; 
            break;
        }
    }
    //Find the ending position of unsortedness
    for(int i = A.size()-1; i >=end; i--)
    {
        if(A[i] < maxi)
        {
            end = i; 
            break;
        }
    }
    //Get the answer from obtained indices
    if(start == end)
        answer.push_back(-1);
    else
        answer.insert(answer.end(), {start, end});
    return answer;
}