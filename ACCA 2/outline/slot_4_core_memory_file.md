# 📕 Slot 4: Core Engine, Memory Allocation & File Persistence
**PIC:** `[x] Chandra`  
**Tingkat Kesulitan:** **Tinggi (Fondasi Arsitektur Sistem, Pointer Heap & Rekursi)**  
**Topik Silabus:** Week 6 (*Recursion*), Week 8 (*Dynamic Memory Allocation*), Week 9 (*File Processing & Searching*)  

---

## 🎯 Deskripsi Tugas

Slot 4 merupakan tulang punggung (*backbone*) teknis dari aplikasi Toko Buku "Literasi Nusantara Jaya". Modul ini memastikan program berjalan dengan performa tinggi, efisien dalam penggunaan memori, bebas dari *memory leak*, dan tangguh dalam menangani berkas teks (*fault-tolerant*).

Tanggung jawab utama:
1. **Dynamic Memory Allocation (Heap Engine):** Mengelola alokasi memori dinamis untuk entitas `Book` dan `TransactionHistory` menggunakan `malloc`, `realloc` (strategi doubling capacity), dan `free`.
2. **Fault-Tolerant File Engine (Week 9):** Membaca dan menulis berkas `databuku.txt` dan `history.txt`. Menangani kondisi saat file **belum ada pada awal program dijalankan** (kondisi *cold start*) tanpa menyebabkan program crash.
3. **Implementasi Rekursi (Week 6 Compliance):**
   * **Rekursi Akumulator Omzet:** Menghitung total omzet kumulatif toko dari data histori penjualan.
   * **Recursive Linear Search:** Mencari data buku berdasarkan kode secara rekursif saat transaksi kasir.

---

## 🛠️ Kontrak Antarmuka Fungsi (Function Prototypes)

```c
// ==========================================
// 1. MANAJEMEN MEMORI DINAMIS (WEEK 8)
// ==========================================
void initBookArray(Book **books, int *capacity);
void ensureBookCapacity(Book **books, int *count, int *capacity);
void initHistoryArray(TransactionHistory **histories, int *capacity);
void ensureHistoryCapacity(TransactionHistory **histories, int *count, int *capacity);
void cleanupMemory(Book **books, TransactionHistory **histories);

// ==========================================
// 2. PEMROSESAN BERKAS / FILE I/O (WEEK 9)
// ==========================================
void loadBooksFromFile(const char *filename, Book **books, int *count, int *capacity);
void saveBooksToFile(const char *filename, const Book *books, int count);
void loadHistoryFromFile(const char *filename, TransactionHistory **histories, int *count, int *capacity);
void appendTransactionToFile(const char *filename, const TransactionHistory *trans);
void saveAllHistoryToFile(const char *filename, const TransactionHistory *histories, int count);

// ==========================================
// 3. FUNGSI REKURSIF (WEEK 6)
// ==========================================
// Menghitung total nilai omzet seluruh transaksi secara rekursif
double calculateTotalRevenueRecursive(const TransactionHistory *histories, int n);

// Mencari indeks buku berdasarkan kode secara rekursif
int searchBookByCodeRecursive(const Book *books, int currentIndex, int totalBooks, const char *targetCode);
```

---

## 📝 Spesifikasi Teknis Mendalam

### 1. Manajemen Memori Dinamis (Heap Engine)
* Kapasitas awal: `INITIAL_CAPACITY = 10`.
* Saat `count == capacity`, lakukan penggandaan kapasitas: `newCapacity = capacity * 2`.
* Gunakan pointer temporer saat memanggil `realloc` untuk mencegah memory leak jika alokasi gagal:
  ```c
  Book *temp = realloc(*books, newCapacity * sizeof(Book));
  if (!temp) {
      fprintf(stderr, "[FATAL] Gagal memperluas memori buku!\n");
      exit(EXIT_FAILURE);
  }
  *books = temp;
  *capacity = newCapacity;
  ```
* Pada Menu 6 (Exit), panggil `cleanupMemory()` untuk membebaskan seluruh pointer heap.

### 2. Format Serialisasi & Penanganan Berkas (File Engine)
* **Format Delimiter Berkas:** Gunakan karakter pipa (`|`) agar nama buku atau jenis yang mengandung spasi tidak terpotong:
  * `databuku.txt`: `Kode|Nama Buku|Kategori|Harga`
    ```text
    BK001|Dasar Pemrograman C|Komputer|85000.00
    BK002|Algoritma Lanjut|Komputer|115000.00
    ```
  * `history.txt`: `Kode|Qty|TotalPrice|PayType|Detail`
    ```text
    BK001|2|170000.00|1|170000.00
    BK002|1|115000.00|2|TRX-INV-9901
    ```
* **Penanganan First-Run (Wajib):**
  ```c
  FILE *fp = fopen(filename, "r");
  if (!fp) {
      // File belum ada di disk (Kondisi Run Pertama)
      // JANGAN CRASH! Cukup inisialisasi count = 0
      *count = 0;
      return;
  }
  ```
* **Penyimpanan Berkas (Menu 6 & Menu 7):**
  * `saveBooksToFile`: Menimpa berkas dengan mode `"w"`.
  * `appendTransactionToFile`: Menambahkan baris baru seketika dengan mode `"a"`.
  * `saveAllHistoryToFile`: Menulis ulang seluruh histori saat ada data yang dihapus (Menu 4).

### 3. Implementasi Rekursi (Week 6)
* **Akumulasi Finansial:**
  ```c
  double calculateTotalRevenueRecursive(const TransactionHistory *histories, int n) {
      if (n <= 0) return 0.0; // Base case
      return histories[n - 1].totalPrice + calculateTotalRevenueRecursive(histories, n - 1);
  }
  ```
* **Pencarian Kode Buku:**
  ```c
  int searchBookByCodeRecursive(const Book *books, int currentIndex, int totalBooks, const char *targetCode) {
      if (currentIndex >= totalBooks) return -1; // Base case: tidak ditemukan
      if (strcmp(books[currentIndex].bookCode, targetCode) == 0) return currentIndex; // Base case: ditemukan
      return searchBookByCodeRecursive(books, currentIndex + 1, totalBooks, targetCode); // Recursive step
  }
  ```

---

## ⚠️ Checklist Pengujian Mandiri
- [ ] Program dapat dijalankan dari folder bersih (tanpa berkas `databuku.txt` dan `history.txt`) tanpa crash.
- [ ] Berkas tersimpan dengan format delimiter yang konsisten dan dapat dimuat kembali pada sesi berikutnya.
- [ ] Fungsi rekursi akumulasi omzet memberikan nilai yang sama persis dengan penjumlahan iteratif.
- [ ] Pencarian rekursi dapat menemukan kode buku di awal, tengah, dan akhir array, serta mengembalikan `-1` jika tidak ada.
- [ ] Tidak ada memory leak yang terdeteksi saat program ditutup dengan Menu 6.
