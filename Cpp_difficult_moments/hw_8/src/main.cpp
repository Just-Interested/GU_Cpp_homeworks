#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <tuple>
#include <string>
#include <optional>
#include <iomanip>
#include <algorithm>
#include "..\src\helper.h"


int main(int argc, char const *argv[])
{
    std::ifstream file("D:\\phonebook.txt"); // путь к файлу PhoneBook.txt
    PhoneBook book(file);
    std::cout << book << std::endl;
    std::cout << "------SortByName-------" << std::endl;
    book.SortByName();
    std::cout << book << std::endl;
    std::cout << "------SortByPhone-------" << std::endl;
    book.SortByPhone();
    std::cout << book << std::endl;
    std::cout << "------GetPhoneNumber-------" << std::endl;
    auto print_phone_number = [&book](const std::string &surname)
    {
        std::cout << surname << "\t";
        auto answer = book.GetPhoneNumber(surname);
        if (std::get<0>(answer).empty())
            std::cout << std::get<1>(answer);
        else
            std::cout << std::get<0>(answer);
        std::cout << std::endl;
    };
    print_phone_number("Иванов");
    print_phone_number("Петров");
    std::cout << "----ChangePhoneNumber----" << std::endl;
    book.ChangePhoneNumber(Person{"Котов", "Василий", "Елисееевич"},
                           PhoneNumber{7, 123, 15344458, std::nullopt});
    book.ChangePhoneNumber(Person{"Миронова", "Маргарита", "Владимировна"},
                           PhoneNumber{16, 465, 9155448, 13});
    std::cout << book << std::endl;
    return 0;
}
