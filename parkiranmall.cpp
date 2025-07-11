#include <iostream>
#include <cstring>
#include <cstdlib>
#include <conio.h>
#include <windows.h>
#include <cctype>
using namespace std;

struct Kendaraan {
    char plat[10];
    char jenis[10];
    int jamMasuk;
    Kendaraan* next;
};

struct RiwayatKeluar {
    char plat[10];
    char jenis[10];
    int jamMasuk;
    int jamKeluar;
    int biaya;
    RiwayatKeluar* next;
};

void clearScreen() {
    system("cls");
}

void toLowerCase(char str[]) {
    for (int i = 0; str[i]; i++) str[i] = tolower(str[i]);
}

void tambahRiwayatMasuk(Kendaraan*& riwayat, const char* plat, const char* jenis, int jamMasuk) {
    Kendaraan* baru = new Kendaraan;
    strcpy(baru->plat, plat);
    strcpy(baru->jenis, jenis);
    baru->jamMasuk = jamMasuk;
    baru->next = nullptr;

    if (riwayat == nullptr) riwayat = baru;
    else {
        Kendaraan* temp = riwayat;
        while (temp->next != nullptr) temp = temp->next;
        temp->next = baru;
    }
}

void tambahRiwayatKeluar(RiwayatKeluar*& riwayat, const char* plat, const char* jenis, int jamMasuk, int jamKeluar, int biaya) {
    RiwayatKeluar* baru = new RiwayatKeluar;
    strcpy(baru->plat, plat);
    strcpy(baru->jenis, jenis);
    baru->jamMasuk = jamMasuk;
    baru->jamKeluar = jamKeluar;
    baru->biaya = biaya;
    baru->next = nullptr;

    if (riwayat == nullptr) riwayat = baru;
    else {
        RiwayatKeluar* temp = riwayat;
        while (temp->next != nullptr) temp = temp->next;
        temp->next = baru;
    }
}

void parkirMasuk(Kendaraan*& head, Kendaraan*& riwayatMasuk) {
    char plat[10], jenis[10];
    int jam;
    clearScreen();
    cout << "===== MENU PARKIR MASUK =====\n";
    cout << "Plat Nomor          : "; cin >> plat;
    cout << "Jenis (mobil/motor) : "; cin >> jenis;
    toLowerCase(jenis);
    cout << "Jam Masuk (0-23)    : "; cin >> jam;

    Kendaraan* baru = new Kendaraan;
    strcpy(baru->plat, plat);
    strcpy(baru->jenis, jenis);
    baru->jamMasuk = jam;
    baru->next = nullptr;

    if (head == nullptr) head = baru;
    else {
        Kendaraan* temp = head;
        while (temp->next != nullptr) temp = temp->next;
        temp->next = baru;
    }

    tambahRiwayatMasuk(riwayatMasuk, plat, jenis, jam);

    cout << "\nKendaraan " << plat << " berhasil masuk parkiran.\n";
    cout << "Tekan 'k' untuk kembali ke menu...";
    while (getch() != 'k');
}

void parkirKeluar(Kendaraan*& head, RiwayatKeluar*& riwayatKeluar) {
    char plat[10];
    int jamKeluar;
    clearScreen();
    cout << "===== MENU PARKIR KELUAR =====\n";
    cout << "Plat Nomor         : "; cin >> plat;
    cout << "Jam Keluar (0-23)  : "; cin >> jamKeluar;

    Kendaraan* temp = head;
    Kendaraan* prev = nullptr;

    while (temp != nullptr && strcmp(temp->plat, plat) != 0) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == nullptr) {
        cout << "\nKendaraan tidak ditemukan.\n";
    } else {
        int durasi = jamKeluar - temp->jamMasuk;
        if (durasi <= 0) durasi += 24;

        int tarif;
        if (strcmp(temp->jenis, "mobil") == 0) tarif = 5000;
        else if (strcmp(temp->jenis, "motor") == 0) tarif = 3000;
        else tarif = 4000;

        int biaya = durasi * tarif;

        if (prev == nullptr) head = temp->next;
        else prev->next = temp->next;

        cout << "\nKendaraan " << temp->plat << " keluar dari parkiran.\n";
        cout << "Jenis         : " << temp->jenis << endl;
        cout << "Durasi parkir : " << durasi << " jam\n";
        cout << "Tarif per jam : Rp" << tarif << endl;
        cout << "Total Biaya   : Rp" << biaya << endl;

        tambahRiwayatKeluar(riwayatKeluar, temp->plat, temp->jenis, temp->jamMasuk, jamKeluar, biaya);
        delete temp;
    }

    cout << "\nTekan 'k' untuk kembali ke menu...";
    while (getch() != 'k');
}

void tampilParkiran(Kendaraan* head) {
    clearScreen();
    cout << "===== DAFTAR KENDARAAN PARKIR =====\n";
    if (head == nullptr) {
        cout << "Parkiran kosong.\n";
    } else {
        Kendaraan* temp = head;
        while (temp != nullptr) {
            cout << "- Plat : " << temp->plat
                 << ", Jenis : " << temp->jenis
                 << ", Jam Masuk : " << temp->jamMasuk << endl;
            temp = temp->next;
        }
    }
    cout << "\nTekan 'k' untuk kembali ke menu...";
    while (getch() != 'k');
}

void tampilRiwayatMasuk(Kendaraan* riwayat) {
    clearScreen();
    cout << "===== RIWAYAT MASUK =====\n";
    if (riwayat == nullptr) {
        cout << "Tidak ada riwayat masuk.\n";
    } else {
        Kendaraan* temp = riwayat;
        while (temp != nullptr) {
            cout << "- Plat : " << temp->plat
                 << ", Jenis : " << temp->jenis
                 << ", Jam Masuk : " << temp->jamMasuk << endl;
            temp = temp->next;
        }
    }
    cout << "\nTekan 'k' untuk kembali ke menu...";
    while (getch() != 'k');
}

void tampilRiwayatKeluar(RiwayatKeluar* riwayat) {
    clearScreen();
    cout << "===== RIWAYAT KELUAR =====\n";
    if (riwayat == nullptr) {
        cout << "Tidak ada riwayat keluar.\n";
    } else {
        RiwayatKeluar* temp = riwayat;
        while (temp != nullptr) {
            cout << "- Plat : " << temp->plat
                 << ", Jenis : " << temp->jenis
                 << ", Masuk : " << temp->jamMasuk
                 << ", Keluar : " << temp->jamKeluar
                 << ", Biaya : Rp" << temp->biaya << endl;
            temp = temp->next;
        }
    }
    cout << "\nTekan 'k' untuk kembali ke menu...";
    while (getch() != 'k');
}

void hapusSemua(Kendaraan*& head) {
    while (head != nullptr) {
        Kendaraan* temp = head;
        head = head->next;
        delete temp;
    }
}

void hapusSemuaRiwayatKeluar(RiwayatKeluar*& head) {
    while (head != nullptr) {
        RiwayatKeluar* temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    Kendaraan* head = nullptr;
    Kendaraan* riwayatMasuk = nullptr;
    RiwayatKeluar* riwayatKeluar = nullptr;
    int pilihan;
    char input;

    do {
        clearScreen();
        cout << "=========================================\n";
        cout << "       SISTEM PARKIRAN MALL JAWA\n";
        cout << "=========================================\n";
        cout << "1. Parkir Masuk\n";
        cout << "2. Parkir Keluar\n";
        cout << "3. Lihat Kendaraan Saat Ini\n";
        cout << "4. Lihat Riwayat Masuk\n";
        cout << "5. Lihat Riwayat Keluar\n";
        cout << "0. Keluar\n";
        cout << "Pilih Menu: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                parkirMasuk(head, riwayatMasuk);
                break;
            case 2:
                parkirKeluar(head, riwayatKeluar);
                break;
            case 3:
                tampilParkiran(head);
                break;
            case 4:
                tampilRiwayatMasuk(riwayatMasuk);
                break;
            case 5:
                tampilRiwayatKeluar(riwayatKeluar);
                break;
            case 0:
                clearScreen();
                cout << "\nTerima kasih telah menggunakan sistem ini.\n";
                cout << "================================";
                cout << "\nNama Kelompok : Group ANOMALI";
                cout << "\n================================";
                cout << "\nNama Anggota : ";
                cout << "\nFEBIA NURWULAN C030324067\n";
                cout << "RISMA          C030324106\n";
                break;
            default:
                cout << "\nPilihan tidak valid.\n";
                cout << "Tekan 'k' untuk kembali ke menu...";
                while ((input = getch()) != 'k');
        }
    } while (pilihan != 0);

    hapusSemua(head);
    hapusSemua(riwayatMasuk);
    hapusSemuaRiwayatKeluar(riwayatKeluar);
    return 0;
}