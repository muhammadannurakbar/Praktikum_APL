#include <iostream>

using namespace std;

int main() {
    string dataperalatan[100], nama,user,pw;
    int pilih,size, perulangan =0 ;
    while ( perulangan < 3)
    {
        cout << "Masukkan Username Terlebih Dahulu: ";
        getline(cin, user);
        cout << "Masukkan Password Terlebih Dahulu: ";
        getline(cin, pw);
        if (user == "Muhammad Annur Akbar" && pw == "2309106110"){

            while(perulangan < 3) {
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
                        cout << "Daftar Peralatan:" << endl;

                        if (!dataperalatan[0].empty()) {
                            for (int i = 0; i < 100; ++i) {
                            if (!dataperalatan[i].empty()) {
                                cout << i + 1 << ". " << dataperalatan[i] << endl;}
                            }
                        cout <<"-------------------"<< endl;
                        
                        }else{
                            cout << "Data Belum Ada" << endl;

                        }
                        
                        break;
                    case 2:
                        
                        cout << "Masukkan Nama Peralatan: ";
                        cin >> nama;
                        for (int i = 0; i < 100; ++i) {
                            if (dataperalatan[i].empty()) {
                                dataperalatan[i] = nama;
                                break;
                            }
                        }
                        break;
                    case 3:
                        cout << "Masukkan Nomor Peralatan yang Akan Dihapus: ";
                        int nomor;
                        cin >> nomor;
                        if (nomor >= 1 && nomor <= 100 && !dataperalatan[nomor - 1].empty()) {
                            dataperalatan[nomor - 1] = "";
                            cout << "Peralatan berhasil dihapus." << endl;
                        } else {
                            cout << "Nomor peralatan tidak valid atau data peralatan tidak ada." << endl;
                        }
                        break;
                    case 4:
                        cout << "Masukkan Nomor Peralatan yang Akan Diedit: ";
                        int nomorEdit;
                        cin >> nomorEdit;
                        if (nomorEdit >= 1 && nomorEdit <= 100 && !dataperalatan[nomorEdit - 1].empty()) {
                            cout << "Masukkan Nama Peralatan Baru: ";
                            cin >> nama;
                            dataperalatan[nomorEdit - 1] = nama;
                            cout << "Peralatan berhasil diupdate." << endl;
                        } else {
                            cout << "Nomor peralatan tidak valid atau data peralatan tidak ada." << endl;
                        }
                        
                        break;
                    case 5:
                        perulangan = 3; 
                        break;
                    default:
                        cout << "Pilihan Tidak Ada" << endl;
                        break;
                }
            }
        }else {
            cout << "Username Atau Password SALAH"<<endl;
            perulangan++;
        }

    }
    cout << "Program selesai." << endl;
    return 0;
}
