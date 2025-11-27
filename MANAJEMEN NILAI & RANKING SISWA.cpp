#include <iostream>
#include <vector>
#include <string>
#include <algorithm> // Untuk fungsi swap()

using namespace std;

// =================================================================
// DEKLARASI FUNGSI MODUL (Prototypes)
// =================================================================

// Fungsi untuk mengelola input data siswa (Menu 1)
void inputData(vector<int>& id_siswa, vector<string>& nama_siswa,
               vector<float>& nilai_tugas, vector<float>& nilai_uts,
               vector<float>& nilai_uas, vector<float>& rata_rata,
               vector<char>& kategori, int& jumlah_siswa);

// Fungsi untuk menampilkan seluruh data (Menu 2)
void tampilkanData(const vector<int>& id_siswa, const vector<string>& nama_siswa,
                    const vector<float>& rata_rata, const vector<char>& kategori,
                    int jumlah_siswa);

// Fungsi untuk mengurutkan data (Menu 3)
void bubbleSort(vector<int>& id_siswa, vector<string>& nama_siswa,
                vector<float>& nilai_tugas, vector<float>& nilai_uts,
                vector<float>& nilai_uas, vector<float>& rata_rata,
                vector<char>& kategori, int jumlah_siswa);

// Fungsi untuk mencari data siswa (Menu 4)
void cariSiswa(const vector<int>& id_siswa, const vector<string>& nama_siswa,
               const vector<float>& rata_rata, const vector<char>& kategori,
               int jumlah_siswa);

// Fungsi untuk menampilkan nilai tertinggi dan terendah (Menu 5)
void nilaiTertinggiTerendah(const vector<string>& nama_siswa,
                            const vector<float>& rata_rata, int jumlah_siswa);


// =================================================================
// FUNGSI UTAMA (MAIN MENU)
// Struktur kontrol utama berada pada fungsi main()
// =================================================================

int main() {
    // a. Deklarasi Variabel Global / Vector
    vector<int> id_siswa;
    vector<string> nama_siswa;
    vector<float> nilai_tugas, nilai_uts, nilai_uas, rata_rata;
    vector<char> kategori;

    int jumlah_siswa = 0;
    int pilihan_menu;

    cout << "=== SISTEM MANAJEMEN NILAI & RANKING SISWA ===\n";

    do {
        // c. Main Menu
        cout << "\nMENU:\n";
        cout << "1. Input Data Siswa\n";
        cout << "2. Tampilkan Semua Data Nilai\n";
        cout << "3. Urutkan Data Berdasarkan Nilai Rata-rata\n";
        cout << "4. Cari Data Siswa Berdasarkan ID\n";
        cout << "5. Tampilkan Siswa Nilai Tertinggi & Terendah\n";
        cout << "6. Keluar\n";
        cout << "Pilih menu: ";
        cin >> pilihan_menu;

        // Struktur kontrol utama memanggil modul-modul
        if (pilihan_menu == 1) {
            // Memanggil Modul inputData()
            inputData(id_siswa, nama_siswa, nilai_tugas, nilai_uts, nilai_uas, rata_rata, kategori, jumlah_siswa);
        }
        else if (pilihan_menu == 2) {
            // Memanggil Modul tampilkanData()
            tampilkanData(id_siswa, nama_siswa, rata_rata, kategori, jumlah_siswa);
        }
        else if (pilihan_menu == 3) {
            // Memanggil Modul bubbleSort()
            bubbleSort(id_siswa, nama_siswa, nilai_tugas, nilai_uts, nilai_uas, rata_rata, kategori, jumlah_siswa);
        }
        else if (pilihan_menu == 4) {
            // Memanggil Modul cariSiswa()
            cariSiswa(id_siswa, nama_siswa, rata_rata, kategori, jumlah_siswa);
        }
        else if (pilihan_menu == 5) {
            // Memanggil Modul nilaiTertinggiTerendah()
            nilaiTertinggiTerendah(nama_siswa, rata_rata, jumlah_siswa);
        }
        else if (pilihan_menu == 6) {
            cout << "\nTerima kasih, program selesai!\n";
        }
        else {
            cout << "\nPilihan tidak valid!\n";
        }

    } while (pilihan_menu != 6);

    return 0;
}



// =================================================================
// DEFINISI FUNGSI MODUL
// (Sesuai dengan b. Fungsi-fungsi Modul & 2. Penjelasan Modul)
// =================================================================

// b. Fungsi–fungsi Modul: inputData()
void inputData(vector<int>& id_siswa, vector<string>& nama_siswa,
               vector<float>& nilai_tugas, vector<float>& nilai_uts,
               vector<float>& nilai_uas, vector<float>& rata_rata,
               vector<char>& kategori, int& jumlah_siswa) {
    // =======================================
    // VALIDASI JUMLAH SISWA HARUS ANGKA
    // =======================================
    string temp_jumlah;
    bool jumlah_valid = false;

    while (!jumlah_valid) {
        cout << "Masukkan jumlah siswa: ";
        cin >> temp_jumlah;

        bool semua_digit = true;
        for (char c : temp_jumlah) {
            if (!isdigit(c)) {
                semua_digit = false;
                break;
            }
        }

        if (!semua_digit) {
            cout << "❌ Jumlah siswa harus berupa angka! Coba lagi.\n";
            continue;
        }

        jumlah_siswa = stoi(temp_jumlah);

        if (jumlah_siswa <= 0) {
            cout << "❌ Jumlah siswa tidak boleh 0 atau negatif!\n";
        } else {
            jumlah_valid = true;
        }
    }

    // Resize vector
    id_siswa.resize(jumlah_siswa);
    nama_siswa.resize(jumlah_siswa);
    nilai_tugas.resize(jumlah_siswa);
    nilai_uts.resize(jumlah_siswa);
    nilai_uas.resize(jumlah_siswa);
    rata_rata.resize(jumlah_siswa);
    kategori.resize(jumlah_siswa);

    for (int i = 0; i < jumlah_siswa; i++) {
        cout << "\nData siswa ke-" << i + 1 << endl;

        // ============================
        // VALIDASI INPUT ID HARUS ANGKA
        // ============================
        string temp_id;
        bool id_valid = false;

        while (!id_valid) {
            cout << "ID Siswa (unik & angka): ";
            cin >> temp_id;

            bool semua_digit = true;
            for (char c : temp_id) {
                if (!isdigit(c)) {
                    semua_digit = false;
                    break;
                }
            }

            if (!semua_digit) {
                cout << "❌ ID harus berupa angka! Coba lagi.\n";
                continue;
            }

            id_siswa[i] = stoi(temp_id);

            // cek ID unik
            id_valid = true;
            for (int j = 0; j < i; j++) {
                if (id_siswa[i] == id_siswa[j]) {
                    cout << "❌ ID sudah digunakan! Masukkan ID lain.\n";
                    id_valid = false;
                    break;
                }
            }
        }

        // ============================
        // VALIDASI NAMA HARUS HURUF
        // ============================
        bool nama_valid = false;
        while (!nama_valid) {
            cout << "Nama Siswa (huruf saja): ";
            cin >> nama_siswa[i];

            nama_valid = true;
            for (char c : nama_siswa[i]) {
                if (!isalpha(c)) {
                    nama_valid = false;
                    break;
                }
            }

            if (!nama_valid) {
                cout << "❌ Nama hanya boleh huruf! Coba lagi.\n";
            }
        }

        // ============================
        // VALIDASI NILAI HARUS ANGKA
        // Bisa float
        // ============================
        auto inputNilai = [&](string label, float &nilai) {
            string temp;
            bool valid = false;
            while (!valid) {
                cout << label;
                cin >> temp;

                bool angka_valid = true;
                int titik_count = 0;

                for (char c : temp) {
                    if (c == '.') {
                        titik_count++;
                        if (titik_count > 1) {
                            angka_valid = false;
                            break;
                        }
                    } else if (!isdigit(c)) {
                        angka_valid = false;
                        break;
                    }
                }

                if (!angka_valid) {
                    cout << "❌ Nilai harus berupa angka! Coba lagi.\n";
                    continue;
                }

                nilai = stof(temp); // konversi
                valid = true;
            }
        };

        inputNilai("Nilai Tugas: ", nilai_tugas[i]);
        inputNilai("Nilai UTS   : ", nilai_uts[i]);
        inputNilai("Nilai UAS   : ", nilai_uas[i]);

        // hitung rata-rata
        rata_rata[i] = (nilai_tugas[i] + nilai_uts[i] + nilai_uas[i]) / 3;

        // kategori
        if (rata_rata[i] >= 85) kategori[i] = 'A';
        else if (rata_rata[i] >= 70) kategori[i] = 'B';
        else if (rata_rata[i] >= 55) kategori[i] = 'C';
        else if (rata_rata[i] >= 40) kategori[i] = 'D';
        else kategori[i] = 'E';
    }

    cout << "\nInput data siswa berhasil!\n";
}


// b. Fungsi–fungsi Modul: tampilkanData()
void tampilkanData(const vector<int>& id_siswa, const vector<string>& nama_siswa,
                    const vector<float>& rata_rata, const vector<char>& kategori,
                    int jumlah_siswa) {
    if (jumlah_siswa == 0) {
        cout << "\nBelum ada data siswa!\n";
    } else {
        cout << "\n=== DAFTAR NILAI SISWA ===\n";
        for (int i = 0; i < jumlah_siswa; i++) {
            cout << "\nID: " << id_siswa[i]
                 << "\nNama: " << nama_siswa[i]
                 << "\nRata-rata: " << rata_rata[i]
                 << "\nKategori: " << kategori[i] << "\n";
        }
    }
}

// b. Fungsi–fungsi Modul: bubbleSort()
void bubbleSort(vector<int>& id_siswa, vector<string>& nama_siswa,
                vector<float>& nilai_tugas, vector<float>& nilai_uts,
                vector<float>& nilai_uas, vector<float>& rata_rata,
                vector<char>& kategori, int jumlah_siswa) {
    if (jumlah_siswa == 0) {
        cout << "\nBelum ada data siswa!\n";
    } else {
        // Algoritma Bubble Sort (Descending)
        for (int i = 0; i < jumlah_siswa - 1; i++) {
            for (int j = 0; j < jumlah_siswa - i - 1; j++) {
                if (rata_rata[j] < rata_rata[j + 1]) {
                    // swap() dari library <algorithm>
                    swap(rata_rata[j], rata_rata[j + 1]);
                    // Tukar semua elemen terkait untuk menjaga stabilitas data
                    swap(id_siswa[j], id_siswa[j + 1]);
                    swap(nama_siswa[j], nama_siswa[j + 1]);
                    swap(nilai_tugas[j], nilai_tugas[j + 1]);
                    swap(nilai_uts[j], nilai_uts[j + 1]);
                    swap(nilai_uas[j], nilai_uas[j + 1]);
                    swap(kategori[j], kategori[j + 1]);
                }
            }
        }

        cout << "\nData telah diurutkan berdasarkan nilai rata-rata (descending).\n";

        cout << "\n=== Ranking Siswa ===\n";
        for (int i = 0; i < jumlah_siswa; i++) {
            cout << i + 1 << ". " << nama_siswa[i]
                 << " - Rata-rata: " << rata_rata[i] << endl;
        }
    }
}


// b. Fungsi–fungsi Modul: cariSiswa()
void cariSiswa(const vector<int>& id_siswa, const vector<string>& nama_siswa,
               const vector<float>& rata_rata, const vector<char>& kategori,
               int jumlah_siswa) {
    if (jumlah_siswa == 0) {
        cout << "\nBelum ada data siswa!\n";
    } else {
        int id_cari;
        bool ditemukan = false;

        cout << "Masukkan ID yang dicari: ";
        cin >> id_cari;

        // Sequential Search
        for (int i = 0; i < jumlah_siswa; i++) {
            if (id_siswa[i] == id_cari) {
                cout << "\nData ditemukan!\n";
                cout << "ID: " << id_siswa[i] << endl;
                cout << "Nama: " << nama_siswa[i] << endl;
                cout << "Rata-rata: " << rata_rata[i] << endl;
                cout << "Kategori: " << kategori[i] << endl;
                ditemukan = true;
                break;
            }
        }

        if (!ditemukan) {
            cout << "\nData siswa tidak ditemukan.\n";
        }
    }
}

// b. Fungsi–fungsi Modul: nilaiTertinggiTerendah()
void nilaiTertinggiTerendah(const vector<string>& nama_siswa,
                            const vector<float>& rata_rata, int jumlah_siswa) {
    if (jumlah_siswa == 0) {
        cout << "\nBelum ada data siswa!\n";
    } else {
        int idx_max = 0, idx_min = 0;

        for (int i = 1; i < jumlah_siswa; i++) {
            if (rata_rata[i] > rata_rata[idx_max]) idx_max = i;
            if (rata_rata[i] < rata_rata[idx_min]) idx_min = i;
        }

        cout << "\nNilai Tertinggi: "
             << nama_siswa[idx_max] << " (" << rata_rata[idx_max] << ")\n";

        cout << "Nilai Terendah: "
             << nama_siswa[idx_min] << " (" << rata_rata[idx_min] << ")\n";
    }
}
