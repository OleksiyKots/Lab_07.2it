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

            // ������� �������
            a[0] = new int[n] { 1, 2, 3, 4 };  // ������ ����� 0
            a[1] = new int[n] { 5, 6, 7, 8 };  // �������� ����� 1
            a[2] = new int[n] { 9, 10, 11, 12 }; // ������ ����� 2
            a[3] = new int[n] { 13, 14, 15, 16 }; // �������� ����� 3

            // ������ ������� ��� �����
            SwapMaxMinInEvenRows(a, k, n);

            // �������� ����������
            Assert::AreEqual(4, a[0][0]);  // �������� � ����� 0 ��� ���� �� ���� 0
            Assert::AreEqual(1, a[0][3]);  // ̳���� � ����� 0 ��� ���� �� ���� 3
            Assert::AreEqual(12, a[2][0]); // �������� � ����� 2 ��� ���� �� ���� 0
            Assert::AreEqual(9, a[2][3]);  // ̳���� � ����� 2 ��� ���� �� ���� 3

            // �������� ���'��
            for (int i = 0; i < k; i++) {
                delete[] a[i];
            }
            delete[] a;
        }
    };
}
