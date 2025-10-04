#include <iostream>
using namespace std;

struct Nodo {
	int valor;
	Nodo* next;
	Nodo(int x) : valor(x), next(nullptr) {}
};

class LinkedListSorted {
private:
	Nodo* head;
	int num_elem;
public:
	LinkedListSorted();
	~LinkedListSorted();
	bool find(int x, Nodo**&p);
	void insert(int a);
	void remo(int a);
	int operator[] (int x);
	void print();

	friend void Merge(LinkedListSorted &A, LinkedListSorted &B);
};

LinkedListSorted::LinkedListSorted() : head(nullptr), num_elem(0) {}
LinkedListSorted::~LinkedListSorted() {
	while(head) {
		Nodo* t=head;
		head=head->next;
		delete t;
	}
	num_elem=0;
}
bool LinkedListSorted::find(int x,Nodo**&p) {
	p=&head;
	while(*p && (*p)->valor < x) {
		p=&((*p)->next);
	}
	return *p && (*p)->valor == x;
}
void LinkedListSorted::insert(int a) {
	Nodo**p;
	if(!find(a,p)) {
		Nodo* nuevo = new Nodo(a);
		nuevo->next=*p;
		*p=nuevo;
		num_elem++;
	}
}
void LinkedListSorted::remo(int a) {
	Nodo**p;
	if(find(a,p)) {
		Nodo* temp=*p;
		*p=(*p)->next;
		delete temp;
		num_elem--;
	}
}
int LinkedListSorted::operator[] (int x) {
	if (x>=num_elem) {
		cout << "Excediste el num del indice" << endl;
		return -1;
	}
	Nodo* p = head;
	int a = 0;
	while(a<x && p) {
		p=p->next;
		a++;
	}
	return p->valor;
}
void LinkedListSorted::print() {
	Nodo* p = head;
	while(p != nullptr) {
		cout<<"->"<< "(" << p->valor << ")";
		p=p->next;
	}
	cout<<endl;
}


void Merge(LinkedListSorted &A, LinkedListSorted &B) {
	Nodo** pA = &A.head;
	Nodo** pB = &B.head;

	while (*pB) {
		while (*pA && (*pA)->valor < (*pB)->valor) {
			pA = &((*pA)->next);
		}

		Nodo* nodoEntrante = *pB;
		*pB = nodoEntrante->next;

		nodoEntrante->next = *pA;
		*pA = nodoEntrante;
		pA = &((*pA)->next);
		
		A.num_elem++;
		B.num_elem--;
		cout << "Merging" << endl;
		A.print();
		B.print();
	}
}

int main() {
	LinkedListSorted Alist;
	LinkedListSorted Blist;
	Alist.insert(1);
	Alist.insert(4);
	Alist.insert(5);
	Alist.insert(7);
	Alist.insert(9);
	Blist.insert(2);
	Blist.insert(3);
	Blist.insert(55);
	Blist.insert(88);
	Blist.insert(101);

	cout<<"Listas al comienzo\n";
	Alist.print();
	Blist.print();
	cout<<"Mergeo de listas\n";
	Merge(Alist, Blist);
	cout << "Se mergearon\n";
	Alist.print();
	Blist.print();
	return 0;
}
