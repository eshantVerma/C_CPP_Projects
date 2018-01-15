#include <stdio.h>
#include <stdlib.h>

void inputSPI();
void what();
void edit();
float calculateCpi(int sem);
void printCpi();
int numberOfSem();
void onStart();
void play();
int getTotalCredits(int sem);
float getTotalGrade(int sem);
float maxCpi(float i);
void printCpi2(float p);
void copyArray(float a[8],float mSpi);
float getCPI();
int getSem();
void loadFile();
void closeFile();



float spi[8] = {0,0,0,0,0,0,0,0};

const int credits[8] = {39,43,37,37,36,36,33,36}; 




void main(){


loadFile();

//onStart();

//closeFile()

}










void loadFile(){

FILE *fptr;

fptr = fopen("cpi.txt","r");
if(fptr == NULL){
printf("File 'cpi.txt' does not exist.\nCreating new blank file cpi.txt");
fptr = fopen("cpi.txt","a+");
}
int i = 0;

while(fscanf(fptr,"%f",&spi[i]) == 1){
i++;
}

fclose(fptr);
onStart();

}


void closeFile(){

FILE *fptr;
fptr = fopen("cpi.txt","a+");


int i =0;
//while(spi[i] != 0){
//fprintf(fptr,"%f\n",spi[i]);
fwrite(spi,sizeof(float),numberOfSem(),fptr);
//i++;
//}

//fflush(fptr);
fclose(fptr);
}


































float getCPI(){
float c;
scanf("%f",&c);
if(c<10 && c>=0){
return c;
} else {
printf("\ninvalid input\n");
getCPI();
}
}

int getSem(){
int c;
scanf("%d",&c);
if(c<9 && c > numberOfSem()){
return c;
} else{
printf("\ninvalid input\n");
getSem();
}
}






void copyArray(float a[8],float p){
int i;
for(i=0;i<8;i++){
a[i] = spi[i];
}
for(i=0;i<8;i++){
if(spi[i] == 0)
spi[i] = p;
}
}



void printCpi2(float p){

float a[8] = {0,0,0,0,0,0,0,0};
copyArray(a,p);


int s = 8;
printf("\n\n----------------------------------------\nSem\tSPI\tCPI\tCredits\n");
int i;
for(i=0;i<s;i++){
printf("%d\t%2.2f\t%2.2f\t%d\n",i+1,spi[i],calculateCpi(i),credits[i]);
}
printf("----------------------------------------");

int q;
for(q=0;q<8;q++){
spi[q] = a[q];
}

}


void play(){
float refCpi;

printf("\nEnter 0 to get expected values for different SPIs\nwhat CPI do you want?\n");
float cpi;
//scanf("%f",&cpi);
cpi = getCPI();
printf("...and by the end of what semester?\n");
int sem;
sem = getSem();
//scanf("%d",&sem);

int numOfSem =(8 - numberOfSem());

//printf("%d\t%d\t%2.2f\n",getTotalCredits(7),getTotalCredits(numberOfSem()-1),getTotalGrade(numberOfSem()));

float mCPI;
mCPI = maxCpi(10);


refCpi = ((cpi * getTotalCredits(sem-1)) - getTotalGrade(numberOfSem()))/(getTotalCredits(sem-1) - getTotalCredits(numberOfSem()-1));

if (cpi == 0){

float i;
float temp; 
for(i=20;i>14;i--){
//printf("hell");
temp = i/2;
printf("\n\n\n\n//////////////////////////////////////\n//////////////////////////////////////\nBy the end 8th semester you would have \nCPI %2.2f for %2.2f SPI evry semester",maxCpi(temp),temp);
printCpi2(temp);
}
} else if ( mCPI > cpi && cpi != 0){
printf("number of semesters left : %d\nYou should get an average of SPI %2.2f every semester to get CPI of %2.2f",numOfSem,refCpi,cpi);
printCpi2(refCpi);
} else{
printf("Sorry, the maximum CPI you can get is \n");
printf("%2.2f\t for 10.00 SPI evry semester",maxCpi(10));
}



onStart();
}


float maxCpi(float i){

float p;

p= ((getTotalGrade(numberOfSem()) + (i * (getTotalCredits(7) - getTotalCredits(numberOfSem()-1)))) / getTotalCredits(7));
//printf("\n\n\n%2.2f\n\n\n",p);

return p;
}




void onStart(){
//getchar();
char e;
printCpi();
printf("\n\nWhat would you like to do?\n1: get expected CPI?\n2: quit?\n");
what();
}


void printCpi(){
int s = numberOfSem();
printf("\n\n***************************************\nSem\tSPI\tCPI\tCredits\n");
int i;
for(i=0;i<s;i++){
printf("%d\t%2.2f\t%2.2f\t%d\n",i+1,spi[i],calculateCpi(i),credits[i]);
}
printf("***************************************");
}


int numberOfSem(){
int q = 0;
while(spi[q] != 0){
q++;
}
return q;
}



float calculateCpi (int sem){
float cpi;
int totalCredits = getTotalCredits(sem);
float totalGrade = getTotalGrade(sem);
cpi = totalGrade/totalCredits;
return cpi;
}

int getTotalCredits(int sem){
int totalCredits = 0;
int t;
for(t=0;t<sem+1;t++){
totalCredits = totalCredits + credits[t];
}
return totalCredits;
}

float getTotalGrade(int sem){
float totalGrade = 0;
int t;
for(t=0;t<sem+1;t++){
totalGrade = totalGrade + ((spi[t] * credits[t]));
}
return totalGrade;
}


void edit(){
inputSPI();
}



void what(){
int i;
//getchar();
scanf("%d",&i);

switch(i){
//case 1:edit();
case 1:play();
case 2:{
	//closeFile();
	return;	
	}
default : {printf("Nigga what?\n");
	onStart();	
	}

}

}



void inputSPI(){

int sem;
float semSpi;

sem = numberOfSem() + 1;
printf("enter spi for semester: %d\n",sem);
//printf("Semester :\n");
//scanf("%d",&sem);

printf("SPI:\n");
semSpi = getCPI();
//scanf("%f",&semSpi);
spi[sem - 1] = semSpi;
getchar();
onStart();

}

