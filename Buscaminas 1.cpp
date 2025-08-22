#include <iostream>
using namespace std;

int main() {
    int tablero[10][10] = {
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,-1,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,-1,0,0,0,0,0,-1},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,-1,0,0,0},
        {0,0,0,0,0,0,-1,0,-1,-1},
        {0,0,0,0,0,0,0,0,0,0}
    };

    int *base = *tablero;
    int *fin  = base + 100;


    for (int *p = base; p < fin; p++) {
        if (*p < 0) {
            int marcas[8] = {-11, -10, -9, -1, 1, 9, 10, 11};
            for (int k = 0; k < 8; k++) {
                int *vecino = p + marcas[k];
                
                if ((p - base) % 10 == 0 && (marcas[k] == -1 || marcas[k] == -11 || marcas[k] == 9))
                    continue;
                    
                if ((p - base) % 10 == 9 && (marcas[k] == 1 || marcas[k] == -9 || marcas[k] == 11))
                    continue;
                    
                if (*vecino >= 0) 
                (*vecino)++;
            }
        }
    }

    // Imprimir resultado
    int contador = 0;
    
    for (int *p = base; p < fin; p++) {
        if (*p < 0) cout << "* ";
        else cout << *p << " ";
        contador++;
        if (contador == 10) { 
            cout << endl; 
            contador = 0; 
        }
    }
}
