#include <iostream>
#include <vector>
#include <array>
#include <set>
#include <iomanip>
#include <algorithm>
#include <map>

// Task 1
template<typename T, typename Iterator>
void print_uniq(const Iterator &start, const Iterator &end){
    std::set<T> set;
    std::copy(start, end, std::inserter(set, set.begin()));
    for (T el : set){
        std::cout << el << " ";
    }
    std::cout << std::endl;
}


// Task 2
int word_count(std::string s){
    int n_spaces = std::count(s.begin(), s.end(), ' ');
    if (s.at(0) == ' ')
        return n_spaces;
    return n_spaces + 1;
}

std::multimap<int, std::string> get_sentences_by_word_count(std::string text, char delimiter){
    auto c_pos = text.find(delimiter);
    auto l_pos = 0;
    std::multimap<int, std::string> map;
    std::string sentence;
    while (c_pos != std::string::npos)
    {
        sentence = text.substr(l_pos, c_pos - l_pos + 1);
        map.insert(std::make_pair(word_count(sentence), sentence));
        l_pos = ++c_pos;
        c_pos = text.find(delimiter, l_pos);
    }
    return map;
}



int main(int, char**) {
    // Task 1 tests
    std::vector<std::string> names_v = {"John", "Stiven", "Roland", "John", "Bill", "Homer", "Rick", "Bill", "Morty"};
    print_uniq<std::string, std::vector<std::string>::iterator>(names_v.begin(), names_v.end());
    std::array<std::string, 9> names_a{"John", "Stiven", "Roland", "John", "Bill", "Homer", "Rick", "Bill", "Morty"};
    print_uniq<std::string>(names_a.begin(), names_a.end());


    // Task 2
    std::string text;
    std::getline(std::cin, text);
    std::multimap<int, std::string> sentences = get_sentences_by_word_count(text, '.');
    std::for_each(sentences.begin(), sentences.end(), [](std::pair<int, std::string> p){
        std::cout << p.first << " " << p.second << std::endl;
    });
    return 0;
}
