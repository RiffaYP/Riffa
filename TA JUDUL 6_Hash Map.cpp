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
    cout << "Daftar Data Pasien Rumah Sakit:\n";
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

    insert(table, 1001, "Riffa");
    insert(table, 1011, "Faqih");
    insert(table, 1021, "Icha");
    insert(table, 1002, "Fareluna");

    display(table);

    cout << "\nPencarian pasien dengan NRM 1011:\n";
    Node* hasil = search(table, 1011);
    if (hasil)
        cout << "Pasien ditemukan: " << hasil->namaPasien << endl;
    else
        cout << "Pasien tidak ditemukan.\n";

    cout << "\nMenghapus pasien dengan NRM 1011...\n";
    removeKey(table, 1011);

    cout << "\nSetelah penghapusan:\n";
    display(table);

    return 0;
}