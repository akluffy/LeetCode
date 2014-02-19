#include <iostream>
#include <string.h>
#include <vector>

using namespace std;

void Zero(int **a, int m, int n);
vector<vector<int> > ZeroVector(vector<vector<int> > a, int m, int n);

int main()
{
    const int m = 10, n = 10;
    int Matrix[m][n] = {
        {1,2,3,4,5,6,7,8,9,10},
        {11,12,13,14,15,16,17,18,19,20},
        {21,22,13,14,15,16,17,18,19,20},
        {31,32,13,14,15,16,17,18,19,20},
        {41,42,13,14,15,16,17,18,19,20},
        {51,52,13,14,0,16,17,18,19,20},
        {61,62,13,14,15,16,17,18,19,20},
        {71,72,13,14,15,16,17,18,19,20},
        {81,82,13,14,15,16,17,18,19,20},
        {91,92,13,14,15,16,17,18,19,20},
    };

    // bulit-in array version.

    int **p = new int *[m];
    for(int i = 0; i < m; i++) {
        p[i] = new int [n];
    }
    for(int j = 0; j < m; j++) {
        for(int k = 0; k < n; k++) {
            *(*(p+j)+k) = Matrix[j][k];
        }
    }

     // vector version

    vector<vector<int> > q;
    for(int i = 0; i < m; i++) {
        vector<int> sub;
        for(int j = 0; j < n; j++) {
            sub.push_back(Matrix[i][j]);
        }
        q.push_back(sub);
    }


     // original Matrix

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            cout << Matrix[i][j] << '\t';
        }
        cout << endl;
    }

     // output for built-in array
    Zero(p, m, n);
    cout << "=================================AFTER================================" << endl;

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            cout << p[i][j] << '\t';
        }
        cout << endl;
    }

    // output for vector
    q = ZeroVector(q, m, n);
    cout << "=================================AFTER================================" << endl;

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            cout << q[i][j] << '\t';
        }
        cout << endl;
    }

    return 0;
}

void Zero(int **a, int m, int n)
{
    bool row[m], col[n];
    memset(row, false, sizeof(row));
    memset(col, false, sizeof(col));
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(a[i][j] == 00) {
                row[i] = true;
                col[j] = true;
            }

        }
    }

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(row[i] == true || col[j] == true) {
                a[i][j] = 0;
            }
        }
    }
}

vector<vector<int> > ZeroVector(vector<vector<int> > a, int m, int n)
{
    bool row[m], col[n];
    memset(row, false, sizeof(row));
    memset(col, false, sizeof(col));
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(a[i][j] == 0) {
                row[i] = true;
                col[j] = true;
            }

        }
    }

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(row[i] == true || col[j] == true) {
                a[i][j] = 0;
            }
        }
    }

    return a;
}

