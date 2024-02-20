#include "s21_interface.h"

void s21::Interface::start() {
  clearScreen();
  string input;

  while (true) {
    cout << endl
         << "-------------------------------------------------------------"
         << endl;
    cout << "Выберите пункт:" << endl;
    cout << "1. Загрузка исходного графа из файла" << endl;
    cout << "2. Выгрузка графа в файл" << endl;
    cout << "3. Обход графа в ширину от заданной вершины" << endl;
    cout << "4. Обход графа в глубину от заданной вершины" << endl;
    cout << "5. Поиск кратчайшего пути между произвольными двумя вершинами"
         << endl;
    cout << "6. Поиск кратчайших путей между всеми парами вершин в графе"
         << endl;
    cout << "7. Поиск минимального остовного дерева в графе" << endl;
    cout << "8. Решение задачи комивояжера" << endl;
    cout << "9. Выход из программы" << endl;
    cout << "-------------------------------------------------------------"
         << endl;

    cout << "Введите от 1 до 9: ";
    cin >> input;
    clearScreen();
    if (input >= "1" && input <= "8" && input.size() == 1) {
      if (graph_.getSize() == 0 && input >= "2" && input <= "8") {
        cout << "\nОШИБКА: Граф пустой" << endl;
      } else if (input == "1") {
        try {
          cout << "\nУкажите название файла для загрузки:" << endl;
          cout << "Например: v5.txt, v6.txt, v11.txt" << endl;
          string file_path;
          cin >> file_path;
          graph_.loadGraphFromFile(file_path);
          cout << "Граф успешно загружен" << endl;
        } catch (const exception &e) {
          cout << "ОШИБКА: ";
          cout << e.what() << endl;
        }
      } else if (input == "2") {
        try {
          cout << "\nУкажите, название файла для сохранения" << endl;
          string file_path;
          cin >> file_path;
          file_path = file_path + ".dot";
          graph_.exportGraphToDot(file_path);
          cout << "Граф успешно сохранен" << endl;
        } catch (const exception &e) {
          cout << "ОШИБКА: ";
          cout << e.what() << endl;
        }
      } else if (input == "3") {
        cout << "\nОбход графа в ширину (BSF)" << endl;
        cout << "Укажите, начальную вершину (от 1 до " << graph_.getSize()
             << ")" << endl;
        s21::GraphAlgorithms ga;
        string str;
        cin >> str;
        try {
          int vertex = stoi(str);
          try {
            auto vector = ga.breadthFirstSearch(graph_, vertex);
            cout << "Полученный путь:" << endl;
            for (auto &it : vector) {
              cout << it << " ";
            }
            cout << endl;
          } catch (const exception &e) {
            cout << "ОШИБКА: ";
            cout << e.what() << endl;
          }
        } catch (...) {
          cout << "ОШИБКА: Нет такой вершины" << endl;
        }
      } else if (input == "4") {
        cout << "\nОбход графа в глубину (DSF)" << endl;
        cout << "Укажите, начальную вершину (от 1 до " << graph_.getSize()
             << ")" << endl;
        s21::GraphAlgorithms ga;
        string str;
        cin >> str;
        try {
          int vertex = stoi(str);
          try {
            auto vector = ga.depthFirstSearch(graph_, vertex);
            cout << "Полученный путь:" << endl;
            for (auto &it : vector) {
              cout << it << " ";
            }
            cout << endl;
          } catch (const exception &e) {
            cout << "ОШИБКА: ";
            cout << e.what() << endl;
          }
        } catch (...) {
          cout << "ОШИБКА: Нет такой вершины" << endl;
        }
      } else if (input == "5") {
        cout << "\nПоиск кратчайшего пути между произвольными двумя вершинами"
             << endl;
        cout << "Алгоритм Дейкстры" << endl;
        s21::GraphAlgorithms ga;
        cout << "Укажите, начальную вершину (от 1 до " << graph_.getSize()
             << ")" << endl;
        string str_begin;
        cin >> str_begin;
        cout << "Укажите, конечную вершину (от 1 до " << graph_.getSize() << ")"
             << endl;
        string str_end;
        cin >> str_end;
        try {
          int vertex_begin = stoi(str_begin);
          int vertex_end = stoi(str_end);
          try {
            auto result = ga.getShortestPathBetweenVertices(
                graph_, vertex_begin, vertex_end);
            cout << "Дистанция между вершинами:" << endl;
            cout << result << endl;
          } catch (const exception &e) {
            cout << "ОШИБКА: ";
            cout << e.what() << endl;
          }
        } catch (...) {
          cout << "ОШИБКА: Нет такой вершины" << endl;
        }
      } else if (input == "6") {
        cout << "\nПоиск кратчайших путей между всеми парами вершин в графе"
             << endl;
        s21::GraphAlgorithms ga;
        try {
          auto matrix = ga.getShortestPathsBetweenAllVertices(graph_);
          cout << "Матрица кратчайших путей:" << endl;
          for (size_t r = 0; r < matrix.getNumRows(); ++r) {
            for (size_t c = 0; c < matrix.getNumColumns(); ++c) {
              cout << matrix(r, c) << " ";
            }
            cout << endl;
          }
        } catch (const exception &e) {
          cout << "ОШИБКА: ";
          cout << e.what() << endl;
        }
      } else if (input == "7") {
        cout << "\nПоиск минимального остовного дерева в графе" << endl;
        cout << "Алгоритм Прима" << endl;
        s21::GraphAlgorithms ga;
        try {
          auto matrix = ga.getLeastSpanningTree(graph_);
          cout << "Матрица минимального остовного древа:" << endl;
          for (size_t r = 0; r < matrix.getNumRows(); ++r) {
            for (size_t c = 0; c < matrix.getNumColumns(); ++c) {
              cout << matrix(r, c) << " ";
            }
            cout << endl;
          }
        } catch (const exception &e) {
          cout << "ОШИБКА: ";
          cout << e.what() << endl;
        }
      } else if (input == "8") {
        cout << "\nРешение задачи комивояжера" << endl;
        s21::GraphAlgorithms ga;
        try {
          auto tsm = ga.solveTravelingSalesmanProblem(graph_);
          cout << "Дистанция: " << endl;
          cout << tsm.distance << endl;
          cout << "Полученный путь:" << endl;
          for (auto &it : tsm.vertices) {
            cout << it << " ";
          }
          cout << endl;
        } catch (const exception &e) {
          cout << "ОШИБКА: ";
          cout << e.what() << endl;
        }
      }

    } else if (input == "9") {
      break;
    } else {
      cout << "\nОШИБКА: Некорректный ввод" << endl;
    }
  }
}
void s21::Interface::clearScreen() {
#if defined _WIN32
  system("cls");
#elif defined(__LINUX__) || defined(__gnu_linux__) || defined(__linux__)
  system("clear");
#elif defined(__APPLE__)
  system("clear");
#endif
}
