#include <iostream>
#include <string>
using namespace std;

// Kelas untuk menghitung nilai
class HitungNilai {
private:
    string nama;
    string kelas;

public:
    // Constructor
    HitungNilai(string n, string k) {
        nama = n;
        kelas = k;
    }

    // Fungsi untuk menampilkan data siswa
    void tampilDataSiswa() {
        cout << "Nama  : " << nama << endl;
        cout << "Kelas : " << kelas << endl;
    }

    // Fungsi untuk menghitung rata-rata
    float hitungRataRata(float nilai[], int jumlah) {
        float total = 0;
        for(int i = 0; i < jumlah; i++) {
            total += nilai[i];
        }
        return total / jumlah;
    }

    // Fungsi untuk menghitung nilai akhir
    float hitungNilaiAkhir(float rataHarian, float uts, float uas, float rataTugas) {
        // Bobot: Harian 30%, UTS 30%, UAS 30%, Tugas 10%
        return (rataHarian * 0.3) + (uts * 0.3) + (uas * 0.3) + (rataTugas * 0.1);
    }

    // Fungsi untuk menentukan grade
    string tentukanGrade(float nilai) {
        if(nilai >= 90) return "A (Sangat Baik)";
        else if(nilai >= 80) return "B (Baik)";
        else if(nilai >= 70) return "C (Cukup)";
        else if(nilai >= 60) return "D (Kurang)";
        else return "E (Sangat Kurang)";
    }

    // Fungsi untuk menentukan status kelulusan
    string tentukanStatus(float nilai) {
        if(nilai >= 75) return "LULUS (Baik)";
        else if(nilai >= 65) return "LULUS (Cukup)";
        else return "TIDAK LULUS (Remedial)";
    }
};

int main() {
    string nama, kelas;

    cout << "=============================\n";
    cout << "   SISTEM NILAI RAPORT OOP\n";
    cout << "=============================\n\n";

    // Input data siswa
    cout << "Masukkan Nama Siswa: ";
    getline(cin, nama);

    cout << "Masukkan Kelas: ";
    getline(cin, kelas);

    // Buat objek dari kelas HitungNilai
    HitungNilai raport(nama, kelas);

    cout << "\n=== INPUT NILAI ===\n\n";

    // Input nilai
    float harian[3], tugas[2], uts, uas;

    // Input nilai harian
    cout << "NILAI HARIAN (3 nilai):\n";
    for(int i = 0; i < 3; i++) {
        cout << "  Nilai harian ke-" << (i+1) << ": ";
        cin >> harian[i];
    }

    // Input nilai UTS dan UAS
    cout << "\nNILAI UTS: ";
    cin >> uts;
    cout << "NILAI UAS: ";
    cin >> uas;

    // Input nilai tugas
    cout << "\nNILAI TUGAS (2 nilai):\n";
    for(int i = 0; i < 2; i++) {
        cout << "  Nilai tugas ke-" << (i+1) << ": ";
        cin >> tugas[i];
    }

    // Hitung rata-rata menggunakan fungsi dari class
    float rataHarian = raport.hitungRataRata(harian, 3);
    float rataTugas = raport.hitungRataRata(tugas, 2);

    // Hitung nilai akhir
    float nilaiAkhir = raport.hitungNilaiAkhir(rataHarian, uts, uas, rataTugas);

    // Tentukan grade
    string grade = raport.tentukanGrade(nilaiAkhir);

    // Tentukan status
    string status = raport.tentukanStatus(nilaiAkhir);

    // Tampilkan hasil
    cout << "\n\n=============================\n";
    cout << "       HASIL RAPORT\n";
    cout << "=============================\n";
    raport.tampilDataSiswa();
    cout << "=============================\n\n";

    cout << "REKAP NILAI:\n";
    cout << "----------\n";
    cout << "Nilai Harian : ";
    for(int i = 0; i < 3; i++) {
        cout << harian[i] << " ";
    }
    cout << "(Rata-rata: " << rataHarian << ")\n";

    cout << "Nilai UTS    : " << uts << endl;
    cout << "Nilai UAS    : " << uas << endl;

    cout << "Nilai Tugas  : ";
    for(int i = 0; i < 2; i++) {
        cout << tugas[i] << " ";
    }
    cout << "(Rata-rata: " << rataTugas << ")\n\n";

    cout << "=============================\n";
    cout << "NILAI AKHIR : " << nilaiAkhir << endl;
    cout << "GRADE       : " << grade << endl;
    cout << "STATUS      : " << status << endl;
    cout << "=============================\n";

    return 0;
}
