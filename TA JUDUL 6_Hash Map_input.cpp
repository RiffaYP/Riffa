#include <iostream>
#include <string>
using namespace std;

const int SIZE = 10;

struct Node {
    int nrm;
    string namaPasien;
    Node* next;
};

int hashFunction(int key) {
    return key % SIZE;
}

void initTable(Node* table[]) {
    for (int i = 0; i < SIZE; i++) {
        table[i] = nullptr;
    }
}

void insert(Node* table[], int nrm, string nama) {
    int index = hashFunction(nrm);
    Node* newNode = new Node{nrm, nama, table[index]};
    table[index] = newNode;
}

void display(Node* table[]) {
    cout << "\n=== Daftar Data Pasien Rumah Sakit ===\n";
    for (int i = 0; i < SIZE; i++) {
        cout << i << ": ";
        Node* temp = table[i];
        while (temp != nullptr) {
            cout << "(" << temp->nrm << ", " << temp->namaPasien << ") -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
}

Node* search(Node* table[], int nrm) {
    int index = hashFunction(nrm);
    Node* temp = table[index];
    while (temp != nullptr) {
        if (temp->nrm == nrm)
            return temp;
        temp = temp->next;
    }
    return nullptr;
}

void removeKey(Node* table[], int nrm) {
    int index = hashFunction(nrm);
    Node* cur = table[index];
    Node* prev = nullptr;

    while (cur != nullptr) {
        if (cur->nrm == nrm) {
            if (prev == nullptr)
                table[index] = cur->next;
            else
                prev->next = cur->next;
            delete cur;
            cout << "Pasien dengan NRM " << nrm << " telah dihapus.\n";
            return;
        }
        prev = cur;
        cur = cur->next;
    }
    cout << "Data pasien tidak ditemukan.\n";
}

int main() {
    Node* table[SIZE];
    initTable(table);

    int pilihan;
    do {
        cout << "\n=== MENU DATA PASIEN RUMAH SAKIT ===\n";
        cout << "1. Tambah Data Pasien\n";
        cout << "2. Tampilkan Semua Data\n";
        cout << "3. Cari Data Pasien\n";
        cout << "4. Hapus Data Pasien\n";
        cout << "5. Keluar\n";
        cout << "Pilih menu (1-5): ";
        cin >> pilihan;

        if (pilihan == 1) {
            int nrm;
            string nama;
            cout << "Masukkan Nomor Rekam Medis pasien: ";
            cin >> nrm;
            cin.ignore();
            cout << "Masukkan nama pasien: ";
            getline(cin, nama);
            insert(table, nrm, nama);
            cout << "Data pasien berhasil ditambahkan!\n";
        }
        else if (pilihan == 2) {
            display(table);
        }
        else if (pilihan == 3) {
            int nrm;
            cout << "Masukkan NRM pasien yang dicari: ";
            cin >> nrm;
            Node* hasil = search(table, nrm);
            if (hasil)
                cout << "Pasien ditemukan: " << hasil->namaPasien << endl;
            else
                cout << "Pasien tidak ditemukan.\n";
        }
        else if (pilihan == 4) {
            int nrm;
            cout << "Masukkan NRM pasien yang ingin dihapus: ";
            cin >> nrm;
            removeKey(table, nrm);
        }
        else if (pilihan == 5) {
            cout << "Terima kasih! Program selesai.\n";
        }
        else {
            cout << "Pilihan tidak valid, coba lagi.\n";
        }

    } while (pilihan != 5);

    return 0;
}