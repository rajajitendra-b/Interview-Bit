/**************** QUESTION **************

A hotel manager has to process N advance bookings of rooms for the next season. 
His hotel has K rooms. 
Bookings contain an arrival date and a departure date. 
He wants to find out whether there are enough rooms in the hotel to satisfy the demand. 
Write a program that solves this problem in time O(N log N) .

Input:


First list for arrival time of booking.
Second list for departure time of booking.
Third is K which denotes count of rooms.

Output:

A boolean which tells whether its possible to make a booking. 
Return 0/1 for C programs.
O -> No there are not enough rooms for N booking.
1 -> Yes there are enough rooms for N booking.
Example :

Input : 
        Arrivals :   [1 3 5]
        Departures : [2 6 8]
        K : 1

Return : False / 0 

At day = 5, there are 2 guests in the hotel. But I have only one room. 

*/

/*************** APPROACH *************
	Sort arrival and departures irrespective of the correlation. 
	On each day
		i) Check if anybody arrived or not. If so, assign a room. 
		ii) Check if anybody is leaving. If so, vacate the room. 
		iii) Check if number of rooms assigned are more than the available rooms. If so, booking is not possible
	If all bookings are possible on each day, enough rooms are available to satisfy the demand
 */
	
/*************** SOLUTION *************/
bool Solution::hotel(vector<int> &arrive, vector<int> &depart, int K) 
{
	//Sort arrival and departures irrespective of the correlation. 
    sort(arrive.begin(), arrive.end());
    sort(depart.begin(), depart.end());

    int n = depart[depart.size()-1];
    int arr = 0, dep = 0;
    int bookings = 0;
    //Check all the days, one by one if we are able to meet the demand.
    for(int days = 1; days <= n; days++)
    {
    	//Check if anybody arrived or not. If so, assign a room (bookings++)
        while(arr < arrive.size() && arrive[arr]<=days)
        {
            bookings++;
            arr++;
        }
    	//Check if anybody is leaving. If so, vacate the room (bookings--)
        while(dep < depart.size() && depart[dep]<=days)
        {
            bookings--;
            dep++;
        }
        //Check if number of rooms assigned are more than the available rooms. 
        if(bookings > K)
        	//If so, booking is not possible
            return 0;
    }
    //If all bookings are possible on each day, enough rooms are available to satisfy the demand
    return 1;
}