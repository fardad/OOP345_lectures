// conditional_platform.cpp
// Simulate platforms with defines (in real use, compilers define these)
#define WINDOWS  // Comment/uncomment to toggle

#include <iostream>

#if defined(WINDOWS)
#include <windows.h>
void greet() {
   std::cout << "Hello from Windows!" << std::endl;
}
void clearScreen() {
   HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
   COORD coord = { 0, 0 };
   DWORD count;
   CONSOLE_SCREEN_BUFFER_INFO csbi;

   GetConsoleScreenBufferInfo(hConsole, &csbi);
   FillConsoleOutputCharacter(hConsole, ' ', csbi.dwSize.X * csbi.dwSize.Y, coord, &count);
   SetConsoleCursorPosition(hConsole, coord);
}
#elif defined(__linux__)
#include <cstdlib>
void greet() {
   std::cout << "Hello from Linux!" << std::endl;
}
void clearScreen() {
   system("clear");
}
#else
void greet() {
   std::cout << "Hello from unknown platform!" << std::endl;
}
void clearScreen() {
}

#endif

int main() {
   greet();
   greet();
   greet();
   greet();
   greet();
   std::cin.ignore(1000, '\n');
   clearScreen();
   std::cout << "cleared" << std::endl;
   std::cin.ignore(1000, '\n');
   return 0;
}