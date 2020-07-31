
/* programma gia sta8mo diodion*/

#include<stdio.h>
#include<math.h>
int main(int argc,char *argv[]){
  double total, xreosi_autoki,xreosi_fort,xreosi_moto,xreosi_leof,poso,ipol,num_bus,num_car,num_moto,num_truck,xreosi,epipleon_poso;
  char veh_type;                                          /*    tipos oximatos       */
  int chan_1,chan_10,chan_20,chan_5,num_vehicles,chan_01;
   xreosi_autoki=2.35;	                                  /*xreosi gia autokinita    */
   xreosi_moto=1.25;                                      /*xreosi gia motosikletes  */
   xreosi_fort=8.40;                                      /*xreosi gia foriga oximata*/
   xreosi_leof=16.50;	                                  /*xreosi gia leoforia      */
   num_bus=0;
   num_car=0;
   num_moto=0;
   num_truck=0;
  
   
   /*pollaplh anagnosi oximaton kai ektelesis tou body mexri na do8ei o xarakthras 0*/
   
   do{
      printf("Enter vehicle type: ");
      scanf(" %c",&veh_type); 
      if (veh_type=='0'){break;
      }
      
      else{
      
      
      /*anagnorisi tipou oximatos kai ipologismos ari8mou ana tipo oximatos*/
      
      switch (veh_type){
                 
        case ('M'): printf("PAY %4.2lf \n",xreosi_moto);
                       	   // printf("> ");
	                    xreosi=xreosi_moto;
			    num_moto=num_moto+1 ;break;
	case ('m'): printf("PAY %4.2lf \n",xreosi_moto);      /*tipos oximatos:autokinitou */
                     	    //printf("> ");
	                    xreosi=xreosi_moto;
			    num_moto=num_moto+1 ;break;
       
	case ('C'): printf("PAY %4.2lf \n",xreosi_autoki);
	                    //printf("> ");
	                    xreosi=xreosi_autoki;
			    num_car=num_car+1 ;break;
        case ('c'): printf("PAY %4.2lf \n",xreosi_autoki);
	                    //printf("> ");
	                    xreosi=xreosi_autoki;
			    num_car=num_car+1 ;break;
  
	case ('T'): printf("PAY %4.2lf \n",xreosi_fort);
	                    //printf("> ");
	                    xreosi=xreosi_fort;
			    num_truck=num_truck+1;break;
        case ('t'): printf("PAY %4.2lf \n",xreosi_fort);
	                    //printf("> ");
	                    xreosi=xreosi_fort;
			    num_truck=num_truck+1 ;break;
      
	case ('B'): printf("PAY %4.2lf \n",xreosi_leof);
	                    //printf("> ");
	                    xreosi=xreosi_leof;
			    num_bus=num_bus+1 ;break;
        case ('b'): printf("PAY %4.2lf \n",xreosi_leof);
	                    //printf("> ");
	                    xreosi=xreosi_leof;
			    num_bus=num_bus+1;break;
        
        default: break;
      }
      
   }

   scanf(" %lf",&poso);
      
      /*ektiposi kai ipologismos ipolipomenou xreostoumenou an poso <apo tin antistoixi xreosi*/
   while (poso<xreosi){
		
		  if (poso<xreosi){
		    printf("> PAY  %2.2lf more  \n",(xreosi-poso));  /*ipolipomeno xreos*/
		    
		    scanf("%lf",&epipleon_poso);
		    poso=poso+epipleon_poso;}                   /*neo epauximeno do8en xrimatiko poso*/
		  else 
		    {break;}}
                 
   printf("> ");
       
       /*ipologismos kai ektiposi reston */
      
       
   if (poso>xreosi){
		   chan_20=(poso-xreosi)/20;             /*chan_20= ari8mos 20euron xartonomismaton*/
		   ipol=((poso-xreosi)-(chan_20*20));    
		   chan_5=ipol/5;                        /*chan_5= ari8mos 5euron xartonomismaton  */
		   ipol=ipol-(chan_5*5);
		   chan_1=(ipol)/1;                      /*chan_1=ari8mos 1euron nomismaton        */
		   ipol=ipol-chan_1;
		   chan_10=(ipol/0.1);              /*chan_10=ari8mos 10lepton nomismaton     */
		   ipol=ipol-chan_10*0.1;
		   
		   if ((ipol>0.1)||(ipol>0.099)){
		     chan_10=chan_10+1;
		     ipol=ipol-0.1;}
		   chan_01=round(ipol/0.01);             /*chan_01=ari8mos 1lepton nomismaton      */
		   
		   printf("Amount Received: %2.2lf euro\n",poso);
		   printf("Change: \n");
		   if (chan_20!=0){
                        printf("%d of 20 euro \n",chan_20);}
		   else {}
		   if (chan_5!=0){
		       printf("%d of 5 euro \n",chan_5);}
		   else {}
                   if (chan_1!=0){
		       printf("%d of 1 euro \n",chan_1);}
		   else {}
		   if (chan_10!=0)
		       {printf("%d of 10 cents \n",chan_10);}
		   else{}
		   if (chan_01>0){
		       printf("%d of 1 cent \n",chan_01);}
		   else{}
		  }
   else {printf(" Change 0 \n");}
    
    
     }
   while (veh_type!='0');
  
  /*ipologismos kai ektiposi esodon ana tipo  oximatos kai sinoliko*/
  
   total=(num_bus*xreosi_leof)+(num_car*xreosi_autoki)+(num_moto*xreosi_moto)+(num_truck*xreosi_fort); 
   num_vehicles=num_bus+num_car+num_moto+num_truck;
   printf("\nNumber of vehicles: %7d \n",num_vehicles);
   printf("    Motorcycles:    %7.2lf \n",num_moto*xreosi_moto);        /*esoda apo mixanes   */
   printf("           Cars:    %7.2lf \n",num_car*xreosi_autoki);       /*esoda apo autokinita*/
   printf("          Buses:    %7.2lf \n",num_bus*xreosi_leof);         /*esoda apo leoforia  */
   printf("         Trucks:    %7.2lf \n",num_truck*xreosi_fort);       /*esoda apo fortiga   */
   printf("          Total:   %8.2lf \n",total);                        /*sinolika esoda      */
  
   return 0;
}