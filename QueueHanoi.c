/*
	*Abdullah Enes Korkmaz
	*18061263


*/

#include<stdio.h>
#include<stdlib.h>


// sekiller oluþturuldu
struct sekil {
	int boyut ;
};

// çubuklar tanýmlandý
struct sopa{
	char isim ;
	int veri ;
	struct sekil *ilk ;
	struct sekil *next ;
	// prev tanýmlanacak............................................................................
};

// okuma kolaylýðý için oluþturuldu
typedef struct sekil Sekil ;
typedef struct sopa Sopa ;



void ekle(char _cubukIsim, int _diskBoyut);
void cikar();
/*void yazdir();*/


int main (void){
	
	Sekil *sekil_1 ;
	Sekil *sekil_2 ;
	Sekil *sekil_3 ;
	
	sekil_1->boyut = 1 ;
	sekil_2->boyut = 2 ;
	sekil_3->boyut = 3 ;
	
	Sopa *sopa_A;
	Sopa *sopa_B;
	Sopa *sopa_C;
	
	//sopa_X -> veri  -------> içindeki sekil sayýsý
	sopa_A->isim = 'A';
	sopa_A->veri = 0 ;
	
	sopa_B->isim = 'B';
	sopa_B->veri = 0 ;
	
	sopa_C->isim = 'C';
	sopa_C->veri = 0 ;
	
	
	
	
	
	
	
}


void ekle(Sopa * _sopaIsim, Sekil*_sekil){
	
	if((_sopaIsim->veri)==0){
	
		_sopaIsim->ilk = _sekil ;
		(_sopaIsim->next)= NULL ;
		_sopaIsim->veri = veri++ ; // 1 denile bilirdi 
	}
	else if ((_sopaIsim->veri)==1){
		if(((_sopaIsim->ilk)->boyut) < (_sekil->boyut)){
			printf("kucuk diskin üzerine %d diskini ekleyemezsin",_sekil->boyut);
		}
		else{
			_sekil->next = NULL;
			(_sopaIsim->ilk)->next = _sekil ;
			_sopaIsim->veri = veri++ ;
			
		}
	}
	else{
		Sekil * tutucu = _sopaIsim->ilk ;
		while((tutucu->next)!=NULL){
			tutucu=tutucu->next ;
		}
		tutucu->next = _sekil ;
		_sopaIsim->veri = veri ++
	}
}

void cikar(Sopa* _sopaIsim){
	Sekil * sekilTut = (_sopaIsim->ilk);
	while((sekilTut->next)!= NULL){
		sekilTut= sekilTut->next ;
	}
	
	if((_sopaIsim->veri)==3){
		
		
		
		
	}
	else if (){
		
	}
	
	else{
		
	}
	
	
}
/*
void yazdir(){
	
	
}*/


