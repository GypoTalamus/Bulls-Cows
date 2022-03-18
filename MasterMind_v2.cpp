#include "pch.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdio>
#include <ctime>

using namespace std;

int *StartNumber;  // загадываемое число
int *Otgadka;  // Ваш ответ
int Counter = 1; //Счётчик ответов
int Score; //Количество очков сложности
int Level; //Сложность игры
//int ScorePoint;//Счётчик очков - не реализована турнирная таблица

int Bulls = 0; //Счётчик Быков
int Cows = 0; //Счётчик Коров



//Сравнение на чистое совпадение
bool NumberCompare(int *StN, int *Otg, int Razmer)
{
    bool sovp = true;
    for (int i = 0; i < Razmer; i++)
    {
        if (StN[i] != Otg[i])
        {
            sovp = false;
            break;
        }
    }
    return sovp;
}

//Сравнение заданного и введенного чисел 
static int BullsAndСows(int *StN, int *Otg)
{
    int k = 0;
    for (int i = 0; i < Level; i++)
    {
        for (int j = 0; j < Level; j++)
        {
            if (StN[i] == Otg[j])
            {
                if (i == j)
                   Bulls++;
                else
                   Cows++;
                k++;
            }
        }
    }
    return k;
}

// Генератор множества StN не повторяющихся целых чисел в диапазоне от 0 до Maxis-1
static void GenSetN(int Lvl, int Maxis, int *StN)
{
    int p, k = 0;
    while (k < Lvl)
    {
        p = rand() % Maxis;
        bool nepovtor = true;
        for (int i = 0; i < k; i++)
            if (p == StN[i])
            {
                nepovtor = false;
                break;
            }
        if (nepovtor)
        {
            StN[k] = p;
            k++;
        }
    }
}


//Ответ пользователя (строка в число), так же проверяется правильность ввода числа (только цифры, не менее и не более заданных параметрами Сложности игры)
static bool Answer(int * Otg)
{
    bool bb = true;
    Bulls = 0;
    Cows = 0;
    string ss;
    cout << "Введите Ваше " << Level << "-значное число: ";
    while (bb)
    {
        cin >> ss;
        // посимвольная разборка
        for (int i = 0; i < Level; i++)
        {
            char c = ss[i];
            if ((isdigit(c)) && (ss.length() == Level))
            {
                Otg[i] = c - '0';
                bb = false;
            }
            else
            {
                cout << "Игрок, Вы ввели НЕ " << Level << "-хзначное число! Будьте так любезны, введите " << Level << "-значное число: " << endl;
                break;
            }
        }
    }
    bb = true;
    return bb;
}

//Запрашиваем ввод числа-отгадки, проверяем на совпадение, подсчитываем количество попыток ответа
void ProverkaOtveta()
{
    bool tak = true;
    while (Counter <= Score)
    {
        if (Answer(Otgadka))  // ответ
        {
            if (NumberCompare(StartNumber, Otgadka, Level))
            {
                cout << "Вы угадали число c " << Counter << " попытки!" << endl;
                return;
            }
        }

        int CountAnswer = BullsAndСows(StartNumber, Otgadka);
        if (CountAnswer == 0)
        {
            cout << "Ход " << Counter << " . В Вашем числе нет загаданных цифр." << endl;
        }
        else
        {
            cout << "Ход " << Counter << ". Быки = " << Bulls << ", Коровы = " << Cows << "." << endl;
        }
        Counter++;
    }

    cout << "Вы не угадали загаданное компьютером число ";
    for (int i = 0; i < Level; i++)
        cout << StartNumber[i];
    cout << " даже за " << Score << " предоставленных попыток..." << endl;
}

//Вывод на экран загаданного компьютером числа
void Zagadano()
{
    cout << "Загаданное число: ";
    for (int i = 0; i < Level; i++)
           cout << StartNumber[i];
    cout << endl << endl;
}

//Инициализируем переменные для загаданного числа, отгадки, генерируем загаданное и запускаем получение и проверку ответа
void Level_Settings()
{
    cout << "Компьютер загадал " << Level << "-значное число с НЕповторяющимися цифрами.У Вас есть " << Score << " попыток." << endl;
    Counter = 1;
    //ScorePoint = Score;
    StartNumber = new int[Level];
    Otgadka = new int[Level];
    GenSetN(Level, 10, StartNumber);
    //Zagadano();
    ProverkaOtveta();
    cout << "Игра завершена!" << endl << endl;
    system("pause");
}

//Параметры Простой игры
void Level_Easy()
{
    Level = 4;
    Score = 10;
    Level_Settings();
}

//Параметры Средней игры
void Level_Medium()
{
    Level = 6;
    Score = 20;
    Level_Settings();
}

//Параметры Сложной игры
void Level_Hard()
{
    Level = 8;
    Score = 40;
    Level_Settings();
}

//Переключатель-Меню
void Menu(int ch)
{
    switch (ch)
    {
    case 1:
        Level_Easy();
        break;
    case 2:
        Level_Medium();
        break;
    case 3:
        Level_Hard();
        break;
    case 0:
        cout << "Прощай, Игрок! Надеюсь, мы ещё встретимся!.." << endl;
        break;
    default:
        cout << "Такой команды нет, Игрок! Вернись и выбери заново!" << endl;
        break;
    }
}

//Основное тело программы
int main()
{
    setlocale(LC_ALL, "Russian");
    srand(time(0));
    cout << endl << " Игра 'Быки и коровы'." << endl << " Привет, Игрок!" << endl << endl;
    int choice; //переменная для выбора пункта меню

    //Цикл вывода меню повторяется, пока игрок не введет 0 - выход из игры
    do
    {
        Level = 0;
        Score = 0;
        cout <<  " = = = =  Меню  = = = = " << endl << endl <<
            "1) Простая игра (4-значное число, 10 попыток)." << endl <<
            "2) Средняя игра (6-значное число, 20 попыток)." << endl <<
            "3) Сложная игра (8-значное число, 40 попыток)." << endl <<
            "0) Выход." << endl <<
            "Ваш выбор: ";
        cin >> choice;
        Menu(choice);
    } while (choice != 0);
}