#include <string>
#include <iostream>

int pointer = 0;
std::string s;

void E();
void E_();
void T();
void T_();
void F();

void E()
{
    T();
    E_();
    if (s.at(pointer) == '\0') {
        std::cout << "String accepted." << std::endl;
    } else {
        std::cout << "Not accepted." << std::endl;
    }
}

void E_()
{
    if (s.at(pointer) == '+') {
        pointer++;
        T();
        E_();
    }
}
void T()
{
    F();
    T_();
}

void T_()
{
    if (s.at(pointer) == '*') {
        pointer++;
        F();
        T_();
    }
}

void F()
{
    if (s.at(pointer) == 'i' && s.at(pointer + 1) == 'd') {
        pointer++;
        pointer++;
    } else if (s.at(pointer) == '(') {
        pointer++;
        E();
        if (s.at(pointer) == ')') {
            pointer++;
        }
    }
}

int main()
{
    std::cout << "Enter input string: ";
    std::cin >> s;
    s.push_back('\0');
    E();
    return 0;
}
