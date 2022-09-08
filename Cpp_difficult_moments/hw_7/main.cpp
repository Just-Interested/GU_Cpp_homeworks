// main.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <fstream>

#include "classroom.pb.h"

class IRepository {
    virtual void Open(std::ifstream &is) = 0;  
    virtual void Save(std::ofstream &os) = 0; 
};
class IMethods {
    virtual double GetAverageScore(const classroom::FullName& name) = 0;
    virtual std::string GetAllInfo(const classroom::FullName& name) = 0;
    virtual std::string GetAllInfo() = 0;
};

class StudentsGroup : public IRepository, IMethods {
private:
    classroom::StudentsGroup students;
public:
    void IRepository::Open(std::ifstream &is) {
        if (!students.ParseFromIstream(&is)) {
            std::cout << "Parse Error!" << std::endl;
        }
    }
    void IRepository::Save(std::ofstream& os) {
        students.SerializeToOstream(&os);
    }
    double IMethods::GetAverageScore(const classroom::FullName& name) {
        for (auto s : students.students()) {
            if (s.full_name().name() == name.name())
                return s.average_score();
        }
        std::cout << "Student " << name.name() << " not found!" << std::endl;
        return 0;
    }
    std::string IMethods::GetAllInfo(const classroom::FullName& name) {
        for (auto s : students.students()) {
            if (s.full_name().name() == name.name())
                return s.SerializeAsString();
        }
        return "";
    }
    std::string IMethods::GetAllInfo() {
        return students.SerializeAsString();
    }
    void AddStudent(std::string name, std::string surname, double avg_score = 0.0) {
        classroom::Student* tmp = students.add_students();
        tmp->set_average_score(4.5);
        tmp->mutable_full_name()->set_name(name);
        tmp->mutable_full_name()->set_surname(surname);
    }
};


int main()
{
    // Protobuf testing
    //std::cout << "Hello World!\n";
    //classroom::Student st1;
    //st1.add_scores(4);
    //st1.add_scores(5);
    //st1.add_scores(5);
    //double sum = 0;
    //for (auto a : st1.scores()) {
    //    sum += a;
    //}
    //st1.set_average_score(sum / st1.scores_size());
    ////std::cout << st.average_score() << std::endl;
    //st1.mutable_full_name()->set_name("Tony");
    //st1.mutable_full_name()->set_surname("Stark");
    ////std::cout << st1.SerializeAsString() << std::endl;
    //classroom::Student st2;
    //st2.set_average_score(4.5);
    //st2.mutable_full_name()->set_name("Piter");
    //st2.mutable_full_name()->set_surname("Parker");
    ////std::cout << st2.SerializeAsString() << std::endl;
    //classroom::StudentsGroup gp;
    //classroom::Student *tmp = gp.add_students();
    //*tmp = st1;
    //tmp = gp.add_students();
    //*tmp = st2;
    //tmp = gp.add_students();
    //tmp->set_average_score(4.5);
    //tmp->mutable_full_name()->set_name("Nat");
    //tmp->mutable_full_name()->set_surname("Rostova");
    ////std::cout << gp.SerializeAsString() << std::endl;

    // Task 1-3
    StudentsGroup gr;
    gr.AddStudent("Stiven", "Diskein", 4.5);
    //std::cout << gr.GetAllInfo() << std::endl;
    classroom::FullName tmp;
    tmp.set_name("Stiven");
    tmp.set_surname("Diskein");
    //std::cout << gr.GetAllInfo(tmp) << std::endl;
    std::ofstream out("D:\\students_group.bin", std::ios_base::binary);
    gr.Save(out);
    out.close();
    std::ifstream in("D:\\students_group.bin", std::ios_base::binary);
    StudentsGroup g;
    g.Open(in);
    std::cout << g.GetAllInfo() << std::endl;
    return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
