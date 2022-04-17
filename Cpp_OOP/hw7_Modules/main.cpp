#include <iostream>
#include <memory>


// Task 1
class Date{
private:
    int day, month, year;
public:
    Date(int day, int month, int year){
        this->day = day;
        this->month = month;
        this->year = year;
    }
    int get_day() const { return day; }
    int get_month() const { return month; }
    int get_year() const { return year; }
    friend std::ostream& operator<<(std::ostream& os, Date& r_date);
};

std::ostream& operator<<(std::ostream& os, Date& r_date){
    os << r_date.day << "." << r_date.month << "." << r_date.year << std::endl;
    return os;
}


// Task 2
// Знаю, что метод может показаться странным, но мне это показалось легче, чем городить if'ы.
// Идея в том, чтобы назначить нужные "веса" каждому параметру.
// Таким образом я смогу получить результирующий "вес" в зависимости от значимости каждого параметра 
// Сравнив результаты, получу большее значение. 
Date& get_later(std::shared_ptr<Date> &date1, std::shared_ptr<Date> &date2){
    int days_1 = date1->get_year() * 500 + date1->get_month() * 35 + date1->get_day();
    int days_2 = date2->get_year() * 500 + date2->get_month() * 35 + date2->get_day();
    return (days_1 > days_2) ? *date1 : *date2; 
}

template <class T>
void swap_ptrs(std::shared_ptr<T> &ptr1, std::shared_ptr<T> &ptr2){
    ptr1.swap(ptr2);
}


int main(int argc, char* argv[]){

    // Task 1 tests
    std::shared_ptr<Date> today(new Date(12, 4, 2022));
    std::shared_ptr<Date> date;
    std::cout << today->get_day() << "." << today->get_month() << "." << today->get_year() << std::endl;
    std::cout << *today;
    date = today;
    if (today)
        std::cout << "Today: " << *today;
    else
        std::cout << "Null pointer!" << std::endl;
    if (date)
        std::cout << "Date: " << *date;
    else
        std::cout << "Null pointer!" << std::endl;

    std::cout << "Today count: " << today.use_count() << std::endl;
    std::cout << "Date count: " << date.use_count() << std::endl;


    // Task 2 tests
    std::shared_ptr<Date> date1 = std::make_shared<Date>(1, 10, 2000);
    std::shared_ptr<Date> date2 = std::make_shared<Date>(31, 9, 2000);;
    std::cout << get_later(date1, date2);
    std::cout << *date2;
    swap_ptrs<Date>(date1, date2);
    std::cout << *date2;

    return 0;
}