#include <iostream>
using namespace std;

const int MAX = 100;
string queueMie[MAX];
int frontIdx = -1, rearIdx = -1;

bool isEmpty() {
    return (frontIdx == -1 && rearIdx == -1);
}

bool isFull() {
    return (rearIdx == MAX - 1);
}

void enqueue(string nama) {
    if (isFull()) {
        cout << "Antrian penuh! Tidak dapat menambah pesanan.\n";
        return;
    } else if (isEmpty()) {
        frontIdx = rearIdx = 0;
    } else {
        rearIdx++;
    }
    queueMie[rearIdx] = nama;
    cout << "Pesanan atas nama " << nama << " berhasil ditambahkan ke antrian.\n";
}

void dequeue() {
    if (isEmpty()) {
        cout << "Antrian kosong! Tidak ada pesanan yang bisa dilayani.\n";
        return;
    }
    cout << "Pesanan atas nama " << queueMie[frontIdx] << " telah selesai dilayani.\n";
    if (frontIdx == rearIdx) {
        frontIdx = rearIdx = -1;
    } else {
        frontIdx++;
    }
}

void peek() {
    if (isEmpty()) {
        cout << "Tidak ada pelanggan yang sedang dilayani.\n";
    } else {
        cout << "Pelanggan yang sedang dilayani: " << queueMie[frontIdx] << endl;
    }
}

void display() {
    if (isEmpty()) {
        cout << "Antrian kosong.\n";
    } else {
        cout << "Daftar pelanggan yang sedang menunggu di Mie Gacoan:\n";
        for (int i = frontIdx; i <= rearIdx; i++) {
            cout << i - frontIdx + 1 << ". " << queueMie[i] << endl;
        }
    }
}

int main() {
    int pilih;
    string nama;
    do {
        cout << "\n=== SISTEM ANTRIAN PESANAN MIE GACOAN ===\n";
        cout << "1. Tambah Pesanan\n";
        cout << "2. Layani Pesanan\n";
        cout << "3. Lihat Pesanan Terdepan\n";
        cout << "4. Lihat Semua Pesanan\n";
        cout << "5. Keluar\n";
        cout << "Pilih: ";
        cin >> pilih;
        cin.ignore();

        switch (pilih) {
            case 1:
                cout << "Masukkan nama pelanggan: ";
                getline(cin, nama);
                enqueue(nama);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
            case 5:
                cout << "Program selesai. Semua pesanan telah dilayaani.\n";
                break;
            default:
                cout << "Pilihan tidak valid.\n";
        }
    } while (pilih != 5);

    return 0;
}