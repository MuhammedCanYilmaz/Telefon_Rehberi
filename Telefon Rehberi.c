#include <stdio.h>
#include <string.h>

// Kişi bilgilerini tutacak yapı (Struct)
// Başlangıçta en temiz yöntem budur.
struct Kisi {
    char ad[50];
    char soyad[50];
    char numara[20];
};

// Rehberde en fazla 100 kişi olsun dedik (Sabit dizi)
struct Kisi rehber[100];
int kisiSayisi = 0; // Şu an rehberde kaç kişi var?

// --- Fonksiyonlar ---

void kisiEkle() {
    if (kisiSayisi >= 100) {
        printf("Hata: Rehber dolu! Daha fazla kisi ekleyemezsiniz.\n");
        return;
    }

    printf("\n--- YENI KISI EKLE ---\n");
    
    // scanf kullanırken stringlerde & işareti konmaz, bu önemli detaydır.
    printf("Ad: ");
    scanf("%s", rehber[kisiSayisi].ad);
    
    printf("Soyad: ");
    scanf("%s", rehber[kisiSayisi].soyad);
    
    printf("Numara: ");
    scanf("%s", rehber[kisiSayisi].numara);

    kisiSayisi++; // Kişi sayısını bir arttır
    printf("Kisi basariyla eklendi!\n");
}

void listele() {
    printf("\n--- REHBER LISTESI ---\n");
    if (kisiSayisi == 0) {
        printf("Rehber bos.\n");
    } else {
        for (int i = 0; i < kisiSayisi; i++) {
            printf("%d. %s %s - Tel: %s\n", i + 1, rehber[i].ad, rehber[i].soyad, rehber[i].numara);
        }
    }
}

void kisiAra() {
    char aranacakIsim[50];
    int bulunduMu = 0; // 0: Bulunamadı, 1: Bulundu
    
    printf("\n--- KISI ARA ---\n");
    printf("Aranacak Ad: ");
    scanf("%s", aranacakIsim);
    
    printf("Sonuclar:\n");
    for (int i = 0; i < kisiSayisi; i++) {
        // strcmp iki metni karşılaştırır. 0 dönerse eşleşmiş demektir.
        if (strcmp(rehber[i].ad, aranacakIsim) == 0) {
            printf("Bulundu: %s %s - %s\n", rehber[i].ad, rehber[i].soyad, rehber[i].numara);
            bulunduMu = 1;
        }
    }
    
    if (bulunduMu == 0) {
        printf("Boyle bir kisi bulunamadi.\n");
    }
}

// --- Ana Program ---

int main() {
    int secim;
    
    // Sonsuz döngü (Programdan çık diyene kadar döner)
    while (1) {
        printf("\n=========================\n");
        printf(" TELEFON REHBERI MENUSU\n");
        printf("=========================\n");
        printf("1. Kisi Ekle\n");
        printf("2. Rehberi Listele\n");
        printf("3. Isimden Numara Bul\n");
        printf("4. Cikis\n");
        printf("Seciminiz: ");
        scanf("%d", &secim);
        
        switch (secim) {
            case 1:
                kisiEkle();
                break;
            case 2:
                listele();
                break;
            case 3:
                kisiAra();
                break;
            case 4:
                printf("Cikis yapiliyor...\n");
                return 0; // Programı sonlandırır
            default:
                printf("Gecersiz secim! Tekrar deneyin.\n");
        }
    }
    
    return 0;
}