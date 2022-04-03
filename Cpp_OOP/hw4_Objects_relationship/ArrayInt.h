#ifndef ARRAYINT_H
#define ARRAYINT_H
#include <cassert> // для assert()


class ArrayInt{
private:
    int m_length;
    int *m_data;
public:
    ArrayInt();

    ArrayInt(int length);

    ~ArrayInt();

    void erase();

    int getLength() const;

    int& operator[](int index);

    void resize(int newLength);

    void insertBefore(int value, int index);

    void push_back(int value);

    
    
    // Task 1
    void remove_item(int index);

    int pop_back();

    int pop_front();

    void print();

    void qsort();

    int get_num_of_uniq_elem();

    int get_num_of_uniq_elem_2();
};

#endif