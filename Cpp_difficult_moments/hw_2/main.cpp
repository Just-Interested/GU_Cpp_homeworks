#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <sstream>
#include <fstream>
#include <codecvt>
#include <locale>
#include <chrono>


template<typename T>
void Swap(T*& ptr1, T*& ptr2){
    T* tmp = ptr1;
    ptr1 = ptr2;
    ptr2 = tmp;
}

template<typename T>
void SortPointers(std::vector<T*> &v){
    std::sort(v.begin(), v.end(), [](T* a, T* b){
        return *a < *b;
    });
}


int CountVowelsW_0(std::wstring &s){
    std::wstring vowels(L"аеёиоуыэюяАЕЁИОУЫЭЮЯaeiouyAEIOUY");
    int n = std::count_if(s.begin(), s.end(), [&vowels](auto c){
        return vowels.find(c) != std::wstring::npos;
    });
    return n;
}

int CountVowelsW_1(std::wstring &s){
    std::wstring vowels(L"аеёиоуыэюяАЕЁИОУЫЭЮЯaeiouyAEIOUY");
    int n = std::count_if(s.begin(), s.end(), [&vowels](auto c){
        for (auto v : vowels)
            if (v == c)
                return 1;
        return 0;
    });
    return n;
}

int CountVowelsW_2(std::wstring &s){
    std::wstring vowels(L"аеёиоуыэюяАЕЁИОУЫЭЮЯaeiouyAEIOUY");
    int n = 0; 
    for (auto c : s){
        if (vowels.find(c) != std::wstring::npos)
            n++;
    }
    return n;
}

int CountVowelsW_3(std::wstring &s){
    std::wstring vowels(L"аеёиоуыэюяАЕЁИОУЫЭЮЯaeiouyAEIOUY");
    int n = 0; 
    for (auto c : s){
        for (auto v : vowels)
            if (v == c)
                n++; 
    }
    return n;
}


int main(int, char**) {
    // Task 1
    int a = 10;
    int b = 20;
    int* p1 = &a;
    int* p2 = &b;
    std::cout << "p1: " << p1 << " p1_val: " << *p1 << std::endl;
    std::cout << "p2: " << p2 << " p2_val: " << *p2 << std::endl;
    Swap(p1, p2);
    std::cout << "p1: " << p1 << " p1_val: " << *p1 << std::endl;
    std::cout << "p2: " << p2 << " p2_val: " << *p2 << std::endl;

    // Task2 
    std::vector<int*> v;
    std::srand(1117);
    int n1 = std::rand();
    int n2 = std::rand();
    int n3 = std::rand();
    int n4 = std::rand();
    int n5 = std::rand();
    v.push_back(&n1);
    v.push_back(&n2);
    v.push_back(&n3);
    v.push_back(&n4);
    v.push_back(&n5);
    for(auto p : v){
        std::cout << *p << std::endl;
    }
    SortPointers(v);
    std::cout << " " << std::endl;
    for(auto p : v){
        std::cout << *p << std::endl;
    }

    // Task 3
    std::wifstream in("D:\\voina-i-mir.bak");
    std::wstringstream ss;
    in.imbue(std::locale(std::locale(), new std::codecvt_utf8<wchar_t>));
    ss << in.rdbuf();
    std::wstring s = ss.str();
    auto start = std::chrono::high_resolution_clock::now();
    n1 = CountVowelsW_0(s);
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::duration<double, std::ratio<1>>>(end - start);
    std::cout << "count_if и find: " << (duration.count() * 1000)  << " ms" << std::endl;

    start = std::chrono::high_resolution_clock::now();
    n2 = CountVowelsW_1(s);
    end = std::chrono::high_resolution_clock::now();
    duration = end - start;
    std::cout << "count_if и цикл for: " << (duration.count() * 1000)  << " ms" << std::endl;

    start = std::chrono::high_resolution_clock::now();
    n3 = CountVowelsW_2(s);
    end = std::chrono::high_resolution_clock::now();
    duration = end - start;
    std::cout << "цикл for и find: " << (duration.count() * 1000)  << " ms" << std::endl;

    start = std::chrono::high_resolution_clock::now();
    n4 = CountVowelsW_3(s);
    end = std::chrono::high_resolution_clock::now();
    duration = end - start;
    std::cout << "2 цикла for: " << (duration.count() * 1000)  << " ms" << std::endl;

    std::cout << n1 << " " << n2 << " " << n3 << " " << n4 << std::endl;
}
