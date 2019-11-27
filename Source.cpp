#include <iostream>
#include <conio.h> //Функция _getch() для считывания кода нажатых клавиш.
#include <Windows.h> //Для настроек вывода в консоль и т.п.

using namespace std;

short int MainMenu()
{
	short int* marker = new short int(1);
	short int* button_code = new short int;
	*button_code = _getch();

}

int main()
{
	MainMenu();
	return 0;
}
//тест