#include <iostream>
#include <cstdlib>
using namespace std;

int main() {
	srand(time(NULL));
	// --- 3 ---
	int data[10];
	for (int i = 0; i < 10; i++)
		data[i] = 10 - i;

	// --- 4 ---
	//int input[5];
	//for (int i = 0; i < 5; i++) {
	//	cout << "Input number: ";
	//	cin >> input[i];
	//}
	//for (int i = 4; i >= 0; i--) {
	//	cout << input[i] << " ";
	//}

	// --- 5 ---
	//const int SIZE = 10;
	//int input[SIZE];
	//for (int i = 0; i < SIZE; i++) {
	//	cout << "In: ";
	//	cin >> input[i];
	//}

	//int big, small;
	//big = small = input[0];
	//for (int i = 1; i < SIZE; i++) {
	//	if (input[i] < small)
	//		small = input[i];
	//	if (input[i] > big)
	//		big = input[i];
	//}

	//cout << "Largest: " << big << " Smallest: " << small << endl;

	// --- 6 ---
	int arr[3][3];
	int counter = 0;
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++) {
			counter++;
			arr[i][j] = counter;
		}

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}

	// --- 7 ---
	int days[29][5];
	int tally;
	for (int i = 0; i < 29; i++) {
		tally = 0;
		for (int j = 0; j < 5; j++)
			tally += days[i][j];
		cout << "Row sum: " << tally << endl;
	}

	for (int i = 0; i < 5; i++) {
		tally = 0;
		for (int j = 0; j < 29; j++)
			tally += days[j][i];
		cout << "Column sum: " << tally << endl;
	}

	//// --- 8 ---
	//int hps[5] = { 100, 100, 100, 100, 100 };
	//int input;
	//for (int i = 1; i < 6; i++) {
	//	cout << "Attack which character? (0-4): ";
	//	cin >> input;
	//	while (hps[input] <= 0) {
	//		cout << "Character is dead, pick a different one: ";
	//		cin >> input;
	//	}
	//	hps[input] -= (rand() % 31) + 25;
	//}

	//for (int i = 0; i < 5; i++) {
	//	cout << i << " health: " << hps[i] << endl;
	//}

	// --- 9 ---
	int info[3][7];
	int avg[3] = {};
	int totalAvg, max = 0, min = 1000000000, maxD, minD;
	max = 0;
	maxD = minD = 1;

	for (int i = 0; i < 3; i++) {
		cout << "Dragon " << i << ": ";
		for (int j = 0; j < 7; j++) {
			cin >> info[i][j];
			avg[i] += info[i][j];
			if (info[i][j] < min) {
				min = info[i][j];
				minD = i + 1;
			}
			if (info[i][j] > max) {
				max = info[i][j];
				maxD = i + 1;
			}
		}
	}
	avg[0] /= 7;
	avg[1] /= 7;
	avg[2] /= 7;
	totalAvg = (avg[0] + avg[1] + avg[2]) / 3;

	cout << "Total average: " << totalAvg << endl;
	cout << "Average for 1: " << avg[0] << endl;
	cout << "Average for 2: " << avg[1] << endl;
	cout << "Average for 3: " << avg[2] << endl;
	cout << "Largest amount: " << max << " eaten by dragon " << maxD << endl;
	cout << "Smallest amount: " << min << " eaten by dragon " << minD << endl;
}