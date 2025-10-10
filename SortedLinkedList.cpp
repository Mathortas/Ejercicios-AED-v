#include <iostream>
using namespace std;
struct Node{
    int val;
    Node* next;
    Node(int x) : val(x), next(nullptr) {};
};

class SortedLinkedList{
    public:
        SortedLinkedList();
        ~SortedLinkedList();
        bool find(Node** &lookingpointer, int x);
        bool ins(int x);
        bool rem(int x);
        void print();
        Node* head;
};


SortedLinkedList::SortedLinkedList(){
    head = 0;
}
SortedLinkedList::~SortedLinkedList(){
    Node* temp = head;
    while(head){
        head = head->next;
        delete temp;
        temp = head;
    }
}

bool SortedLinkedList::find(Node** &lookingpointer, int x){
    while(*lookingpointer && (*lookingpointer)->val < x){
        (lookingpointer) = &((*lookingpointer)->next);
    }
    return *lookingpointer && (*lookingpointer)->val == x;
}

bool SortedLinkedList::ins(int x){
    Node** lookingpointer = &head;
    if (find(lookingpointer, x)){
        return 0;
    }
    else{
        Node* temp = *lookingpointer;
        *lookingpointer = new Node(x);
        (*lookingpointer)->next = temp;
        return 1;
    }
}

bool SortedLinkedList::rem(int x){
    Node** lookingpointer = &head;
    if(!find(lookingpointer,x)){
        return 0;
    }
    else{
        Node* temp1 = *lookingpointer;
        *lookingpointer = (*lookingpointer)->next;
        delete temp1;
        return 1; 
    }
}

void SortedLinkedList::print(){
    Node** lookingpointer = &head;
    while(*lookingpointer){
        cout << "->(" << (*lookingpointer)->val << ")";
        (lookingpointer) = &((*lookingpointer)->next);
    }
}

int main(){
    SortedLinkedList listaordenada;
    listaordenada.ins(1);
    listaordenada.ins(2);
    listaordenada.ins(100);
    listaordenada.ins(50);
    listaordenada.ins(4);
    listaordenada.print();
    listaordenada.rem(50);
    cout << endl;
    listaordenada.print();
}
