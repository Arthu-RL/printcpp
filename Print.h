#ifndef PRINT_H
#define PRINT_H
#include <iostream>
#include "MyString/MyString.h"

struct ConsoleColors
{
    const MyString reset = "\033[0m";
    const MyString bold = "\033[1m";

    // Normal Colors
    const MyString black = "\033[30m";
    const MyString red = "\033[31m";
    const MyString green = "\033[32m";
    const MyString yellow = "\033[33m";
    const MyString blue = "\033[34m";
    const MyString magenta = "\033[35m";
    const MyString cyan = "\033[36m";
    const MyString white = "\033[37m";

    // Light Colors
    const MyString lightBlack = "\033[90m";
    const MyString lightRed = "\033[91m";
    const MyString lightGreen = "\033[92m";
    const MyString lightYellow = "\033[93m";
    const MyString lightBlue = "\033[94m";
    const MyString lightMagenta = "\033[95m";
    const MyString lightCyan = "\033[96m";
    const MyString lightWhite = "\033[97m";
} consoleColors;

class Print
{   
public:
    void print_in_color(const char* message, const char* color) {
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
        print_in_color("OK", consoleColors.greenColor);
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