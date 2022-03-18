#include "pch.h"
#include <iostream>
#include <iomanip>
#include <cstdio>
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
static bool Answer(int * Otg, int lvl)
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
    while (Counter <= Score)
    {
        if (Answer(Otgadka, Level))  // ответ
                if (NumberCompare(StartNumber, Otgadka, Level))
                {
                    cout << "Вы угадали число c " << Counter << " попытки!" << endl;
                    return;
                }
        
        int CountAnswer = BullsAndСows(StartNumber, Otgadka, Level);
        if (CountAnswer == 0)
        {
            cout << "Ход " << Counter << " . В Вашем числе нет загаданных цифр. Осталось " << Score-Counter << " попыток." << endl;
        }
        else
        {
            cout << "Ход " << Counter << ". Быки = " << Bulls << ", Коровы = " << Cows << ". Осталось " << Score-Counter << " попыток."<< endl;
        }
        Counter++;
    }

    cout << "Вы не угадали загаданное компьютером число ";
    for (int i = 0; i < Level; i++)
        cout << StartNumber[i];
    cout << " даже за " << Score << " предоставленных попыток..." << endl;
}

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
void Level_Settings()
{
    cout << "Компьютер загадал " << Level << "-значное число с НЕповторяющимися цифрами.У Вас есть " << Score << " попыток." << endl;
    Counter = 1;
    StartNumber = new int[Level];
    Otgadka = new int[Level];
    //Рандомно генерируем множество StartNumber не повторяющихся целых чисел в диапазоне от 0 до 9 (10 цифр)
    int pTemp, step = 0;
    while (step < Level)
    {
        pTemp = rand() % 10;
        if (GenSetN(step, pTemp, StartNumber))
            step++;
    }

    ProverkaOtveta();
    cout << "Игра завершена!" << endl << endl;
    system("pause");
}


//Переключатель-Меню
void Menu(int ch)
{
    switch (ch)
    {
    case 1:
        Level = 4;
        Score = 10;
        Level_Settings();
        break;
    case 2:
        Level = 6;
        Score = 20;
        Level_Settings();
        break;
    case 3:
        Level = 8;
        Score = 40;
        Level_Settings();
        break;
    case 4:
        Level = 2;
        Score = 10;
        Level_Settings();
        break;
    case 5:
        Level = 10;
        Score = 80;
        Level_Settings();
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
            "4)* Кошмарная игра (10-значное число, 5 попыток)." << endl <<
            "5) Бонусная игра (10-значное число, 80 попыток)." << endl <<
            "0) Выход." << endl <<
            "Ваш выбор: ";
        cin >> choice;
        Menu(choice);
    } while (choice != 0);
}