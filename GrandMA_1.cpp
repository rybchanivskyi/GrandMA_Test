#include <iostream>
#include <stdlib.h>
#include<time.h>
using namespace std;


int main() {
    int N , f, c, temp;
    cout << "Enter value of N = ";
    cin >> N;
    int matrix[N][N];
    f = N / 2;
    c = (N + 1) / 2;
    srand(time(NULL));

    cout<<"\nInitial matrix:\n";
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            matrix[i][j] = rand () % 10000 + (rand() % 9 + 1) * 10000;
            cout << matrix[i][j] << ' ';
        }
        cout << '\n';
    }

    for (int x = 0; x < f; ++x) {
        for (int y = 0; y < c; ++y) {
            temp = matrix[x][y];
            matrix[x][y] = matrix[N-1-y][x];
            matrix[N-1-y][x] = matrix[N-1-x][N-1-y];
            matrix[N-1-x][N-1-y] = matrix[y][N-1-x];
            matrix[y][N-1-x] = temp;
        }
    }
    cout << "\nFinal matrix : \n";
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cout << matrix[i][j] << ' ';
        }
        cout << '\n';
    }
    system("pause");
    return 0;
}
