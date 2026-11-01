#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Slot 4: File I/O & Rekursif
// PIC: Chandra

// Membaca databuku.txt. Jika file belum ada, set count = 0
void loadBooksFromFile(const char *filename, Book books[], int *count) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
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

        Book *b = &books[*count];

        // Format: KodeBuku|NamaBuku|JenisBuku|HargaBuku
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

// Simpan semua data buku ke file (dipanggil saat Exit)
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

// Membaca riwayat transaksi dari history.txt
void loadHistoryFromFile(const char *filename, TransactionHistory histories[], int *count) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
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

// Tambah 1 transaksi baru ke akhir history.txt (dipanggil saat transaksi selesai)
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

// Tulis ulang seluruh histori transaksi (setelah hapus riwayat / saat exit)
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

// Hitung total omzet transaksi secara rekursif
double calculateTotalRevenueRecursive(const TransactionHistory histories[], int n) {
    if (n <= 0) {
        return 0.0; // Base case: tidak ada transaksi
    }

    // Rekursif: transaksi ke-(n-1) + total sisa transaksi sebelumnya
    return histories[n - 1].totalPrice + calculateTotalRevenueRecursive(histories, n - 1);
}

// Cari indeks buku berdasarkan kode secara rekursif
int searchBookByCodeRecursive(const Book books[], int currentIndex, int totalBooks, const char *targetCode) {
    if (currentIndex >= totalBooks) {
        return -1; // Base case: buku tidak ditemukan
    }

    if (strcmp(books[currentIndex].bookCode, targetCode) == 0) {
        return currentIndex; // Base case: buku ketemu
    }

    // Rekursif: cek ke indeks berikutnya
    return searchBookByCodeRecursive(books, currentIndex + 1, totalBooks, targetCode);
}
