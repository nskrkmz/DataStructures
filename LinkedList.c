#include<stdio.h>
#include<stdlib.h>
//include<string.h>

struct musteri {
	char * isim ;
	int tutar ;
};

typedef struct musteri Musteri ;

//Fonksiyonlarýn deklerasyonlari
void ekleListe(Musteri**start, char * isim, int tutar);
void ekleAd();
void ekleFatura();
void yazdirAd();
void yazdirTutar();

char isimler[] = {"Ahmet","Bilal","Cemal","Adem","Yasin","Esin","Emel","Mustafa","Ayten","Ceylan","Nesrin","Bekir","Emin","Hakan","Hatice"};
int tutarlar[] = {100,1000,600,650,350,270,410,750,600,1000,900,850,790,610,550};




int main (void){
	Musteri* start = NULL ;
	
	ekleListe(&start, isimler[0], tutarlar[0]);
	ekleListe(&start, isimler[1], tutarlar[1]);
	ekleListe(&start, isimler[2], tutarlar[2]);
	ekleListe(&start, isimler[3], tutarlar[3]);
	ekleListe(&start, isimler[4], tutarlar[4]);
	ekleListe(&start, isimler[5], tutarlar[5]);
	ekleListe(&start, isimler[6], tutarlar[6]);
	ekleListe(&start, isimler[7], tutarlar[7]);
	ekleListe(&start, isimler[8], tutarlar[8]);
	ekleListe(&start, isimler[9], tutarlar[9]);
	ekleListe(&start, isimler[10], tutarlar[10]);
	ekleListe(&start, isimler[11], tutarlar[11]);
	ekleListe(&start, isimler[12], tutarlar[12]);
	ekleListe(&start, isimler[13], tutarlar[13]);
	ekleListe(&start, isimler[14], tutarlar[14]);
	ekleListe(&start, isimler[15], tutarlar[15]);
	
	
}// main() func. sonu

void ekleListe(){
	Musteri* yeni =[]
	
}//musteri ad ve fatura tutarýný içeren listeyi oluþturacak

void ekleAd (){
	
}//musteri adýna gore sirali index tablosuna kayýt ekleyecek

void ekleFatura(){
	
}//fatura miktarina gore sirali index tablosuna kayit ekleyecek 
void yazdirAd(){
	
	
}//yazdirAd() func. sonu

void yazdirTutar(){
	
	
}//yazdirTutar() func. sonu 



