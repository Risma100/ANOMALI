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