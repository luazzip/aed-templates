#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};

class SinglyLinkedList {
private:
    Node* head;
    Node* tail;
    int sz;

public:
    SinglyLinkedList() {
        head = nullptr;
        tail = nullptr;
        sz = 0;
    }

    // Insertar al inicio
    void push_front(int x) {
        Node* nuevo = new Node(x);

        nuevo->next = head;
        head = nuevo;

        if (tail == nullptr)
            tail = head;

        sz++;
    }

    // Insertar al final
    void push_back(int x) {
        Node* nuevo = new Node(x);

        if (head == nullptr) {
            head = nuevo;
            tail = nuevo;
        } else {
            tail->next = nuevo;
            tail = nuevo;
        }

        sz++;
    }

    // Eliminar primero
    void pop_front() {
        if (head == nullptr)
            return;

        Node* temp = head;
        head = head->next;

        delete temp;
        sz--;

        if (head == nullptr)
            tail = nullptr;
    }

    // Eliminar último
    void pop_back() {
        if (head == nullptr)
            return;

        // Solo hay un elemento
        if (head == tail) {
            delete head;
            head = nullptr;
            tail = nullptr;
            sz = 0;
            return;
        }

        Node* current = head;

        // Buscar el nodo anterior a tail
        while (current->next != tail) {
            current = current->next;
        }

        delete tail;

        tail = current;
        tail->next = nullptr;

        sz--;
    }

    // Buscar un valor
    bool contains(int x) {
        Node* current = head;

        while (current != nullptr) {
            if (current->data == x)
                return true;

            current = current->next;
        }

        return false;
    }

    // Eliminar la primera aparición de x
    void remove(int x) {
        if (head == nullptr)
            return;

        // Si es el primero
        if (head->data == x) {
            pop_front();
            return;
        }

        Node* current = head;

        // Buscamos el nodo anterior al que queremos eliminar
        while (current->next != nullptr &&
               current->next->data != x) {
            current = current->next;
        }

        // No encontramos x
        if (current->next == nullptr)
            return;

        Node* temp = current->next;

        current->next = temp->next;

        if (temp == tail)
            tail = current;

        delete temp;
        sz--;
    }

    // Obtener tamaño
    int size() {
        return sz;
    }

    bool empty() {
        return head == nullptr;
    }

    // Imprimir
    void print() {
        Node* current = head;

        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }

        cout << '\n';
    }

    // Liberar memoria
    void clear() {
        while (head != nullptr) {
            pop_front();
        }
    }

    ~SinglyLinkedList() {
        clear();
    }
};
