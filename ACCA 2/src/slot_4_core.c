/**
 * ========================================================================================
 * SLOT 4: CORE ENGINE, FILE PERSISTENCE & RECURSIVE ALGORITHMS
 * PIC: Chandra
 *
 * MATA KULIAH    : ALGORITHM AND PROGRAMMING (COMP6112036)
 * TOPIK SILABUS  : WEEK 6 (FUNCTION & RECURSION), WEEK 9 (FILE PROCESSING & SEARCHING)
 *
 * CAKUPAN TUGAS SLOT 4:
 * 1. Manajemen Berkas Teks (File I/O):
 *    - loadBooksFromFile     : Membaca berkas "databuku.txt" dengan penanganan cold-start.
 *    - saveBooksToFile       : Menyimpan seluruh katalog buku ke "databuku.txt" saat Exit (Menu 6).
 *    - loadHistoryFromFile   : Membaca berkas "history.txt" saat program dijalankan.
 *    - appendTransactionToFile : Menambahkan transaksi baru seketika ke "history.txt" (Menu 7).
 *    - saveAllHistoryToFile  : Menulis ulang riwayat saat ada histori dihapus (Menu 4 / Menu 6).
 *
 * 2. Algoritma Rekursif (Week 6 Compliance):
 *    - calculateTotalRevenueRecursive : Akumulasi omzet kumulatif toko via call stack.
 *    - searchBookByCodeRecursive      : Pencarian kode buku rekursif untuk verifikasi transaksi.
 * ========================================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * ========================================================================================
 * 1. PEMROSESAN BERKAS KATALOG BUKU ("databuku.txt")
 * ========================================================================================
 */

/**
 * Membaca data buku dari berkas teks saat program pertama kali dibuka.
 * 
 * INVARIAN PENTING DARI DOSEN:
 * Berkas databuku.txt TIDAK DISEDIAKAN di awal oleh dosen.
 * Jika file belum ada (fp == NULL), program TIDAK BOLEH CRASH/EXIT!
 * Cukup inisialisasi jumlah buku (*count = 0) dan kembali secara aman (graceful fallback).
 */
void loadBooksFromFile(const char *filename, Book books[], int *count) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        // Kondisi Cold-Start: File belum terbentuk di disk
        *count = 0;
        return;
    }

    char line[256];
    *count = 0;

    // Membaca baris demi baris hingga akhir berkas (EOF)
    while (fgets(line, sizeof(line), fp) != NULL) {
        // Hapus karakter newline '\r' atau '\n' di ujung baris
        line[strcspn(line, "\r\n")] = '\0';

        // Lewati baris kosong
        if (strlen(line) == 0) {
            continue;
        }

        Book *b = &books[*count];

        // Format baris: KodeBuku|NamaBuku|JenisBuku|HargaBuku
        // Menggunakan strtok dengan delimiter pipa '|' agar nama ber-spasi tetap utuh
        char *token = strtok(line, "|");
        if (token != NULL) {
            strncpy(b->bookCode, token, sizeof(b->bookCode) - 1);
            b->bookCode[sizeof(b->bookCode) - 1] = '\0';
        }

        token = strtok(NULL, "|");
        if (token != NULL) {
            strncpy(b->title, token, sizeof(b->title) - 1);
            b->title[sizeof(b->title) - 1] = '\0';
        }

        token = strtok(NULL, "|");
        if (token != NULL) {
            strncpy(b->category, token, sizeof(b->category) - 1);
            b->category[sizeof(b->category) - 1] = '\0';
        }

        token = strtok(NULL, "|");
        if (token != NULL) {
            b->price = atof(token);
        }

        (*count)++;
    }

    fclose(fp);
}

/**
 * Menyimpan seluruh data buku aktif ke berkas teks saat Menu 6 (Exit).
 * Format penyimpanan seragam menggunakan delimiter pipa '|'.
 */
void saveBooksToFile(const char *filename, const Book books[], int count) {
    FILE *fp = fopen(filename, "w");
    if (fp == NULL) {
        fprintf(stderr, "[ERROR] Gagal membuka '%s' untuk penulisan data buku!\n", filename);
        return;
    }

    for (int i = 0; i < count; i++) {
        fprintf(fp, "%s|%s|%s|%.2f\n", 
                books[i].bookCode, 
                books[i].title, 
                books[i].category, 
                books[i].price);
    }

    fclose(fp);
}

/**
 * ========================================================================================
 * 2. PEMROSESAN BERKAS RIWAYAT PENJUALAN ("history.txt")
 * ========================================================================================
 */

/**
 * Membaca seluruh histori transaksi penjualan dari berkas teks.
 * Jika file belum ada, inisialisasi histori kosong (*count = 0).
 */
void loadHistoryFromFile(const char *filename, TransactionHistory histories[], int *count) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        // Kondisi Cold-Start: File history.txt belum ada
        *count = 0;
        return;
    }

    char line[256];
    *count = 0;

    while (fgets(line, sizeof(line), fp) != NULL) {
        line[strcspn(line, "\r\n")] = '\0';
        if (strlen(line) == 0) {
            continue;
        }

        TransactionHistory *h = &histories[*count];

        // Format: KodeBuku|JumlahTerjual|TotalHarga|MetodeBayar|Detail
        char *token = strtok(line, "|");
        if (token != NULL) {
            strncpy(h->bookCode, token, sizeof(h->bookCode) - 1);
            h->bookCode[sizeof(h->bookCode) - 1] = '\0';
        }

        token = strtok(NULL, "|");
        if (token != NULL) {
            h->quantity = atoi(token);
        }

        token = strtok(NULL, "|");
        if (token != NULL) {
            h->totalPrice = atof(token);
        }

        token = strtok(NULL, "|");
        if (token != NULL) {
            h->payType = (PaymentType)atoi(token);
        } else {
            h->payType = PAYMENT_CASH;
        }

        token = strtok(NULL, "|");
        if (token != NULL) {
            if (h->payType == PAYMENT_CASH) {
                h->detail.cashReceived = atof(token);
            } else {
                strncpy(h->detail.transactionRef, token, sizeof(h->detail.transactionRef) - 1);
                h->detail.transactionRef[sizeof(h->detail.transactionRef) - 1] = '\0';
            }
        }

        (*count)++;
    }

    fclose(fp);
}

/**
 * Menambahkan (append) satu data transaksi baru ke berkas history.txt.
 * Dipanggil langsung saat transaksi berhasil dicatat di Menu 7.
 */
void appendTransactionToFile(const char *filename, const TransactionHistory *trans) {
    FILE *fp = fopen(filename, "a");
    if (fp == NULL) {
        fprintf(stderr, "[ERROR] Gagal membuka '%s' untuk pencatatan transaksi!\n", filename);
        return;
    }

    if (trans->payType == PAYMENT_CASH) {
        fprintf(fp, "%s|%d|%.2f|%d|%.2f\n", 
                trans->bookCode, 
                trans->quantity, 
                trans->totalPrice, 
                trans->payType, 
                trans->detail.cashReceived);
    } else {
        fprintf(fp, "%s|%d|%.2f|%d|%s\n", 
                trans->bookCode, 
                trans->quantity, 
                trans->totalPrice, 
                trans->payType, 
                trans->detail.transactionRef);
    }

    fclose(fp);
}

/**
 * Menulis ulang seluruh data riwayat penjualan ke berkas history.txt.
 * Dipanggil saat terjadi penghapusan histori (Menu 4) atau saat keluar aplikasi (Menu 6).
 */
void saveAllHistoryToFile(const char *filename, const TransactionHistory histories[], int count) {
    FILE *fp = fopen(filename, "w");
    if (fp == NULL) {
        fprintf(stderr, "[ERROR] Gagal membuka '%s' untuk penulisan ulang riwayat!\n", filename);
        return;
    }

    for (int i = 0; i < count; i++) {
        if (histories[i].payType == PAYMENT_CASH) {
            fprintf(fp, "%s|%d|%.2f|%d|%.2f\n", 
                    histories[i].bookCode, 
                    histories[i].quantity, 
                    histories[i].totalPrice, 
                    histories[i].payType, 
                    histories[i].detail.cashReceived);
        } else {
            fprintf(fp, "%s|%d|%.2f|%d|%s\n", 
                    histories[i].bookCode, 
                    histories[i].quantity, 
                    histories[i].totalPrice, 
                    histories[i].payType, 
                    histories[i].detail.transactionRef);
        }
    }

    fclose(fp);
}

/**
 * ========================================================================================
 * 3. ALGORITMA REKURSIF (WEEK 6: FUNCTION & RECURSION)
 * ========================================================================================
 */

/**
 * Menghitung akumulasi total omzet pendapatan seluruh riwayat transaksi secara rekursif.
 * 
 * KONSEP REKURSI:
 * - Base Case    : Jika n <= 0 (tidak ada data transaksi tersisa), kembalikan 0.0.
 * - Recursive Step: Ambil total harga transaksi elemen terakhir (histories[n - 1].totalPrice),
 *                   lalu jumlahkan dengan hasil pemanggilan fungsi ini untuk n - 1 elemen sebelumnya.
 */
double calculateTotalRevenueRecursive(const TransactionHistory histories[], int n) {
    // Base Case: Tidak ada elemen untuk dihitung
    if (n <= 0) {
        return 0.0;
    }

    // Recursive Call: Elemen ke-(n-1) + akumulasi (n-1) elemen pertama
    return histories[n - 1].totalPrice + calculateTotalRevenueRecursive(histories, n - 1);
}

/**
 * Mencari indeks buku di dalam katalog berdasarkan kode buku secara rekursif.
 * Dipanggil oleh Slot 2 saat kasir memasukkan kode buku untuk mendapatkan harga satuan.
 * 
 * KONSEP REKURSI:
 * - Base Case 1   : currentIndex >= totalBooks -> traversal selesai dan kode tidak ditemukan (-1).
 * - Base Case 2   : strcmp cocok (0) -> kode buku ditemukan, kembalikan currentIndex.
 * - Recursive Step : Lanjut periksa indeks berikutnya (currentIndex + 1).
 */
int searchBookByCodeRecursive(const Book books[], int currentIndex, int totalBooks, const char *targetCode) {
    // Base Case 1: Traversal mencapai batas tanpa menemukan kecocokan
    if (currentIndex >= totalBooks) {
        return -1;
    }

    // Base Case 2: Kode buku cocok ditemukan
    if (strcmp(books[currentIndex].bookCode, targetCode) == 0) {
        return currentIndex;
    }

    // Recursive Step: Cek elemen berikutnya
    return searchBookByCodeRecursive(books, currentIndex + 1, totalBooks, targetCode);
}
