/* Naveed Ahmed
   22i-0889
   Project
*/








/* PROGRAMMING FUNDAMENTAL'S PROJECT FOR FALL 2022 BS(CS)
 * You don't need to change anything in the driver code/main function except the part(s) where instructed.
 * You are expected to define your functionalities in the "functionality.h" header and call them here in the instructed part(s).
 * The game is started with a small box, you need to create other possible in "pieces.h" file in form of array.
    E.g., Syntax for 2 pieces, each having four coordinates -> int Pieces[2][4];
 * Load the images into the textures objects from img directory.
 * Don't make any changes to the "utils.h" header file except for changing the coordinate of screen or global variables of the game.
 * SUGGESTION: If you want to make changes in "utils.h", do it once you complete rest of the functionalities.
 * TIP: You can study SFML for drawing scenes, sprites and window.
 * */


   

#include <SFML/Graphics.hpp>
#include <time.h>
#include "utils.h"
#include "pieces.h"
#include "functionality.h"
#include <iostream>
#include <string>
#include <sstream>
#include <iostream>
using namespace sf;

int main(){


	
    srand(time(0));
    RenderWindow window(VideoMode(320, 480), title);
    Texture obj1, obj2, obj3, obj4, obj5;
    /*
        Load "frames.png","tiles.png" and "background.png" for Texture objects
    */
    obj1.loadFromFile("img/tiles.png");
    obj2.loadFromFile("img/background.jpg");
    obj3.loadFromFile("img/frame.png");
    obj4.loadFromFile("img/menu.png");
    obj5.loadFromFile("img/gameover.png");
    Sprite sprite(obj1), background(obj2), frame(obj3), menu(obj4), gameover(obj5);
    int delta_x=0, colorNum=1;
    float timer=0, delay=0.3;
    bool rotate=1;
   	bool space=0;
    Clock clock;
    int counter=0;
    int score=0;	
    bool stopp=false; 	
    int n;
    bool endgame=0;
    bool menuuu=0;
    bool exitt=0;	
    
	/*	////////Purposes of Variables Created////////
	
	  delta_x variable is for left and right movement of the block
	  colorNum for changing color of the blocks
	  timer to note time
	  delay to reduce speed of a block
	  rotate is for rotating a block whenever the Up key is pressed
	  space is for dropping a block immediately when space is pressed 
	  counter is for the purpose of removing the first square block
	  score is for displaying score
	  stopp is to pause the game whenever H is pressed
	  n is type of block
	  endgame is to end the game whenever blocks reach the top
	  menuuu is to be turned on when H key is pressed
	  exitt is to be turned on when Q key is pressed while the user is in the menu
	*/


	
    while (window.isOpen()){
	    float time = clock.getElapsedTime().asSeconds();
        clock.restart();
        timer+=time;
        //---Event Listening Part---//
        Event e;
        while (window.pollEvent(e)){                    //Event is occurring - until the game is in running state
            if (e.type == Event::Closed)                   //If cross/close is clicked/pressed
                window.close();                            //Opened window disposes
            if (e.type == Event::KeyPressed) {             //If any other key (not cross) is pressed
                if (e.key.code == Keyboard::Up)            //Check if the other key pressed is UP key
                    rotate = true;                         //Rotation gets on	
                else if (e.key.code == Keyboard::Left)     //Check if the other key pressed is LEFT key
                    delta_x = -1;                          //Change in X-Axis - Negative
                else if (e.key.code == Keyboard::Right)    //Check if the other key pressed is RIGHT key
                    delta_x = 1;                           //Change in X-Axis - Positive                                        
            }
        }
        if (Keyboard::isKeyPressed(Keyboard::Down))   //Just another way to detect key presses without event listener
            delay=0.05;                                    //If DOWN key is pressed, delay in falling piece decreases from 0 to 0.05
        if (Keyboard::isKeyPressed(Keyboard::H)) 
        	stopp=true;
        if (Keyboard::isKeyPressed(Keyboard::Escape)){
        	stopp=false;	
        	menuuu=false;
        }
        if (Keyboard::isKeyPressed(Keyboard::Space))
        	space=true;
        
        	
            
        ///////////////////////////////////////////////
        ///*** START CALLING YOUR FUNCTIONS HERE ***///
        
        //!stopp condition is applied in every function to run the function only when the game is in the running state
		//Some functions are called before the others in order for the program to run properly
		
		///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		//Function #9:
		if (Keyboard::isKeyPressed(Keyboard::H))
   			menuu(menuuu); 	//This function will turn on the bool variable menuuu which will result in menu display
       
       
       
       ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
          			
   		
   		
   		
   		//Function #10:
   		if (Keyboard::isKeyPressed(Keyboard::Q))
        	exittt(exitt);	//This function will turn on the exitt variable which will result in window closing




       ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
       		



		//Function #1 
		if (space && !stopp)
        	dropp(delay, space);	//What dropp does is reduce the delay whenever the space key is pressed for thhat block



       ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
       		



		//Function #2:
		if (!stopp)
        fallingPiece(timer, delay, colorNum, n);               /*Example: fallingPiece() function is called here in order to make the  
														        pieces fall randomly from 7 colours and 7 shapes. 
       															This function also determines how much units the piece will fall in its 				
       															regular movement*/
        
         
        	
  
       ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
       
       
       
       
        if (counter<1)		
        	{
        		//Function #3:
        		removesqaureblock();	/*The function is called to remove the first square block (given by default in skeleton code)
        								 and another square block which turned out when we applied the rotation technique*/ 
        		counter++;	//To ensure that this function is called is called only one time to remove only the first block
        	}
       
       
         
        	
  
       ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
       
       
       
       
       
       
        if (delta_x==1 && !stopp)	//if the right key is pressed
        	//Function #4:
        	movement_Piece_Right();						//Function is called if right key is pressed to move the block one unit right
       
       
       
       
       
       ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
       
       
        
        
        else if (delta_x==-1 && !stopp)	//if the left key is pressed
        	//Function #5:
        	movement_Piece_Left();						//Function is called if left key is pressed to move the block one unit left
     
         
        	
  
       ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
     	
     	
     	
     	
     	
     	if (rotate && !stopp)
     		//Function #6:
      		funrot(n);	/*This Function is to rotate blocks. Whenever Up key is pressed, rotate becomes true and whenenver rotate=true, 					
        				  this function is called*/
        
         
        	
  
       ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
       
       
       
        				  
        				  
        //Function #7:
        lineerase(score);	//This function will erase the line that is filled with blocks
        
       
       
       ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        
        
        
        //Function #8:
        endthegame(endgame);	/*This function is called to check if the blocks have reached uptop and if they have reached uptop, the
        						  endgame variable becomes true*/
        						  
        						  
   		 	
        	
        
        
        
        
        
        	
        
        ///*** YOUR CALLING STATEMENTS END HERE ***///
        //////////////////////////////////////////////
		
		
		
			

      
       	 
      	  window.clear(Color::Black);
      	  window.draw(background); 
        
        for (int i=0; i<M; i++){
            for (int j=0; j<N; j++){
                if (gameGrid[i][j]==0)
                    continue;
                sprite.setTextureRect(IntRect(gameGrid[i][j]*18,0,18,18));
                sprite.setPosition(j*18,i*18);
                sprite.move(28,31); //offset
                window.draw(sprite);
            }
        }
        for (int i=0; i<4; i++){
            sprite.setTextureRect(IntRect(colorNum*18,0,18,18));
            sprite.setPosition(point_1[i][0]*18,point_1[i][1]*18);
            sprite.move(28,31);
            window.draw(sprite);
          }
            
          
      	
        
        
      
        //---The Final on Which Everything is Drawn Over is Loaded---//
        window.draw(frame);
        
        std::ostringstream str1;
        str1 << score;
        std::string score1 = str1.str();
        sf::Font font;
		if (!font.loadFromFile("arial.ttf"))
		{
			// error...
		}
    	sf::Text text;

		// select the font
		text.setFont(font); 
		// font is a sf::Font
		text.move(240.f, 185.f);

		// set the string to display
		text.setString(score1);

		// set the character size
		text.setCharacterSize(18); // in pixels, not points!

		// set the color
		text.setFillColor(sf::Color::White);
		
		// set the text style
		text.setStyle(sf::Text::Bold);
		
		
		//Line 253 to 278 are actually sfml code to display score (out of our course's scope)
		
		
		
		
		if (menuuu){				/*if endgame is true i.e. blocks have reached uptop, stopp pause the game and the next two statements
									  display the message Game Over*/ 
        	window.draw(menu);
        	window.display();
        	if (exitt)	//This will close the game windows if Quit option is selected by the user
     			exit(0);
        }
        
		
		if (endgame){				/*if endgame is true i.e. blocks have reached uptop, stopp pause the game and the next two statements
									  display the message Game Over*/ 
        	stopp=true;
        	window.draw(gameover);
        	window.display();
        }
        window.draw(text);	//in order to display score
        //---The Window that now Contains the Frame is Displayed---//
        window.display();
     
     	
     	
     
    //Following variables have been set to their original values after some event has taken place
        delta_x=0;	//delta_x has been set to zero after left or right movement of the block
        delay=0.3;	//delay has been reset to its original value so that the down key has an impact of speeding up the piece motion just for the time when the down key is hold
    	rotate=0;	//if the event of rotation has occured, this line will set rotate value to false 
    	space=0;
    	endgame=0;
    	exitt=0;
    	
		
		

       
       
       
       
      
       }
    return 0;
}
