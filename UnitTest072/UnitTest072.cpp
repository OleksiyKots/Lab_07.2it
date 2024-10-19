#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_07.2it.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;


namespace MyProjectTests
{
    TEST_CLASS(SwapMaxMinInEvenRowsTest)
    {
    public:

        TEST_METHOD(TestSwapElementsInEvenRows)
        {
            const int k = 4;
            const int n = 4;
            int** a = new int* [k];
            for (int i = 0; i < k; i++) {
                a[i] = new int[n];
            }

            // Приклад матриці
            a[0] = new int[n] { 1, 2, 3, 4 };  // Парний рядок 0
            a[1] = new int[n] { 5, 6, 7, 8 };  // Непарний рядок 1
            a[2] = new int[n] { 9, 10, 11, 12 }; // Парний рядок 2
            a[3] = new int[n] { 13, 14, 15, 16 }; // Непарний рядок 3

            // Виклик функції для заміни
            SwapMaxMinInEvenRows(a, k, n);

            // Перевірка результату
            Assert::AreEqual(4, a[0][0]);  // Максимум у рядку 0 мав бути на місці 0
            Assert::AreEqual(1, a[0][3]);  // Мінімум у рядку 0 мав бути на місці 3
            Assert::AreEqual(12, a[2][0]); // Максимум у рядку 2 мав бути на місці 0
            Assert::AreEqual(9, a[2][3]);  // Мінімум у рядку 2 мав бути на місці 3

            // Очищення пам'яті
            for (int i = 0; i < k; i++) {
                delete[] a[i];
            }
            delete[] a;
        }
    };
}
