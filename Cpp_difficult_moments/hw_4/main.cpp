#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <iomanip>
#include <numeric>

// Task 1
template <typename T>
void insert_sorted(std::vector<T> &v, T val){
    auto low = std::lower_bound(v.begin(), v.end(), val);
    v.insert(low, val);
}

// Task 2
std::vector<double> generate_rand_signal(){
    std::srand(std::time(nullptr));
    std::vector<double> v;
    v.reserve(100);
    for (int i = 0; i < 100; i++)
        v.push_back((std::rand() % 1000) / 10.0);
    return v;
}

// print vector helper
template <typename T>
std::ostream& operator<<(std::ostream &os, std::vector<T> v){
    os << "| ";
    for (auto i : v){
        os << std::setw(5) << i << " ";
    }
    os << " |" << std::endl;
    return os;
}

int main(int, char**) {
    // Task 1 tests
    std::vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8 ,9 ,10};
    insert_sorted(v, 7);
    std::cout << v << std::endl;
    
    // Task 2
    std::vector<double> a = generate_rand_signal();
    std::cout << a << std::endl;
    std::vector<int> b;
    std::transform(a.begin(), a.end(), std::back_inserter(b), [](double d){
        return static_cast<int>(d);
    });
    std::cout << b << std::endl;

    // Первый способ подсчета (нечитаемый, сложный, но интересно, что так можно сделать))
    std::vector<double> diff;
    auto calc_diff = [](std::vector<int>::iterator &start, std::vector<int>::iterator &end){
        return [&](double val){
            if (start == end)
                return val;
            double result = (val - *start) * ((val - *start));
            start++;
            return  result;
        };
    };
    auto start_it = b.begin();
    auto end_it = b.end();
    std::transform(a.begin(), a.end(), std::back_inserter(diff), calc_diff(start_it, end_it));
    std::cout << diff << std::endl;
    double sum = std::accumulate(diff.begin(), diff.end(), 0.0);
    std::cout << sum << std::endl;


    // Второй способ подсчета
    auto sq = [](double x, int y){ return (x - y)*(x - y);};
    sum = std::inner_product(a.begin(), a.end(), b.begin(), 0.0, std::plus<>(), sq);
    std::cout << sum << std::endl;
}
