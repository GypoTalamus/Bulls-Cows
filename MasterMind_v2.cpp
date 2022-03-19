#include "pch.h"
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cctype>
#include <ctime>

using namespace std;

int *StartNumber;  // загадываемое число
int *Otgadka;  // Ваш ответ
int Counter; //Счётчик ответов
int Score; //Количество очков сложности
int Level; //Сложность игры

int Bulls = 0; //Счётчик Быков
int Cows = 0; //Счётчик Коров


//Сравнение на чистое совпадение
//Unit-test NumberCompare_Tests
static bool NumberCompare(int *StN, int *Otg, int lvl)
{
    bool sovp = true;
    for (int i = 0; i < lvl; i++)
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
//Unit-test BullsAndCows_Tests
static int BullsAndСows(int *StN, int *Otg, int lvl)
{
    int k = 0;
    for (int i = 0; i < lvl; i++)
    {
        for (int j = 0; j < lvl; j++)
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


//Ответ пользователя (строка в число), так же проверяется правильность ввода числа (только цифры, не менее и не более заданных параметрами Сложности игры)
//static bool Answer(int * Otg, int lvl)
static bool Answer(int* Otg, int lvl)
{
    bool bb = true;
    Bulls = 0;
    Cows = 0;
    string ss;
    cout << "Введите Ваше " << lvl << "-значное число: ";

    while (bb)
    {
        cin >> ss;
        // посимвольная разборка
        for (int i = 0; i < lvl; i++)
        {
            char c = ss[i];
                if ((isdigit(c)) && (ss.length() == lvl))
                {
                    Otg[i] = c - '0';
                    bb = false;
                }
                else
                {
                    cout << "Игрок, Вы ввели НЕ " << lvl << "-хзначное число! Будьте так любезны, введите " << lvl << "-значное число: " << endl;
                    bb = true;
                    break;
                }
            }
    }
    bb = true;
    return bb;
}

//Запрашиваем ввод числа-отгадки, проверяем на совпадение, подсчитываем количество попыток ответа
// НЕ всё можно протестировать Unit'ами
void ProverkaOtveta(int lvl, int scor)
{
    while (Counter <= scor)
    {
    if (Answer(Otgadka, lvl))  // ответ
        if (NumberCompare(StartNumber, Otgadka, lvl))
        {
            cout << "Вы угадали число c " << Counter << " попытки!" << endl;
            return;
        }

        int CountAnswer = BullsAndСows(StartNumber, Otgadka, lvl);
        if (CountAnswer == 0)
        {
            cout << "Ход " << Counter << " . В Вашем числе нет загаданных цифр. Осталось " << scor-Counter << " попыток." << endl;
        }
        else
        {
            cout << "Ход " << Counter << ". Быки = " << Bulls << ", Коровы = " << Cows << ". Осталось " << scor-Counter << " попыток."<< endl;
        }
        Counter++;
    }

    cout << "Вы не угадали загаданное компьютером число ";
    for (int i = 0; i < lvl; i++)
        cout << StartNumber[i];
    cout << " даже за " << scor << " предоставленных попыток..." << endl;
}


//Проверяем цифры на неповторяемость в загаданном числе
//Unit-test GenSetN_Tests
static bool GenSetN(int step, int pTemp, int *StN)
{
    bool nepovtor = true;
    for (int i = 0; i < step; i++)
        if (pTemp == StN[i])
        {
            nepovtor = false;
            break;
        }
    if (nepovtor)
    {
        StN[step] = pTemp;
    }
    return nepovtor;
}


//Инициализируем переменные для загаданного числа, отгадки, генерируем загаданное и запускаем получение и проверку ответа
// НЕ всё можно протестировать Unit'ами
void Level_Settings(int lvl, int scor)
{
    cout << "Компьютер загадал " << lvl << "-значное число с НЕповторяющимися цифрами.У Вас есть " << scor << " попыток." << endl;
    Counter = 1;
    StartNumber = new int[lvl];
    Otgadka = new int[lvl];
    //Рандомно генерируем множество StartNumber не повторяющихся целых чисел в диапазоне от 0 до 9 (10 цифр)
    int pTemp, step = 0;
    while (step < lvl)
    {
        pTemp = rand() % 10;
        if (GenSetN(step, pTemp, StartNumber))
            step++;
    }

    ProverkaOtveta(lvl, scor);
    cout << "Игра завершена!" << endl << endl;
    system("pause");
}


//Переключатель-Меню
// Не всё можно протестировать Unit'ами
void Menu(int ch, int lvl, int scor)
{
    switch (ch)
    {
    case 1:
        lvl = 4;
        scor = 10;
        Level_Settings(lvl, scor);
        break;
    case 2:
        lvl = 6;
        scor = 20;
        Level_Settings(lvl, scor);
        break;
    case 3:
        lvl = 8;
        scor = 40;
        Level_Settings(lvl, scor);
        break;
    case 4:
        lvl = 2;
        scor = 10;
        Level_Settings(lvl, scor);
        break;
    case 5:
        lvl = 10;
        scor = 80;
        Level_Settings(lvl, scor);
        break;
    case 0:
        //cout << "Прощай, Игрок! Надеюсь, мы ещё встретимся!.." << endl;
        break;
    default:
        cout << "Такой команды нет, Игрок! Вернись и выбери заново!" << endl;
        break;
    }
}


//Основное тело программы
// Не всё можно протестировать Unit'ами
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
        cout << " = = = =  Меню  = = = = " << endl << endl <<
            "1) Простая игра (4-значное число, 10 попыток)." << endl <<
            "2) Средняя игра (6-значное число, 20 попыток)." << endl <<
            "3) Сложная игра (8-значное число, 40 попыток)." << endl <<
            "4)* Кошмарная игра (10-значное число, 5 попыток)." << endl <<
            "5) Бонусная игра (10-значное число, 80 попыток)." << endl <<
            "0) Выход." << endl <<
            "Ваш выбор: ";
        cin >> choice;
        Menu(choice, Level, Score);
    } while (choice != 0);

    cout << "Прощай, Игрок! Надеюсь, мы ещё встретимся!.." << endl;
    delete[] StartNumber;
    delete[] Otgadka;
}