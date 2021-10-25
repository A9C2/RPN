#include <iostream>
#include <ctype.h>
#include <sstream>
#include <tgmath.h>
using namespace std;

const int SIZE = 3;

string stack[SIZE];
int stackPointer = -1;

int getInt(string s) {
  stringstream obj;
  obj << s;
  int n;
  obj >> n;
  return n;
}

string getString (int n) {
  stringstream obj;
  obj << n;
  string s;
  obj >> s;
  return s;
}

bool isOperator(char c) {
  return c == '+' or c == '-' or c == '*' or c == '/' or c =='^';
}

bool isNumber(string s) {
  for (int i = 0; i < s.length(); ++i) {
    if (!isdigit(s[i])) {
      return false;
    }
  }
  return true;
}

void push(string newElement) {
  stack[++stackPointer] = newElement;
}

string pop() {
  return stack[stackPointer--];
}

void displayStack() {
  cout << "Stos (pozycja: wartość)" << endl;
  for (int i = SIZE - 1; i > -1; --i) {
    cout << i << ": " << stack[i];
    if (i == stackPointer) {
      cout << " <--";
    }
    cout << endl;
  }
}

int stackLength() {
  return stackPointer + 1;
}

string getNewStackElementInput() {
  string s;
  while (true) {
    cout << "Wprowadź element do umieszczenia w stosie: ";
    cin >> s;

    if (s.length() == 1 and isOperator(s[0]) and stackLength() >= 2) {
      int b = getInt(pop());
      int a = getInt(pop());
      char o = s[0];
      int result;
      if (o == '+') {
        result = a + b;
      } else if (o == '-') {
        result = a - b;
      } else if (o == '*') {
        result = a * b;
      } else if (o == '/') {
        result = a / b;
      } else if (o == '^') {
        result = pow(a, b);
      }
      return getString(result);
    }

    if (isNumber(s)) {
      return s;
    }

    cout << "Niewłaściwe dane. Podaj liczbę, bądź operator (+-*/^). Do wykonania operacji potrzebne są minimum 2 liczby." << endl;
  } 
}

int main() {
  for (int i = 0; i < SIZE; ++i) {
    cout << "[" << i + 1 << "/" << SIZE << "] ";
    push(getNewStackElementInput());
    displayStack();
  }
  cout << "Wynik to: " << stack[0];
}