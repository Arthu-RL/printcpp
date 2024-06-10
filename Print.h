#ifndef PRINT_H
#define PRINT_H
#include <iostream>
#include "MyString/MyString.h"

struct ConsoleColors
{
    MyString reset = "\033[0m";
    MyString bold = "\033[1m";

    // Normal Colors
    MyString black = "\033[30m";
    MyString red = "\033[31m";
    MyString green = "\033[32m";
    MyString yellow = "\033[33m";
    MyString blue = "\033[34m";
    MyString magenta = "\033[35m";
    MyString cyan = "\033[36m";
    MyString white = "\033[37m";

    // Light Colors
    MyString lightBlack = "\033[90m";
    MyString lightRed = "\033[91m";
    MyString lightGreen = "\033[92m";
    MyString lightYellow = "\033[93m";
    MyString lightBlue = "\033[94m";
    MyString lightMagenta = "\033[95m";
    MyString lightCyan = "\033[96m";
    MyString lightWhite = "\033[97m";
} consoleColors;

class Print
{   
public:
    void print_in_color(const char* message, MyString color) {
        std::cout << color << message << consoleColors.reset << std::endl;
    }

    template<typename ...Args>
    void debug(Args ...args) {
        std::cout << "[ ";
        print_in_color("DEBUG", consoleColors.bold+consoleColors.white);
        std::cout << " ] ";
        print(args...);
    }

    template<typename ...Args>
    void info(Args ...args) {
        std::cout << "[ ";
        print_in_color("INFO", consoleColors.bold+consoleColors.blue);
        std::cout << " ] ";
        print(args...);
    }

    template<typename ...Args>
    void ok(Args ...args) {
        std::cout << "[ ";
        print_in_color("OK", consoleColors.green);
        std::cout << " ] ";
        print(args...);
    }

    template<typename ...Args>
    void warn(Args ...args) {
        std::cout << "[ ";
        print_in_color("WARN", consoleColors.lightRed);
        std::cout << " ] ";
        print(args...);
    }

    template<typename ...Args>
    void error(Args ...args) {
        std::cout << "[ ";
        print_in_color("ERROR", consoleColors.red);
        std::cout << " ] ";
        print(args...);
    }

private:
    template<typename Arg>
    void print(const Arg arg)
    {
        std::cout << arg;
    }

    template<typename First, typename ...Args>
    void print(const First first, Args ...args) 
    {
        std::cout << first; 
        print(args...);
    }
};

#endif