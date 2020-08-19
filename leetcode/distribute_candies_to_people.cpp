/*
We distribute some number of candies, to a row of n = num_people people in the following way:

We then give 1 candy to the first person, 2 candies to the second person, and so on until we give n candies to the last person.

Then, we go back to the start of the row, giving n + 1 candies to the first person, n + 2 candies to the second person, and so on until we give 2 * n candies to the last person.

This process repeats (with us giving one more candy each time, and moving to the start of the row after we reach the end) until we run out of candies.  The last person will receive all of our remaining candies (not necessarily one more than the previous gift).

Return an array (of length num_people and sum candies) that represents the final distribution of candies.
*/
class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        int k = (sqrt(8*(long)candies+1)-1)/(2*num_people);
        int c = k*num_people;
        int a = c*(k-1)/2;
        vector<int> res(num_people, a);
        candies -= (c*(c+1)/2);
        for(int i=0; i<num_people; ++i){
            res[i] += k*(i+1);
        }
        int i=0;
        c++;
        while(candies>0){
            res[i]+=min(candies,c);
            candies-=c;
            i++;
            c++;
        }
        return res;
    }
};
