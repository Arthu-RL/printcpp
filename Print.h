#ifndef PRINT_H
#define PRINT_H
#include <iostream>

struct ConsoleColors
{
    const char *reset = "\033[0m";
    const char *bold = "\033[1m";

    // Normal Colors
    const char *black = "\033[30m";
    const char *red = "\033[31m";
    const char *green = "\033[32m";
    const char *yellow = "\033[33m";
    const char *blue = "\033[34m";
    const char *magenta = "\033[35m";
    const char *cyan = "\033[36m";
    const char *white = "\033[37m";

    // Light Colors
    const char *lightBlack = "\033[90m";
    const char *lightRed = "\033[91m";
    const char *lightGreen = "\033[92m";
    const char *lightYellow = "\033[93m";
    const char *lightBlue = "\033[94m";
    const char *lightMagenta = "\033[95m";
    const char *lightCyan = "\033[96m";
    const char *lightWhite = "\033[97m";
} consoleColors;

class Print
{   
public:
    void print_in_color(const char* message, const char* color) {
        std::cout << color << message << consoleColors.reset << std::endl;
    }

    template<typename... Args>
    void info(Args... args) {
        std::cout << "[ ";
        print_in_color("INFO", consoleColors.bold+consoleColors.blue);
        std::cout << " ] ";
        print(args...);
    }

    template<typename... Args>
    void ok(Args... args) {
        std::cout << "[ ";
        print_in_color("OK", consoleColors.greenColor);
        std::cout << " ] ";
        print(args...);
    }

    template<typename... Args>
    void warn(Args... args) {
        std::cout << "[ ";
        print_in_color("WARN", consoleColors.lightRed);
        std::cout << " ] ";
        print(args...);
    }

    template<typename... Args>
    void error(Args... args) {
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

    template<typename First, typename... Args>
    void print(const First first, Args ...args) 
    {
        std::cout << first; 
        print(args...);
    }
};

#endif