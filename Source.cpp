#include <iostream>
#include <conio.h> //Функция _getch() для считывания кода нажатых клавиш.
#include <Windows.h> //Для настроек вывода в консоль и т.п.
#include <stdlib.h> //Функция system("cls") для очистки консоли.
#include <fstream> //Запись и чтение из файла.
#include <chrono>

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

short int Menu3()
{
	short int marker = 1;
	short int* button_code = new short int;
	while (true)
	{
		cout << "Choose the method of array entry:\n";
		if (marker == 1)
		{
			HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(handle, FOREGROUND_GREEN);
			cout << "1. Manual input\n";
			SetConsoleTextAttribute(handle, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
		}
		else
		{
			cout << "1. Manual input\n";
		}
		if (marker == 2)
		{
			HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(handle, FOREGROUND_GREEN);
			cout << "2. Random numbers from 0 to 99\n";
			SetConsoleTextAttribute(handle, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
		}
		else
		{
			cout << "2. Random numbers from 0 to 99\n";
		}
		if (marker == 3)
		{
			HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(handle, FOREGROUND_GREEN);
			cout << "3. From the 'array.txt' file. (there is a sample in the directory)\n";
			SetConsoleTextAttribute(handle, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
		}
		else
		{
			cout << "3. From the 'array.txt' file. (there is a sample in the directory)\n";
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
				marker = 3;
			}
			break;
		case 80: //Стрелка вниз.
		case 83: //S
		case 115: //s
		case 155: //Ы
		case 235: //ы
			marker += 1;
			if (marker > 3)
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

short int Menu3_2()
{
	short int marker = 1;
	short int* button_code = new short int;
	while (true)
	{
		cout << "Select the sorting algorithm:\n";
		//Выделение цветом.
		if (marker == 1)
		{
			HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(handle, FOREGROUND_GREEN);
			cout << "1. Bubble sort\n";
			SetConsoleTextAttribute(handle, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
		}
		else
		{
			cout << "1. Bubble sort\n";
		}
		if (marker == 2)
		{
			HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(handle, FOREGROUND_GREEN);
			cout << "2. Shaker sort\n";
			SetConsoleTextAttribute(handle, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
		}
		else
		{
			cout << "2. Shaker sort\n";
		}
		if (marker == 3)
		{
			HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(handle, FOREGROUND_GREEN);
			cout << "3. Comb sort\n";
			SetConsoleTextAttribute(handle, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
		}
		else
		{
			cout << "3. Comb sort\n";
		}
		if (marker == 4)
		{
			HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(handle, FOREGROUND_GREEN);
			cout << "4. Insert sort\n";
			SetConsoleTextAttribute(handle, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
		}
		else
		{
			cout << "4. Insert sort\n";
		}
		if (marker == 5)
		{
			HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(handle, FOREGROUND_GREEN);
			cout << "5. Quick sort\n";
			SetConsoleTextAttribute(handle, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
		}
		else
		{
			cout << "5. Quick sort\n";
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
				marker = 5;
			}
			break;
		case 80: //Стрелка вниз.
		case 83: //S
		case 115: //s
		case 155: //Ы
		case 235: //ы
			marker += 1;
			if (marker > 5)
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

void BrUnsignedInt(unsigned int x);

void BrString(char * subname)
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
	BrUnsignedInt(9893);
	cout << ",\n" << "and surname as:\n";
	char subname[7] = "Ivanov";
	BrString(subname);
	delete func_choice;
}

void BrUnsignedInt(unsigned int x)
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

void RandomizeArray(short int amount_of_elements, short int* arr)
//Процедура заполняет массив arr длины amount_of_elements случайными значениями [srand(time(NULL))] в диапазоне от 0 до 99 (int).
{
	srand(time(NULL));
	short int counter = 0;
	for (counter; counter < amount_of_elements; counter++)
	{
		arr[counter] = rand() % 100;
	}
}

void PrintArray(short int amount_of_elements, short int* arr)
//Процедура для вывода массива arr длины amount_of_elements в консоль, 10 элементов на строку.
//Если количество элементов в массиве больше 200, печатает по 20 элементов в строке.
//Если количество элементов в массиве больше 600, печатает по 40 элементов в строке.
//Если значение элемента массива меньше 10 (у числа только 1 разряд), перед ним в консоль печатается дополнительный пробел.
//После выполнения процедуры курсор переводится на две строки вниз.
{
	short int counter = 0;
	if (amount_of_elements <= 200)
	{
		for (counter; counter < amount_of_elements; counter++)
		{
			if ((counter + 1) % 10 == 0 and counter != 0)
			{
				if (arr[counter] >= 10)
					cout << arr[counter] << "\n";
				else
					cout << " " << arr[counter] << "\n";
			}
			else
			{
				if (arr[counter] >= 10)
					cout << arr[counter] << " ";
				else
					cout << " " << arr[counter] << " ";
			}
		}
		if (amount_of_elements % 10 != 0)
		{
			cout << "\n";
		}
	}
	else if (amount_of_elements <= 600)
	{
		for (counter; counter < amount_of_elements; counter++)
		{
			if ((counter + 1) % 20 == 0 and counter != 0)
			{
				if (arr[counter] >= 10)
					cout << arr[counter] << "\n";
				else
					cout << " " << arr[counter] << "\n";
			}
			else
			{
				if (arr[counter] >= 10)
					cout << arr[counter] << " ";
				else
					cout << " " << arr[counter] << " ";
			}
		}
		if (amount_of_elements % 20 != 0)
		{
			cout << "\n";
		}
	}
	else
	{
		for (counter; counter < amount_of_elements; counter++)
		{
			if ((counter + 1) % 40 == 0 and counter != 0)
			{
				if (arr[counter] >= 10)
					cout << arr[counter] << "\n";
				else
					cout << " " << arr[counter] << "\n";
			}
			else
			{
				if (arr[counter] >= 10)
					cout << arr[counter] << " ";
				else
					cout << " " << arr[counter] << " ";
			}
		}
		if (amount_of_elements % 40 != 0)
		{
			cout << "\n";
		}
	}
	cout << "\n";
}

float BubbleSort(short int amount_of_elements, short int* arr)
{
	short int exchange;
	short int i = 0; //Переменная-счетчик для цикла for.
	short int early_exit; //Отвечает за досрочный выход из цикла при завершении сортировки.
	unsigned int start_time = clock();
	do
	{
		early_exit = 0;

		for (i; i < amount_of_elements - 1; i++)
		{
			if (arr[i] > arr[i + 1])
			{
				exchange = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = exchange;
				early_exit += 1;
			}
		}
		amount_of_elements -= 1;
		i = 0;
	} while (early_exit != 0);
	unsigned int end_time = clock();
	return float(end_time - start_time) / 1000;
}

float ShakerSort(short int amount_of_elements, short int* arr)
{
	short int left_border = 0;
	short int right_border = 0;
	short int exchange;
	long int early_exit; //Отвечает за досрочный выход из цикла при завершении сортировки.
	short int i; //Переменная-счетчик для цикла for.
	unsigned int start_time = clock();
	do
	{
		early_exit = 0;
		i = left_border;
		for (i; i < amount_of_elements - right_border - 1; i++)
		{
			if (arr[i] > arr[i + 1])
			{
				exchange = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = exchange;
				early_exit += 1;
			}
		}
		right_border += 1;
		i = amount_of_elements - right_border - 1; //Т.к. в массивах индексы нумеруются с нуля.
		for (i; i > left_border - 1; i--)
		{
			if (arr[i] < arr[i - 1])
			{
				exchange = arr[i];
				arr[i] = arr[i - 1];
				arr[i - 1] = exchange;
				early_exit += 1;
			}
		}
		left_border += 1;
	} while (early_exit != 0);
	unsigned int end_time = clock();
	return float(end_time - start_time) / 1000;
}

float CombSort(short int amount_of_elements, short int* arr)
{
	const float reduction_factor = 1.2473309F; // 1 / (1 - e ^ (-ф)) -- где "e" - основание натурального логарифма, а ф - золотое сечение.
	long int step = amount_of_elements - 1;
	short int i;
	short int exchange;
	short int early_exit;
	unsigned int start_time = clock();
	do
	{
		early_exit = 0;
		for (i = 0; i < amount_of_elements - step; i++)
		{
			if (arr[i] > arr[i + step])
			{
				exchange = arr[i];
				arr[i] = arr[i + step];
				arr[i + step] = exchange;
				early_exit += 1;
			}
		}
		step /= reduction_factor;
	} while (early_exit != 0 or step >= 1);
	unsigned int end_time = clock();
	return float(end_time - start_time) / 1000;
}

float InsertSort(short int amount_of_elements, short int* arr)
{
	short int buffer;
	short int i;
	unsigned int start_time = clock();
	for (short int subarray_size = 1; subarray_size < amount_of_elements; subarray_size++)
	{
		buffer = arr[subarray_size];
		i = subarray_size;
		while (i != 0 and buffer < arr[i - 1])
		{
			arr[i] = arr[i - 1];
			i -= 1;
		}
		arr[i] = buffer;
	}
	unsigned int end_time = clock();
	return float(end_time - start_time) / 1000;
}

void QuickSort(short int* arr, short int low, short int high)
{                        //main()  -->  // 0 // amount_of_elements
	if (high - low < 2) return;
	short int exchange;
	short int left_index = low;
	short int right_index = high - 1;
	short int supporting_element_index = high - 1; //Опорный элемент - самый правый элемент.
	while (true)
	{
		for (left_index; left_index < high; left_index++)
		{
			if (arr[left_index] > arr[supporting_element_index])
			{
				break;
			}
		}
		if (left_index == high) left_index -= 1;
		for (right_index; low - 1 < right_index; right_index--)
		{
			if (arr[right_index] < arr[supporting_element_index])
			{
				break;
			}
		}
		if (right_index == low - 1) right_index += 1;
		if (left_index >= right_index)
		{
			exchange = arr[supporting_element_index];
			arr[supporting_element_index] = arr[left_index];
			arr[left_index] = exchange;
			supporting_element_index = left_index;
			break;
		}
		else
		{
			exchange = arr[left_index];
			arr[left_index] = arr[right_index];
			arr[right_index] = exchange;
		}
	}
	QuickSort(arr, low, supporting_element_index);
	QuickSort(arr, supporting_element_index + 1, high);
}

void Array()
{
	short int* array_size = new short int;
	short int* func_choice = new short int;
	short int* func_choice_2 = new short int;
	cout << "Enter the array size: (Arabic natural numbers, <= 32767)\n";
	cin >> *array_size;
	short int* arr = new short int[*array_size];
	system("cls");
	*func_choice = Menu3();
	switch (*func_choice)
	{
	case 1:

		break;
	case 2:
		RandomizeArray(*array_size, arr);
		break;
	case 3:

		break;
	default:
		break;
	}
	*func_choice_2 = Menu3_2();
	system("cls");
	PrintArray(*array_size, arr);
	switch (*func_choice_2)
	{
	case 1:
		cout << "Sorting time - " << BubbleSort(*array_size, arr) << "sec.\n\n";
		break;
	case 2:
		cout << "Sorting time - " << ShakerSort(*array_size, arr) << "sec.\n\n";
		break;
	case 3:
		cout << "Sorting time - " << CombSort(*array_size, arr) << "sec.\n\n";
		break;
	case 4:
		cout << "Sorting time - " << InsertSort(*array_size, arr) << "sec.\n\n";
		break;
	case 5:
		unsigned int start_time = clock();
		QuickSort(arr, 0, *array_size);
		unsigned int end_time = clock();
		float time = float(end_time - start_time) / 1000;
		cout << "Sorting time - " << time << "sec.\n";
		break;
	}
	PrintArray(*array_size, arr);
	delete array_size;
	delete func_choice;
	delete func_choice_2;
	delete[] arr;
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
			Array();
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