#ifndef HELPER_H  // not #ifnotdef
#define HELPER_H

#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <tuple>
#include <string>
#include <optional>
#include <iomanip>
#include <algorithm>


bool is_ASCII_printable(std::string s);

struct Person
{
    std::string surname;
    std::string name;
    std::optional<std::string> patronymic;
};

std::ostream &operator<<(std::ostream &os, Person &p);

bool operator<(Person p1, Person p2);

bool operator==(Person p1, Person p2);

struct PhoneNumber
{
    unsigned int country_code;
    unsigned int city_code;
    unsigned int number;
    std::optional<unsigned int> additional_number;
};

std::ostream &operator<<(std::ostream &os, PhoneNumber &ph_num);

bool operator<(PhoneNumber ph_num1, PhoneNumber ph_num2);

bool operator==(PhoneNumber ph_num1, PhoneNumber ph_num2);

std::vector<std::string> split_string(std::string src, char delimiter);

PhoneNumber parse_number(std::string s);

Person parse_fullname(std::string s);

std::pair<Person, PhoneNumber> parse_record(std::string record);

class PhoneBook{
private:
    std::vector<std::pair<Person, PhoneNumber>> records;
public:
    PhoneBook(std::ifstream& ifs);
    void SortByName();
    void SortByPhone();
    std::tuple<std::string, PhoneNumber> GetPhoneNumber(std::string surname);
    void ChangePhoneNumber(Person p, PhoneNumber ph_num);
    friend std::ostream& operator<<(std::ostream& os, const PhoneBook& book);
};

std::ostream& operator<<(std::ostream& os, const PhoneBook& book);


#endif