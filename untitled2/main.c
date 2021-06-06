#include <stdio.h>
#include <stdlib.h>

int main() {


    int commandData[10];
    float myfloat;
    commandData[5] = ((int)(&myfloat));


    float f = 2.75;



    enum cinsiyet{
        k = 'K',
        e = 'E'
    };
    char cinsiyetler[] = {'k', 'e'};

    enum Sube{
        a,
        b,
        c,
        d
    };

    char subeler[] = {'a', 'b', 'c', 'd'};

    struct Ogrenci{
        int No;
        char Ad[10];
        int Yas;
        char Cinsiyet;
        int Not;
        char Sube;
    };

    FILE *Dosya;
    Dosya=fopen("ogrenci.txt", "w");
    int No_;
    char Ad_[10];
    int Yas_;
    char Cinsiyet_;
    int Not_;
    char Sube_;
    int i = 1;
    char devam_mi;

    if (Dosya==NULL) {
        printf("Başarısız dosya oluşturma isteği!\n");
        exit(1);
    } else {
        printf("Dosya oluşturuldu !\n");

        do {
        printf("%d. öğrencinin numarasi :", i);
        scanf("%d", &No_);
        printf("%d. öğrencinin adı :", i);
        scanf("%s", Ad_);
        printf("%d. öğrencinin yasi :", i);
        scanf("%d", &Yas_);
        printf("%d. öğrencinin cinsiyeti (K ya da E):", i);
        scanf(" %c", &Cinsiyet_);
        printf("%d. öğrencinin notu :", i);
        scanf("%d", &Not_);
        printf("%d öğrencinin subesi (A, B, C ya da D):", i);
        scanf(" %c", &Sube_);
        printf("\n");

        int Cinsiyet$;
        if (Cinsiyet_ == 'K') {
            Cinsiyet$ = 'k';
        }
        else if (Cinsiyet_ == 'E') {
            Cinsiyet$ = 'e';
        }

        int Sube$;
        if (Sube_ == 'A') {
            Sube$ = 'a';
        }
        else if (Sube_ == 'B') {
            Sube$ = 'b';
        }
        else if (Sube_ == 'C') {
            Sube$ = 'c';
        }
        else if (Sube_ == 'D') {
            Sube$ = 'd';
        }

        fprintf(Dosya, "%d %s %d %d %d %d\n", No_, Ad_, Yas_, Cinsiyet$, Not_, Sube$);
        i = i + 1;
        printf("Devam etmek istermisiniz (E/e veya H/h)?");
        scanf(" %c", &devam_mi);
        } while (devam_mi=='E'||devam_mi=='e');
    }
    fclose(Dosya);


    int ogrenci_sayisi[] = {0, 0, 0, 0};
    int dusuk[] = {101, 101, 101, 101};
    int yuksek[] = {-1, -1, -1, -1};
    double orta[] = {0.0, 0.0, 0.0, 0.0};
    struct Ogrenci ogrenciler[i];

    Dosya = fopen("ogrenci.txt", "r");
        if (Dosya == NULL){
        printf("Basarisiz dosya okuma istegi!\n");
        exit(1);
        } else {
        int s = 0;
            for(s = 0; s < i; s ++){
            fscanf(Dosya, "%d %s %d %d %d %d",
            &ogrenciler[s].No,
            ogrenciler[s].Ad,
            &ogrenciler[s].Yas,
            &ogrenciler[s].Cinsiyet,
            &ogrenciler[s].Not,
            &ogrenciler[s].Sube);
        }
    }
    printf("\nDosyadaki tum veriler okundu!\n");
    fclose(Dosya);

    int s = 0;
    for (s = 0; s < i; s++) {
        printf("%d", s);
        int sube = ogrenciler[s].Sube - 'a';
        ogrenci_sayisi[sube] = ogrenci_sayisi[sube] + 1;
        orta[sube] = orta[sube] + ogrenciler[s].Not;
        if (ogrenciler[s].Not < dusuk[sube]) {
            dusuk[sube] = ogrenciler[s].Not;
        }
        if (ogrenciler[s].Not > yuksek[sube]) {
            yuksek[sube] = ogrenciler[s].Not;
        }
    }
    for (s = 0; s < 4; s++) {
        orta[s] = orta[s] / ogrenci_sayisi[s];

        printf("%c: %d %d %.2f\n", subeler[s], yuksek[s], dusuk[s], orta[s]);
    }


    return 0;
}