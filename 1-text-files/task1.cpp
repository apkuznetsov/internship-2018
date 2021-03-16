#include <fstream>
using namespace std;

int main()
{
	const char* FILE_NAME = "Hello.txt";
	const char* INSERTED_LINE = "INSERTED";
	const int K = 4;

	FILE* myFile = fopen(FILE_NAME, "rt");
	const char tempFileName[] = "tempFile.txt";
	FILE* additFile = fopen(tempFileName, "wt");

	if (!myFile || !additFile) {
		puts("ошибка: невозможно открыть или создать файл\n");
		return -1;
	}

	char ch;
	int pos = 0;
	int linesNumb = 1;
	bool IsSuchLine = false;
	while (!feof(myFile))
	{
		ch = fgetc(myFile);
		fputc(ch, additFile);
		++pos;
		if (ch == '\n')
		{
			++linesNumb;
			if (linesNumb == K + 1)	// запись после K-ой строки
			{
				fputs(INSERTED_LINE, additFile);
				IsSuchLine = true;
				break;
			}
		}
	}

	if (IsSuchLine)
	{
		while (!feof(myFile))
		{
			ch = fgetc(myFile);
			fputc(ch, additFile);
			++pos;
		}
		fclose(myFile);
		fclose(additFile);
		remove(FILE_NAME);
		rename(tempFileName, FILE_NAME);
	}
	else
	{
		fclose(myFile);
		fclose(additFile);
		remove(tempFileName);
		puts("строки с таким номером нет в файле — файл оставлен без изменений\n");
	}
}
