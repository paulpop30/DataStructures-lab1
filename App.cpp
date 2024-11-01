#include "Bag.h"
#include "ShortTest.h"
#include "ExtendedTest.h"
#include <iostream>
#define _CRT_SECURE_NO_WARNINGS

using namespace std;

int main() {

	testAll();
	cout << "Short tests over" << endl;
	testAllExtended();

	cout << "All tests over" << endl;
}

