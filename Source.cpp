#include <iostream>
#include <string>
#include <fstream>
#include <cctype> 
#include <Windows.h>
#include <random>
using namespace std;

int randNum(const int length) // генерируем "случайное" число
{
    random_device rd;
    mt19937 mersenne(rd());
    return mersenne() % length; // диапазон чисел (0 - length)
}

bool makeChoice(char& choice) // предложение повторить 
{
    cout << "\n\nхотите ";
    while (true) {
        cout << "продолжить? да/нет - д/н : ";
        cin >> choice;
        cin.ignore(SHRT_MAX, '\n');
        if (choice == 'Д' || choice == 'Н' || choice == 'д' || choice == 'н')
            return (choice == 'Д' || choice == 'д') ? true : false;
        else cout << "Error, ";
    }
}

void readFile(vector<string>& vec) // считываем слова из файла в массив
{
    string path = "my_file.txt";
    ifstream inFile; // открываем файл для чтения
    inFile.open(path);
    string s;
    if (inFile.is_open()) { // или if (my_file), если файл найден и успешно открыт
        while (inFile && inFile >> s) // пока нет ошибок и EOF, извлекаем данные
            vec.push_back(s); // присваиваем данные в вектор
        inFile.close(); // закрываем файл
    }
    else  cout << "Файл \"C://my_file.txt\" не обнаружен\n";
}

void toArray(char* arr_ch, int length) // выводим массив-форму слова
{
    for (int j(0); j < length; ++j)
        cout << arr_ch[j] << " ";
}

void initializing_arrays(char* arr_ch, int* arr_i, const int length) // инициализируем массивы
{
    for (int i(0); i < length; ++i) { // инициализируем
        arr_ch[i] = '_'; // массив-форма с прочерками под символы
        arr_i[i] = -1; // массив индексов значением отличным от индексов
    }
}
void Picture(int count = 0)
{
    if (count == 7)
        cout << "\n"
        "\n"
        "\n"
        "\n"
        "\n"
        "\n"
        "\n"
        "\n"
        "\n"
        "\n"
        "\n"
        " $$$$$$$$$$$$$$$$$$$$$$$$$$$$\n"
        " $                          $\n" << endl;
    else false;
    if (count ==6)
        cout << "\n"
        "        $$$$$$$$$$$$$$$\n"
        "                      $\n"
        "                      $\n"
        "                      $\n"
        "                      $\n"
        "                      $\n"
        "                      $\n"
        "                      $\n"
        "                      $\n"
        "                      $\n"
        "                      $\n"
        " $$$$$$$$$$$$$$$$$$$$$$$$$$$$\n"
        " $                          $\n" << endl;
    else false;
    if (count == 5)
        cout << "\n"
        "        $$$$$$$$$$$$$$$\n"
        "        |             $\n"
        "        |             $\n"
        "        |             $\n"
        "        |             $\n"
        "                      $\n"
        "                      $\n"
        "                      $\n"
        "                      $\n"
        "                      $\n"
        "                      $\n"
        " $$$$$$$$$$$$$$$$$$$$$$$$$$$$\n"
        " $                          $\n" << endl;
    else false;
    if (count == 4)
        cout << "\n"
        "        $$$$$$$$$$$$$$$\n"
        "        |             $\n"
        "        |             $\n"
        "        |             $\n"
        "        |             $\n"
        "        O             $\n"
        "                      $\n"
        "                      $\n"
        "                      $\n"
        "                      $\n"
        "                      $\n"
        " $$$$$$$$$$$$$$$$$$$$$$$$$$$$\n"
        " $                          $\n" << endl;
    else false;
    if (count == 3)
        cout << "\n"
        "        $$$$$$$$$$$$$$$\n"
        "        |             $\n"
        "        |             $\n"
        "        |             $\n"
        "        |             $\n"
        "        O             $\n"
        "      /               $\n"
        "                      $\n"
        "                      $\n"
        "                      $\n"
        "                      $\n"
        " $$$$$$$$$$$$$$$$$$$$$$$$$$$$\n"
        " $                          $\n" << endl;
    else false;
    if (count == 2)
        cout << "\n"
        "        $$$$$$$$$$$$$$$\n"
        "        |             $\n"
        "        |             $\n"
        "        |             $\n"
        "        |             $\n"
        "        O             $\n"
        "      / | \\           $\n"
        "        |             $\n"
        "                      $\n"
        "                      $\n"
        "                      $\n"
        " $$$$$$$$$$$$$$$$$$$$$$$$$$$$\n"
        " $                          $\n" << endl;
    else false;
    if (count == 0)
        cout << "\n"
        "        $$$$$$$$$$$$$$$\n"
        "        |             $\n"
        "        |             $\n"
        "        |             $\n"
        "        |             $\n"
        "        O             $\n"
        "      / | \\           $\n"
        "        |             $\n"
        "       / \\            $\n"
        "                      $\n"
        "                      $\n"
        " $$$$$$$$$$$$$$$$$$$$$$$$$$$$\n"
        " $                          $\n" << endl;
    else false;

}

int main()
{
    SetConsoleCP(1251); SetConsoleOutputCP(1251);
    setlocale(LC_ALL, ""); // для работы toupper() с кириллицей
    char choice{}; // символ да/нет 
    cout << "Популярная игра, в которой Вам нужно угадать слово, буква за буквой.\n"
        "Угадывая одну букву за раз можно ошибиться только 8 раз.\n";
    do {
        char ch; // символ выбранный юзером
        int count(8); // счетчик, 6 попыток угадать букву
        bool flag(false);
        vector<string>vec; // массив всех слов

        readFile(vec); // считываем слова из файла в массив
        string str = vec[randNum(vec.size())]; // рандомно выбираем из массива одно слово
        const int length = str.length(); // длина рандомного слова
        char* arr_ch = new char[length]; // динам. массив-форма для угадывания символов ранд. слова
        int* arr_i = new int[length]; // динам. массив для индексов угаданных букв, для исключения повторов
        initializing_arrays(arr_ch, arr_i, length); // инициализируем массивы

        cout << "\nДобро пожаловать в игру \"Виселица\"!\n\nСлово - \t";
        toArray(arr_ch, length); // выводим массив-форму в виде прочерков
        cout << "\n\nУгадайте букву : ";
        while (count-- != 0) { // пока все попытки не использованы
            cin >> ch;  cout << endl;

            for (int k(0); k < length; ++k) // проверяем совпадение символа юзера с буквами слова
                if ((ch == str[k] || toupper(ch) == str[k])) { // если совпадение символа юзера с буквой слова
                    if (k != arr_i[k]) { // если символ, на данной позиции, совпал впервые
                        cout << "\nВерно - \t";
                        arr_ch[k] = toupper(ch); // присваиваем в массив-форму символ в прописном виде
                        toArray(arr_ch, length); // выводим результат массива-формы
                        arr_i[k] = k; // присваиваем индекс итерации
                        for (int f(0); f < length; ++f) // проверяем все ли буквы угаданы
                            if (arr_ch[f] == '_') { // если не все, возвращаем 6 попыток
                                cout << endl;
                                ++count; break;
                            }
                            else if (f == length - 1) count = 9; // если все, слово угадано
                        break; // выходим из цикла
                    }
                    else flag = true; // если был повтор буквы на данной позиции в слове
                }
            cin.ignore(SHRT_MAX, '\n'); // очищаем поток
            if (count == 9) break; // т.к. слово угадано выходим из цикла
            else if (count == 8) { // начинаем поиск новой буквы
                cout << "\n\nУгадайте следующую букву : ";
                if (flag) flag = false;
            }
            else if (flag) { // если было повторное совпадение букв
                cout << "Угадайте следующую букву : ";
                ++count; // 
                flag = false;
            }
            else if (count == 0) // если попытки закончились
                cout << "Неверно!Такой буквы нет, у вас закончились попытки.\n"
                "\nЗагаданное слово - " << str;
            
            else // если совпадений не было, но попытки остались

                cout << "У вас осталось " << count <<
                " попыток неверно указать букву!\n" << "Угадайте следующую букву : "<<endl;
              Picture(count);  
           
        } 
        
        delete[] arr_ch;
        delete[] arr_i;
    } while (makeChoice(choice)); // продолжить (да/нет)

    return 0;
}