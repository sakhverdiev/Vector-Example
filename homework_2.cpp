#include <iostream>
#include <vector>
using namespace std;

template <typename T>
class Vector {
private:
    T* _array = nullptr;
    size_t _size = 0;
    size_t _capacity = 15;

public:
    Vector() = default;
    Vector(size_t capacity);

    T* getData() const { return _array; }
    size_t size() const { return _size; }
    size_t capacity() const { return _capacity; }

    T& operator[](size_t index);

    Vector& push_back(const T& value);
    Vector& push_front(const T& value);
    Vector& pop_back();
    Vector& pop_front();
    void delete_by_index(const size_t index);
    void insert_by_index(const size_t index, const T& element);
    size_t find(const T& element);
    size_t rfind(const T& element);
    void sort(bool reverse = false);
};

template<typename T>
Vector<T>::Vector(size_t capacity) : _capacity(capacity) {
    _array = new T[_capacity];
}

template<typename T>
T& Vector<T>::operator[](size_t index) {
    return _array[index];
}

template<typename T>
Vector<T>& Vector<T>::push_back(const T& value) {
    if (_size >= _capacity) {
        _capacity *= 2;
        T* new_array = new T[_capacity];
        for (size_t i = 0; i < _size; i++) {
            new_array[i] = _array[i];
        }
        delete[] _array;
        _array = new_array;
    }

    _array[_size++] = value;
    return *this;
}

template<typename T>
Vector<T>& Vector<T>::push_front(const T& value) {
    insert_by_index(0, value);
    return *this;
}

template<typename T>
Vector<T>& Vector<T>::pop_back() {
    if (_size > 0) {
        _size--;
    }
    return *this;
}

template<typename T>
Vector<T>& Vector<T>::pop_front() {
    delete_by_index(0);
    return *this;
}

template<typename T>
void Vector<T>::delete_by_index(const size_t index) {
    if (index >= _size) {
        return;
    }

    for (size_t i = index; i < _size - 1; i++) {
        _array[i] = _array[i + 1];
    }

    _size--;
}

template<typename T>
void Vector<T>::insert_by_index(const size_t index, const T& element) {
    if (_size >= _capacity) {
        _capacity *= 2;
        T* new_array = new T[_capacity];
        for (size_t i = 0; i < _size; i++) {
            new_array[i] = _array[i];
        }
        delete[] _array;
        _array = new_array;
    }

    for (size_t i = _size; i > index; i--) {
        _array[i] = _array[i - 1];
    }

    _array[index] = element;
    _size++;
}

template<typename T>
size_t Vector<T>::find(const T& element) {
    for (size_t i = 0; i < _size; i++) {
        if (_array[i] == element) {
            return i;
        }
    }
    return _size;
}

template<typename T>
size_t Vector<T>::rfind(const T& element) {
    for (size_t i = _size - 1; i >= 0; i--) {
        if (_array[i] == element) {
            return i;
        }
    }
    return _size;
}

template<typename T>
void Vector<T>::sort(bool reverse) {
    for (size_t i = 0; i < _size - 1; i++) {
        for (size_t j = 0; j < _size - i - 1; j++) {
            if ((!reverse && _array[j] > _array[j + 1]) || (reverse && _array[j] < _array[j + 1])) {
                // Swap
                T temp = _array[j];
                _array[j] = _array[j + 1];
                _array[j + 1] = temp;
            }
        }
    }
}


int main() {
    Vector<int> vec;

    vec.push_back(10);
    vec.push_back(20);
    vec.push_back(30);

    for (size_t i = 0; i < vec.size(); i++) {
        cout << vec[i] << " ";
    }
    cout << endl;

    return 0;
}