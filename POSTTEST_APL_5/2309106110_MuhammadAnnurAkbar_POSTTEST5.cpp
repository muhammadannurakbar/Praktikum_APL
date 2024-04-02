#include <iostream>
using namespace std;

struct EquipmentCategory {
    string name;
};

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
            return true; 
        } else {
            cout << "Username Atau Password SALAH" << endl;
            perulangan++;
        }
    }

    return false; 
}
void printEquipment(const Equipment* equipment) {
    cout << "Nama Peralatan: " << equipment->name << " (Kategori: " << equipment->category.name << ")" << endl;
}

void setEquipmentCategory(Equipment& equipment, const string& newCategory) {
    equipment.category.name = newCategory;
    cout << "Kategori peralatan berhasil diubah menjadi: " << newCategory << endl;
}

void displayEquipment(const Equipment dataperalatan[], int perulangan) {
    cout << "Daftar Peralatan:" << endl;

    bool dataExists = false;
    for (int i = 0; i < 100; ++i) {
        if (!dataperalatan[i].name.empty()) {
            cout << i + 1 << ". ";
            printEquipment(&dataperalatan[i]); 
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
            displayEquipment(dataperalatan, perulangan + 1); 
        }
    }
}

void addEquipment(Equipment dataperalatan[]) {
  
    string nama, kategori;
    cout << "Masukkan Nama Peralatan: ";
    getline(cin,nama);
    cout << "Masukkan Kategori Peralatan: ";
    getline(cin,kategori);

    for (int i = 0; i < 100; ++i) {
        if (dataperalatan[i].name.empty()) {
            dataperalatan[i].name = nama;
            dataperalatan[i].category.name = kategori;
            break;
        }
    }
}

void deleteEquipment(Equipment dataperalatan[]) {
    for (int i = 0; i < 100; ++i) {
        if (!dataperalatan[i].name.empty()) {
            cout << i + 1 << ". ";
            printEquipment(&dataperalatan[i]); 
        }
    }

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

    for (int i = 0; i < 100; ++i) {
        if (!dataperalatan[i].name.empty()) {
            cout << i + 1 << ". ";
            printEquipment(&dataperalatan[i]); 
        }
    }    

    cout << "Masukkan Nomor Peralatan yang Akan Diedit: ";
    cin >> nomorEdit;

    if (nomorEdit >= 1 && nomorEdit <= 100 && !dataperalatan[nomorEdit - 1].name.empty()) {
        string nama, kategori;
        cin.ignore();
        cout << "Masukkan Nama Peralatan Baru: ";
        getline(cin, nama);
        cout << "Masukkan Kategori Peralatan Baru: ";
        getline(cin, kategori);
        dataperalatan[nomorEdit - 1].name = nama;
        setEquipmentCategory(dataperalatan[nomorEdit - 1], kategori); 
        cout << "Peralatan berhasil diupdate." << endl;
    } else {
        cout << "Nomor peralatan tidak valid atau data peralatan tidak ada." << endl;
    }
}


int main() {
    Equipment dataperalatan[100];
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
                cin.ignore();
                displayEquipment(dataperalatan, 0); 
                break;
            case 2:
                cin.ignore();
                addEquipment(dataperalatan);
                break;
            case 3:
                cin.ignore();
                deleteEquipment(dataperalatan);
                break;
            case 4:
                cin.ignore();
                editEquipment(dataperalatan);
                break;
            case 5:
                cin.ignore();
                perulangan = 3;
                break;
            default:
                cin.ignore();
                cout << "Pilihan Tidak Ada" << endl;
                break;
        }
    }

    cout << "Program selesai." << endl;
    return 0;
}
