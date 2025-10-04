#include <iostream>
using namespace std;
template<class T>
struct Cola{
  T A[10];
  T* head = nullptr;
  T* tail = nullptr;
  bool vacio();
  bool lleno();
  bool push(T a);
  bool pop(T& a);
  void print();
};
template<class T>
bool Cola<T>::vacio()
{
    return !head;
}
template<class T>
bool Cola<T>::lleno()
{
    
    if(((head == A && tail == A+9) || tail+1 == head))
    {
            return true;
    }
    return false;
}
template<class T>
bool Cola<T>::push(T a)
{
    if(lleno()) return false;
    else{
        if(!head) //esto si la lisat esta vacia xd
        {
            head=A;
            tail = A;
            *tail=a;
            return true;
        }
        if (tail == A + 9) tail = A;
        else tail++;
        *tail= a;
        return true;
    }
}
template<class T>
bool Cola<T>::pop(T& a)
{
    if(vacio()) return false;
    else{
        
        a=*head;
        if(head==tail)
        {
            head=nullptr;
            tail=nullptr;
            
        }
        else if(head == A+9)
        {
            head=A;
        }
        else
        {
            head++;
        }
        return true;
        
    }
}
template<class T>
void Cola<T>::print()
{
    if (vacio()) {
            cout << "(vacia)\n";
            return;
        }
    T* p = head;
    while (true) {
        cout << *p << " ";
        if (p == tail) break;  
        if (p == A + 9) p = A;       
        else p++;
    }
    cout<<endl;
}
int main()
{
    int a;
    Cola<int> lista;
    lista.push(1);
    lista.push(2);
    lista.push(3);
    lista.push(4);
    lista.push(5);
    lista.push(6);
    lista.push(7);
    lista.push(9);
    lista.push(8);
    lista.push(10);
    lista.print();
    lista.pop(a);
    cout<<a<<endl;
    lista.pop(a);
    cout<<a<<endl;
    lista.print();
    lista.push(11);
    lista.push(12);
    lista.print();
    cout<<lista.lleno()<<endl;
    return 0;
}
