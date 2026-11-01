/**
 * ========================================================================================
 * SLOT 4: CORE ENGINE, FILE PERSISTENCE & RECURSIVE ALGORITHMS
 * PIC: Chandra
 *
 * TUGAS UTAMA:
 * 1. Membaca dan menyimpan berkas teks "databuku.txt" dan "history.txt".
 *    - Tangani kondisi "cold-start" (saat file belum ada di komputer, program tidak boleh crash).
 * 2. Implementasi Rekursi (Week 6 Compliance):
 *    - calculateTotalRevenueRecursive (menghitung omzet riwayat transaksi secara rekursif).
 *    - searchBookByCodeRecursive (mencari kode buku di katalog secara rekursif).
 * ========================================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Membaca data buku dari file teks saat program pertama kali dibuka
 */
void loadBooksFromFile(const char *filename, Book books[], int *count) {
    FILE *fp = fopen(filename, "r");
    if (!fp) {
        // Cold start: file belum ada, inisialisasi jumlah buku = 0 secara aman
        *count = 0;
        return;
    }

    char line[256];
    while (fgets(line, sizeof(line), fp)) {
        line[strcspn(line, "\r\n")] = '\0';
        if (strlen(line) == 0) continue;

        Book *b = &books[*count];
        char *token = strtok(line, "|");
        if (token) strncpy(b->bookCode, token, sizeof(b->bookCode) - 1);

        token = strtok(NULL, "|");
        if (token) strncpy(b->title, token, sizeof(b->title) - 1);

        token = strtok(NULL, "|");
        if (token) strncpy(b->category, token, sizeof(b->category) - 1);

        token = strtok(NULL, "|");
        if (token) b->price = atof(token);

        (*count)++;
    }
    fclose(fp);
}

/**
 * Menyimpan seluruh data buku ke file teks saat Menu 6 (Exit)
 */
void saveBooksToFile(const char *filename, const Book books[], int count) {
    FILE *fp = fopen(filename, "w");
    if (!fp) {
        fprintf(stderr, "[ERROR] Gagal membuka '%s' untuk penulisan berkas!\n", filename);
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
 * Membaca data riwayat transaksi saat program dibuka
 */
void loadHistoryFromFile(const char *filename, TransactionHistory histories[], int *count) {
    FILE *fp = fopen(filename, "r");
    if (!fp) {
        *count = 0;
        return;
    }

    char line[256];
    while (fgets(line, sizeof(line), fp)) {
        line[strcspn(line, "\r\n")] = '\0';
        if (strlen(line) == 0) continue;

        TransactionHistory *h = &histories[*count];
        char *token = strtok(line, "|");
        if (token) strncpy(h->bookCode, token, sizeof(h->bookCode) - 1);

        token = strtok(NULL, "|");
        if (token) h->quantity = atoi(token);

        token = strtok(NULL, "|");
        if (token) h->totalPrice = atof(token);

        token = strtok(NULL, "|");
        if (token) h->payType = (PaymentType)atoi(token);

        token = strtok(NULL, "|");
        if (token) {
            if (h->payType == PAYMENT_CASH) {
                h->detail.cashReceived = atof(token);
            } else {
                strncpy(h->detail.transactionRef, token, sizeof(h->detail.transactionRef) - 1);
            }
        }

        (*count)++;
    }
    fclose(fp);
}

/**
 * Menambahkan 1 baris transaksi baru ke berkas history.txt (Menu 7)
 */
void appendTransactionToFile(const char *filename, const TransactionHistory *trans) {
    FILE *fp = fopen(filename, "a");
    if (!fp) {
        fprintf(stderr, "[ERROR] Gagal membuka '%s' untuk pencatatan transaksi!\n", filename);
        return;
    }
    if (trans->payType == PAYMENT_CASH) {
        fprintf(fp, "%s|%d|%.2f|%d|%.2f\n", 
                trans->bookCode, trans->quantity, trans->totalPrice, 
                trans->payType, trans->detail.cashReceived);
    } else {
        fprintf(fp, "%s|%d|%.2f|%d|%s\n", 
                trans->bookCode, trans->quantity, trans->totalPrice, 
                trans->payType, trans->detail.transactionRef);
    }
    fclose(fp);
}

/**
 * Menulis ulang seluruh data riwayat saat ada history yang dihapus (Menu 4) atau Exit (Menu 6)
 */
void saveAllHistoryToFile(const char *filename, const TransactionHistory histories[], int count) {
    FILE *fp = fopen(filename, "w");
    if (!fp) {
        fprintf(stderr, "[ERROR] Gagal membuka '%s' untuk penulisan riwayat!\n", filename);
        return;
    }
    for (int i = 0; i < count; i++) {
        if (histories[i].payType == PAYMENT_CASH) {
            fprintf(fp, "%s|%d|%.2f|%d|%.2f\n", 
                    histories[i].bookCode, histories[i].quantity, histories[i].totalPrice, 
                    histories[i].payType, histories[i].detail.cashReceived);
        } else {
            fprintf(fp, "%s|%d|%.2f|%d|%s\n", 
                    histories[i].bookCode, histories[i].quantity, histories[i].totalPrice, 
                    histories[i].payType, histories[i].detail.transactionRef);
        }
    }
    fclose(fp);
}

/**
 * FUNGSI REKURSIF (WEEK 6): Menghitung Akumulasi Total Omzet Penjualan Toko
 */
double calculateTotalRevenueRecursive(const TransactionHistory histories[], int n) {
    // Base Case: jika tidak ada transaksi tersisa
    if (n <= 0) {
        return 0.0;
    }
    // Recursive Step: total transaksi terakhir + total transaksi elemen sebelumnya
    return histories[n - 1].totalPrice + calculateTotalRevenueRecursive(histories, n - 1);
}

/**
 * FUNGSI REKURSIF (WEEK 6): Mencari Buku Berdasarkan Kode Buku
 */
int searchBookByCodeRecursive(const Book books[], int currentIndex, int totalBooks, const char *targetCode) {
    // Base Case 1: pencarian selesai tanpa menemukan kecocokan
    if (currentIndex >= totalBooks) {
        return -1;
    }
    // Base Case 2: kode buku ditemukan
    if (strcmp(books[currentIndex].bookCode, targetCode) == 0) {
        return currentIndex;
    }
    // Recursive Step: periksa elemen berikutnya
    return searchBookByCodeRecursive(books, currentIndex + 1, totalBooks, targetCode);
}
