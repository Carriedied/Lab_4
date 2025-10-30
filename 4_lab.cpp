#include <iostream>
#include <vector>
#include <map>
#include <cmath>

using namespace std;

void PrintVector(const vector<int>& vec);
void FindMinMax(const vector<int>& arr, int& max_val, int& min_val);
void SwapMinMax(vector<int>& arr);
void CountDistinct(const vector<int>& arr);
int FindMinIndex(const double* arr, int size);
double SumBetweenNegatives(const double* arr, int size);
void RearrangeArray(double*& arr, int& size);

int main() 
{
    setlocale(LC_ALL, "russian");

    cout << "=== Общие задания (std::vector) ===" << endl;
    vector<int> commonArr = { 3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5 };

    cout << "Исходный вектор: ";
    PrintVector(commonArr);

    int maxVal, minVal;

    FindMinMax(commonArr, maxVal, minVal);

    cout << "Максимальный элемент: " << maxVal << endl;
    cout << "Минимальный элемент: " << minVal << endl;

    SwapMinMax(commonArr);

    cout << "После перестановки max и min: ";

    PrintVector(commonArr);

    cout << "Количество различных элементов и их частота:" << endl;
    CountDistinct(commonArr);

    cout << "\n=== Индивидуальные задания (без std::vector) ===" << endl;

    int n = 6;
    double* individualArr = new double[n] {1.0, 0.5, -1.0, -2.0, 3.0, -0.3};

    cout << "Исходный массив: ";

    for (int i = 0; i < n; ++i) 
    {
        cout << individualArr[i] << " ";
    }

    cout << endl;

    int minIdx = FindMinIndex(individualArr, n);
    cout << "Номер (индекс) минимального элемента: " << minIdx << endl;

    double sum = SumBetweenNegatives(individualArr, n);
    cout << "Сумма элементов между первым и вторым отрицательными: " << sum << endl;

    RearrangeArray(individualArr, n);

    cout << "Преобразованный массив: ";

    for (int i = 0; i < n; ++i) 
    {
        cout << individualArr[i] << " ";
    }

    cout << endl;

    delete[] individualArr;

    return 0;
}

void PrintVector(const vector<int>& vec) 
{
    for (int num : vec) 
    {
        cout << num << " ";
    }

    cout << endl;
}

void FindMinMax(const vector<int>& arr, int& maxVal, int& minVal) 
{
    if (arr.empty()) 
    {
        maxVal = minVal = 0;

        return;
    }

    maxVal = minVal = arr[0];

    for (int num : arr) 
    {
        if (num > maxVal) 
            maxVal = num;

        if (num < minVal) 
            minVal = num;
    }
}

void SwapMinMax(vector<int>& arr) 
{
    if (arr.empty()) 
        return;

    int maxVal, minVal;

    FindMinMax(arr, maxVal, minVal);

    int maxIdx = -1, minIdx = -1;

    for (size_t i = 0; i < arr.size(); ++i) 
    {
        if (arr[i] == maxVal && maxIdx == -1) 
            maxIdx = i;

        if (arr[i] == minVal)
            minIdx = i;
    }

    if (maxIdx != -1 && minIdx != -1) 
    {
        swap(arr[maxIdx], arr[minIdx]);
    }
}

void CountDistinct(const vector<int>& arr) 
{
    map<int, int> freqMap;

    for (int num : arr) 
    {
        freqMap[num]++;
    }

    for (const auto& pair : freqMap) 
    {
        cout << "Значение: " << pair.first << ", Частота: " << pair.second << endl;
    }
}

int FindMinIndex(const double* arr, int size) 
{
    if (size <= 0) 
        return -1;

    int minIdx = 0;

    for (int i = 1; i < size; ++i) 
    {
        if (arr[i] < arr[minIdx]) 
        {
            minIdx = i;
        }
    }

    return minIdx;
}

double SumBetweenNegatives(const double* arr, int size) 
{
    int firstNegIdx = -1;
    int secondNegIdx = -1;

    for (int i = 0; i < size; ++i) 
    {
        if (arr[i] < 0) 
        {
            if (firstNegIdx == -1) 
            {
                firstNegIdx = i;
            }
            else if (secondNegIdx == -1) 
            {
                secondNegIdx = i;
                break;
            }
        }
    }

    if (firstNegIdx == -1 || secondNegIdx == -1 || secondNegIdx - firstNegIdx <= 1) 
    {
        return 0.0;
    }

    double sum = 0.0;

    for (int i = firstNegIdx + 1; i < secondNegIdx; ++i) 
    {
        sum += arr[i];
    }

    return sum;
}

void RearrangeArray(double*& arr, int& size)
{
    double* temp = new double[size];
    int writeIdx = 0;

    for (int i = 0; i < size; ++i)
    {
        if (abs(arr[i]) <= 1.0)
        {
            temp[writeIdx++] = arr[i];
        }
    }

    for (int i = 0; i < size; ++i)
    {
        if (abs(arr[i]) > 1.0)
        {
            temp[writeIdx++] = arr[i];
        }
    }

    delete[] arr;
    arr = temp;
}
