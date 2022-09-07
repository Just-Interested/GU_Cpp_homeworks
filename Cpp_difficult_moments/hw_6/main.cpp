#include <cstdlib>
#include <iostream>
#include <ctime>
#include <thread>
#include <mutex>
#include <chrono>
#include <vector>
#include <cmath>
#include <algorithm>


using namespace std::chrono_literals;

std::mutex pcout_m;
std::mutex race_m;

// template <typename T>
// class safe_obj{
// private:
//     T obj;
// public:
//     safe_obj() = default;
//     safe_obj(T val){
//         this->obj = val;
//     }
//     safe_obj<T>& operator=(T obj){
//         this->obj = obj;
//         return *this;
//     }
//     void set(T obj){
//         this->obj = obj;
//     }
//     template <typename U>
//     friend std::ostream& operator<<(std::ostream&, const safe_obj<U>&);
// };

// template <typename T>
// std::ostream& operator<< (std::ostream& os, const safe_obj<T>& o){
//     std::lock_guard lg(pcout_m);
//     os << o.obj;
//     return os;
// }

// Task 1
template <typename T>
void pcout(T obj){
    std::lock_guard<std::mutex> lg(pcout_m);
    std::cout << obj << std::endl;
}
// Task 1 helper
std::ostream& operator<<(std::ostream& os, std::vector<std::pair<int, int>> v){
    for (auto p : v){
        os << p.first << "_" << p.second << "  ";
    }
    os << std::endl;
    return os;
}


// Task 2
bool is_prime(long long n){
    if(n < 2) return false;
    if(n == 2) return true;
    if(n % 2 == 0) return false; 
	for(long long i=3; (i*i) <= n; i += 2)
		if(n%i==0)
			return false;
	return true;
}

long long calc_n_prime(int n, int& counter){
    counter = 1;
    long long c_val = 3;
    if (n < 1)
        return 0;
    if (n == 1)
        return 2;
    while (1){
        if (is_prime(c_val)){
            counter++;
        }
        if (counter == n)
            break;
        c_val++;
    }
    return c_val;
}

// Task 3
void owner(std::vector<int>& v) {
    std::srand(std::time(0));
    while (1) {
        race_m.lock();
        v.push_back(std::rand() % 1000);
        race_m.unlock();
        std::this_thread::sleep_for(500ms);
    }
}

void thief(std::vector<int>& v) {
    while (1) {
        race_m.lock();
        if (!v.empty()) {
            v.erase(std::max_element(v.begin(), v.end()));
        }
        race_m.unlock();
        std::this_thread::sleep_for(1000ms);
    }
}
// Task 3 helper
std::ostream& operator<<(std::ostream& os, std::vector<int> v) {
    for (auto i : v) {
        os << i << "  ";
    }
    os << std::endl;
    return os;
}


int main(int, char**) {
    // Task 1
    std::vector<std::pair<int, int>> v1;
    for (size_t i = 0; i < 1000; i++)
    {
        v1.push_back(std::pair<int, int>(1, i));
    }
    std::vector<std::pair<int, int>> v2;
    for (size_t i = 0; i < 1000; i++)
    {
        v2.push_back(std::pair<int, int>(2, i));
    }
    // std::thread th1([&]{
    //     std::cout << v1;
    // });
    // std::thread th2([&]{
    //     std::cout << v2;
    // }); 
    // // output ... _1555_  9872  _1556_  9882  _1557_  9892  _1558_  9902  ...
    std::thread th1([&]{
        pcout(v1);
    });
    std::thread th2([&]{
        pcout(v2);
    });
    //output is correct
    th1.join();
    th2.join(); 

    // Task 2
    int cnt = 0;
    int n_prime = 1000000;
    long long prime = 0;
    std::thread th3([&] {
        prime = calc_n_prime(n_prime, cnt);
        });
    std::cout << "Calculating " << n_prime << "-th prime:\n";
    int step = 0;
    while (cnt < n_prime) {
        std::cout << "Calculated " << cnt << "/" << n_prime << " prime\n";
        std::this_thread::sleep_for(300ms);
    }
    std::cout << "\nCalculation is done!\nPrime: " << prime << std::endl;
    th3.join();

    // Task 3
    std::vector<int> v;
    std::thread th4([&v] {
        owner(v);
        });
    std::thread th5([&v] {
        thief(v);
        });
    th4.detach();
    th5.detach();
    int n_checks = 0;
    while (1) {
        n_checks++;
        std::cout << "Vector: " << v << std::endl;
        std::this_thread::sleep_for(1500ms);
        if (n_checks > 5)
            break;
    }

}
