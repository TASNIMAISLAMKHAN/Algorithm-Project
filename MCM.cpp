#include <bits/stdc++.h>
using namespace std;

//clear the console screen
void clearScreen() {
#ifdef _WIN32
   system("cls");
#else
    system("clear");
#endif
}

// For clean format
void printMatrix(vector<vector<int>>& matrix) {
    int rows = matrix.size();
    int cols = matrix[0].size();

    //spacing
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << setw(6) << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

// MCM visualization
void matrixChainOrder(vector<int>& dims) {
    int n = dims.size() - 1;
    vector<vector<int>> m(n, vector<int>(n, 0));
    vector<vector<int>> s(n, vector<int>(n, 0));


    for (int l = 2; l <= n; l++) {
        for (int i = 0; i < n - l + 1; i++) {
            int j = i + l - 1;
            m[i][j] = INT_MAX;


            for (int k = i; k < j; k++) {
                int q = m[i][k] + m[k+1][j] + dims[i] * dims[k+1] * dims[j+1];

                if (q < m[i][j]) {
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }


            clearScreen();


            cout << "Processing matrix chain from row " << i << " to column " << j << endl;


            printMatrix(m);


            this_thread::sleep_for(chrono::milliseconds(1000));
        }
    }


    cout << "\nMinimum number of multiplications: " << m[0][n-1] << endl;
}

int main() {
    int n;


    cout << "Enter the number of matrices: ";
    cin >> n;

    vector<int> dims(n + 1);


    cout << "Enter the dimensions of the matrices (n+1 values): ";
    for (int i = 0; i <= n; i++) {
        cin >> dims[i];
    }

    cout << "\nMatrix Chain Order Visualization:\n";
    matrixChainOrder(dims);

    return 0;
}
