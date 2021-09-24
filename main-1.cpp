/*
Дана последовательность натуральных чисел {aj}j=1...n (n<=10000). 
Если в последовательности есть хотя бы одно число, сумма цифр 
которого равна 14, упорядочить последовательность по неубыванию.

Сеин Максим

*/
#include <iostream>
#include <fstream>
using std::cout;
using std::ifstream;
using std::ofstream;
using std::cin;
using std::endl;
#define N 100
#define M 100

int main() {
    ifstream in("input.txt");
    ofstream out("output.txt");
    int matrix[N][M];
    int n,m;
    int sum, a, b;
    bool check;
    sum=0;
    in >> n >> m;
    for (int i=0; i<n; i++) {
        for (int j = 0; j < m; j++) {
            in >> matrix[i][j];
        }
    }
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            b = matrix[i][j];
            while (b > 0){
                a = b%10;
                sum+=a;
                b=b/10;
            }
            if(sum==14) {
                check = true;
                break;
            }
            sum=0;
        }
        if(check) break;
    }
    if(check){
        for (int k = 0; k < n; k++)
            for (int p = 0; p < m; p++)
                for (int i = 0; i < n; i++)
                    for (int j = 0; j < m; j++)
                        if (matrix[i][j] > matrix[k][p])
                            std::swap (matrix[i][j],matrix[k][p]);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                out << matrix[i][j] << " ";
            }
            out << endl;
        }
    }
    else {
        out << "Необходимое условие не выявлено";
    }


    return 0;
}
