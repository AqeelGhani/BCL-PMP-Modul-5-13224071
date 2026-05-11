/** EL2008 Praktikum Pemecahan Masalah dengan Pemrograman 2025/2026
 *   Modul               : 5 - Foundation of Algorithm
 *   Hari dan Tanggal    : Senin, 11 Mei 2026
 *   Nama (NIM)          : Muhammad Aqeel Ghani (13224071)
 *   Nama File           : soal1.c
 *   Deskripsi           : Membaca peta fasilitas bawah tanah dengan menghitung derajat setiap simpul, simpul maksimum, dan simpul terisolasi
 * 
 */

#include <stdio.h>

void ScanInput(int N, int degree[], int *idMaks){
    for(int i = 0; i<N; i++){
        degree[i] = 0;
        for(int j = 0; j<N; j++){
            int temp;
            scanf(" %d", &temp);
            degree[i] += temp;
            
            *idMaks = (degree[*idMaks]< degree[i]) ? i : *idMaks;
        }
    }
}

void PrintDegree(int N, int degree[]){
    for (int i = 0 ; i<N; i++) printf("DEGREE %d %d\n", i, degree[i]);
}

void PrintMaxVertex(int idMaks){
    printf("MAX_VERTEX %d\n", idMaks);
}

void PrintIsolated(int N, int degree[]){
    int isolated = 1;
    printf("ISOLATED");
    for (int i = 0 ; i<N; i++){
        if (degree[i]==0){
            printf(" %d", i);
            isolated = 0;
        }
    }
    if (isolated) printf(" NONE");
}



int main(void) {
    int N;
    scanf("%d", &N);
    int degree[N], idMaks;

    ScanInput(N, degree, &idMaks);
    PrintDegree(N, degree);
    PrintMaxVertex(idMaks);
    PrintIsolated(N, degree);

    return 0;
}
