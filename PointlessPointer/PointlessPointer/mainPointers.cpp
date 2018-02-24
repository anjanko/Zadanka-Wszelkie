#include <iostream>
#include <vector>
#include <memory>
using std::cout;
using std::endl;
using std::vector;
using std::unique_ptr;
using std::shared_ptr;
using std::weak_ptr;

void fillValues(vector<int>& v, int size) {
	v.reserve(size);
	for (int i = 0; i < size; i++) {
		v.emplace_back(i);
	}
}

void main() {
	int size = 20;
	unique_ptr<vector<int>> pvUnique(new vector<int>);
	pvUnique->push_back(7);
	pvUnique->push_back(8);
	cout << "Capacity of vector pointed by pvUnique: " << pvUnique->capacity() << endl;
	cout << "pvUnique.get() = " << pvUnique.get() << endl;
	shared_ptr<vector<int>> pvShared1(pvUnique.release());
	shared_ptr<vector<int>> pvShared2(pvShared1);
	shared_ptr<vector<int>> pvShared3(pvShared1);
	weak_ptr<vector<int>> pvWeak(pvShared1);
	cout << "pvShared1.get() = " << pvShared1.get() << endl;
	cout << "pvShared2.get() = " << pvShared2.get() << endl;
	cout << "pvShared3.get() = " << pvShared3.get() << endl;
	cout << "pvShared2.use_count() = " << pvShared2.use_count() << endl;
	cout << "Is pvShared3 unique? " << std::boolalpha << pvShared3.unique() << endl;
	pvShared3.reset();
	cout << "Reset pvShared3, use_count of pvShared1 = " << pvShared1.use_count() << endl;
	fillValues(*pvShared1, size);
	pvShared1.reset();
	pvShared2.reset();
	cout << "Reset pvShared1 and pvShared2, now checking pvWeak use_count: " << pvWeak.use_count() << "," << endl;
	cout << "and pvWeak.expired(): " << pvWeak.expired() << endl;
	// a auto_ptr nie robie, bo internety mowia, ze to przestarzale
	getchar();

}