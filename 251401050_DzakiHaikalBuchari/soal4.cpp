#include <iostream>
using namespace std;

int main() {
    int n;
    string s;
    cout << "N : ";
    cin >> n;

    cout << "S : ";
    cin >> s;

    int poina = 0, poinb = 0;
    int streaka = 0, streakb = 0;

    for (int i = 0; i < n; i++) {
        if (s[i] == 'A' || s[i] == 'a') {
            poina += 3;
            streaka++;
            streakb = 0;

            if (streaka == 3) {
                poina += 2;
            }
        }
        else if (s[i] == 'B' || s[i] == 'b') {
            poinb += 3;
            streakb++;
            streaka = 0;

            if (streakb == 3) {
                poinb += 2;
            }
        }
        else if (s[i] == 'C' || s[i] == 'c') {
            poina += 1;
            poinb += 1;
            streaka = 0;
            streakb = 0;
        }
    }

    if (poina > poinb) {
        cout << "pemenangnya adalah pemain A" << endl;
    }
    else if (poinb > poina) {
        cout << "pemenangnya adalah pemain B" << endl;
    }
    else {
        cout << "seri" << endl;
    }

    cout << "poin A: " << poina << endl;
    cout << "poin B: " << poinb << endl;

    return 0;
}

/*
ALGORITMA PROGRAM:

1. Input jumlah babak (n) dan string hasil pertandingan (s).

2. Inisialisasi:
   - poin A = 0, poin B = 0
   - streak A = 0, streak B = 0 (untuk menghitung menang berturut-turut)

3. Loop setiap karakter dalam string:
   - Jika 'A':
       → poin A +3
       → streak A bertambah
       → streak B direset
       → jika streak A = 3 → tambah bonus +2 poin

   - Jika 'B':
       → poin B +3
       → streak B bertambah
       → streak A direset
       → jika streak B = 3 → tambah bonus +2 poin

   - Jika 'C' (seri):
       → poin A +1 dan poin B +1
       → kedua streak direset

4. Setelah semua babak selesai:
   - Bandingkan poin A dan B
   - Jika poin A > poin B → A menang
   - Jika poin B > poin A → B menang
   - Jika sama → seri

5. Tampilkan:
   - pemenang pertandingan
   - total poin A dan B
*/
