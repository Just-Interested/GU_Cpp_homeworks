#include <iostream>
#include <math.h>


// Task 1.
class Figure{
public:
	virtual float area() = 0;
};


class Parallelogram : public Figure{
protected:
	float a;
	float b;
	float h_a; // высота, проведенная к основанию a
public:
	Parallelogram(){
		a = 5;
		b = 4;
		h_a = 3;
	}

	Parallelogram(float a, float b, float h_a){
		this->a = a;
		this->b = b;
		this->h_a = h_a;
	}

	virtual float area() override {
		return a*h_a;
	}
};


class Circle : public Figure{
protected:
	float radius;
public:
	Circle(){
		radius = 1.0;
	}
	Circle(float radius){
		this->radius = radius;
	}
	float area() override {
		return radius * 2 * M_PI;
	}
};


class Rectangle : public Parallelogram{
public:
	Rectangle(){
		a = 5;
		b = 3;
		h_a = b;
	}
	Rectangle(float a, float b){
		this->a = a;
		this->b = b;
		this->h_a = b;
	}
	// переопределять функцию area() нет необходимости
};


class Square : public Parallelogram{
public:
	Square(){
		a = 3;
		b = a;
		h_a = a;
	}
	Square(float a){
		this->a = a;
		this->b = a;
		this->h_a = a;
	}
	// переопределять функцию area() нет необходимости

};


class Rhombus : public Parallelogram{
public:
	Rhombus(){
		a = 3;
		b = a;
		h_a = 2.5;
	}
	Rhombus(float a, float h_a){
		this->a = a;
		this->b = a;
		this->h_a = h_a;
	}
	// переопределять функцию area() нет необходимости
};


// Task 2.
class Car {
protected:
	std::string company;
	std::string model;
public:
	Car(){
		company = "";
		model = "";
		std::cout << "Generic car created." << std::endl;
	}
};

class PassengerCar : /*virtual*/ public Car{
public:
	PassengerCar(){
		std::cout << "Passenger car created." << std::endl;
	}
};

class Bus : /*virtual*/ public Car{
public:
	Bus(){
		std::cout << "Bus car created." << std::endl;
	}
};

class Minivan : public PassengerCar, public Bus{
public:
	Minivan(){
		std::cout << "Minivan car created." << std::endl;
	}
};

// Task 3.
class Fraction {
private:
	int numerator;
	int denominator;
public:
	Fraction(){
		numerator = 1;
		denominator = 1;
	}
	Fraction(int numerator, int denominator){
		this->numerator = numerator;
		if (denominator == 0){
			std::cout << "Error! Denominator cannot be zero!" << std::endl;
			this->denominator = 1;
		}
		else {
			this->denominator = denominator;
		}
	}
	static int calculate_NOD(int x, int y){ 
		if (x % y == 0)
			return y;
		if (y % x == 0)
			return x;
		if (x > y)
			return calculate_NOD(x % y, y);
		return calculate_NOD(x, y % x);
	}
	static int calculate_NOK(int x, int y){ 
		return (x * y) / std::abs(calculate_NOD(x, y));
	}
	void normalize(){
		int NOD = std::abs(calculate_NOD(this->numerator, this->denominator));
		this->numerator = this->numerator / NOD;
		this->denominator = this->denominator / NOD;
	}
	int get_numerator() const{
		return this->numerator;
	}
	int get_denominator() const{
		return this->denominator;
	}
	void print() {
		this->normalize();
		std::cout << numerator << "/" << denominator << std::endl;
	}
	std::string to_text() const{
		return std::to_string(this->numerator) + "/" + std::to_string(denominator);
	}
	// попробуем переопределить операторы в методах класса...
	Fraction operator+(int x) const {
		int new_numerator = this->numerator + this->denominator * x;
		return Fraction(new_numerator, this->denominator);
	}
	Fraction operator+(Fraction& fr) const {
		int nok = calculate_NOK(this->denominator, fr.denominator);
		int numerator_1 = this->numerator * (nok / this->denominator);
		int numerator_2 = fr.numerator * (nok / fr.denominator);
		return Fraction(numerator_1 + numerator_2, nok);
	}
	Fraction operator-(int x) const {
		int new_numerator = this->numerator - this->denominator * x;
		return Fraction(new_numerator, this->denominator);
	}
	Fraction operator-(Fraction& fr) const {
		int nok = calculate_NOK(this->denominator, fr.denominator);
		int numerator_1 = this->numerator * (nok / this->denominator);
		int numerator_2 = fr.numerator * (nok / fr.denominator);
		return Fraction(numerator_1 - numerator_2, nok);
	}
	Fraction operator*(int x) const {
		int new_numerator = this->numerator * x;
		return Fraction(new_numerator, this->denominator);
	}
	Fraction operator*(Fraction& fr) const {
		return Fraction(this->numerator * fr.numerator, this->denominator * fr.denominator);
	}
	Fraction operator/(int x) const {
		int new_denominator = this->denominator * x;
		return Fraction(this->numerator, new_denominator);
	}
	Fraction operator/(Fraction& fr) const {
		if (fr.numerator == 0){
			std::cout << "Error! Division by zero!" << std::endl;
			return Fraction();
		}
		return Fraction(this->numerator * fr.denominator, this->denominator * fr.numerator);
	}
	Fraction operator-() const{
		return Fraction(-this->numerator, this->denominator);
	}
};

// ... а также в отдельных функциях
bool operator==(Fraction& fr1, Fraction& fr2) {
		int NOK = Fraction::calculate_NOK(fr1.get_denominator(), fr2.get_denominator());
		int numerator1 = fr1.get_numerator() * (NOK / fr1.get_denominator());
		int numerator2 = fr2.get_numerator() * (NOK / fr2.get_denominator());
		return (numerator1 == numerator2);
}

bool operator!=(Fraction& fr1, Fraction& fr2) {
		return !(fr1 == fr2);
}

bool operator>(Fraction& fr1, Fraction& fr2) {
		int NOK = Fraction::calculate_NOK(fr1.get_denominator(), fr2.get_denominator());
		int numerator1 = fr1.get_numerator() * (NOK / fr1.get_denominator());
		int numerator2 = fr2.get_numerator() * (NOK / fr2.get_denominator());
		return (numerator1 > numerator2);
}

bool operator<=(Fraction& fr1, Fraction& fr2) {
		return !(fr1 > fr2);
}

bool operator<(Fraction& fr1, Fraction& fr2) {
		int NOK = Fraction::calculate_NOK(fr1.get_denominator(), fr2.get_denominator());
		int numerator1 = fr1.get_numerator() * (NOK / fr1.get_denominator());
		int numerator2 = fr2.get_numerator() * (NOK / fr2.get_denominator());
		return (numerator1 < numerator2);
}

bool operator>=(Fraction& fr1, Fraction& fr2) {
		return !(fr1 < fr2);
}

//Task 4.
class Card{
public:
	enum Suit {SPADES, HEARTS, DIAMONDS, CLUBS};
	enum Rank {ACE = 1, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN,
               JACK, QUEEN, KING};
	Card(){
		this->rank = ACE;
		this->suit = SPADES;
		is_opened = false;
	}
	Card(Rank rank, Suit suit, bool is_opened){
		this->rank = rank;
		this->suit = suit;
		is_opened = false;
	}
	void flip() {
		is_opened = !is_opened;
	}
	int get_value() const{
		if (this->rank > 10)
			return 10;
		return rank;
	}
	void show() const{
		std::cout << "**** CARD ****" << std::endl;
		std::cout << "Rank: ";
		switch(this->rank){
			case ACE : std::cout << "ACE" << std::endl;   break;
			case TWO : std::cout << "TWO" << std::endl;   break;
			case THREE : std::cout << "THREE" << std::endl;   break;
			case FOUR : std::cout << "FOUR" << std::endl;   break;
			case FIVE : std::cout << "FIVE" << std::endl;   break;
			case SIX : std::cout << "SIX" << std::endl;   break;
			case SEVEN : std::cout << "SEVEN" << std::endl;   break;
			case EIGHT : std::cout << "EIGHT" << std::endl;   break;
			case NINE : std::cout << "NINE" << std::endl;   break;
			case TEN : std::cout << "TEN" << std::endl;   break;
			case JACK : std::cout << "JACK" << std::endl;   break;
			case QUEEN : std::cout << "QUEEN" << std::endl;   break;
			case KING : std::cout << "KING" << std::endl;   break;
		}
		std::cout << "Suit: ";
		switch(this->suit){
			case SPADES : std::cout << "SPADES" << std::endl;   break;
			case HEARTS : std::cout << "HEARTS" << std::endl;   break;
			case DIAMONDS : std::cout << "DIAMONDS" << std::endl;   break;
			case CLUBS : std::cout << "CLUBS" << std::endl;   break;
		}
		std::cout << "Value: " << get_value() << std::endl; 
		std::cout << "**************" << std::endl;
	}
private:
	Suit suit;
	Rank rank;
	bool is_opened;
};


int main(int argc, char const *argv[])
{
	// Task 1 tests
	std::cout << "Task 1." << std::endl;
	Parallelogram p(4, 5, 3);
	std::cout << p.area() << std::endl;
	Circle c(3.0);
	std::cout << c.area() << std::endl;
	Rectangle r(3, 4);
	std::cout << r.area() << std::endl;
	Square s(4);
	std::cout << s.area() << std::endl;
	Rhombus rh(4, 3);
	std::cout << rh.area() << std::endl;
	std::cout << std::endl;

	/// Task 2 test
	std::cout << "Task 2." << std::endl;
	Car gc;
	std::cout << "--------------" << std::endl;
	PassengerCar pc;
	std::cout << "--------------" << std::endl;
	Bus bc;
	std::cout << "--------------" << std::endl;
	Minivan mc;
	std::cout << std::endl;

	
	//Task 3 test
	std::cout << "Task 3." << std::endl;
	std::cout << Fraction::calculate_NOD(18, 27) << std::endl;
	std::cout << Fraction::calculate_NOK(35, 7) << std::endl;
	Fraction fr1(3,4);
	Fraction fr2(5,4);
	Fraction fr3(3,4);
	Fraction fr_result = fr1 + fr2;
	fr_result.print();
	fr_result = fr1 - fr2;
	fr_result.print();
	fr_result = fr1 * fr2;
	fr_result.print();
	fr_result = fr1 / fr2;
	fr_result.print();
	fr_result = fr1 / 3;
	fr_result.print();
	fr_result = -fr_result;
	fr_result.print();
	std::cout << "Fraction 1 and fraction 2 are" << ((fr1 == fr2) ? " " : " not ") << "equal." << std::endl;
	std::cout << "Fraction 1 and fraction 3 are" << ((fr1 == fr3) ? " " : " not ") << "equal." << std::endl;
	std::cout << "Fraction 1 and fraction 3 are" << ((fr1 != fr3) ? " not " : " ") << "equal." << std::endl;
	std::cout << "Fraction 1" << ((fr1 > fr2) ? " > " : " <= ") << "fraction 2." << std::endl;
	std::cout << "Fraction 1" << ((fr1 < fr2) ? " < " : " >= ") << "fraction 2." << std::endl;
	std::cout << "Fraction 1" << ((fr1 <= fr3) ? " <= " : " > ") << "fraction 3." << std::endl;
	std::cout << "Fraction 1" << ((fr1 >= fr3) ? " >= " : " < ") << "fraction 3." << std::endl;
	std::cout << std::endl;
	
	// Task 4 test;
	std::cout << "Task 4." << std::endl;
	Card card(Card::TWO, Card::CLUBS, 0);
	card.show();
	std::cout << std::endl;

	return 0;
}