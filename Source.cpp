#include <iostream>
#include <conio.h> //Функция _getch() для считывания кода нажатых клавиш.
#include <Windows.h> //Для настроек вывода в консоль и т.п.
#include <stdlib.h> //Функция system("cls") для очистки консоли.
#include <fstream> //Запись и чтение из файла.

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

short int Menu2()
{
	short int marker = 1;
	short int* button_code = new short int;
	while (true)
	{
		cout << "You haven't authorized! Are you sure you want to continue this way?\n";
		if (marker == 1)
		{
			HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(handle, FOREGROUND_GREEN);
			cout << "YES\n";
			SetConsoleTextAttribute(handle, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
		}
		else
		{
			cout << "YES\n";
		}
		if (marker == 2)
		{
			HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(handle, FOREGROUND_GREEN);
			cout << "NO\n";
			SetConsoleTextAttribute(handle, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
		}
		else
		{
			cout << "NO\n";
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
	char username[16];
	char password[16];
	cout << "Enter your username, only english letters and arabic numerals. (<= 16 symbols)\n";
	cin >> username;
	system("cls");
	cout << "Enter your password, only english letters and arabic numerals. (<= 16 symbols)\n";
	cin >> password;
	system("cls");
	ofstream data;
	data.open("data.txt");
	data << username;
	data << endl;
	data << password;
	data.close();
	cout << "Registration was successful!\n";
}

bool Authorization()
{
	char true_username[16];
	char true_password[16];
	ifstream data;
	data.open("data.txt");
	data >> true_username;
	data >> true_password;
	data.close();
	char input_username[16];
	char input_password[16];
	cout << "Enter your username:\n";
	cin >> input_username;
	system("cls");
	cout << "Enter your password: (Backspace working!)\n";
	char* input = new char;
	short int* i = new short int;
	for (*i = 0; *i < 16; *i += 1)
	{
		*input = _getch();
		if (*input == 13)
		{
			break;
		}
		else if (*input == 8 and *i > 0)
		{
			cout << "\b";
			*i -= 2;
		}
		else if (*input == 8)
		{
			;
		}
		else
		{
			input_password[*i] = *input;
			cout << "*";
		}
	}
	delete input;
	system("cls");
	bool* coincidence = new bool(true);
	for (short int j = 0; j < *i; j++)
	{
		if (true_username[j] != input_username[j])
		{
			*coincidence = false;
			cout << "There is no user with this name!\n";
			break;
		}
		if (true_password[j] != input_password[j])
		{
			*coincidence = false;
			cout << "Wrong password!\n";
			break;
		}
	}
	delete i;
	if (*coincidence == true)
	{
		delete coincidence;
		cout << "Authorization was successful!\n";
		return true;
	}
	else
	{
		delete coincidence;
		return false;
	}
}

void Greetings(bool user_status)
{
	char username[16];
	short int* func_choice = new short int;
	if (user_status == false)
	{
		*func_choice = Menu2();
		if (*func_choice == 1)
		{
			//User N
			//username[16] += "UserN";
		}
		else
		{
			//Возвращение в главное меню
			cout << "Log in to the appropriate place in the main menu.\n";
			return;
		}
	}
	else
	{
		//Имя из DATA
		ifstream data;
		data.open("data.txt");
		data >> username;
	}
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
				if (*user_status == false)
				{
					*user_status = Authorization();
				}
				else
				{
					cout << "You're already authorized.\n";
				}
			}
			break;
		case 2:
			Greetings(*user_status);
			break;
		default:
			break;
		}
		//Возможность завершить работу программы.
		cout << "If you want to close the program, press 'Escape' button.\n";
		short int* input = new short int;
		*input = _getch();
		system("cls");
		if (*input == 27) //Escape button code.
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