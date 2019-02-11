// Ilias Mastoras  Honors Project Hangman
#include<iostream>
#include<windows.h>
#include<cstring>
#include<cctype>
#include <ctime>
#include <cstdlib>
using namespace std;

void Intro();                       
string Words (int) ;                       
void Correct_Incorrect(int , char );      
char GameOver(int);
void Errors( char []);               
void Levels(int );
  


int main()
{
	Intro() ;

 	
	int level=1;
    int stop=0;
    int z;

   char again='1';
	     
    while ( (stop!=1) || (again!='2') )       
   {
   	
	 
	 char choice[100];  //stores the letter that the user enters. 100 is if the user enters more than one letters
     char Mistakes[16] = {'-',',',' ','-',',',' ','-',',',' ','-',',',' ','-',',',' ','-'};
     
   	
	
    
  	 string word=Words(level) ;          // call the functin which will return me a word to play
  
   
     int count=word.length();           //  finds the length of the word 
   
   
	char *find = new char [count];               //  array to store the word that plays
	char *solution = new char [count];          //   array that displays the word that plays like this  h e _ _ o
	char *storeLetters = new char [count*6];   // stores the letters the user has already entered. Helps to inform the user that he already entered a letter
	strcpy(find, word.c_str());               // copys the selected (string) word to the find  (char) array 
	
	
	 
	Levels(level);   
	
	for (int i=0; i<80; i++) cout<<"=";
	cout<<"\n\n\n";
   
       for (int j=0; j<=count-1; j++)
       {
    	solution[j] ='_';
    	cout<<"  "<<solution[j];           //fills the array, that displays the word,  with underscores and prints it 
       }
    
       for (int j=0; j<count*6; j++)
       {
    	storeLetters[j] ='_';          
       }
	
	
	  int tries=0  , flag=0 , position=0, k=0 ;
	  
	            
      do
	  {   
		 Errors( Mistakes);

	     cout<<"\n\n\nType your letter and press enter : ";
	     cin.getline(choice,100);                           
	
	
	     while( (strlen(choice) >1 )  ||  (!isalpha(choice[0]) )     )       //this loop works while the user
	     {                                                                   // enters invalid input . More than one char or  number
		        system("cls"); 
	    
	   
		        if(strlen(choice) > 1)                                        //checks if the user entered         
		       {                                                             // more than one characters
			    for (int i=0; i<80; i++) cout<<"=";                                   
		        
		        
				  COORD posRow1 = {16,6};   
                  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), posRow1);
	              
				  for (int i=0; i<45; i++) cout<<"=";                                                    //sets the cursor to a specific place
				                                                                                        //and prints from there
				  COORD pos = {17,10};   
                  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);	
				  
				  cout<<"You must enter ONLY ONE letter at a time!!! ";
				 
				  COORD posRow2 = {16,13};   
                  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), posRow2);
	              
				  for (int i=0; i<45; i++) cout<<"=";         
	           }
			    else  
			       {
			        for (int i=0; i<80; i++) cout<<"=";
			                                                                               
			        COORD posRow1 = {22,6};   
                    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), posRow1);          //sets the cursor to a specific place
	                
					for (int i=0; i<31; i++) cout<<"=";                                         //and prints from there
				
				    COORD pos = {24,10};   
                    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);	
				    	
					cout<<"You must enter ONLY LETTERS ";
				 
				    COORD posRow2 = {22,13};   
                    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), posRow2);
	                
					for (int i=0; i<31; i++) cout<<"=";         
			        
	               }
	     
	     
		     for(int i=0; i<=480000000; i++);       //counds and
	   	  	 system("cls");                         // clears the screen      
	   	
	   	
	   	     for (int i=0; i<80; i++) cout<<"=";
		     cout<<"\n\n\n"; 
		 
		     
			 for(int j=0; j<=count-1; j++)
		     {
		 	   cout<<"  "<<solution[j];       //prints the word with the letters that are found and the underscores
		     }
		
		   Errors( Mistakes);
		   
		   cout<<"\n\n\nType your letter and press enter : ";
	       cin.getline(choice,100);
		 } // end of while loop   that checks for valid input

   
        choice[0] = tolower(choice[0]);  
       
        int mistakes=1;                           
        int check_if_correct=0;
      
        int allow=1;
	     
	     
         for(int x=0; x < count*6;  x++)
        {
		
       	   if(choice[0]==storeLetters[x])   // checks if the user has already entered the same letter before
       	   {                               // if yes, allow=0        
			                                   
       		    allow=0;                    
       		
       		    COORD posRow1 = {26,10};   
                SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), posRow1);
	            cout<<"===================================";
	  
	            COORD pos = {27,13};   
                SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);		
	            cout<<"You already entered this letter !";
		
                COORD posRow2 = {26,16};   
                SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), posRow2);
	            cout<<"===================================";	
		
	     	    for(int i=0; i<=300000000; i++);
		
		        system("cls"); 
		    
			break;
	       }
        }
       		
	   
	   
	   storeLetters[k]=choice[0]; // stores the letter the user entered in the array that holds
	   k++;                       // the used letters
	   
	   
	   
	   if(allow==1)   // allow==1 means that the user entered a letter for the first time
	   {
	   
	      for(int j=0; j<=count-1; j++)
	      { 
		  
		     if (choice[0] == find[j])
		     { 
		                                                                // checks if the letter that user entered is in the word
	           solution[j] = toupper ( choice[0] ) ;                    // wich is stored in find array. if yes, copies the letter
		       mistakes=0;                                              // to the solution array an changes the underscore with the letter  
			   flag++;                                                  // flag counts the correct answers and terminates level
			   check_if_correct=1;                                      // when the user has entered all the correct letters                                                                 
		     }  
		                                          
          } 
	       
		   Correct_Incorrect(check_if_correct , choice[0] );
	             
	         	                                          
                                                              
	       if (mistakes==1)
	       {
	        Mistakes[position] = toupper ( choice[0] );     //stores the wrong letters to Mistakes array.
		    tries++;                                       //counts the wrong letters the user entered. If tries==6 the game ends and the user loses.   
		    position+=3;                                  // increments the position of the Mistakes array       
	       }
	   
       }
		
		
		for (int i=0; i<80; i++) cout<<"=";
		cout<<"\n\n\n"; 
		 
		 for(int j=0; j<=count-1; j++)
		 {
		 	cout<<"  "<<solution[j];       //prints the word with the letters that are found and the underscores
		 }
		
		
		if (tries==6) stop=1;
       
       
	  }while( (tries!=6) && (flag!=count) ) ;
	  
	  
	  if(flag==count) level++;     
      

    if (flag==count)  for(int delay=1;delay<=300000000;delay++);

    
    system("cls"); 
	
   
   if ( (stop==1) || (level==6) )     // stop==1 the user lost
   {                                  // level==6 the user won
   	 if (stop == 1) z=1;
	 else z = 6;	 
   	 
	 again = GameOver(z);
     level = 1;
     stop = 0;
   }
   
   
       delete [] find;
       delete [] solution;
       delete [] storeLetters;	
 	
  }
 	

 
	cout<<"\n\n\n\n\n\n\n";
	system("pause");
	return 0;
	
}




	void Intro()   
	{
	   COORD game = {32,9};
	   SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), game); 
	   cout<<"H A N G M A N";
	   	
	   COORD KBCC = {24,15};
	   SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), KBCC); 
	   cout<<"Kingsborough Community College";	
	   
	   COORD Myname = {31,17};
	   SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Myname); 
	   cout<<"Mastoras Ilias";	
	   
	   
	   
		 for(int x = 8; x<=68 ; x++)
         { 
           
           COORD positionUP = {x,5};   
           SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), positionUP);
           cout<<"#";
           for(int delay=1;delay<=5300000;delay++);
         }
        
         
         
         for( int y=5; y<=21; y++)
		 {
		     
           COORD positionDOWN = {68,y};   
           SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), positionDOWN);
           cout<<"#";
           for(int delay=1;delay<=7000000;delay++);
         }
		            
          for(int x=68; x>=8; x--)
          {
		  
	       COORD positionUPstar = {x,21};   
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), positionUPstar);
            cout<<"#";
            for(int delay=1;delay<=5500000;delay++);
         }
         
         for(int y=21; y>=5; y--)
         {
           COORD positionDOWNstar = {8,y};   
           SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), positionDOWNstar);
           cout<<"#";
           for(int delay=1;delay<=7000000;delay++);
         }
		
         
         
 for(int delay=1;delay<=299000000;delay++);
 system("cls"); 
}


string Words(int list)
{
 	
  string word;	
  
  srand(time(0));
   
  string list1[20] ={"super","hello","forever","examine","button","creature","chicken","exercise","water","mountain","practice","select","number","positive","calculator","banana","advantage","programming","television","internet"};
  string list2[20]={"perfect","complete","great", "playground","achieve","turkey","coffee","basketball","freedom","aeroplane","search","grammar","magazine","because","teacher","improve","building","classroom","decline","productive" }; 
  string list3[20]={"mesmerize","question","anxious","hunger","article","global","dominant","development","indicator","children","research","knowledge","saxophone","computer","question","education","advertising","yellow","multimedia","receive" };             
  string list4[20]={"savage","tolerate","confusion","inequality","sociologist","exposure","context","culture","relationship","album","advance","ultimate","accuse","awkward","ignorance","require","frequency","aspects","encounter","hypothesis" };
  string list5[20]={"adjective","wealth","emphasize","literacy","encounter","significance","moderator","subscribe","measure","betray","outspoken","diagnose","receptive","syntax","morphology","spontaneous","synonym","semantic","clarification","judgement" };
   
   
   
   if(list==1)      word=list1[rand() % 20]; 	 // stores a random word
   else if(list==2) word=list2[rand() % 20];
   else if(list==3) word=list3[rand() % 20];
   else if(list==4) word=list4[rand() % 20];
   else if(list==5) word=list5[rand() % 20];
  
  
   return word;
}


	void Correct_Incorrect(int x , char y)  //checks if the user entered a correct letter
	{
		y=toupper(y);
		
		 COORD posRow1 = {28,10};   
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), posRow1);
	   cout<<"========================";
	  
	  if(x==1)
	  {
	   COORD pos = {30,13};   
       SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);		
	
		cout<<" "<<y<<"  is  CORRECT!!!";
		
      }
	  else
       {
       	COORD pos = {30,13};   
       SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);		
	
		cout<<" "<<y<<"  is  Incorrect!!";
       	
	   }
		
			 COORD posRow2 = {28,16};   
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), posRow2);
	 cout<<"========================";	
		
		for(int i=0; i<=170000000; i++);
		
		system("cls"); 
		
		
	}
	

  char GameOver(int z)
	{
	 char answer[100];
     
	 	
		
	   do
		{
		   
		      for (int i=0; i<80; i++) cout<<"=";
		
		
		
		    	COORD posRow1 = {29,6};   
                SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), posRow1);
	            cout<<"====================";
		
		       if(z==1) // if the user lost
		       {
			    COORD pos = {34,10};   
                SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);		
	
		        cout<<"GAME OVER";
		       }
			   else //if the user won
		       {
		       	COORD pos = {34,10};   
                SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);		
	
		        cout<<"YOU WIN!!";
		     
				} 
		
			   COORD posRow2 = {29,14};   
               SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), posRow2);
	           cout<<"====================";	
	
	
		   cout<<"\n\nPlay again : Type 1 and press enter."
		       <<"\nQuit : Type 2 and press enter.\n\n";
		       cin.getline(answer,100);
		  
		   
		   system("cls"); 
		   
		    if( (isalnum(answer[1]))  ||  (ispunct(answer[1]))  ) answer[0]='5';  // checks if the user entered more than 1  or  2
		    
		} while ( (answer[0]!='1')  && (answer[0]!='2') );
		
		 
		  char x=answer[0]; 
		    
		    
    return x;
			
	}





	void Errors( char Errors[16])  // Prints the line with the mistakes
	{
		
	   
	  	COORD position = {50,4};   
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
        cout<<"Mistakes: ";
		for(int i=0; i<=15; i++)cout<<Errors[i];
		
	}



	void Levels(int i)
	{
		
	
		
		
	 COORD posRow1 = {29,6};   
     SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), posRow1);
	 cout<<"====================";
		
		
	 COORD pos = {34,10};   
     SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);		
	    
	    if(i==5)cout<<" FINAL LEVEL ";
	    
		else cout<<"  LEVEL  "<<i;
	   	
		
    COORD posRow2 = {29,14};   
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), posRow2);
	cout<<"====================";	
		
		
		for(int i=0; i<=450000000; i++);
		
		system("cls"); 	
		
	}	



