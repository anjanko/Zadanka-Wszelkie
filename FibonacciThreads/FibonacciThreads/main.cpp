//Pierwszy watek liczy Fibonacciego z pierwszej liczby, drugi - z drugiej
//trzeci liczy lcm obu liczb

#include <iostream>
#include <thread>
#include <string>
#include <vector>
#include <mutex>
#define SEQUENCE_LENGHT 20
using std::cout;
using std::endl;
using std::cin;
using std::string;
using std::thread;

int fibon1[SEQUENCE_LENGHT];
int fibon2[SEQUENCE_LENGHT];
int lcmResult;
long sum = 0;
std::mutex mtx;

void fibonacciSequence(int startNum, int* fArray) {
	fArray[0] = 1;	//wiem, ze powinno byc startNum, ale jesli to bedzie np. 2, to nie bedzie wcale ciekawie
	fArray[1] = startNum;
	int fSum = fArray[0] + fArray[1];
	for (int i = 2; i < SEQUENCE_LENGHT; i++) {
		fArray[i] = fArray[i - 1] + fArray[i - 2];
		fSum += fArray[i];
	}
	mtx.lock();
	sum += fSum;
	mtx.unlock();
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

void lcm(int a, int b) {	//least common multiple
	if (a < b) {
		a, b = b, a;
	}
	lcmResult = a*b / gcd(a, b);
	mtx.lock();
	sum += lcmResult;
	mtx.unlock();
}

void getCorrectNumbers(int* num1, int* num2, string* userStr1, string* userStr2) {
	bool correct;
	do {
		try {
			*num1 = stoi(*userStr1);
			*num2 = stoi(*userStr2);
			correct = true;
		}
		catch (...) {
			cout << "Invalid arguments! Numbers have to be intiger. Enter them again." << endl;
			cout << "First number: ";
			cin >> *userStr1;
			cout << "Second number: ";
			cin >> *userStr2;
			correct = false;
		}
	} while (!correct);
}

void printArray(int* fArray) {
	for (int i = 0; i < SEQUENCE_LENGHT; i++) {
		cout << fArray[i] << "\t";
		if (i % 10 == 0) {
			cout << endl;
		}
	}
}

void main(int argc,char** argv) {
	int num1, num2;
	string userStr1, userStr2;
	if (argc < 3) {
		cout << "First number for first Fibonacci sequence: ";
		cin >> userStr1;
		cout << "First number for second sequence: ";
		cin >> userStr2;
	}
	else {
		userStr1 = argv[1];
		userStr2 = argv[2];
	}
	getCorrectNumbers(&num1, &num2, &userStr1, &userStr2);
	cout << "Numbers: " << num1 << " and " << num2;
	std::vector <thread> threads;
	threads.push_back(thread(lcm, num1, num2));
	threads.push_back(thread(fibonacciSequence, num1, fibon1));
	threads.push_back(thread(fibonacciSequence, num2, fibon2));
	for (auto& th : threads) {
		th.join();
	}
	cout << endl;
	printArray(fibon1);
	cout << endl;
	printArray(fibon2);
	cout << endl;
	cout << "The least common multiple: " << lcmResult << endl;
	cout << "Sum of all: " << sum << endl;
	getchar();

}