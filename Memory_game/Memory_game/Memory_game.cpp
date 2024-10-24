// Memory_game.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <Windows.h>
#include <cstdlib>
#include <ctime>
using namespace std;


int main() {
	srand(time(NULL));
	int n, n1, arr[100], l, attempts = 0;
	int a, b;
	double score = 0, scoreboard[10];
	bool game = true;
	char choice;
	for (int i = 0; i < 10; i++) {
		scoreboard[i] = 0;
	}


	while (game) {
		cout << "LEADERBOARDS" << endl;
		for (int i = 0; i < 10; i++) {
			cout << i + 1 << ". " << scoreboard[i] << endl;
			Sleep(50);
		}
		Sleep(200);
	    cout << "GREETINGS, MASTER, INPUT PAIR AMOUNT TO START" << endl << "MAX PAIR NUMBER IS: 10" << endl;
		cin >> l;
		if (l > 10) {
			l = 10;
			system("cls");
			for (int i = 0; i < 3; i++) {
				cout << "ERROR INDEX OUT OF RANGE" << endl << "FIXING ISSUE.";
				Sleep(250);
				system("cls");
				cout << "ERROR INDEX OUT OF RANGE" << endl << "FIXING ISSUE..";
				Sleep(250);
				system("cls");
				cout << "ERROR INDEX OUT OF RANGE" << endl << "FIXING ISSUE...";
				Sleep(250);
				system("cls");
			}
		}
		system("cls");
		n = l * 2;
		attempts = 0;

		for (int i = 0; i < 3; i++) {
			cout << "BUILDING LIST.";
			Sleep(250);
			system("cls");
			cout << "BUILDING LIST..";
			Sleep(250);
			system("cls");
			cout << "BUILDING LIST...";
			Sleep(250);
			system("cls");
		}

		for (int i = 0; i < l; i++) {
			arr[i * 2] = i + 1;
			arr[(i * 2) + 1] = i + 1;
		}
		for (int i = 0; i < l; i++) {
			int arr1 = rand() % n;
			int arr2 = rand() % n;
			int temp = arr[arr1];
			arr[arr1] = arr[arr2];
			arr[arr2] = temp;
		}

		while (l > 0) {
			for (int i = 0; i < n; i++) {
				if (arr[i] != 0) {
					cout << "[ ";
					if (i + 1 < 10)
					{
						cout << " ";
					}
					cout << i + 1 << " ] ";
				}
				else {
					cout << "[    ] ";
				}
				if ((i+1) % 5 == 0)
				{
					cout << endl;
				}
			}
			cout << endl << "INPUT TWO NUMBERS" << endl;
			cin >> a >> b;
			attempts++;
			system("cls");
			for (int i = 0; i < n; i++) {
				if ((i + 1 == a) || (i + 1 == b)) {
					switch (arr[i]) {
					case 1:
						cout << "[  ! ] ";
						break;
					case 2:
						cout << "[  @ ] ";
						break;
					case 3:
						cout << "[  # ] ";
						break;
					case 4:
						cout << "[  $ ] ";
						break;
					case 5:
						cout << "[  % ] ";
						break;
					case 6:
						cout << "[  ^ ] ";
						break;
					case 7:
						cout << "[  & ] ";
						break;
					case 8:
						cout << "[  * ] ";
						break;
					case 9:
						cout << "[  - ] ";
						break;
					case 10:
						cout << "[  + ] ";
						break;
					default:
						cout << "[    ] ";
						break;
					}
				}
				else if (arr[i] != 0) {
					cout << "[ ";
					if (i + 1 < 10)
					{
						cout << " ";
					}
					cout << i + 1 << " ] ";
				}
				else {
					cout << "[    ] ";
				}
				if ((i + 1) % 5 == 0)
				{
					cout << endl;
				}
			}
			if ((arr[a - 1] == arr[b - 1]) && arr[a - 1] != 0) {
				arr[a - 1] = 0;
				arr[b - 1] = 0;
				l--;
				cout << endl << "CORRECT" << endl;
				Sleep(2000);
				system("cls");
			}
			else {
				cout << endl << "INCORRECT" << endl;
				Sleep(2000);
				system("cls");
			}
		}
		score = double(n) / attempts * double(n / 2) * 20;
		for (int i = 0; i < 10; i++) {
			if (score > scoreboard[i]) {
				for (int j = 9; j > i; j--) {
					scoreboard[j] = scoreboard[j - 1];
				}
				scoreboard[i] = score;
				break;
			}
		}
		cout << "LEADERBOARDS" << endl;
		for (int i = 0; i < 10; i++) {
			cout << i + 1 << ". " << scoreboard[i] << endl;
			Sleep(50);
		}
		Sleep(500);
		cout << "CONGRATULATIONS, YOU WON. IT TOOK YOU " << attempts << " ATTEMPTS" << endl;
		Sleep(300);
		cout << "YOUR SCORE IS " << score << " POINTS" << endl;
		Sleep(300);
		cout << "ENTER Y TO CONTINUE" << endl;
		cin >> choice;
		system("cls");
		if (choice != 'Y' && choice != 'y') {
			game = false;
		}
	}
	return 0;
}

