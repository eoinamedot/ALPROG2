#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <limits>

int main()
{
    // unsigned int start_time = clock(); // проверка времени выполнения программы

    std::cout << "Group, Name: 2346, E. Isaeva, N=8" << '\n'; // вводная часть, которая выводится на консоль
    std::cout << "Task - Array and Pointers" << '\n';
    std::cout << "Type: <1) Array, 2) Array and pointers> This is Program 2) Array and pointers" << '\n';
    std::cout << "Options of equation: Op(S)=4 (Op(S) = Nmod5+1)" << '\n';

    int i = 1;
    while (i < 5) // цикл для повторения тестов, итерация i++
    {
        unsigned n, m, total;

        std::cout << "\nTest t = " << i << "." << ' ';
        std::cout << "Input: n (rows) = ";
        std::cin >> n;
        std::cout << "Input: n (rows) = " << n << ", m(columns) = ";
        std::cin >> m;
        total = m * n;
        std::cout << "Input: n (rows) = " << n << ", m(columns) = " << m << ", total = " << total << " (elements)" << '\n';

        unsigned int start_time = clock();          // проверка времени выполнения одного цикла
        unsigned *nm_linear{new unsigned[n * m]{}}; // определение динамического двумерного массива
        unsigned **nm{new unsigned *[n] {}};        // определение динамического двумерного массива
        for (unsigned q{}; q < n; q++)
        {
            nm[q] = &nm_linear[m * q];
        }

        // Random
        unsigned int *end{nm[0] + n * m - 1}; // указатель на самый последний элемент 0 + 3 * 4 - 1 = 11
        unsigned int *pa{nm[0]};              // указатель на первый элемент
        *pa = rand() % 10;
        unsigned minVal = *pa; // определение переменной minVal для вычисления минимального элемента массива
        unsigned maxVal = *pa; // определение переменной maxVal для вычисления максимального элемена массива
        unsigned sum = *pa;    // определение переменной sum для вычисления суммы всех ээлементов массива
        unsigned av = *pa;     // определение переменной av для вычисления среднего значения элементов массива

        // std::cout << *pa << "\t";
        pa++;
        for (unsigned i{2}; pa <= end; pa++, i++)
        {
            *pa = rand();
            sum += *pa; // определение суммы, максимального и минимального значения элементов массива
            if (*pa < minVal)
                minVal = *pa;
            if (*pa > maxVal)
                maxVal = *pa;
            // std::cout << *pa << "\t";
            //  если остаток от целочисленного деления равен 0,
            /*  переходим на новую строку
            if (i % m == 0)
            {
                std::cout << std::endl;
            }*/
        }

        av = sum / total;
        std::cout << "\n1. Random array: max= " << maxVal << ' '; // вывод максимального элемента массива
        std::cout << "min= " << minVal << ' ';                    // вывод минимального элемента массива
        std::cout << "average= " << av;                           // вывод  среднего значения элементов массива

        // Estimated OS(S)
        unsigned int *end2{nm[0] + n * m - 1}; // указатель на самый последний элемент 0 + 3 * 4 - 1 = 11
        unsigned int *pa2{nm[0]};              // указатель на первый элемент
        // рандомное определение значения переменной x,y,z (20% от диапазона положительных чисел включая 0)
        float x = rand() % 10;
        float y = rand() % 10;
        float z = rand() % 10;
        float S1, S2, numer1, numer2, denom1, denom2; // определение переменных суммы первого слагаемого
        // и второго слагаемого, а так же числителей и знаменателей соответственно
        // std::cout << x << y << z << '\n';

        // рассчет ранее обозначенных переменных
        numer1 = (cbrt(y + (pow(z, x)))) * (pow((sin(x) + cos(z)), 2));
        denom1 = y * (pow((sin(z * x)), 2)) * (log(((exp(x)) + (exp(z)))));
        numer2 = (sqrt(y + (pow(x, z)))) * (pow((sin(x)), 2));
        denom2 = log(y + (pow(x, z) + (pow(z, x))));
        S1 = numer1 / denom1;
        S2 = numer2 / denom2;

        float S = S1 + S2; // расчет общей суммы
        // std::cout << S << '\n';
        unsigned value = static_cast<unsigned>(S); // присвоение переменной S тип данных unsigned int
        // std::cout << value << '\n';
        *pa2 = value;  // присвоение элементу массива значение суммы арифм операции
        minVal = *pa2; // определение переменной minVal для вычисления минимального элемента массива
        maxVal = *pa2; // определение переменной maxVal для вычисления максимального элемена массива
        sum = *pa2;    // определение переменной sum для вычисления суммы всех элементов массива
        av = *pa2;

        // std::cout << *pa2 << "\t";
        pa2++;
        // цикл для формирования массива по значениям введенных с консоли столбцов и строк
        for (unsigned i{2}; pa2 <= end; pa2++, i++)
        {
            // рандомное определение значения переменной x,y,z (20% от диапазона положительных чисел включая 0)
            x = rand() % 10;
            y = rand() % 10;
            z = rand() % 10;

            // рассчет ранее обозначенных переменных
            numer1 = (cbrt(y + (pow(z, x)))) * (pow((sin(x) + cos(z)), 2));
            denom1 = y * (pow((sin(z * x)), 2)) * (log(((exp(x)) + (exp(z)))));
            numer2 = (sqrt(y + (pow(x, z)))) * (pow((sin(x)), 2));
            denom2 = log(y + (pow(x, z) + (pow(z, x))));
            S1 = numer1 / denom1;
            S2 = numer2 / denom2;

            float S = S1 + S2;                         // расчет общей суммы
            unsigned value = static_cast<unsigned>(S); // присвоение переменной S тип данных unsigned int

            *pa2 = value;
            sum += *pa2; // определение суммы, максимального и минимального значения элементов массива
            if (*pa2 < minVal)
                minVal = *pa2;
            if (*pa2 > maxVal)
                maxVal = *pa2;
            /* std::cout << *pa2 << "\t";
            // если остаток от целочисленного деления равен 0,
            // переходим на новую строку
            if (i % m == 0)
            {
                std::cout << std::endl;
            } */
        }

        // Вывод суммы, максимального значения и минимального
        av = sum / total;
        std::cout << "\n2. Estimated array: max= " << maxVal << ' '; // вывод максимального элемента массива
        std::cout << "min= " << minVal << ' ';                       // вывод минимального элемента массива
        std::cout << "average= " << av;                              // вывод среднего значения элементов массива

        // очистка памяти
        delete[] nm;
        delete[] nm_linear;

        unsigned int end_time = clock();
        unsigned int search_time = end_time - start_time;
        std::cout << "\n3. Elapsed time: time = " << search_time << '\n';

        i++; // итерация
    }

    /* unsigned int end_time = clock();
    unsigned int search_time = end_time - start_time;
    std::cout << " 3. Elapsed time: time = " << search_time; */

    return 0;
}