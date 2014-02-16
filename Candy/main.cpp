/*******************************************

There are N children standing in a line. Each child is assigned a rating value.

You are giving candies to these children subjected to the following requirements:

Each child must have at least one candy.
Children with a higher rating get more candies than their neighbors.
What is the minimum candies you must give?

********************************************/

#include <iostream>
#include <vector>

using namespace std;

int candy(vector<int> &ratings) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int count = 0;
        vector<int> candies(ratings.size(), 1);
        for (int i = 0;i < ratings.size() - 1;++i) {
            if (ratings[i + 1] > ratings[i]) candies[i + 1] = candies[i] + 1;
        }
        for (int i = ratings.size() - 1;i >= 0;--i) {
            if (ratings[i - 1] > ratings[i])
                candies[i - 1] = max(candies[i - 1], candies[i] + 1);
                count += candies[i];
        }

        return count;
}


int main() {

    vector<int> A;


    for(int i = 0; i < 1; i++) {
        A.push_back(i);
    }


    cout << candy(A) << endl;

    return 0;
}
