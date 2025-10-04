#include <iostream>
#include <string>
using namespace std;

int binarySearch(string arr[], int n, string target) {
    int l = 0, r = n - 1;
    while (l <= r) {
        int m = l + (r - l) / 2;
        cout << "median :" << m << endl;

        if (arr[m] == target)
            return m;

        if (arr[m] > target)
            r = m - 1;
        else
            l = m + 1;
    }
    return -1; 
}

int main() {
    string kamus[] = {"apel", "buku", "cantik", "daun", "elektro", 
                      "ganteng", "hujan", "informatika", "jendela", "kuda"};

    int n = sizeof(kamus) / sizeof(kamus[0]);
    string kata;

    cout << "Masukkan kata yang ingin dicari: ";
    cin >> kata;

    int hasil = binarySearch(kamus, n, kata);

    if (hasil != -1)
        cout << "Kata \"" << kata << "\" ditemukan pada indeks ke-" << hasil << endl;
    else
        cout << "Kata \"" << kata << "\" tidak ditemukan dalam kamus." << endl;

    return 0;
}