#include "pch.h"
#include <iostream>
#include <fstream>
#include <cstdio>
#include <ctime>

using namespace std;

//int[] StartNumber;  // загадываемое число
//int[] Otgadka;  // Ваш ответ
int Counter = 1; //Счётчик ответов
int Score; //Количество очков сложности
int Level; //Сложность игры
int ScorePoint;//Счётчик очков

int Bulls = 0;
int Cows = 0;


void Menu(int ch)
{
    switch (ch)
    {
    case 1:
        cout << "Компьютер загадал 4-значное число с НЕповторяющимися цифрами. У Вас есть 10 попыток." << endl;
        //sum();
        break;
    case 2:
        cout << "Обычная игра временно недоступна. Компьютер не может выполнить Ваш запрос." << endl;
        //system("Pause");
        break;
    case 3:
        cout << "Сложная игра временно недоступна. Компьютер не может выполнить Ваш запрос." << endl;
        //system("Pause");
        break;
    case 4:
        cout << "Турнирная таблица временно неджоступна. Компьютер не может выполнить Ваш запрос." << endl;
        //system("Pause");
        break;
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
    cout << " Игра 'Быки и коровы'." << endl << " Привет, Игрок!" << endl <<
        " = = = =  Меню  = = = = " << endl << endl <<
        " (!) Пункты со * временно недоступны..." << endl << endl <<
        "1. Легкая игра (4-значное число, 10 попыток)." << endl <<
        "2)* Обычная игра(6 - значное число, 20 попыток)." << endl <<
        "3)* Сложная игра(10 - значное число, 40 попыток)." << endl <<
        "4)* Турнирная таблица." << endl <<
        "0) Выход." << endl << 
        "Ваш выбор: ";

    int choice;
    cin >> choice;
    Menu(choice);

     system("Pause");
}


/*
namespace MasterMind
{
    public partial class Form1 : Form
    {
        int[] StartNumber;  // загадываемое число
        int[] Otgadka;  // Ваш ответ
        int Counter = 1; //Счётчик ответов
        int Score; //Количество очков сложности
        int Level; //Сложность игры
        int ScorePoint;//Счётчик очков

        int Bulls = 0;
        int Cows = 0;

        public Form1()
        {
            InitializeComponent();
            panelLevelSelect.Visible = true;
            panel2.Location = new Point(0, 20);
            panel1.Location = new Point(400, 20);
            panelLevelSelect.Location = new Point(15,60);
        }

        private void buttonLevelEasy_Click(object sender, EventArgs e)
        {
            Level = 4;
            Score = 10;
            mtbInputOtgadka.Mask = "0000";
            StartButton();
        }

        private void buttonLevelMiddle_Click(object sender, EventArgs e)
        {
            Level = 6;
            Score = 20;
            mtbInputOtgadka.Mask = "000000";
            StartButton();
        }

        private void buttonLevelHard_Click(object sender, EventArgs e)
        {
            Level = 8;
            Score = 40;
            mtbInputOtgadka.Mask = "00000000";
            StartButton();
        }

        private void buttonPopytka_Click(object sender, EventArgs e) //кнопка Угадать
        {
            Bulls = 0;
            Cows = 0;



            if (ScorePoint > 1)
            {

                Console.WriteLine(mtbInputOtgadka.Text);
                string InputOtgadka = mtbInputOtgadka.Text;
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

        private void buttonStart_Click(object sender, EventArgs e)
        {
            StartButton();
        }

        //берешь функцию
        //создаёшь mock объект
        //вызываешь эту функцию с  mock объектом и проверяешь каждую строчку
        private void StartButton()
        {
            panelLevelSelect.Visible = false;
            panel1.Visible = true;
            panel1.Location = new Point(0, 20);
            StartNumber = new int[Level];
            Otgadka = new int[Level];
            labelLevel.Text = Level + " ";
            labelScorePoint.Text = Score + " ";
            rtbChat.Clear();
            mtbInputOtgadka.Text = "";
            GenSetN(Level, 10, StartNumber);
            ScorePoint = Score;
            labelScorePoint.Text = Score + " ";
            buttonStart.Visible = false;
            buttonPopytka.Visible = true;
            labelInputOtgadka.Visible = true;
            mtbInputOtgadka.Visible = true;
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