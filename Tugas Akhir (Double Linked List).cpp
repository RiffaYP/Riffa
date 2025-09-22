#include <iostream>
#include <string>
using namespace std;

struct Node {
    string url;
    Node *prev;
    Node *next;
};

Node *head = NULL, *tail = NULL, *current = NULL;

void bukaHalaman(string alamat) {
    Node *newNode = new Node{alamat, NULL, NULL};

    if (head == NULL) {
        head = tail = current = newNode;
    } else {
        Node *temp = current->next;
        while (temp != NULL) {
            Node *hapus = temp;
            temp = temp->next;
            delete hapus;
        }
        current->next = newNode;
        newNode->prev = current;
        tail = newNode;
        current = newNode;
    }
    cout << "Membuka halaman: " << alamat << endl;
}

void back() {
    if (current != NULL && current->prev != NULL) {
        current = current->prev;
        cout << "Kembali ke: " << current->url << endl;
    } else {
        cout << "Tidak ada halaman sebelumnya!" << endl;
    }
}

void forward() {
    if (current != NULL && current->next != NULL) {
        current = current->next;
        cout << "Maju ke: " << current->url << endl;
    } else {
        cout << "Tidak ada halaman berikutnya!" << endl;
    }
}

void tampilkanRiwayat() {
    cout << "\n=== Riwayat Browser ===" << endl;
    Node *temp = head;
    while (temp != NULL) {
        if (temp == current) {
            cout << "* " << temp->url << " (halaman aktif)" << endl;
        } else {
            cout << "  " << temp->url << endl;
        }
        temp = temp->next;
    }
    cout << "========================\n";
}

int main() {
    int pilihan;
    string alamat;

    do {
        cout << "\n===== MENU BROWSER =====" << endl;
        cout << "1. Buka Halaman Baru" << endl;
        cout << "2. Back" << endl;
        cout << "3. Forward" << endl;
        cout << "4. Tampilkan Riwayat" << endl;
        cout << "5. Keluar" << endl;
        cout << "Pilihan: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                cout << "Masukkan URL: ";
                cin >> alamat;
                bukaHalaman(alamat);
                break;
            case 2:
                back();
                break;
            case 3:
                forward();
                break;
            case 4:
                tampilkanRiwayat();
                break;
            case 5:
                cout << "Keluar dari program." << endl;
                break;
            default:
                cout << "Pilihan tidak valid!" << endl;
        }
    } while (pilihan != 5);

    return 0;
}