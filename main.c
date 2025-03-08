#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_HASTA 100
int i,j;

typedef struct {
    int gun;
    int ay;
    int yil;
} Yas;

typedef struct {
    float kucukTansiyon;
    float buyukTansiyon;
} Tansiyon;

typedef struct {
    char il[100];
    char ilce[100];
    char mahalle[100];
    char sokak[100];
    char kapiNO[10];
    unsigned short kat;
}Adres;

typedef struct {
    int siraNO;
    int belgeNO;
    char kimlik[11];
    Yas yas;
    char isim[100];
    char soyisim[100];
    Adres adres;
    char telefonNO[10];
    int oncelikDurumu;
    char cinsiyet[10];
    char sikayet[1000];
    float atesDegeri;
    float kiloDegeri;
    Tansiyon tansiyon;
    float sekerDegeri;
    char ilacAdi[100];
    char alerji[100];
    char operasyon[100];
} Hasta;

int yasHesapla(int gun, int ay, int yil) {
    time_t t = time(NULL);
    struct tm *bugun = localtime(&t);

    int simdiGun = bugun->tm_mday;
    int simdiAy = bugun->tm_mon + 1;
    int simdiYil = bugun->tm_year + 1900;

    int yas = simdiYil - yil;
    if (simdiAy < ay || (simdiAy == ay && simdiGun < gun)) {
        yas--;
    }
    return yas;
}

int BelgeNO() {
    return rand() % 10000;
}

void hastaSiralama(Hasta hastalar[], int hastaSayisi) {
    for (i = 0; i < hastaSayisi - 1; i++) {
        for (j = 0; j < hastaSayisi - i - 1; j++) {
            if (hastalar[j].oncelikDurumu < hastalar[j + 1].oncelikDurumu) {
                Hasta temp = hastalar[j];
                hastalar[j] = hastalar[j + 1];
                hastalar[j + 1] = temp;
            }
        }
    }
    for (i = 0; i < hastaSayisi; i++) {
        hastalar[i].siraNO = i + 1;
    }
}

void hastaEkle(Hasta *hasta, int hastaSayisi) {
    printf("Hasta Kimlik: ");
    scanf("%s", hasta->kimlik);

    printf("Hasta Ismi: ");
    scanf("%s", hasta->isim);

    printf("Hasta Soyismi: ");
    scanf("%s", hasta->soyisim);

    printf("Hasta Cinsiyeti (E/K): ");
    scanf("%s", hasta->cinsiyet);

    if (strcmp(hasta->cinsiyet, "e") == 0 || strcmp(hasta->cinsiyet, "E") == 0) {
        strcpy(hasta->cinsiyet, "Erkek");
    } else if (strcmp(hasta->cinsiyet, "k") == 0 || strcmp(hasta->cinsiyet, "K") == 0) {
        strcpy(hasta->cinsiyet, "Kadin");
    }

    printf("Dogum Tarihi : \n");
    printf("Yil: ");
    scanf("%d", &hasta->yas.yil);
    printf("Ay: ");
    scanf("%d", &hasta->yas.ay);
    printf("Gun: ");
    scanf("%d", &hasta->yas.gun);

    printf("Hasta Telefon No (Basinda 0 olmamali): ");
    scanf("%s", hasta->telefonNO);

    printf("Hasta Adresi: \n");
    printf("Il: ");
    scanf(" %[^\n]", hasta->adres.il);
    printf("Ilce: ");
    scanf(" %[^\n]", hasta->adres.ilce);
    printf("Mahalle: ");
    scanf(" %[^\n]", hasta->adres.mahalle);
    printf("Sokak/Cadde: ");
    scanf(" %[^\n]", hasta->adres.sokak);
    printf("No: ");
    scanf(" %[^\n]", hasta->adres.kapiNO);
    printf("Kat: ");
    scanf("%hu", &hasta->adres.kat);

    printf("Kullandigi ilac var mi? (E/H): ");
    char ilacVarMi;
    scanf(" %c", &ilacVarMi);
    if ((ilacVarMi == 'E')||(ilacVarMi == 'e')) {
        printf("Ilac Adi: ");
        scanf(" %[^\n]", hasta->ilacAdi);
    }
    printf("Alerjisi var mi? (E/H): ");
    char AlerjiVarMi;
    scanf(" %c", &AlerjiVarMi);
    if ((AlerjiVarMi == 'E')||(AlerjiVarMi == 'e')) {
        printf("Alerjileri: ");
        scanf(" %[^\n]", hasta->alerji);
    }
    printf("Operasyon gecirdi mi?(E/H): ");
    char operasyonGecirdiMi;
    scanf(" %c", &operasyonGecirdiMi);
    if ((operasyonGecirdiMi == 'E')||(operasyonGecirdiMi == 'e')) {
        printf("Operasyon Adi: ");
        scanf(" %[^\n]", hasta->operasyon);
    }

    printf("Hasta Hangi Sikayetle Geldi: ");
    scanf(" %[^\n]", hasta->sikayet);

    printf("Kilo Degeri: ");
    scanf("%f", &hasta->kiloDegeri);

    printf("Ates Degeri: ");
    scanf("%f", &hasta->atesDegeri);

    printf("Tansiyon Degeri:(Sifirlar dahil olarak giriniz) \n");
    printf("Buyuk: ");
    scanf("%f", &hasta->tansiyon.buyukTansiyon);
    printf("Kucuk: ");
    scanf("%f", &hasta->tansiyon.kucukTansiyon);

    if (hasta->atesDegeri > 38.0 || hasta->atesDegeri < 36.0 || hasta->tansiyon.buyukTansiyon >= 140.0 || hasta->tansiyon.buyukTansiyon <= 90.0 || hasta->tansiyon.kucukTansiyon >= 90.0 || hasta->tansiyon.kucukTansiyon <= 60.0) {
        hasta->oncelikDurumu = 3;
    } else {
        printf("Hasta Oncelik Durumu (1: En dusuk, 5: En yuksek): ");
        scanf("%d", &hasta->oncelikDurumu);
    }

    printf("Seker Degeri: ");
    scanf("%f", &hasta->sekerDegeri);

    hasta->belgeNO = BelgeNO();
    hasta->siraNO = hastaSayisi + 1;

    hastaSiralama(hasta, hastaSayisi);

    int hastaYasi=yasHesapla(hasta->yas.gun, hasta->yas.ay, hasta->yas.yil);
    printf("Hasta basariyla eklendi! Sira No: %d  Yas: %d\n", hasta->siraNO, hastaYasi);
}


void hastaListele(Hasta hastalar[], int *hastaSayisi) {
    if (*hastaSayisi == 0) {
        printf("Hic hasta kaydi bulunmamaktadir. Yeni hasta eklemelisiniz.\n");
        hastaEkle(&hastalar[*hastaSayisi], *hastaSayisi);
        (*hastaSayisi)++;
        return;
    }
    hastaSiralama(hastalar, *hastaSayisi);

    printf("\nHasta Listesi:\n");
    for (i = 0; i < *hastaSayisi; i++) {
        if(hastalar[i].yas.ay<10 && hastalar[i].yas.gun>=10){
            printf("PID|%d||%d||%s||%s^%s||%d0%d%d||%s||%s^%s^%s^%d^%s^%s||%s|\n",
                   hastalar[i].siraNO, hastalar[i].belgeNO, hastalar[i].kimlik,
                   hastalar[i].isim, hastalar[i].soyisim,
                   hastalar[i].yas.yil, hastalar[i].yas.ay, hastalar[i].yas.gun,
                   hastalar[i].cinsiyet, hastalar[i].adres.mahalle, hastalar[i].adres.sokak,hastalar[i].adres.kapiNO,hastalar[i].adres.kat, hastalar[i].adres.ilce,hastalar[i].adres.il, hastalar[i].telefonNO);
        }
        else if(hastalar[i].yas.ay<10 && hastalar[i].yas.gun<10){
            printf("PID|%d||%d||%s||%s^%s||%d0%d0%d||%s||%s^%s^%s^%d^%s^%s||%s|\n",
                   hastalar[i].siraNO, hastalar[i].belgeNO, hastalar[i].kimlik,
                   hastalar[i].isim, hastalar[i].soyisim,
                   hastalar[i].yas.yil, hastalar[i].yas.ay, hastalar[i].yas.gun,
                   hastalar[i].cinsiyet, hastalar[i].adres.mahalle, hastalar[i].adres.sokak,hastalar[i].adres.kapiNO,hastalar[i].adres.kat, hastalar[i].adres.ilce,hastalar[i].adres.il, hastalar[i].telefonNO);
        }
        else if(hastalar[i].yas.ay>=10 && hastalar[i].yas.gun<10){
            printf("PID|%d||%d||%s||%s^%s||%d%d0%d||%s||%s^%s^%s^%d^%s^%s||%s|\n",
                   hastalar[i].siraNO, hastalar[i].belgeNO, hastalar[i].kimlik,
                   hastalar[i].isim, hastalar[i].soyisim,
                   hastalar[i].yas.yil, hastalar[i].yas.ay, hastalar[i].yas.gun,
                   hastalar[i].cinsiyet, hastalar[i].adres.mahalle, hastalar[i].adres.sokak,hastalar[i].adres.kapiNO,hastalar[i].adres.kat, hastalar[i].adres.ilce,hastalar[i].adres.il, hastalar[i].telefonNO);
        }
        else{
            printf("PID|%d||%d||%s||%s^%s||%d%d%d||%s||%s^%s^%s^%d^%s^%s||%s|\n",
                   hastalar[i].siraNO, hastalar[i].belgeNO, hastalar[i].kimlik,
                   hastalar[i].isim, hastalar[i].soyisim,
                   hastalar[i].yas.yil, hastalar[i].yas.ay, hastalar[i].yas.gun,
                   hastalar[i].cinsiyet, hastalar[i].adres.mahalle, hastalar[i].adres.sokak,hastalar[i].adres.kapiNO,hastalar[i].adres.kat, hastalar[i].adres.ilce,hastalar[i].adres.il, hastalar[i].telefonNO);
        }

        printf("\n");
    }
}

void receteYaz(Hasta* hastalar, int *hastaSayisi) {
    if (*hastaSayisi == 0) {
        printf("Hic hasta kaydi bulunmamaktadir. Hasta eklemelisiniz.\n");
        hastaEkle(&hastalar[*hastaSayisi], *hastaSayisi);
        (*hastaSayisi)++;
        return;
    }
    hastaListele(hastalar, hastaSayisi);
    int siraSecim;
    printf("Recete yazilacak hassikayetn sira numarasini giriniz: ");
    scanf("%d", &siraSecim);
    for ( i = 0; i < *hastaSayisi; i++) {
        if (hastalar[i].siraNO == siraSecim) {
            printf("Recete No: R-%d atandi. Hasta kaydi siliniyor...\n", rand() % 100000);
            for ( j = i; j < *hastaSayisi - 1; j++) {
                hastalar[j] = hastalar[j + 1];
            }
            (*hastaSayisi)--;
            return;
        }
    }
    printf("Gecersiz sira numarasi!\n");
}


int main() {
    srand(time(NULL));
    Hasta hastalar[MAX_HASTA];
    int hastaSayisi = 0;
    int secim;

    while (1) {
        printf("\nAcil Servis Kayit Sistemi\n");
        printf("1. Yeni Hasta Kaydi\n");
        printf("2. Hastalari Listele\n");
        printf("3. Recete Yaz\n");
        printf("4. Cikis\n");
        printf("Seciminizi yapiniz: ");
        scanf("%d", &secim);

        switch (secim) {
            case 1:
                if (hastaSayisi < MAX_HASTA) {
                    hastaEkle(&hastalar[hastaSayisi], hastaSayisi);
                    hastaSayisi++;
                } else {
                    printf("Hasta kapasitesine ulasildi!\n");
                }
                break;
            case 2:
                hastaListele(hastalar, &hastaSayisi);
                break;
            case 3:
                receteYaz(hastalar, &hastaSayisi);
                break;
            case 4:
                printf("Cikis yapiliyor...\n");
                return 0;
            default:
                printf("Gecersiz secim! Tekrar deneyiniz.\n");
        }
    }
}