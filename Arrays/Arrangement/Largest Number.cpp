/**************** QUESTION **************

Given a list of non negative integers, arrange them such that they form the largest number.

For example:

Given [3, 30, 34, 5, 9], the largest formed number is 9534330.

Note: The result may be very large, so you need to return a string instead of an integer.

*/

/*************** APPROACH *************
	Get all integer values as string for easier comparison. 
	Sort the vector of strings with custom comparison function.
	We need to append one after the other to check which string is more.
 */
	
/*************** SOLUTION *************/

//Custom comparison function to check if appending one to the other becomes largest. 
bool largest(string s1, string s2)
{
    return (s1+s2 > s2+s1);
}

string Solution::largestNumber(const vector<int> &A) 
{
    vector<string> s;
    string answer;
    //Get integers as strings
    for(int i = 0; i < A.size(); i++)
    {
        s.push_back(to_string(A[i]));
    }
    //Sort based on custom comparison function
    sort(s.begin(), s.end(), largest);
    //Finally, append the obtained sorted list to the array
    for(int i = 0; i < s.size(); i++)
    {
        answer.append(s[i]);
        if(s[0] == "0")
            return answer;
    }
    return answer;
}