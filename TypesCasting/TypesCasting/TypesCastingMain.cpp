#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;

class BaseClass {
private:
	string s;
public:
	BaseClass() {
		s = "This is string in BaseClass.";
	}
	virtual ~BaseClass() = default;
	virtual const string& getString() const { 
		return s; 
	}
	void setString(string& ss) {
		s = ss;
	}
};

class DerivedClass: public BaseClass {
private:
	int i;
public:
	DerivedClass(){
		i = 13;
		setString(static_cast<string>("This is string in derived class."));
	}
	virtual ~DerivedClass() = default;
	int getInt() const { return i; }
};

int myFun(int* a) {
	return *a + 3;
}
void main() {
	float f = 3.22;
	float intF = (int)f;
	cout << "Float number: " << f << ", casted to int: " << intF << endl;
	char line[] = "Characters chain";
	string strLine = static_cast<string>(line);
	strLine.append(" is now a string.");
	cout << strLine << endl;
	const int constA = 12;
	//myFun(&constA); <--doesn't work, it has to be int, not const int
	cout << "Function myFun takes casted const int as parameter and here is the result: "
		<< myFun(const_cast<int*>(&constA));
	BaseClass base;
	DerivedClass der;
	cout << "Fields in base class: s=\"" << base.getString() << "\"" << endl;
	cout << "Fields in derived class: s=\"" << der.getString() << "\", i=" << der.getInt() << endl;
	BaseClass* castedDer = reinterpret_cast<BaseClass*>(&der);
	DerivedClass* castedBase = reinterpret_cast<DerivedClass*>(&base);
	cout << endl << "After casting (reinterpret_cast)" << endl;
	cout << "Fields in casted derived class: s=\"" << castedDer->getString() << "\"" << endl;
	cout << "Fields in casted base class: s=\"" << castedBase->getString() << "\", i=" << 
		castedBase->getInt() << endl;

}