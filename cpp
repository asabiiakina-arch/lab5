#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

// =====================================================
// ФУНКЦІЇ ВВЕДЕННЯ ДАНИХ З ПЕРЕВІРКОЮ КОРЕКТНОСТІ
// =====================================================

// Функція введення цілого числа з перевіркою
int inputInt(const string& msg)
{
    int x;
    while (true)
    {
        cout << msg;     // запит 
        cin >> x;        // введення значення

        // перевірка помилки введення
        if (!cin)
        {
            cin.clear();                 // очищення стану потоку
            cin.ignore(10000, '\n');     // очищення буфера
            cout << "Input error! Try again.\n";
        }
        else
            return x;    // коректне введення
    }
}

// Функція введення дійсного числа з перевіркою
double inputDouble(const string& msg)
{
    double x;
    while (true)
    {
        cout << msg;
        cin >> x;

        if (!cin)
        {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Input error! Try again.\n";
        }
        else
            return x;
    }
}

// =====================================================
// ЗАВДАННЯ 1. ГЕОМЕТРІЯ
// Перевірка належності точки червоній області
// =====================================================

// Функція перевірки належності точки (x, y) червоній області
bool inRedArea(double x, double y, double R)
{
    // перевірка: точка праворуч від осі Oy
    if (x < 0) return false;

    // перевірка: точка не виходить за межі R по осі Ox
    if (x > R) return false;

    // перевірка: точка вище похилої прямої y = x - R
    if (y < x - R) return false;

    // перевірка: точка всередині кола з центром (R, 0)
    if ((x - R) * (x - R) + y * y > R * R)
        return false;

    // якщо всі умови виконані
    return true;
}

// Основна процедура завдання 1
void task1()
{
    cout << "\n*********** TASK 1 (GEOMETRY) ***********\n";

    int n;              // кількість точок
    double x, y;        // координати точки
    int count = 0;      // лічильник точок у області
    double R = 5.0;     // радіус кола 

    // введення кількості точок
    n = inputInt("Enter number of points n: ");

    // цикл введення та перевірки точок
    for (int i = 1; i <= n; i++)
    {
        x = inputDouble("x = ");
        y = inputDouble("y = ");

        // перевірка належності точки області
        if (inRedArea(x, y, R))
            count++;
    }

    // виведення результату
    cout << "Points in red area: " << count << endl;
}

// =====================================================
// ЗАВДАННЯ 2. ОБЧИСЛЕННЯ РЯДУ (ВАРІАНТ 16)
// =====================================================

// Основна процедура завдання 2
void task2()
{
    cout << "\n*********** TASK 2 (SERIES) ***********\n";

    double x;       // дійсне число x
    int n;          // натуральне число n
    double term;    // поточний елемент ряду
    double sum;     // сума ряду

    // введення вхідних даних
    x = inputDouble("Enter real x: ");
    n = inputInt("Enter natural n: ");

    // перевірка коректності n
    if (n <= 0)
    {
        cout << "n must be positive!\n";
        return;
    }

    // ініціалізація першого елемента
    term = 1.0;
    sum = term;

    cout << fixed << setprecision(15);

    // виведення першого елемента
    cout << "k = 0  term = " << term << endl;

    // цикл обчислення елементів ряду
    for (int k = 1; k <= n; k++)
    {
        // рекурентна формула обчислення елемента
        term *= (2.0 * k - 1) / (2.0 * k) * x * x;
        sum += term;

        cout << "k = " << k << "  term = " << term << endl;

        // для парного варіанта — вивід кожного третього елемента
        if (k % 3 == 0)
            cout << ">>> every 3rd element: " << term << endl;
    }

    // виведення суми ряду
    cout << "Sum S = " << sum << endl;
}

// =====================================================
// ЗАВДАННЯ 3. ДОСЛІДЖЕННЯ ЗБІЖНОСТІ РЯДУ
// =====================================================

// Основна процедура завдання 3
void task3()
{
    cout << "\n*********** TASK 3 (CONVERGENCE) ***********\n";

    double e;       // мала величина epsilon
    double g;       // велика величина g
    int M;          // крок виведення
    double u;       // n-й елемент ряду
    double sum;     // сума ряду
    int n = 1;      // номер елемента

    // введення параметрів
    e = inputDouble("Enter epsilon e: ");
    g = inputDouble("Enter g: ");
    M = inputInt("Enter output step M: ");

    // перевірка коректності параметрів
    if (e <= 0 || g <= 0 || M <= 0)
    {
        cout << "Invalid parameters!\n";
        return;
    }

    sum = 0.0;
    cout << fixed << setprecision(15);

    // цикл дослідження збіжності
    while (true)
    {
        // обчислення n-го елемента ряду
        u = (n * n + 5.0) / pow(2.0, n);

        // умови завершення обчислень
        if (fabs(u) < e || fabs(u) > g)
            break;

        sum += u;

        // виведення з кроком M
        if (n % M == 0)
            cout << "n = " << n
                 << "  u_n = " << u
                 << "  sum = " << sum << endl;

        n++;
    }

    // виведення підсумкових результатів
    cout << "Last element u_n = " << u << endl;
    cout << "Final sum = " << sum << endl;
}

// =====================================================
// ГОЛОВНА ФУНКЦІЯ З МЕНЮ
// =====================================================
int main()
{
    int choice;    // вибір пункту меню

    do
    {
        cout << "\n========== MENU ==========\n";
        cout << "1 - Task 1 (Geometry)\n";
        cout << "2 - Task 2 (Series)\n";
        cout << "3 - Task 3 (Convergence)\n";
        cout << "0 - Exit\n";
        cout << "Choose: ";
        cin >> choice;

        switch (choice)
        {
        case 1: task1(); break;
        case 2: task2(); break;
        case 3: task3(); break;
        case 0: cout << "Program finished.\n"; break;
        default: cout << "Wrong menu item!\n";
        }
    }
    while (choice != 0);

    return 0;
}
