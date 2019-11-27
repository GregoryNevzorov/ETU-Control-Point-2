#include <iostream>
#include <conio.h> //Функция _getch() для считывания кода нажатых клавиш.
#include <Windows.h> //Для настроек вывода в консоль и т.п.
#include <stdlib.h> //Функция system("cls") для очистки консоли.

using namespace std;

short int MainMenu()
{
	short int marker = 1;
	short int* button_code = new short int;
	while (true)
	{
		//Выделение цветом.
		if (marker == 1)
		{
			HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(handle, FOREGROUND_GREEN);
			cout << "1. Registration or Authorization\n";
			SetConsoleTextAttribute(handle, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
		}
		else
		{
			cout << "1. Registration or Authorization\n";
		}
		if (marker == 2)
		{
			HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(handle, FOREGROUND_GREEN);
			cout << "2. Greetings\n";
			SetConsoleTextAttribute(handle, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
		}
		else
		{
			cout << "2. Greetings\n";
		}
		if (marker == 3)
		{
			HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(handle, FOREGROUND_GREEN);
			cout << "3. Array\n";
			SetConsoleTextAttribute(handle, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
		}
		else
		{
			cout << "3. Array\n";
		}
		if (marker == 4)
		{
			HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(handle, FOREGROUND_GREEN);
			cout << "4. Flag\n";
			SetConsoleTextAttribute(handle, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
		}
		else
		{
			cout << "4. Flag\n";
		}
		*button_code = _getch();
		system("cls");
		switch (*button_code)
		{
		case 72: //Стрелка вверх.
		case 119: //W.
			marker -= 1;
			if (marker < 1)
			{
				marker = 4;
			}
			break;
		case 80: //Стрелка вниз.
		case 115: //S.
			marker += 1;
			if (marker > 4)
			{
				marker = 1;
			}
			break;
		case 13: //Enter.
			delete button_code;
			return marker;
			break;
		default:
			break;
		}
	}
}

short int Menu1() //Доп. меню для первого пункта.
{
	short int marker = 1;
	short int* button_code = new short int;
	while (true)
	{
		if (marker == 1)
		{
			HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(handle, FOREGROUND_GREEN);
			cout << "1. Registration\n";
			SetConsoleTextAttribute(handle, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
		}
		else
		{
			cout << "1. Registration\n";
		}
		if (marker == 2)
		{
			HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(handle, FOREGROUND_GREEN);
			cout << "2. Authorization\n";
			SetConsoleTextAttribute(handle, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
		}
		else
		{
			cout << "2. Authorization\n";
		}
		*button_code = _getch();
		system("cls");
		switch (*button_code)
		{
		case 72: //Стрелка вверх.
		case 119: //W.
			marker -= 1;
			if (marker < 1)
			{
				marker = 2;
			}
			break;
		case 80: //Стрелка вниз.
		case 115: //S.
			marker += 1;
			if (marker > 2)
			{
				marker = 1;
			}
			break;
		case 13: //Enter.
			delete button_code;
			return marker;
			break;
		default:
			break;
		}
	}
}

void Registration()
{

}

short int Authorization()
{
	return 0;
}

int main()
{
	bool* user_status = new bool(false);
	short int* func_choice = new short int;
	while (true)
	{
		*func_choice = MainMenu();
		switch (*func_choice)
		{
		case 1:
			*func_choice = Menu1();
			if (*func_choice == 1)
			{
				Registration();
			}
			else
			{
				Authorization();
			}
			break;
		default:
			break;
		}
		//Возможность завершить работу программы.
		cout << "If you want to close the program, press 'Escape' button.\n";
		short int* input = new short int;
		*input = _getch();
		system("cls");
		if (*input == 27)
		{
			delete input;
			break;
		}
		delete input;
	}
	delete user_status;
	delete func_choice;
	return 0;
}