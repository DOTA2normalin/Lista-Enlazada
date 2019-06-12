#include <iostream>

using namespace std;

template<typename T>
class Node
{
    public:
    Node<T> *sgte;
    T data;

    Node(T data){this->data = data;}

    void imprimirN()
    {
        cout << data << "-> ";
    }

};

template<typename T>
class Lista
{
    public:
    Node<T> *head;
    Node<T> *actual;

    void add(T data)
    {
        if(head == NULL)
        {
            head = new Node<T>(data);
            return;
        }
        Node<T> *actual = head;
        while(actual->sgte != NULL){actual = actual->sgte;}
        actual->sgte = new Node<T>(data);
    }


    void addF(T data)
    {
        Node<T> *newHead = new Node<T>(data);
        newHead->sgte = head;
        head = newHead;
    }

    void deleteV(T x)
    {
        if(head = NULL) return;
        if(head->data == x)
        {
            Node<T> *temp = head;
            head = head->sgte;
            delete temp;
            return;
        }

        Node<T> *actual = head;
        while(actual->sgte != NULL)
        {
            if(actual->sgte->data == x)
            {
                actual->sgte = actual->sgte->sgte;
                return;
            }
            actual = actual->sgte;
        }
    }

    void imprimir()
    {
        Node<T> *temp = head;
        if (!head) {
            cout << "Lista no inicializada " << endl;
        } else {
            while (temp) {
                temp->imprimirN();
                if (!temp->sgte) cout << "NULL";
                    temp = temp->sgte;
            }
      }
      cout << endl << endl;
    }
};

int main()
{
    Lista<int> a;
    a.add(5);
    a.add(4);
    a.add(3);
    a.add(2);
    a.addF(4);
    a.imprimir();
    return 0;
}
