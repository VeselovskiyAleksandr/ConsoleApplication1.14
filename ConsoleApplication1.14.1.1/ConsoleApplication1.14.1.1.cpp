// ConsoleApplication1.14.1.1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
//Урок 14. Задача 1. Реализация шифра Цезаря.

#include <iostream>
#include <string>
#include <locale.h>
#include <cmath>
using namespace std;
string encrypted_Str(string str, int n);
string decreapt_ceasar(string encryptedStr, int n);
int main()
{
	setlocale(LC_ALL, "Russian");
	string strSource;
	int n;
	cout << "\nВведите предложение на английском. ";
	getline(cin, strSource);
	cout << "\nУкажите величину сдвига ";
	cin >> n;
	cout << "\nЗашифрованная строка ";
	cout<<encrypted_Str(strSource, n);
	strSource= encrypted_Str(strSource,n);
	cout << "\nДешифрованная строка: " << decreapt_ceasar(strSource, n);
}
string encrypted_Str(string str, int n) {
int i;
string  encryptedStr;
n = n % 26;
       encryptedStr = str;
	for (i = 0; i < str.length(); i++) {
		if(n>=0){
			if (str[i] >= 'A' && str[i] <= 'Z') {
				encryptedStr[i] =(int) str[i] + n;

				if ((int)str[i] + n> 90) {
					encryptedStr[i] = str[i] + n -26;
				}
			
			}
				
				if (str[i] >='a' && str[i] <='z') {
					encryptedStr[i] =(int)str[i] + n;
					if ((int)str[i] + n > 122) {
						encryptedStr[i] = (int)str[i] + n-26;

					}
				
				}
			}
		if (n < 0) {
			if (str[i] >= 'A' && str[i] <= 'Z') {
				encryptedStr[i] = (int)str[i] + n;

				if ((int)str[i] + n < 65) {
					encryptedStr[i] =(int) str[i] + n + 26;

				}
			}
			if (str[i] >= 'a' && str[i] <= 'z') {
				encryptedStr[i] = str[i] + n;

				if (str[i] + n < 'a') {
					encryptedStr[i] = str[i] + n + 26;
				}
			}
		}
	}
	return  encryptedStr;
}
string decreapt_ceasar(string encryptedStr  , int n) {
	string decreaptCeasar;
	n = -n%26;
	decreaptCeasar =encrypted_Str(encryptedStr,n);
	return decreaptCeasar;
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
