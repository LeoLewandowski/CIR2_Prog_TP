#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <cmath>

/// -------------------------- EXO 1 --------------------------

size_t longest_greater_monotony(std::vector<int> &arr)
{
    size_t pos = 0, size = 1, max = 0;
    while (pos < arr.size() - 1)
    {
        if (arr[pos] <= arr[pos + 1])
        {
            size++;
            if (size > max)
                max = size;
        }
        else if (pos >= arr.size() - 1 - max)
            break;
        else
            size = 1;
        pos++;
    }
    return max;
}

/// -------------------------- EXO 2 --------------------------

void next_word(std::vector<char> &word, std::vector<char> &alphabet)
{
    bool carry = true;

    for (size_t i = word.size() - 1; i >= 0; i--)
    {
        if (carry)
        {
            if (word[i] == alphabet.back())
                word[i] = alphabet.front();
            else
            {
                word[i] = *(std::find(alphabet.begin(), alphabet.end(), word[i]) + 1);
                carry = false;
            }
        }
        else
        {
            word[i] = word[i];
            carry = false;
        }
    }
}

void word_generator(std::vector<char> &original){
    std::set<char> uniq;
    uniq.insert(original.begin(), original.end());
    if(uniq.size() != original.size()) {
        std::cout << "The original word must only contain unique letters !" << std::endl;
        return;
    }
    std::sort(original.begin(), original.end());
    std::vector<char> word;
    word.insert(word.begin(), original.size(), original[0]);
    for(int i = 0; i < pow(original.size(), 3); i++) {
        std::cout << " - ";
        next_word()
        for(size_t j = 0; j < )
    }
}

/// -------------------------- MAIN --------------------------

int main(int argc, char const *argv[])
{
    std::vector<int> tab = {3, 1, 2, 8, 9, -8, 7, 7, 4, 10, 5, 6};
    auto size = longest_greater_monotony(tab);

    std::cout << "Longest monotony : " << size << std::endl;

    return 0;
}
