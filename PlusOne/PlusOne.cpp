/*******************************************

Given a number represented as an array of digits, plus one to the number.

********************************************/

#include <iostream>
#include <vector>

using namespace std;

   vector<int> plusOne(vector<int> &digits) {
        int length = digits.size();
        digits[length-1] += 1;
        for(int i = length - 1; i > 0; i--) {
            if(digits[i] > 9) {
                digits[i] = 0;
                digits[i-1] += 1;
            }
        }
        if(digits[0] == 0 || digits[0] == 10) {
            digits[0] = 1;
            digits.push_back(0);
        }

     return digits;
    }


int main() {

    vector<int> A(1,9);


    for(int i = 0; i < A.size(); i++) {
        cout << A[i] << "    ";
    }

    cout << endl;

    plusOne(A);

    for(int i = 0; i < A.size(); i++) {
        cout << A[i] << "    ";
    }

    return 0;
}
