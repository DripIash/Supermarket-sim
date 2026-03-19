#include <iostream>
using namespace std;

int main() {
	/// --- 1 ---
	cout << "---1---" << endl;
	for (int i = 100; i >= 0; i -= 2)
		cout << i << endl;

	/// --- 2 ---
	cout << "\n\n---2---" << endl;
	for (int i = 0; i <= 100; i++) {
		if ((i % 3 == 0) && (i % 5 == 0))
			cout << "FizzBuzz" << endl;
		else if (i % 3 == 0)
			cout << "Fizz" << endl;
		else if (i % 5 == 0)
			cout << "Buzz" << endl;
		else
			cout << i << endl;
	}

	/// --- 3 ---
	cout << "\n\n---3---" << endl;
	int tally = 0;
	for (int i = 0; i < 1000; i++)
		if ((i % 3 == 0) || (i % 5 == 0))
			tally += i;
	cout << tally;

	/// --- 4-1 ---
	cout << "\n\n---4-1---" << endl;
	int i = 100;
	while (i >= 0) {
		cout << i << endl;
		i -= 2;
	}

	/// --- 4-2 ---
	cout << "\n\n---4-2---" << endl;
	i = 0;
	while (i <= 100) {
		if ((i % 3 == 0) && (i % 5 == 0))
			cout << "FizzBuzz" << endl;
		else if (i % 3 == 0)
			cout << "Fizz" << endl;
		else if (i % 5 == 0)
			cout << "Buzz" << endl;
		else
			cout << i << endl;
		i++;
	}

	/// --- 4-3 ---
	cout << "\n\n---4-3---" << endl;
	tally = 0;
	i = 0;
	while (i < 1000) {
		if ((i % 3 == 0) || (i % 5 == 0))
			tally += i;
		i++;
	}
	cout << tally;

}