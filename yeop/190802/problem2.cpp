// Employee 와 Manager 에서 다르게 쓰이는 함수가 있다. -> 이를 같은 함수를 사용하도록 
// 만들어주자.
// 그래서 계산 값이 원하는 값으로 나오지 않는다. 

/*

오답 예시 : 
노홍철 (평사원 , 34) ==> 250만원
하하 (평사원 , 34) ==> 250만원
유재석 (부장 , 41) ==> 550만원
정준하 (과장 , 43) ==> 400만원
박명수 (차장 , 43) ==> 450만원
정형돈 (대리 , 36) ==> 300만원
길 (인턴 , 36) ==> 100만원
총 비용 : 2300만원  
 
정답 예시 :
노홍철 (평사원 , 34) ==> 250만원
하하 (평사원 , 34) ==> 250만원
유재석 (부장 , 41, 12년차) ==> 610만원
정준하 (과장 , 43, 15년차) ==> 475만원
박명수 (차장 , 43, 13년차) ==> 515만원
정형돈 (대리 , 36) ==> 300만원
길 (인턴 , 36) ==> 100만원
총 비용 : 2500만원 
 */

#include <iostream>
#include <string>

class Employee {
protected:
    std::string name;
    int age;

    std::string position;  // 직책 (이름)
    int rank;              // 순위 (값이 클 수록 높은 순위)

public:
    Employee(std::string name, int age, std::string position, int rank)
        : name(name), age(age), position(position), rank(rank) {}

  // 복사 생성자
    Employee(const Employee& employee) {
        name = employee.name;
        age = employee.age;
        position = employee.position;
        rank = employee.rank;
    }

  // 디폴트 생성자
    Employee() {}

    void print_info() {
        std::cout << name << " (" << position << " , " << age << ") ==> "
                << calculate_pay() << "만원" << std::endl;
    }
    int calculate_pay() { return 200 + rank * 50; }
};

class Manager : public Employee {
    int year_of_service;

public:
    Manager(std::string name, int age, std::string position, int rank, int year_of_service)
      : year_of_service(year_of_service), Employee(name, age, position, rank) {}

  // 복사 생성자
    Manager(const Manager& manager)
        : Employee(manager.name, manager.age, manager.position, manager.rank) {
        year_of_service = manager.year_of_service;
    }

  // 디폴트 생성자
    Manager() : Employee() {}

    int calculate_pay() { return 200 + rank * 50 + 5 * year_of_service; }
    void print_info() {
        std::cout << name << " (" << position << " , " << age << ", "
              << year_of_service << "년차) ==> " << calculate_pay() << "만원"
              << std::endl;
    }
};

class EmployeeList {
    int alloc_employee;        // 할당한 총 직원 수
    int current_employee;      // 현재 직원 수
    Employee** employee_list;  // 직원 데이터

public:
    EmployeeList(int alloc_employee) : alloc_employee(alloc_employee) {
    employee_list = new Employee*[alloc_employee];

    current_employee = 0;
  }
  
    void add_employee(Employee* employee) {
    // 사실 current_employee 보다 alloc_employee 가 더
    // 많아지는 경우 반드시 재할당을 해야 하지만, 여기서는
    // 최대한 단순하게 생각해서 alloc_employee 는
    // 언제나 current_employee 보다 크다고 생각한다.
    // (즉 할당된 크기는 현재 총 직원수 보다 많음)
        employee_list[current_employee] = employee;
        current_employee++;
    }
    int current_employee_num() { return current_employee; }

    void print_employee_info() {
    int total_pay = 0;
        for (int i = 0; i < current_employee; i++) {
            employee_list[i]->print_info();
            total_pay += employee_list[i]->calculate_pay();
        }
        std::cout << "총 비용 : " << total_pay << "만원 " << std::endl;
  }
    ~EmployeeList() {
        for (int i = 0; i < current_employee; i++) {
            delete employee_list[i];
        }
        delete[] employee_list;
    }
};

int main() {
    EmployeeList emp_list(10);
    emp_list.add_employee(new Employee("노홍철", 34, "평사원", 1));
    emp_list.add_employee(new Employee("하하", 34, "평사원", 1));
    emp_list.add_employee(new Manager("유재석", 41, "부장", 7, 12));
    emp_list.add_employee(new Manager("정준하", 43, "과장", 4, 15));
    emp_list.add_employee(new Manager("박명수", 43, "차장", 5, 13));
    emp_list.add_employee(new Employee("정형돈", 36, "대리", 2));
    emp_list.add_employee(new Employee("길", 36, "인턴", -2));
    emp_list.print_employee_info();
    return 0;
}
