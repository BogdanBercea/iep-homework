#include <iostream>

class Vehicle{
	private:
		std::string name;
		int number_of_wheels;
	
	public:
		Vehicle(std::string n, int nr_wheels){
			name = n;
			number_of_wheels = nr_wheels;
		}

		// Copy constructor
		Vehicle(const Vehicle& v):name(v.name), number_of_wheels(v.number_of_wheels){}

		// Item 10: Have assignment operators return a reference to *this.
		Vehicle& operator=(const Vehicle& v){

			// Item 11: Handle assignment to self in operator=.
			if(this != &v){
				// copy v's data
				name = v.name; 
				number_of_wheels= v.number_of_wheels;
			}

			// make sure to return *this
			return *this;
		}

		void print_vehicle_data(){
			std::cout << name <<std::endl;
			std::cout << number_of_wheels << std::endl;
		}
};

class AutoVehicle : Vehicle{
	private:
		std::string motor_info;

	public:
		AutoVehicle(std::string n, int nr_wheels, std::string m_info):Vehicle(n, nr_wheels){
			motor_info = m_info;
		}

		AutoVehicle& operator=(const AutoVehicle& av){
			
			// Item 12: Copy all parts of an object.
			if(this != &av){
				// copy av's data
				Vehicle::operator=(av);
				motor_info = av.motor_info;
			}

			// make sure to return *this
			return *this;
		}

		void print_av_data(){
			print_vehicle_data();
			std::cout << motor_info << std::endl;
			std::cout << std::endl;
		}
};

int main(void){
	Vehicle v1("Bicicleta", 2);
	v1.print_vehicle_data();
	Vehicle v2 = v1;
	v2.print_vehicle_data();

	AutoVehicle av1("Masina", 4, "2.0 TDI");
	av1.print_av_data();
	AutoVehicle av2 = av1;
	av2.print_av_data();
}