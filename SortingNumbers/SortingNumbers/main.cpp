#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
using std::cout;
using std::endl;
using std::vector;
using std::list;

void oddAndEvenSorting(vector<int> &v)
{
	sort(v.begin(), v.end());
	vector<int> sortedV;
	sortedV.reserve(v.size());
	for (auto it = v.begin(); it != v.end(); it++)
	{
		if (*it % 2)	//if it's odd
		{
			sortedV.push_back(*it);
		}
	}
	for (auto it = v.begin(); it != v.end(); it++)
	{
		if (*it % 2 == 0)	//if it's even
		{
			sortedV.push_back(*it);
		}
	}
	v.assign(sortedV.begin(), sortedV.end());
}

void printVector(vector<int> &v)
{
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << "\t";
	}
}

const list<int>::const_iterator findNumber(const list<int> &l, int number)
{
	auto it = l.begin();
	while (it != l.end() && *it != 5)
	{
		it++;
	}
	return it;
}

int main()
{
	//sorting numbers in vector
	vector<int> vec;
	for (int i = 1; i < 10; i++)
	{
		vec.push_back(i);
	}
	cout << "Vector before sorting:" << endl;
	printVector(vec);
	oddAndEvenSorting(vec);
	cout << endl << endl << "After:" << endl;
	printVector(vec);
	cout << endl << endl;

	//finding element 5 in the list
	cout << endl << endl << "- - - - - -" << endl << endl;
	list<int> l = { 0,1,2,3,4,5 };
	if (*findNumber(l, 5) == 5)
	{
		cout << "The element 5 has been found.";
	}
	else
	{
		cout << "Error! Couldn't find the element.";
	}
	getchar();
	return 0;
}
