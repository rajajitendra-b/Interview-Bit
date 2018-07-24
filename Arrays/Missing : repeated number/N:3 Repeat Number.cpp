/****************,QUESTION,**************

You’re given a read only array of n integers. Find out if any integer occurs more than n/3 times in the array in linear time and constant additional space.

If so, return the integer. If not, return -1.

If there are multiple solutions, return any one.

Example :

Input : [1 2 3 1 1]
Output : 1 
1 occurs 3 times which is more than 5/3 times. 


/***************,APPROACH,*************
As the question says N/3 repeat, the N can be changed by removing 3 distinct elements. 
Which means, if I'm taking distinct elements out of N, we just need to find out (N-3)/3 repeat number (same as N/3 repeat number)
In other words, answer doesn't change if we remove 3 distinct elements. 
To implement this, we take 2 variables first and second, with their corresponding counts firstC and secondC.
Whenever a new element is seen, it must be either of them. If not, we decrement both of them so that, new one can b accommodated.

,*/
	
/***************,SOLUTION,*************/

int Solution::repeatedNumber(const vector<int> &A) 
{
    int first = INT_MIN, second = INT_MIN;
    int nBy3 = (A.size())/3;
    int firstC = 0, secondC = 0;
    for(auto a : A)
    {
        if(a == first)
            firstC++;
        else if(a == second)
            secondC++;
        else if (!firstC)
        {
            first = a;
            firstC++;
        }
        else if (!secondC)
        {
            second = a;
            secondC++;
        }
        else 
        {
            firstC--;
            secondC--;
        }
        //cout<<firstC<<" "<<first%1000<<" "<<secondC<<" "<<second%1000<<endl;
    }

    {
        firstC = 0, secondC = 0;
        for(auto a : A)
        {
            if(first == a)
                firstC++;
            if(second == a)
                secondC++;
        }
        if(firstC > nBy3)
            return first;
        if(secondC > nBy3)
            return second;
        return -1;
    }
}
