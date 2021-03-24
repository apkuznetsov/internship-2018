#define MIN_RUS_ASCII_CODE		-64	// русские буквы в ASCII
#define MAX_CAP_RUS_ASCII_CODE	-33	// большая буква Я
#define MAX_RUS_ASCII_CODE		-1
#define FNAME				"Text.txt"
#define MIN_K				1
#define CURR_K				5
#define MAX_K				9

static void DoubleX(ref int[] A, ref int N, int X)
{
	int[] A2 = new int[2 * N];
	int i;
	int newN;
	for (i = 0, newN = 0; i < N; i++, newN++)
	{
		if (A[i] == X)
		{
			A2[newN++] = A[i];
			A2[newN] = A[i];
		}
		else
			A2[newN] = A[i];
	}

	A = A2;
	N = newN;
}

int PosK(const char* S0, const char* S, const int K)
{
	if (K < 0)
		throw "ошибка: номер вхождения не может быть равным или меньшим нуля";

	int
		i = 0,
		j = 0;

	if (S[i] == '\0')
		throw "ошибка: пустая строка";

	int numbOfInputs = 0;	// количество вхождений всего
	bool KeepOn = false;

	while (S[i] != '\0')
	{
		if (S[i] == S0[j])
			KeepOn = true;
		else
		{
			if (KeepOn & (S0[j] == '\0'))
			{
				if (++numbOfInputs == K)
					return (i - j);
				--i;
			}

			KeepOn = false;
			++i;
			j = 0;
			continue;
		}

		i++;
		j++;
	}
	if (S[i - 1] == S0[j - 1])	// если вхождение совпадает с концом строки
		if (++numbOfInputs == K)
			return (i - j);

	return -1;
}
static void DoubleX(ref int[] A, ref int N, int X)
{
	int[] A2 = new int[2 * N];
	int i;
	int newN;
	for (i = 0, newN = 0; i < N; i++, newN++)
	{
		if (A[i] == X)
		{
			A2[newN++] = A[i];
			A2[newN] = A[i];
		}
		else
			A2[newN] = A[i];
	}

	A = A2;
	N = newN;
}

int PosK(const char* S0, const char* S, const int K)
{
	if (K < 0)
		throw "ошибка: номер вхождения не может быть равным или меньшим нуля";

	int
		i = 0,
		j = 0;

	if (S[i] == '\0')
		throw "ошибка: пустая строка";

	int numbOfInputs = 0;	// количество вхождений всего
	bool KeepOn = false;

	while (S[i] != '\0')
	{
		if (S[i] == S0[j])
			KeepOn = true;
		else
		{
			if (KeepOn & (S0[j] == '\0'))
			{
				if (++numbOfInputs == K)
					return (i - j);
				--i;
			}

			KeepOn = false;
			++i;
			j = 0;
			continue;
		}

		i++;
		j++;
	}
	if (S[i - 1] == S0[j - 1])	// если вхождение совпадает с концом строки
		if (++numbOfInputs == K)
			return (i - j);

	return -1;
}

void EncodeText(const char* S, const int K)
{
	if ((K < MIN_K) | (K > MAX_K))
		throw "ошибка: по условию 0 < K < 10";

	FILE* f;
	if ((f = fopen(S, "r+b")) == NULL)
		throw "ошибка: невозможно открыть или создать файл";
	fseek(f, 0, SEEK_END);
	int sizeOfFile = ftell(f);

	char readSymb;	// считанный символ
	const int sizeOfChar = sizeof(char);
	int symbCodePlusK;
	const int maxCapMinusOne = MAX_CAP_RUS_ASCII_CODE - 1;
	const int maxCapPlusOne = MAX_CAP_RUS_ASCII_CODE + 1;
	const int maxMinusOne = MAX_RUS_ASCII_CODE - 1;
	for (int i = 0; i < sizeOfFile; i++)
	{
		fseek(f, i, SEEK_SET);
		fread(&readSymb, sizeOfChar, 1, f);

		symbCodePlusK = readSymb + K;
		if (readSymb >= MIN_RUS_ASCII_CODE)
		{
			if (readSymb <= MAX_CAP_RUS_ASCII_CODE)	// если большая буква
			{
				if (symbCodePlusK > MAX_CAP_RUS_ASCII_CODE)
					readSymb = MIN_RUS_ASCII_CODE + (symbCodePlusK - maxCapMinusOne);
				else
					readSymb += K;
			}
			else
			{
				if (readSymb <= MAX_RUS_ASCII_CODE)	// если маленькая буква
				{
					if (symbCodePlusK > MAX_RUS_ASCII_CODE)
						readSymb = maxCapPlusOne + (symbCodePlusK - maxMinusOne);
					else
						readSymb += K;
				}
				else
					continue;
			}

			fseek(f, i, SEEK_SET);
			fwrite(&readSymb, sizeOfChar, 1, f);
		}
	}

	fclose(f);
}

struct Point // TPoint
{
	double x;
	double y;
};

struct Triangle // TTriangle
{
	Point a;
	Point b;
	Point c;
};

double getLengthOfLineSegment(Point a, Point b) // Leng(A, B)
{
	return (
		sqrt(
			pow((a.x - b.x), 2) +
			pow((a.y - b.y), 2)));
}

double getPerimeterOfTriangle(Triangle triangle) // Perim(T)
{
	return (
		getLengthOfLineSegment(triangle.a, triangle.b) +
		getLengthOfLineSegment(triangle.b, triangle.c) +
		getLengthOfLineSegment(triangle.c, triangle.a));
}

double getAreaOfTriangle(Triangle triangle) // Area(T)
{
	double semiperimeter = getPerimeterOfTriangle(triangle) / 2.0;
	return (
		sqrt(
			semiperimeter *
			(semiperimeter - getLengthOfLineSegment(triangle.a, triangle.b)) *
			(semiperimeter - getLengthOfLineSegment(triangle.b, triangle.c)) *
			(semiperimeter - getLengthOfLineSegment(triangle.c, triangle.a))));
}

double getDistanceFromPointToLine(Point p, Point a, Point b) // Dist(P, A, B)
{
	Triangle triangle;
	triangle.c = p;
	triangle.a = a;
	triangle.b = b;

	return (2.0 * getAreaOfTriangle(triangle) / getLengthOfLineSegment(a, b));
}

void getAltitudesOfTriangle(Triangle triangle, double* h1, double* h2, double* h3) // Altitudes(T, h1, h2, h3)
{
	*h1 = getDistanceFromPointToLine(triangle.a, triangle.b, triangle.c);
	*h2 = getDistanceFromPointToLine(triangle.b, triangle.a, triangle.c);
	*h3 = getDistanceFromPointToLine(triangle.c, triangle.a, triangle.b);
}
