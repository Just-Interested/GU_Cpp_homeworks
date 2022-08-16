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

bool operator<(PhoneNumber ph_num1, PhoneNumber ph_num2)
{
    return std::tie(ph_num1.country_code, ph_num1.city_code, ph_num1.number, ph_num1.additional_number) < std::tie(ph_num2.country_code, ph_num2.city_code, ph_num2.number, ph_num2.additional_number);
}

bool operator==(PhoneNumber ph_num1, PhoneNumber ph_num2)
{
    return std::tie(ph_num1.country_code, ph_num1.city_code, ph_num1.number, ph_num1.additional_number) == std::tie(ph_num2.country_code, ph_num2.city_code, ph_num2.number, ph_num2.additional_number);
}

std::vector<std::string> split_string(std::string src, char delimiter){
    std::vector<std::string> v;
    int src_len = src.length();
    int last_pos = 0;
    for (int i = 0; i < src_len; i++){
        if (src.at(i) == delimiter){
            if (last_pos != i)      // исключаем подряд идущие разделители
                v.push_back(src.substr(last_pos, i - last_pos));
            last_pos = i + 1;
        }
    }
    if (last_pos < src_len)
        v.push_back(src.substr(last_pos, src_len - last_pos));
    return v;
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
    for (int i = 0; i < s.length(); i++){
        char t = s[i];
        if (t == '+' || t == '(' || t == ')')
            s[i] = ' ';
    }
    std::vector<std::string> v = split_string(s, ' ');
    if (v.size() > 4 || v.size() < 3)
        return PhoneNumber();
    if (v.size() == 4)
        ph_num.additional_number = std::stoi(v.back()) ; v.pop_back();
    ph_num.number = std::stoi(v.back()) ; v.pop_back();
    ph_num.city_code = std::stoi(v.back()) ; v.pop_back();
    ph_num.country_code = std::stoi(v.back()) ; v.pop_back();
    return ph_num;
}

Person parse_fullname(std::string s){
    Person p;
    std::vector<std::string> splited = split_string(s, ' ');
    int size = splited.size();
    if (size > 3 || size < 2)
        return Person();
    if (size == 3){
        p.patronymic = splited.back(); splited.pop_back();
    }
    p.surname = splited.back(); splited.pop_back();
    p.name = splited.back();
    return p;
}


std::pair<Person, PhoneNumber> parse_record(std::string record){
    Person p;
    PhoneNumber ph_num;
    int splitter = record.find('+');
    p = parse_fullname(record.substr(0, splitter - 1));
    ph_num = parse_number(record.substr(splitter, record.size() - splitter));
    return std::pair<Person, PhoneNumber>(p, ph_num);
}

int main(int argc, char const *argv[])
{
    std::string record("Ильин Петр Артемович +7(17)455767 57");
    std::string src("123 456 789 aaa bbb ccc  444  555     ");
    std::vector<std::string> v = split_string(record, '+');
    for (auto str : v){
        std::cout << str << std::endl;
    }

    Person p = parse_fullname("Ильин Петр");
    std::cout << (p == Person()) << p << std::endl;

    PhoneNumber n = parse_number("7 ( 17 )455767 57");
    std::cout << (n == PhoneNumber()) << n << std::endl;

    std::pair<Person, PhoneNumber> pp = parse_record("Ильин Петр Артемович +7(17)455767 57");
    std::cout << "Person: " << pp.first << std::endl;
    std::cout << "Number: " << pp.second << std::endl;
    return 0;
}
