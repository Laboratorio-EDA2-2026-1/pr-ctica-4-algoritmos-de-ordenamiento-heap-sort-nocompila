/*
 * Objetivo: Completar las funciones Max-Heapify, Build-Max-Heap y Heap-Sort.
 * Entradas (stdin):
 *   n

 *   a1 a2 ... an

 * Salida (stdout):
 *   a1 a2 ... an  // en orden ascendente
 */

#include <stdio.h>
#include <stdlib.h>

/* PROTOTIPOS: NO CAMBIAR LAS FIRMAS */
void max_heapify(int a[], int n, int i);
void build_max_heap(int a[], int n);
void heap_sort(int a[], int n);


int main(void) {
    int n;printf("Ingresa el tamaño de tu arreglo:\n"); if (scanf("%d", &n) != 1 || n <= 0) return 0;
    int *a = (int*)malloc(sizeof(int) * n);
    if (!a) return 0;
    for (int i = 0; i < n; ++i) {
        printf("Ingresa tu elemento #%d del arreglo:\n", i + 1);
        scanf("%d", &a[i]);
    }

    heap_sort(a, n);
    printf("Tu arreglo ordenado es:\n");
    for (int i = 0; i < n; ++i) {
        if (i) putchar(' ');
        printf("%d", a[i]);
    }
    putchar(' ');

    free(a);
    return 0;
}

/* IMPLEMENTAR AQUÍ */
void max_heapify(int a[], int n, int i) {
    int left = 2*i + 1;
    int right = 2*i + 2; 
    int largest = i;

    if (left < n && a[left] > a[largest]) 
        largest = left;
    if (right < n && a[right] > a[largest]) 
        largest = right;

    if (largest != i) {
        int tmp = a[i];
        a[i] = a[largest];
        a[largest] = tmp;

       
        max_heapify(a, n, largest);
    }
}



void build_max_heap(int a[], int n) {
    for (int i = n/2 - 1; i >= 0; --i) {
        max_heapify(a, n, i);
    }
}


void heap_sort(int a[], int n) {
     build_max_heap(a, n);
    for (int end = n - 1; end > 0; --end) {
        
        int tmp = a[0];
        a[0] = a[end];
        a[end] = tmp;

        
        max_heapify(a, end, 0);
    }
}
