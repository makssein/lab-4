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
    int n,m,matrix[N][M],min,str,stolb;

    ifstream in ("/Users/maksimsein/CLionProjects/lab-4-3/input.txt");
    ofstream out ("/Users/maksimsein/CLionProjects/lab-4-3/output.txt");
    in >> n >> m;

    for(int i=0; i < n; i++){
        for(int j=0; j<m; j++){
            in >> matrix[i][j];
        }
    }
    min = matrix[0][0];
    for(int i=0; i < n; i++){
        for(int j=0; j<m; j++){
            if(matrix[i][j] < min){
                stolb = j;
            }
        }
    }
    for(int i = 0; i<n; i++){
        if(matrix[i][stolb] < 0){
           matrix[i][stolb] = 0;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            out << matrix[i][j] << " ";
        }
        out << endl;
    }



}
