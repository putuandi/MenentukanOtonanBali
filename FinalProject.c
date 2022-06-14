#include <stdio.h>
#include <stdlib.h>

int main()
{
    //sekarang 27 November 2021: Saniscara, Paing, Langkir
    Mulai:
    printf("===================PROGRAM HARI OTONAN===================");
    char pancaWaraMaju[5][10]={"Paing", "Pon", "Wage", "Kliwon", "Umanis"};
    char pancaWaraMundur[5][10]={"Paing", "Umanis", "Kliwon", "Wage", "Pon"};
    char saptaWaraMaju[7][10]={"Saniscara", "Redite", "Soma", "Anggara", "Buda", "Wraspati", "Sukra"};
    char saptaWaraMundur[7][10]={"Saniscara", "Sukra", "Wraspati", "Buda", "Anggara", "Soma", "Redite"};
    char wukuMaju[30][15]={"Langkir", "Medangsia", "Pujut", "Pahang", "Krulut", "Merakih", "Tambir", "Medangkungan", "Matal", "Uye", "Menail", "Perangbakat", "Bala", "Ugu", "Wayang", "Kulawu", "Dukut", "Watugunung", "Sinta", "Landep", "Ukir", "Kulantir", "Tolu", "Gumbreg", "Wariga", "Warigadean", "Julungwangi", "Sungsang", "Dungulan", "Kuningan"};
    char wukuMundur[30][15]={"Langkir", "Kuningan", "Dungulan", "Sungsang", "Julungwangi",  "Warigadean", "Wariga",  "Gumbreg", "Tolu", "Kulantir", "Ukir", "Landep", "Sinta", "Watugunung", "Dukut", "Kulawu",  "Wayang", "Ugu", "Bala", "Perangbakat", "Menail", "Uye", "Matal", "Medangkungan", "Tambir", "Merakih", "Krulut", "Pahang", "Pujut", "Medangsia" };
    //Maju: kelahiran setelah 27 November 2021
    //Mundur: kelahiran sebelum 27 November 2021
    int tanggal, bulan, tahun, a, b, c;
    //a: untuk pancawara, b: untuk saptawara, c: untuk wuku

    printf("\n\nTanggal berapa Anda lahir : ");
    scanf("%d", &tanggal);
    printf("Bulan berapa Anda lahir : ");
    scanf("%d", &bulan);
    printf("Tahun berapa Anda lahir : ");
    scanf("%d", &tahun);

    int selisih=0;
    if(tahun<2021)
    {
        //baris 30-40: selisih => sampai akhir bulan kelahiran pada tahun kelahiran
        if(bulan==4||bulan==6||bulan==9||bulan==11)
        {
            selisih+=(30-tanggal);
        }
        else if(bulan==1||bulan==3||bulan==5||bulan==7||bulan==8||bulan==10||bulan==12)
        {
            selisih+=(31-tanggal);
        }
        else
        {
            if(tahun%400==0||((tahun%4==0)&&(tahun%100!=0))) //tahun kabisat: habis dibagi 400, atau habis dibagi 4 tetapi tidak habis dibagi 100
            {
                selisih+=(29-tanggal); //29: umur Februari pada tahun kabisat
            }
            else
            {
                selisih+=(28-tanggal); //28: umur Februari pada tahun nonkabisat
            }
        }
        //baris 51-65: selisih => akhir bulan kelahiran hingga 31 Desember pada tahun kelahiran
        for(int a=bulan+1; a<=12; a++)
        {
            if(a==4||a==6||a==9||a==11)
            {
                selisih+=30;
            }
            else if(a==1||a==3||a==5||a==7||a==8||a==10||a==12)
            {
                selisih+=31;
            }
            else
            {
                if(tahun%400==0||((tahun%4==0)&&(tahun%100!=0)))
                {
                    selisih+=29;
                }
                else
                {
                    selisih+=28;
                }
            }
        }
        //baris 65-76: selisih => 31 Desember pada tahun kelahiran hingga 31 Desember 2020
        for(int a=tahun+1; a<=2020; a++)
        {
            if(a%400==0||((a%4==0)&&(a%100!=0)))
            {
                selisih+=366; //total hari pada setahun kabisat
            }
            else
            {
                selisih+=365; //total hari pada sebulan nonkabisat
            }
        }
        selisih+=(365-34); //selisih => 31 Desember 2020 hingga 27 November 2021
        a=(selisih%5); //perulangan 5, berubah tiap hari
        b=(selisih%7); //perulangan 7, berubah tiap hari
        c=((selisih/7)%30); //perulangan 30, berubah tiap 7 hari
        printf("Hari otonan Anda: %s, %s, wuku %s", saptaWaraMundur[b], pancaWaraMundur[a], wukuMundur[c]);
    }
    else if(tahun==2021)
    {
        if(bulan==11)
        {
            if(tanggal==27)
            {
                selisih+=0;
                printf("Hari otonan Anda: Saniscara, Paing, wuku Langkir");
            }
            else if(tanggal>27)
            {
                selisih+=(tanggal-27);
                a=(selisih%5);
                b=(selisih%7);
                if(selisih%7!=0)
                {
                   c=((selisih/7)%30)+1; //tambah 1 untuk menyesuaikan, keluarannya Langkir ketika selisihnya 1-6, seharusnya Medangsia (Langkir+1)
                }
                else
                {
                    c=((selisih/7)%30); //ketika selisih 7, sesuai
                }
                printf("Hari otonan Anda: %s, %s, wuku %s", saptaWaraMaju[b], pancaWaraMaju[a], wukuMaju[c]);
            }
            else
            {
                selisih+=(27-tanggal);
                a=(selisih%5);
                b=(selisih%7);
                c=((selisih/7)%30);
                printf("Hari otonan Anda: %s, %s, wuku %s", saptaWaraMundur[b], pancaWaraMundur[a], wukuMundur[c]);
            }
        }
        else if(bulan==12)
        {
            selisih+=(3+tanggal); //3 = selisih 27 ke 30 November 2021
            a=(selisih%5);
            b=(selisih%7);
            if(selisih%7!=0)
            c=((selisih/7)%30)+1;
            else
            c=((selisih/7)%30);
            printf("Hari otonan Anda: %s, %s, wuku %s", saptaWaraMaju[b], pancaWaraMaju[a], wukuMaju[c]);
        }
        else
        {
            //baris 131-149: selisih => sampai akhir bulan kelahiran pada tahun 2021
            if(bulan==2)
            {
                selisih+=(28-tanggal);
            }
            else if(bulan==4||bulan==6||bulan==9||bulan==11)
            {
                selisih+=(30-tanggal);
            }
            else
            {
                selisih+=(31-tanggal);
            }
            //baris 151-172: selisih => akhir bulan kelahiran sampai 31 Oktober 2021
            for(int a=bulan+1; a<=10; a++)
            {
                if(a==2)
                {
                    selisih+=28;
                }
                else if(a==4||a==6||a==9)
                {
                    selisih+=30;
                }
                else
                {
                    selisih+=31;
                }
            }
            selisih+=27; //selisih => 31 Oktober 2021 hingga 27 n=November 2021
            a=(selisih%5);
            b=(selisih%7);
            c=((selisih/7)%30);
            printf("Hari otonan Anda: %s, %s, wuku %s", saptaWaraMundur[b], pancaWaraMundur[a], wukuMundur[c]);
        }
    }
    else
    {
        selisih+=(3+31); //selisih => 27 November 2021 hingga 31 Desember 2021
        //baris 184-194: selisih => 31 Desember 2021 hingga 31 Desember tahun kelahiran-1
        for(int a=2022; a<=tahun-1; a++)
        {
            if(a%400==0||((a%4==0)&&(a%100!=0)))
            {
                selisih+=366;
            }
            else
            {
                selisih+=365;
            }
        }
        //baris 196-217: selisih => 31 Desember tahun kelahiran-1 hingga tanggal 31 bulan kelahiran-1
        for(int a=1; a<=bulan-1; a++)
        {
            if(a==4||a==6||a==9||a==11)
            {
                selisih+=30;
            }
            else if(a==1||a==3||a==5||a==7||a==8||a==10||a==12)
            {
                selisih+=31;
            }
            else
            {
                if(tahun%400==0||((tahun%4==0)&&(tahun%100!=0)))
                {
                    selisih+=29;
                }
                else
                {
                    selisih+=28;
                }
            }
        }
        selisih+=tanggal; //selisih tanggal 31 bulan kelahiran-1 hingga tanggal kelahiran
        a=(selisih%5);
        b=(selisih%7);
        if(selisih%7==0)
        {
            c=((selisih/7)%30);
        }
        else
        {
            c=((selisih/7)%30)+1;
        }
        printf("Hari otonan Anda: %s, %s, wuku %s", saptaWaraMaju[b], pancaWaraMaju[a], wukuMaju[c]);
    }

    Pilihan:
    printf("\n\nApakah Anda ingin mengulangi program?");
    int pilihan;
    printf("\n*Masukkan \"1\" jika IYA\n*Masukkan \"2\" jika TIDAK\nPilihan : ");
    scanf("%d", &pilihan);
    if(pilihan==1)
    {
        system("cls");
        goto Mulai;
    }
    else if(pilihan==2)
    {
        printf("\n=====================PROGRAM SELESAI=====================");
    }
    else
    {
        printf("\nPilihan yang Anda masukkan salah!");
        goto Pilihan;
    }
    return 0;
}
