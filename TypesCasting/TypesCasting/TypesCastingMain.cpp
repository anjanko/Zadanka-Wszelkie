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
	void setString(const string& ss) {
		s = ss;
	}
};

class DerivedClass: public BaseClass {
private:
	int i;
public:
	DerivedClass(){
		i = 13;
		setString("This is string in derived class.");
	}
	virtual ~DerivedClass() = default;
	int getInt() const { return i; }
};

class BaseClass2{
private:
	float f;
public:
	BaseClass2();
	~BaseClass2();
}

class DerivedClass2 : public BaseClass2{
	DerivedClass2();
	~DerivedClass2();
}

int myFun(int* a) {
	return *a + 3;
}

void main() {
	float d = 6.33;
	float f = 3.22;
	float divisionResult = (int)d / (int)f;
	cout << "Division of two float numbers (" << d << " and " << f << ") casted to int before: " 
		<< divisionResult << endl;
	int a = 7;
	float b = static_cast<float>(a) + 0.33;
	cout << "'A' is equal 7, casted to float to add 0.33. Result: " << b << endl;
	const int constA = 12;
	//myFun(&constA); <--doesn't work, it has to be int, not const int
	cout << "Function myFun takes casted const int as parameter and here is the result: "
		<< myFun(const_cast<int*>(&constA)) << endl;
	BaseClass base;
	DerivedClass der;
	cout << endl << "Fields in base class: s=\"" << base.getString() << "\"" << endl;
	cout << "Fields in derived class: s=\"" << der.getString() << "\", i=" << der.getInt() << endl;
	BaseClass* castedDer = reinterpret_cast<BaseClass*>(&der);
	DerivedClass* castedBase = reinterpret_cast<DerivedClass*>(&base);
	cout << endl << "After casting (reinterpret_cast)" << endl;
	cout << "Fields in casted derived class: s=\"" << castedDer->getString() << "\"" << endl;
	cout << "Fields in casted base class: s=\"" << castedBase->getString() << "\", i=" << 
		castedBase->getInt() << endl;
	DerivedClass2 derived2;
	BaseClass* derived2Casted = dynamic_cast<BaseClass*>(derived2);
	if(!derived2Casted ){
		std::cout << "Bad cast!";
	}
	getchar();

}