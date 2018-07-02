/**************** QUESTION **************

Given a read only array of n + 1 integers between 1 and n, find one number that repeats in linear time using less than O(n) space and traversing the stream sequentially O(1) times.

Sample Input:

[3 4 1 4 1]
Sample Output:

1
If there are multiple possible answers ( like in the sample case above ), output any one.

If there is no duplicate, output -1

*/


/*************** APPROACH *************
	Sum of all numbers from 1 to n being n(n-1)/2, say SUM
	If one of them is repeated, we can substract the elements sum from SUM gives the repeated number
 */
	
/*************** SOLUTION *************/

int Solution::repeatedNumber(const vector<int> &A) 
{
    long long n = A.size();
    long long sum = (n * (n-1))/2;
    for(auto a : A)
    {
        sum -= a;
    }
    if(!sum)
        return -1;
    return abs(sum);
}
