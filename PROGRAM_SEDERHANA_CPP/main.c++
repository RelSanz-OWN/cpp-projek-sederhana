#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

struct Rekening {
    string nama;
    string noRekening;
    double saldo;
};

void tampilkanMenu() {
    cout << "\n=== MENU PERBANKAN ===" << endl;
    cout << "1. Cek Saldo" << endl;
    cout << "2. Topup/Isi Saldo" << endl;
    cout << "3. Penarikan" << endl;
    cout << "4. Keluar" << endl;
    cout << "Pilih menu (1-4): ";
}

void cekSaldo(Rekening &akun) {
    cout << fixed << setprecision(2);
    cout << "\n=== INFORMASI SALDO ===" << endl;
    cout << "Nama: " << akun.nama << endl;
    cout << "No. Rekening: " << akun.noRekening << endl;
    cout << "Saldo saat ini: Rp " << akun.saldo << endl;
}

void topupSaldo(Rekening &akun) {
    double jumlah;
    cout << "\n=== TOPUP SALDO ===" << endl;
    cout << "Masukkan jumlah topup: Rp ";
    cin >> jumlah;
    
    if (jumlah > 0) {
        akun.saldo += jumlah;
        cout << "Topup berhasil!" << endl;
        cout << "Saldo baru: Rp " << akun.saldo << endl;
    } else {
        cout << "Jumlah topup tidak valid!" << endl;
    }
}

void penarikan(Rekening &akun) {
    double jumlah;
    cout << "\n=== PENARIKAN ===" << endl;
    cout << "Masukkan jumlah penarikan: Rp ";
    cin >> jumlah;
    
    if (jumlah > 0 && jumlah <= akun.saldo) {
        akun.saldo -= jumlah;
        cout << "Penarikan berhasil!" << endl;
        cout << "Saldo baru: Rp " << akun.saldo << endl;
    } else if (jumlah > akun.saldo) {
        cout << "Saldo tidak mencukupi!" << endl;
    } else {
        cout << "Jumlah penarikan tidak valid!" << endl;
    }
}

int main() {
    Rekening akunSaya = {"John Doe", "1234567890", 1000000.00};
    int pilihan;
    bool keluar = false;
    
    cout << "=== SELAMAT DATANG DI BANK SEDERHANA ===" << endl;
    
    while (!keluar) {
        tampilkanMenu();
        cin >> pilihan;
        
        switch(pilihan) {
            case 1:
                cekSaldo(akunSaya);
                break;
            case 2:
                topupSaldo(akunSaya);
                break;
            case 3:
                penarikan(akunSaya);
                break;
            case 4:
                keluar = true;
                break;
            default:
                cout << "Pilihan tidak valid!" << endl;
        }
    }
    
    cout << "Terima kasih telah menggunakan layanan kami!" << endl;
    return 0;
}