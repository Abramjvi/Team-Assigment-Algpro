/**
 * ========================================================================================
 * PROYEK PRAKTIKUM 2 (KELOMPOK) - WEEK 10
 * MATA KULIAH    : ALGORITHM AND PROGRAMMING (COMP6112036)
 * KELAS          : ACCA - LAB (BOBOT PENILAIAN: 60%)
 * DOSEN / ASLAB  : CS015 - ACHMAD ALIF NASRULLOH
 * KELOMPOK       : GROUP 1
 *
 * BERKAS UTAMA (MAIN ENTRY POINT):
 * Berkas ini bertindak sebagai orkestrator sistem. Setiap anggota kelompok mengerjakan
 * fiturnya masing-masing di file slot terkait tanpa perlu pusing memikirkan file .h!
 *
 * PEMBAGIAN FILE PENGERJAAN:
 * - slot_1_katalog.c   : Menu 1, 3, 5 (Input Buku, View Buku, Delete Buku)
 * - slot_2_transaksi.c : Menu 7, 2, 4 (Input Transaksi, View History, Delete History)
 * - slot_3_sorting.c   : Menu 8 (Bubble Sort & Selection Sort)
 * - slot_4_core.c      : Core Engine (Penyimpanan Berkas & Rekursi) -> PIC: Chandra
 * - slot_5_ui.c        : Tampilan Menu & Helper Sanitasi Keyboard
 * ========================================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_BOOKS 100
#define MAX_HISTORY 100
#define FILE_BOOKS "databuku.txt"
#define FILE_HISTORY "history.txt"

/* ========================================================================================
 * STRUKTUR DATA & UNION BERSAMA (WEEK 7)
 * ======================================================================================== */

/**
 * 1. Entitas Data Buku sesuai Tabel 1 Dokumen Soal
 */
typedef struct {
    char bookCode[16];      // Format otomatis: BK001, BK002, dst.
    char title[100];        // Nama/Judul buku (mendukung spasi)
    char category[50];      // Jenis buku (Komputer, Sains, Novel, dll.)
    double price;           // Harga buku dalam rupiah (desimal presisi)
} Book;

/**
 * 2. Enumerasi Metode Pembayaran
 */
typedef enum {
    PAYMENT_CASH = 1,
    PAYMENT_QRIS = 2
} PaymentType;

/**
 * 3. Union (Week 7): Menghemat memori dengan berbagi ruang memori yang sama
 */
typedef union {
    double cashReceived;        // Uang tunai diterima jika memilih Cash
    char transactionRef[25];    // Kode referensi transaksi jika memilih QRIS
} PaymentDetail;

/**
 * 4. Entitas Riwayat Transaksi Penjualan sesuai Tabel 2 Dokumen Soal
 */
typedef struct {
    char bookCode[16];          // Kode buku yang dibeli
    int quantity;               // Jumlah eksemplar terjual
    double totalPrice;          // Total harga = quantity * price
    PaymentType payType;        // Metode pembayaran yang dipilih
    PaymentDetail detail;       // Detail spesifik pembayaran via Union
} TransactionHistory;

/* ========================================================================================
 * IMPORT MODUL TUGAS ANGGOTA KELOMPOK (LANGSUNG DARI FILE .C)
 * ======================================================================================== */
#include "slot_5_ui.c"
#include "slot_4_core.c"
#include "slot_1_katalog.c"
#include "slot_2_transaksi.c"
#include "slot_3_sorting.c"

/* ========================================================================================
 * MAIN ENTRY POINT
 * ======================================================================================== */
int main(void) {
    Book books[MAX_BOOKS];
    int bookCount = 0;

    TransactionHistory histories[MAX_HISTORY];
    int historyCount = 0;

    // 1. Muat data dari berkas teks saat program dibuka (Slot 4 - Week 9)
    loadBooksFromFile(FILE_BOOKS, books, &bookCount);
    loadHistoryFromFile(FILE_HISTORY, histories, &historyCount);

    // 2. Loop Menu Utama
    int choice = 0;
    do {
        printMainMenu();
        choice = readIntegerSafe(">> Masukkan pilihan menu [1-8]: ");

        switch (choice) {
            case 1:
                // Menu 1: Input Data Buku Baru (Slot 1)
                handleInputBook(books, &bookCount);
                break;
            case 2:
                // Menu 2: View History Transaksi Penjualan (Slot 2)
                handleViewHistory(histories, historyCount);
                break;
            case 3:
                // Menu 3: View Seluruh Buku (Slot 1)
                handleViewBooks(books, bookCount);
                break;
            case 4:
                // Menu 4: Delete History Penjualan (Slot 2)
                handleDeleteHistory(histories, &historyCount);
                break;
            case 5:
                // Menu 5: Delete Buku (Slot 1)
                handleDeleteBook(books, &bookCount);
                break;
            case 6:
                // Menu 6: Exit & Simpan Perubahan ke File (Slot 4)
                printf("\nMenyimpan seluruh data ke '%s' dan '%s'...\n", FILE_BOOKS, FILE_HISTORY);
                saveBooksToFile(FILE_BOOKS, books, bookCount);
                saveAllHistoryToFile(FILE_HISTORY, histories, historyCount);
                printf("Semua data berhasil disimpan. Terima kasih telah menggunakan sistem ini!\n");
                break;
            case 7:
                // Menu 7: Input Transaksi Penjualan & Union (Slot 2)
                handleInputTransaction(books, bookCount, histories, &historyCount);
                break;
            case 8:
                // Menu 8: Sort Buku - Bubble & Selection Sort (Slot 3)
                handleSortingMenu(books, bookCount);
                break;
            default:
                printf("\n[PERINGATAN] Pilihan tidak valid! Silakan masukkan angka 1 sampai 8.\n");
                break;
        }

        if (choice != 6) {
            printf("\nTekan [Enter] untuk kembali ke menu utama...");
            clearInputBuffer();
        }

    } while (choice != 6);

    return 0;
}
