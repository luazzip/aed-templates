#include <iostream>

template <typename T>
struct Node {
    T data;
    Node<T>* prev;
    Node<T>* next;

    Node(T value)
        : data(value), prev(nullptr), next(nullptr) {}
};

template <typename T>
class CircularDoublyLinkedList {
private:
    Node<T>* head;
    Node<T>* tail;
    int sz;

public:
    CircularDoublyLinkedList()
        : head(nullptr), tail(nullptr), sz(0) {}

    ~CircularDoublyLinkedList() {
        clear();
    }

    bool empty() const {
        return head == nullptr;
    }

    int size() const {
        return sz;
    }

    // Insertar al inicio
    void push_front(T value) {
        Node<T>* newNode = new Node<T>(value);

        // Lista vacía
        if (empty()) {
            head = newNode;
            tail = newNode;

            head->next = head;
            head->prev = head;
        }
        else {
            newNode->next = head;
            newNode->prev = tail;

            head->prev = newNode;
            tail->next = newNode;

            head = newNode;
        }

        sz++;
    }

    // Insertar al final
    void push_back(T value) {
        Node<T>* newNode = new Node<T>(value);

        // Lista vacía
        if (empty()) {
            head = newNode;
            tail = newNode;

            head->next = head;
            head->prev = head;
        }
        else {
            newNode->prev = tail;
            newNode->next = head;

            tail->next = newNode;
            head->prev = newNode;

            tail = newNode;
        }

        sz++;
    }

    // Eliminar el primero
    void pop_front() {
        if (empty()) return;

        // Solo hay un elemento
        if (head == tail) {
            delete head;

            head = nullptr;
            tail = nullptr;
        }
        else {
            Node<T>* temp = head;

            head = head->next;

            head->prev = tail;
            tail->next = head;

            delete temp;
        }

        sz--;
    }

    // Eliminar el último
    void pop_back() {
        if (empty()) return;

        // Solo hay un elemento
        if (head == tail) {
            delete tail;

            head = nullptr;
            tail = nullptr;
        }
        else {
            Node<T>* temp = tail;

            tail = tail->prev;

            tail->next = head;
            head->prev = tail;

            delete temp;
        }

        sz--;
    }

    // Obtener el primer elemento
    T& front() {
        return head->data;
    }

    const T& front() const {
        return head->data;
    }

    // Obtener el último elemento
    T& back() {
        return tail->data;
    }

    const T& back() const {
        return tail->data;
    }

    // Buscar un elemento
    bool contains(T value) const {
        if (empty()) return false;

        Node<T>* current = head;

        do {
            if (current->data == value) {
                return true;
            }

            current = current->next;

        } while (current != head);

        return false;
    }

    // Eliminar la primera aparición de un valor
    void remove(T value) {
        if (empty()) return;

        Node<T>* current = head;

        do {
            if (current->data == value) {

                // Eliminar el único nodo
                if (head == tail) {
                    delete current;

                    head = nullptr;
                    tail = nullptr;
                }
                // Eliminar head
                else if (current == head) {
                    pop_front();
                    return;
                }
                // Eliminar tail
                else if (current == tail) {
                    pop_back();
                    return;
                }
                // Eliminar nodo intermedio
                else {
                    current->prev->next = current->next;
                    current->next->prev = current->prev;

                    delete current;
                }

                sz--;
                return;
            }

            current = current->next;

        } while (current != head);
    }

    // Eliminar todos los elementos
    void clear() {
        if (empty()) return;

        Node<T>* current = head;

        while (current->next != head) {
            Node<T>* temp = current;
            current = current->next;
            delete temp;
        }

        delete current;

        head = nullptr;
        tail = nullptr;
        sz = 0;
    }

    //Eliminar por nodo 
    Node<T>* eraseNode(Node<T>* node) {
    Node<T>* nxt = node->next;          // guardamos a dónde seguir

    if (head == tail) {                 // único nodo en la lista
        head = tail = nullptr;
        nxt = nullptr;
    } else {
        node->prev->next = node->next;  // "saltamos" el nodo
        node->next->prev = node->prev;
        if (node == head) head = node->next;
        if (node == tail) tail = node->prev;
    }

    delete node;
    sz--;
    return nxt;  // el nodo desde el cual seguirá el recorrido
}

    // Imprimir de head hacia adelante
    void print_forward() const {
        if (empty()) {
            std::cout << "Lista vacia\n";
            return;
        }

        Node<T>* current = head;

        do {
            std::cout << current->data << " ";
            current = current->next;

        } while (current != head);

        std::cout << '\n';
    }

    // Imprimir de tail hacia atrás
    void print_backward() const {
        if (empty()) {
            std::cout << "Lista vacia\n";
            return;
        }

        Node<T>* current = tail;

        do {
            std::cout << current->data << " ";
            current = current->prev;

        } while (current != tail);

        std::cout << '\n';
    }
};
