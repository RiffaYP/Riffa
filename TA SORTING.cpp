#include <iostream>
#include <string>
using namespace std;

struct Mahasiswa {
    string nama;
    int nilai;
};

int main() {
    int n;
    Mahasiswa mhs[100];

    cout << "Masukkan jumlah mahasiswa:";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Masukkan nama mahasiswa ke-" << i+1 << ": ";
        cin >> mhs[i].nama;
        cout << "Masukkan nilai " << mhs[i].nama << ": ";
        cin >> mhs[i].nilai;
    }

    for (int i = 1; i < n; i++) {
        Mahasiswa temp = mhs[i];
        int j = i - 1;
        while (j >= 0 && mhs[j].nilai > temp.nilai) {
            mhs[j + 1] = mhs[j];
            j--;
        }
        mhs[j + 1] = temp;
    }

    cout << "\nDaftar Nilai Mahasiswa (Ascending):\n";
    for (int i = 0; i < n; i++) {
        cout << mhs[i].nama << " - " << mhs[i].nilai << endl;
    }

    return 0;
}