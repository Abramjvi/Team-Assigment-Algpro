/**
 * ========================================================================================
 * SLOT 5: SISTEM MENU, SANITASI BUFFER KEYBOARD & HAICOLA INTEGRATION
 * PIC: [Nama Rekan Pemegang Slot 5]
 *
 * TUGAS UTAMA ANDA:
 * 1. Menyediakan fungsi sanitasi buffer keyboard agar tidak terjadi "newline skipping bug"
 *    saat membaca string setelah membaca angka (clearInputBuffer, readStringSafe, dll).
 * 2. Menyediakan tampilan banner konsol dan navigasi menu utama.
 * 3. Menyusun laporan dokumentasi konsultasi & refleksi AI (HAICOLA Framework).
 * ========================================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Helper: Membersihkan sisa karakter di buffer stdin setelah scanf
 */
void clearInputBuffer(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

/**
 * Helper: Membaca string dengan aman menggunakan fgets dan memangkas newline di ujung
 */
void readStringSafe(char *dest, int maxLen) {
    if (fgets(dest, maxLen, stdin) != NULL) {
        size_t len = strlen(dest);
        if (len > 0 && dest[len - 1] == '\n') {
            dest[len - 1] = '\0';
        }
    }
}

/**
 * Helper: Membaca input bilangan bulat dengan validasi buffer aman
 */
int readIntegerSafe(const char *prompt) {
    int val;
    int status;
    while (1) {
        printf("%s", prompt);
        status = scanf("%d", &val);
        if (status == 1) {
            clearInputBuffer();
            return val;
        } else {
            printf("[ERROR] Input harus berupa bilangan bulat! Silakan coba lagi.\n");
            clearInputBuffer();
        }
    }
}

/**
 * Helper: Membaca input bilangan pecahan/desimal (double) dengan validasi aman
 */
double readDoubleSafe(const char *prompt) {
    double val;
    int status;
    while (1) {
        printf("%s", prompt);
        status = scanf("%lf", &val);
        if (status == 1) {
            clearInputBuffer();
            return val;
        } else {
            printf("[ERROR] Input harus berupa angka valid! Silakan coba lagi.\n");
            clearInputBuffer();
        }
    }
}

/**
 * Menampilkan Header Toko Buku
 */
void printBanner(void) {
    printf("\n");
    printf("======================================================================\n");
    printf("           SISTEM TRANSAKSI & MONITORING KATALOG BUKU                \n");
    printf("                TOKO \"LITERASI NUSANTARA JAYA\"                       \n");
    printf("======================================================================\n");
}

/**
 * Menampilkan 8 Pilihan Menu Utama
 */
void printMainMenu(void) {
    printBanner();
    printf("  [1] Input Data Buku Baru\n");
    printf("  [2] View History Transaksi Penjualan\n");
    printf("  [3] View Buku (Seluruh Data Buku yang Tersedia)\n");
    printf("  [4] Delete History (Hapus Histori Penjualan Tertentu)\n");
    printf("  [5] Delete Buku (Hapus Data Buku Tertentu)\n");
    printf("  [6] Exit (Simpan Data & Selesai)\n");
    printf("  [7] Input Transaksi Penjualan\n");
    printf("  [8] Sort Buku (Berdasarkan Nama & Harga)\n");
    printf("======================================================================\n");
}
