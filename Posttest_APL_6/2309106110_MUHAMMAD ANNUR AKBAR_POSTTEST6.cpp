#include <iostream>
#include <algorithm>
#include <vector>
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

void printEquipment(const Equipment& equipment) {
   cout << "Nama Peralatan: " << equipment.name << " (Kategori: " << equipment.category.name << ")" << endl;
}

void setEquipmentCategory(Equipment& equipment, const string& newCategory) {
   equipment.category.name = newCategory;
   cout << "Kategori peralatan berhasil diubah menjadi: " << newCategory << endl;
}

void displayEquipment(const vector<Equipment>& dataperalatan, int perulangan) {
   cout << "Daftar Peralatan:" << endl;

   if (dataperalatan.empty()) {
       cout << "Data Belum Ada" << endl;
   } else {
       for (int i = 0; i < dataperalatan.size(); ++i) {
           cout << i + 1 << ". ";
           printEquipment(dataperalatan[i]);
       }
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

void addEquipment(vector<Equipment>& dataperalatan) {
   string nama, kategori;
   cout << "Masukkan Nama Peralatan: ";
   getline(cin, nama);
   cout << "Masukkan Kategori Peralatan: ";
   getline(cin, kategori);

   Equipment newEquipment;
   newEquipment.name = nama;
   newEquipment.category.name = kategori;
   dataperalatan.push_back(newEquipment);
}

void deleteEquipment(vector<Equipment>& dataperalatan) {
   for (int i = 0; i < dataperalatan.size(); ++i) {
       cout << i + 1 << ". ";
       printEquipment(dataperalatan[i]);
   }

   int nomor;
   cout << "Masukkan Nomor Peralatan yang Akan Dihapus: ";
   cin >> nomor;

   if (nomor >= 1 && nomor <= dataperalatan.size()) {
       dataperalatan.erase(dataperalatan.begin() + nomor - 1);
       cout << "Peralatan berhasil dihapus." << endl;
   } else {
       cout << "Nomor peralatan tidak valid atau data peralatan tidak ada." << endl;
   }
}

void editEquipment(vector<Equipment>& dataperalatan) {
   int nomorEdit;

   for (int i = 0; i < dataperalatan.size(); ++i) {
       cout << i + 1 << ". ";
       printEquipment(dataperalatan[i]);
   }    

   cout << "Masukkan Nomor Peralatan yang Akan Diedit: ";
   cin >> nomorEdit;

   if (nomorEdit >= 1 && nomorEdit <= dataperalatan.size()) {
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

bool compareEquipmentNameDesc(const Equipment& a, const Equipment& b) {
   return a.name > b.name;
}

bool compareEquipmentCategoryAsc(const Equipment& a, const Equipment& b) {
   return a.category.name < b.category.name;
}

void sortEquipmentByNameDesc(vector<Equipment>& dataperalatan) {
   sort(dataperalatan.begin(), dataperalatan.end(), compareEquipmentNameDesc);
   cout << "Data peralatan berhasil diurutkan berdasarkan nama secara descending." << endl;
}

void sortEquipmentByCategoryAsc(vector<Equipment>& dataperalatan) {
   sort(dataperalatan.begin(), dataperalatan.end(), compareEquipmentCategoryAsc);
   cout << "Data peralatan berhasil diurutkan berdasarkan kategori secara ascending." << endl;
}

void sortEquipmentByNameLength(vector<Equipment>& dataperalatan) {
   sort(dataperalatan.begin(), dataperalatan.end(), [](const Equipment& a, const Equipment& b) {
       return a.name.length() < b.name.length();
   });
   cout << "Data peralatan berhasil diurutkan berdasarkan panjang nama." << endl;
}

int linearSearchEquipmentNameascending(const vector<Equipment>& dataperalatan, const string& name) {
   for (int i = 0; i < dataperalatan.size(); ++i) {
       if (dataperalatan[i].name == name) {
           return i;
       }
   }
   return -1;
}

int binarySearchEquipmentCategoryDesc(const vector<Equipment>& dataperalatan, const string& category) {
   int left = 0, right = dataperalatan.size() - 1;
   while (left <= right) {
       int mid = left + (right - left) / 2;
       if (dataperalatan[mid].category.name == category) {
           return mid;
       } else if (dataperalatan[mid].category.name > category) {
           left = mid + 1;
       } else {
           right = mid - 1;
       }
   }
   return -1;
}

int main() {
   vector<Equipment> dataperalatan;
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
       cout << "5. Urutkan Peralatan" << endl;
       cout << "6. Cari Peralatan" << endl;
       cout << "7. EXIT" << endl;
       cout << "---------------------------" << endl;
       cout << "Masukkan Pilihan Anda:  ";
       cin >> pilih;

       switch (pilih) {
           case
           1:
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
               cout << "1. Urutkan Berdasarkan Nama Secara Descending" << endl;
               cout << "2. Urutkan Berdasarkan Kategori Secara Ascending" << endl;
               cout << "3. Urutkan Berdasarkan Panjang Nama" << endl;
               cout << "Masukkan Pilihan: ";
               int sortChoice;
               cin >> sortChoice;
               switch (sortChoice) {
                   case 1:
                       sortEquipmentByNameDesc(dataperalatan);
                       break;
                   case 2:
                       sortEquipmentByCategoryAsc(dataperalatan);
                       break;
                   case 3:
                       sortEquipmentByNameLength(dataperalatan);
                       break;
                   default:
                       cout << "Pilihan tidak valid." << endl;
                       break;
               }
               break;
           case 6:
               cin.ignore();
               cout << "1. Cari Peralatan Berdasarkan Nama (Data Terurut Ascending)" << endl;
               cout << "2. Cari Peralatan Berdasarkan Kategori (Data Terurut Descending)" << endl;
               cout << "Masukkan Pilihan: ";
               int searchChoice;
               cin >> searchChoice;
               if (searchChoice == 1) {
                   string name;
                   cout << "Masukkan Nama Peralatan: ";
                   cin.ignore();
                   getline(cin, name);
                   sort(dataperalatan.begin(), dataperalatan.end(), [](const Equipment& a, const Equipment& b) {
                       return a.name < b.name;
                   });
                   int index = linearSearchEquipmentNameascending(dataperalatan, name);
                   if (index == -1) {
                       cout << "Peralatan dengan nama \"" << name << "\" tidak ditemukan." << endl;
                   } else {
                       cout << "Peralatan ditemukan pada indeks " << index << ": " << endl;
                       printEquipment(dataperalatan[index]);
                   }
               } else if (searchChoice == 2) {
                   string category;
                   cout << "Masukkan Kategori Peralatan: ";
                   cin.ignore();
                   getline(cin, category);
                   sort(dataperalatan.begin(), dataperalatan.end(), [](const Equipment& a, const Equipment& b) {
                       return a.category.name > b.category.name;
                   });
                   int index = binarySearchEquipmentCategoryDesc(dataperalatan, category);
                   if (index == -1) {
                       cout << "Peralatan dengan kategori \"" << category << "\" tidak ditemukan." << endl;
                   } else {
                       cout << "Peralatan ditemukan pada indeks " << index << ": " << endl;
                       printEquipment(dataperalatan[index]);
                   }
               } else {
                   cout << "Pilihan tidak valid." << endl;
               }
               break;
           case 7:
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