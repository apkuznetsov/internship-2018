#include <fstream>
#include <iostream>
#include <windows.h>
using namespace std;

void main()
{
	const char* TEXT_FILE_NAME = "text.txt";
	const char* SYMBOLS_FILE_NAME = "symbols.txt";

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "Rus");

	puts("Задание \"Text 54\".\n");
	puts("Выполнил: Кузнецов, группа 6213.\n");
	puts("     Дан текстовый файл. Создать символьный файл,");
	puts("содержащий все символы, встретившиеся в тексте,");
	puts("включая пробел и знаки препинания (без повторений).");
	puts("Символы располагать в порядке из первого появления в тексте.\n");

	FILE* tf = fopen(TEXT_FILE_NAME, "rt");
	FILE* nf = fopen(SYMBOLS_FILE_NAME, "wt");
	if (!tf || !nf) {
		puts("ошибка: невозможно открыть или создать файл\n");
		return -1;
	}
	fclose(nf);

	char ch;
	while (!feof(tf))
	{
		ch = fgetc(tf);
		if (!IsThereSuchSymb(SYMBOLS_FILE_NAME, ch))
		{
			nf = fopen(SYMBOLS_FILE_NAME, "at");
			fputc(ch, nf);
			fclose(nf);
		}
	}
	fclose(tf);
}

bool IsThereSuchSymb(const char* fname, const char symb)
{
	FILE* f = fopen(fname, "rt");
	if (!f)
		throw "ошибка: невозможно открыть или создать файл\n";

	char ch;
	while (!feof(f))
	{
		ch = fgetc(f);
		if (ch == symb)
		{
			fclose(f);
			return true;
		}
	}
	fclose(f);
	return false;
}
