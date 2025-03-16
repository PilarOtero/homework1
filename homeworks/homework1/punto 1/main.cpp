#include <iostream>
#include "main.h"

vector<vector<int>> createMtx (int n){
    vector<vector<int>> mtx (n, vector<int>(n, 0));

    // Determino que el valor de la posicion [0][0] es 1
    int initial_value = 1;

    for (int i = 0; i < n; i ++){
        for (int j = 0; j < n; j ++){
            mtx[i][j] = initial_value;
            initial_value ++;
        }
    }
    return mtx;
}

void printMtx (vector<vector<int>> matrix, int n) { 
    //Aprovechando que la matriz va en orden creciente, imprimo los valores desde Mtx[n][n] hasta Mtx[0][0]
    for (int i = n * n - 1; i >= 0; i --){
        int row = i / n;
        int column = i % n;

        cout << "M[" << row << "][" << column << "] = " << matrix[row][column] << endl;
    }
}

int main () {
    int n;
    cout << "Ingrese el tamaño de la matriz: ";
    cin >> n;

    while (n < 1){
        cout << "Ingrese un valor de n valido (debe ser mayor a 1): ";
        cin >> n;
    }

    vector<vector<int>> matrix = createMtx(n);
    printMtx(matrix, n);

    return 0;
}
