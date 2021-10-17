#pragma once
class Complex {
private:
	double* real_part;
	double* imaginary_part;
	static int count;

	/*all the function phototypes are in here.
	the function definitions are in the cpp file*/

public:
	Complex();
	Complex(const Complex& number);
	~Complex();

	void input_values();
	void print();
	double get_modulus(const Complex& number);
	friend int object_count();
	friend Complex conjugate(const Complex& num);

	void setReal(double real_part);
	double getReal() const;
	void setImag(double imaginary_part);
	double getImag() const;

	Complex  operator + (const Complex& num);
	Complex  operator - (const Complex& num);
	Complex  operator * (const Complex& num);
	Complex operator / (const Complex& num);
	Complex operator = (const Complex& number);
};