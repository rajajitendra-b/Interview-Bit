/**************** QUESTION **************

For Given Number N find if its COLORFUL number or not

Return 0/1

COLORFUL number:

A number can be broken into different contiguous sub-subsequence parts. 
Suppose, a number 3245 can be broken into parts like 3 2 4 5 32 24 45 324 245. 
And this number is a COLORFUL number, since product of every digit of a contiguous subsequence is different
Example:

N = 23
2 3 23
2 -> 2
3 -> 3
23 -> 6
this number is a COLORFUL number since product of every digit of a sub-sequence are different. 

Output : 1

*/


/*************** APPROACH *************

Consider the following number
3245
All combinations to find the uniqueness are expanded for observation.
3 32 324 3245
2 24 245
4 45
5

On observation, we find that we need to find the product of all combinations and check it there is any repetition.
Checking repitition can be done using a hash map.

 */
	
/*************** SOLUTION *************/

int Solution::colorful(int num) 
{
    map<int, bool> m;
    vector<int> nums;
    int A = num;
    Get all the numbers in an array
    while(A)
    {
    	//This will get the numbers in reverse order to a vector
        nums.push_back(A%10);
        A /= 10;
    }
    //Check all combinations using 2 loops
    for(int i = 0; i < nums.size(); i++)
    {
        int prod = 1;
        for(int j = i; j < nums.size(); j++)
        {
            prod *= nums[j];
            //Check if the combination already exists in hashmap
            auto it = m.find(prod);
            if(it != m.end())
            {
                return 0; //If already exists, not a colorful number
            }
            m.insert(make_pair(prod, true));
        }
    }
    //No combinations exists already. So, this is a colorful number
    return 1;
}
