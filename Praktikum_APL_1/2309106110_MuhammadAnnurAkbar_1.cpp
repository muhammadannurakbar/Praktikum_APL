#include<iostream>
using namespace std;

int masuk(){
    string nama;
    string katasandi;
    int percobaanlogin = 0;

    while (percobaanlogin < 3)
    {
        cout << "Masukkan nama anda : ";
        cin >> nama;
        cout << "Masukkan password anda :";
        cin >> katasandi;

        if (nama == "Akbar" && katasandi == "777")
        {
            cout << "Selamat datang di program pengubah suhu\n";
            break;
        }
        else
        {
            cout << "Password salah. Silahkan coba lagi\n" << "\n";
            percobaanlogin++;
        }
    }
    if (percobaanlogin == 3)
    {
            cout << "Anda sudah salah 3x. Program berhenti";
            return 0;
    }
    return 0;
}

int menu(){
    string menu;
    double kelvin, reamur, fahrenheit, celcius;

    cout << "-----------------------------------" << endl;
    cout << "masukan menu suhu yang ingin diubah" << endl;
    cout << "1. kelvin" << endl;
    cout << "2. reamur" << endl;
    cout << "3. fahrenheit" << endl;
    cout << "4. celcius" << endl;
    cout << "masukan menu anda :" <<endl;
    cout << "-----------------------------------" << endl;
    cin >> menu;

    if(menu == "1"){
         cout << "masukan suhu kelvin yang akan diubah : " << endl;
        cin >> kelvin;
        celcius = kelvin - 273;
        reamur = (kelvin - 273 ) * 4 / 5;
        fahrenheit = (kelvin - 273) * 9 / 5 + 32;
        cout << kelvin << " Kelvin = " << celcius << " suhu Celcius" << endl;
        cout << kelvin << " Kelvin = " << reamur << " suhu Reamur" << endl;
        cout << kelvin << " Kelvin = " << fahrenheit << " suhu Fahrenheit" << endl;
    } else if(menu == "2"){
         cout << "masukkan suhu reamur yang akan diubah : " << endl;
        cin >> reamur;
        celcius = reamur * 5 / 4;
        kelvin = reamur * 5 / 4 + 32;
        fahrenheit = reamur * 9 / 4 + 32;
        cout << reamur << " Reamur = " << celcius << " suhu Celcius" << endl;
        cout << reamur << " Reamur = " << kelvin << " suhu Kelvin" << endl;
        cout << reamur << " Reamur = " << fahrenheit << " suhu Fahrenheit" << endl;
    }else if(menu == "3"){
         cout << "masukkan suhu fahrenheit yang akan diubah : " << endl;
        cin >> fahrenheit;
        celcius = (fahrenheit - 32) * 5 / 9;
        reamur = (fahrenheit - 32) * 4 / 9;
        kelvin = (fahrenheit - 32) * 5 / 9 + 273;
        cout << fahrenheit << " Fahrenheit = " << celcius << " suhu Celcius" << endl;
        cout << fahrenheit << " Fahrenheit = " << reamur << " suhu Reamur" << endl;
        cout << fahrenheit << " Fahrenheit = " << kelvin << " suhu Kelvin" << endl;
    }else if(menu == "4"){
        cout << "masukkan suhu celcius yang akan diubah : " << endl;
        cin >> celcius;
        kelvin = celcius + 273;
        reamur = celcius * 4 / 5;
        fahrenheit = (celcius * 9 / 5) + 32;
        cout << celcius << " Celcius = " << kelvin << " suhu Kelvin" << endl;
        cout << celcius << " Celcius = " << reamur << " suhu Reamur" << endl;
        cout << celcius << " Celcius = " << fahrenheit << " suhu Fahrenheit" << endl;
    }else{
        cout << "menu tidak ada dalam pilihan, silahkan coba lagi";
    }
    return 0;

}

int main(){
    string lanjut;
    masuk();
    do {
        menu();
        cout << "Lanjut? <y/n> : ";
        cin >> lanjut;
    } while (lanjut == "y");
    cout << "Pengubah suhu Selesai" << endl;
}