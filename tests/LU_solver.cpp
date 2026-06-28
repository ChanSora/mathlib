#include <iostream>
const int MAXN = 1010;
const double eps = 1e-6;
int n;
double mat[MAXN][MAXN], Lmat[MAXN][MAXN], Rmat[MAXN][MAXN], Pmat[MAXN][MAXN];

void LU_solve() {
    for (int j = 1; j <= n; j++) {
        Pmat[j][j] = 1;
        for (int k = 1; k <= n; k++) {
            Rmat[j][k] = mat[j][k];
        }
    }
    for (int i = 1; i <= n; i++) {
        if (Rmat[i][i] == 0) {
            int swap_line = i, value = fabs(Rmat[i][i]);
            for (int j = i + 1; j <= n; j++) {
                if (fabs(Rmat[j][i]) > value) {
                    swap_line = j;
                }
            }
            if (swap_line == i) return;
            std::swap(Rmat[i], Rmat[swap_line]);
            std::swap(Pmat[i], Pmat[swap_line]);
            std::swap(Lmat[i], Lmat[swap_line]);   
        }
        for (int j = i + 1; j <= n; j++) {
            double ratio = Rmat[j][i] / Rmat[i][i];
            std::cout << ratio << '\n';
            Lmat[j][i] = ratio;
            for (int k = i; k <= n; k++) {
                Rmat[j][k] = Rmat[j][k] - ratio * Rmat[i][k];
            }
        }
    }
    for (int i = 1; i <= n; i++) Lmat[i][i] = 1;
} 

int main() {
    std::cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            std::cin >> mat[i][j];
        }
    }
    LU_solve();
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            std::cout << Pmat[i][j] << ' ';
        }
        std::cout << '\n';
    }
    std::cout << '\n';
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            std::cout << Lmat[i][j] << ' ';
        }
        std::cout << '\n';
    }
    std::cout << '\n';
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            std::cout << Rmat[i][j] << ' ';
        }
        std::cout << '\n';
    }
    return 0;
}