#include "functions.cpp"

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
