#include <iostream>

// Task 1
template<typename T>
class Pair1{
private:
    T value1;
    T value2;
public:
    Pair1(T value1, T value2){
        this->value1 = value1;
        this->value2 = value2;
    }
    T first() const {
        return value1;
    }
    T second() const {
        return value2;
    }
};

// Task 2
template<typename T1, typename T2>
class Pair{
private:
    T1 value1;
    T2 value2;
public:
    Pair(T1 value1, T2 value2){
        this->value1 = value1;
        this->value2 = value2;
    }
    T1 first() const {
        return value1;
    }
    T2 second() const {
        return value2;
    }
};


// Task 3
template <typename T>
class StringValuePair : public Pair<std::string, T>{
public:
    StringValuePair(std::string s, T t) : Pair<std::string, T>(s, t) {}
};



int main(int argc, char* argv[]){
    // Task 1 tests
    Pair1<int> p1(6, 9);
    std::cout << "Pair: " << p1.first() << ' ' << p1.second() << '\n';

    const Pair1<double> p2(3.4, 7.8);
    std::cout << "Pair: " << p2.first() << ' ' << p2.second() << '\n';

    // Task 2 tests
    Pair<int, double> p3(6, 7.8);
    std::cout << "Pair: " << p3.first() << ' ' << p3.second() << '\n';

    const Pair<double, int> p4(3.4, 5);
    std::cout << "Pair: " << p4.first() << ' ' << p4.second() << '\n';

    // Task 3 tests
    StringValuePair<int> svp("Amazing", 7);
    std::cout << "Pair: " << svp.first() << ' ' << svp.second() << '\n';

    return 0;
}