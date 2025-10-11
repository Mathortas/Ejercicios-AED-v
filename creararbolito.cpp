#include <iostream>
using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;
    Node(int v) : val(v), left(nullptr), right(nullptr) {}
    Node(Node* L, Node* R) : val(L->val + R->val), left(L), right(R) {}
};

template<class T>
struct Cola {
    T A[32];
    T* head = nullptr;
    T* tail = nullptr;
    bool vacio();
    bool lleno();
    bool push(T a);
    bool pop(T& a);
};

template<class T>
bool Cola<T>::vacio() {
    return !head;
}

template<class T>
bool Cola<T>::lleno() {
    return ((head == A && tail == A + 31) || (tail && tail + 1 == head));
}

template<class T>
bool Cola<T>::push(T a) {
    if (lleno()) return false;
    if (!head) {
        head = A;
        tail = A;
        *tail = a;
        return true;
    }
    if (tail == A + 31) tail = A;
    else tail++;
    *tail = a;
    return true;
}

template<class T>
bool Cola<T>::pop(T& a) {
    if (vacio()) return false;
    a = *head;
    if (head == tail) {
        head = nullptr;
        tail = nullptr;
    } else if (head == A + 31) {
        head = A;
    } else {
        head++;
    }
    return true;
}

Node* CrearArbol(int* ini, int* fin) {
    Cola<Node*> C;
    
    for (int* p = ini; p != fin; p++) {
        Node* nuevo = new Node(*p);
        C.push(nuevo);
    }

    
    while (true) {
        Node *a, *b;
        
        if (!C.pop(a)) break;
        if (!C.pop(b)) {
            return a;
        }
        
        Node* nuevo = new Node(a, b);
        C.push(nuevo);

        
        if (C.head == C.tail) {
            Node* raiz;
            C.pop(raiz);
            return raiz;
        }
    }
    return nullptr; // por seguridad
}

void printTree(Node* root, int nivel = 0) {
    if (!root) return;

    for (int i = 0; i < nivel; i++)
        cout << "   "; 

    cout << root->val << "\n";

    
    printTree(root->left, nivel + 1);
    printTree(root->right, nivel + 1);
}





int main() {
    int valores[16] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};
    Node* raiz = CrearArbol(valores, valores + 16);

    cout << "Árbol resultante (inorden):\n";
    printTree(raiz,0);
    return 0;
}
