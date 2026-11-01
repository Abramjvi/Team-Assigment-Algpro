/**
 * ========================================================================================
 * SLOT 3: ALGORITMA SORTING DATA BUKU (MENU 8A & MENU 8B)
 * PIC: [Nama Rekan Pemegang Slot 3] (Fokus Algoritma & Modular)
 *
 * PANDUAN PENGERJAAN UNTUK ANGGOTA TIM:
 * Modul ini bertugas menambahkan fitur pengurutan data buku toko "Literasi Nusantara Jaya".
 * Modul ini murni algoritma pengurutan array (self-contained) tanpa perlu file I/O rumit.
 * Silakan lengkapi logika fungsi di bawah ini sesuai petunjuk TODO masing-masing.
 * ========================================================================================
 */

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

/**
 * MENU 8A: BUBBLE SORT ASCENDING BERDASARKAN NAMA BUKU (A -> Z)
 * 
 * TODO YANG HARUS ANDA KERJAKAN:
 * 1. Gunakan nested loop Bubble Sort:
 *    for (int i = 0; i < count - 1; i++) {
 *        bool swapped = false;
 *        for (int j = 0; j < count - 1 - i; j++) { ... }
 *    }
 * 2. Bandingkan judul buku secara alfabetis:
 *    if (strcmp(books[j].title, books[j + 1].title) > 0) { ... }
 * 3. Jika lebih besar, tukar (swap) posisi kedua struct buku:
 *    Book temp = books[j];
 *    books[j] = books[j + 1];
 *    books[j + 1] = temp;
 * 4. Berikan flag 'swapped' agar jika dalam satu putaran tidak ada pertukaran,
 *    loop langsung berhenti (optimasi best-case O(n)).
 */
void bubbleSortByNameAscending(Book books[], int count) {
    (void)books;
    (void)count;
    printf("[TODO Slot 3] Algoritma Bubble Sort (Nama Ascending) belum diimplementasikan.\n");
    printf(">> Silakan buka file 'src/slot_3_sorting.c' dan tulis kodingan Bubble Sort di sini!\n");

    // TODO: Tulis kodingan Bubble Sort di sini...
}

/**
 * MENU 8B: SELECTION SORT DESCENDING BERDASARKAN HARGA BUKU (TERMAHAL -> TERMURAH)
 * 
 * TODO YANG HARUS ANDA KERJAKAN:
 * 1. Gunakan nested loop Selection Sort:
 *    for (int i = 0; i < count - 1; i++) {
 *        int maxIdx = i;
 *        for (int j = i + 1; j < count; j++) { ... }
 *    }
 * 2. Cari elemen dengan harga paling mahal:
 *    if (books[j].price > books[maxIdx].price) { maxIdx = j; }
 * 3. Lakukan pertukaran (swap) jika maxIdx != i:
 *    Book temp = books[i];
 *    books[i] = books[maxIdx];
 *    books[maxIdx] = temp;
 */
void selectionSortByPriceDescending(Book books[], int count) {
    (void)books;
    (void)count;
    printf("[TODO Slot 3] Algoritma Selection Sort (Harga Descending) belum diimplementasikan.\n");
    printf(">> Silakan buka file 'src/slot_3_sorting.c' dan tulis kodingan Selection Sort di sini!\n");

    // TODO: Tulis kodingan Selection Sort di sini...
}

/**
 * MENU 8: SUB-MENU PENGURUTAN BUKU INTERAKTIF
 * 
 * TODO YANG HARUS ANDA KERJAKAN:
 * 1. Validasi jika data buku masih kosong (bookCount <= 0).
 *    Tampilkan pesan wajib persis sesuai soal:
 *    "Tidak ada data buku untuk diurutkan."
 * 2. Tampilkan pilihan sub-menu:
 *    [1] Urutkan berdasarkan Nama Buku (Ascending - Bubble Sort)
 *    [2] Urutkan berdasarkan Harga Buku (Descending - Selection Sort)
 *    [3] Kembali ke Menu Utama
 * 3. Berdasarkan pilihan user, panggil fungsi sorting terkait lalu tampilkan hasilnya.
 *    (Tips: agar urutan asli tidak rusak, salin dulu array buku ke array sementara,
 *     lalu urutkan dan tampilkan array sementara tersebut).
 */
void handleSortingMenu(Book books[], int bookCount) {
    (void)books;
    // Validasi data kosong wajib sesuai soal
    if (bookCount <= 0) {
        printf("\nTidak ada data buku untuk diurutkan.\n");
        return;
    }

    printf("\n=======================================================\n");
    printf("               SUB-MENU PENGURUTAN BUKU\n");
    printf("=======================================================\n");
    printf("[TODO Slot 3] Sub-Menu Sorting belum diimplementasikan.\n");
    printf(">> Silakan buka file 'src/slot_3_sorting.c' dan tulis kodingan sub-menu di sini!\n");

    // TODO: Tulis kodingan sub-menu dan pemanggilan sorting di sini...
}
