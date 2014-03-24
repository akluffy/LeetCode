/*******************************************

Longest non-decreasing sequence

Dynamic programming

**********************************************/

#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <limits>

using namespace std;

void calculate_LIS(vector<int> D) {
    vector<vector<int> > L(D.size()); // L stores the longest sub-sequence

    L[0].push_back(D[0]);

    for(int i = 1; i < D.size(); i++) {
        for(int j = 0; j < i; j++) {
            if(D[j] < D[i] && L[j].size() + 1 > L[i].size())
                L[i] = L[j];
        }
        L[i].push_back(D[i]);
    }

    for(vector<vector<int> >::iterator i = L.begin(); i != L.end(); i++) {
        for(vector<int>::iterator j = (*i).begin(); j != (*i).end(); j++) {
            cout << *j << "   ";
        }
        cout << endl;
    }

    return ;
}





int main()
{

    vector<int> a = {5, 3, 4, 8, 7, 2, 1, 9, 6};
    calculate_LIS(a);


    return 0;
}

