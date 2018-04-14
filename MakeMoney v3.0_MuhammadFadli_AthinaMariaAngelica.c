/*
PROYEK AKHIR PROGLAN
SISTEM ONLINE BANKING
Dibuat oleh : Muhammad Fadli dan Athina Maria Angelica

Referensi: http://www.learn-c.org/en/Linked_lists
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//#include <time.h>

typedef struct {
    char nama[30];
    int rekening;
    char jenis[16];
    int jml;
} transaction;

typedef struct bank{
    char nama[30];
    int pin;
    int saldo;
    int rekening;
    transaction * history[30];
    //int trans_num;
    struct bank *next;
} user;

char c = 0;
int num[8] = {0};
int j,i;

user * head;
user * current_user;
user * logged_user;

void header();
int startMenu();
user * reg();
void  addUser(char * iname, int ipin);
user * login();
user * mainMenu();
void isiUang();
void cekSaldo();
void tarik();
int transfer();
void petunjuk();
void tPush(user * u, transaction * t);
//user * ganti(user * logged_user);

void help();
int pay_input(int mon, char a);
int withdraw_input(int mon, char a);

int main(){
    //setup
    int choice = 0;
    logged_user = NULL;

    while(choice != 4 && choice != 27){
        choice = startMenu();
        switch(choice){
            case 1: reg(); break;
            case 2: logged_user = login(); break;
            case 3: help(); break;
            case 4: break;
        }

        while(logged_user != NULL){
            logged_user = mainMenu();
        }
    }
}

void header(){
    printf("	 __  __       _ \n");
    printf("	|  \\/  |     | | \n");
    printf("	| \\  / | __ _| | _____ _ __ ___   ___  _ __   ___ _   _ \n");
    printf("	| |\\/| |/ _` | |/ / _ \\ '_ ` _ \\ / _ \\| '_ \\ / _ \\ | | |\n");
    printf("	| |  | | (_| |   <  __/ | | | | | (_) | | | |  __/ |_| |\n");
    printf("	|_|  |_|\\__,_|_|\\_\\___|_| |_| |_|\\___/|_| |_|\\___|\\__, |\n");
    printf("	                                                   __/ |\n");
    printf("	                                                  |___/ \n");
}

int startMenu(){
    int select = 1;
    do{
        header();
        printf("                         	");if (select == 1) printf("\b>");printf("Daftar                                   \n\n");
        printf("                         	");if (select == 2) printf("\b>");printf("Login                                   \n\n");
        printf("                         	");if (select == 3) printf("\b>");printf("Help                               \n\n");
        printf("                         	");if (select == 4) printf("\b>");printf("Exit                             \n\n");
        c = getch();
        switch(c){
            case 'd':
            case 'D':
            case 's':
            case 'S':
                select++;
                break;
            case 'a':
            case 'A':
            case 'w':
            case 'W':
                select--;
                break;
            case 27: return c;
        }
        if(select > 4) select = 1;
        if(select < 1) select = 4;

        system("cls");
      } while(c != 13);
      return select;
}

user * reg(){
    int j;
	int sama;
    char t_nama[30];
    int t_pin;

    header();
	printf("\n\n	    Silahkan Masukkan Nama Anda : ");
    scanf(" %[^\n]", t_nama);

	printf("\n	    Silahkan Masukkan PIN (6 Digit): ");
	if(scanf("	%d", &t_pin) != 1){
		while(getchar() != '\n');
		printf("\n\n	    Input Yang Anda Masukkan Salah");
		getch();
		//return -1;
	} else {

        sama = 0;
        current_user = head;

        while(current_user != NULL){
            if(strcmp(t_nama, current_user->nama) == 0){
                sama = 1;
            }
            current_user = current_user->next;
        }

        //printf("tidak ada sama");

        if(sama == 1){
            printf("\n\n	    Nama Yang Anda Masukkan Sudah Terdaftar");
            printf("\n\n	    Silahkan Ulangi Pendaftaran");
            getch();
            //return -1;

        } else
        if(t_pin > 999999 || t_pin < 100000){
            printf("\n\n	    Pin Yang Dimasukkan Tidak 6 Digit");
            getch();
            //return -1;
        } else {
            //printf("test");
            addUser(t_nama, t_pin);
            printf("\n\n        Berhasil mendaftar user %s", t_nama);
            getch();
        }
        system("cls");

	}
}

void addUser(char * iname, int ipin){
    current_user = head;

    user *  temp = malloc(sizeof(user));

    strcpy(temp->nama, iname);
    temp->saldo = 0;
    temp->pin = ipin;
    temp->rekening += i;
    i += 2;
    for(j = 0; j < 30; j++){
        temp->history[j] = NULL;
    }
    temp->next = NULL;

    if(head == NULL){
        head = temp;

    }else{
        while(current_user->next != NULL){
            current_user = current_user->next;  //find end of list
        }

        current_user->next = temp;
    }
}

user * login(){
    header();

	int t_pin;
	char t_nama[30];

	printf("	    Masukkan Nama Anda: ");
	scanf(" %[^\n]",&t_nama);

	printf("\n\n	    Masukkan PIN Anda : ");

	if(scanf("	%d", &t_pin) != 1){
		while(getchar() != '\n');
		printf("\n\n	    Input Yang Anda Masukkan Salah");
		system("cls");
		//return -1;
	} else if(t_pin > 999999 && t_pin < 100000){
		printf("\n\n	    Angka Yang Anda Masukkan Bukan 6 Digit");
		system("cls");
		//return -1;
	} else {
        //int found = 0;
        current_user = head;
        while(current_user != NULL){
            if(strcmp(current_user->nama, t_nama) == 0 && t_pin == current_user->pin){
                //user found
                system("cls");
                return current_user;
            }
            current_user = current_user->next;
        }

        //user not found
        system("cls");
        header();
        printf("\n      Nama atau PIN salah! Silahkan coba kembali.");
        printf("\n\n        Tekan tombol apa saja untuk kembali");
        getch();
        system("cls");
        return NULL;
	}

}

void help(){
    header();
    printf("\n	1. Program Simulasi Banking Online\n");
    printf("	2. Pada Menu Utama Gunakan W Untuk Naik Dan S Untuk Turun\n");
    printf("	3. Pada Menu Utama Gunakan ENTER Untuk Konfirmasi Pilihan\n");
    printf("	4. Program Ini Bisa Melakukan Transfer Antar Nasabah\n");
    printf("	5. Program Ini Menggunakan Multi User\n");
    printf("	6. Selamat Menggunakan Program Kami\n");
    printf("\n	Tekan Tombol Apa Saja Untuk Kembali Ke Menu Awal\n");
    getch();
    system("cls");
}

user * mainMenu(){
    int select = 1;
    int ret = 0;
    do{
        header();
        printf("                         ");if (select == 1) printf("\b>");printf("1.Isi Uang                                   \n");
        printf("                         ");if (select == 2) printf("\b>");printf("2.Cek Saldo                                   \n");
        printf("                         ");if (select == 3) printf("\b>");printf("3.Tarik Uang                               \n");
        printf("                         ");if (select == 4) printf("\b>");printf("4.Transfer Uang                             \n");
        printf("                         ");if (select == 5) printf("\b>");printf("5.Keterangan Akun                                \n");
        //printf("                         ");if (select == 6) printf("\b>");printf("6.Ganti Akun                                \n");
        printf("                         ");if (select == 6) printf("\b>");printf("6.Keluar                                 \n");
        c = getch();
        switch(c){
            case 'd':
            case 'D':
            case 's':
            case 'S':
                select++;
                break;
            case 'a':
            case 'A':
            case 'w':
            case 'W':
                select--;
                break;
        }
        if(select > 6) select = 1;
        if(select < 1) select = 6;

        system("cls");
    }while(c != 13);

    switch(select){
        case 1:
            isiUang();
            break;
        case 2:
            cekSaldo();
            break;
        case 3:
            tarik();
            break;
        case 4:
            transfer();
            break;
        case 5:
            petunjuk();
            break;
        case 6:
            return NULL;
    }

    return logged_user;
}

void isiUang(){
    int money = 0;
    do{
        header();
        printf("\n\n        Masukkan jumlah uang yang ingin diisikan:");
        printf("Rp %d", money);
        c = getch();
        switch(c){
            case 8:
            case '0' ... '9': money = pay_input(money,c); break;
            case 13:
                logged_user->saldo += money;

//                j = 0;
//
//                while(logged_user->history[j] != NULL){
//                    j++;
//                }

                transaction * temp = malloc(sizeof(transaction));
                strcpy(temp->jenis, "Isi");
                temp->jml = money;
                temp->rekening = logged_user->rekening;
                strcpy(temp->nama, logged_user->nama);

          //      logged_user->history[j] = temp;

                tPush(logged_user,temp);

                break;
        }
        system("cls");
    }while(c != 13 && c != 27);

    if(c == 13){
        header();
        printf("\n\n        Isi saldo berhasil!");
        printf("\n\n        Tekan tombol apa saja untuk kembali . . .");
        getch();
    }
    system("cls");

    money = 0;
    for (j = 0; j < 8; j++){
        num[j] = 0;
    }
}

void cekSaldo(){
    header();
    printf("\n\n    Saldo Anda saat ini:");
    printf("\n\n        Rp %d",logged_user->saldo);
    printf("\n\n    Tekan tombol apa saja untuk kembali . . .");
    getch();
    system("cls");
}

void tarik(){
    int money = 0;
    do{
        header();
        printf("\n\n        Masukkan jumlah uang yang ingin diisikan:");
        printf("Rp %d", money);
        c = getch();
        switch(c){
            case 8:
            case '0' ... '9': money = withdraw_input(money,c); break;
            case 13:
                logged_user->saldo -= money;

//                j = 0;
//
//                while(logged_user->history[j] != NULL){
//                    j++;
//                }

                transaction * temp = malloc(sizeof(transaction));
                strcpy(temp->jenis, "Tarik");
                temp->jml = money;
                temp->rekening = logged_user->rekening;
                strcpy(temp->nama, logged_user->nama);

                //logged_user->history[j] = temp;

                tPush(logged_user, temp);

                break;
        }
        system("cls");
    }while(c != 13 && c != 27);

    if(c == 13){
        header();
        printf("\n\n        Penarikan uang berhasil!");
        printf("\n\n        Tekan tombol apa saja untuk kembali . . .");
        getch();
    }
    system("cls");

    money = 0;
    for (j = 0; j < 8; j++){
        num[j] = 0;
    }
}

int transfer(){
    header();
    int recipient, money = 0;
    printf("\n\n        Masukkan rekening tujuan : ");
    if(scanf("%d",&recipient) != 1){
        while(getchar() != '\n');
		printf("\n\n	    Input Yang Anda Masukkan Salah");
		getch();
    } else {

        //find user with that number
        current_user = head;
        while (current_user != NULL && recipient != current_user->rekening ){
                current_user = current_user->next;
        }

        if(current_user == NULL){
            //user not found
            system("cls");
            header();
            printf("\n\n        Tidak ditemukan akun dengan nomor rekening tersebut!");
            printf("\n\n        Tekan tombol apa saja untuk kembali . . .");
            c = getch();
        }else{
            do{
                system("cls");
                header();
                printf("\n\n        Nama penerima   : %s", current_user->nama);
                printf("\n\n        Jumlah transfer : Rp %d", money);
                c = getch();
                switch(c){
                    case 8:
                    case '0' ... '9' : money = withdraw_input(money, c); break;
                    case 13:
                        if(money > 0){
                            logged_user->saldo -= money;
                            current_user->saldo += money;

    //                        j = 0;
    //
    //                        while(logged_user->history[j] != NULL){
    //                            j++;
    //                        }

                            transaction * temp = malloc(sizeof(transaction));
                            strcpy(temp->jenis, "Transfer Keluar");
                            temp->jml = money;
                            temp->rekening = current_user->rekening;
                            strcpy(temp->nama, current_user->nama);

                            tPush(logged_user, temp);

    //                        logged_user->history[j] = temp;
    //
    //                        j = 0;

                            while(current_user->history[j] != NULL){
                                j++;
                            }

                            temp = malloc(sizeof(transaction));
                            strcpy(temp->jenis, "Transfer Masuk");
                            temp->jml = money;
                            temp->rekening = logged_user->rekening;
                            strcpy(temp->nama, logged_user->nama);

                            tPush(current_user, temp);

                            //current_user->history[j] = temp1;
                        }

                        break;
                }
            }while(c != 13 && c!= 27);

            if(c == 13 && money > 0){
                system("cls");
                header();
                printf("\n\n        Transaksi berhasil!");
                printf("\n\n        Keterangan transaksi:");
                printf("\n      Nama penerima   : %s", current_user->nama);
                printf("\n      Jumlah transfer : Rp %d", money);
                getch();
            }
        }
    }

    money = 0;
    for (j = 0; j < 8; j++){
        num[j] = 0;
    }

    system("cls");
}

void petunjuk(){
    header();
    printf("\n\n        Nama            :%s", logged_user->nama);
    printf("\n\n        No. Rekening    :%d", logged_user->rekening);
    printf("\n\n        Riwayat transaksi:");
    i=0;
//    i = 0;
//    while(logged_user->history[j] != NULL){
//        printf("\n\n        %d. \n",i+1);
//        printf("\n        Jenis Transaksi    : %s", logged_user->history[j]->jenis);
//        if(strcmp(logged_user->history[j]->jenis, "Transfer Keluar") == 0 || strcmp(logged_user->history[j]->jenis, "Transfer Masuk") == 0) printf("\n        Nama               : %s", logged_user->history[j]->nama);
//        if(strcmp(logged_user->history[j]->jenis, "Transfer Keluar") == 0 || strcmp(logged_user->history[j]->jenis, "Transfer Masuk") == 0) printf("\n        Rekening           : %d", logged_user->history[j]->rekening);
//        printf("\n        Jumlah             : Rp %d", logged_user->history[j]->jml);
//        j--;
//        i++;
//    }

    for(j = 0; j < 30; j++){
        if(logged_user->history[j] != NULL){
            printf("\n\n        %d. \n",i+1);
            printf("\n        Jenis Transaksi    : %s", logged_user->history[j]->jenis);
            if(strcmp(logged_user->history[j]->jenis, "Transfer Keluar") == 0 || strcmp(logged_user->history[j]->jenis, "Transfer Masuk") == 0) printf("\n        Nama               : %s", logged_user->history[j]->nama);
            if(strcmp(logged_user->history[j]->jenis, "Transfer Keluar") == 0 || strcmp(logged_user->history[j]->jenis, "Transfer Masuk") == 0) printf("\n        Rekening           : %d", logged_user->history[j]->rekening);
            printf("\n        Jumlah             : Rp %d", logged_user->history[j]->jml);
            i++;
        }
    }

    getch();
    system("cls");
}

int pay_input(int mon, char a){//input uang dengan shift
    if(a == 8 && mon > 0){
        mon = 0;
        if(num[0]!=0){mon += 1000000*(num[0]-'0') ;}
        if(num[1]!=0){mon += 100000*(num[1]-'0') ;}
        if(num[2]!=0){mon += 10000*(num[2]-'0') ;}
        if(num[3]!=0){mon += 1000*(num[3]-'0') ;}
        if(num[4]!=0){mon += 100*(num[4]-'0') ;}
        if(num[5]!=0){mon += 10*(num[5]-'0') ;}
        if(num[6]!=0){mon += (num[6]-'0') ;}

        for (j = 7; j > 0; j--){
            num[j] = num[j-1];
        }

        num[0] = 0;

    } else if (a != 8){
        if(num[0] != 0 && num[0] != '0'){return 100000000;}
        mon = 0;
        mon += (a-'0');
        if(num[7] != 0){mon += 10*(num[7]-'0');}
        if(num[6] != 0){mon += 100*(num[6]-'0');}
        if(num[5] != 0){mon += 1000*(num[5]-'0');}
        if(num[4] != 0){mon += 10000*(num[4]-'0');}
        if(num[3] != 0){mon += 100000*(num[3]-'0');}
        if(num[2] != 0){mon += 1000000*(num[2]-'0');}
        if(num[1] != 0){mon += 10000000*(num[1]-'0');}

        for(j = 0; j < 7;j++){
            num[j] = num[j+1];
        }

        num[7] = a;
    }
    return mon;
}

int withdraw_input(int mon, char a){
    if(a == 8 && mon > 0){
        mon = 0;
        if(num[0]!=0){mon += 1000000*(num[0]-'0') ;}
        if(num[1]!=0){mon += 100000*(num[1]-'0') ;}
        if(num[2]!=0){mon += 10000*(num[2]-'0') ;}
        if(num[3]!=0){mon += 1000*(num[3]-'0') ;}
        if(num[4]!=0){mon += 100*(num[4]-'0') ;}
        if(num[5]!=0){mon += 10*(num[5]-'0') ;}
        if(num[6]!=0){mon += (num[6]-'0') ;}

        for (j = 7; j > 0; j--){
            num[j] = num[j-1];
        }

        num[0] = 0;

    } else if (a != 8){
        mon = 0;
        mon += (a-'0');
        if(num[7] != 0){mon += 10*(num[7]-'0');}
        if(num[6] != 0){mon += 100*(num[6]-'0');}
        if(num[5] != 0){mon += 1000*(num[5]-'0');}
        if(num[4] != 0){mon += 10000*(num[4]-'0');}
        if(num[3] != 0){mon += 100000*(num[3]-'0');}
        if(num[2] != 0){mon += 1000000*(num[2]-'0');}
        if(num[1] != 0){mon += 10000000*(num[1]-'0');}

        if(mon > logged_user->saldo){return logged_user->saldo;}

        for(j = 0; j < 7;j++){
            num[j] = num[j+1];
        }

        num[7] = a;
    }
    return mon;
}

void tPush(user * u, transaction * t){
    j = 29;
    while(current_user->history[j] != NULL && j >= 0){
        j--;
    }

    if(j >= 0){
        u->history[j] = t;
    } else {
        for(j = 29; j > 0; j--){
            u->history[j] = u->history[j-1];
        }

        u->history[0] = t;
    }
}
