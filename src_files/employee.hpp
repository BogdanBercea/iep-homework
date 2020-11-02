#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <iostream>

class Employee{
	private:
		std::string id;
		std::string name;
		std::string phone_number;
		int age;
		int salary;

	public:
		Employee(std::string id, std::string name,
		 std::string phone_number, int age, int salary);
		
		void setID(std::string id);
		std::string getID();
		
		void setName(std::string name);
		std::string getName();
		
		void setPhoneNumber(std::string phone_number);
		std::string getPhoneNumber();
		
		void setAge(int agee);
		int getAge();

		void setSalary(int s);
		int getSalary();

		void printEmployeeData();

		Employee& operator=(const Employee&);
};

#endif