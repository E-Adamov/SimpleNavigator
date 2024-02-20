#include "./interface/s21_interface.h"

int main() {
  setlocale(LC_ALL, "ru");
  s21::Interface interface;
  interface.start();
}