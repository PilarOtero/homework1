#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> generateMtx (int n){
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

int main () {
    int n;
    cout << "Ingrese el tamaño de la matriz: ";
    cin >> n;

    while (n < 1){
        cout << "Ingrese un valor de n valido (debe ser mayor a 1): ";
        cin >> n;
    }
}
