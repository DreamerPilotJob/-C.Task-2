using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;

namespace WordFrequencyCounter
{
    class Program
    {
        static void Main(string[] args)
        {
            // Проверка наличия аргументов командной строки
            if (args.Length != 2)
            {
                Console.WriteLine("Usage: WordFrequencyCounter <input_file> <output_file>");
                return;
            }

            // Получение входного и выходного файлов
            string inputFile = args[0];
            string outputFile = args[1];

            // Чтение входного файла
            string text = File.ReadAllText(inputFile);

            // Разделение текста на слова
            string[] words = text.Split(new char[] { ' ', '\n', '\r', '.', ',', '!', '?', ';', ':' }, StringSplitOptions.RemoveEmptyEntries);

            // Подсчет частоты слов
            Dictionary<string, int> wordFrequencies = new Dictionary<string, int>();
            foreach (string word in words)
            {
                string lowerCaseWord = word.ToLower();
                if (wordFrequencies.ContainsKey(lowerCaseWord))
                {
                    wordFrequencies[lowerCaseWord]++;
                }
                else
                {
                    wordFrequencies[lowerCaseWord] = 1;
                }
            }

            // Сортировка слов по частоте использования
            var sortedWordFrequencies = wordFrequencies.OrderByDescending(pair => pair.Value);

            // Запись результатов в выходной файл
            using (StreamWriter writer = new StreamWriter(outputFile))
            {
                foreach (var pair in sortedWordFrequencies)
                {
                    writer.WriteLine($"{pair.Key}\t{pair.Value}");
                }
            }

            Console.WriteLine("Word frequencies have been saved to {0}", outputFile);
        }
    }
}
