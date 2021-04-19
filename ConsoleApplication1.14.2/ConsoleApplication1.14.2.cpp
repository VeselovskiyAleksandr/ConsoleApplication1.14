// ConsoleApplication1.14.2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//Урок 14. Задача 5. Анализ результатов игры в крестики-нолики.

#include <iostream>
#include <locale.h>
using namespace std;
//void correct_input(string str); функция проверки правильности ввода
//void playing_field(string s0, s1, s2); эта функция почему-то не принимала 3 значения
int count_won(string str,char ch);
int count_symbol(string s,char ch);

int main() {
    setlocale(LC_ALL, "Russian");
        int countPoint = 0, countX = 0, countO = 0, countXwon = 0, countOwon = 0;
    string str0, str1, str2;
    cout << "\nВведите первую строку ";
    cin >> str0;
   // correct_input(str0);
    cout << "\nВведите вторую строку ";
    cin >> str1;
    //correct_input(str1);
    cout << "\nВведите третью строку ";
    cin >> str2;
   // correct_input(str2);
    countPoint = count_symbol(str0,'.') + count_symbol(str1,'.') + count_symbol(str2,'.');
    countX = count_symbol(str0,'X') + count_symbol(str1,'X') + count_symbol(str2,'X');
    countO = count_symbol(str0,'O') + count_symbol(str1,'O') + count_symbol(str2,'O');
 
    if ((str1.length() == 3) && (str1.length() == 3) && (str2.length() == 3) &&
        (countPoint + countX + countO == 9)) {
        if ((str0[0] == str1[1]) && (str0[0] == str2[2]) && (str0[0] == 'X')) {
            countXwon++;
        }
        else  if ((str0[2] == str1[1]) && (str0[2] == str2[0]) && (str0[2] == 'X')) {
            countXwon++;
        }
        else if ((str0[0] == str1[1]) && (str0[0] == str2[2]) && (str0[0] == 'O')) {
            countOwon++;
        }
        else if ((str0[2] == str1[1]) && (str0[2] == str2[0]) && (str0[2] == 'O')) {
            countOwon++;
        }
        countXwon += count_won(str0,'X') + count_won(str1,'X') + count_won(str2,'X');
        countOwon += count_won(str0,'O') + count_won(str1,'O') + count_won(str2,'O');
  
        if ((countXwon > 1) || (countOwon > 1) || ((countXwon > 0) && (countOwon > 0))) {
            cout << "\nIncorrect";
        }
        else if ((countX - countO > 1) || (countO > countX)) {
            cout << "\nIncorrect";
        }

        else if ((countXwon == 1) && (countX == countO + 1)) {
            cout << "\nPetya won ";
          
        }
        else if ((countOwon == 1) && (countO == countX)) {
            cout << "\nVanya won ";
           
        }
        else {
            cout << "\nNobody";
        }
    }
        else {
            cout << "\nIncorrect";
        }
    }


int count_won(string s,char ch){
        string x;
        int  countWon=0, i;
    x = s;
    for (i = 1; i < 3; i++) {
        if ((x[i] == s[0]) && (s[0] == ch)) {
            countWon++;
        }
    }
                if (countWon == 2) {
                    countWon = 1;
                }
                else {
                    countWon = 0;
                }
        
    return  countWon;
    }


 int count_symbol(string s, char ch) {
     int i, countSymbol=0;
     for (i = 0; i < 3; i++) {
         if (ch== s[i]) {
             countSymbol++;
         }
     }
     return  countSymbol;
}

 //void correct_input(string str) {
  //  int 
    //if (str.length() != 3) {
      //  cout << "\nIncorrect.";
    //}
   // int i;
     //   for (i = 0; i < 3; i++) {
       //     if ((str[i] != 'X') && (str[i] != 'O') && (str[i] != '.')) {
         //       cout << "\nIncorrect.";
           //     break;
            //}
     //   }
   // }
  
// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
