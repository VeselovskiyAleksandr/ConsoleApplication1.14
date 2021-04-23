// ConsoleApplication1.14.3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//Урок 14. Задача 3. Проверка корректности e-mail адреса.
#include <iostream>
#include <locale.h>
 using namespace std;
string str_symbol(string str, int  countSymbol, int count);
int count_symbol(string subStr, string s);
int comparison_function(string subStr, string str);

int main()
{
    setlocale(LC_ALL, "Russian");
    int  countSymbolOne = 0, countSymbolTwo = 0, i;
    string mailStr, subStrOne, subStrTwo, strSym = "!#*/+-%${}|&^()~", strSym0 = "";
    cout << "\nВведите e-mail адрес ";
    cin >> mailStr;
    for (i = 0; i < mailStr.length(); i++) {
        if (mailStr[0] == '.') {
            cout << "\n No ";  break;
        }
 if (i == mailStr.length() - 1) {
            cout << "\n No "; 
        }
 
     if (mailStr[i] == '@') {
         break;
     }    
         countSymbolOne++;
 }
        subStrOne = str_symbol(mailStr, countSymbolOne, 0);
        subStrTwo = str_symbol(mailStr, mailStr.length(), countSymbolOne + 1);
   int subStrO, subStrT;
        subStrO = count_symbol(subStrOne, strSym);
        subStrT = count_symbol(subStrTwo, strSym0);
            if (subStrO + subStrT == subStrOne.length() + subStrTwo.length()) {
                cout << "\n Yes";
            }
            else {
                cout << "\n No";
            }
}


string str_symbol(string str, int  countSymbol, int count) {
    char chi;
    int i;
    bool coup = true;
    string s;
   
if ((countSymbol-count < 1) || (countSymbol-count > 64)) {//функция разделяет e-mail строку
    cout << "\n No ";  coup = false;                          //на две подстроки.  
    }   
if (coup == true) {
    for (i = count; i < countSymbol; i++) {
        chi = str[i]; s += chi;
    }
}
else if (coup == false) {
    s = "";
}
return s;
}


int count_symbol(string subStr, string s) {   //функция подсчитывает количество символов,
    int i;                                    // соответствующих  требуемым
    string strUppercase, strLowerCase, strNumber, strHyphen="-", strPoint=".";
        char chi;
    for (i ='A'; i <='Z'; i++) {
        chi = i;
        strUppercase += chi;
        strLowerCase += chi + 32;
    }
    for (i ='/'; i <='9'; i++) {
        chi = i;
        strNumber += chi;
    }
   int subSt = 0;
    subSt+= comparison_function(subStr, strUppercase);
    subSt+= comparison_function(subStr, strLowerCase);
    subSt += comparison_function(subStr, strNumber);
    subSt += comparison_function(subStr, strHyphen);
    subSt+= comparison_function(subStr, s);
    subSt += comparison_function(subStr, strPoint);
    return subSt;
}


int comparison_function(string subStr, string str) {//функция сравнивает символы
    int i, j, coup = 1,  count = 0;                 //с требуемыми;                                              
    for (i = 0; i < str.length(); i++) {            //subStr - подстрока e-mail адреса
        for (j = 0; j < subStr.length(); j++) {     //str - строки допустимых символов 
            if ((j<subStr.length()-1)&&(subStr[j] == '.') && (subStr[j + 1] == '.')) {
                cout << "\n No "; coup = 0; break;
        }
             if ((j == subStr.length() - 1) && (subStr[j] == '.')) {
                 cout << "\n No"; coup = 0; break;
             }    
                 if (str[i] == subStr[j]) {
                     count++;
                 }
             }
        if (coup == 0) {
            break;
        }
        }   
    return count;
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
