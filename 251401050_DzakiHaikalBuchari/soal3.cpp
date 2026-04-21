#include <iostream>
using namespace std;

int main() {
    string kode;
    cout << "Masukkan kode : ";
    cin >> kode;

    if (kode.length() != 8) {
        cout << "kode tidak valid";
        return 0;
    }

    string namahari, namaloyal;
    int poinpel = 0;

    if (kode[0] == '0' && kode[1] == '1') {
        namahari = "Hari Kerja";
        if (kode[2] == '0' && kode[3] == '1') { namaloyal = "Biasa"; poinpel = 1; }
        else if (kode[2] == '0' && kode[3] == '2') { namaloyal = "Silver"; poinpel = 2; }
        else if (kode[2] == '0' && kode[3] == '3') { namaloyal = "Gold"; poinpel = 3; }
        else { cout << "kode tidak valid"; return 0; }
    }
    else if (kode[0] == '0' && kode[1] == '2') {
        namahari = "Akhir Pekan";
        if (kode[2] == '0' && kode[3] == '1') { namaloyal = "Biasa"; poinpel = 2; }
        else if (kode[2] == '0' && kode[3] == '2') { namaloyal = "Silver"; poinpel = 3; }
        else if (kode[2] == '0' && kode[3] == '3') { namaloyal = "Gold"; poinpel = 5; }
        else { cout << "kode tidak valid"; return 0; }
    }
    else if (kode[0] == '0' && kode[1] == '3') {
        namahari = "Hari Libur Nasional";
        if (kode[2] == '0' && kode[3] == '1') { namaloyal = "Biasa"; poinpel = 3; }
        else if (kode[2] == '0' && kode[3] == '2') { namaloyal = "Silver"; poinpel = 5; }
        else if (kode[2] == '0' && kode[3] == '3') { namaloyal = "Gold"; poinpel = 7; }
        else { cout << "kode tidak valid"; return 0; }
    }
    else {
        cout << "kode tidak valid";
        return 0;
    }

    int belanja =
        (kode[4] - '0') * 1000 +
        (kode[5] - '0') * 100 +
        (kode[6] - '0') * 10 +
        (kode[7] - '0');

    int totalpoin = belanja * poinpel;
    int totalbelanja = belanja * 100000;

    cout <<"Jenis Hari : " << namahari << endl;     
    cout <<"Jenis Pelanggan : " << namaloyal << endl;
    cout << "Jumlah Belanja : "<< totalbelanja << endl;
    cout <<"Total Poin : "<< totalpoin << endl;

    return 0;
}

/*
ALGORITMA PROGRAM:

1. Input kode transaksi (8 digit).
2. Cek apakah panjang kode = 8, kalau tidak → tidak valid.

3. Ambil 2 digit pertama sebagai jenis hari:
   - 01 → hari kerja
   - 02 → akhir pekan
   - 03 → hari libur nasional

4. Ambil 2 digit berikutnya sebagai jenis pelanggan:
   - 01 → biasa
   - 02 → silver
   - 03 → gold

5. Ambil 4 digit terakhir sebagai jumlah belanja:
   - ubah ke angka
   - kalikan 100000 untuk dapat rupiah

6. Tentukan poin per 100000 berdasarkan kombinasi hari dan pelanggan:
   - hari kerja: biasa=1, silver=2, gold=3
   - akhir pekan: biasa=2, silver=3, gold=5
   - libur nasional: biasa=3, silver=5, gold=7

7. Hitung total poin:
   - total poin = jumlah belanja × poin per kategori

8. Tampilkan:
   - jenis hari
   - jenis pelanggan
   - total belanja (rupiah)
   - total poin
*/
