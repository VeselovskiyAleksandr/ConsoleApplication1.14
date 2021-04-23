// ConsoleApplication1.14.4.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//Урок 14. Задача 4. Сравнение длинных вещественных чисел.

#include <iostream>
#include <locale.h>
using namespace std;
int checking_correctInput(string str);
string wholePartSelection_function(string st);
string fractionalPartSelection_function(string st);
string discarding_zeros(string s);
string absoluteValue_function(string s);

int main()
{
    setlocale(LC_ALL, "Russian");
    string x, y, u, v, wholePart1, wholePart2, fractionalPart1, fractionalPart2;
    cout << "\n Введите первое число ";
    cin >> x;
	if (checking_correctInput(x)==1) {
		cout << "\n Введите второе число ";
		cin >> y;
		if (checking_correctInput(y) == 1) {

			if ((x[0] == '-') && (y[0] != '-')) {
				cout << "\n" << x << "<" << y;
			}
			else if ((x[0] != '-') && (y[0] == '-')) {
				cout << "\n" << x << ">" << y;
			}
			else if ((x[0] == '-') && (y[0] == '-')) {
				u = x; v = y;
				u = absoluteValue_function(u);
				v = absoluteValue_function(v);
				wholePart1 = wholePartSelection_function(u);
				wholePart2 = wholePartSelection_function(v);
				fractionalPart1 = fractionalPartSelection_function(u);
				fractionalPart2 = fractionalPartSelection_function(v);
				if (wholePart1.length() > wholePart2.length()) {
					cout << "\n" << x << "<" << y;
				}
				else if (wholePart1.length() < wholePart2.length()) {
					cout << "\n" << x << ">" << y;
				}
				else {
					int i;
					for (i = 0; i < wholePart1.length(); i++) {
						if (wholePart1[i] > wholePart2[i]) {
							cout << "\n" << x << "<" << y; break;
						}
						else if (wholePart1[i] < wholePart2[i]) {
							cout << "\n" << x << ">" << y; break;
						}
						else if ((i == wholePart1.length() - 1) && (wholePart1[i] == wholePart2[i])) {
							if (fractionalPart1.length() > fractionalPart2.length()) {
								cout << "\n" << x << "<" << y; break;
							}
							else if (fractionalPart1.length() < fractionalPart2.length()) {
								cout << "\n" << x << ">" << y; break;
							}
							else {
								int j;
								for (j = 0; j < fractionalPart1.length(); j++) {
									if (fractionalPart1[j] > fractionalPart2[j]) {
										cout << "\n" << x << "<" << y; break;
									}
									else if (fractionalPart1[j] < fractionalPart2[j]) {
										cout << "\n" << x << ">" << y; break;
									}
									else if ((wholePart1 == wholePart2) && (fractionalPart1 == fractionalPart2)) {
										cout << "\n" << x << "=" << y; break;
									}
								}
							}
						}
					}
				}
			}
			if ((x[0] != '-') && (y[0] != '-')) {
			wholePart1 = wholePartSelection_function(x);
			wholePart2 = wholePartSelection_function(y);
			fractionalPart1 = fractionalPartSelection_function(x);
			fractionalPart2 = fractionalPartSelection_function(y);
				if (wholePart1.length() > wholePart2.length()) {
					cout << "\n" << x << ">" << y;
				}
				else if (wholePart1.length() < wholePart2.length()) {
					cout << "\n" << x << "<" << y;
				}
				else {
					int i;
					for (i = 0; i < wholePart1.length(); i++) {
						if (wholePart1[i] > wholePart2[i]) {
							cout << "\n" << x << ">" << y; break;
						}
						else if (wholePart1[i] < wholePart2[i]) {
							cout << "\n" << x << "<" << y; break;
						}
						else if ((i == wholePart1.length() - 1) && (wholePart1[i] == wholePart2[i])) {
							if (fractionalPart1.length() > fractionalPart2.length()) {
								cout << "\n" << x << ">" << y; break;
							}
							else if (fractionalPart1.length() < fractionalPart2.length()) {
								cout << "\n" << x << "<" << y; break;
							}
							else {
								int j;
								for (j = 0; j < fractionalPart1.length(); j++) {
									if (fractionalPart1[j] > fractionalPart2[j]) {
										cout << "\n" << x << ">" << y; break;
									}
									else if (fractionalPart1[j] < fractionalPart2[j]) {
										cout << "\n" << x << "<" << y; break;
									}
									else if ((wholePart1 == wholePart2) && (fractionalPart1 == fractionalPart2)) {
										cout << "\n" << x << "=" << y; break;
									}
								}
							}
						}
					}
				}
			}
		}
		else {
			cout << "\nВведите правильно число ";
		}
	}
	else {
		cout << "\nВведите правильно число ";
	}
}

int checking_correctInput(string number)
	{
		setlocale(LC_ALL, "Russian");
		int countNumber = 0, countPoint = 0, countSign=0;
		bool correct=true;
		if ((number[0] == '-') || (number[0] == '.') || ((number[0] >= '0') &&( number[0] <= '9'))) {
			int i;
			for (i = 0; i < number.length(); i++) {
				if (number[i] == '.') {
					countPoint++;
				}
				else if (number[i] >= '0' && number[i] <= '9') {
					countNumber++;
				}
			}
				if (number[0] == '-') {
					countSign = 1;		
			}
if ((countPoint <= 1) &&
					((countNumber+ countPoint+ countSign)== number.length()))
				{
					correct = true;
				}
		}
		else {
			correct = false;

		}
         return correct;
	}

string wholePartSelection_function(string st) {
int i, count=0;
string str;
char ch;
if (st[0] == '.') {
	str = '0';
}
else if ((st[0] == '0') && (st[1] == '.')) {
	str = '0';
}
else if ((st[0] == '0') && (st[1] != '.')) {
	for (i = 0; i < st.length(); i++) {
		if (st[i] != '0') { break;}
		else {
			count++;
		}
	}
	for (i = count; i < st.length(); i++) {
		if (st[i] == '.') {
			break;
		}
		else {
			ch = st[i]; str += ch;
		}
	}
}
else if ((st[0] != 0) &&(st[0]!='.')&&(st.length() == 1)) {
	str = st;
}
else if(st[0]!=0){
	for (i = 0; i < st.length(); i++) {
		if (st[i] == '.') {
			break;
		}
		else {
			ch = st[i]; str += ch;
		}
	}
}

return str;
}

string fractionalPartSelection_function(string st) {
	int i, count = 0;
	string str, s;
	char ch;
	for (i = 0; i < st.length(); i++) {
		if ((st[i] == '.') && (i < st.length() - 1)) {
			break;
		}
		else if (st[i] != '.') {
			count++;
		}
	}
	if ((count == st.length()) || (count == st.length() - 1)) {
		str = '0';
	}
	else {
		for (i = count + 1; i < st.length(); i++) {
			ch = st[i]; str += ch;
		}
		if (str[str.length()-1] == '0') {
			str = discarding_zeros(str);
		}
	}
	return str;
}
string discarding_zeros(string s) {
	int count=0, t;
	char ch;
	string str;
	t = s.length(); 
		if (s[t-1] == '0') {
			int i;
			for (i = t-1; i >= 0; i--) { 
				if (s[i] != '0') { break; }
				 count++;
			}
			t -= count;
if (t == 0) {
					str = '0';
				}
else if (t == 1) {
	str = s[0];
}
else {
	int j;
	for (j = 0; j < t; j++) {
		ch = s[j]; str += ch;
	}
}
		}
		return str;
}

string absoluteValue_function(string str) {	
	string s;
	char ch;
	if (str[0] == '-') {
        int i;
		for (i = 1; i < str.length(); i++) {
			ch = str[i]; s += ch;
		}
	}
	else {
		s = str;
	}
	return s;
}

	
// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
