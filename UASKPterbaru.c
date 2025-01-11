#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int slotmobildosen[5] = {0, 0, 0, 0, 0}; // 0 = kosong, 1 = terisi
int slotmotordosen[13] = {0}; // 13 slot parkir motor dosen
int slotmotormahasiswa[20] = {0}; // 20 slot parkir motor mahasiswa
char tempatparkirmobildosen[5][5]; // Array untuk menyimpan tempat parkir mobil dosen berdasarkan ID
char tempatparkirmotordosen[13][5];
char tempatparkirmahasiswa[20][5]; // Array untuk menyimpan tempat parkir motor mahasiswa berdasarkan ID
char IDparkirMahasiswa[20][20]; // Menyimpan ID yang parkir di motor mahasiswa
char IDparkirMobildosen[5][5]; // Menyimpan ID parkir mobil dosen
char IDparkirMotordosen[13][13]; // Menyimpan ID parkir motor dosen

#define jumlah_slotmobildosen 5
#define jumlah_slotmotordosen 13
#define jumlah_slotmotormahasiswa 20

//Fungsi untuk mengecek pengguna berdasarkan ID
void cekpengguna(char* ID, char* user) {
    char line[100], kategorinamafile[20];
    char IDpengguna[20], nama[50];
    FILE *file;
    int ditemukan = 0;

    //Deteksi tipe ID (Dosen atau Mahasiswa)
    if (strncmp(ID, "00", 2) == 0) {
        strcpy(kategorinamafile, "dosen.txt");
        strcpy(user, "Dosen");
    } else if (ID[0] == 'L') {
        strcpy(kategorinamafile, "mahasiswa.txt");
        strcpy(user, "Mahasiswa");
    } else {
        printf("Format ID tidak valid.\n");
        exit(1);
    }

    //Buka file sesuai tipe
    file = fopen(kategorinamafile, "r");
    if (file == NULL) {
        printf("File %s tidak ditemukan.\n", kategorinamafile);
        exit(1);
    }

    //Cari ID dalam file
    while (fgets(line, sizeof(line), file)) {
        sscanf(line, "%[^ | ] | %[^\n]", IDpengguna, nama); // Pisahkan ID dan Nama
        if (strcmp(IDpengguna, ID) == 0) {
            ditemukan = 1;
            break;
        }
    }
    fclose(file);

    //Tampilkan hasil
    if (!ditemukan) {
        printf("ID tidak ditemukan dalam data %s.\n", user);
        exit(1);
    } else {
        printf("Kategori: %s\n", user);
        printf("Nama: %s\n", nama);
        printf("ID: %s\n", ID);
    }
}

// Fungsi untuk memilih slot parkir dosen
void masukparkirdosen(char* ID) {
    char kategorikendaraan[10];
    char tempatparkir[5];
    char jammasuk[10];
    int valid = 0; // Flag untuk validasi input

    printf("Masukkan Jam masuk anda(--:--): ");
    scanf("%s", jammasuk);

    printf("Silakan masukkan kategori kendaraan Anda (mobil/motor): ");
    scanf("%s", kategorikendaraan);

    if (strcmp(kategorikendaraan, "mobil") == 0) {
        do {
        printf("Berikut tempat parkir mobil dosen yang tersedia:\n");
        for (int i = 0; i < 5; i++) {
            if (slotmobildosen[i] == 0) {
                printf("-A%d ", i + 1);
            }
        }

        printf("\nSilakan pilih tempat parkir mobil dosen (Contoh: A1): ");
        scanf("%s", tempatparkir);


    // Cek apakah input berada dalam rentang A1 - A5
        if (tempatparkir[0] == 'A' && strlen(tempatparkir) > 1) {
            int index = atoi(&tempatparkir[1]); // Konversi angka setelah 'A' menjadi integer
            if (index >= 1 && index <= 5) {
                if (slotmobildosen[index - 1] == 0) { // Cek apakah slot kosong
                    valid = 1; // Input valid
                    slotmobildosen[index - 1] = 1; // Tandai slot sebagai terisi
                    strcpy(IDparkirMobildosen[index - 1], ID); // Simpan ID pengguna
                    printf("Anda telah memilih tempat parkir A%d pada jam %s.\n", index, jammasuk);
                } else {
                    printf("Tempat parkir A%d sudah ditempati. Silakan pilih tempat lain.\n", index);
                }
            } else {
                printf("Input tidak valid. Tempat parkir harus antara A1 - A5.\n");
            }
        } else {
            printf("Input tidak valid. Format harus A diikuti angka (contoh: A1 atau A5).\n");
        }
    } while (!valid); // Ulangi hingga input valid

    } else if (strcmp(kategorikendaraan, "motor") == 0) {
        do {
        printf("Berikut tempat parkir motor dosen yang tersedia:\n");
        for (int i = 0; i < 13; i++) {
            if (slotmotordosen[i] == 0) {
                printf("-B%d ", i + 1);
            }
        }

        printf("\nSilakan pilih tempat parkir motor dosen (Contoh: B1): ");
        scanf("%s", tempatparkir);

    // Cek apakah input berada dalam rentang B1 - B13
        if (tempatparkir[0] == 'B' && strlen(tempatparkir) > 1) {
            int index = atoi(&tempatparkir[1]); // Konversi angka setelah 'C' menjadi integer
            if (index >= 1 && index <= 13) {
                if (slotmotordosen[index - 1] == 0) { // Cek apakah slot kosong
                    valid = 1; // Input valid
                    slotmotordosen[index - 1] = 1; // Tandai slot sebagai terisi
                    strcpy(IDparkirMotordosen[index - 1], ID); // Simpan ID pengguna
                    printf("Anda telah memilih tempat parkir B%d pada jam %s.\n", index, jammasuk);
                } else {
                    printf("Tempat parkir B%d sudah ditempati. Silakan pilih tempat lain.\n", index);
                }
            } else {
                printf("Input tidak valid. Tempat parkir harus antara B1 - B13.\n");
            }
        } else {
            printf("Input tidak valid. Format harus B diikuti angka (contoh: B1 atau B13).\n");
        }
    } while (!valid); // Ulangi hingga input valid
    }
}

// Fungsi untuk memilih slot parkir mahasiswa
void masukparkirmahasiswa(char* ID) {
    char tempatparkir[5];
    char jammasuk[10];

    printf("Masukkan Jam masuk anda(--:--): ");
    scanf("%s", jammasuk);

   int valid = 0; // Flag untuk validasi input

    do {
        printf("Berikut tempat parkir motor mahasiswa yang tersedia:\n");
        for (int i = 0; i < 20; i++) {
            if (slotmotormahasiswa[i] == 0) {
                printf("-C%d ", i + 1);
            }
        }
    printf("\nSilahkan pilih tempat parkir motor mahasiswa (Contoh: C1 atau C10): ");
    scanf("%s", tempatparkir);


    // Cek apakah input berada dalam rentang C1 - C20
        if (tempatparkir[0] == 'C' && strlen(tempatparkir) > 1) {
            int index = atoi(&tempatparkir[1]); // Konversi angka setelah 'C' menjadi integer
            if (index >= 1 && index <= 20) {
                if (slotmotormahasiswa[index - 1] == 0) { // Cek apakah slot kosong
                    valid = 1; // Input valid
                    slotmotormahasiswa[index - 1] = 1; // Tandai slot sebagai terisi
                    strcpy(IDparkirMahasiswa[index - 1], ID); // Simpan ID pengguna
                    printf("Anda telah memilih tempat parkir C%d pada jam %s.\n", index, jammasuk);
                } else {
                    printf("Tempat parkir C%d sudah ditempati. Silakan pilih tempat lain.\n", index);
                }
            } else {
                printf("Input tidak valid. Tempat parkir harus antara C1 - C20.\n");
            }
        } else {
            printf("Input tidak valid. Format harus C diikuti angka (contoh: C1 atau C10).\n");
        }
    } while (!valid); // Ulangi hingga input valid

}

// Fungsi untuk keluar parkir (mengosongkan slot parkir)
void keluarparkir(char* user) {
    int ditemukan = 0;
    
        printf("Masukkan ID Anda (NIDN untuk Dosen || NIM untuk Mahasiswa): ");
        char ID[20];
        scanf("%s", ID);
        cekpengguna(ID, user);

    if (strcmp(user, "Dosen") == 0) {
        // Pilih kategori kendaraan untuk keluar parkir
        printf("Masukkan kategori kendaraan yang ingin keluar (mobil/motor): ");
        char kategorikendaraan[10];
        scanf("%s", kategorikendaraan);

        if (strcmp(kategorikendaraan, "mobil") == 0) {
            for (int i = 0; i < jumlah_slotmobildosen; i++) {
                if (strcmp(IDparkirMobildosen[i], ID) == 0) {
                    slotmobildosen[i] = 0; // Kosongkan slot parkir
                    strcpy(IDparkirMobildosen[i], ""); // Kosongkan ID yang parkir
                    printf("Tempat parkir A%d telah dikosongkan.\n", i + 1);
                    ditemukan = 1;
                    break;
                }
            } if (!ditemukan) {
                printf("ID tidak ditemukan pada tempat parkir mobil dosen.\n");
            }  
        } else if (strcmp(kategorikendaraan, "motor") == 0) {
            for (int i = 0; i < jumlah_slotmotordosen; i++) {
                if (strcmp(IDparkirMotordosen[i], ID) == 0) {
                    slotmotordosen[i] = 0; // Kosongkan slot parkir
                    strcpy(IDparkirMotordosen[i], ""); // Kosongkan ID yang parkir
                    printf("Tempat parkir B%d telah dikosongkan.\n", i + 1);
                    ditemukan = 1;
                    break;
                }
            } if (!ditemukan) {
                printf("ID tidak ditemukan pada tempat parkir motor dosen.\n");
            }
        }
    } else if (strcmp(user, "Mahasiswa") == 0) {
        for (int i = 0; i < jumlah_slotmotormahasiswa; i++) {
            if (strcmp(IDparkirMahasiswa[i], ID) == 0) {
                slotmotormahasiswa[i] = 0; // Kosongkan slot parkir
                strcpy(IDparkirMahasiswa[i], ""); // Kosongkan ID yang parkir
                printf("Tempat parkir C%d telah dikosongkan.\n", i + 1);
                ditemukan = 1;
                break;
            }
        } if (!ditemukan)
        {
            printf("ID tidak ditemukan pada tempat parkir motor mahasiswa.\n");
        }
    }
}

void lihatstatusparkir() {
    printf("Status Tempat Parkir Mobil Dosen:\n");
    for (int i = 0; i < 5; i++) {
        if (slotmobildosen[i] == 0) {
            printf("A%d: Kosong\n", i + 1);
        } else {
            printf("A%d: Terisi oleh ID %s\n", i + 1, IDparkirMobildosen[i]);
        }
    }

    printf("\nStatus Tempat Parkir Motor Dosen:\n");
    for (int i = 0; i < 13; i++) {
        if (slotmotordosen[i] == 0) {
            printf("B%d: Kosong\n", i + 1);
        } else {
            printf("B%d: Terisi oleh ID %s\n", i + 1, IDparkirMotordosen[i]);
        }
    }

    printf("\nStatus Tempat Parkir Motor Mahasiswa:\n");
    for (int i = 0; i < 20; i++) {
        if (slotmotormahasiswa[i] == 0) {
            printf("C%d: Kosong\n", i + 1);
        } else {
            printf("C%d: Terisi oleh ID %s\n", i + 1, IDparkirMahasiswa[i]);
        }
    }
}


int main() {
    char ID[30];
    char user[10];
    int pilihan;
    char jammasuk[10];

    while (1) {
        printf("\n**Menu Parkir**\n");
        printf("1. Masuk Parkir\n");
        printf("2. Keluar Parkir\n");
        printf("3. Lihat Status Parkir Terkini\n");
        printf("4. Exit\n");
        printf("Silakan pilih menu sesuai nomor yang tertera: ");
        scanf("%d", &pilihan);

        switch (pilihan) {
            case 1:
                printf("Masukkan ID (NIDN untuk Dosen || NIM untuk Mahasiswa): ");
                scanf("%s", ID);

                cekpengguna(ID, user); // Cek pengguna dan tentukan kategori
                if (strcmp(user, "Dosen") == 0) {
                    masukparkirdosen(ID);
                } else if (strcmp(user, "Mahasiswa") == 0) {
                    masukparkirmahasiswa(ID);
                }
                break;

            case 2:
                keluarparkir(user);
                break;

            case 3:
                lihatstatusparkir();
                break;

            case 4:
                printf("Anda telah keluar dari program sistem parkir.\n");
                exit(0);

            default:
                printf("Pilihan tidak valid. Silakan coba lagi.\n");
        }
    }

    return 0;
}
