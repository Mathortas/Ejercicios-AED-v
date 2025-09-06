#include <iostream>
using namespace std;

const int N = 10;
int movs[4] = {1, 10, -10, -1}; 

void print(char* A) {
    for(char* i = A; i < A + N*N; i++) {
        cout << *i << " | ";
        if(((i + 1 - A) % N) == 0) {
            cout << "\n---------------------------------------" << endl;
        }
    }
    cout << endl;
}

void laberinto(char* A) {
    char* ptr = A;

    while(true) {
        char* siguiente = nullptr;
        for(int* p = movs; p < movs+4 ; p++) {
            char* candidato = ptr + *(p);
            if(*candidato == ' ' || *candidato == 'B') {
                siguiente = candidato;
                break;
            }
        }
        if(siguiente != nullptr) {
            if(*ptr != 'A' && *ptr != 'B') {
                *ptr = '.';
            }
            
            ptr = siguiente;
            
            if(*ptr == 'B') {
                cout << "¡Meta encontrada!" << endl;
                break;
            }
        } else {
            //Volver sobre sus pasos
            if(*ptr != 'A') 
                *ptr = '_'; 
            bool retrocedio = false;
            for(int* p = movs; p < movs+4 ; p++) {
                char* candidato = ptr + *(p);
                if(*candidato == '.') {
                    ptr = candidato; // volver a esa posición
                    retrocedio = true;
                    break;
                }
            }
            if(!retrocedio) {
                cout << "Se quedo sin opciones" << endl;
                break;
            }
        }
    }
}

int main() {
    char A[N][N] = {
        {'A','X',' ',' ',' ',' ',' ',' ',' ','X'},
        {' ','X',' ',' ',' ',' ','X','X',' ','X'},
        {' ','X',' ','X','X',' ','X','X','X','X'},
        {' ','X',' ','X',' ',' ','X',' ',' ',' '},
        {' ',' ',' ','X',' ',' ',' ',' ','X','X'},
        {' ','X','X','X','X','X',' ',' ','X',' '},
        {' ',' ',' ',' ','X',' ',' ',' ',' ',' '},
        {' ','X','X',' ','X',' ',' ','X','X','X'},
        {'X','X',' ',' ','X',' ',' ','X',' ','X'},
        {' ',' ',' ','X','X',' ',' ',' ',' ','B'}
    };
    
    cout << "Laberinto inicial:" << endl;
    print(*A);
    
    laberinto(*A);
    
    cout << "Laberinto final:" << endl;
    print(*A);
    
    return 0;
}
