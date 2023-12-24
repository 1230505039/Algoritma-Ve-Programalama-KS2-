#include <stdio.h>
#include <stdlib.h>
#include <time.h>      //Burada rand fonksiyonundan sürekli farkli degerler almak için 'time' kütüphanesini ekliyorum.

typedef float Artirma;   //Burada 'float' veri tipini 'Artirma' olarak tanimliyorum.

struct musteri{				//Burada 'musteri' diye bir 'struct' olusturuyorum.
	int musteri_no[11];		//Ve bu structin icine tum musterilerin sahip olacagi 'musteri_no' tanimliyorum. 
};

void acikarttirma(int teklif_veren_no, Artirma musteri_bid){		//Burada hangi musterinin ne kadar teklif ettigini ögrenecegimiz bir fonksiyon olusturuyoruz.
	printf("%d numarali musterimiz %.2fTL veriyor arttiran var mi?\n",teklif_veren_no, musteri_bid);
}


int main() {
	srand(time(NULL));  //Burada program her tekrar çalistiginda farkli bir sonuc olmasi için 'srand (seedrand)' fonksiyonun icine 'time(NULL)' argümanini ekliyoruz.
	struct musteri mus = {{0,1,2,3,4,5,6,7,8,9,10} //Burada structi belirtiyorum ve teklif verecek 10 tane müsteri olusturuyorum. '0' açik artirmanin bittigini gösterecektir.
	};
	int baslangic_fiyati = rand() %100+20;      //Burada bilgisayardan açilis fiyati için 20 ile 120 arasinda rastgele bir fiyat belirlemesini istiyoruz.
	printf("Acilis fiyatimiz %dTL\n",baslangic_fiyati); //Burada açilis fiyatini yazdiriyoruz.
	
	int temp;	//Burada teklif veren kisi üs üste teklif vermemesi icin 'temp' degiskenini 'int' tipinde tanimliyoruz.
	
	while(1){		//Burada herhangi bir kosula bagli olmayan bir 'while' döngüsü olusturuyoruz.
		int kazanan;	//Kazanan müsterinin numarasini almak icin bir 'kazanan' diye bir degisken olusturuyoruz.
		int teklif_veren_no = mus.musteri_no[rand() %10+0];    //Burada musteri numarasina ulasmak için olusturdugumuz struct yapisindan musteri numaralarina ulasiyoruz ve 0 ile 10 arasinda rastgele bir sayi seçmesini sagliyoruz.
		Artirma musteri_bid = rand() %baslangic_fiyati*2+baslangic_fiyati;  //Burada ise müsterinin teklif verecegi miktari rastgele aliyoruz. Verilen her tekliften sonra, bir önceki teklifin 2 kati verilecek olan teklifin minimum degeri olacaktir.
		
		if(teklif_veren_no != temp){	//Eger 'teklif_veren_no' esit degilse 'temp'e asagidaki kodlari yapsin.
		
		
			if(teklif_veren_no == 0){   //Burada eger bilgisayar '0'i seçerse açik arttirma bitecektir.
				printf("Acik arttirmayi kazanan %dTL fiyat ile %d numarali musterimizdir.",baslangic_fiyati ,kazanan);	//Burada kazanan açiklanir.
				break;		//Döngü kirilir.
			}
			acikarttirma(teklif_veren_no, musteri_bid);		//Burada teklif veren müsterinin numarasini ve verilen teklifin paramtrelerini girerek 'acikarttirma' fonksiyonumuzu çagiriyoruz.
			baslangic_fiyati = musteri_bid; //Burada verilecek sonraki teklifin önceki tekliften az olmasini engelliyoruz. Bu yüzden baslngic fiyatini verilen teklife esitliyoruz.
			kazanan = teklif_veren_no;		//Burada bunu olusturmamizin nedeni program '0'i rastgele sectiginde kazananin '0' olarak yazmasini engellemektir. 
			temp = teklif_veren_no;
		}
	}
	return 0;
}
