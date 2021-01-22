/*Предметная область – «Отдел кадров сотрудников». Данные о
сотруднике хранятся в структуре WORKER, содержащей следующие
поля:
 фамилию и инициалы работника;
 название занимаемой должности;
 год поступления на работу.
Задание на поиск: найти работников, чей стаж работы в организации
превышает значение, введѐнное с клавиатуры.*/


#include <iostream>
#include <fstream>
#include <string>
//#include "stdafx.h"
//#include "pch.h"
#include <regex>
#include <locale>



using namespace std;

#define Num 5
struct WORKER
{
	char NAME[80];
	char POS[20];
	int YEAR;
};
WORKER TABL[Num];

void ShowMenu()
{
    cout << " Меню:"
        << "\n 1.Список работников"
        << "\n 2.Редактирование работников"
        << "\n 3.Удаление работников"
        << "\n 4.Поиск работников"
        << "\n 5.Сохранить в фаил"
        << "\n 6.Загрузить из файла"
        << "\n 0.Выход"
        << endl;
}
int GetIntValue()
{
    bool bFirst = true;

    bool bCheck = false;

    const regex regex("(\\+|-)?[[:digit:]]+");

    string strValue;

    do
    {
        if (bFirst)
        {
            bFirst = false;
        }
        else
        {
            cin.clear();

            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout << "Invalid input. Значение должно быть целым." << endl;
        }

        strValue = GetStringValue();

        bCheck = regex_match(strValue, regex);

    } while (!bCheck);

    int iValue = atoi(strValue.c_str());

    return iValue;
}
string GetStringValue()
{
    bool bFirst = true;
    std::string strValue;

    do
    {
        if (bFirst)
        {
            bFirst = false;
        }
        else
        {
            std::cin.clear();

            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            std::cout << "Неправельный ввод. Значяение должно быть строкой g.\n";
        }

        std::cin >> strValue;

    } while (!std::cin.good());

    return strValue;
}
void PressToContinue()
{
    std::cout << "\nДля прододжения ,нажмите любую кнопку..."
        << std::endl;

    std::cin.get();
    std::cin.get();
}


int main() {

    setlocale(LC_ALL, "Russian");
    size_t nCommand = 1;




    while (nCommand != 0)
    {


        ShowMenu();

        nCommand = GetIntValue();



        switch (nCommand)
        {
        case 1:
        {
            std::cout << "Добавить работников\n\n";


        }
        break;
        case 2:
        {
            std::cout << "Редактирование работников\n\n";

            std::cout << "Поиск работников:\n";


        }
        break;
        case 3:
        {
            std::cout << "Удаление работников\n\n";


        }
        break;
        case 4:
        {
            std::cout << "Поиск работников\n\n";


        }
        break;


        case 7:
        {
            std::cout << "Сохранить в фаил\n\n";

        }
        break;
        case 8:
        {
            std::cout << "Загрузить из файла\n\n";


        }
        break;
        case 0:
            std::cout << "Выход\n" << std::endl;
            break;
        default:
            std::cout << "Error: command unknown";
            break;
        }

        PressToContinue();

    }
    return 0;
 
}
/*
void ShowMenu()
{
   cout << " Меню:"
        << "\n 1.Список работников"
        << "\n 2.Редактирование работников"
        << "\n 3.Удаление работников"
        << "\n 4.Поиск работников"
        << "\n 5.Сохранить в фаил"
        << "\n 6.Загрузить из файла"
        << "\n 0.Выход"
        << endl;
}
int GetIntValue()
{
    bool bFirst = true;

    bool bCheck = false;

    const regex regex("(\\+|-)?[[:digit:]]+");

    string strValue;

    do
    {
        if (bFirst)
        {
            bFirst = false;
        }
        else
        {
            cin.clear();

            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout << "Invalid input. Значение должно быть целым." << endl;
        }

        strValue = GetStringValue();

        bCheck = regex_match(strValue, regex);

    } while (!bCheck);

    int iValue = atoi(strValue.c_str());

    return iValue;
}
string GetStringValue()
{
    bool bFirst = true;
    std::string strValue;

    do
    {
        if (bFirst)
        {
            bFirst = false;
        }
        else
        {
            std::cin.clear();

            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            std::cout << "Неправельный ввод. Значяение должно быть строкой g.\n";
        }

        std::cin >> strValue;

    } while (!std::cin.good());

    return strValue;
}
void PressToContinue()
{
    std::cout << "\nДля прододжения ,нажмите любую кнопку..."
        << std::endl;

    std::cin.get();
    std::cin.get();
}

*/

/*
void prog()
{
	setlocale(LC_ALL, "Russian");//Объявляем локализацию текста в консоли

















	for (int i = 0; i < Num; i++)//Заполнение структуры данными
	{
		system("cls");
		cin.get(); cout<<"Введите ФИО работника: "; cin.getline(TABL[i].NAME, 80);
		cout<<"Введите должность работника: "; cin>>TABL[i].POS;
		cout<<"Введите год поступления на работу: "; cin>>TABL[i].YEAR;
	}
	//Сортировка по Алфавиту
	for (int i = 0; i < Num; i++)
	{
		for (int j = 0; j < Num; j++)
		{
			if (TABL[i].NAME[0] < TABL[j].NAME[0])
			{
				swap(TABL[i], TABL[j]);
			}
			else if (TABL[i].NAME[0] == TABL[j].NAME[0])
			{
				if (TABL[i].NAME[1] < TABL[j].NAME[1])
				{
					swap(TABL[i], TABL[j]);
				}
			}
		}
	}
	//Вывод работников по алфавиту
	system("cls");
	for (int i = 0; i < Num; i++)
	{
		cout<<"ФИО работника: "<<TABL[i].NAME<<endl;
		cout<<"Должность работника: "<<TABL[i].POS<<endl;
		cout<<"Год поступления на работу: "<<TABL[i].YEAR<<endl;
		cout<<endl;
	}
	//Поиск работников имеющих стаж работы отличный от введенного числа
	system("pause"); system("cls");
	short Year; bool flag = false; //Объявляем переменные
	cout<<"\nВведите нужный вам год и вы узнаете работников \nимеющих стаж работы не меньше года: ";
AskYear: cin>>Year; system("cls"); //Ввод года и очистка консоли от записей
	if (Year <= 0)
	{
		cout<<"Вы ввели недопустимый год! Введите корректный год :"; goto AskYear; //Запрос на повторный ввод значения "год"
	}
	else
	{
		for (int i = 0; i < Num; i++)//Цикл перебора массива структур TABL поля NAME
		{
			if (TABL[i].YEAR < Year)//Условие проверяющее стаж работника с введенным годом с клавиатуры
			{
				for (int j = 0; j < sizeof(TABL[i].NAME); j++)//Цикл проверки строки NAME
				{
					if (TABL[i].NAME[j] == ' ')//Проверка символов на равенство "пробел" или нет.
					{
						break; //Вывод из цикла если "пробел"
					}
					else
					{
						cout<<TABL[i].NAME[j]; //Вывод символа если не равен "пробелу"
					}
				}
				cout<<endl;
				flag = true;
			}
		}
	}
	if (flag == false) cout<<"Работников со стажем не найдено.\n\n";//Вывод сообщения (сотрудников со стажем не найдено)
	system("pause");
}

*/
