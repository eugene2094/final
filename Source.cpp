#include <iostream>
#include <string>
#include <fstream>
#include <cctype> 
#include <Windows.h>
#include <random>
using namespace std;

int randNum(const int length) // ���������� "���������" �����
{
    random_device rd;
    mt19937 mersenne(rd());
    return mersenne() % length; // �������� ����� (0 - length)
}

bool makeChoice(char& choice) // ����������� ��������� 
{
    cout << "\n\n������ ";
    while (true) {
        cout << "����������? ��/��� - �/� : ";
        cin >> choice;
        cin.ignore(SHRT_MAX, '\n');
        if (choice == '�' || choice == '�' || choice == '�' || choice == '�')
            return (choice == '�' || choice == '�') ? true : false;
        else cout << "Error, ";
    }
}

void readFile(vector<string>& vec) // ��������� ����� �� ����� � ������
{
    string path = "my_file.txt";
    ifstream inFile; // ��������� ���� ��� ������
    inFile.open(path);
    string s;
    if (inFile.is_open()) { // ��� if (my_file), ���� ���� ������ � ������� ������
        while (inFile && inFile >> s) // ���� ��� ������ � EOF, ��������� ������
            vec.push_back(s); // ����������� ������ � ������
        inFile.close(); // ��������� ����
    }
    else  cout << "���� \"C://my_file.txt\" �� ���������\n";
}

void toArray(char* arr_ch, int length) // ������� ������-����� �����
{
    for (int j(0); j < length; ++j)
        cout << arr_ch[j] << " ";
}

void initializing_arrays(char* arr_ch, int* arr_i, const int length) // �������������� �������
{
    for (int i(0); i < length; ++i) { // ��������������
        arr_ch[i] = '_'; // ������-����� � ���������� ��� �������
        arr_i[i] = -1; // ������ �������� ��������� �������� �� ��������
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
    setlocale(LC_ALL, ""); // ��� ������ toupper() � ����������
    char choice{}; // ������ ��/��� 
    cout << "���������� ����, � ������� ��� ����� ������� �����, ����� �� ������.\n"
        "�������� ���� ����� �� ��� ����� ��������� ������ 8 ���.\n";
    do {
        char ch; // ������ ��������� ������
        int count(8); // �������, 6 ������� ������� �����
        bool flag(false);
        vector<string>vec; // ������ ���� ����

        readFile(vec); // ��������� ����� �� ����� � ������
        string str = vec[randNum(vec.size())]; // �������� �������� �� ������� ���� �����
        const int length = str.length(); // ����� ���������� �����
        char* arr_ch = new char[length]; // �����. ������-����� ��� ���������� �������� ����. �����
        int* arr_i = new int[length]; // �����. ������ ��� �������� ��������� ����, ��� ���������� ��������
        initializing_arrays(arr_ch, arr_i, length); // �������������� �������

        cout << "\n����� ���������� � ���� \"��������\"!\n\n����� - \t";
        toArray(arr_ch, length); // ������� ������-����� � ���� ���������
        cout << "\n\n�������� ����� : ";
        while (count-- != 0) { // ���� ��� ������� �� ������������
            cin >> ch;  cout << endl;

            for (int k(0); k < length; ++k) // ��������� ���������� ������� ����� � ������� �����
                if ((ch == str[k] || toupper(ch) == str[k])) { // ���� ���������� ������� ����� � ������ �����
                    if (k != arr_i[k]) { // ���� ������, �� ������ �������, ������ �������
                        cout << "\n����� - \t";
                        arr_ch[k] = toupper(ch); // ����������� � ������-����� ������ � ��������� ����
                        toArray(arr_ch, length); // ������� ��������� �������-�����
                        arr_i[k] = k; // ����������� ������ ��������
                        for (int f(0); f < length; ++f) // ��������� ��� �� ����� �������
                            if (arr_ch[f] == '_') { // ���� �� ���, ���������� 6 �������
                                cout << endl;
                                ++count; break;
                            }
                            else if (f == length - 1) count = 9; // ���� ���, ����� �������
                        break; // ������� �� �����
                    }
                    else flag = true; // ���� ��� ������ ����� �� ������ ������� � �����
                }
            cin.ignore(SHRT_MAX, '\n'); // ������� �����
            if (count == 9) break; // �.�. ����� ������� ������� �� �����
            else if (count == 8) { // �������� ����� ����� �����
                cout << "\n\n�������� ��������� ����� : ";
                if (flag) flag = false;
            }
            else if (flag) { // ���� ���� ��������� ���������� ����
                cout << "�������� ��������� ����� : ";
                ++count; // 
                flag = false;
            }
            else if (count == 0) // ���� ������� �����������
                cout << "�������!����� ����� ���, � ��� ����������� �������.\n"
                "\n���������� ����� - " << str;
            
            else // ���� ���������� �� ����, �� ������� ��������

                cout << "� ��� �������� " << count <<
                " ������� ������� ������� �����!\n" << "�������� ��������� ����� : "<<endl;
              Picture(count);  
           
        } 
        
        delete[] arr_ch;
        delete[] arr_i;
    } while (makeChoice(choice)); // ���������� (��/���)

    return 0;
}