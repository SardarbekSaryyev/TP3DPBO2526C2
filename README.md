TP3DPBO2526C2
# TP3DPBO2526C-Hospital

## Janji

Saya Sardarbek Saryyev dengan NIM 2521823 mengerjakan Tugas Praktikum 3 dalam mata kuliah Desain dan Pemrograman Berorientasi Objek untuk keberkahanNya maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.

## Tema

Sistem Manajemen Rumah Sakit sederhana: rumah sakit punya beberapa departemen, setiap departemen berisi dokter, perawat, dan pasien.

## Desain Diagram
 ![diagram](https://github.com/user-attachments/assets/fef93c06-e5d5-4c72-96cd-67b590bbcedf)

## Atribut dan Method

- **Person (abstract):** atribut `name`, `age`. Method abstrak `role()` dan `detail()`, serta `display()` untuk mencetak satu baris data.
- **Doctor:** atribut `specialty`. Mengisi `role()` dan `detail()`.
- **Nurse:** atribut `shift`. Mengisi `role()` dan `detail()`.
- **Patient:** atribut `diagnosis`, `room`. Mengisi `role()` dan `detail()`.
- **Department:** atribut `name` dan tiga array of object (`doctors`, `nurses`, `patients`). Method `addDoctor()`, `addNurse()`, `addPatient()`, `getName()`, `display()`.
- **Hospital:** atribut `name` dan array of object `departments`. Method `addDepartment()`, `findDepartment()`, `display()`.

## Penjelasan Desain

- **Hierarchical Inheritance:** `Doctor`, `Nurse`, dan `Patient` sama-sama mewarisi `Person`. Atribut umum dan `display()` ditulis sekali di `Person`. Polimorfisme lewat `role()` dan `detail()` membuat tiap subkelas mencetak keterangan yang berbeda.
- **Composition:** `Hospital` memiliki `Department`, dan `Department` memiliki `Doctor`, `Nurse`, `Patient`. Objek anak disimpan langsung di dalam induknya sehingga ikut hilang bersama induknya.
- **Array of Object:** koleksi memakai `vector` (C++), `list` (Python)

## Alur Program

1. Buat `Hospital` dan dua departemen (Kardiologi dan Anak), masing-masing diisi satu dokter, perawat, dan pasien.
2. Cetak semua data (sebelum ditambahkan).
3. Tambah data baru: satu pasien di Kardiologi, satu dokter di Anak, dan departemen Saraf lengkap.
4. Cetak semua data lagi (sesudah ditambahkan).

Ketiga bahasa menghasilkan keluaran yang sama.

## Cara Menjalankan

```bash
cd CPP/Program && g++ -std=c++17 main.cpp -o main && ./main
cd Python/Program && python3 main.py

## Dokumentasi

screenshot python - Folder Python / Folder Dokumentasi / python.png
screenshot cpp - Folder CPP / Folder Dokumentasi / cpp.png
Foto Diagram - diagram.png 
