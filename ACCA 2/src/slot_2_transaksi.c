/**
 * ========================================================================================
 * SLOT 2: TRANSAKSI PENJUALAN & IMPLEMENTASI UNION (MENU 7, MENU 2, MENU 4)
 * PIC: [Nama Rekan Pemegang Slot 2]
 *
 * PANDUAN PENGERJAAN UNTUK ANGGOTA TIM:
 * Modul ini menangani kasir dan pencatatan riwayat transaksi penjualan.
 * Silakan lengkapi logika fungsi di bawah ini sesuai petunjuk TODO masing-masing.
 * ========================================================================================
 */

#include <stdio.h>
#include <string.h>

/**
 * MENU 7: INPUT TRANSAKSI PENJUALAN
 * 
 * TODO YANG HARUS ANDA KERJAKAN:
 * 1. Cek apakah katalog buku kosong (bookCount == 0). Jika ya, batalkan transaksi.
 * 2. Minta input Kode Buku (contoh: BK001).
 * 3. Cari buku tersebut di katalog menggunakan fungsi pencarian:
 *    searchBookByCodeRecursive(books, 0, bookCount, targetCode).
 *    Jika tidak ditemukan (-1), cetak error dan batalkan transaksi.
 * 4. Minta input Jumlah Terjual (qty >= 1).
 * 5. Hitung total harga: total = (double)qty * selectedBook->price;
 * 6. Menerapkan Fitur UNION (Week 7):
 *    Tanyakan Metode Pembayaran:
 *      [1] Tunai (Cash): Minta nominal uang, simpan ke newTrans->detail.cashReceived, hitung kembalian.
 *      [2] Non-Tunai / QRIS: Minta kode ref transaksi, simpan ke newTrans->detail.transactionRef.
 * 7. Simpan transaksi ke riwayat: histories[*historyCount] dan (*historyCount)++;
 * 8. Simpan/append transaksi ke berkas 'history.txt' dengan memanggil:
 *    appendTransactionToFile("history.txt", newTrans);
 * 9. Tampilkan pesan sukses persis sesuai teks soal:
 *    "Transaksi berhasil dicatat."
 */
void handleInputTransaction(const Book books[], int bookCount, 
                            TransactionHistory histories[], int *historyCount) {
    (void)books;
    (void)bookCount;
    (void)histories;
    (void)historyCount;
    printf("\n=======================================================\n");
    printf("               INPUT TRANSAKSI PENJUALAN\n");
    printf("=======================================================\n");

    if (bookCount == 0) {
        printf("[ERROR] Belum ada data buku di katalog! Silakan input buku terlebih dahulu di Menu 1.\n");
        return;
    }

    printf("[TODO Slot 2] Fitur Menu 7 (Input Transaksi) belum diimplementasikan.\n");
    printf(">> Silakan buka file 'src/slot_2_transaksi.c' dan tulis kodingan kasirmu di sini!\n");

    // TODO: Tulis kodingan transaksi penjualan di sini...
}

/**
 * MENU 2: VIEW HISTORY TRANSAKSI PENJUALAN
 * 
 * TODO YANG HARUS ANDA KERJAKAN:
 * 1. Cek apakah history kosong (historyCount == 0). Jika kosong, tampilkan info:
 *    ">> [INFO] Belum ada transaksi penjualan yang tercatat pada sistem."
 * 2. Jika ada, cetak riwayat dalam bentuk tabel rapi:
 *    Tampilkan No, Kode Buku, Jumlah Terjual, Total Harga, dan Metode/Detail Bayar.
 * 3. Hitung dan tampilkan akumulasi total omzet toko menggunakan fungsi rekursif:
 *    double grandTotal = calculateTotalRevenueRecursive(histories, historyCount);
 */
void handleViewHistory(const TransactionHistory histories[], int historyCount) {
    (void)histories;
    (void)historyCount;
    printf("\n========================================================================================\n");
    printf("                        HISTORI TRANSAKSI PENJUALAN\n");
    printf("========================================================================================\n");

    if (historyCount == 0) {
        printf(">> [INFO] Belum ada transaksi penjualan yang tercatat pada sistem.\n");
        printf("========================================================================================\n");
        return;
    }

    printf("[TODO Slot 2] Fitur Menu 2 (View History) belum diimplementasikan.\n");
    printf(">> Silakan buka file 'src/slot_2_transaksi.c' dan tulis kodingan tabel riwayat di sini!\n");

    // TODO: Tulis kodingan cetak tabel histori dan omzet rekursif di sini...
}

/**
 * MENU 4: DELETE HISTORY (HAPUS HISTORI PENJUALAN TERTENTU)
 * 
 * TODO YANG HARUS ANDA KERJAKAN:
 * 1. Cek apakah data histori ada (*historyCount == 0). Jika kosong, cetak info kosong.
 * 2. Tampilkan terlebih dahulu riwayat (panggil handleViewHistory) agar user tahu nomornya.
 * 3. Minta input nomor indeks yang ingin dihapus (1 sampai *historyCount).
 * 4. Validasi indeks (1 <= idx <= *historyCount).
 * 5. Lakukan pergeseran array (Array Shifting) ke kiri dari indeks yang dihapus:
 *    int targetIdx = idx - 1;
 *    for (int i = targetIdx; i < *historyCount - 1; i++) {
 *        histories[i] = histories[i + 1];
 *    }
 *    (*historyCount)--;
 * 6. Tampilkan pesan sukses persis sesuai teks soal:
 *    "Data Successfully delete.."
 */
void handleDeleteHistory(TransactionHistory histories[], int *historyCount) {
    (void)histories;
    (void)historyCount;
    printf("\n=======================================================\n");
    printf("               HAPUS HISTORI TRANSAKSI\n");
    printf("=======================================================\n");

    if (*historyCount == 0) {
        printf(">> [INFO] Belum ada data histori untuk dihapus.\n");
        return;
    }

    printf("[TODO Slot 2] Fitur Menu 4 (Delete History) belum diimplementasikan.\n");
    printf(">> Silakan buka file 'src/slot_2_transaksi.c' dan tulis kodingan hapus riwayat di sini!\n");

    // TODO: Tulis kodingan hapus histori di sini...
}
