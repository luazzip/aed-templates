#include <iostream>
#include <vector>

template <typename T>
class Stack {
private:
    std::vector<T> data;
    //std::vector<T> minData;

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

    // MIN
    // --- PUSH que ademas actualiza el minimo ---
    void push_min(T x) {
        data.push_back(x);
        if (minData.empty() || x <= minData.back())
            minData.push_back(x);
        else
            minData.push_back(minData.back());
    }

    // --- POP sincronizado con el stack de minimos ---
    void pop_min() {
        data.pop_back();
        minData.pop_back();
    }

    // --- MINIMO ACTUAL EN O(1) ---
    T getMin() const {
        return minData.back();
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
