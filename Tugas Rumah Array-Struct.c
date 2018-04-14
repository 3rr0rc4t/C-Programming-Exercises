#include <stdio.h>

typedef struct {
  int nip;
  char first_name[100];
  char last_name[100];
  int golongan;
  int gajip;
  char status_kawin;
  int jml_ank;
  int ti;
  int ta;
  int p;
  float gajib;
} employee;

int main(void){
    int i, n;
    float gajit;
    //char *fname;
    //char *lname;

    //tabel referensi
	float pti[9] = {4.5, 4.0, 3.5, 3.0, 2.5, 2.0, 1.5, 1.0, 0.5};
	float pta[9] = {4.0, 3.5, 3.0, 2.5, 2.0, 1.5, 1.0, 0.5, 0};
	float pp[9] = {0.3, 0.29, 0.28, 0.27, 0.26, 0.25, 0.24, 0.23, 0.22};

	printf("Jumlah pegawai: ");
	scanf("%d",&n);

	employee emp[n];

    printf("\nMasukkan data pegawai:\n\n");

	for(i = 0; i < n; i++){
		printf("NIP: ");
		scanf(" %d",&emp[i].nip);
		//getchar();

		printf("Nama depan: ");
		scanf (" %[^\n]%*c", &emp[i].first_name);

		printf("Nama belakang: ");
		scanf (" %[^\n]%*c", &emp[i].last_name);

		printf("Golongan: ");
		scanf(" %d",&emp[i].golongan);

		printf("Gaji pokok: ");
		scanf("%d",&emp[i].gajip);

		printf("Status Kawin: ");
		scanf(" %c",&emp[i].status_kawin);

		printf("Jumlah Anak: ");
		scanf("%d", &emp[i].jml_ank);
		if(emp[i].jml_ank > 3) emp[i].jml_ank = 3;

		printf("\n");
	}

	for(i = 0; i < n; i++){
		//pajak tunjangan istri
		if(emp[i].status_kawin == 'K' || emp[i].status_kawin == 'k'){
			emp[i].ti = emp[i].gajip * pti[(emp[i].golongan) - 1]/100;
		} else {emp[i].ti = 0;}

		//pajak tunjangan anak
		emp[i].ta = emp[i].jml_ank*emp[i].gajip * pta[emp[i].golongan-1]/100;

		//gaji total
		gajit = emp[i].gajip + emp[i].ti + emp[i].ta;

		//pajak
		emp[i].p = pp[emp[i].golongan-1] * gajit;

		//gaji bersih
		emp[i].gajib = gajit - emp[i].p;
	}

	for(i = 0; i < n; i++){
		printf("\n");
		printf("NIP: %d\n", emp[i].nip);
		printf("Nama: %s %s\n", &emp[i].first_name,&emp[i].last_name);
		printf("Golongan: %d\n",emp[i].golongan);
		printf("Gaji Pokok: Rp %d\n",emp[i].gajip);
		printf("Tunjangan Istri: Rp %d\n",emp[i].ti);
		printf("Tunjangan Anak: Rp %d\n",emp[i].ta);
		printf("Pajak: Rp %d\n",emp[i].p);
		printf("Gaji Bersih: Rp %.0f\n",emp[i].gajib);
        printf("\n");
	}
}
