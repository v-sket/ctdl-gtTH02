#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>

using namespace std;

//void NhapMang(int a[], int n);
void PhatSinhMang(int a[], int n);
void XuatMang(int a[], int n);
void Swap(int &x, int &y);
void InterchangeSort(int a[], int n);
void BubbleSort(int a[], int n);
void InsertionSort(int a[], int n);
void SelectionSort(int a[], int n);
void QuickSort(int a[], int left, int right);
int main()
{
    int n;
    printf("Nhap kich thuoc mang: ");
    scanf("%d", &n);
    int a[n];
    //NhapMang(a, n);
    PhatSinhMang(a, n);
    printf("Mang:");
    XuatMang(a, n);
    printf("\n");

    int *b = a;
    XuatMang(b, n);
    InterchangeSort(b, n);

    int *c = a;
    XuatMang(c, n);
    BubbleSort(c, n);

    int *d = a;
    XuatMang(d, n);
    InsertionSort(d, n);

    int *e = a;
    XuatMang(e, n);
    SelectionSort(e, n);

    int *f = a;
    XuatMang(f, n);
    clock_t start, end;
    start = clock();
    QuickSort(f, 0, n-1);
    end = clock();
    double t = end - start;
    printf("Quick Sort:");
    XuatMang(f, n);
    printf("\nThoi gian thuc hien: %f\n\n", t);
    return 0;
}

/*
void NhapMang(int a[], int n){
    for(int i = 0; i < n; i++){
        printf("a[%d] = ", i);
        scanf("%d", &a[i]);
    }
}
*/

//1. Nhap mang ngau nhien
void PhatSinhMang(int a[], int n){
    srand(time(NULL));
    for(int i = 0; i < n; i++)
        a[i] = rand()/1000;
}

//2. Xuat mang ngau nhien
void XuatMang(int a[], int n){
    printf("\n");
    for(int i = 0; i < n; i++)
        printf("%d ", a[i]);
}

void Swap(int &x, int &y){
    int temp = x;
    x = y;
    y = temp;
}

//3. Interchange Sort
void InterchangeSort(int a[], int n){
    clock_t start, end;
    start = clock();
    for(int i = 0; i < n-1; i++)
        for(int j = i + 1; j < n; j++)
            if(a[i] > a[j])
                Swap(a[i], a[j]);
    end = clock();
    double t = end - start;
    printf("\nInterchange Sort:");
    XuatMang(a, n);
    printf("\nThoi gian thuc hien: %f\n\n", t);
}

//4. Bubble Sort
void BubbleSort(int a[], int n){
    clock_t start, end;
    start = clock();
    for(int i = 0; i < n-1; i++)
        for(int j = n-1; j > i; j--)
            if(a[j-1] > a[j])
                Swap(a[j-1], a[j]);
    end = clock();
    double t = end - start;
    printf("Bubble Sort:");
    XuatMang(a, n);
    printf("\nThoi gian thuc hien: %f\n\n", t);
}

//5. Insertion Sort
void InsertionSort(int a[], int n){
    clock_t start, end;
    start = clock();
    for(int i = 0; i < n; i++){
        int x = a[i];
        int pos = i - 1;
        while(pos >= 0 && a[pos] > x){
            a[pos + 1] = a[pos];
            pos--;
        }
        a[pos + 1] = x;
    }
    end = clock();
    double t = end - start;
    printf("Insertion Sort:");
    XuatMang(a, n);
    printf("\nThoi gian thuc hien: %f\n\n", t);
}

//6. Selection Sort
void SelectionSort(int a[], int n){
    clock_t start, end;
    start = clock();
    int min;
    for(int i = 0; i < n -1; i++){
        min = i;
        for(int j = i + 1; j < n; j++)
            if(a[j] < a[min])
                    min = j;
        if(min != i)
            Swap(a[min], a[i]);
    }
    end = clock();
    double t = end - start;
    printf("Selection Sort:");
    XuatMang(a, n);
    printf("\nThoi gian thuc hien: %f\n\n", t);
}

//7. QuickSort
void QuickSort(int a[], int left, int right){
    int i, j, x;
    x = a[(left + right)/2];
    i = left;
    j = right;
    do{
        while(a[i] < x)
            i++;
        while(a[j] > x)
            j--;
        if(i <= j){
            Swap(a[i], a[j]);
            i++;
            j--;
        }
    }while(i <= j);
    if(left < j)
        QuickSort(a, left, j);
    if(i < right)
        QuickSort(a, i, right);
}

