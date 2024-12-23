**Sistem Parkir Kampus**
**Deskripsi Program**
Program ini adalah sistem parkir berbasis bahasa C yang dirancang untuk mengelola parkir di lingkungan kampus UNS,
khususnya bagi dosen FATISDA dan mahasiswa Informatika kelas A 2024. 
Sistem ini membagi slot parkir menjadi tiga kategori utama:

Parkir mobil dosen (5 slot).
Parkir motor dosen (13 slot).
Parkir motor mahasiswa (20 slot).
Setiap slot parkir dikelola dengan status:

0: Kosong
1: Terisi

Program ini mempermudah pengguna dalam memilih dan mengelola parkir secara efisien.

Program kami memiliki 4 menu utama
1. **Masuk Parkir:**

Validasi ID pengguna (dosen atau mahasiswa) dari file dosen.txt dan mahasiswa.txt.
Menampilkan nama dan kategori pengguna setelah validasi
Meminta pengguna memasukkan jam masuk
Pengguna memilih slot parkir berdasarkan jenis kendaraan yang tersedia.

2. **Keluar Parkir:**
ID pengguna diverifikasi untuk mengosongkan slot parkir.
Slot parkir menjadi tersedia untuk pengguna lain.

3. **Cek status parkir terkini:**
Menampilkan status terkini dari semua slot parkir, termasuk ID pengguna yang terparkir di masing-masing slot.

4. **Keluar Program:**
Menutup program dengan aman.

**Cara Instalasi**
Pastikan Anda memiliki compiler C (misalnya GCC) di sistem Anda.
Unduh file UASKP_SistemParkir.c
Unduh file pendukung:
dosen.txt
mahasiswa.txt
Simpan semua file di direktori kerja yang sama.

**Struktur File**

dosen.txt:

Berisi data dosen yang valid.
Format: ID | Nama
Contoh:
Copy code
0030116204 | Drs. Bambang H, M.App.Sc, PhD
0030126608 | DR. Wiranto M.KOM., M.CS.

mahasiswa.txt:

Berisi data mahasiswa yang valid.
Format: ID | Nama
Contoh:
Copy code
L0124005 | Ayu Saniatus Sholihah
L0124001 | Adrian Alviano Susatyo

Catatan Penting
Pastikan file mahasiswa.txt dan dosen.txt tersedia dan diformat dengan benar.
Format input harus sesuai untuk memastikan validasi berhasil.
Jika file yang diperlukan tidak ditemukan, program akan menampilkan pesan kesalahan.

Informatika UNS 2024
L0124003	Aprilia Alfa Gusasti Ciptaningtyas 
L0124005 	Ayu Saniatus Sholihah 
L0124029 	Nurul Janati Ramadhani

