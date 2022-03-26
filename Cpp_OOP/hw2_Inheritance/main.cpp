#include <iostream>


// Task 1.
class Person{
protected:
	std::string name;
	std::string gender; // was a time, when this field might be boolean
	int age;
	int weight;
public:
	Person(){
		name = "Jonh";
		gender = "Male";
		age = 18;
		weight = 73;
	}
	Person(std::string name, std::string gender, int age, int weight){
		this->name = name;
		this->gender = gender;
		this->age = age;
		this->weight = weight;
	}

	void set_name(std::string name){
		this->name = name;
	}

	void set_gender(std::string gender){
		this->gender = gender;
	}

	void set_age(int age){
		this->age = age;
	}

	void set_weight(int weight){
		this->weight = weight;
	}

	std::string get_name() const {
		return name;
	}

	std::string get_gender() const {
		return gender;
	}

	int get_age() const {
		return age;
	}

	int get_weight() const {
		return weight;
	}

	void print_person_info() const {
		std::cout << "**********************" << std::endl;
		std::cout << "Name: " << name << std::endl;
		std::cout << "Gender: " << gender << std::endl;
		std::cout << "Age: " << age << std::endl;
		std::cout << "Weight: " << weight << std::endl;
		std::cout << "**********************" << std::endl;
		std::cout << std::endl;
	}

};



class Student : public Person{
private:
	static int num_of_students; 
	int year_of_study;
public:
	Student(){
		num_of_students++;
		year_of_study = 1;
	}

	Student(std::string name, std::string gender, int age, int weight, int year_of_study){
		num_of_students++;
		this->name = name;
		this->gender = gender;
		this->age = age;
		this->weight = weight;
		this->year_of_study = year_of_study;
	}

	~Student(){
		num_of_students--;
	}

	static int get_num_of_students(){
		return num_of_students;
	}

	int get_year_of_study() const {
		return year_of_study;
	}

	void set_year_of_study(int year_of_study){
		this->year_of_study = year_of_study;
	}

	void increment_year_of_study(){
		year_of_study++;
	}

	void print_person_info() const {
		std::cout << "**********************" << std::endl;
		std::cout << "Name: " << name << std::endl;
		std::cout << "Gender: " << gender << std::endl;
		std::cout << "Age: " << age << std::endl;
		std::cout << "Weight: " << weight << std::endl;
		std::cout << "Year of study: " << year_of_study << std::endl;
		std::cout << "**********************" << std::endl;
		std::cout << std::endl;
	}
};
int Student::num_of_students = 0;


// Task 2.

class Fruit{
protected:
	std::string name;
	std::string color;
public:
	Fruit(){
		name = "";
		color = "";
	}
	std::string getName(){
		return name;
	}

	std::string getColor(){
		return color;
	}
};



class Apple : public Fruit{
public:
	Apple(){
		name = "apple";
		color = "";
	}

	Apple(std::string color){
		this->name = "apple";
		this->color = color;
	}
};



class Banana : public Fruit{
public:
	Banana(){
		name = "banana";
		color = "yellow";
	}
};



class GrannySmith : public Apple{
public:
	GrannySmith(){
		name = "Granny Smith apple";
		color = "green";
	}
};


int main(int argc, char const *argv[])
{
	// Task 1. Test
	Student s;
	s.print_person_info();
	s.set_year_of_study(3);
	s.increment_year_of_study();
	s.print_person_info();
	std::cout << "Number of students: " << Student::get_num_of_students() << std::endl;
	Student alice("Alice", "Female", 19, 51, 1);
	alice.print_person_info();
	Student bob("Bob", "Male", 21, 83, 3);
	bob.print_person_info();
	std::cout << "Number of students: " << Student::get_num_of_students() << std::endl;

	// Task 2. Test
	Apple a("red");
	Banana b;
	GrannySmith c;

	std::cout << "My " << a.getName() << " is " << a.getColor() << ".\n";
	std::cout << "My " << b.getName() << " is " << b.getColor() << ".\n";
	std::cout << "My " << c.getName() << " is " << c.getColor() << ".\n";

	return 0;
}

// Task 3.
/*
Думаю для реализации игры в Blackjack создам классы 
1. Игра
	Свойства:
		Набор колод карт
		Игроки
		Дилер
	Методы:
		Добавить колоду
		Добавить игрока
		Добавить дилера
		Старт игры
		Конец игры
2. Колода
	Свойства:
		Набор карт
	Методы:
		Перемешать
		Добавить карту
		Извлечь карту
3. Карта (для консольной версии наверное можно обойтись и без класса, т.к. нужна только ценность карты)
	Свойства:
		Масть
		"Тип" (1, 2, ... 10, Валет и т.д.)
		"Ценность" (1 - 1, Король - 4 и т.д.)
	Методы:
		Получить ценность
4.1 Игрок
4.2 Дилер
	Поскольку у игрока и дилера есть ряд общих свойств и методов, то можно
	создать общий базовый класс и от него наследоваться
	Общие свойства:
		Рука
	Общие методы:
		Взять еще карту
		"Остановиться"
		Посчитать очки
5. Рука 
	Свойства:
		Набор карт
	Методы:
		Добавить карту
		Посчитать очки
*/