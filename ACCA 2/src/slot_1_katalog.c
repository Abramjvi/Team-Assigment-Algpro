/**
 * ========================================================================================
 * SLOT 1: MANAJEMEN KATALOG BUKU (MENU 1, MENU 3, MENU 5)
 * PIC: [Nama Rekan Pemegang Slot 1]
 *
 * PANDUAN PENGERJAAN UNTUK ANGGOTA TIM:
 * Modul ini bertugas mengelola katalog buku toko "Literasi Nusantara Jaya".
 * Silakan lengkapi logika fungsi di bawah ini sesuai petunjuk TODO masing-masing.
 * ========================================================================================
 */

#include <stdio.h>
#include <string.h>

/**
 * MENU 1: INPUT DATA BUKU BARU
 * 
 * TODO YANG HARUS ANDA KERJAKAN:
 * 1. Auto-generate kode buku dengan format: BK001, BK002, dst.
 *    Rumus: int nextId = *bookCount + 1;
 *           snprintf(books[*bookCount].bookCode, sizeof(books[*bookCount].bookCode), "BK%03d", nextId);
 *    Tampilkan kode otomatis tersebut ke layar console.
 * 2. Minta input Nama Buku (gunakan readStringSafe agar aman dari spasi).
 * 3. Minta input Jenis Buku (Komputer, Novel, Sains, dll).
 * 4. Minta input Harga Buku (validasi harga harus > 0 menggunakan loop).
 * 5. Tambahkan jumlah buku: (*bookCount)++;
 * 6. Tampilkan pesan sukses: "Data buku berhasil ditambahkan ke sistem!"
 */
void handleInputBook(Book books[], int *bookCount) {
    (void)books;
    (void)bookCount;
    printf("\n=======================================================\n");
    printf("               INPUT DATA BUKU BARU\n");
    printf("=======================================================\n");

    printf("[TODO Slot 1] Fitur Menu 1 (Input Buku) belum diimplementasikan.\n");
    printf(">> Silakan buka file 'src/slot_1_katalog.c' dan tulis kodinganmu di sini!\n");

    // TODO: Tulis kodinganmu di sini...
}

/**
 * MENU 3: VIEW BUKU (SELURUH DATA BUKU YANG TERSEDIA)
 * 
 * TODO YANG HARUS ANDA KERJAKAN:
 * 1. Cek apakah daftar buku masih kosong (bookCount == 0).
 *    Jika kosong, tampilkan pesan:
 *    ">> [INFO] Belum ada data buku yang terdaftar di sistem."
 * 2. Jika ada, cetak dalam bentuk tabel rapi menggunakan printf dengan format specifier lebar:
 *    Contoh format: | %-3d | %-10s | %-30s | %-15s | Rp %10.2f |
 * 3. Tampilkan total koleksi buku di bagian bawah tabel.
 */
void handleViewBooks(const Book books[], int bookCount) {
    (void)books;
    (void)bookCount;
    printf("\n========================================================================================\n");
    printf("                       DAFTAR BUKU TOKO LITERASI NUSANTARA JAYA\n");
    printf("========================================================================================\n");

    if (bookCount == 0) {
        printf(">> [INFO] Belum ada data buku yang terdaftar di sistem.\n");
        printf("========================================================================================\n");
        return;
    }

    printf("[TODO Slot 1] Fitur Menu 3 (View Buku) belum diimplementasikan.\n");
    printf(">> Silakan buka file 'src/slot_1_katalog.c' dan tulis kodingan tabelmu di sini!\n");

    // TODO: Tulis kodingan looping cetak tabel buku di sini...
}

/**
 * MENU 5: DELETE BUKU (HAPUS DATA BUKU TERTENTU)
 * 
 * TODO YANG HARUS ANDA KERJAKAN:
 * 1. Cek apakah ada data buku (*bookCount == 0). Jika kosong, tampilkan pesan info.
 * 2. Tampilkan terlebih dahulu daftar buku (panggil handleViewBooks) agar user tahu nomor indeksnya.
 * 3. Minta input nomor indeks yang ingin dihapus (1 sampai *bookCount).
 * 4. Validasi indeks: pastikan input berada di antara 1 dan *bookCount.
 *    Jika salah, cetak error dan batalkan.
 * 5. Lakukan pergeseran array (Array Shifting) ke kiri dari indeks yang dihapus:
 *    int targetIdx = idx - 1;
 *    for (int i = targetIdx; i < *bookCount - 1; i++) {
 *        books[i] = books[i + 1];
 *    }
 *    (*bookCount)--;
 * 6. Tampilkan pesan sukses persis sesuai teks soal:
 *    "Data Successfully delete.."
 */
void handleDeleteBook(Book books[], int *bookCount) {
    (void)books;
    (void)bookCount;
    printf("\n=======================================================\n");
    printf("                  HAPUS DATA BUKU\n");
    printf("=======================================================\n");

    if (*bookCount == 0) {
        printf(">> [INFO] Belum ada data buku untuk dihapus.\n");
        return;
    }

    printf("[TODO Slot 1] Fitur Menu 5 (Delete Buku) belum diimplementasikan.\n");
    printf(">> Silakan buka file 'src/slot_1_katalog.c' dan tulis kodingan array shifting di sini!\n");

    // TODO: Tulis kodingan hapus buku di sini...
}
