/*
*	03.11.2020
*	Abdullah Enes Korkmaz
*	18061263
*	enes.korkmaz@bil.omu.edu.tr
*/



#include <stdio.h>
#include <stdlib.h>

//Ogrenci verilerinin tamami
int indexs[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14};
int studentNumbers[] = {18060311, 20060045, 
			19061091, 20060134, 
			20060678, 18061086, 
		   	20060032, 20060067, 
		  	19060456, 18060245, 
			20060110, 20060234, 
			20060141, 20060011, 20060012 };
int examGrades[] = {40, 50, 75, 90, 40, 75, 50, 60, 60, 75, 40, 90, 60, 50, 60};

//Ogrenci verilerini tutacak yapi
struct data {
	int index; 		
	int studentNumber;	
	int examGrade; 		
	struct data *nextStudent ; //Verileri ore siralama yaparken kullanilcak
	struct data *preStudent ; //	""			   ""				""
};
typedef struct data Student ; //Source code da ifade kolayligi saglamak icin 

void ekle (Student ** startIndexTable, int index, int studentNumber, int examGrade);
void sil (Student ** startIndexTable, int _index);
//int  degistir(Student ** startIndexTable , int _index , int _examGrade); // bug � ��zemedim hocam 
void yazdir (startIndexTable);

int main (void) {
	Student * startIndexTable = NULL;
	
	//__dongu kullanilabilirdi girdilerin net g�r�nmesi i�in bu �ekilde kodlamay� tercih ettim__
	ekle (&startIndexTable, indexs[0],  studentNumbers[0] ,  examGrades[0]);
	ekle (&startIndexTable, indexs[1],  studentNumbers[1] ,  examGrades[1]);
	ekle (&startIndexTable, indexs[2],  studentNumbers[2] ,  examGrades[2]);
	ekle (&startIndexTable, indexs[3],  studentNumbers[3] ,  examGrades[3]);
	ekle (&startIndexTable, indexs[4],  studentNumbers[4] ,  examGrades[4]);
	ekle (&startIndexTable, indexs[5],  studentNumbers[5] ,  examGrades[5]);
	ekle (&startIndexTable, indexs[6],  studentNumbers[6] ,  examGrades[6]);
	ekle (&startIndexTable, indexs[7],  studentNumbers[7] ,  examGrades[7]);
	ekle (&startIndexTable, indexs[8],  studentNumbers[8] ,  examGrades[8]);
	ekle (&startIndexTable, indexs[9],  studentNumbers[9] ,  examGrades[9]);
	ekle (&startIndexTable, indexs[10], studentNumbers[10] , examGrades[10]);
	ekle (&startIndexTable, indexs[11], studentNumbers[11] , examGrades[11]);
	ekle (&startIndexTable, indexs[12], studentNumbers[12] , examGrades[12]);
	ekle (&startIndexTable, indexs[13], studentNumbers[13] , examGrades[13]);
	ekle (&startIndexTable, indexs[14], studentNumbers[14] , examGrades[14]); 
	
	
	yazdir( startIndexTable ); // beklenen : null-3,11,9,5,2,8,14,7,12,13,6,1,0,10,4-null
	
	// 5 indisli veriyi sil 
	//sil(startIndexTable , 5); 
	//printf("\n"); 
	//yazdir(startIndexTable);
	
	
	
}

void ekle (Student ** startIndexTable, int index, int studentNumber, int examGrade){
	Student*newStudent = (Student*)malloc(sizeof(Student));
	if (newStudent == NULL){ // |yeni veri icin yer ayr�lamadi
		printf("Yeni ogrenci icin yer ayrilamadi.(Bellek dolu olabilir!!!)");
		exit(EXIT_FAILURE);
	}
	else{ // |yeni veri i�in yer ayr�labildi
	
		//ekle() fonksiyonuna verilen parametreler e�le�tiriliyor 
		newStudent->nextStudent = NULL ;
		newStudent->preStudent = NULL ;
		newStudent->index = index ;
		newStudent->studentNumber = studentNumber ;
		newStudent->examGrade = examGrade ;
		
		Student *currentStudent = (*startIndexTable);
		
		if(currentStudent == NULL){ // | |Tabloya daha �nce hi� veri y�klenmemi� ise
			(*startIndexTable) = newStudent;
		}
		else {// | |tabloya daha �nce veri giri�i yap�lm��, yeni veri i�in uygun yer sorgulanacak
			
			if ((newStudent->examGrade) > (currentStudent->examGrade)){ // | | |yeni eklenen veri en b�y�k examGrade'e sahipse
				currentStudent->preStudent = newStudent ;
				newStudent->nextStudent = currentStudent ;
				(*startIndexTable) = newStudent ;
			}
			else if((newStudent->examGrade) == (currentStudent->examGrade)){ // | | |yeni eklenen veri ile ilk veri ayn� examGrade'e sahipse
				
				if ((newStudent->studentNumber) < (currentStudent->studentNumber)){ // ||||yeni eklenen verinin studentnumber i ilk veriden k���kse
					currentStudent->preStudent = newStudent ;
					newStudent->nextStudent = currentStudent ;
					(*startIndexTable) = newStudent ;
				}
				else{ //||||yeni eklenen verinin student number i daha b�y�kse
					Student* tutucu = currentStudent->nextStudent ;
					
					currentStudent->nextStudent = newStudent ;
					newStudent->preStudent = currentStudent;
					tutucu->preStudent = newStudent ;
					newStudent->nextStudent = tutucu;
					
					
				}
			}
			else{ // | | |yeni eklenen veri'nin examGrade i ilk veriden daha k���kse
				while ((currentStudent->examGrade) > (newStudent->examGrade)){ //veri i�in uygun yeri bul
					currentStudent = currentStudent->nextStudent ;
				}
				if((currentStudent->nextStudent)== NULL){ // bulunan yer indexTable �n sonu ise
					currentStudent->nextStudent = newStudent ;
					newStudent->preStudent = currentStudent ;
				}
				
				else if ((currentStudent->examGrade)==(newStudent->examGrade)){ // bulunan yer ile examGrade leri ayni ise
				
					//bulunan yer ile daha sa��ndaki veri ile de examGrade i ayni ise	
					if(((currentStudent->nextStudent)->examGrade)==(newStudent->examGrade)&(((currentStudent->nextStudent)->studentNumber)<(newStudent->studentNumber))){
						currentStudent=currentStudent->nextStudent;
						if((currentStudent->studentNumber) < (newStudent->studentNumber)){
							Student* tutucu = currentStudent->nextStudent ;
						
							currentStudent->nextStudent=newStudent ;
							newStudent->preStudent = currentStudent ;
							newStudent->nextStudent = tutucu ;
							tutucu->preStudent = newStudent ;
						}
						else {
							Student* tutucu = currentStudent->preStudent ;
						
							currentStudent->preStudent = newStudent ;
							newStudent->nextStudent = currentStudent ;
							tutucu->nextStudent = newStudent ;
							newStudent->preStudent = tutucu ;
						}	
						
					}
					
					else{
						if((currentStudent->studentNumber) < (newStudent->studentNumber)){
							Student* tutucu = currentStudent->nextStudent ;
						
							currentStudent->nextStudent=newStudent ;
							newStudent->preStudent = currentStudent ;
							newStudent->nextStudent = tutucu ;
							tutucu->preStudent = newStudent ;
						}
						else {
							Student* tutucu = currentStudent->preStudent ;
						
							currentStudent->preStudent = newStudent ;
							newStudent->nextStudent = currentStudent ;
							tutucu->nextStudent = newStudent ;
							newStudent->preStudent = tutucu ;
						}
						
					}
					
					
					
					
				}
				else if ((newStudent->examGrade) > (currentStudent->examGrade)){
					Student* tutucu = currentStudent->preStudent ;
						
					currentStudent->preStudent = newStudent ;
					newStudent->nextStudent = currentStudent ;
					tutucu->nextStudent = newStudent ;
					newStudent->preStudent = tutucu ;
				}
				else{
					Student* tutucu = currentStudent->nextStudent ;
					
					currentStudent->nextStudent=newStudent ;
					newStudent->preStudent = currentStudent ;
					newStudent->nextStudent = tutucu ;
					tutucu->preStudent = newStudent ;
				}
			
				
			}
		}
	}
}// ekle() sonu
	


void sil (Student ** startIndexTable, int _index) {
	Student* tutucu =startIndexTable;
	//Student* silici = (Student*)malloc(sizeof(Student));
	
	while((tutucu->index)!=_index){
		tutucu = tutucu->nextStudent;
	}
	
	if ((tutucu->preStudent)==NULL){ // En ba�taki veri silinecekse
		
		//startIndexTable  = startIndexTable->nextStudent;
		
		tutucu = tutucu->nextStudent;
		tutucu->preStudent = NULL ;
		(*startIndexTable)=tutucu ;
		//tutucu->preStudent = NULL ;
		
		//free(tutucu);
		//printf("\n");
		//yazdir(startIndexTable);
		
		
		//tutucu= tutucu->nextStudent;
		//tutucu->preStudent = NULL;
		//(*startIndexTable)= tutucu;
		//startIndexTable->preStudent =NULL;
		
		//(tutucu->nextStudent)->preStudent = NULL ;
		//tutucu = tutucu->nextStudent;
		//(*startIndexTable)= tutucu ;
		//free(*startIndexTable) ;
		//(*startIndexTable) = newStudent;
	}
	else if ((tutucu->nextStudent)==NULL){ //En sondaki veri silinecekse
		(tutucu->preStudent)->nextStudent = NULL ;
		//free(tutucu) ;
		
	}
	
	else { //aralarda bulunan bir veri silinecekse
		
		(tutucu->preStudent)->nextStudent = tutucu->nextStudent ;
		(tutucu->nextStudent)->preStudent = tutucu->preStudent ;
		//free(tutucu);
		
	}
	
	
	
	
}// sil() sonu

/* int degistir(Student ** startIndexTable , int _index , int _examGrade){
	
	Student* tutucu =startIndexTable;
	//Student* silici = (Student*)malloc(sizeof(Student));
	
	while((tutucu->index)!=_index){
		tutucu = tutucu->nextStudent;
	}
	
	if ((tutucu->preStudent)==NULL){ 
		
		
		
		tutucu = tutucu->nextStudent;
		tutucu->preStudent = NULL ;
		(*startIndexTable)=tutucu ;
		tutucu->nextStudent = NULL ;
		tutucu->preStudent = NULL ;
		tutucu->examGrade = _examGrade ;
		ekle(&startIndexTable,_index,(tutucu->studentNumber),_examGrade);
		
		
	else if((tutucu->nextStudent)== NULL){ 
	
		(tutucu->preStudent)->nextStudent = NULL ;
		tutucu->nextStudent = NULL ;
		tutucu->preStudent = NULL ;
		tutucu->examGrade = _examGrade ;
		ekle(&startIndexTable,_index,(tutucu->studentNumber),_examGrade);
		//free(tutucu) ;
	}
	
	else { //aralarda bulunan bir veri silinecekse
		
		(tutucu->preStudent)->nextStudent = tutucu->nextStudent ;
		(tutucu->nextStudent)->preStudent = tutucu->preStudent ;
		tutucu->nextStudent = NULL ;
		tutucu->preStudent = NULL ;
		tutucu->examGrade = _examGrade ;
		ekle(&startIndexTable,_index,(tutucu->studentNumber),_examGrade);
		//free(tutucu);
		
	}
	
	
	
	
}//degistir() sonu */

void yazdir(Student * startIndexTable){
	if(startIndexTable == NULL){
		printf("Index tablosuna veri girisi yapilmadi!!!");
	}
	else{
		Student* currentStudent = startIndexTable;
		while(currentStudent != NULL){
			printf("%d,",currentStudent->index);
			currentStudent = currentStudent->nextStudent ;
		}
	}
}//yazdir() sonu  problemsiz calisiyor





