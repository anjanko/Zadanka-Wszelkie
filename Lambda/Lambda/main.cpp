#include <iostream>
#include <vector>
#include <functional>
#include <math.h>
using std::cout;
using std::endl;
void main() {
	std::vector<std::function<double(double, double)>> funVector;
	funVector.reserve(3 * sizeof(std::function<double(double, double)>));
	funVector.emplace_back([](double arg1, double arg2) {
		cout << "First function, I multiply " << arg1 << " by " << arg2 << "." << endl;
		return arg1*arg2;
	});
	funVector.emplace_back([](double arg1, double arg2) {
		cout << "Second function, I divide " << arg1 << " by " << arg2 << "." << endl;
		return arg1/arg2;
	});
	funVector.emplace_back([](double arg1, double arg2) {
		cout << "Third function, I raise " << arg1 << " to the power of " << arg2 << "." << endl;
		return std::pow(arg1, arg2);
	});

	double result1 = (funVector[0])(3, 4);
	cout << result1 << endl;
	double result2 = (funVector[1])(3, 4);
	cout << result2 << endl;
	double result3 = (funVector[2])(3, 4);
	cout << result3 << endl;
	getchar();
}