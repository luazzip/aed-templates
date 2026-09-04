#include <iostream>
#include <vector>

template <typename T>
class Stack {
private:
    std::vector<T> data;

public:

    // Agregar elemento al tope
    void push(T x) {
        data.push_back(x);
    }

    // Eliminar elemento del tope
    void pop() {
        data.pop_back();
    }

    // Consultar el elemento del tope
    T& top() {
        return data.back();
    }

    const T& top() const {
        return data.back();
    }

    // Verificar si está vacía
    bool empty() const {
        return data.empty();
    }

    // Cantidad de elementos
    int size() const {
        return (int)data.size();
    }

    // Eliminar todos los elementos
    void clear() {
        data.clear();
    }
};
