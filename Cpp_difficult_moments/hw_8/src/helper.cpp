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


bool is_ASCII_printable(std::string s){
    for (int i = 0; i < s.length(); i++){
        if (!std::isprint(static_cast<char>(s[i])))
            return false;
    }
    return true;
}

std::ostream &operator<<(std::ostream &os, Person &p)
{
    int aw_name = p.name.length() / 2;  // костыли для форматированного вывода кирилицы
    if (is_ASCII_printable(p.name))     // в частности для подбора значения, передаваемого в функцию setw(n)
        aw_name = 0;                    // для ASCII символов, все и так работает корректно
    int aw_surname = p.surname.length() / 2; // с кирилицей похоже проблема заключается в том, что
    if (is_ASCII_printable(p.surname))      // setw вычисляет разницу между длиной строки и необходимой шириной поля и добавляет нужное количиство "пробелов"
        aw_surname = 0;                     // а для кирилицы каждый выводимый символ кодируется двумя байтами, что и вызывает расхождение
    os << std::setw(20 + aw_surname) << std::right << p.surname << std::setw(15 + aw_name) << std::right << p.name;
    if (p.patronymic){
        int aw_patronymic = (*p.patronymic).length() / 2;
        if (is_ASCII_printable(*p.patronymic))
            aw_patronymic = 0;
        os << std::setw(20 + aw_patronymic) << std::right << *p.patronymic;
    }
    else 
        os << std::setw(20) << std::right << " ";
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
        if (src[i] == delimiter){
            if (last_pos != i)      // исключаем подряд идущие разделители
                v.push_back(src.substr(last_pos, i - last_pos));
            last_pos = i + 1;
        }
    }
    if (last_pos < src_len)
        v.push_back(src.substr(last_pos, src_len - last_pos));
    return v;
}

PhoneNumber parse_number(std::string s){
    PhoneNumber ph_num;
    for (int i = 0; i < s.length(); i++){   // заменяем все разделители на ' '
        char c = s[i];
        if (c == '+' || c == '(' || c == ')')
            s[i] = ' ';
    }
    std::vector<std::string> v = split_string(s, ' ');
    if (v.size() > 4 || v.size() < 3)
        return PhoneNumber();
    if (v.size() == 4){
        ph_num.additional_number = std::stoi(v.back()); 
        v.pop_back();
    }
    ph_num.number = std::stoi(v.back()) ; v.pop_back();
    ph_num.city_code = std::stoi(v.back()) ; v.pop_back();
    ph_num.country_code = std::stoi(v.back()); v.pop_back();
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
    p.name = splited.back(); splited.pop_back();
    p.surname = splited.back(); splited.pop_back();
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

PhoneBook::PhoneBook(std::ifstream& ifs){
    std::string c_line;
    while(std::getline(ifs, c_line)){
        records.push_back(parse_record(c_line));
    }
}

void PhoneBook::SortByName(){
    std::sort(this->records.begin(), this->records.end(), [](std::pair<Person, PhoneNumber> a, std::pair<Person, PhoneNumber> b){
        return a.first < b.first;
    });
}

void PhoneBook::SortByPhone(){
        std::sort(this->records.begin(), this->records.end(), [](std::pair<Person, PhoneNumber> a, std::pair<Person, PhoneNumber> b){
            return a.second < b.second;
        });
}

std::tuple<std::string, PhoneNumber> PhoneBook::GetPhoneNumber(std::string surname){
    std::tuple<std::string, PhoneNumber> t = std::make_tuple("not found", PhoneNumber());
    PhoneNumber ph_num;
    int n_rec = 0;
    for (auto rec : this->records){
        if (rec.first.surname == surname){
            ph_num = rec.second;
            n_rec++;
        }
    }
    if (n_rec == 1)
        t = std::make_tuple("", ph_num);
    if (n_rec > 1)
        t = std::make_tuple("found more than 1", PhoneNumber());
    return t;
}

void PhoneBook::ChangePhoneNumber(Person p, PhoneNumber ph_num){
    for (auto &rec : this->records){
        if (rec.first == p){
            rec.second = ph_num;
            break;
        }
    }
}

std::ostream& operator<<(std::ostream& os, const PhoneBook& book);

std::ostream& operator<<(std::ostream& os, const PhoneBook& book){
    for (auto record : book.records){
        os << record.first << "   "  << record.second << std::endl;
    }
    return os;
}