#include <iostream>
using namespace std;

bool login() {
    string user, pw;
    int perulangan = 0;
    
    while (perulangan < 3) {
        cout << "Masukkan Username Terlebih Dahulu: ";
        getline(cin, user);
        cout << "Masukkan Password Terlebih Dahulu: ";
        getline(cin, pw);

        if (user == "Muhammad Annur Akbar" && pw == "2309106110") {
            return true; // Login successful
        } else {
            cout << "Username Atau Password SALAH" << endl;
            perulangan++;
        }
    }

    return false; // Login failed after 3 attempts
}

void displayEquipment(const string dataperalatan[], int perulangan) {
    cout << "Daftar Peralatan:" << endl;

    bool dataExists = false;
    for (int i = 0; i < 100; ++i) {
        if (!dataperalatan[i].empty()) {
            cout << i + 1 << ". " << dataperalatan[i] << endl;
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

void addEquipment(string dataperalatan[]) {
    string nama;
    cout << "Masukkan Nama Peralatan: ";
    cin >> nama;

    for (int i = 0; i < 100; ++i) {
        if (dataperalatan[i].empty()) {
            dataperalatan[i] = nama;
            break;
        }
    }
}

void deleteEquipment(string dataperalatan[]) {
    int nomor;
    cout << "Masukkan Nomor Peralatan yang Akan Dihapus: ";
    cin >> nomor;

    if (nomor >= 1 && nomor <= 100 && !dataperalatan[nomor - 1].empty()) {
        dataperalatan[nomor - 1] = "";
        cout << "Peralatan berhasil dihapus." << endl;
    } else {
        cout << "Nomor peralatan tidak valid atau data peralatan tidak ada." << endl;
    }
}

void editEquipment(string dataperalatan[]) {
    int nomorEdit;
    cout << "Masukkan Nomor Peralatan yang Akan Diedit: ";
    cin >> nomorEdit;

    if (nomorEdit >= 1 && nomorEdit <= 100 && !dataperalatan[nomorEdit - 1].empty()) {
        string nama;
        cout << "Masukkan Nama Peralatan Baru: ";
        cin >> nama;
        dataperalatan[nomorEdit - 1] = nama;
        cout << "Peralatan berhasil diupdate." << endl;
    } else {
        cout << "Nomor peralatan tidak valid atau data peralatan tidak ada." << endl;
    }
}

int main() {
    string dataperalatan[100];
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
                displayEquipment(dataperalatan, 0); // Start recursion from 0
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
