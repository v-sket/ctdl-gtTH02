#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>

using namespace std;

//void NhapMang(int a[], int n);
void PhatSinhMang(int a[], int n);
void XuatMang(int a[], int n);
void Swap(int x, int y);
void InterchangeSort(int a[], int n);
void BubbleSort(int a[], int n);
void InsertionSort(int a[], int n);

int main()
{
    int n;
    printf("Nhap kich thuoc mang: ");
    scanf("%d", &n);
    int a[n];
    //NhapMang(a, n);
    PhatSinhMang(a, n);
    XuatMang(a, n);

    InterchangeSort(a, n);
    BubbleSort(a, n);
    InsertionSort(a, n);
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

void PhatSinhMang(int a[], int n){
    srand(time(NULL));
    for(int i = 0; i < n; i++)
        a[i] = rand()/10;
}

void XuatMang(int a[], int n){
    printf("\n");
    for(int i = 0; i < n; i++)
        printf("%d ", a[i]);
}

void Swap(int x, int y){
    int temp = x;
    x = y;
    y = temp;
}

void InterchangeSort(int a[], int n){
    clock_t start, end;
    start = clock();
    for(int i = 0; i < n-1; i++)
        for(int j = i + 1; j < n; j++)
            if(a[i] > a[j])
                Swap(a[i], a[j]);
    XuatMang(a, n);
    end = clock();
    double t = end - start;
    XuatMang(a, n);
    printf("\nThoi gian thuc hien: %f\n", t);
}

void BubbleSort(int a[], int n){
    clock_t start, end;
    start = clock();
    for(int i = 0; i < n-1; i++)
        for(int j = n-1; j > i; j--)
            if(a[j-1] > a[j])
                Swap(a[j-1], a[j]);
    XuatMang(a, n);
    end = clock();
    double t = end - start;
    XuatMang(a, n);
    printf("\nThoi gian thuc hien: %f\n", t);
}

void InsertionSort(int a[], int n){
    clock_t start, end;
    start = clock();
    for(int i = 0; i < n+1; i++){
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
    XuatMang(a, n);
    printf("\nThoi gian thuc hien: %f\n", t);
}
