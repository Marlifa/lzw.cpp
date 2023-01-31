#ifndef LZW_H
#define LZW_H

#include <vector>
#include <string>
#include <unordered_map>

// Функция сжатия по алгоритму LZW
std::vector<int> LZW_compress(const std::string& input) {
    // инициализируем словарь
    int dict_size = 256;
    std::unordered_map<std::string, int> dict;
    for (int i = 0; i < dict_size; i++)
        dict[std::string(1, i)] = i;

    std::string str;
    std::vector<int> output;
    for (auto c : input) {
        str.push_back(c);
        if (dict.count(str) == 0) {
            dict[str] = dict_size++;
            str.pop_back();
            output.push_back(dict[str]);
            str = c;
        }
    }
    if (str.length() > 0)
        output.push_back(dict[str]);

    return output;
}

// Функция декодирования вектора с числами типа int в строку
std::string LZW_decompress(const std::vector<int>& input) {
    // инициализируем словарь
    int dict_size = 256;
    std::unordered_map<int, std::string> dict;
    for (int i = 0; i < dict_size; i++)
        dict[i] = std::string(1, i);

    std::string str = dict[input[0]];
    std::string output = str;
    int prev_code = input[0];
    for (int i = 1; i < input.size(); i++) {
        int code = input[i];
        if (dict.count(code) == 0)
            dict[code] = dict[prev_code] + str[0];
        str = dict[code];
        output += str;
        dict[dict_size++] = dict[prev_code] + str[0];
        prev_code = code;
    }

    return output;
}

#endif
