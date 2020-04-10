#include "Header.h"

//KLASA SORT
template <class T>
Sort<T>::Sort()
{
    arr = nullptr;
    size = 0;
    percent = 0.0;
}
template <class T>
Sort<T>::~Sort()
{
    delete[] arr;
    arr = nullptr;
}

void check_if_open(std::ofstream& file)
{
    if (!file.is_open())
    {
        std::cout << "File is not open!\nProgram closing...";
        std::cin.get();
        exit(1);
    }
}
template <class T>
void Sort<T>::randomInit()
{
    srand((unsigned int)time(NULL));
    for (int j = 0; j < this->size; j++)
    {
        arr[j] = rand() % 2000000 + 1;
    }
}

template <class T>
T Sort<T>::retVal(int nrIndeksu)
{
    return arr[nrIndeksu];
}

template <class T>
void Sort<T>::setAllArr()
{
    percent = 100;
}

template <class T>
void Sort<T>::initArr(int rozmiar)
{
    switch (rozmiar)
    {
    case 0: size = 10000; arr = new T[size];  break; //10k
    case 1: size = 50000; arr = new T[size];  break; //50k
    case 2: size = 100000; arr = new T[size];  break; //100k
    case 3: size = 500000; arr = new T[size];  break; //500k
    case 4: size = 1000000; arr = new T[size];  break; //1000k
    }
}
template <class T>
void Sort<T>::reversal(int rozmiar)
{
    int i = 0;
    int j = rozmiar - 1;
    T temp;
    for (i, j; i < j; i++, j--)
    {
        temp = arr[j];
        arr[j] = arr[i];
        arr[i] = temp;
    }
}

template <class T>
void Sort<T>::checkSort(int maxIndex)
{
    //std::cout << "NR " << 0 << " " << this->retVal(0) << std::endl;
    for (int i = 1; i < maxIndex + 1; i++)
    {
        //std::cout << "NR " << i << " " << this->retVal(i) << std::endl;
        if (arr[i] < arr[i - 1])
        {
            std::cout << "Blad!!!!" << std::endl;
            exit(7001);
        }
    }
}

template <class T>
T* Sort<T>::retArr()
{
    return arr;
}


//!QUICKSORT
template <class T>
void Sort<T>::QuickSort(int low, int high)
{
    int v = arr[(low + high) / 2];
    int i, j, x;
    i = low;
    j = high;
    do {
        while (arr[i] < v) i++;
        while (arr[j] > v) j--;
        if (i <= j)
        {
            x = arr[i];
            arr[i] = arr[j];
            arr[j] = x;
            i++;
            j--;
        }
    } while (i <= j);
    if (j > low)   QuickSort(low, j);
    if (i < high) QuickSort(i, high);
}
//!QS 2
template <class T>
void Sort<T>::Swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

template <class T>
int Sort<T>::Partition(T* data, int left, int right) {
    int x = data[right];
    int i = (left - 1);

    for (int j = left; j <= right - 1; ++j)
    {
        if (data[j] <= x)
        {
            ++i;
            Swap(data[i], data[j]);
        }
    }

    Swap(data[i + 1], data[right]);

    return (i + 1);
}

template <class T>
void Sort<T>::QuickSortIterative(T* data, int count) {
    int startIndex = 0;
    int endIndex = count - 1;
    int top = -1;
    int* stack = new int[count];

    stack[++top] = startIndex;
    stack[++top] = endIndex;

    while (top >= 0)
    {
        endIndex = stack[top--];
        startIndex = stack[top--];

        int p = Partition(data, startIndex, endIndex);

        if (p - 1 > startIndex)
        {
            stack[++top] = startIndex;
            stack[++top] = p - 1;
        }

        if (p + 1 < endIndex)
        {
            stack[++top] = p + 1;
            stack[++top] = endIndex;
        }
    }

    delete stack;
}

//!MERGESORT
template <class T>
void Sort<T>::MergeSort(int left, int right)
{
    if (left < right)
    {
        int m = left + (right - left) / 2;

        MergeSort(left, m);
        MergeSort(m + 1, right);

        merge(left, m, right);
    }
}
template <class T>
void Sort<T>::merge(int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    T* L = new int[n1];
    T* R = new int[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }

    delete[] L;
    delete[] R;
}

template <class T>
int Sort<T>::Min(int a, int b) {
    return a <= b ? a : b;
}

template <class T>
void Sort<T>::Merge(T* data, int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int* L = new int[n1];
    int* R = new int[n2];

    for (i = 0; i < n1; i++)
        L[i] = data[left + i];

    for (j = 0; j < n2; j++)
        R[j] = data[mid + 1 + j];

    i = 0;
    j = 0;
    k = left;

    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            data[k] = L[i];
            i++;
        }
        else
        {
            data[k] = R[j];
            j++;
        }

        k++;
    }

    while (i < n1)
    {
        data[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        data[k] = R[j];
        j++;
        k++;
    }

    delete L;
    delete R;
}

template <class T>
void Sort<T>::MergeSortIterative(T* data, int count) {
    int currentSize;
    int leftStart;

    for (currentSize = 1; currentSize <= count - 1; currentSize = 2 * currentSize)
    {
        for (leftStart = 0; leftStart < count - 1; leftStart += 2 * currentSize)
        {
            int mid = leftStart + currentSize - 1;
            int rightEnd = Min(leftStart + 2 * currentSize - 1, count - 1);

            Merge(data, leftStart, mid, rightEnd);
        }
    }
}
//!INTROSORT
template <class T>
void Sort<T>::Hybrid_Introspective_Sort(T* Array, int N)
{
    IntroSort(Array, N, (int)floor(2 * log(N) / M_LN2));
    Insertion_Sort(Array, N);
}

template <class T>
void Sort<T>::IntroSort(T* Array, int N, int M)
{
    int i;
    if (M <= 0)
    {
        Heap_Sort(Array, N);
        return;
    }
    i = Partition(Array, 0, N);
    if (i > 9)
        IntroSort(Array, i, M - 1);
    if (N - 1 - i > 9)
        IntroSort(Array + i + 1, N - 1 - i, M - 1);
}


template <class T>
void Sort<T>::MedianOfThree(T* Array, int& L, int& R)
{
    if (Array[++L - 1] > Array[--R])
        Exchange(Array, L - 1, R);
    if (Array[L - 1] > Array[R / 2])
        Exchange(Array, L - 1, R / 2);
    if (Array[R / 2] > Array[R])
        Exchange(Array, R / 2, R);
    Exchange(Array, R / 2, R - 1);
}

template <class T>
void Sort<T>::Exchange(T* Array, int i, int j)
{
    T temp;
    temp = Array[i];
    Array[i] = Array[j];
    Array[j] = temp;
}


template <class T>
void Sort<T>::Heap_Sort(T* Array, int N)
{
    int i;
    for (i = N / 2; i > 0; --i)
        Heapify(Array - 1, i, N);
    for (i = N - 1; i > 0; --i)
    {
        Exchange(Array, 0, i);
        Heapify(Array - 1, 1, i);
    }
}

template <class T>
void Sort<T>::Heapify(T* Array, int i, int N)
{
    int j;
    while (i <= N / 2)
    {
        j = 2 * i;
        if (j + 1 <= N && Array[j + 1] > Array[j])
            j = j + 1;
        if (Array[i] < Array[j])
            Exchange(Array, i, j);
        else break;
        i = j;
    }
}


template <class T>
void Sort<T>::Insertion_Sort(T* Array, int N)
{
    int i, j;
    T temp;
    for (i = 1; i < N; ++i)
    {
        temp = Array[i];
        for (j = i; j > 0 && temp < Array[j - 1]; --j)
            Array[j] = Array[j - 1];
        Array[j] = temp;
    }
}


template <class T>
int Sort<T>::PartitionI(T* data, int left, int right) {
    int pivot = data[right];
    int temp;
    int i = left;

    for (int j = left; j < right; ++j)
    {
        if (data[j] <= pivot)
        {
            temp = data[j];
            data[j] = data[i];
            data[i] = temp;
            i++;
        }
    }

    data[right] = data[i];
    data[i] = pivot;

    return i;
}

template <class T>
void Sort<T>::QuickSortRecursive(T* data, int left, int right) {
    if (left < right)
    {
        int q = PartitionI(data, left, right);
        QuickSortRecursive(data, left, q - 1);
        QuickSortRecursive(data, q + 1, right);
    }
}

template <class T>
void Sort<T>::MaxHeapify(T* data, int heapSize, int index) {
    int left = (index + 1) * 2 - 1;
    int right = (index + 1) * 2;
    int largest = 0;

    if (left < heapSize && data[left] > data[index])
        largest = left;
    else
        largest = index;

    if (right < heapSize && data[right] > data[largest])
        largest = right;

    if (largest != index)
    {
        int temp = data[index];
        data[index] = data[largest];
        data[largest] = temp;

        MaxHeapify(data, heapSize, largest);
    }
}

template <class T>
void Sort<T>::HeapSort(T* data, int count) {
    int heapSize = count;

    for (int p = (heapSize - 1) / 2; p >= 0; --p)
        MaxHeapify(data, heapSize, p);

    for (int i = count - 1; i > 0; --i)
    {
        int temp = data[i];
        data[i] = data[0];
        data[0] = temp;

        --heapSize;
        MaxHeapify(data, heapSize, 0);
    }
}

template <class T>
void Sort<T>::InsertionSort(T* data, int count) {
    for (int i = 1; i < count; ++i)
    {
        int j = i;

        while ((j > 0))
        {
            if (data[j - 1] > data[j])
            {
                data[j - 1] ^= data[j];
                data[j] ^= data[j - 1];
                data[j - 1] ^= data[j];

                --j;
            }
            else
            {
                break;
            }
        }
    }
}

template <class T>
void Sort<T>::IntroSort(T* data, int count) {
    int partitionSize = Partition(data, 0, count - 1);

    if (partitionSize < 16)
    {
        InsertionSort(data, count);
    }
    else if (partitionSize > (2 * log(count)))
    {
        HeapSort(data, count);
    }
    else
    {
        QuickSortRecursive(data, 0, count - 1);
    }
}

//#####################################################################################################################################################





template class Sort<int>;
