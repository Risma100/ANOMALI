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