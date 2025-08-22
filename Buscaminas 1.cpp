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

	int marcas[8] = {-11, -10, -9, -1, 1, 9, 10, 11};

	for (int *p = base; p < fin; p++) {
		if (*p < 0) {
			int col = (p - base) % 10;
			for (int* mar = marcas; mar < marcas+8; mar++) {
                
                //Columna izquierda
				if (col == 0 && (*(mar) == -1 || *(mar) == -11 || *(mar) == 9))
					continue;
				//Columna derecha
				if (col == 9 && (*(mar) == 1 || *(mar) == -9 || *(mar) == 11))
					continue;

				p += *(mar);
				
				if (*p >= 0)
					(*p)++;
				
				p -= *(mar);
			}
		}
	}
	
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
