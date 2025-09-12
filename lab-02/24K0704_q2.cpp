#include <iostream>
using namespace std;

class DynamicGrid {
private:
    int** grid;
    int m, n;

    void allocateGrid(int r, int c) {
        m = r;
        n = c;
        grid = new int*[m];
        for (int i = 0; i < m; i++) {
            grid[i] = new int[n];
        }
    }

public:
    DynamicGrid(int r, int c) {
        allocateGrid(r, c);
    }

    void inputGrid() {
        cout << "Provide values:\n";
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                cin >> grid[i][j];
            }
        }
    }

    void changeSize(int newR, int newC, int fill) {
        int** temp = new int*[newR];
        for (int i = 0; i < newR; i++) {
            temp[i] = new int[newC];
            for (int j = 0; j < newC; j++) {
                if (i < m && j < n)
                    temp[i][j] = grid[i][j];
                else
                    temp[i][j] = fill;
            }
        }

        for (int i = 0; i < m; i++) delete[] grid[i];
        delete[] grid;

        grid = temp;
        m = newR;
        n = newC;
    }

    void doTranspose() {
        int** temp = new int*[n];
        for (int i = 0; i < n; i++) {
            temp[i] = new int[m];
            for (int j = 0; j < m; j++) {
                temp[i][j] = grid[j][i];
            }
        }

        for (int i = 0; i < m; i++) delete[] grid[i];
        delete[] grid;

        grid = temp;
        int t = m;
        m = n;
        n = t;
    }

    void showGrid() {
        cout << "Grid Data:\n";
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int out = grid[i][j];
                if ((i + j) % 2 == 1) out += 2;
                cout << out << " ";
            }
            cout << endl;
        }
    }

    ~DynamicGrid() {
        for (int i = 0; i < m; i++) delete[] grid[i];
        delete[] grid;
    }
};

int main() {
    int r, c;
    cout << "Rows and Columns please: ";
    cin >> r >> c;

    DynamicGrid G(r, c);
    G.inputGrid();
    cout << "Initial Grid:\n";
    G.showGrid();

    G.doTranspose();
    cout << "After Transpose:\n";
    G.showGrid();

    G.changeSize(r + 2, c + 2, -1);
    cout << "After Resize:\n";
    G.showGrid();

    return 0;
}
