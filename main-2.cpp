/* Ввести последовательность натуральных чисел {Aj}j=1...n (n<=1000). 
Упорядочить последовательность по неубыванию первой цифры числа, 
числа с одинаковыми первыми цифрами дополнительно упорядочить по 
неубыванию наибольшей цифры числа, числа с одинаковыми первыми 
цифрами и одинаковыми наибольшими цифрами дополнительно упорядочить 
по неубыванию самого числа.

Сеин Максим
*/
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
    ifstream in("input.txt");
    ofstream out("output.txt");
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

                    if (d<=a && d!=a) {
                        std::swap(matrix[i][j], matrix[k][p]);
                    }
                    else if (d==a && maxa >= maxd) {
                        std::swap(matrix[i][j], matrix[k][p]);
                    }
                    else if (d==a && maxd==maxa && matrix[k][p] <= matrix[i][j]) {
                        std::swap(matrix[k][p], matrix[i][j]);
                    }
                }
                maxa=0;
                maxd=0;
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
