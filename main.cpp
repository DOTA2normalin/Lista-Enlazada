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

    //Añade un nuevo nodo al final de la  lista 
    void add(T data)
    {
        //Si el nodo inicial(head) de la lista no contiene nada, lo inicializa con el contenido de data
        if(head == NULL)
        {
            head = new Node<T>(data);
            return;
        }
        //actual un puntero a nodo se iguala a head, haciendo que recorra la lista hasta que encuentre el nodo final y agregar el nuevo dato
        Node<T> *actual = head;
        while(actual->sgte != NULL){actual = actual->sgte;}
        actual->sgte = new Node<T>(data);
    }

    // Similar a la logica de add con la diferencia que aqui el elemento data se agrega como la cabeza es decir el primer elemento de  la lista
    void addF(T data)
    {
        Node<T> *newHead = new Node<T>(data);
        newHead->sgte = head;
        head = newHead;
    }
    
    //Funcion para borrar un elemento de la lista por un dato ingresado
    void deleteV(T x)
    {
        
        if(head = NULL) return;//comprueba si la lista esta vacia, si es el caso no tiene nada que hacer y sale de la funciòn
        //Si encuentra el dato a borrar en la cabeza de la lista utiliza un nodo temporal para hacer el cambio al sgte nodo como cabeza y libera memoria
        if(head->data == x)
        {
            Node<T> *temp = head;
            head = head->sgte;
            delete temp;
            return;
        }
        
        //Recorre todos los nodos buscando el valor a borrar y al nodo anterior al nodo borrado lo  hace apuntar hacia el sgte nodo del nodo borrado 
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
    
    //funciòn para imprimir la lista 
    void imprimir()
    {
        //se crea un nodo temp para que luego recorra la lista mientras que el nodo no sea NULL, luego usando la funcion imprimirN de Nodo imprime los valores
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
