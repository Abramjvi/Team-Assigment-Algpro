# 📋 PANDUAN OUTLINE & WORKFLOW PENGERJAAN TIM (ACCA 2)
**Mata Kuliah:** Algorithm and Programming (COMP6112036) — Kelas ACCA (Lab)  
**Tugas:** Proyek Praktikum 2 (Team Assignment 2) - Week 10  
**Topik Utama:** Pointers, Dynamic Memory Allocation, Recursion, Struct & Union, File Handling, dan Sorting Algorithms  

---

## 💡 Alur Pengerjaan untuk Anggota Tim

Halo teman-teman kelompok! Proyek Praktikum 2 (ACCA 2) ini adalah **penilaian terbesar semester ini (bobot 60%)**. Untuk memastikan tugas selesai tepat waktu, bernilai maksimal (A / 100 + Bonus 10), dan pengerjaannya adil tanpa ada yang saling tumpang-tindih (*merge conflict* / kode bentrok), folder `outline/` ini telah membagi pekerjaan menjadi **5 Slot Tugas Modular**.

> [!IMPORTANT]
> **Prinsip Utama Arsitektur Tim:**
> 1. **Modular & Loose Coupling:** Setiap slot memiliki batasan tanggung jawab yang jelas (*single responsibility*). Fungsi antarmuka (*interface contract*) sudah ditentukan parameternya sehingga masing-masing anggota bisa fokus menulis fungsinya tanpa perlu menunggu kode orang lain selesai.
> 2. **Sesuai Capaian Pembelajaran (LO 1, LO 2, LO 3):** Hindari library rumit luar yang belum diajarkan. Semua kode ditulis dalam **C murni** standar silabus Binus (Week 1 s.d. Week 10).
> 3. **Fault-Tolerant Invariant:** Berkas `databuku.txt` dan `history.txt` **tidak disediakan dari awal**. Program tidak boleh crash jika file tidak ada saat run pertama.
> 4. **Mitigasi Kolaborasi & Fleksibilitas:** Slot tugas telah dirancang modular dan mandiri sehingga jika ada anggota yang menghadapi kendala teknis atau butuh bantuan, rekan lain dapat saling mendukung tanpa mengganggu kestabilan arsitektur inti program.

---

## 🎯 Pembagian 5 Paket Slot Tugas

| Slot | Modul & Fitur | Menu Soal | File Spesifikasi Slot | Tingkat Kompleksitas | Status & PIC |
| :---: | :--- | :---: | :---| :---: | :---: |
| **Slot 1** | **Manajemen Katalog Buku**<br>Input buku baru (`BK001`), View buku tabular, Delete buku (index 1..n), Array shifting | Menu 1, 3, 5 | [`slot_1_katalog_buku.md`](./slot_1_katalog_buku.md) | Sedang (CRUD & Array) | `[ ] Open Slot` |
| **Slot 2** | **Transaksi Penjualan & Union**<br>Input transaksi, hitung total, View history, Delete history, Integrasi `union PaymentDetail` | Menu 2, 4, 7 | [`slot_2_transaksi_union.md`](./slot_2_transaksi_union.md) | Sedang (Logika Bisnis & Union) | `[ ] Open Slot` |
| **Slot 3** | **Algoritma Sorting Data Buku**<br>Bubble Sort Ascending (Nama) & Selection Sort Descending (Harga) + Validasi data kosong | Menu 8a & 8b | [`slot_3_sorting_buku.md`](./slot_3_sorting_buku.md) | **Ringan / Mandiri**<br>*(Self-Contained Algorithm)* | `[ ] Open Slot` |
| **Slot 4** | **Core Engine, Memory & File Processing**<br>Dynamic memory (`malloc`/`realloc`/`free`), Persistensi `databuku.txt` & `history.txt`, Rekursi Omzet & Search | Week 6, 8, 9, Menu 6 | [`slot_4_core_memory_file.md`](./slot_4_core_memory_file.md) | **Tinggi (Arsitektur Inti)** | `[x] Chandra` |
| **Slot 5** | **Sistem Menu, Sanitasi & HAICOLA**<br>Console UI Main Menu loop, Helper sanitasi buffer keyboard (`clearInputBuffer`), Dokumentasi Konsultasi & Refleksi AI | Menu Utama, HAICOLA | [`slot_5_menu_sanitasi_haicola.md`](./slot_5_menu_sanitasi_haicola.md) | Sedang (Integrasi & Laporan) | `[ ] Open Slot` |

---

## 🛡️ Alasan Pembagian Slot & Manajemen Modularitas Tugas

1. **Kenapa Slot 3 Dirancang Sangat Mandiri?**
   * Slot 3 hanya membutuhkan input berupa pointer array buku dan jumlah data: `(Book *arr, int n)`.
   * Fungsi sorting ini **sama sekali tidak menyentuh File I/O** dan fokus murni pada logika komparasi string (`strcmp`) dan pertukaran elemen (`swap`).
   * **Kemudahan Pengerjaan:** Modul ini sangat terisolasi sehingga anggota yang mengerjakannya bisa fokus 100% pada algoritma tanpa khawatir terganggu alur modul lain.
2. **Kenapa Slot 4 Dipegang Chandra?**
   * Mengatur fondasi memori heap, pembacaan file dengan penanganan graceful NULL saat file belum ada, dan penulisan kembali saat exit.
   * Mengimplementasikan fungsi rekursif (Week 6) agar capaian silabus Binus terpenuhi 100%.
3. **Bagaimana dengan Slot 1, 2, dan 5?**
   * Memiliki panduan baris per baris di file panduan masing-masing sehingga setiap anggota bisa langsung bekerja dengan mengisi fungsi yang telah disiapkan.

---

## 🤖 Panduan Integrasi AI (HAICOLA Framework)

Sesuai ketentuan dosen:
* Mahasiswa **wajib** berkonsultasi dengan AI untuk membedah minimal 1 topik teknis:
  1. *File Handling* (kenapa data tidak tersimpan atau penanganan file hilang).
  2. *Sorting* (logika komparasi string `strcmp` pada Bubble Sort).
  3. *Menu System / Input Buffer* (kenapa `fgets()` terlewat setelah `scanf()`).
  4. *Struct / Memory Allocation* (kenapa pointer data corrupt saat kapasitas penuh).
  5. *Logika Transaksi* (kalkulasi harga dan union).
* **Format Bukti Laporan yang Wajib Diserahkan:**
  1. Potongan kode (5–25 baris) sebelum diperbaiki.
  2. Teks prompt yang diajukan ke AI.
  3. Jawaban teknis dari AI.
  4. **Refleksi Pribadi (4–6 kalimat)** mengenai masalah, insight AI, perbaikan nyata yang dilakukan, dan pelajaran teknis yang didapat.

---

## 🚀 3 Langkah Memulai

1. **Pilih Slot:** Konfirmasi slot pilihanmu di grup WhatsApp kelompok.
2. **Baca Panduan Slot:** Buka file `slot_X_...md` yang sesuai di folder ini. Ikuti panduan pseudocode dan spesifikasi fungsi.
3. **Kompilasi & Uji:** Pastikan fungsimu dapat dikompilasi dengan standar `gcc -std=c99 -Wall` tanpa menghasilkan warning.
