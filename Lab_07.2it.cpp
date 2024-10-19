#include <iostream>
#include <iomanip>
#include <ctime>
using namespace std;

void Create(int** a, const int k, const int n, const int Low, const int High);
void Print(int** a, const int k, const int n);
void SwapMaxMinInEvenRows(int** a, const int k, const int n);

int main()
{
    srand((unsigned)time(NULL));
    int Low = 7;
    int High = 65;
    int k, n;
    cout << "Enter number of rows (k): "; cin >> k;
    cout << "Enter number of columns (n): "; cin >> n;

    int** a = new int* [k];
    for (int i = 0; i < k; i++)
        a[i] = new int[n];

    // ��������� �� ��������� ��������� �������
    Create(a, k, n, Low, High);
    cout << "Original matrix:" << endl;
    Print(a, k, n);

    // ����� ������������� �� ���������� �������� � ������ ������
    SwapMaxMinInEvenRows(a, k, n);
    cout << "Modified matrix:" << endl;
    Print(a, k, n);

    // �������� ���'��
    for (int i = 0; i < k; i++)
        delete[] a[i];
    delete[] a;

    return 0;
}

// ������� ��������� �������
void Create(int** a, const int k, const int n, const int Low, const int High)
{
    for (int i = 0; i < k; i++)
        for (int j = 0; j < n; j++)
            a[i][j] = Low + rand() % (High - Low + 1);
}

// ������� ��������� �������
void Print(int** a, const int k, const int n)
{
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < n; j++)
            cout << setw(4) << a[i][j];
        cout << endl;
    }
}

// ������� ����� ������������� � ���������� �������� � ������ ������
void SwapMaxMinInEvenRows(int** a, const int k, const int n)
{
    for (int i = 0; i < k; i += 2) { // ����� � ������� ��������� (0, 2, 4,...)
        int maxIndex = 0, minIndex = 0;
        for (int j = 1; j < n; j++) {
            if (a[i][j] > a[i][maxIndex])
                maxIndex = j;
            if (a[i][j] < a[i][minIndex])
                minIndex = j;
        }
        // ����� ������ ������������� � ���������� ��������
        swap(a[i][maxIndex], a[i][minIndex]);
    }
}
