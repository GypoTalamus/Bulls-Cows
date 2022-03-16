#include "pch.h"
#include <iostream>
#include <fstream>
#include <cstdio>
#include <ctime>

using namespace std;

int *StartNumber;  // загадываемое число
int *Otgadka;  // Ваш ответ
int Counter = 1; //Счётчик ответов
int Score; //Количество очков сложности
int Level; //Сложность игры
int ScorePoint;//Счётчик очков

int Bulls = 0; //Счётчик Быков
int Cows = 0; //Счётчик Коров


// Сравнение на чистое совпадение
static bool NumberCompare(int * StN, int *Otg)
{
    bool sovp = true;
    for (int i = 0; i < 4; i++)
    {
        if (StN[i] != Otg[i])
        {
            sovp = false;
            break;
        }
    }
    return sovp;
}

// Сравнение заданного и введенного чисел 
static int BullsAndСows(int *StN, int * Otg)
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

// Генератор множества Nq не повторяющихся целых чисел в диапазоне от 0 до Nm-1 (RVA)
static void GenSetN(int Nq, int Nm, int *qN)
{
    int p, k = 0;
    while (k < Nq)
    {
        p = rand() % Nm;
        bool povtor = true;
        for (int i = 0; i < k; i++)
            if (p == qN[i])
            {
                povtor = false;
                break;
            }
        if (povtor)
        {
            qN[k] = p;
            k++;
        }
    }
}


// ответ пользователя (строка в число)
static bool Answer(int * Otg)
{
    bool bb = true;
    Bulls = 0;
    Cows = 0;
    cout << "Введите Ваше 4-значное число: ";
    string ss;
    cin >> ss;
    // посимвольная разборка
    for (int i = 0; i < 4; i++)
    {
        char c = ss[i];
        if (isdigit(c))
        {
            Otg[i] = c - '0';
        }
        else
        {
            cout << "Вы ввели НЕ " << Level << "-хзначное число!";
            bb = false;
            return bb;
        }
    }
    return bb;
}

void ProverkaOtveta()
{
    while (Counter <= Score)
    {
        if (Answer(Otgadka))  // ответ
            if (NumberCompare(StartNumber, Otgadka))
            {
                cout << "Вы угадали число c " << Counter << " попытки!";
                return;
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
}

void Level_Easy()
{
    Level = 4;
    Score = 10;
    ScorePoint = 10;
    StartNumber = new int[Level];
    Otgadka = new int[Level];
    GenSetN(Level, 10, StartNumber);
    cout << "Zagadano: ";
    for (int i = 0; i < Level; i++)
    {
        cout << StartNumber[i];
    }
    cout << endl << endl;


    ProverkaOtveta();
}



void Menu(int ch)
{
    switch (ch)
    {
    case 1:
        cout << "Компьютер загадал 4-значное число с НЕповторяющимися цифрами. У Вас есть 10 попыток." << endl;
        Level_Easy();

        break;
    //case 2:
    //    cout << "Обычная игра временно недоступна. Компьютер не может выполнить Ваш запрос." << endl;
    //    //
    //    break;
    //case 3:
    //    cout << "Сложная игра временно недоступна. Компьютер не может выполнить Ваш запрос." << endl;
    //    //
    //    break;
    //case 4:
    //    cout << "Турнирная таблица временно недоступна. Компьютер не может выполнить Ваш запрос." << endl;
    //    //
    //    break;
    case 0:
        cout << "Прощай, Игрок! Надеюсь, мы ещё встретимся!.." << endl;
        break;
    default:
        cout << "Такой команды нет, Игрок! Вернись и выбери заново!" << endl;
        break;
    }
}

int main()
{
    setlocale(LC_ALL, "Russian");

    srand(time(0));

    int choice;
    
    //Цикл вывода меню повторяется, пока игрок не введет 0 - выход из игры
    do
    {
        cout << endl << " Игра 'Быки и коровы'." << endl << " Привет, Игрок!" << endl <<
            " = = = =  Меню  = = = = " << endl << endl <<
            " (!) Пункты со * временно недоступны..." << endl << endl <<
            "1. Легкая игра (4-значное число, 10 попыток)." << endl <<
            "2)* Обычная игра(6 - значное число, 20 попыток)." << endl <<
            "3)* Сложная игра(10 - значное число, 40 попыток)." << endl <<
            "4)* Турнирная таблица." << endl <<
            "0) Выход." << endl <<
            "Ваш выбор: ";
        cin >> choice;
        Menu(choice);
    } while (choice != 0);
    

     system("Pause");
}


/*
        int[] StartNumber;  // загадываемое число
        int[] Otgadka;  // Ваш ответ
        int Counter = 1; //Счётчик ответов
        int Score; //Количество очков сложности
        int Level; //Сложность игры
        int ScorePoint;//Счётчик очков

        int Bulls = 0;
        int Cows = 0;


        private void buttonPopytka_Click(object sender, EventArgs e) //кнопка Угадать
        {
            Bulls = 0;
            Cows = 0;



            if (ScorePoint > 1)
            {

                
                for (int it = 0; it < Level; it++)
                {
                    char c = InputOtgadka[it];
                    if (char.IsDigit(c))
                        Otgadka[it] = Convert.ToInt32(c - 48);
                }

                if (NumberCompare(StartNumber, Otgadka))
                {
                    rtbChat.AppendText("Вы угадали число " + InputOtgadka + " c " + Counter + " попытки!");
                    buttonStart.Visible = true;
                    buttonPopytka.Visible = false;
                    return;
                }

                int[,] Analyze = new int[Level, 2];
                // угаданная цифра Analyze[i,1], бык(Analyze[i,0]=2) корова(Analyze[i,0]=1)
                // АНАЛИЗ. CountAnswer - число угаданных цифр
                int CountAnswer = BullsAndСows(StartNumber, Otgadka, Analyze);

                if (CountAnswer == 0)
                {
                    rtbChat.AppendText("Ход " + Counter + ". В Вашем числе " + InputOtgadka + " нет загаданных цифр..." + "\r\n");
                    Counter++;
                    rtbChat.ScrollToCaret();
                }
                else
                {
                    rtbChat.AppendText("Ход " + Counter + ". Число " + InputOtgadka + ". Быки = " + Bulls + ", Коровы = " + Cows + "\r\n");
                    Counter++;
                    rtbChat.ScrollToCaret();
                }
            }
            else
            {
                rtbChat.AppendText("Вы не угадали загаданное компьютером число " + NumberToString() + " даже за " + Score + " предоставленных попыток..." + "\r\n");
                buttonStart.Visible = true;
                buttonPopytka.Visible = false;
            }

            ScorePoint -= 1;
            labelScorePoint.Text = ScorePoint + " ";
        }

       

        //берешь функцию
        //создаёшь mock объект
        //вызываешь эту функцию с  mock объектом и проверяешь каждую строчку

        private void StartButton()
        {
            StartNumber = new int[Level];
            Otgadka = new int[Level];
            
            GenSetN(Level, 10, StartNumber);
            ScorePoint = Score;
            
            Counter = 1;
        }

        // Генератор множества Nq не повторяющихся целых чисел в диапазоне от 0 до Nm-1 (RVA)
        static void GenSetN(int Nq, int Nm, int[] qN)
        {
            Random r = new Random();
            int p, k = 0;
            while (k < Nq)
            {
                p = r.Next(Nm);
                bool b = true;
                for (int i = 0; i < k; i++)
                    if (p == qN[i])
                    {
                        b = false;
                        break;
                    }
                if (b)
                {
                    qN[k] = p;
                    k++;
                }
            }
        }

        // Сравнение заданного и введенного чисел
        private int BullsAndСows(int[] stNum, int[] otg, int[,] anlz)
        {
            int k = 0;
            for (int i = 0; i < Level; i++)
            {
                for (int j = 0; j < Level; j++)
                {
                    if (stNum[i] == otg[j])
                    {
                        anlz[k, 1] = stNum[i];
                        if (i == j)
                        {
                            anlz[k, 0] = 2;
                            Bulls += 1;
                        }
                        else
                        {
                            anlz[k, 0] = 1;
                            Cows += 1;
                        }
                        k++;
                    }
                }
            }
            return k;
        }

        // Сравнение на чистое совпадение
        private bool NumberCompare(int[] a, int[] b)
        {
            bool d = true;
            for (int i = 0; i < Level; i++)
            {
                if (a[i] != b[i])
                {
                    d = false;
                    break;
                }
            }
            return d;
        }

        private void ExitToolStripMenuItem_Click(object sender, EventArgs e)
        {
            Application.Exit();
        }

        private void referenceToolStripMenuItem_Click(object sender, EventArgs e)
        {
            MessageBox.Show("Игра Быки-и-Коровы." + "\r\n" + "\r\n" +
                "Автор - студент группы ЗП-81 Горелов Иван Александрович. " + "\r\n" + "\r\n" +
                "Задание выбрано из списка тем, представленных для выполнения " + "\r\n" +
                "в виде курсовой работы с использованием распределённой " + "\r\n" +
                "системы контроля версий Github", "Справка");
        }

        private void button1_Click(object sender, EventArgs e)
        {
            panel2.Visible = false;
        }

        private void toolStripMenuItem1_Click(object sender, EventArgs e)
        {
            string Number = NumberToString();
            toolStripMenuItem1.Text = Number;
        }

        private string NumberToString()
        {
            string Numb = "";
            for (int i = 0; i < Level; i++)
            {
                Numb += StartNumber[i];
            }
            return Numb;
        }

        private void labelScorePoint_Click(object sender, EventArgs e)
        {
            ScorePoint = 2;
            labelScorePoint.Text = "2";
            Counter = Score-1;
        }
    }
}
*/