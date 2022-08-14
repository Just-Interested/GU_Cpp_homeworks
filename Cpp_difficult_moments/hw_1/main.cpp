#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <tuple>
#include <string>
#include <optional>

struct Person
{
    std::string name;
    std::string surname;
    std::optional<std::string> patronymic;
};

std::ostream &operator<<(std::ostream &os, Person &p)
{
    os << p.surname << " " << p.name;
    if (p.patronymic)
        return os << " " << *p.patronymic;
    return os;
}

bool operator<(Person p1, Person p2)
{
    return std::tie(p1.surname, p1.name, p1.patronymic) < std::tie(p2.surname, p2.name, p2.patronymic);
}

bool operator==(Person p1, Person p2)
{
    return std::tie(p1.surname, p1.name, p1.patronymic) == std::tie(p2.surname, p2.name, p2.patronymic);
}

struct PhoneNumber
{
    unsigned int country_code;
    unsigned int city_code;
    unsigned int number;
    std::optional<unsigned int> additional_number;
};

std::ostream &operator<<(std::ostream &os, PhoneNumber &ph_num)
{
    os << "+" << ph_num.country_code << "(" << ph_num.city_code << ")" << ph_num.number;
    if (ph_num.additional_number)
        os << " " << *ph_num.additional_number;
    return os;
}

bool operator<(PhoneNumber &ph_num1, PhoneNumber &ph_num2)
{
    return std::tie(ph_num1.country_code, ph_num1.city_code, ph_num1.number, ph_num1.additional_number) < std::tie(ph_num2.country_code, ph_num2.city_code, ph_num2.number, ph_num2.additional_number);
}

bool operator==(PhoneNumber &ph_num1, PhoneNumber &ph_num2)
{
    return std::tie(ph_num1.country_code, ph_num1.city_code, ph_num1.number, ph_num1.additional_number) == std::tie(ph_num2.country_code, ph_num2.city_code, ph_num2.number, ph_num2.additional_number);
}


class PhoneBook{
private:
    std::vector<std::pair<Person, PhoneNumber>> records;
public:
    PhoneBook(std::ifstream& ifs){
        std::string c_line;
        std::string tmp;
        std::istringstream input;
        Person p;
        PhoneNumber ph_num;
        while(std::getline(ifs, c_line)){
            std::cout << c_line << std::endl;
            // input.str(c_line);
            // input >> p.surname >> p.name >> *p.patronymic >> tmp;         
        }
        
    }


};

PhoneNumber parse_number(std::string s){
    PhoneNumber ph_num;
    int plus_pos = -1;
    int open_brace_pos = -1;
    int close_brace_pos = -1;
    int space_pos = -1;
    for (int i = 0; i < s.length(); i++){
        if (s[i] == '+')
            plus_pos = i;
        if (s[i] == '(')
            open_brace_pos = i;
        if (s[i] == ')')
            close_brace_pos = i;
        if (s[i] == ' ')
            space_pos = i;
    }
    ph_num.country_code = std::stoi(s.substr(plus_pos + 1, open_brace_pos));
    ph_num.city_code = std::stoi(s.substr(open_brace_pos + 1, close_brace_pos));
    if (space_pos != -1){
        ph_num.number = std::stoi(s.substr(close_brace_pos + 1, space_pos));
        ph_num.additional_number = std::stoi(s.substr(space_pos + 1));
    }
    ph_num.number = std::stoi(s.substr(close_brace_pos + 1));
    return ph_num;
}

int main(int argc, char const *argv[])
{
    // std::cout << "Hello, ";
    // Person p1{"Pavel", "Kucheryaviy", "Yurevich"};
    // Person p2{"Андрей", "Неизвестный"};
    // Person p3{"Андрей", "Известный"};
    // Person p4{"Андрей", "Известный", "Андреевич"};
    // Person p5{"Андрей", "Известный", "Яковлевич"};
    // //std::cout << p.name << " " << p.surname << std::endl;
    // std::cout << p1 << std::endl;
    // std::cout << p2 << std::endl;
    // std::cout << (p3 < p2) << std::endl;
    // std::cout << (p3 < p4) << std::endl;
    // std::cout << (p4 < p5) << std::endl;
    // std::cout << (p3 < p1) << std::endl;
    // std::cout << (p3 == p3) << std::endl;
    // PhoneNumber ph_num{7, 987, 123456, 20};
    // std::cout << ph_num << std::endl;
    // std::ifstream file("G:\\phonebook.txt");
    // PhoneBook book(file);
    // std::stringstream stream("123 456");
    // std::string word1;
    // std::string word2;
    // std::optional<std::string> word3;
    // std::string word4;
    // stream >> word1 >> word2 >> word4;
    // std::cout << word1 << word2 << word4.empty();
    std::string phone("+7(17)455767 57");
    std::string phone2("+493(7637)6114861");
    int pos = phone.rfind(" ");
    std::cout << phone.substr(pos + 1) << std::endl;
    std::optional<std::string> add_n;
    add_n = phone.substr(pos + 1);
    std::cout << *add_n << std::endl;
    pos = phone2.rfind(" ");
    std::cout << pos << std::endl;
    std::cout << phone2.substr(pos + 1) << std::endl;

    std::string record("Ильин Петр Артемович +7(17)455767 57");
    std::string p;
    std::string num;
    pos = record.find("+");
    p = record.substr(0, pos);
    num = record.substr(pos);
    std::cout << p << " --- " << num << std::endl;

    PhoneNumber pn = parse_number("+7(17)455767 57");
    std::cout << pn << std::endl;
    pn = parse_number("+493(7637)6114861");
    std::cout << pn << std::endl;
    return 0;
}
