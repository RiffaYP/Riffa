#include <iostream>
using namespace std;

struct Node {
    int nilai;
    int urutan;
    Node *left, *right;
};

Node* buatNode(int nilai, int urutan) {
    Node* baru = new Node;
    baru->nilai = nilai;
    baru->urutan = urutan;
    baru->left = baru->right = nullptr;
    return baru;
}

Node* insertNode(Node* root, int nilai, int urutan) {
    if (root == nullptr)
        return buatNode(nilai, urutan);
    if (nilai < root->nilai)
        root->left = insertNode(root->left, nilai, urutan);
    else if (nilai > root->nilai)
        root->right = insertNode(root->right, nilai, urutan);
    else
        cout << "Nilai " << nilai << " sudah ada di tree.\n";
    return root;
}

void inorder(Node* root) {
    if (root == nullptr)
        return;
    inorder(root->left);
    cout << "Mahasiswa ke-" << root->urutan << " : Nilai = " << root->nilai << endl;
    inorder(root->right);
}

void preorder(Node* root) {
    if (root == nullptr)
        return;
    cout << "Mahasiswa ke-" << root->urutan << " : Nilai = " << root->nilai << endl;
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node* root) {
    if (root == nullptr)
        return;
    postorder(root->left);
    postorder(root->right);
    cout << "Mahasiswa ke-" << root->urutan << " : Nilai = " << root->nilai << endl;
}


Node* findMin(Node* root) {
    while (root && root->left != nullptr)
        root = root->left;
    return root;
}

Node* findMax(Node* root) {
    while (root && root->right != nullptr)
        root = root->right;
    return root;
}

int main() {
    Node* root = nullptr;
    int pilih, nilai;
    int urutan = 1;

    do {
        cout << "\n=== DATA NILAI MAHASISWA (BST DASAR) ===\n";
        cout << "1. Tambah nilai mahasiswa\n";
        cout << "2. Tampilkan (Inorder)\n";
        cout << "3. Tampilkan (Preorder)\n";
        cout << "4. Tampilkan (Postorder)\n";
        cout << "5. Nilai minimum\n";
        cout << "6. Nilai maksimum\n";
        cout << "7. Keluar\n";
        cout << "Pilih: ";
        cin >> pilih;

        switch (pilih) {
            case 1:
                cout << "Masukkan nilai mahasiswa ke-" << urutan << ": ";
                cin >> nilai;
                root = insertNode(root, nilai, urutan);
                urutan++;
                break;

            case 2:
                if (root == nullptr)
                    cout << "Belum ada data nilai mahasiswa.\n";
                else {
                    cout << "\nTraversal Inorder (kiri–akar–kanan):\n";
                    inorder(root);
                }
                break;

            case 3:
                if (root == nullptr)
                    cout << "Belum ada data nilai mahasiswa.\n";
                else {
                    cout << "\nTraversal Preorder (akar–kiri–kanan):\n";
                    preorder(root);
                }
                break;

            case 4:
                if (root == nullptr)
                    cout << "Belum ada data nilai mahasiswa.\n";
                else {
                    cout << "\nTraversal Postorder (kiri–kanan–akar):\n";
                    postorder(root);
                }
                break;

            case 5:
                if (root) {
                    Node* minNode = findMin(root);
                    cout << "Nilai terkecil: " << minNode->nilai 
                         << " (Mahasiswa ke-" << minNode->urutan << ")\n";
                } else cout << "Data kosong.\n";
                break;

            case 6:
                if (root) {
                    Node* maxNode = findMax(root);
                    cout << "Nilai terbesar: " << maxNode->nilai 
                         << " (Mahasiswa ke-" << maxNode->urutan << ")\n";
                } else cout << "Data kosong.\n";
                break;

            case 7:
                cout << "Program selesai.\n";
                break;

            default:
                cout << "Pilihan tidak valid!\n";
        }

    } while (pilih != 7);

    return 0;
}