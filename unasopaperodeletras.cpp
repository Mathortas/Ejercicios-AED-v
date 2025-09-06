#include <iostream>
using namespace std;

const int N = 11;

int encontrar(char* palabra, char* matriz) {
    int longitud = 0;
    for (char* p = palabra; *p; p++) 
        longitud++;
    int repeticiones = 0;

    // Recorremos toda la matriz
    for (char* pos = matriz; pos < matriz + N * N; pos++) {
        int pos2 = pos - matriz;   
        int fila = pos2 / N;
        int col  = pos2 % N;

        // --- derecha ---
        if (col + longitud <= N) {
            char* temp = pos;
            char* p = palabra;
            while (*p && *p == *temp) {
                p++;
                temp++;
            }
            if (!*p) 
                repeticiones++;
        }

        // --- izquierda ---
        if (col - longitud + 1 >= 0) {
            char* temp = pos;
            char* p = palabra;
            while (*p && *p == *temp) {
                p++;
                temp--;
            }
            if (!*p) 
                repeticiones++;
        }

        // --- abajo ---
        if (fila + longitud <= N) {
            char* temp = pos;
            char* p = palabra;
            while (*p && *p == *temp) {
                p++;
                temp += N;
            }
            if (!*p) 
                repeticiones++;
        }

        // --- arriba ---
        if (fila - longitud + 1 >= 0) {
            char* temp = pos;
            char* p = palabra;
            while (*p && *p == *temp) {
                p++;
                temp -= N;
            }
            if (!*p) 
                repeticiones++;
        }
    }

    return repeticiones;
}

int main() {
    char matriz[N][N]{
        {"TPPAPTPIPT"},
        {"OPATAPOZOJ"},
        {"SATATOTAZI"},
        {"ATAPADATOS"},
        {"PATANOPOTN"},
        {"TAAPATIPAP"},
        {"RRNADOTADO"},
        {"EDNTAPOTAT"},
        {"NIIATITAPA"},
        {"PSSNTTTPAP"}
    };

    char palabra[] = "PATAN";
    int x = encontrar(palabra, *matriz);
    cout << "El numero de veces es: " << x << endl;
    return 0;
}
