#include <iostream>
#include <vector>
#include <gtest/gtest.h>
#include <helper.h>

// частичное покрытие тестами

TEST(helper, split_string){
    // Arrange
    int count1 = 5;
    int count2 = 2;
    std::string s1(" 11 22-22   33';!@#$%^&*()  4      5asdfgf "); // test string

    // Act 
    std::vector<std::string> v = split_string(s1, ' ');
    std::vector<std::string> v2 = split_string(s1, '-');

    // Assert
    ASSERT_EQ(v.size(), count1);
    ASSERT_EQ(v2.size(), count2);
}

TEST(helper, parse_number){
    // Arrange
    std::string number(" +7 (17)   455767   57");

    // Act
    PhoneNumber ph_num = parse_number(number);

    // Assert
    ASSERT_EQ(ph_num.country_code, 7);
    ASSERT_EQ(ph_num.city_code, 17);
    ASSERT_EQ(ph_num.number, 455767);
    ASSERT_EQ(ph_num.additional_number, 57);
}

TEST(helper, parse_fullname){
    // Arrange
    std::string fullname(" Ильин   Петр   Артемович ");

    // Act
    Person p = parse_fullname(fullname);

    // Assert
    ASSERT_EQ(p.name, "Петр");
    ASSERT_EQ(p.surname, "Ильин");
    ASSERT_EQ(p.patronymic, "Артемович");
}

TEST(helper, parse_record){
    // Arrange
    std::string plain_record("Ильин Петр Артемович +7(17)455767 57");

    // Act
    std::pair<Person, PhoneNumber> book_record = parse_record(plain_record);

    // Assert
    ASSERT_EQ(book_record.first.name, "Петр");
    ASSERT_EQ(book_record.first.surname, "Ильин");
    ASSERT_EQ(book_record.first.patronymic, "Артемович");
    ASSERT_EQ(book_record.second.country_code, 7);
    ASSERT_EQ(book_record.second.city_code, 17);
    ASSERT_EQ(book_record.second.number, 455767);
    ASSERT_EQ(book_record.second.additional_number, 57);
}


int main(int argc, char** argv){
    testing::InitGoogleTest(&argc, argv);
    int result = RUN_ALL_TESTS();
    return result;
}