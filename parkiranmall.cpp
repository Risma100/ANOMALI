#include <iostream>
#include <cstring>
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