#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::vector;

void fillValues(int* tab, int size) {
	for (int i = 0; i < size; i++) {
		*tab = i;
		tab++;
	}
}

const int* findFive(int* tab, int size) {
	int* ptr = NULL;
	for (int i = 0; i < size; i++) {
		if (tab[i] == 5) {
			ptr = &tab[i];
		}
	}
	return ptr;
}

void main() {
	int size = 20;
	int* dynamicTab = new int[size];
	fillValues(dynamicTab, size);
	const int* ptrTo5 = findFive(dynamicTab, size);
	if ( ptrTo5 != NULL) {
		cout << "Number 5 has been found!";
	}
	vector<int*> v;
	v.reserve(size);
	for (int i = 0; i < size; i++) {
		v.emplace_back(&dynamicTab[i]);
	}
	vector<int*>* pv1 = &v;
	vector<int*>* pv2 = &v;

	delete[] dynamicTab;
	getchar();

}