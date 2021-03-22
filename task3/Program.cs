using System;
using System.IO;
using System.Text;

namespace task3
{
    class Program
    {
        static void Main()
        {
            const String TEXT_FILE = "Text.txt";
            const String INTEGERS_FILE = "Integers.txt";
            const String TEMP_FILE = "New Text.txt";
            const String NEW_LINE = "\r\n";

            Encoding enc = Encoding.GetEncoding(1251);  // подключение русского языка
            StreamReader textReader = new StreamReader(TEXT_FILE, enc);
            StreamReader integersReader = new StreamReader(INTEGERS_FILE, enc);
            StreamWriter newTextFile = new StreamWriter(TEMP_FILE);

            string lineFromText, lineFromIntegers;

            do
            {
                lineFromText = textReader.ReadLine();
                newTextFile.Write(lineFromText);
                if ((lineFromIntegers = integersReader.ReadLine()) != null)
                    newTextFile.Write(lineFromIntegers + NEW_LINE);
                else
                    break;
            } while (lineFromText != null);
            while ((lineFromText = textReader.ReadLine()) != null)  // чтобы, когда закончился файл с целыми числами, не считывать строки этого же файла
                newTextFile.Write(lineFromText + NEW_LINE);

            textReader.Close();
            integersReader.Close();
            newTextFile.Close();
            File.Delete(TEXT_FILE);
            File.Move(TEMP_FILE, TEXT_FILE);
        }
    }
}
