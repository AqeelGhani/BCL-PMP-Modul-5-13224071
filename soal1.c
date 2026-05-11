/** EL2008 Praktikum Pemecahan Masalah dengan Pemrograman 2025/2026
 *   Modul               : 5 - Foundation of Algorithm
 *   Hari dan Tanggal    : Senin, 11 Mei 2026
 *   Nama (NIM)          : Muhammad Aqeel Ghani (13224071)
 *   Nama File           : soal1.c
 *   Deskripsi           : Membaca peta fasilitas bawah tanah dengan menghitung derajat setiap simpul, simpul maksimum, dan simpul terisolasi
 * 
 */
// Penambahan standard input output
#include <stdio.h>

// Prosedur Scan Input (Membaca Degree Tiap vertex dan mencari max vertex)
void ScanInput(int N, int degree[], int *idMaks){
    for(int i = 0; i<N; i++){
        // Inisialisasi degree tiap vertex
        degree[i] = 0;
        for(int j = 0; j<N; j++){
            int temp;
            // membaca adjency matrix
            scanf(" %d", &temp);
            // Menghitung degree vertex
            degree[i] += temp;
            
        }
        // Jika Degree vertex lebih besar dibanding vertex dengan degree sebelumnya akan di masukan indeks vertex yang baru
        *idMaks = (degree[*idMaks]< degree[i]) ? i : *idMaks;
    }
}

// Prosedur Print Degree
void PrintDegree(int N, int degree[]){
    // Print Degree Tiap Vertex
    for (int i = 0 ; i<N; i++) printf("DEGREE %d %d\n", i, degree[i]);
}

// Prosedure Print Max Vertex
void PrintMaxVertex(int idMaks){
    // Print indeks Max vertex
    printf("MAX_VERTEX %d\n", idMaks);
}

// Prosedur Print Isolated (Vertex tanpa degree)
void PrintIsolated(int N, int degree[]){
    // Jika terisolasi makas isolated = 1, jika tidak maka isolated = 0
    int isolated = 0;
    printf("ISOLATED");
    // Cari vertex yang terisolasi
    for (int i = 0 ; i<N; i++){
        if (degree[i]==0){
            printf(" %d", i);
            isolated = 1; // Ubah menjadi 1 jika vertex terisolasi
        }
    }
    // Jika tidak ada yang terisolasi, maka print NONE
    if (!isolated) printf(" NONE");
}



int main(void) {
    int N;
    scanf("%d", &N);
    int degree[N], idMaks = 0;

    ScanInput(N, degree, &idMaks);
    PrintDegree(N, degree);
    PrintMaxVertex(idMaks);
    PrintIsolated(N, degree);

    return 0;
}
