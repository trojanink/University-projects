

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include<sys/time.h>

#define VEHICLES 10000  // diathesimes theseis gia oximata ston pinaka 
#define STRLEN 20       // megethos tou kathe string ston pinaka		  

#define MAMOUNT  1.25   // timi gia motosikletes
#define CAMOUNT  2.35   // timi gia autokinita
#define TAMOUNT  8.40   // timi gia fortiga
#define BAMOUNT 16.50   // timi gia leoforeia

//opou false keni thesi pinaka opou true kataxorimeno oxima
enum boolean{false, true};

//dimiourgia tipou struct me onoma oximata gia tin apothikeusi ton dedomenwn
typedef struct {
	char type;             //tipos oximatos
	char pinakida[STRLEN]; //arithmos plaisiou
	double amount;         //xreostoumeno poso
	enum boolean valid;    //iparksi kataxorisis (false/true)
}oximata;


/** data_input 
 * -----------
 * parametros: pinakas struct oximata
 * 
 * @diavazei tis kataxoriseis oximatwn
 * kai tis vazei ston pinaka
 ****************************************/
void data_input ( oximata veh[]){
	
	char pinakida_char[4], pinakida_num[5];
	double paid, balance;
	int i; 

	//arxikopiisi olwn twn timwn valid se false
	for(i=0; i< VEHICLES; i++){
		veh[i].valid = false;
	}
	
	//epanalipsi eisagogis dedomenwn mexri na diavastei timi 0 i na gemisei o pinakas
	for(i=0; i<VEHICLES; i++){
		
		//eisagogi tipou oximatos
		scanf(" %c", &veh[i].type); 
		//telos epanalipsis an diavastei timi 0
		if (veh[i].type=='0'){break;}
		else{ veh[i].valid=true;}
		
		//eisagogi stoixeiwn oximatos
		scanf("%3s", pinakida_char);
		scanf("%4s", pinakida_num);
		scanf("%lf", &paid);
		
		//metatropi tipou oximatos se kefalaio
		veh[i].type = toupper(veh[i].type);
	
		//ipologismos posou pou ofeilei to kathe oxima
		switch (veh[i].type){
			case 'M':
				balance = MAMOUNT;
				break;
			case 'C':
				balance = CAMOUNT;
				break;
			case 'T':
				balance = TAMOUNT;
				break;
			case 'B':
				balance = BAMOUNT;
				break;
		}
		
		//ipologismos posou pou xrostaei to oxima
		if (balance>paid){
			veh[i].amount = balance - paid;
		}
		else{
			veh[i].amount=0;
		}
		//apothikeusi ton stoixeiwn ston pinaka string
		sprintf(veh[i].pinakida,"%s %s", pinakida_char, pinakida_num);
	}
}

/** selection_sort 
 * ---------------
 * parametros: pinakas struct oximata
 * 
 * @taksinomei ton pinaka struct me 
 * xrisi selection sort
 ****************************************/
void selection_sort (oximata veh[]){
	
	int i,j; 
	int min;
	oximata temp2;
	
	//algorithmos selection sort
	for (i=0; i< VEHICLES; i++) {
		min = i;
		for (j=i+1; j< VEHICLES; j++) {
			if (strcmp(veh[j].pinakida,veh[min].pinakida)<0) {
				min = j;
			}
		}
		if (min != i) {
			//antimetathesi pinaka struct
			temp2=veh[i];
			veh[i]=veh[min];
			veh[min]=temp2;
		}
	}
}

/** insertion_sort 
 * ---------------
 * parametros: pinakas struct oximata
 * 
 * @taksinomei ton pinaka struct me 
 * xrisi insertion sort
 ****************************************/
void insertion_sort(oximata veh[]){
	int wall, j;
	oximata numtosort;
	
	//algorithmos insertion sort
	for (wall=1; wall<VEHICLES; wall++){
		numtosort = veh[wall];
		j=wall-1;
		while (j >= 0 && strcmp(veh[j].pinakida, numtosort.pinakida)>0){
			
			veh[j+1] = veh[j];
			j--;
		}
		
		veh[j+1] = numtosort;
	}
}

/** bubble_sort 
 * ------------
 * parametros: pinakas struct oximata
 * 
 * @taksinomei ton pinaka struct me 
 * xrisi bubble sort
 ****************************************/
void bubble_sort(oximata veh[])
{
	int i, j;
	oximata temp2; //voithitiki metavliti antimetathesis
	
	//algoritmos bubble sort
	for (i=VEHICLES-1; i>0; i--){
		for (j=1; j<=i; j++){
			if (strcmp(veh[j-1].pinakida, veh[j].pinakida)>0){
				//antimetathesi struct 
				temp2=veh[j];
				veh[j]=veh[j-1];
				veh[j-1]=temp2;
			}
		}
	}
}


/** amount_sum 
 * -----------
 * parametroi: 
 * -pinakas struct oximata
 * -start: i proti thesi pou dixnei poso pou xrostaei 
 * -end: i teleutaia thesi pou dixnei to poso pou xrostaei
 * @epistrefei to sinoliko poso pou xrostaei to kathe oxima 
 * pou einai kataxorimeno polles fores
 ***********************************************************/
double amount_sum (int start, int end, oximata veh[]){
	
	int i;
	double sum=0;
	
	//prosthesi poswn sto sum
	for(i=start; i<=end; i++){
		sum = sum + veh[i].amount;
	}
	
	return sum;
}


/** find_same 
 * ----------
 * parametroi: 
 * -pinakas struct oximata
 * @vriskei tis theseis stis opoies iparxoun kataxoriseis 
 * tou idiou oximatos, frontizei na sigkentrwthoun se mia
 * kai adeiazei tis ipolipes
 ***********************************************************/
void find_same (oximata veh[]){
	
	//o start einai deiktis pou dixnei tin prwti thesi pou periexei idia oximata kai o end tin teleutaia
	int start=0,end=0,j,i; 
	
	/* 
	 * o algorithmos elegxei an kathe pinakida tou pinaka einai iso me to proigoumeno tou
	 * oso vriskei oti oi 2 times einai ises allazei ton dikti tis telikis thesis, meta
	 * an iparxoun diples kataxoriseis kalei tin sinartisi amount_sum gia na ipologisei 
	 * to sinolo pou xrostaei sigxoneuei tis diplokataxoriseis kai telos allazei tin 
	 * thesi tou deikti start sti nea thesi 
	 */
	for (i=1; i< VEHICLES; i++){
		while( strcmp(veh[i-1].pinakida,veh[i].pinakida)==0 && i<VEHICLES){
			end=i;
			i++; 
		}
		if(end>start){
			veh[start].amount= amount_sum(start,end,veh);
			for(j=start+1; j<=end; j++){
				veh[j].valid=false;
			}
		}
		start=i;
	}
}

/** print_arrays 
 * -------------
 * parametroi: 
 * -pinakas struct oximata
 * @ektiponei tis kataxoriseis (pinakida, tipos,xreos)
 ***********************************************************/
void print_arrays(oximata veh[]){
	
	int i;
	
	for(i=0; i< VEHICLES; i++){
		//elegxos an i thesi einai egkiri
		if(veh[i].valid){
			printf("%11s %c, %.2lf\n", veh[i].pinakida,veh[i].type,veh[i].amount);
		}
	}
	
	//ektiposi diaxoristikou (=)
	for(i=1; i<=20 ; i++){
		printf("=");
	}
	printf("\n");
}


/** total_amount_owed
 * ------------------
 * parametroi: 
 * -pinakas struct oximata
 * @epistrefei to sinoliko poso pou xrostane ola ta oximat
 ***********************************************************/
double total_amount_owed (oximata veh[]){
	
	int i;
	double sum=0;

	//prosthesi poswn sto sum
	for (i=0; i<VEHICLES; i++){
		if(veh[i].valid){
			sum = sum + veh[i].amount;
		}
	}

	return sum;
}


/** average_type_owes
 * ------------------
 * parametroi: 
 * -type: o tipos oximatwn
 * -pinakas struct oximata
 * @epistrefei to meso oro ton xreon olon ton oximatwn mias
 * katigorias
 ***********************************************************/
double average_type_owes (char type, oximata veh[]){

	int i,vehnumber=0;
	double sum=0;
	
	for (i=0; i< VEHICLES; i++){
		 //elegxos an iparxei oxima sti sigkekrimeni thesi, an einai autou tou tipou kai an xrostaei
		 // an nai auksanei ton arithmo oximaton kai prosthetei to poso
		if(veh[i].valid && type == veh[i].type && veh[i].amount>0){
			vehnumber++;
			sum=sum+veh[i].amount; //sinoliko poso
		}
	}
	
	//ipologismos mesou orou an iparxoun oximata autou tou tupou
	if(vehnumber>0){
		sum = sum/vehnumber;
	}
	
	return sum;
}

/** print_stats
 * -----------
 * parametroi: 
 * -pinakas struct oximata
 * @ektiponei ta statistika 
 ***********************************************************/
void print_stats (oximata veh[]){

	printf("Total amount owed: %.2lf euros\n", total_amount_owed(veh));
	printf("Motorcycles owe %.2lf euros on average\n", average_type_owes('M', veh));
	printf("Cars owe %.2lf euros on average\n", average_type_owes('C', veh));
	printf("Buses owe %.2lf euros on average\n", average_type_owes('B', veh));
	printf("Trucks owe %.2lf euros on average\n", average_type_owes('T', veh));
}


int main(int argc, char *argv[]){

	double total_mic;
	struct timeval start, end;
	oximata veh[VEHICLES];
	
	data_input (veh); // anagnosi dedomenwn
	
	//taksinomisi analoga tin epilogi tou xristi
	//kai ipologismos xronou ektelesis
	
	if(argc>1){
	
		switch (*argv[1]){
			case '2' :
				gettimeofday(&start,NULL);
				selection_sort (veh);
				gettimeofday(&end,NULL);
				break;
			case '3' :
				gettimeofday(&start,NULL);
				bubble_sort(veh);
				gettimeofday(&end,NULL);
				break;
			default :
				gettimeofday(&start,NULL);
				insertion_sort(veh);
				gettimeofday(&end,NULL);
		}
	}
	else{
		gettimeofday(&start,NULL);
		insertion_sort(veh);
		gettimeofday(&end,NULL);
		
	}
	
	
	//ipologismos microsecond xronou ektelesis
	total_mic=(end.tv_sec-start.tv_sec)*(1000000)+end.tv_usec-start.tv_usec;
	

	

	find_same    (veh);  //entopismos idion kataxorisewn
	print_arrays (veh);  //ektiposi kataxorisewn
	print_stats  (veh);  //ektiposi statistikwn
	printf("TIME TO SORT:%lf \n",total_mic);
	

return 0;


}
/**   gettimeofday tests 
 * ----------------------
 * 
 * time for test 1 (microseconds):
 * 	---insection sort:    1858
 *  ---selection sort:  543056
 *  ---bubble sort   :  540341
 * 
 * time for test 2 (microseconds):
 *  ---insection sort:  168164
 *  ---selection sort:  565126
 *  ---bubble sort   :  775233
 *
 * time for test 3 (microseconds):
 *  ---insection sort:  416671
 *  ---selection sort:  575490
 *  ---bubble sort   : 2638323
 *
 * 
 * Simfona me ta test fenete oti i insection sort einai h pio grigori gia to sigekrimeno ari8mo stoixeion 
 * ostoso oso auxanetai o ari8mos ton stoixeion auxanetai kata poli o xronos ektelesis 
 * 
 * Apo thn alli i selection sort an kai pio argh sta sigekrimena test elegxoy
 * einai pio statheri sto xrono ektelesis tis akoma kai otan auxanontai oi kataxoriseis
 * 
 * H buuble sort simperasmatika einai i katapoli pio argh apo tis proigoumenes 2 taxinomiseis anexarthta apo ton ari8mo ton kataxoriseon
 * auksanetai me ton pio megalo rithmo apo tis ipolipes kai malista me geometriko rithmo
 * 
 * gia to sigkekrimeno programa
 * gia arxeia elegxou megethous mexri peripou 10 000 pio grigori einai i selection sort
 * gia megalitera arxeia elegxou i selection sort tha einai pio grigori apo tin insection
 * i bubble sort fainetai na einai i pio argi se oles tis periptoseis
 *************************************************************************************************/