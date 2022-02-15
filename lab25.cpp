#include<iostream>
#include<cmath>
using namespace std;

class ComplexNumber{				
	public:
		double real;
		double imag;
		ComplexNumber(double,double);
		ComplexNumber operator+(const ComplexNumber &);
		ComplexNumber operator-(const ComplexNumber &);
		ComplexNumber operator*(const ComplexNumber &);
		ComplexNumber operator/(const ComplexNumber &);
		bool operator==(const ComplexNumber &);
		
		double abs();
		double angle();
};

ComplexNumber::ComplexNumber(double x = 0,double y = 0){
	real = x; imag = y;
}

ComplexNumber ComplexNumber::operator+(const ComplexNumber &c){
	return ComplexNumber(real+c.real,imag+c.imag);
}

ComplexNumber ComplexNumber::operator-(const ComplexNumber &c){
	return ComplexNumber(real-c.real,imag-c.imag);
}

ComplexNumber ComplexNumber::operator*(const ComplexNumber &c){
	double p1 = real * c.real;
    double p2 = imag * c.imag;
    double p3 = (real + imag) * (c.real + c.imag);
    double real_prat = p1-p2;
    double imag_part = p3-(p1+p2);
    return ComplexNumber(real_prat,imag_part);
}

ComplexNumber ComplexNumber::operator/(const ComplexNumber &c){
	double real_part = (real*c.real + imag*c.imag)/(c.real*c.real + c.imag*c.imag);
    double imag_part = (imag*c.real - real*c.imag)/(c.real*c.real + c.imag*c.imag);
    return ComplexNumber(real_part,imag_part);
}
double ComplexNumber::abs() {
	double r;
	r = sqrt(pow(real,2)+pow(imag,2));
	return r;
}
double ComplexNumber::angle() {
	double result;
	result = atan2 (imag,real) * 180 / M_PI;
	return result;
}
bool operator==(double s,const ComplexNumber &x){
	if (s == x.real && s == x.imag)
	{
		return true;
	} else return false;
}
bool ComplexNumber::operator==(const ComplexNumber &x){
	if (real == x.real && imag == x.imag)
	{
		return true;
	} else return false;
	
}
ComplexNumber operator+(double s,const ComplexNumber &c){
	return ComplexNumber(s+c.real,c.imag);
}
ComplexNumber operator-(double s,const ComplexNumber &c) {
	return ComplexNumber(s-c.real,-c.imag);
}
ComplexNumber operator*(double s,const ComplexNumber &c){
	double p1 = s * c.real;
    double p2 = 0 * c.imag;
    double p3 = (s + 0) * (c.real + c.imag);
    double real_prat = p1-p2;
    double imag_part = p3-(p1+p2);
    return ComplexNumber(real_prat,imag_part);
}

ComplexNumber operator/(double s,const ComplexNumber &c){
	double real_part = (s*c.real + 0*c.imag)/(c.real*c.real + c.imag*c.imag);
    double imag_part = (0*c.real - s*c.imag)/(c.real*c.real + c.imag*c.imag);
    return ComplexNumber(real_part,imag_part);
}
ostream & operator<<(ostream &os,const ComplexNumber &c){
	if (c.real == 0 && c.imag == 0)
	{
		return os << 0;
	} else if (c.real == 0 && c.imag != 0 ) {
		return os << c.imag <<"i";
	} else if (c.real != 0 && c.imag == 0 ) {
		return os << c.real;
	} else if (c.real != 0 && c.imag != 0 ) {
		if (c.imag > 0 )
		{
			return os << c.real << "+" << c.imag << "i";
		} else {
			return os << c.real << c.imag << "i";
		}
		
	} else {
		return os << 0;
	}
	
}

int main(){
	ComplexNumber a(1.5,2),b(3.2,-2.5),c(-1,1.2);	
	cout << a << "\n";
	cout << b << "\n";
	cout << c << "\n";
	cout << a+2.5 << "\n";
	cout << 2.5+a << "\n";
	cout << a-1.5 << "\n";
	cout << 1.5-a << "\n";
	cout << b+ComplexNumber(0,2.5) << "\n";
	cout << c-c << "\n";
	cout << "-----------------------------------\n";
	
	ComplexNumber d = (a+b)/c;
	ComplexNumber e = b/(a-c);
	cout << d << "\n";
	cout << e << "\n";
	cout << c*2 << "\n";
	cout << 0.5*c << "\n";
	cout << 1/c << "\n";
	cout << "-----------------------------------\n";
	
	cout << ComplexNumber(1,1).abs() << "\n";
	cout << ComplexNumber(-1,1).abs() << "\n";
	cout << ComplexNumber(1.5,2.4).abs() << "\n";
	cout << ComplexNumber(3,4).abs() << "\n";
	cout << ComplexNumber(69,-9).abs() << "\n";		
	cout << "-----------------------------------\n";	
	
	cout << ComplexNumber(1,1).angle() << "\n";
	cout << ComplexNumber(-1,1).angle() << "\n";
	cout << ComplexNumber(-1,-1).angle() << "\n";
	cout << ComplexNumber(1,-1).angle() << "\n";
	cout << ComplexNumber(5,2).angle() << "\n";
	cout << "-----------------------------------\n";
	
	cout << (ComplexNumber(1,1) == ComplexNumber(1,2)) << "\n";
	cout << (ComplexNumber(1,1) == 1) << "\n";
	cout << (0 == ComplexNumber()) << "\n";
}





