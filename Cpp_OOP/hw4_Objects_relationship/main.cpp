#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include "ArrayInt.h"
#include "BlackJack.h"




int main(int argc, char *argv[]){

    // Task 1 test
    std::cout << "Task 1 tests" << std::endl;
    ArrayInt arr;
    std::srand(12345);
    for (int i = 0; i < 20; i++)
        arr.push_back(std::rand() % 20);    
    arr.print();
    arr.resize(15);
    arr.print();
    arr.push_back(100);
    arr.print();
    std::cout << arr.pop_back() << std::endl;
    arr.print();
    arr.push_back(200);
    std::cout << arr.pop_front() << std::endl;
    arr.print();
    arr.qsort();
    arr.print();
    std::cout << std::endl;

    // Task 2 test
    std::cout << "Task 2 tests" << std::endl;
    ArrayInt arr2(1000000);
    for (int i = 0; i < 1000000; i++)
        arr2[i] = std::rand() % 1000000;
    int n;
    // измеряем время выполнения первой функции
    std::clock_t c_start = std::clock();
    auto t_start = std::chrono::high_resolution_clock::now();
    n = arr2.get_num_of_uniq_elem();
    std::clock_t c_end = std::clock();
    auto t_end = std::chrono::high_resolution_clock::now();  
    std::cout << "Number of uniq elements: " << n << std::endl;
    std::cout << "Wall clock time passed: " << std::chrono::duration<double, std::milli>(t_end-t_start).count() << std::endl;
    std::cout << "CPU time used: " << 1000.0 * (c_end - c_start) / CLOCKS_PER_SEC << std::endl;
    std::cout << std::endl;
    
    // измеряем время выполнения второй функции
    c_start = std::clock();
    t_start = std::chrono::high_resolution_clock::now();
    n = arr2.get_num_of_uniq_elem_2();
    c_end = std::clock();
    t_end = std::chrono::high_resolution_clock::now();
    std::cout << "Number of uniq elements: " << n << std::endl;
    std::cout << "Wall clock time passed: " << std::chrono::duration<double, std::milli>(t_end-t_start).count() << std::endl;
    std::cout << "CPU time used: " << 1000.0 * (c_end - c_start) / CLOCKS_PER_SEC << std::endl;
    /* Вывод:
    Task 2 tests
    Number of uniq elements: 631993
    Wall clock time passed: 402.501
    CPU time used: 406

    Number of uniq elements: 631993
    Wall clock time passed: 141.19
    CPU time used: 141
    */

    // Task 3 tests
    std::cout << std::endl;
    std::cout << "Task 3 tests" << std::endl;
    Hand* hand = new Hand();
    hand->Add(new Card(Card::QUEEN, Card::CLUBS));
    std::cout << "Hand total: " << hand->GetValue() << std::endl;
    hand->Add(new Card(Card::QUEEN, Card::CLUBS));
    std::cout << "Hand total: " << hand->GetValue() << std::endl;
    delete hand;   
    return 0;
}