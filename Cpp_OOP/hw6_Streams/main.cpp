#include <iostream>
#include <limits>


// Task 1
void correcting_input(){
    int a;
    while (!(std::cin >> a) || (std::cin.peek() != '\n')){
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Некорректный ввод! Введите целое число!" << std::endl;
    }
}


// Task 2
std::ostream& endll(std::ostream& out)
{
    out << std::endl << std::endl << std::flush;
    return out;
} 


int main(int argc, char* argv[]){
    // Task 1 tests
    correcting_input();

    // Task 2 tests
    std::cout << 22 << endll << 33 << std::endl << 44 << std::endl;
    return 0;
}