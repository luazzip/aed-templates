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

class CircularLinkedList {
private:
    Node* head;
    Node* tail;
    int sz;

public:
    CircularLinkedList() {
        head = nullptr;
        tail = nullptr;
        sz = 0;
    }

    // Insertar al inicio
    void push_front(int x) {
        Node* nuevo = new Node(x);

        if (head == nullptr) {
            head = nuevo;
            tail = nuevo;

            tail->next = head;
        } else {
            nuevo->next = head;
            head = nuevo;

            tail->next = head;
        }

        sz++;
    }

    // Insertar al final
    void push_back(int x) {
        Node* nuevo = new Node(x);

        if (head == nullptr) {
            head = nuevo;
            tail = nuevo;

            tail->next = head;
        } else {
            nuevo->next = head;

            tail->next = nuevo;
            tail = nuevo;
        }

        sz++;
    }

    // Eliminar primero
    void pop_front() {
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

        Node* temp = head;

        head = head->next;
        tail->next = head;

        delete temp;

        sz--;
    }

    // Eliminar último
    void pop_back() {
        if (head == nullptr)
            return;

        // Solo un elemento
        if (head == tail) {
            delete head;

            head = nullptr;
            tail = nullptr;

            sz = 0;

            return;
        }

        Node* current = head;

        // Buscar nodo anterior a tail
        while (current->next != tail) {
            current = current->next;
        }

        delete tail;

        tail = current;

        tail->next = head;

        sz--;
    }

    // Buscar
    bool contains(int x) {
        if (head == nullptr)
            return false;

        Node* current = head;

        do {
            if (current->data == x)
                return true;

            current = current->next;

        } while (current != head);

        return false;
    }

    // Eliminar primera aparición
    void remove(int x) {
        if (head == nullptr)
            return;

        // El primero
        if (head->data == x) {
            pop_front();
            return;
        }

        Node* current = head;

        while (current->next != head &&
               current->next->data != x) {

            current = current->next;
        }

        // No encontrado
        if (current->next == head)
            return;

        Node* temp = current->next;

        current->next = temp->next;

        // Si eliminamos tail
        if (temp == tail)
            tail = current;

        delete temp;

        sz--;
    }

    int size() {
        return sz;
    }

    bool empty() {
        return head == nullptr;
    }

    void print() {
        if (head == nullptr) {
            cout << '\n';
            return;
        }

        Node* current = head;

        do {
            cout << current->data << " ";
            current = current->next;

        } while (current != head);

        cout << '\n';
    }

    void clear() {
        while (head != nullptr) {
            pop_front();
        }
    }

    ~CircularLinkedList() {
        clear();
    }
};
