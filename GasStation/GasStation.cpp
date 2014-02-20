/*******************************************

There are N gas stations along a circular route,
where the amount of gas at station i is gas[i].

You have a car with an unlimited gas tank and it costs cost[i] of gas
to travel from station i to its next station (i+1). You begin the
journey with an empty tank at one of the gas stations.

Return the starting gas station's index if you can travel
around the circuit once, otherwise return -1.

Note:
The solution is guaranteed to be unique.

********************************************/

#include <iostream>
#include <vector>

using namespace std;

// Direct method. Regard every element as the start point and then do the loop to check
int canCompleteCircuit2(vector<int> &gas, vector<int> &cost) {

    int n = gas.size();
    int remainGas = 0;
    // traverse the gas station, use every i as the start point
    for(int i = 0; i < n; i++) {
        int checkedIndex = i;
        int ct = 1;
        remainGas = 0;
        while(ct <= n) {
            if(remainGas + gas[checkedIndex%n] >= cost[checkedIndex%n]) {
                if(ct == n) return i;
                remainGas += gas[checkedIndex%n] - cost[checkedIndex%n];
                checkedIndex++;
                ct++;
            }
            else {
                i = checkedIndex; // don't need to check these points as the start point, so just skill them.
                break;
            }

        }
    }

    return -1;
}

// Another mathematics method
int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {

    int n = gas.size();

/*
    vector<int> diff(n);
    for(int i = 0; i < n; i++) {
        diff[i] = gas[i] - cost[i];
    }
*/
    int remainGas = 0, sum = 0, startPoint = 0;

    for(int i = 0; i < n; i++) {
        remainGas += gas[i] - cost[i]; //最终remainGas必须大于0
        sum += gas[i] - cost[i]; // sum小于0, 那sum之前的gasstation都不能作为startpoint
        if(sum < 0) {
            startPoint = i + 1;
            sum = 0;
        }
    }

    if(remainGas >= 0) return startPoint;
    else return -1;
}




int main() {

    vector<int> gas1 = {10, 10, 10, 10, 10, 10};
    vector<int> cost1 = {9, 9, 9 ,9, 9, 9};

    vector<int> gas2 = {10, 10, 10, 10, 10, 10};
    vector<int> cost2 = {11, 11, 11, 8, 8, 10};

    vector<int> gas3 = {10, 10, 10, 10, 10, 10};
    vector<int> cost3 = {11, 11, 11, 11, 11, 5};

    vector<int> gas4 = {10, 10, 10, 10, 10, 10};
    vector<int> cost4 = {11, 11, 11, 11, 11, 11};

    int answer[4];
    answer[0] = canCompleteCircuit(gas1, cost1);
    answer[1] = canCompleteCircuit(gas2, cost2);
    answer[2] = canCompleteCircuit(gas3, cost3);
    answer[3] = canCompleteCircuit(gas4, cost4);

    for(int i = 0; i < 4; i++) {
        cout << "The Answer is : " << answer[i] << endl;
    }

    return 0;
}
