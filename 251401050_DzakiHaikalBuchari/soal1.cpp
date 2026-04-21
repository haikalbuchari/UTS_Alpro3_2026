#include <iostream>
using namespace std;

int main() {
    string kartu;
    int total = 0;

    cout << "Masukkan nomor kartu: ";
    cin >> kartu;

    int panjang = kartu.length();

    
    if (panjang == 14 && kartu[0] == '6' && kartu[1] == '5') {
        cout << "Jenis kartu: NUSANTARA" << endl;
    }
    
    else if (panjang == 16 &&
            ((kartu[0] == '7' && kartu[1] == '7') ||
             (kartu[0] == '7' && kartu[1] == '8'))) {
        cout << "Jenis kartu: GARUDA" << endl;
    }
    
    else if (panjang == 15 && kartu[0] == '9' && kartu[1] == '1') {
        cout << "Jenis kartu: MERDEKA" << endl;
    }

    else {
        cout << "Jenis kartu tidak valid!" << endl;
        return 0;
    }


    for (int i = panjang - 1; i >= 0; i--) {
    int digit = kartu[i] - '0';

    
    if ((panjang - i) % 2 == 0) {
        digit = digit * 2;

        if (digit > 9) {
            digit = (digit / 10) + (digit % 10);
        }
    }

    total += digit;
}
        

    if (total % 10 == 0) {
        cout << "Nomor kartu VALID" << endl;
    } 
    else {
        cout << "Nomor kartu TIDAK VALID" << endl;
    }

    return 0;
}

/*
ALGORITMA PROGRAM:

1. Input nomor kartu dalam bentuk string.
2. Hitung panjang digit kartu.
3. Cek jenis kartu:
   - Jika panjang 14 dan diawali 65 → NUSANTARA
   - Jika panjang 16 dan diawali 77 atau 78 → GARUDA
   - Jika panjang 15 dan diawali 91 → MERDEKA
   - Jika tidak sesuai → program berhenti

4. Lakukan proses validasi:
   - Loop dari digit paling kanan ke kiri
   - Ambil setiap digit dan ubah ke angka
   - Untuk setiap digit ke-2 dari belakang:
       kalikan dengan 2
       jika hasil > 9, jumlahkan digitnya
   - Jumlahkan semua digit ke dalam variabel total

5. Cek hasil akhir:
   - Jika total habis dibagi 10 → kartu VALID
   - Jika tidak → kartu TIDAK VALID
*/
