#include <iostream>
#include <vector>
#include <list>
#include <ctime>
#include <iomanip>

// Task 1
void add_average_value(std::list<double> &l){
    double tmp = 0;
    for(auto cur : l){
        tmp += cur;
    }
    tmp = tmp / l.size();
    l.push_back(tmp);
}

// Task 2
class Matrix{
private:
    int m_row, m_col;
    int n_elements;
    std::vector<double> data;
public: 
    Matrix(int size){
        std::srand(std::time(nullptr));
        int random;
        this->m_row = size;
        this->m_col = size;
        this->n_elements = size * size;
        this->data.reserve(this->n_elements);
        for (size_t i = 0; i < this->n_elements; i++)
        {
            random = std::rand() % 100;
            this->data.push_back(random / 10.0);
        }
    }
    Matrix(int r, int c, double init_val = 0){
        this->m_row = r;
        this->m_col = c;
        this->n_elements = r * c;
        this->data.reserve(this->n_elements);
        for (size_t i = 0; i < this->n_elements; i++)
        {
            this->data.push_back(init_val);
        }
    }
    double& operator()(int r, int c){
        if (r >= m_row || c >= m_col){
            std::cout << "Wrong index!" << std::endl;
            return this->data.at(0);
        }
        return this->data.at(r * m_col + c);
    }
    double operator()(int r, int c) const {
        if (r >= m_row || c >= m_col){
            std::cout << "Wrong index!" << std::endl;
            return this->data.at(0);
        }
        return this->data.at(r * m_col + c);
    }
    Matrix submatrix(int rem_row, int rem_col){
        Matrix m(this->m_row - 1, this->m_col - 1);
        m.data.clear();
        for (int i = 0; i < this->m_row; i++){
            if (i == rem_row)
                continue;
            for (int j = 0; j < this->m_col; j++){
                if (j == rem_col)
                    continue;
                m.data.push_back((*this)(i, j));                
            }
        }
        return m;
    }
    double determinant(){
        double det = 0;
        if (this->n_elements == 1){
            return this->data.back();
        }
        if (this->n_elements == 4){
            return (*this)(0, 0) * (*this)(1, 1) - (*this)(1, 0) * (*this)(0, 1);
        } 
        int sign = 1;
        for (int j = 0; j < this->m_col; j++){
            Matrix sub_matrix = (*this).submatrix(0, j);
            double sub_det = sub_matrix.determinant();
            det = det + (sign * (*this)(0, j) * sub_det);
            sign *= -1; 
        }
        return det;
    }
    friend std::ostream& operator<<(std::ostream& os, Matrix m);
};

std::ostream& operator<<(std::ostream& os, Matrix m){
    for (int i = 0; i < m.m_row; i++){
        std::cout << "| ";
        for (int j = 0; j < m.m_col; j++){
            std::cout << std::setw(4) << m(i, j) << " ";
        }
        std::cout << " |" << std::endl;
    }
    // for (auto d : m.data){
    //     os << d << " ";
    // }
    // os << std::endl;
    return os;
}

// Task 3
class IntIterator{
private:
    int* ptr;
public:
    IntIterator() = default;
    IntIterator(int &val) {
        ptr = &val;
    }
    int operator*(){
        return *ptr;	
    }
    void operator=(int val){
        *ptr = val;
    }
    void operator++(){
        ptr++;
    }
    void operator--(){
        ptr--;
    }
    bool operator!=(int& val){
        return ptr != &val;
    }
};

int main(int, char**) {
    // Task 1 tests
    std::list<double> l = { 7.3, 5.1, 16.9, 8.8 };
    for (auto d : l){
        std::cout << d << " ";
    }
    std::cout << std::endl;
    add_average_value(l);
    for (auto d : l){
        std::cout << d << " ";
    }
    std::cout << "\n" << std::endl;

    // Task 2 tests
    Matrix m(4);
    std::cout << m << std::endl;
    std::cout << m.determinant() << std::endl;
    m(0, 0) = 3;
    m(0, 1) = 7;
    m(0, 2) = 11;
    m(0, 3) = 4;
    m(1, 0) = 24;
    m(1, 1) = 42;
    m(1, 2) = 74;
    m(1, 3) = 8;
    m(2, 0) = 12;
    m(2, 1) = 3;
    m(2, 2) = 12;
    m(2, 3) = 13;
    m(3, 0) = 27;
    m(3, 1) = 34;
    m(3, 2) = 17;
    m(3, 3) = 21;
    std::cout << m << std::endl;
    std::cout << m.determinant() << std::endl;

    // Task 3 tests
    int arr[5] = { 1,2,3,4,5 };
    for (IntIterator it : arr){
        std::cout << *it << " ";
    }
}
