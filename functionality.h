/* Naveed Ahmed
   22i-0889
   Project
*/






/* PROGRAMMING FUNDAMENTAL'S PROJECT FOR FALL 2022 BS(CS)
 * You need to define the required function in the part instructed here below.
 * Avoid making any unnecessary changes, particularly the ones you don't understand.
 * The different pieces should be defined using an array - uncomment the following code once you are done creating the array.
 * TIP: Understand thoroughly before getting started with coding.
 * */

//---Piece Starts to Fall When Game Starts---//
#include <iostream>
//Function #1
void fallingPiece(float& timer, float& delay, int& colorNum, int& n){
	
    if (timer>delay){
           for (int i=0;i<4;i++){
              point_2[i][0]=point_1[i][0];	//Each and every value of array point_1 is assigned to point_2 array
              point_2[i][1]=point_1[i][1];	//in these two lines
	                            
        	  point_1[i][1]+=1;		/*How much units downward...This phenomenon is used to develop functions for movement of piece towards 	
        	  						right or left.
        	  						if it was point_1[i][1]+=n, the block would have dropped n units*/		           	  
        	}
       
        
        if (!anamoly()){
        	for (int i=0; i<4; i++)
        		gameGrid[point_2[i][1]][point_2[i][0]]=colorNum;
        		colorNum=1+rand()%7;	//1-7 Colours
            	n=rand()%7;		//The random number n generated determines the shape of the upcoming block
            //--- Un-Comment this Part When You Make BLOCKS array---//	(uncommented)
            
                for (int i=0;i<4;i++){
                    point_1[i][0] = BLOCKS[n][i] % 2;	
                    point_1[i][1] = BLOCKS[n][i] / 2;
                    
                }
        }
        
        timer=0;
    }
    delay=0.3;   
}

/////////////////////////////////////////////
///*** START CODING YOUR FUNTIONS HERE ***///

//Function #1
void dropp(float& delay, bool& space){
	delay=0.01;
	space=0;
}
           

//Function #3
void removesqaureblock()	
	{	
		for (int j=0; j<M; j++)
			for (int i=0;i<4;i++)
              	point_1[i][1]+=2;
    }
              


//Function #4              
void movement_Piece_Right ()
	{
		if ((point_1[0][0]<9 && point_1[1][0]<9 && point_1[2][0]<9 && point_1[3][0]<9)) 
        	for (int i=0;i<4;i++)
        		point_1[i][0]+=1; 		/*This was for units downward but when point_1[i][1] is replaced with point_1[i][0] the 
              							movement is towards right*/		 	 
        	
        	
    }



//Function #5
void movement_Piece_Left ()
	{
		if (point_1[0][0]>0 && point_1[1][0]>0 && point_1[2][0]>0 && point_1[3][0]>0) 
        	for (int i=0;i<4;i++)
            	  point_1[i][0]-=1; 		/*This was for units downward but when point_1[i][1]+=1 is replaced with point_1[i][0]-=1 the 
         								movement is towards left */
		
    
    }
    
    
    
//Function #6
void funrot(int& n)
	{
	if(n==1 && ((point_1[0][0]<8 && point_1[1][0]<8 && point_1[2][0]<8 && point_1[3][0]<8 && point_1[0][0]>1 && point_1[1][0]>1 && point_1[2][0]>1 && point_1[3][0]>1) || ((point_1[1][0]-point_1[0][0]==1 || point_1[1][0]-point_1[0][0]==-1)))){
		int counter=0;
        while (counter<=3)
          {
            int a = point_1[counter][1]-point_1[1][1];
            int b = point_1[counter][0]-point_1[1][0];
            point_1[counter][0]=point_1[1][0]-a;
           	point_1[counter][1]=point_1[1][1]+b;
            counter++;
          }
        counter=-1;
        if (!anamoly())
        {  
           	do 
           	{
           		for (int count=0; count<2; count++)
           			point_1[count][0]=point_2[count][0];
           		counter++;
           	}
           	while (counter<4);
 		}
		
      }
	else if (n!=1 && (point_1[0][0]>0 && point_1[1][0]>0 && point_1[2][0]>0 && point_1[3][0]>0 && point_1[0][0]<9 && point_1[1][0]<9 && point_1[2][0]<9 && point_1[3][0]<9)){
		int counter=0;
        while (counter<=3)
          {
            int a = point_1[counter][1]-point_1[1][1];
            int b = point_1[counter][0]-point_1[1][0];
            point_1[counter][0]=point_1[1][0]-a;
           	point_1[counter][1]=point_1[1][1]+b;
            counter++;
          }
        counter=-1;
        if (!anamoly())
        {  
           	do 
           	{
           		for (int count=0; count<2; count++)
           			point_1[count][0]=point_2[count][0];
           		counter++;
           	}
           	while (counter<4);
 		}
		
          
     
           
      }
		
	  }


//Function #7
void lineerase(int& score)
{	int count4score=0;
	short int temp=M-1;	//because 19 is the height 
	short int counter=M-1;	
    while (counter>0)	//because 19 is the height
    {
        int tally=0;
        int count2=0;
        do 
        {
            if (gameGrid[counter][count2]){ 
            	tally++; 
            }
            gameGrid[temp][count2]=gameGrid[counter][count2];
        	count2++;    	
        }
        while (count2<N);
        if (tally<N) 
        	temp--;
        else{ 
        	count4score++;
        	switch (count4score)
        	{
        		case 1:
        		score+=10;
        		break;
        		case 2:
        		score+=20;
        		break;
        		case 3:
        		score+=30;
        		break;
        		case 4:
        		score+=40;
        		break;
        		default:
        		score=100;
        	}
        	}
        counter--;
        	}
      
	count4score=0;
}
 
 
 //Function #8:
 void endthegame(bool& endgame){
 	for (int count=0; count<4; count++)
 		if (gameGrid[point_1[count][1]][point_1[count][0]]){
 			endgame=1;
 		}         	
}


//Function #9:
void menuu(bool& menu){
	menu=1;
}

//Function #10:
void exittt(bool& exit){
	exit=1;
}
		


				
	
		


///*** YOUR FUNCTIONS END HERE ***///
/////////////////////////////////////
