//Pierwszy watek liczy Fibonacciego z pierwszej liczby, drugi - z drugiej
//trzeci liczy lcm obu liczb

#include <iostream>
#include <windows.h>
#include <process.h>
#include <string>
#include <vector>
#define SEQUENCE_LENGHT 20
using std::cout;
using std::endl;
using std::cin;
using std::string;
using std::vector;

void __cdecl makeFibonSequence(void * args) {
	int* p = (int*)args;
	int startNum = p[0];
	int* fs = &p[1];
	fs[0] = 1;	//wiem, ze powinno byc startNum, ale jesli to bedzie np. 2, to nie bedzie wcale ciekawie
	fs[1] = startNum;
	for (int i = 2; i < SEQUENCE_LENGHT; i++) {
		fs[i] = fs[i - 1] + fs[i - 2];
	}
	_endthread();
}

int gcd(int a, int b) {	//greatest common divisor
	int temp;
	while (b != 0) {
		temp = b;
		b = a%b;
		a = temp;
	}
	return a;
}

void __cdecl lcm(void * args) {	//least common multiple
	int* p = (int*)args;
	int a = p[0];
	int b = p[1];
	if (a < b) {
		a, b = b, a;
	}
	int* lcmResult = &p[2];
	*lcmResult = a*b / gcd(a, b);
}

void getCorrectNumbers(int* i1, int* i2, string* s1, string* s2) {
	bool correct;
	do {
		try {
			*i1 = stoi(*s1);
			*i2 = stoi(*s2);
			correct = true;
		}
		catch (...) {
			cout << "Invalid arguments! Numbers have to be intiger. Enter them again." << endl;
			cout << "First number: ";
			cin >> *s1;
			cout << "Second number: ";
			cin >> *s2;
			correct = false;
		}
	} while (!correct);
}

void printArray(int* fArray) {
	for (int i = 1; i < SEQUENCE_LENGHT + 1; i++) {
		cout << fArray[i] << "\t";
		if (i % 10 == 0) {
			cout << endl;
		}
	}
}

void main(int argc,char** argv) {
	int i1, i2;
	string s1, s2;
	if (argc < 3) {
		cout << "First number for first Fibonacci sequence: ";
		cin >> s1;
		cout << "First number for second sequence: ";
		cin >> s2;
	}
	else {
		s1 = argv[1];
		s2 = argv[2];
	}
	getCorrectNumbers(&i1, &i2, &s1, &s2);
	cout << "Numbers: " << i1 << " and " << i2;
	vector <HANDLE> hThreads;
	int fArgs1[SEQUENCE_LENGHT + 1];
	fArgs1[0] = i1;
	int fArgs2[SEQUENCE_LENGHT + 1];
	fArgs2[0] = i2;
	int lcmArgs[] = { i1,i2,0 };
	hThreads.push_back((HANDLE)_beginthread(makeFibonSequence, 0, fArgs1));
	hThreads.push_back((HANDLE)_beginthread(makeFibonSequence, 0, fArgs2));
	hThreads.push_back((HANDLE)_beginthread(lcm, 0, lcmArgs));
	if (WaitForMultipleObjects(hThreads.size(), &hThreads[0], TRUE, 10000) == WAIT_OBJECT_0) {
		cout << endl;
		printArray(fArgs1);
		cout << endl;
		printArray(fArgs2);
		cout << endl;
		cout << "The least common multiple: " << lcmArgs[2] << endl;
	}
	getchar();

}