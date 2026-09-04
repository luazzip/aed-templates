#include <iostream>
#include <vector>
#include <algorithm>

template <typename T>
class Queue {
private:
    std::vector<T> data;

    int front_index;
    int count;

    // Duplicar capacidad
    void grow() {
        int old_capacity = (int)data.size();

        int new_capacity = std::max(1, old_capacity * 2);

        std::vector<T> new_data(new_capacity);

        for (int i = 0; i < count; i++) {
            new_data[i] =
                data[(front_index + i) % old_capacity];
        }

        data = std::move(new_data);

        front_index = 0;
    }

public:

    Queue(int capacity = 1)
        : data(capacity),
          front_index(0),
          count(0) {}

    // Agregar al final
    void enqueue(T x) {

        if (count == (int)data.size()) {
            grow();
        }

        int position =
            (front_index + count) % data.size();

        data[position] = x;

        count++;
    }

    // Eliminar del frente
    void dequeue() {

        if (empty())
            return;

        front_index =
            (front_index + 1) % data.size();

        count--;
    }

    // Consultar el frente
    T& front() {
        return data[front_index];
    }

    const T& front() const {
        return data[front_index];
    }

    // Verificar si está vacía
    bool empty() const {
        return count == 0;
    }

    // Cantidad de elementos
    int size() const {
        return count;
    }

    // Eliminar todos
    void clear() {
        front_index = 0;
        count = 0;
    }
};
