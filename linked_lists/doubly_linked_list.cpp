#include <iostream>
using namespace std;

template <typename T>
struct Node {
    T data;
    Node* prev;
    Node* next;

    Node(T x) {
        data = x;
        prev = nullptr;
        next = nullptr;
    }
};

template <typename T>
class DoublyLinkedList {
private:
    Node<T>* head;
    Node<T>* tail;
    int sz;

public:
    DoublyLinkedList() {
        head = nullptr;
        tail = nullptr;
        sz = 0;
    }

    // Insertar al inicio
    void push_front(T x) {
        Node<T>* nuevo = new Node<T>(x);

        nuevo->next = head;

        if (head != nullptr)
            head->prev = nuevo;
        else
            tail = nuevo;

        head = nuevo;

        sz++;
    }

    // Insertar al final
    void push_back(T x) {
        Node<T>* nuevo = new Node<T>(x);

        nuevo->prev = tail;

        if (tail != nullptr)
            tail->next = nuevo;
        else
            head = nuevo;

        tail = nuevo;

        sz++;
    }

    // Eliminar primero
    void pop_front() {
        if (head == nullptr)
            return;

        Node<T>* temp = head;

        head = head->next;

        if (head != nullptr)
            head->prev = nullptr;
        else
            tail = nullptr;

        delete temp;

        sz--;
    }

    // Eliminar último
    void pop_back() {
        if (tail == nullptr)
            return;

        Node<T>* temp = tail;

        tail = tail->prev;

        if (tail != nullptr)
            tail->next = nullptr;
        else
            head = nullptr;

        delete temp;

        sz--;
    }

    // Buscar
    bool contains(T x) {
        Node<T>* current = head;

        while (current != nullptr) {
            if (current->data == x)
                return true;

            current = current->next;
        }

        return false;
    }

    // Eliminar primera aparición de x
    void remove(T x) {
        Node<T>* current = head;

        while (current != nullptr) {

            if (current->data == x) {

                // Si es el primero
                if (current == head) {
                    pop_front();
                    return;
                }

                // Si es el último
                if (current == tail) {
                    pop_back();
                    return;
                }

                // Está en medio
                current->prev->next = current->next;
                current->next->prev = current->prev;

                delete current;

                sz--;

                return;
            }

            current = current->next;
        }
    }

    // Eliminar directamente un nodo
    // O(1) si ya tenemos el puntero al nodo
    void remove_node(Node<T>* node) {
        if (node == nullptr)
            return;

        if (node == head) {
            pop_front();
            return;
        }

        if (node == tail) {
            pop_back();
            return;
        }

        node->prev->next = node->next;
        node->next->prev = node->prev;

        delete node;

        sz--;
    }

    // insertar despues de un nodo
    void insertAfter(Node<T>* node, T x) {
        if (node == nullptr) return;
        if (node == tail) { push_back(x); return; }
        Node<T>* nuevo = new Node<T>(x);
        nuevo->next = node->next;
        nuevo->prev = node;
        node->next->prev = nuevo;
        node->next = nuevo;
        sz++;
    }

    int size() {
        return sz;
    }

    bool empty() {
        return head == nullptr;
    }

    // Imprimir de izquierda a derecha
    void print() {
        Node<T>* current = head;

        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }

        cout << '\n';
    }

    // Imprimir de derecha a izquierda
    void print_reverse() {
        Node<T>* current = tail;

        while (current != nullptr) {
            cout << current->data << " ";
            current = current->prev;
        }

        cout << '\n';
    }

    void clear() {
        while (head != nullptr) {
            pop_front();
        }
    }

    ~DoublyLinkedList() {
        clear();
    }
};
