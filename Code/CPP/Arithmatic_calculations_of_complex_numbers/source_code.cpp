#include <iostream>
#include "complexheader.h"	//Adding the complex header file to the main code
using namespace std;

Complex::Complex() {					//implimentation of the default constructor
	real_part = new double;		//allocating the memory dynamically for two data members
	imaginary_part = new double;
	count++;	//increment the value in the count varieble
}

Complex::Complex(const Complex& number) {		//implimentation of the copy constructor
	this->real_part = new double;	//copy the value to a new memomy location in the heap to avoid the error when deallocation
	this->imaginary_part = new double;
	*this->real_part = *number.real_part;
	*this->imaginary_part = *number.imaginary_part;

}
Complex :: ~Complex() {	//destructor to deallocate the memory because we allocate dynamically,so we have to deallocate by our habd
	delete this->real_part;
	delete this->imaginary_part;
}

void Complex::input_values() {	//function definition for the function to input values by user
	cout << "Enter the real part of the cmplex number	 :   ";
	cin >> *this->real_part;
	cout << endl;
	cout << "Enter the imaginary part of the cmplex number	 :   ";
	cin >> *this->imaginary_part;
	cout << endl;
	cout << endl;
}
void Complex::setReal(double real_part) {	//function definition for the function to setters
	*this->real_part = real_part;

}
void Complex::setImag(double imaginary_part) {
	*this->imaginary_part = imaginary_part;
}

double Complex::getReal() const {	//function definition for the function to getters
	return *this->real_part;
}

double Complex::getImag() const {
	return *this->imaginary_part;

}
void Complex::print() {			//function definition for the function to print the complex number
	if (this->getImag() < 0 && this->getReal()!=0) {	//when imaginary number is negative
		cout << "\t " << this->getReal() << "+" << this->getImag() << "i" << endl;
	}
	else if (this->getReal() == 0 && this->getImag() != 0) {	//when complex number is pure imaginary 
		cout << "\t " << this->getImag() << "i" << endl;
	}
	else if (this->getImag() == 0) {	//when complex number has only a real part
		cout << "\t " << this->getReal() << endl;
	}
	
	else {		//when the imaginary part is positive
		cout << "\t " << this->getReal() << " +" << this->getImag() << "i" << endl;;
	}
	cout << endl << endl;
}

/*operator overloading function for calculations with the camplex number objects.because we
cant interact with them as numeric values we have to define the operator by using operator overloading*/

Complex Complex :: operator +(const Complex& num) {//operator overloading for addition  '+' operator
	Complex result;

	result.setReal(this->getReal() + num.getReal());
	result.setImag(this->getImag() + num.getImag());
	return result;
}
Complex Complex :: operator -(const Complex& num) {	//operator overloading for substraction  '-' operator
	Complex result;

	result.setReal(this->getReal() - num.getReal());
	result.setImag(this->getImag() - num.getImag());
	return result;
}
Complex Complex :: operator *(const Complex& num) {	//operator overloading for multiplication '*' operator
	Complex result;
	result.setReal((this->getReal() * num.getReal()) - (this->getImag() * num.getImag()));
	result.setImag((this->getReal() * num.getImag()) + (this->getImag() * num.getReal()));
	return result;
}
Complex Complex :: operator / (const Complex& num) {	//operator overloading for divition '/' operator

	Complex result, numerator;
	Complex conjugate_value = conjugate(num);
	double modulus = (num.getReal() * num.getReal()) + (num.getImag() * num.getImag());//calculating the modulus
	if (modulus > 0) {		/*after checking the modulus ,if modulus of denomenator is 0 we cant devide the 
							number by 0.so we check devition only if modulator is greator than zero*/
		numerator.setReal((this->getReal() * conjugate_value.getReal()) - this->getImag() * conjugate_value.getImag());
		numerator.setImag((this->getReal() * conjugate_value.getImag()) + this->getImag() * conjugate_value.getReal());
		result.setReal(numerator.getReal() / modulus);
		result.setImag(numerator.getImag() / modulus);

		return result;
	}
	else {
		cout << "\tDivition is not valid while the denomenator is 0.\n\tBecause second complex number is";
		return num;
	}
}
Complex Complex :: operator = (const Complex& number) {	//operator overloading for assign operator
	this->real_part = new double;
	this->imaginary_part = new double;
	*this->real_part = *number.real_part;
	*this->imaginary_part = *number.imaginary_part;
	return *this;
}

double get_modulus(const Complex& number) {		//function definition for modulus function
	return  (number.getReal() * number.getReal()) + (number.getImag() * number.getImag());

}

Complex conjugate(const Complex& num) {	//function definition for conjugate function
	Complex value;
	value.setReal(num.getReal());
	value.setImag(num.getImag() * -1);
	return value;
}

int object_count() {	//function definition for object count function
	return Complex::count;
}
int Complex::count = 0;

int main() {		//main function
	cout <<endl<< "#######  THE PROGRAMME TO DO CALCULATIONS WITH COMPLEX NUMBERS  #######" << endl << endl;
	Complex complex_1;	//object for the complex number 1
	complex_1.input_values();

	Complex complex_2;	//object for the complex number 2
	complex_2.input_values();
	cout << "Complex Number 1 : ";
	complex_1.print();		//calling the print function
	cout << "Complex Number 2 :   ";
	complex_2.print();
//	cout << "############  CALCULATIONS  ############" << endl << endl;
	Complex result;	//object for the result

	cout << "\tAddition operator " << endl;
	result = complex_1 + complex_2;	//adding the two complex numbers
	result.print();

	cout << "\tSubstraction operator" << endl;
	result = complex_1 - complex_2;		//substracting the two complex numbers
	result.print();


	cout << "\tMultiplication operator" << endl;
	result = complex_1 * complex_2;	//multiplying the two complex numbers
	result.print();

	cout << "\tDivition operator " << endl;
	result = complex_1 / complex_2;
	result.print();

	cout << "#####################################" << endl << endl;
	cout << "Conjugate value of first complex number" << endl;
	result = conjugate(complex_1);	//calling the function conjugate to take the conjugate value of first user input complex number
	result.print();
	cout << "Conjugate value of second complex number" << endl;
	result = conjugate(complex_2);	//calling the function conjugate to take the conjugate value of second user input complex number
	result.print();

	cout << "Total object count is " << object_count() << endl;///	printing the object count

	return 0;
}
