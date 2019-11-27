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
		case 87: //W
		case 119: //w
		case 150: //Ц
		case 230:  //ц
			marker -= 1;
			if (marker < 1)
			{
				marker = 4;
			}
			break;
		case 80: //Стрелка вниз.
		case 83: //S
		case 115: //s
		case 155: //Ы
		case 235: //ы
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
		case 87: //W
		case 119: //w
		case 150: //Ц
		case 230:  //ц
			marker -= 1;
			if (marker < 1)
			{
				marker = 2;
			}
			break;
		case 80: //Стрелка вниз.
		case 83: //S
		case 115: //s
		case 155: //Ы
		case 235: //ы
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
		case 87: //W
		case 119: //w
		case 150: //Ц
		case 230:  //ц
			marker -= 1;
			if (marker < 1)
			{
				marker = 2;
			}
			break;
		case 80: //Стрелка вниз.
		case 83: //S
		case 115: //s
		case 155: //Ы
		case 235: //ы
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
	cout << "Enter your username, only english letters and arabic numerals. (<= 15 symbols)\n";
	cin >> username;
	system("cls");
	cout << "Enter your password, only english letters and arabic numerals. (<= 15 symbols)\n";
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
	cout << "Enter your username: (<= 15 symbols)\n";
	cin >> input_username;
	system("cls");
	cout << "Enter your password: (<= 15 symbols)(Backspace working!)\n";
	char* input = new char;
	short int* i = new short int;
	for (*i = 0; *i < 16; *i += 1)
	{
		*input = _getch();
		if (*input == 13)
		{
			break;
		}
		//Backspace button
		else if (*input == 8 and *i > 0)
		{
			cout << "\b";
			*i -= 2;
		}
		else if (*input == 8)
		{
			;
		}
		//
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

void br_unsigned_int(unsigned int x);

void br_string(char * subname)
{
	union str
	{
		long integer;
		char element;
	};
	str str;
	unsigned long int marker;
	for (short int z = 0; z < 6; z++)
	{
		marker = 1 << 7;
		str.element = subname[z];
		cout << subname[z] << " = ";
		for (short int i = 0; i < 8; i++)
		{
			if ((marker & str.integer) == marker)
			{
				cout << "1";
			}
			else
			{
				cout << "0";
			}
			marker >>= 1;
		}
		if (z == 5)
		{
		    cout << ".";
		}
		else
		{
		    cout << ", ";
		}
	}
	cout << "\n";
}

void Greetings(bool user_status)
{
	char username[16] = "User N";
	short int* func_choice = new short int;
	if (user_status == false)
	{
		*func_choice = Menu2();
		if (*func_choice == 2)
		{
			//Возвращение в главное меню
			cout << "Log in to the appropriate place in the main menu.\n";
			delete func_choice;
			return;
		}
	}
	else
	{
		//Имя из DATA
		ifstream data;
		data.open("data.txt");
		data >> username;
		data.close();
	}
	cout << "I greet you, " << username << "!\n";
	cout << "There is such a blizzard on the street. Sit down at the hearth, here you are always welcome.\n";
	cout << "This program was written by a student of the group 9893, Gregory Ivanov.\n";
	cout << "By the way, in the memory of my computer, my group number looks like: ";
	br_unsigned_int(9893);
	cout << ",\n" << "and surname as:\n";
	char subname[7] = "Ivanov";
	br_string(subname);
	delete func_choice;
}

void br_unsigned_int(unsigned int x)
{
	unsigned long int integer_unsigned_number = x;
	//Значение для сравнения с битами вводимого числа.
	unsigned long int marker = 1 << 31;
	//Двигаемся от страшего бита к младшему.
	for (short int i = 0; i < 32; i++)
	{
		if ((marker & integer_unsigned_number) == marker)
		{
			cout << "1";
		}
		else
		{
			cout << "0";
		}
		marker >>= 1;
	}
}

void Flag()
{
	cout << "Russian flag:\n";
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(handle, 15);
	for (short int j = 0; j < 4; j++)
	{
		for (short int i = 0; i < 18; i++)
		{
			cout << "*";
		}
		cout << endl;
	}
	SetConsoleTextAttribute(handle, 1);
	for (short int j = 0; j < 4; j++)
	{
		for (short int i = 0; i < 18; i++)
		{
			cout << "*";
		}
		cout << endl;
	}
	SetConsoleTextAttribute(handle, 4);
	for (short int j = 0; j < 4; j++)
	{
		for (short int i = 0; i < 18; i++)
		{
			cout << "*";
		}
		cout << endl;
	}
	SetConsoleTextAttribute(handle, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	cout <<"Variant 5: Iceland:" << endl;
	for (short int j = 0; j < 4; j++)
	{
		SetConsoleTextAttribute(handle, 1);
        cout << "****";
		SetConsoleTextAttribute(handle, 15);
		cout << "*";
		SetConsoleTextAttribute(handle, 4);
		cout << "**";
		SetConsoleTextAttribute(handle, 15);
		cout << "*";
		SetConsoleTextAttribute(handle, 1);
		cout << "**********";
		cout << endl;
	}
	SetConsoleTextAttribute(handle, 15);
	cout << "*****";
	SetConsoleTextAttribute(handle, 4);
	cout << "**";
	SetConsoleTextAttribute(handle, 15);
	cout << "***********\n";
	SetConsoleTextAttribute(handle, 4);
	for (short int j = 0; j < 2; j++)
	{
		for (short int i = 0; i < 18; i++)
		{
			cout << "*";
		}
		cout << endl;
	}
	SetConsoleTextAttribute(handle, 15);
	cout << "*****";
	SetConsoleTextAttribute(handle, 4);
	cout << "**";
	SetConsoleTextAttribute(handle, 15);
	cout << "***********\n";
	for (short int j = 0; j < 4; j++)
	{
		SetConsoleTextAttribute(handle, 1);
		cout << "****";
		SetConsoleTextAttribute(handle, 15);
		cout << "*";
		SetConsoleTextAttribute(handle, 4);
		cout << "**";
		SetConsoleTextAttribute(handle, 15);
		cout << "*";
		SetConsoleTextAttribute(handle, 1);
		cout << "**********";
		cout << endl;
	}
	SetConsoleTextAttribute(handle, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
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
		case 3:

			break;
		case 4:
			Flag();
			break;
		default:
			break;
		}
		//Возможность завершить работу программы.
		cout << "If you want to close the program, press 'Escape' button or press another key to return to the main menu.\n";
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