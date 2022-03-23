#include <iostream>
#include <cmath>
#include <cstdint>


/*Task 1.*/
class Power
{
private:
	float x;
	float y;

public:
	Power(){
		x = 2.0;
		y = 2.0;
	}

	void set(float a, float b){
		x = a;
		y = b;
	}

	float calculate(){
		return std::pow(x, y);
	}
	
};


/*Task 2.*/
class RGBA{
private:
	std::uint8_t m_red, m_green, m_blue, m_alpha;

public:
	RGBA(){
		m_red = 0;
		m_green = 0;
		m_blue = 0;
		m_alpha = 255;
	}

	RGBA(std::uint8_t r, std::uint8_t g, std::uint8_t b, std::uint8_t a){
		m_red = r;
		m_green = g;
		m_blue = b;
		m_alpha = a;
	}

	void print(){
		std::cout << "(" << int(m_red) << ", " << int(m_green) << ", " << int(m_blue) << ", " << int(m_alpha) << ")" << std::endl;
	}

};

/* Task 3.*/
#define STACK_SIZE 10
class Stack{
private:
	int stack_arr[STACK_SIZE];
	unsigned int sp;

public:
	void reset(){
		for (int i = 0; i < STACK_SIZE; i++){
			stack_arr[i] = 0;
		}
		sp = 0;
	}

	Stack(){
		reset();
	}
	
	bool push(int x){
		if (sp == STACK_SIZE)
			return false;
		stack_arr[sp++] = x;
		return true;
	}

	int pop(){
		int tmp;
		if (sp == 0){
			std::cout << "Err! Stack is empty!" << std::endl;
			return -1;
		}
		tmp = stack_arr[sp];
		stack_arr[--sp] = 0;
		return tmp;
	}

	void print(){
		std::cout << "Stack content: ";
		std::cout << "( ";
		int i = 0;
		while(stack_arr[i] != 0){
			std::cout << stack_arr[i] << " ";
			i++;
		}
		std::cout << ")" << std::endl;
	}

};

int main(int argc, char const *argv[])
{
	// Task 1
	std::cout << "Task 1 results" << std::endl;
	Power *p = new Power();
	std::cout << p->calculate() << std::endl;
	p->set(2.0, 3.0);
	std::cout << p->calculate() << std::endl;
	std::cout << std::endl;

	// Task 2
	std::cout << "Task 2 results" << std::endl;
	RGBA *color_1 = new RGBA();
	color_1->print();
	RGBA *color_2 = new RGBA(55, 55, 55, 230);
	color_2->print();
	std::cout << std::endl;

	// Task 3
	std::cout << "Task 3 results" << std::endl;
	Stack stack;
	stack.reset();
	stack.print();
	stack.push(3);
	stack.push(7);
	stack.push(5);
	stack.print();

	stack.pop();
	stack.print();

	stack.pop();
	stack.pop();
	stack.print();
	stack.pop(); // Here should be error msg

	// clr mem
	delete(p);
	delete(color_1);
	delete(color_2);
	return 0;
}