// ConsoleApplication1.14.5.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//Урок 14. Задача 3. Валидация IP-адреса.

#include <iostream>
#include <locale.h>
#include <string>
using namespace std;


int main()
{
	setlocale(LC_ALL, "Russian");
    int i, counter=0;
	string str, str0, str1, str2, str3;
	char ch;
	bool correct=true;
	cout << "\nВведите IP-адрес ";
	getline(cin, str);
	for (i = 0; i < str.length(); i++) {

		if (str[i] == ' ') {
			cout << "\n No"; break; correct = false;
		}
		else if ((str[0] == '0') && (str[1] == '0')) {
			cout << "\n No"; break; correct = false;
		}
		else if ((str[i] == '.') && (str[i + 1] == '.')) {
			cout << "\n No"; break; correct = false;
		}
		else if ((str[i] == '.') && (str[i + 1] == '0') && (str[i + 2] == '0')) {
			cout << "\n No"; break; correct = false;
		}
		else if (((str[i] < '0') || (str[i] > '9')) && (str[i] != '.')) {
			cout << "\n No"; break; correct = false;
		}
		else if ((str[i] != '.') && (counter == 0)) {
			ch = str[i]; str0 += ch;
		}
		else if ((str[i] != '.') && (counter == 1)) {
			ch = str[i]; str1 += ch;
		}
		else if ((str[i] != '.') && (counter == 2)) {
			ch = str[i]; str2 += ch;
		}
		else if ((str[i] != '.') && (counter == 3)) {
			ch = str[i]; str3 += ch;
		}
		else if (str[i] == '.') {
			counter++;
		}
		else if (counter > 3) {
			cout << "\n No"; break; correct = false;
		}
	}
		 if ((str0.length()>3)||(str1.length()>3)||(str2.length()>3)||(str3.length()>3)) {
				cout << "\n No"; correct = false;
			}
		else if((str0.length()== 3)&&((100*(str0[0]-'0')+10*(str0[1]-'0')+(str0[2]-'0'))>255)){
			cout << "\n No"; correct = false;
			}
		else if ((str1.length() == 3)&&((100*(str1[0] - '0')+10 *(str1[1] - '0')+(str1[2] - '0'))>255)) {
			cout << "\n No"; correct = false;
		}
		else if ((str2.length() == 3)&&((100 * (str2[0] -'0')+10*(str2[1]-'0')+(str2[2]-'0')) > 255)) {
			cout << "\n No"; correct = false;
		}
		else if ((str3.length() == 3) && ((100 * (str3[0] - '0') + 10 * (str3[1] - '0') + (str3[2] - '0')) > 255)) {
			cout << "\n No"; correct = false;
		}
		else if(correct==true) {
			cout << "\n Yes";
		}
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
