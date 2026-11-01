/**
 * ========================================================================================
 * SLOT 3: ALGORITMA SORTING DATA BUKU (MENU 8A & MENU 8B)
 * PIC: ABRAM JANUAR PUTRA WIBOWO (Fokus Algoritma & Modular)
*/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

void bubbleSortByNameAscending(Book books[], int count) {

    for (int i = 0; i < count - 1; i++) {

        bool swapped = false;

        for (int j = 0; j < count - 1 - i; j++) {

            // Membandingkan nama buku secara alfabetis
            if (strcmp(books[j].title, books[j + 1].title) > 0) {

                // Menukar posisi kedua buku
                Book temp = books[j];
                books[j] = books[j + 1];
                books[j + 1] = temp;

                swapped = true;
            }
        }

        // Berhenti jika tidak ada pertukaran
        if (!swapped) {
            break;
        }
    }
}



void selectionSortByPriceDescending(Book books[], int count) {

    for (int i = 0; i < count - 1; i++) {

        // Menentukan posisi harga tertinggi sementara
        int maxIdx = i;

        // Mencari harga tertinggi dari elemen berikutnya
        for (int j = i + 1; j < count; j++) {

            if (books[j].price > books[maxIdx].price) {
                maxIdx = j;
            }
        }

        // Menukar posisi jika ditemukan harga lebih tinggi
        if (maxIdx != i) {

            Book temp = books[i];
            books[i] = books[maxIdx];
            books[maxIdx] = temp;
        }
    }
}



void handleSortingMenu(Book books[], int bookCount) {

    // Validasi jika katalog kosong
    if (bookCount <= 0) {
        printf("\nTidak ada data buku untuk diurutkan.\n");
        return;
    }

    int choice;

    // Membuat array sementara untuk menjaga data asli
    Book *tempBooks = malloc(bookCount * sizeof(Book));

    if (tempBooks == NULL) {
        printf("\nGagal mengalokasikan memori untuk sorting.\n");
        return;
    }

    do {

        printf("\n=======================================================\n");
        printf("               SUB-MENU PENGURUTAN BUKU\n");
        printf("=======================================================\n");
        printf("[1] Urutkan berdasarkan Nama Buku (Ascending - Bubble Sort)\n");
        printf("[2] Urutkan berdasarkan Harga Buku (Descending - Selection Sort)\n");
        printf("[3] Kembali ke Menu Utama\n");
        printf("=======================================================\n");

        printf("Pilihan Anda: ");

        if (scanf("%d", &choice) != 1) {

            printf("\nInput tidak valid! Masukkan angka 1-3.\n");

            // Membersihkan input yang salah
            int ch;
            while ((ch = getchar()) != '\n' && ch != EOF);

            choice = 0;
            continue;
        }

        switch (choice) {

            case 1:

                // Salin katalog asli
                memcpy(tempBooks, books, bookCount * sizeof(Book));

                // Jalankan Bubble Sort
                bubbleSortByNameAscending(tempBooks, bookCount);

                printf("\nBuku berhasil diurutkan berdasarkan nama (A-Z).\n");

                printf("\n%-5s %-12s %-30s %-15s %15s\n",
                       "No", "Kode", "Nama Buku", "Kategori", "Harga");

                printf("-------------------------------------------------------------------------------\n");

                for (int i = 0; i < bookCount; i++) {
                    printf("%-5d %-12s %-30s %-15s Rp%12.2f\n",
                           i + 1,
                           tempBooks[i].bookCode,
                           tempBooks[i].title,
                           tempBooks[i].category,
                           tempBooks[i].price);
                }

                break;


            case 2:

                // Salin katalog asli
                memcpy(tempBooks, books, bookCount * sizeof(Book));

                // Jalankan Selection Sort
                selectionSortByPriceDescending(tempBooks, bookCount);

                printf("\nBuku berhasil diurutkan berdasarkan harga (tertinggi ke terendah).\n");

                printf("\n%-5s %-12s %-30s %-15s %15s\n",
                       "No", "Kode", "Nama Buku", "Kategori", "Harga");

                printf("-------------------------------------------------------------------------------\n");

                for (int i = 0; i < bookCount; i++) {
                    printf("%-5d %-12s %-30s %-15s Rp%12.2f\n",
                           i + 1,
                           tempBooks[i].bookCode,
                           tempBooks[i].title,
                           tempBooks[i].category,
                           tempBooks[i].price);
                }

                break;


            case 3:

                printf("\nKembali ke Menu Utama...\n");

                break;


            default:

                printf("\nPilihan tidak valid! Masukkan angka 1-3.\n");

                break;
        }

    } while (choice != 3);

    // Bebaskan memori array sementara
    free(tempBooks);
}

