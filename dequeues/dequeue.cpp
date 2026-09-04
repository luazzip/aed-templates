#include <iostream>
#include <vector>
#include <algorithm>

template <typename T>
class Deque {
private:
    std::vector<T> data;

    int front_index;
    int count;

    int capacity() const {
        return (int)data.size();
    }

    void grow() {
        int old_capacity = capacity();
        int new_capacity = std::max(1, old_capacity * 2);

        std::vector<T> new_data(new_capacity);

        for (int i = 0; i < count; i++) {
            new_data[i] = data[(front_index + i) % old_capacity];
        }

        data = std::move(new_data);
        front_index = 0;
    }

public:
    Deque(int initial_capacity = 1)
        : data(std::max(1, initial_capacity)),
          front_index(0),
          count(0) {}

    bool empty() const {
        return count == 0;
    }

    int size() const {
        return count;
    }

    void push_back(T x) {
        if (count == capacity()) {
            grow();
        }

        int position = (front_index + count) % capacity();

        data[position] = x;
        count++;
    }

    void push_front(T x) {
        if (count == capacity()) {
            grow();
        }

        front_index = (front_index - 1 + capacity()) % capacity();

        data[front_index] = x;
        count++;
    }

    void pop_front() {
        if (empty()) return;

        front_index = (front_index + 1) % capacity();
        count--;
    }

    void pop_back() {
        if (empty()) return;

        count--;
    }

    T& front() {
        return data[front_index];
    }

    const T& front() const {
        return data[front_index];
    }

    T& back() {
        int position = (front_index + count - 1) % capacity();
        return data[position];
    }

    const T& back() const {
        int position = (front_index + count - 1) % capacity();
        return data[position];
    }

    void clear() {
        front_index = 0;
        count = 0;
    }
};
