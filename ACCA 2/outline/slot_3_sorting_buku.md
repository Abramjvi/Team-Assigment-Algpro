# 📗 Slot 3: Algoritma Sorting Data Buku (Menu 8a & 8b)
**PIC:** `[ ] Open Slot` *(Fokus Algoritma Murni & Modular)*  
**Tingkat Kesulitan:** **Ringan / Sangat Mandiri (Self-Contained Algorithm)**  
**Bobot Nilai Soal:** 15% (Menu 8: Fitur Praktikum Tambahan)  

---

## 🎯 Deskripsi Tugas

Slot 3 bertanggung jawab atas penambahan fitur pengurutan data buku pada toko "Literasi Nusantara Jaya" sesuai materi silabus **Week 10 (Sorting Algorithms)**:
1. **Menu 8a — Bubble Sort Ascending (Nama Buku):** Mengurutkan data buku secara alfabetis dari A ke Z.
2. **Menu 8b — Selection Sort Descending (Harga Buku):** Mengurutkan data buku dari harga yang paling mahal ke paling terjangkau.
3. **Sub-Menu Navigasi:** Menyediakan sub-menu interaktif dan opsi kembali ke menu utama.
4. **Validasi Data Kosong:** Jika katalog belum terisi, tampilkan pesan wajib: `"Tidak ada data buku untuk diurutkan."`

> [!TIP]
> **Kenapa Slot Ini Sangat Ramah & Mudah Dikerjakan?**
> Modul ini **100% independen (self-contained)**. Modul ini tidak berhubungan dengan alokasi memori dinamis rumit atau pembacaan file. Kamu hanya menerima array buku yang sudah ada, lalu mengurutkannya dengan logika algoritma murni. Jika anggota yang bertugas berhalangan, slot ini dapat di-takeover dengan sangat cepat tanpa mengganggu stabilitas modul lain.

---

## 🛠️ Kontrak Antarmuka Fungsi (Function Prototypes)

```c
// 1. Algoritma Bubble Sort: Urutkan Nama Buku (A -> Z)
void bubbleSortByNameAscending(Book *books, int bookCount);

// 2. Algoritma Selection Sort: Urutkan Harga Buku (Tertinggi -> Terendah)
void selectionSortByPriceDescending(Book *books, int bookCount);

// 3. Sub-menu pengatur sorting interaktif
void handleSortingMenu(Book *books, int bookCount);
```

---

## 📝 Spesifikasi Logika & Algoritma

### 1. Menu Navigasi Pengurutan (`handleSortingMenu`)
* Periksa terlebih dahulu:
  ```c
  if (bookCount <= 0) {
      printf("\n[PERINGATAN] Tidak ada data buku untuk diurutkan.\n");
      return;
  }
  ```
* Tampilkan pilihan sub-menu:
  ```text
  --------------------------------------------------
                 SUB-MENU PENGURUTAN BUKU
  --------------------------------------------------
  1. Urutkan berdasarkan Nama Buku (Ascending - Bubble Sort)
  2. Urutkan berdasarkan Harga Buku (Descending - Selection Sort)
  3. Kembali ke Menu Utama
  --------------------------------------------------
  Pilihan Anda [1-3]: 
  ```
* *Catatan Desain:* Agar urutan asli buku di katalog utama tidak rusak permanen, kamu dapat menyalin (*clone*) array buku ke array sementara (`Book temp[bookCount]`), mengurutkan array salinan tersebut, lalu menampilkannya ke layar.

### 2. Algoritma (a): Bubble Sort (Ascending by Title)
* **Aturan Komparasi:** Gunakan `strcmp(books[j].title, books[j+1].title) > 0`.
* **Optimasi Early-Exit:** Gunakan variabel penanda (*boolean flag*) `swapped`. Jika dalam satu putaran loop dalam tidak terjadi pertukaran sama sekali, hentikan iterasi (kompleksitas terbaik $O(n)$).
* **Pseudocode:**
  ```text
  Function bubbleSortByNameAscending(books, n):
      For i FROM 0 TO n - 2:
          swapped = false
          For j FROM 0 TO n - 2 - i:
              If strcmp(books[j].title, books[j+1].title) > 0:
                  Tukar books[j] dengan books[j+1]
                  swapped = true
          If swapped == false:
              Break // Data sudah terurut sempurna
  ```

### 3. Algoritma (b): Selection Sort (Descending by Price)
* **Aturan Komparasi:** Cari elemen dengan harga tertinggi (`price`) pada sisa subarray yang belum terurut.
* **Mekanisme Swap:** Lakukan pertukaran elemen hanya satu kali di akhir setiap putaran iterasi luar ($n-1$ kali penulisan memori).
* **Pseudocode:**
  ```text
  Function selectionSortByPriceDescending(books, n):
      For i FROM 0 TO n - 2:
          maxIndex = i
          For j FROM i + 1 TO n - 1:
              If books[j].price > books[maxIndex].price:
                  maxIndex = j
          If maxIndex != i:
              Tukar books[i] dengan books[maxIndex]
  ```

---

## ⚠️ Checklist Pengujian Mandiri
- [ ] Menampilkan pesan persis: `"Tidak ada data buku untuk diurutkan."` saat jumlah buku $= 0$.
- [ ] Pengurutan nama mengurutkan string secara alfabetis huruf besar/kecil dengan benar.
- [ ] Pengurutan harga menempatkan buku dengan harga paling mahal di urutan pertama.
- [ ] Setelah sorting selesai, hasil langsung dicetak rapi dalam bentuk tabel di layar.
- [ ] Navigasi sub-menu memiliki opsi untuk kembali ke menu utama tanpa error.
