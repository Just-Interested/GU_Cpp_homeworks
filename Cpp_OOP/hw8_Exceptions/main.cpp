#include <iostream>

// Task 1
template <class T>
T Div(T numerator, T denominator){
    if (denominator == 0)
        throw std::string("Division by zero!");
    return numerator / denominator;
}


// Task 2
class Ex{
private:
    float x;
public:
    Ex(float x) : x(x){}
    float get(){
        return x;
    }
};

class Bar{
private:
    float y;
public:
    Bar(){
        y = 0.0;
    }
    void set(float a){
        if (y + a > 100)
            throw Ex(a*y);
        y = a;
    }
};


// Task 3
class OffTheField{
private:
    int current_pos_x;
    int current_pos_y;
    int vector_ix;
    int vector_iy;
    const std::string msg = "Error! Out of the field!";
public:
    OffTheField(int c_pos_x, int c_pos_y, int ix, int iy){
        current_pos_x = c_pos_x;
        current_pos_y = c_pos_y;
        vector_ix = ix;
        vector_iy = iy;
    }
    friend std::ostream& operator<<(std::ostream& os, OffTheField& e);
};

std::ostream& operator<<(std::ostream& os, OffTheField& e){
    os << e.msg << std::endl;
    os << "Current position: x = " << e.current_pos_x << ", y = " << e.current_pos_y << std::endl;
    os << "Step direction: x = " << e.vector_ix << ", y = " << e.vector_iy << std::endl;
    return os;
}


class IllegalCommand{
private:
    int current_pos_x;
    int current_pos_y;
    int vector_ix;
    int vector_iy;
    int step_size_x;
    int step_size_y;
    const std::string msg = "Error! Jumps not allowed!";
public:
    IllegalCommand(int c_pos_x, int c_pos_y, int ix, int iy, int step_size_x, int step_size_y){
        current_pos_x = c_pos_x;
        current_pos_y = c_pos_y;
        vector_ix = ix;
        vector_iy = iy;
        this->step_size_x = step_size_x;
        this->step_size_y = step_size_y;
    }
    friend std::ostream& operator<<(std::ostream& os, IllegalCommand& e);
};

std::ostream& operator<<(std::ostream& os, IllegalCommand& e){
    os << e.msg << std::endl;
    os << "Current position: x = " << e.current_pos_x << ", y = " << e.current_pos_y << std::endl;
    os << "Step direction: x = " << e.vector_ix << ", y = " << e.vector_iy << std::endl;
    os << "Step size x =  " << e.step_size_x << ", y = " << e.step_size_y << ". Acceptable values 0 or 1" << std::endl;
    return os;
}



#define FIELD_SIZE 10
class Robot{
private:
    int current_position_x;
    int current_position_y;
public:
    Robot(){
        current_position_x = FIELD_SIZE / 2;
        current_position_y = FIELD_SIZE / 2;
    }

    enum X {LEFT = -1, STAY_X = 0, RIGHT = 1};
    enum Y {BOTTOM = -1, STAY_Y = 0, TOP = 1};
    // тут я не понял как можно получить "неверная команда (направление не находится в нужном диапазоне)"
    // всего же 8 направлений, какие нам запрещены?
    /*void step(X ix, Y iy){
        current_position_x += ix;
        current_position_y += iy;
    }*/
    // потому добавил в функцию вожможность шагать более чем на 1 клетку
    // но при этом "большие шаги" вызывают исключение
    void step(X ix, Y iy, unsigned int step_size_x = 1, unsigned int step_size_y = 1){
        if (step_size_x < 0 || step_size_y < 0 || step_size_x > 1 || step_size_y > 1)
            throw IllegalCommand(current_position_x, current_position_y, ix, iy, step_size_x, step_size_y);
        int tmp_x = current_position_x + ix * step_size_x;
        int tmp_y = current_position_y + iy * step_size_y;
        if (tmp_x > FIELD_SIZE || tmp_y > FIELD_SIZE || tmp_x < 0 || tmp_y < 0)
            throw OffTheField(current_position_x, current_position_y, ix, iy);
        current_position_x += ix * step_size_x;
        current_position_y += iy * step_size_y;
    }

    int get_x() {
        return current_position_x;
    }

    int get_y() {
        return current_position_y;
    }
};

int main(int argc, char* argv[]){
    // Task 1 tests
    try{
        std::cout << Div(3, 2) << std::endl;
        std::cout << Div(4.6, 2.0) << std::endl;
        std::cout << Div(3.8, 0.0) << std::endl;
    }
    catch (std::string err){
        std::cout << err << std::endl;
    }
    
    // Task 2 tests
    Bar bar;
    int a = 1;
    while (a != 0){
        std::cin >> a;
        try {
            bar.set(a);
        }
        catch (Ex e){
            std::cout << "Exception data: " << e.get() << std::endl;
        }
        catch (...){
            std::cout << "Unknown error!" << std::endl;
        }
    }

    // Task 3 tests
    Robot robot;
    std::cout << robot.get_x() << "x" << robot.get_y() << std::endl;
    robot.step(Robot::LEFT, Robot::BOTTOM, 1, 1);
    std::cout << robot.get_x() << "x" << robot.get_y() << std::endl;
    try {
        robot.step(Robot::LEFT, Robot::TOP);
        robot.step(Robot::LEFT, Robot::TOP);
        robot.step(Robot::LEFT, Robot::TOP);
        robot.step(Robot::LEFT, Robot::TOP);
        robot.step(Robot::LEFT, Robot::TOP);
    }
    catch(OffTheField e){
        std::cout << e;
    }
    catch(IllegalCommand e){
        std::cout << e;
    }
    catch(...){
        std::cout << "Unknown exception!" << std::endl;
    }
    return 0;
}