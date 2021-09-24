#include <iostream>
#include <fstream>

#define N 100
#define M 100

using std::cin;
using std::cout;
using std::ifstream;
using std::ofstream;
using std::endl;

int main() {
    int n, m, matrix[N][M], b, a, c, d, maxd, maxa;
    ifstream in("/Users/maksimsein/CLionProjects/lab-4-2/input.txt");
    ofstream out("/Users/maksimsein/CLionProjects/lab-4-2/output.txt");
    in >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            in >> matrix[i][j];
        }
    }


    for (int k = 0; k < n; k++) {
        for (int p = 0; p < m; p++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    c = matrix[k][p];
                    while (c > 0) {
                        d = c % 10;
                        c = c / 10;
                        if(d > maxd) maxd=d;
                    }
                    b = matrix[i][j];
                    while (b > 0) {
                        a = b % 10;
                        b = b / 10;
                        if(a > maxa) maxa=a;
                    }

                    if (d < a){
                        std::swap(matrix[i][j], matrix[k][p]);
                    } else if(a > d){
                        std::swap(matrix[k][p],matrix[i][j]);
                    }
                    else if (d==a){
                        if(maxa<=maxd){
                            std::swap(matrix[i][j], matrix[k][p]);
                        }
                        if(maxa>=maxd){
                            std::swap(matrix[k][p],matrix[i][j]);
                        }
                    } else if (matrix[i][j] >= matrix[k][p]) {
                        std::swap(matrix[k][p], matrix[i][j]);
                    }
                }
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            out << matrix[i][j] << " ";
        }
        out << endl;
    }

}
