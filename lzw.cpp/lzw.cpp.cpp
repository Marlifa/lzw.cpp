#include <iostream>
#include "lzw.h" // подключаем библиотеку, которую написали

// КАК ИСПОЛЬЗОВАТЬ:
// #include "lzw.h" подключаем библиотеку

// ЧТОБЫ СЖАТЬ СТРОКУ:
// std::vector<int> compressed = LZW_compress(input_string);

// ЧТОБЫ ДЕКОДИРОВАТЬ (РАЗЖАТЬ):
// std::string decompressed = LZW_decompress(compressed);

// РЕЗУЛЬТАТ РАБОТЫ МОЖНО ПРОВЕРИТЬ ТУТ: https://planetcalc.ru/9069/

int main()
{
    std::string input;
    std::cout << "Enter the string to be compressed: ";
    std::getline(std::cin, input);
    // или использовать вместо написанного выше это - std::string input = "ABABA";

    // сжимаем строку по алгоритму LZW
    std::vector<int> compressed = LZW_compress(input); // либо auto compressed = LZW_compress(input)

    // декодируем вектор чисел типа int в строку
    std::string decompressed = LZW_decompress(compressed);

    std::cout << "Input: " << input << std::endl;
    std::cout << "Compressed: ";
    for (auto c : compressed)
        std::cout << c << " ";
    std::cout << std::endl;
    std::cout << "Decompressed: " << decompressed << std::endl;

    return 0;
}