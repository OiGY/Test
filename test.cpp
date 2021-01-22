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
#include <iostream>
#include <iomanip>
#include <regex>
#include <tuple>
#include <math.h>
//#include "stdafx.h"
//#include "pch.h"
#include <regex>
#include <locale>
#include <functional>
#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/reader.h"
#include "rapidjson/stringbuffer.h"
#include "customlinkedlist.h"
//#include "environment.h"


using namespace std;
using namespace rapidjson;
typedef int size_t;

//#define Num 5

struct WORKER
{
	string NAME[80];
	string POS[20];
    int YEAR;
    
};
//WORKER TABL[Num];

struct Stream {
    std::ofstream of{ "/tmp/example.json" };
    typedef char Ch;
    void Put(Ch ch) { of.put(ch); }
    void Flush() {}
} stream;
enum class ERRORS
{
    NO_ERROR = 1,

    OBJ_EMPTY = -1,
    INVALID_ARGUMENT = -2,

    JSON_PART_BROKEN = -10,

    FILE_OPEN_ERROR = -20,
};

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

void PressToContinue()
{
    std::cout << "\nДля прододжения ,нажмите любую кнопку..."
        << std::endl;

    std::cin.get();
    std::cin.get();
}

int main() {

    typedef int size_t;

    LinkedList<WORKER>* pWorkers = new LinkedList<WORKER>();

    
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
            const WORKER worker = EnterFlight();

        }
        break;
        case 2:
        {
            void EditWorker();
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


        case 5:
        {
            std::cout << "Сохранить в фаил\n\n";

        }
        break;
        case 6:
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
bool CheckName(const std::string& NAME)
{
    const std::regex airRegex("[A-Za-z]");

    return regex_match(NAME, airRegex);
}
bool CheckYear(const int& Year)
{
    if (Year < 0); {
        return false;
    }
    
    return Year;

   
}
WORKER AddWorker()
{
    WORKER workers;

    string strTemp;
    bool bFirst = true;

    cout << "Введите ФИО: ";
    do
    {
        if (bFirst)
        {
            bFirst = false;
        }
        else
        {
            cout << "Только буквы" << std::endl;
        }

        strTemp = GetStringValue();
    } while (!CheckName(strTemp));

    workers.NAME = strTemp;


    bFirst = true;
    std::cout << "Должность: ";
    do
    {
        if (bFirst)
        {
            bFirst = false;
        }
        else
        {
            std::cout << "Только буквы" << std::endl;
        }

        strTemp = GetStringValue();
    } while (!CheckName(strTemp));

    workers.POS = strTemp;


    int iNumber = 0;
    bFirst = true;
    std::cout << "Стаж работы: ";
    do
    {
        if (bFirst)
        {
            bFirst = false;
        }
        else
        {
            std::cout << "от 0 до 99" << std::endl;
        }

        iNumber = GetIntValue();
    } while (!CheckYear(iNumber));

    workers.YEAR = iNumber;


    return workers;
}
/*
class JsonArray;
ERRORS SaveToFile(const JsonArray& jArr, const string& strName)
{
    if (jArr.empty() || strName.empty())
    {
        return ERRORS::INVALID_ARGUMENT;
    }

    const QString strFileName = QString::fromStdString(strName);
    QFile saveFile(strFileName);

    if (!saveFile.open(QIODevice::WriteOnly))
    {
        return ERRORS::FILE_OPEN_ERROR;
    }

    QJsonDocument saveDoc(jArr);
    saveFile.write(saveDoc.toJson());

    return ERRORS::NO_ERROR;
}

QJsonArray LoadFromFile(const std::string& strName, ERRORS* pError)
{
    if (strName.empty())
    {
        if (pError != nullptr)
        {
            *pError = ERRORS::INVALID_ARGUMENT;
        }

        return {};
    }

    const QString strFileName = QString::fromStdString(strName);
    QFile loadFile(strFileName);

    if (!loadFile.open(QIODevice::ReadOnly))
    {
        if (pError != nullptr)
        {
            *pError = ERRORS::FILE_OPEN_ERROR;
        }

        return {};
    }

    QByteArray arrData = loadFile.readAll();

    QJsonDocument loadDoc = QJsonDocument::fromJson(arrData);

    if (pError != nullptr)
    {
        *pError = ERRORS::NO_ERROR;
    }

    return loadDoc.array();
}


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

