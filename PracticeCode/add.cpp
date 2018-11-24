#include <iostream>
using namespace std;

struct Employee {
  string name;
  int age;
  int salary;
}

int main() {
  int a = 5;
  int b = 3;

  int result = add(5, 3);
  cout << result << endl;

  Employee a = new Employee();
  a.name = "jamie";
  a.age = 18;
  a.salary = 0;

}
