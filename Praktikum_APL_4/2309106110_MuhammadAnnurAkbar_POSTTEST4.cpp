#include <iostream>
using namespace std;

// Deklarasi nested struct untuk kategori peralatan
struct EquipmentCategory {
    string name;
};

// Deklarasi struct untuk peralatan dengan nested struct kategori
struct Equipment {
    string name;
    EquipmentCategory category;
};

bool login() {
    string user, pw;
    int perulangan = 0;
    
    while (perulangan < 3) {
        cout << "Masukkan Username Terlebih Dahulu: ";
        getline(cin, user);
        cout << "Masukkan Password Terlebih Dahulu: ";
        getline(cin, pw);

        if (user == "Muhammad Annur Akbar" && pw == "110") {
            return true; // Login berhasil
        } else {
            cout << "Username Atau Password SALAH" << endl;
            perulangan++;
        }
    }

    return false; // Login gagal setelah 3 kali mencoba
}

void displayEquipment(const Equipment dataperalatan[], int perulangan) {
    cout << "Daftar Peralatan:" << endl;

    bool dataExists = false;
    for (int i = 0; i < 100; ++i) {
        if (!dataperalatan[i].name.empty()) {
            cout << i + 1 << ". " << dataperalatan[i].name << " (Kategori: " << dataperalatan[i].category.name << ")" << endl;
            dataExists = true;
        }
    }

    if (!dataExists) {
        cout << "Data Belum Ada" << endl;
    }

    cout << "-------------------" << endl;

    if (perulangan < 3) {
        char choice;
        cout << "Apakah Anda ingin melihat daftar peralatan lagi? (y/n): ";
        cin >> choice;
        if (choice == 'y' || choice == 'Y') {
            displayEquipment(dataperalatan, perulangan + 1); // <-- Letak Rekursif
        }
    }
}

void addEquipment(Equipment dataperalatan[]) {
    string nama, kategori;
    cout << "Masukkan Nama Peralatan: ";
    cin >> nama;
    cout << "Masukkan Kategori Peralatan: ";
    cin >> kategori;

    for (int i = 0; i < 100; ++i) {
        if (dataperalatan[i].name.empty()) {
            dataperalatan[i].name = nama;
            dataperalatan[i].category.name = kategori;
            break;
        }
    }
}

void deleteEquipment(Equipment dataperalatan[]) {
    int nomor;
    cout << "Masukkan Nomor Peralatan yang Akan Dihapus: ";
    cin >> nomor;

    if (nomor >= 1 && nomor <= 100 && !dataperalatan[nomor - 1].name.empty()) {
        dataperalatan[nomor - 1].name = "";
        dataperalatan[nomor - 1].category.name = "";
        cout << "Peralatan berhasil dihapus." << endl;
    } else {
        cout << "Nomor peralatan tidak valid atau data peralatan tidak ada." << endl;
    }
}

void editEquipment(Equipment dataperalatan[]) {
    int nomorEdit;
    cout << "Masukkan Nomor Peralatan yang Akan Diedit: ";
    cin >> nomorEdit;

    if (nomorEdit >= 1 && nomorEdit <= 100 && !dataperalatan[nomorEdit - 1].name.empty()) {
        string nama, kategori;
        cout << "Masukkan Nama Peralatan Baru: ";
        cin >> nama;
        cout << "Masukkan Kategori Peralatan Baru: ";
        cin >> kategori;
        dataperalatan[nomorEdit - 1].name = nama;
        dataperalatan[nomorEdit - 1].category.name = kategori;
        cout << "Peralatan berhasil diupdate." << endl;
    } else {
        cout << "Nomor peralatan tidak valid atau data peralatan tidak ada." << endl;
    }
}

int main() {
    Equipment dataperalatan[100]; // Array of struct untuk peralatan
    int pilih, perulangan = 0;

    if (!login()) {
        cout << "Login failed after 3 attempts. Exiting program." << endl;
        return 1;
    }

    while (perulangan < 3) {
        cout << "1. Lihat Semua Peralatan" << endl;
        cout << "2. Tambah Peralatan" << endl;
        cout << "3. Hapus Data Peralatan" << endl;
        cout << "4. Edit Peralatan" << endl;
        cout << "5. EXIT" << endl;
        cout << "---------------------------" << endl;
        cout << "Masukkan Pilihan Anda:  ";
        cin >> pilih;

        switch (pilih) {
            case 1:
                displayEquipment(dataperalatan, 0); // Mulai rekursi dari 0
                break;
            case 2:
                addEquipment(dataperalatan);
                break;
            case 3:
                deleteEquipment(dataperalatan);
                break;
            case 4:
                editEquipment(dataperalatan);
                break;
            case 5:
                perulangan = 3;
                break;
            default:
                cout << "Pilihan Tidak Ada" << endl;
                break;
        }
    }

    cout << "Program selesai." << endl;
    return 0;
}