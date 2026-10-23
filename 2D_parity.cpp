#include <iostream>
using namespace std;

int main() {
    int a[20][20] = {}, m, n, r, c, x = -1, y = -1;
    cout << "Enter rows and columns (1-19): ";
    cin >> m >> n;
    if (m < 1 || m > 19 || n < 1 || n > 19) return 0;

    cout << "Enter data bits:\n";
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
            a[i][n] ^= a[i][j];
            a[m][j] ^= a[i][j];
            a[m][n] ^= a[i][j];
        }

    cout << "Enter error row and column (1-based): ";
    cin >> r >> c;
    if (r < 1 || r > m || c < 1 || c > n) return 0;
    a[r-1][c-1] ^= 1;

    for (int i = 0; i <= m; i++) {
        int p = 0;
        for (int j = 0; j <= n; j++) p ^= a[i][j];
        if (p) x = i;
    }
    for (int j = 0; j <= n; j++) {
        int p = 0;
        for (int i = 0; i <= m; i++) p ^= a[i][j];
        if (p) y = j;
    }

    if (x != -1 && y != -1) {
        cout << "Error at: " << x+1 << " " << y+1 << "\n";
        a[x][y] ^= 1;
    }

    cout << "Corrected data:\n";
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) cout << a[i][j] << " ";
        cout << "\n";
    }
}