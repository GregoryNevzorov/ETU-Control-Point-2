#include <iostream>
#include <conio.h> //������� _getch() ��� ���������� ���� ������� ������.
#include <Windows.h> //��� �������� ������ � ������� � �.�.

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