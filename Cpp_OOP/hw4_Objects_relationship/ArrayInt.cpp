#include <cassert> // для assert()
#include "ArrayInt.h"
#include <iostream>
#include <cstdlib>
#include <unordered_set>


ArrayInt::ArrayInt() : m_length(0), m_data(nullptr){ }

ArrayInt::ArrayInt(int length) : m_length(length){
    assert(length >= 0);
    if (length > 0)
        m_data = new int[length];
    else
        m_data = nullptr;
} 

ArrayInt::~ArrayInt(){
    delete[] m_data;
}

void ArrayInt::erase(){
    delete[] m_data;
    m_data = nullptr;
    m_length = 0;
}

int ArrayInt::getLength() const { return m_length; }

int& ArrayInt::operator[](int index){
    assert(index >= 0 && index < m_length);
    return m_data[index];
}

void ArrayInt::resize(int newLength){
    if (newLength == m_length)
        return;
    if (newLength <= 0){
        erase();
        return;
    } 
    int *data = new int[newLength];
    if (m_length > 0){
        int elementsToCopy = (newLength > m_length) ? m_length : newLength;
        for (int index=0; index < elementsToCopy ; ++index)
            data[index] = m_data[index];
    }
    delete[] m_data;
    m_data = data;
    m_length = newLength;
}

void ArrayInt::insertBefore(int value, int index){
    assert(index >= 0 && index <= m_length);
    int *data = new int[m_length+1];
    for (int before=0; before < index; ++before)
        data[before] = m_data[before];
    data [index] = value;
    for (int after=index; after < m_length; ++after)
        data[after+1] = m_data[after];
    delete[] m_data;
    m_data = data;
    ++m_length;
}

void ArrayInt::push_back(int value) { insertBefore(value, m_length); }



// Task 1
void ArrayInt::remove_item(int index){
    assert(index >= 0 && index <= m_length);
    int *data = new int[m_length-1];
    for (int before=0; before < index; ++before)
        data[before] = m_data[before];
    for (int after=index; after < m_length - 1; ++after)
        data[after] = m_data[after+1];
    delete[] m_data;
    m_data = data;
    --m_length;
}

int ArrayInt::pop_back(){
    int tmp = m_data[m_length - 1];
    remove_item(m_length);
    return tmp;
}

int ArrayInt::pop_front(){
    int tmp = m_data[0];
    remove_item(0);
    return tmp;
}

void ArrayInt::print(){
    std::cout << "[ ";
    for (int i=0; i < m_length; ++i)
        std::cout << m_data[i] << " ";
    std::cout << "]" << std::endl;
}

int sort_cmp_function(const void * value_1, const void * value_2){
    const int a = *static_cast<const int*>(value_1);
    const int b = *static_cast<const int*>(value_2);
    if (a < b)
        return -1;
    if (a > b)
        return 1;
    return 0;
}

void ArrayInt::qsort(){
    std::qsort(m_data, m_length, sizeof(int), sort_cmp_function);
}


// Task 2
int ArrayInt::get_num_of_uniq_elem(){
    if (m_length == 0)
        return 0;
    std::unordered_set<int> s(m_data, m_data + m_length);
    return s.size();
}


// По идее следующий способ должен работать быстрее
// и по большей части зависит от времени сортировки
int ArrayInt::get_num_of_uniq_elem_2(){
    if (m_length == 0)
        return 0;
    int *data = new int[m_length];
    for (int i = 0; i < m_length; i++)
        data[i] = m_data[i];
    std::qsort(data, m_length, sizeof(int), sort_cmp_function);
    int n = 1;
    int current_value = data[0];
    for (int i = 1; i < m_length; i++)
    {
        if (data[i] == current_value)
            continue;
        n++;
        current_value = data[i];
    }
    delete[] data;
    return n;
}
