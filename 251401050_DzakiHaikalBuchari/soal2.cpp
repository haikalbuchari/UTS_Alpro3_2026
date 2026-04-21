#include <iostream>
using namespace std;

int main() {
    string kode;
    int jamkeluar;

    cout << "Masukkan kode parkir (10 digit): ";
    cin >> kode;

    cout << "Masukkan jam keluar (HHMM): ";
    cin >> jamkeluar;

    
    int jenis = (kode[0] - '0') * 10 + (kode[1] - '0');

    
    int jammasuk = (kode[2] - '0') * 10 + (kode[3] - '0');
    int menitmasuk = (kode[4] - '0') * 10 + (kode[5] - '0');

    
    int jamkeluarjam = jamkeluar / 100;
    int menitkeluar = jamkeluar % 100;

    
    int totalmasuk = jammasuk * 60 + menitmasuk;
    int totalkeluar = jamkeluarjam * 60 + menitkeluar;

    int durasimenit = totalkeluar - totalmasuk;


    int durasijam = durasimenit / 60;
    if (durasimenit % 60 != 0) {
        durasijam++;
    }

    
    int totalbiaya = 0;
    string namakendaraan;

    if (jenis == 10) {
        namakendaraan = "Mobil pribadi";
        totalbiaya = 5000;
        if (durasijam > 1) {
            totalbiaya += (durasijam - 1) * 3000;
        }
    }
    else if (jenis == 20) {
        namakendaraan = "Motor";
        totalbiaya = 3000;
        if (durasijam > 1) {
            totalbiaya += (durasijam - 1) * 2000;
        }
    }
    else if (jenis == 30) {
        namakendaraan = "Bus";
        totalbiaya = 10000;
        if (durasijam > 1) {
            totalbiaya += (durasijam - 1) * 7000;
        }
    }
    else {
        cout << "Jenis kendaraan tidak valid!" << endl;
        return 0;
    }

    
        string lokasi = "";
        for (int i = 6; i < 10; i++) {
            lokasi += kode[i];
    }

    
    cout << "\n--- Ringkasan Parkir ---" << endl;
    cout << "Jenis kendaraan : " << namakendaraan << endl;
    cout << "Jam masuk       : " << jammasuk << ":" << menitmasuk << endl;
    cout << "Jam keluar      : " << jamkeluarjam << ":" << menitkeluar << endl;
    cout << "Durasi parkir   : " << durasijam << " jam" << endl;
    cout << "Lokasi parkir   : " << lokasi << endl;
    cout << "Total biaya     : Rp " << totalbiaya << endl;

    return 0;
}

/*
ALGORITMA PROGRAM:

1. Input kode parkir (10 digit) dan jam keluar.
2. Cek apakah panjang kode = 10, kalau tidak → tidak valid.

3. Ambil 2 digit pertama sebagai jenis kendaraan:
   - 10 → mobil pribadi
   - 20 → motor
   - 30 → bus

4. Ambil digit ke-3 sampai ke-6 sebagai waktu masuk:
   - pisahkan jadi jam dan menit

5. Pecah jam keluar menjadi jam dan menit.

6. Ubah waktu masuk dan keluar ke dalam menit semua.

7. Hitung durasi:
   - durasi = keluar - masuk
   - jika hasil negatif → waktu tidak valid
   - ubah ke jam (kalau ada sisa menit, dibulatkan ke atas)

8. Tentukan tarif berdasarkan jenis kendaraan:
   - mobil: 5000 jam pertama, berikutnya 3000
   - motor: 3000 jam pertama, berikutnya 2000
   - bus: 10000 jam pertama, berikutnya 7000

9. Hitung total biaya:
   - jam pertama + tambahan jam berikutnya

10. Ambil 4 digit terakhir sebagai lokasi parkir.

11. Tampilkan:
   - jenis kendaraan
   - durasi parkir
   - lokasi
   - total biaya
*/
