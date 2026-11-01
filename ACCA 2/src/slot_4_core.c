/**
 * ========================================================================================
 * SLOT 4: CORE ENGINE, FILE PERSISTENCE & RECURSIVE ALGORITHMS
 * PIC: Chandra
 *
 * PANDUAN PENGERJAAN UNTUK ANGGOTA TIM:
 * Modul ini bertugas menangani pembacaan/penyimpanan berkas serta algoritma rekursif.
 * Silakan lengkapi logika fungsi di bawah ini sesuai petunjuk TODO masing-masing.
 * ========================================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * 1. MEMBACA DATA BUKU DARI FILE TEKS (WEEK 9: FILE PROCESSING)
 * 
 * TODO YANG HARUS ANDA KERJAKAN:
 * 1. Buka berkas dengan mode read: FILE *fp = fopen(filename, "r");
 * 2. Tangani kondisi cold-start (jika file belum ada / fp == NULL):
 *    Jangan crash! Cukup inisialisasi *count = 0 dan return.
 * 3. Jika file ada, baca baris demi baris menggunakan fgets().
 * 4. Parse setiap baris berformat pipe-delimited: Kode|Nama|Jenis|Harga
 *    (Tips: gunakan strtok atau sscanf).
 * 5. Masukkan ke dalam array books[*count] dan naikkan (*count)++.
 * 6. Tutup file dengan fclose(fp).
 */
void loadBooksFromFile(const char *filename, Book books[], int *count) {
    (void)filename;
    (void)books;
    *count = 0; // Default inisialisasi katalog kosong

    // TODO: Tulis kodingan pembacaan file databuku.txt di sini...
}

/**
 * 2. MENYIMPAN DATA BUKU KE FILE TEKS (MENU 6: EXIT)
 * 
 * TODO YANG HARUS ANDA KERJAKAN:
 * 1. Buka berkas dengan mode write: FILE *fp = fopen(filename, "w");
 * 2. Lakukan looping dari i = 0 sampai count - 1.
 * 3. Tulis data ke file dengan format: fprintf(fp, "%s|%s|%s|%.2f\n", ...);
 * 4. Tutup berkas dengan fclose(fp).
 */
void saveBooksToFile(const char *filename, const Book books[], int count) {
    (void)filename;
    (void)books;
    (void)count;

    // TODO: Tulis kodingan penulisan file databuku.txt di sini...
}

/**
 * 3. MEMBACA RIWAYAT TRANSAKSI DARI FILE TEKS (WEEK 9: FILE PROCESSING)
 * 
 * TODO YANG HARUS ANDA KERJAKAN:
 * 1. Buka berkas dengan mode read: FILE *fp = fopen(filename, "r");
 * 2. Tangani kondisi jika file belum ada (fp == NULL): set *count = 0 dan return.
 * 3. Baca baris demi baris dengan fgets().
 * 4. Parse baris berformat: Kode|Qty|TotalHarga|PayType|Detail
 * 5. Simpan ke array histories[*count] dan naikkan (*count)++.
 * 6. Tutup file dengan fclose(fp).
 */
void loadHistoryFromFile(const char *filename, TransactionHistory histories[], int *count) {
    (void)filename;
    (void)histories;
    *count = 0; // Default inisialisasi riwayat kosong

    // TODO: Tulis kodingan pembacaan file history.txt di sini...
}

/**
 * 4. MENAMBAHKAN SATU TRANSAKSI BARU KE FILE (MENU 7: APPEND MODE)
 * 
 * TODO YANG HARUS ANDA KERJAKAN:
 * 1. Buka berkas dengan mode append: FILE *fp = fopen(filename, "a");
 * 2. Tulis baris transaksi baru sesuai format.
 * 3. Tutup berkas dengan fclose(fp).
 */
void appendTransactionToFile(const char *filename, const TransactionHistory *trans) {
    (void)filename;
    (void)trans;

    // TODO: Tulis kodingan append transaksi ke history.txt di sini...
}

/**
 * 5. MENULIS ULANG SELURUH RIWAYAT TRANSAKSI (MENU 4 / MENU 6)
 * 
 * TODO YANG HARUS ANDA KERJAKAN:
 * 1. Buka berkas dengan mode write ("w") untuk menimpa file lama.
 * 2. Lakukan looping seluruh data di array histories dan tulis ke file.
 * 3. Tutup berkas dengan fclose(fp).
 */
void saveAllHistoryToFile(const char *filename, const TransactionHistory histories[], int count) {
    (void)filename;
    (void)histories;
    (void)count;

    // TODO: Tulis kodingan penulisan ulang file history.txt di sini...
}

/**
 * 6. FUNGSI REKURSIF: MENGHITUNG TOTAL OMZET PENJUALAN (WEEK 6)
 * 
 * TODO YANG HARUS ANDA KERJAKAN:
 * 1. Base Case: Jika tidak ada transaksi tersisa (n <= 0), kembalikan 0.0.
 * 2. Recursive Step: Jumlahkan totalPrice elemen terakhir (histories[n - 1].totalPrice)
 *    dengan pemanggilan rekursif untuk n - 1 elemen sebelumnya.
 */
double calculateTotalRevenueRecursive(const TransactionHistory histories[], int n) {
    (void)histories;
    (void)n;

    // Base Case default:
    if (n <= 0) {
        return 0.0;
    }

    // TODO: Tulis langkah rekursif di sini...
    return 0.0;
}

/**
 * 7. FUNGSI REKURSIF: MENCARI BUKU BERDASARKAN KODE (WEEK 6 & WEEK 9)
 * 
 * TODO YANG HARUS ANDA KERJAKAN:
 * 1. Base Case 1: Jika currentIndex >= totalBooks, buku tidak ditemukan -> return -1.
 * 2. Base Case 2: Jika strcmp(books[currentIndex].bookCode, targetCode) == 0 -> return currentIndex.
 * 3. Recursive Step: Periksa indeks berikutnya -> searchBookByCodeRecursive(books, currentIndex + 1, totalBooks, targetCode).
 */
int searchBookByCodeRecursive(const Book books[], int currentIndex, int totalBooks, const char *targetCode) {
    (void)books;
    (void)currentIndex;
    (void)totalBooks;
    (void)targetCode;

    // Base Case default:
    if (currentIndex >= totalBooks) {
        return -1;
    }

    // TODO: Tulis langkah perbandingan string dan panggilan rekursif di sini...
    return -1;
}
