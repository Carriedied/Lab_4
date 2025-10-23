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
    vector<int> common_arr = { 3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5 };

    cout << "Исходный вектор: ";
    PrintVector(common_arr);

    int max_val, min_val;

    FindMinMax(common_arr, max_val, min_val);

    cout << "Максимальный элемент: " << max_val << endl;
    cout << "Минимальный элемент: " << min_val << endl;

    SwapMinMax(common_arr);

    cout << "После перестановки max и min: ";

    PrintVector(common_arr);

    cout << "Количество различных элементов и их частота:" << endl;
    CountDistinct(common_arr);

    cout << "\n=== Индивидуальные задания (без std::vector) ===" << endl;

    int n = 6;
    double* individual_arr = new double[n] {1.0, 0.5, -1.0, -2.0, 3.0, -0.3};

    cout << "Исходный массив: ";

    for (int i = 0; i < n; ++i) 
    {
        cout << individual_arr[i] << " ";
    }

    cout << endl;

    int min_idx = FindMinIndex(individual_arr, n);
    cout << "Номер (индекс) минимального элемента: " << min_idx << endl;

    double sum = SumBetweenNegatives(individual_arr, n);
    cout << "Сумма элементов между первым и вторым отрицательными: " << sum << endl;

    RearrangeArray(individual_arr, n);

    cout << "Преобразованный массив: ";

    for (int i = 0; i < n; ++i) 
    {
        cout << individual_arr[i] << " ";
    }

    cout << endl;

    delete[] individual_arr;

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

void FindMinMax(const vector<int>& arr, int& max_val, int& min_val) 
{
    if (arr.empty()) 
    {
        max_val = min_val = 0;

        return;
    }

    max_val = min_val = arr[0];

    for (int num : arr) 
    {
        if (num > max_val) 
            max_val = num;

        if (num < min_val) 
            min_val = num;
    }
}

void SwapMinMax(vector<int>& arr) 
{
    if (arr.empty()) 
        return;

    int max_val, min_val;

    FindMinMax(arr, max_val, min_val);

    int max_idx = -1, min_idx = -1;

    for (size_t i = 0; i < arr.size(); ++i) 
    {
        if (arr[i] == max_val && max_idx == -1) 
            max_idx = i;

        if (arr[i] == min_val)
            min_idx = i;
    }

    if (max_idx != -1 && min_idx != -1) 
    {
        swap(arr[max_idx], arr[min_idx]);
    }
}

void CountDistinct(const vector<int>& arr) 
{
    map<int, int> freq_map;

    for (int num : arr) 
    {
        freq_map[num]++;
    }

    for (const auto& pair : freq_map) 
    {
        cout << "Значение: " << pair.first << ", Частота: " << pair.second << endl;
    }
}

int FindMinIndex(const double* arr, int size) 
{
    if (size <= 0) 
        return -1;

    int min_idx = 0;

    for (int i = 1; i < size; ++i) 
    {
        if (arr[i] < arr[min_idx]) 
        {
            min_idx = i;
        }
    }

    return min_idx;
}

double SumBetweenNegatives(const double* arr, int size) 
{
    int first_neg_idx = -1;
    int second_neg_idx = -1;

    for (int i = 0; i < size; ++i) 
    {
        if (arr[i] < 0) 
        {
            if (first_neg_idx == -1) 
            {
                first_neg_idx = i;
            }
            else if (second_neg_idx == -1) 
            {
                second_neg_idx = i;
                break;
            }
        }
    }

    if (first_neg_idx == -1 || second_neg_idx == -1 || second_neg_idx - first_neg_idx <= 1) 
    {
        return 0.0;
    }

    double sum = 0.0;

    for (int i = first_neg_idx + 1; i < second_neg_idx; ++i) 
    {
        sum += arr[i];
    }

    return sum;
}

void RearrangeArray(double*& arr, int& size)
{
    double* temp = new double[size];
    int write_idx = 0;

    for (int i = 0; i < size; ++i)
    {
        if (abs(arr[i]) <= 1.0)
        {
            temp[write_idx++] = arr[i];
        }
    }

    for (int i = 0; i < size; ++i)
    {
        if (abs(arr[i]) > 1.0)
        {
            temp[write_idx++] = arr[i];
        }
    }

    delete[] arr;
    arr = temp;
}