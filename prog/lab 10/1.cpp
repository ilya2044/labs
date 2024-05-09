#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int main()
{
    std::ifstream file("input.txt");
    std::vector<std::string> words;
    std::string line;
    while (std::getline(file, line))
    {
        std::string word;
        for (char c : line)
        {
            if (c == ' ')
            {
                words.push_back(word);
                word = "";
            }
            else
            {
                word += c;
            }
        }
        words.push_back(word);
    }
    file.close();

    std::sort(words.begin(), words.end());

    std::ofstream output("output.txt");
    for (const std::string &word : words)
    {
        output << word << " ";
    }
    output << '\n';
    output.close();

    return 0;
}