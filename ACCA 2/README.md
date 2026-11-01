# 📚 ACCA 2 — Proyek Praktikum 2 (Team Assignment 2) - Week 10
**Mata Kuliah:** Algorithm and Programming (COMP6112036)  
**Kelas:** ACCA - LAB (Bobot Penilaian Praktikum: **60%**)  
**Dosen Pengampu / Aslab:** CS015 - ACHMAD ALIF NASRULLOH  
**Kelompok:** Group 1  
**Studi Kasus:** Digitalisasi Sistem Transaksi & Katalog Toko Buku "Literasi Nusantara Jaya"  

---

## 🎯 Ringkasan Capstone Project

Proyek Praktikum 2 ini merupakan **proyek akhir semester (Capstone Lab)** yang menguji pemahaman komprehensif mahasiswa atas seluruh materi perkuliahan Bahasa C dari **Week 1 hingga Week 10**.

Sistem yang dibangun adalah aplikasi konsol interaktif untuk toko buku skala menengah milik Bapak Anwar, mencakup pengelolaan katalog buku, pencatatan transaksi penjualan, persistensi data ke berkas teks, fitur pengurutan data ganda, hingga integrasi kecerdasan buatan (HAICOLA) untuk evaluasi dan debugging algoritma.

```
========================================================================================
                          TOKO BUKU LITERASI NUSANTARA JAYA
========================================================================================
  [Week 1-4] Control Flow & I/O    --> Navigasi Menu, Input Sanitization, Formatting
  [Week 5 & 8] Pointers & DMA      --> Dynamic Array (malloc/realloc/free), Address Passing
  [Week 6] Function & Recursion    --> Akumulasi Finansial Rekursif & Recursive Search
  [Week 7] Struct & Union          --> struct Book, struct Transaction, union PaymentDetail
  [Week 9] File & Searching        --> databuku.txt, history.txt, Fault-tolerant File Engine
  [Week 10] Sorting Algorithms     --> Bubble Sort (Nama Asc) & Selection Sort (Harga Desc)
========================================================================================
```

---

## 📊 Distribusi Menu & Bobot Penilaian (Total: 100% + Bonus 10%)

| Menu / Fitur | Deskripsi Fungsionalitas | Bobot | Topik Silabus Terkait |
| :---: | :--- | :---: | :--- |
| **Menu 1** | **Input Data Buku Baru**<br>Meminta Nama, Jenis, Harga; auto-generate kode `BK001`, `BK002`, dst. | **10%** | Week 2 (I/O), Week 5 (Array), Week 7 (Struct) |
| **Menu 2** | **View History Transaksi Penjualan**<br>Menampilkan seluruh histori transaksi penjualan secara tabular | **10%** | Week 2 (Formatting), Week 9 (File Processing) |
| **Menu 3** | **View Buku (Katalog Tersedia)**<br>Menampilkan seluruh katalog buku aktif yang terdaftar di sistem | **10%** | Week 2 (Formatting), Week 7 (Array of Struct) |
| **Menu 4** | **Delete History Penjualan**<br>Input index (validasi $1 \le \text{idx} \le N$), hapus data histori, array shifting | **10%** | Week 4 (Selection), Week 5 (Array Manipulation) |
| **Menu 5** | **Delete Buku**<br>Input index (validasi $1 \le \text{idx} \le N$), hapus buku dari katalog, array shifting | **10%** | Week 4 (Selection), Week 5 (Array Manipulation) |
| **Menu 6** | **Exit (Simpan Data & Keluar)**<br>Simpan seluruh data ke `databuku.txt` dan `history.txt`, safely exit | **10%** | Week 8 (Free Memory), Week 9 (File Commit) |
| **Menu 7** | **Input Transaksi Penjualan**<br>Input kode buku & qty, searching harga, hitung total, simpan ke riwayat | **15%** | Week 3 (Arithmetic), Week 6 (Search), Week 7 (Union) |
| **Menu 8** | **Sort Data Buku (Fitur Tambahan)**<br>Sub-menu (a) Bubble Sort Ascending (Nama), (b) Selection Sort Descending (Harga) | **15%** | Week 10 (Sorting Algorithms) |
| **HAICOLA** | **Konsultasi AI & Refleksi Etis**<br>Dokumentasi snippet 5–25 baris, prompt, jawaban AI, dan refleksi 4–6 kalimat | **10%** | HAICOLA Framework (Problem Solving & Debugging) |
| **BONUS** | **Bonus Nilai Tambahan Maksimal**<br>Prompt teknis relevan (+3%), pemahaman/analisis mendalam (+5%), perbaikan nyata (+2%) | **+10%** | Quality Assurance & Evaluasi Logika |

---

## ⚡ Invarian Teknis Penting (Harus Dipatuhi)

1. **File Awal Tidak Disediakan Dosen (First-Run Fault Tolerance):**
   * Berkas `databuku.txt` dan `history.txt` **tidak boleh diasumsikan sudah ada**.
   * Jika file tidak ditemukan saat `fopen(..., "r")`, program **dilarang crash / exit**. Program wajib menginisialisasi katalog/histori kosong dengan alokasi memori dinamis awal.
   * File akan otomatis dibuat dan ditulis saat transaksi pertama kali dicatat (Menu 7) atau saat user memilih keluar (Menu 6).
2. **Sanitasi Buffer Input (Anti Newline Trap):**
   * Dilarang mencampur `scanf("%d")` dengan `fgets()` secara ceroboh. Sisa karakter `\n` pada buffer `stdin` wajib dibersihkan menggunakan helper `clearInputBuffer()`.
3. **Manajemen Memori Dinamis (No Static Limit):**
   * Struktur data menggunakan pointer dinamis (`malloc` / `realloc`) dengan strategi doubling capacity.
   * Seluruh memori di heap wajib dibebaskan (`free()`) saat Menu 6 untuk mencegah memory leak.
4. **Validasi Indeks Hapus (1-Based Indexing):**
   * User memilih nomor urut 1 sampai $N$. Program wajib memvalidasi rentang input sebelum melakukan operasi geser (*shifting*) array.
5. **Implementasi Rekursi (Week 6 Compliance):**
   * Menyediakan fungsi rekursif untuk akumulasi total pendapatan omzet toko serta traversal pencarian buku.

---

## 👥 Alur Kerja Tim & Pembagian Tugas (Outline & Modular Starter-Kit)

Untuk memastikan kolaborasi berjalan terstruktur, adil, modular, dan **bebas dari git merge conflict**, proyek ini telah dipecah ke dalam modul file `.c` terpisah di folder [`src/`](src/) (tanpa file header `.h` yang membingungkan) dengan spesifikasi di [`outline/`](outline/):

* 📋 [**Panduan Utama Outline Tim (`outline/README.md`)**](outline/README.md)
* 📘 [**Slot 1: Manajemen Katalog Buku (Menu 1, 3, 5)**](outline/slot_1_katalog_buku.md) $\to$ [`src/slot_1_katalog.c`](src/slot_1_katalog.c)
* 📙 [**Slot 2: Transaksi Penjualan & Union (Menu 2, 4, 7)**](outline/slot_2_transaksi_union.md) $\to$ [`src/slot_2_transaksi.c`](src/slot_2_transaksi.c)
* 📗 [**Slot 3: Algoritma Sorting Data Buku (Menu 8a & 8b)**](outline/slot_3_sorting_buku.md) $\to$ [`src/slot_3_sorting.c`](src/slot_3_sorting.c) *(Fokus Algoritma & Mandiri)*
* 📕 [**Slot 4: Core Engine, File Persistence & Rekursi (Week 6, 9)**](outline/slot_4_core_memory_file.md) $\to$ [`src/slot_4_core.c`](src/slot_4_core.c) *(Lead Core)*
* 📓 [**Slot 5: Sistem Menu, Sanitasi Buffer & Integrasi HAICOLA**](outline/slot_5_menu_sanitasi_haicola.md) $\to$ [`src/slot_5_ui.c`](src/slot_5_ui.c)
* 🚀 **Master Entry Point:** [`src/main.c`](src/main.c) (Tinggal import fungsi dari file teman-teman)

---

## 🛠️ Panduan Kompilasi & Menjalankan Program

Program ditulis murni menggunakan **Standar C (C99 / C11)** tanpa dependensi pustaka luar pihak ketiga.

### 1. Kompilasi Langsung File `main.c` (GCC / MinGW):
Masuk ke folder `ACCA 2/` atau root repo, lalu cukup kompilasi file `main.c`:
```bash
# Kompilasi berkas utama (otomatis menyertakan file modul lainnya)
gcc -std=c99 -Wall -Wextra src/main.c -o algo_project.exe

# Menjalankan aplikasi
./algo_project.exe
```

### 2. Kompilasi via CLion / CMake:
Target `TugasACCA2` sudah otomatis terdaftar di `CMakeLists.txt`. Cukup pilih profil `TugasACCA2` lalu tekan tombol **Run (Shift + F10)**.


