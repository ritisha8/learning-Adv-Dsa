#include<bits/stdc++.h>
using namespace std;
bool isValidInitialGrid(vector<vector<int>>& v) {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (v[i][j] != 0) {
                int num = v[i][j];
                v[i][j] = 0; // Temporarily empty the cell
                if (!check(v, i, j, num)) {
                    cout << "Invalid initial grid at (" << i << ", " << j << ")" << endl;
                    return false;
                }
                v[i][j] = num; // Restore the cell
            }
        }
    }
    return true;
}

int main() {
    vector<vector<int>> v(9, vector<int>(9, 0));
    // Pre-filled values setup
    v[0][0] = 5; v[0][1] = 3; v[1][0] = 6; v[2][1] = 9; v[2][2] = 8;
    v[0][4] = 7; v[1][3] = 1; v[1][4] = 9; v[1][5] = 5; v[2][7] = 6;
    v[3][0] = 8; v[4][0] = 4; v[5][0] = 7; v[4][3] = 8; v[4][5] = 3;
    v[3][4] = 6; v[5][4] = 2; v[4][8] = 3; v[5][8] = 1; v[6][8] = 6;
    v[6][2] = 6; v[7][4] = 4; v[7][5] = 1; v[7][6] = 9; v[8][5] = 8;
    v[6][6] = 2; v[6][7] = 8; v[7][8] = 5; v[8][8] = 9; v[8][7] = 7;

    // Check if initial grid is valid
    if (!isValidInitialGrid(v)) {
        cout << "Initial grid is invalid. Please correct it." << endl;
        return -1;
    }



    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
