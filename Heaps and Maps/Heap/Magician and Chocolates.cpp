/**************** QUESTION **************

Given N bags, each bag contains Ai chocolates. There is a kid and a magician. In one unit of time, kid chooses a random bag i, eats Ai chocolates, then the magician fills the ith bag with floor(Ai/2) chocolates.

Given Ai for 1 <= i <= N, find the maximum number of chocolates kid can eat in K units of time.

For example,

K = 3
N = 2
A = 6 5

Return: 14
At t = 1 kid eats 6 chocolates from bag 0, and the bag gets filled by 3 chocolates
At t = 2 kid eats 5 chocolates from bag 1, and the bag gets filled by 2 chocolates
At t = 3 kid eats 3 chocolates from bag 0, and the bag gets filled by 1 chocolate
so, total number of chocolates eaten: 6 + 5 + 3 = 14

Note: Return your answer modulo 10^9+7

/*************** APPROACH *************

To maximize the number of chocolates to be eaten everyday, one has to choose the maximum number.
The best data structure to use here is max heap. 
Build a max heap with the array elements. 
On each day
	a) Kid's operation: Get the maximum number and add it to the answer. Remove the max number from the max heap
	b) Magician's operation: Fill half the number (floor) of chocolates ate. Push half the max element to the heap and heapify
 */
	
/*************** SOLUTION *************/

int Solution::nchoc(int A, vector<int> &B) 
{
    long long chocolatesAte = 0;
    int todaysChocolatesToEat = 0;
    make_heap(B.begin(), B.end());
    for(int i = 0; i < A; i++)
    {
    	//Remove the max number from the max heap to eat for today -- Kid's operation
        todaysChocolatesToEat = B.front();
        chocolatesAte = (chocolatesAte+todaysChocolatesToEat)%1000000007;
        /* Use the below debug print to understand further
         * cout<<"Ate "<<todaysChocolatesToEat<<" on Day - "<<i+1<<" Total: "<<chocolatesAte<<endl;
         */
        pop_heap(B.begin(), B.end()); B.pop_back();
        //Push half the chocolates ate today to the heap and heapify -- Magician's operation
        todaysChocolatesToEat /= 2;
        B.push_back(todaysChocolatesToEat); 
        push_heap(B.begin(), B.end());
    }
    return (chocolatesAte%1000000007);
}