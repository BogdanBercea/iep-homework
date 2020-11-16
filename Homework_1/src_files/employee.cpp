#include <iostream>
#include "employee.hpp"

//make sure that object are initialized before they're used
Employee::Employee(std::string i, std::string n,
		 std::string pn, int a, int s)
{
	id = i;
	name = n;
	phone_number = pn;
	age = a;
	salary = s;

	std::cout<< "Employee " << name << " initialized" << std::endl;
}

void Employee::setID(std::string i){
	id = i;
}

std::string Employee::getID(){
	return id;
}

void Employee::setName(std::string n){
	name = n;
}

std::string Employee::getName(){
	return name;
}

void Employee::setPhoneNumber(std::string pn){
	phone_number = pn;
}

std::string Employee::getPhoneNumber(){
	return phone_number;
}

void Employee::setAge(int a){
	age = a;
}

int Employee::getAge(){
	return age;
}

void Employee::setSalary(int s){
	salary = s;
}

int Employee::getSalary(){
	return salary;
}

void Employee::printEmployeeData(){
	std::cout << "Employee ID: " << getID() << std::endl;
	std::cout << "Employee name: " << getName() << std::endl;
	std::cout << "Employee phone number: " << getPhoneNumber() << std::endl;
	std::cout << "Employee age: " << getAge() << std::endl;
	std::cout << "Employee salary: " << getSalary() << std::endl;
	std::cout << "\n\n";
}

int main(){

	//functions that C++ silently writes and calls
	Employee employee1("001", "Eric", "12314213213", 34, 800);
	Employee employee2(employee1);
	Employee employee3 = employee1;

	employee1.printEmployeeData();
	employee2.printEmployeeData();
	employee3.printEmployeeData();

	//the compiler will complain about assignment operator
	//employee3 = employee2;

	return 0;
}
