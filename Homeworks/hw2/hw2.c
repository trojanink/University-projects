
#include<stdio.h>
#include<string.h>
#include<ctype.h>

#define N 10000    /* N o ari8mos ton grammon tou pinaka kataxoriseon*/
#define M 20       /* M o ari8mos ton stilon tou pikaka kataxoriseon */
       

//sinartisi  anagnosis pinakidas kai tipou  oximatos 
void veh_read(char pinakides[N][M],double ofeiles[]){
	
	char char_pinak[4],psifia_pinak[5],veh_type; 
	int i;
	double xreosi,dothen_poso;
  
	for(i=0;i<N;i++){
		scanf(" %c",&veh_type); //tipos oximatos
		veh_type=toupper(veh_type);
	 
		if(veh_type=='0'){     //elegxos gia egiri eisodo oximatos 
			break;
		}

		scanf("%3s",char_pinak);      //xaraktires pinakidas oximatos
		scanf("%4s ",psifia_pinak);   //psifia pinakidas oximatos
		sprintf(pinakides[i],"%s %s %c",char_pinak,psifia_pinak,veh_type);   //dimiourgia disdiastatou pinaka 
		scanf("%lf",&dothen_poso);   //anagnosi do8entos posou
	 
		//ipologismos antitimou analoga me ton tipo tou oximatos  
		switch (veh_type){	
			case ('C'):{      //tipos oximatos autokinito
				xreosi=2.35;  //antistoixh xreosi
				break;
			}
			case ('M'):{      //tipos oximatos mixani
				xreosi=1.25;   
				break;
			}
			case ('T'):{     //tipos oximatos fortigo
				xreosi=8.40;   
				break;
			}
			case ('B'):{     //tipos oximatos leoforeio
				xreosi=16.50;  
				break;
			}
		}
	  
		//elegxos diaforas do8entos posou kai xreosis
		if (dothen_poso<xreosi){
			ofeiles[i]=(xreosi-dothen_poso);   //dimiourgia pinaka ofeilon 
		}
	}
}
   

//sinartisi lexikografikis taxinomisis pinakon analoga me thn pinakida tou oximatos
void taxinomisi(char pinakides[][M],double ofeiles[]){
	
	int i,j,min;
	char temp[M]; //string voi8itikis metavlitis gia thn antimeta8esi ston pinaka ton kataxorimenon 
	double temp2; //voi8itiki metavliti gia thn antimeta8esi stoixeion ston pinaka ofeilon
	
	//taxinomisi pinaka me auxousa seira me th me8odo selection sort
	for (i=0;i<N;i++){
		min=i;
		for(j=i+1;j<N;j++){
			if ((strcmp(pinakides[j],pinakides[min]))<0){
				min=j;
			}
		}
		//antimeta8esi stoixeion me xrisi voi8itikis metavlitis
		if (min!=i){
			strcpy(temp,pinakides[min]);	  
			strcpy(pinakides[min],pinakides[i]); 
			strcpy(pinakides[i],temp);
			temp2=ofeiles[min];                                           
			ofeiles[min]=ofeiles[i];    
			ofeiles[i]=temp2;
		}
	}
}
     


//ipologismos sinolikon xreon gia sigekrimeno oxima pou exei diplokataxori8ei
double summary(int start_point,int end_point,double ofeiles[]){
	int i;
	double sum_xreosi=0;   //sinoliko xreos sigekrimenou autokinitou  
	
	for(i=start_point;i<end_point;i++){
		sum_xreosi=sum_xreosi+ofeiles[i]; //a8roisma ofeilon  
	}
return (sum_xreosi);
}
      
       

//ipologismos ari8mou omoion kataxoriseon
void sigxoneusi(char pinakides[N][M],double ofeiles[]){
	int start,end=0,i;    //start  o deiktis pou deixnei pou xekina i diplokataxorisi eno end pou telionei
	
	for(i=0;i<N;i=end){
		start=i;            
		end=start+1;
	
		while ((strcmp(pinakides[start],pinakides[end]))==0){   //ipologismos deikti end 
			//sigxoneusi diplokataxoriseon ston pinaka kataxoriseon kai  antikatastash ton diplokataxoriseon me keno xarakthra
			sprintf(pinakides[end],"<");   
			end++; //metritis deikti end
		}
		//o deiktis end einai prosauximenos kata mia monada etsi oste h for na sinexizei apo thn epomenh kataxorisi
		
		//elegxos gia to an iprxan diplokataxoriseis gia to sigkekrimeno oxima sti 8esi i tou pinaka kataxoriseon 
		if(end-start>1){
			//kaleitai i sinartisi  summary gia thn sixoneusi tou pinaka xreostoumenon sta stoixeia pou einai diplaktaxorimena
			ofeiles[start]=summary(start,end,ofeiles);    
		}
		
		for(i=start+1;i<end;i++){
			ofeiles[i]=0;   //midenismos ton kelion  pou exoun diagrafei logo sigxoneusis 
		}
    }
}



//ektiposi stoixeion oximaton
void ektiposi(char pinakides[][M],double ofeiles[]){
   int i;
   
	for(i=0;i<N;i++){
		if((strcmp(pinakides[i],"<"))!=0){ //ektiposi stoixeion t pinaka kataxoriseon(stoixeia oximaton) pou dn einai kena 
			printf("%11s, %5.2lf\n",pinakides[i],ofeiles[i]);
		}
	}
	
	for(i=0;i<20;i++){
		printf("=");   //ektiposi 20  xaraktiron '=' meta tin ektiposi ton stoixeion tou pinaka kataxoriseon
	}
	printf("\n");    //allagh  grammhs istera apo tin ektiposi ton  20 xaraktiron
}
  


//sinartisi pou  ipologizei ta sinolika xreostoumena olon ton oximaton tou pinaka,pantos tipou
double entire_summary(double ofeiles[]){
	int i;
	double total_sum=0;  //summary=sinolika xreh olon ton oximaton tou pinaka kataxoriseon
   
	for(i=0;i<N;i++){
		total_sum=total_sum+ofeiles[i];  //a8roisths olon ton xreon ton oximaton tou pinaka 
	}
return total_sum;
}
   
 

//sinartisi pou ipologizei ton meso oro ofeilon gia sigekrimeno tipo oximatos
double veh_average(double ofeiles[],char veh_type,char pinakides[][M]){
	int i,number=0;     
	double veh_sinolo=0,average=0;   //veh_typ=do8en tipos oximatos pros anazitisi kai a8roisma sinolikon ofeilon
   
	for(i=0;i<N;i++){
		//elegxos kai anazitisi oximaton idiou tipou  me tou do8entos veh_typ(anazitisi sto 8 stoixeiou tou string
		//pou einai apo8ikeumenos   o xaraktiras pou dilonei ton tipo tou oximatos
		if(((pinakides[i][8]==veh_type)||(pinakides[i][9]==veh_type)) && (ofeiles[i]>0)){    
			veh_sinolo=veh_sinolo+ofeiles[i]; //a8roisma ton ofeilon olon ton oximaton tipou veh_typ
			number++;
		}
	}
	if(number>0){
		average=(double)(veh_sinolo/number);  //mesos oros ofeilon g t sigekrimeno tipo oximatos
	}   

return average;   
}
	


//sinartisi  ektiposhs statistikon stoixeion  ofeilon gia ta oximata tou pinaka 
void ektiposi_statistikon(char pinakides[][M],double ofeiles[]){
   
	//ektiposi ofeilon  olon ton oximaton p ipologizetai mesa apo tin sinartisi  entire_summary pou kaleitai
	printf("Total amount owed: %5.2lf euros\n",entire_summary(ofeiles));  
	//mesos oros ofeilon antistoixou tipou oximatos pou ipologizetai meso tis sinartisis veh_average
	printf("Motorcycles owe %5.2lf euros on average\n",veh_average(ofeiles,'M',pinakides));
	printf("Cars owe %5.2lf euros on average\n",veh_average(ofeiles,'C',pinakides));
	printf("Buses owe %5.2lf euros on average\n",veh_average(ofeiles,'B',pinakides));     
	printf("Trucks owe %5.2lf euros on average\n",veh_average(ofeiles,'T',pinakides));    
 }
 
 
int main(int argc,char* argv[]){
	int i;
	char kataxorisi[N][M];
	double xreostoumena[N]={0};  //veh_sum sinolikes ofeiles olon ton oximaton
      
	for(i=0;i<N;i++){
		sprintf(kataxorisi[i],"<"); //arxikopoisi stoixeion tou pinaka kataxoriseon
	}
	  
	veh_read(kataxorisi,xreostoumena);   //klisi sinartisis anagnosis stoixeion apo to pliktrologio
	taxinomisi(kataxorisi,xreostoumena); //klisi sinartisis taxinomisis  ton steixion  
	sigxoneusi(kataxorisi,xreostoumena); //klisi sinartisis sixoneusis kelion
	ektiposi(kataxorisi,xreostoumena);   //klisi sinartisis gia ektiposi steixion pinaka kataxoriseon
	ektiposi_statistikon(kataxorisi,xreostoumena);//klisi sinartisis gia ektiposi statistikon
	  
return 0;
}
      

      