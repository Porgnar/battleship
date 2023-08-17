#include <stdio.h>
#include <stdlib.h>
#include <time.h>



int main(){


  int start=0;
  int strt=0;
  int volley,pmaxshot,cpumaxshot;

srand(time(NULL));


  printf("\n Hello, and welcome. \n Would you care for a game of battleship? (y/n) \n");

while(strt==0){

  scanf(" %c",&start);


  //printf("your choice was:"); //debug option
  //  putchar(start);

  switch (start){
    case 110:
    strt++;
    printf("\n Well stop wasting my time then and kindly fuck off!\n\n");
    return 0;
    break;
    break;

    case 121:
    strt++;
    printf("\nLet us set the game up then, please comply with the instructions below.\n");
    break;

  }
//  if((start!='y')&&(start!='n')){  printf("\nDon't you know the fucking ABC? I did not even require the whole thing of you, just two damn letters of it y and n... Your mother and I are VERY disappointed in you.\n");};
}
 // just some formal start menu esque shit
strt=false;

printf("Please select your gamemode, [s]ingle shot or [v]olley\n");

while(strt!=true){

volley=getchar();

//scanf(" %c",&volley);


switch (volley){

case 's':
pmaxshot=1;
cpumaxshot=1;
strt=true;
break;

case 'v':
pmaxshot=5;
cpumaxshot=5;
strt=true;
break;

}
}//while for gamemode selection
//board state initialisation

    int pboard[10][11];
    int cpuboard[10][11];
    int vcpuboard[10][11];
    int hitchart[10][11];

    for(int i=1;i<10;i++){
      for(int j=0;j<11;j++){
    pboard[i][j]=126;
    cpuboard[i][j]=126;
    vcpuboard[i][j]=126;
    hitchart[i][j]='2';
    }
}

    for(int i=0;i<11;i++){
      vcpuboard[0][i]=(i+97);
      pboard[0][i]=(i+97);
      cpuboard[0][i]=(i+97);
      hitchart[0][i]=(i+97);
    }


// printf("\n  r:%c c:%c",row,column); //debug feature





//ship creation, ship storing, initial setup, I beleive this is highly unoptimised. (AS IS THE REST OF THE CODE)


int fit=false;
int length=4;
int bad=false;
int shipcount=0;
int deploy=true;

//orientation check, to see if it fits in the board, if not corrects it, if it is not possible to fir I will figure that case out when I come to it
while(shipcount!=5){

if(length==0){length=2;};

int ro=    (rand() % 9)+1;
int col=   (rand() % 11)+1;

// printf("\n%d %d\n",ro,col);  //debug feature

if(cpuboard[ro][col-1]==33){bad=true;}

  while(fit!=true&&bad!=true){

    deploy=true;

    int orient= rand() % 4;

    //printf("\norient:%d\n",orient);

    switch (orient) {
      case 0:
      if((col-length)>=1){
        for(int modifier=0;modifier<=(length+1);modifier++){
          if(cpuboard[ro][col-modifier-1]==33){deploy=false;}
              }//for
          if(deploy==true){
            for(int modifier=0;modifier<(length+1);modifier++){
              cpuboard[ro][col-modifier-1]=33; }
        fit=true;
        shipcount++;
        length--;
      }
    }
    break;
//checks in a direction if any of the to be occupied spaces is already flagged, if it is do not deploy, look for another orientation.

      case 1:
      if((ro-length)>=1){
        for(int modifier=0;modifier<=(length+1);modifier++){
          if(cpuboard[ro-modifier][col-1]==33){deploy=false;}
      }//for
          if(deploy==true){
            for(int modifier=0;modifier<(length+1);modifier++){
              cpuboard[ro-modifier][col-1]=33; }
        fit=true;
        shipcount++;
        length--;

      }
    }
    break;



      case 2:
      if((col+length-1)<=10){
        for(int modifier=0;modifier<(length+1);modifier++){
          if(cpuboard[ro][col+modifier-1]==33){deploy=false;}
      }//for
          if(deploy==true){
            for(int modifier=0;modifier<(length+1);modifier++){
              cpuboard[ro][col+modifier-1]=33; }
        fit=true;
        shipcount++;
        length--;

      }
    }
  break;

      case 3:
      if((ro+length)<=9){
        for(int modifier=0;modifier<(length+1);modifier++){
          if(cpuboard[ro+modifier][col-1]==33){deploy=false;}
      }//for
          if(deploy==true){
            for(int modifier=0;modifier<(length+1);modifier++){
              cpuboard[ro+modifier][col-1]=33; }
        fit=true;
        shipcount++;
        length--;

      }
    }
  break;



    }//switch
  }//while
  fit=false;
  bad=false;
}//for, game setup loop, CPU side only, this generates the CPU's random starting board that complies with the battleship rules



//initial display of the playing boards


printf("\n");

printf("          CPU                          Player ");

printf("\n");


for(int i=0;i<10;i++){

  if(i!=0){printf("%d  ",i);}
  else {printf("   ");};

  for(int j=0;j<11;j++){
    printf("%c ",vcpuboard[i][j]);
  }

  printf(" |  ");

  if(i!=0){printf("%d  ",i);}
  else {printf("   ");};

  for(int j=0;j<11;j++){
    printf("%c ",pboard[i][j]);
  }

//debug options, this draws the cpu's hidden board,

/*  printf(" |  ");

  if(i!=0){printf("%d  ",i);}
  else {printf("   ");};

  for(int j=0;j<11;j++){
    printf("%c ",cpuboard[i][j]);
  }

//and this draws the cpu logic board

  printf(" |  ");

  if(i!=0){printf("%d  ",i);}
  else {printf("   ");};

  for(int j=0;j<11;j++){
    printf("%c ",hitchart[i][j]);
  }
*/
  printf("\n");

}

//drawing out the board fot hte player so they can have a visual clue as to how it works


printf("\nDeploy our troops Commander by inputing the desired starting coordinates for your ships (2k,9d), and their desired orientation (u,d,l,r), so the final input coordinates look like this: 4gu, 9kl\n");

int buffer=0;
int r=0;
int c=0;
int dir=0;
int pship=0;
length=4;





while(pship!=5){

  bad=false;

scanf(" %c %c %c",&r,&c,&dir);

/*  buffer=getchar();
  r=getchar();
  c=getchar();
  dir=getchar();
*/ // old shitty buggy method, fucking yucky :(

//printf("%d %d %d\n",r,c,dir);

  r=r-48;
  c=c-96;


//printf("%d %d %d\n",r,c,dir);

switch (dir){

case 'l':
dir=0;
break;

case 'u':
dir=1;
break;

case 'r':
dir=2;
break;

case 'd':
dir=3;
break;

default:
printf("Please enter a valid direction u(p) d(own) l(eft) r(ight)!\n");
bad=true;
break;
}

//printf("%d\n",dir);


if(length==0){length=2;};


if(pboard[r][c-1]==33){bad=true;printf("A ship has already been placed here\n");}

  while(fit!=true&&bad!=true){

    deploy=true;

    switch (dir) {
      case 0:
      if((c-length)>=1){
        for(int modifier=0;modifier<(length+1);modifier++){
          if(pboard[r][c-modifier-1]==33){deploy=false;}
              }//for
          if(deploy==true){
            for(int modifier=0;modifier<(length+1);modifier++){
              pboard[r][c-modifier-1]=33; }
        fit=true;
        pship++;
        length--;
      }else{printf("Surely you jest Commander! There is already a ship in the way there!\n");bad=true;};
    }else{printf("You can not fit the ship in this direction, Commander!");bad=true;};
    break;
//checks in a direction if any of the to be occupied spaces is already flagged, if it is do not deploy, look for another orientation.

      case 1:
      if((r-length)>=1){
        for(int modifier=0;modifier<(length+1);modifier++){
          if(pboard[r-modifier][c-1]==33){deploy=false;}
      }//for
          if(deploy==true){
            for(int modifier=0;modifier<(length+1);modifier++){
              pboard[r-modifier][c-1]=33; }
        fit=true;
        pship++;
        length--;

      }else{printf("Please give an applicable deployment that does not conflict with already deployed ships\n");bad=true;};
    }else{printf("You can not fit the ship in this direction");bad=true;};
    break;



      case 2:
      if((c+length-1)<=10){
        for(int modifier=0;modifier<(length+1);modifier++){
          if(pboard[r][c+modifier-1]==33){deploy=false;}
      }//for
          if(deploy==true){
            for(int modifier=0;modifier<(length+1);modifier++){
              pboard[r][c+modifier-1]=33; }
        fit=true;
        pship++;
        length--;

      }else{printf("Please give an applicable deployment that does not conflict with already deployed ships\n");bad=true;};
    }else{printf("You can not fit the ship in this direction");bad=true;};
  break;

      case 3:
      if((r+length)<=9){
        for(int modifier=0;modifier<(length+1);modifier++){
          if(pboard[r+modifier][c-1]==33){deploy=false;}
      }//for
          if(deploy==true){
            for(int modifier=0;modifier<(length+1);modifier++){
              pboard[r+modifier][c-1]=33; }
        fit=true;
        pship++;
        length--;

      }else{printf("Please give an applicable deployment that does not conflict with already deployed ships\n");bad=true;};
    } else{printf("You can not fit the ship in this direction");bad=true;};
  break;

  default:
  printf("Please give an applicable deployment that does not conflict with already deployed ships\n");
  fit=true;
  break;

}//switch

deploy=true;

}//while

printf("\n");

printf("          CPU                          Player ");

printf("\n");

//for(int kurva=0;kurva<10;kurva++){
for(int i=0;i<10;i++){

  if(i!=0){printf("%d  ",i);}
  else {printf("   ");};

  for(int j=0;j<11;j++){
    printf("%c ",vcpuboard[i][j]);
  }

  printf(" |  ");

  if(i!=0){printf("%d  ",i);}
  else {printf("   ");};

  for(int j=0;j<11;j++){
    printf("%c ",pboard[i][j]);
  }

/*
  printf(" |  ");

  if(i!=0){printf("%d  ",i);}
  else {printf("   ");};

  for(int j=0;j<11;j++){
    printf("%c ",cpuboard[i][j]);
  }
  printf(" |  ");

  if(i!=0){printf("%d  ",i);}
  else {printf("   ");};

  for(int j=0;j<11;j++){
    printf("%c ",hitchart[i][j]);
  }
*/
  printf("\n");
}
fit=false;

}   //outer while, the whole deployment loop's end (playerside)



int end=false;
int inrow=0,incol=0;
//int hit=false;
//int playerturn=false;
int playerturn= rand() % 2;


if(playerturn==true){printf("\nWe are ready to engage Commander! Give us the target coordinates, and we'll open fire. (2b, 4d)\n");};
if(playerturn==false){printf("\nHostile ships have opened fire on us Commander! Designate the coordinates so we can fire back! (2b, 4d)\n");}


//printf("%d",playerturn);

int plife=17;
int cpulife=17;
int hr,hc,shit=true;

//HERE BELOW LIES THE GAME ITSELF



while(end!=true){

    printf("\n");

    printf("          CPU                          Player ");

    printf("\n");


    for(int i=0;i<10;i++){

      if(i!=0){printf("%d  ",i);}
      else {printf("   ");};

      for(int j=0;j<11;j++){
        printf("%c ",vcpuboard[i][j]);
      }

      printf(" |  ");

      if(i!=0){printf("%d  ",i);}
      else {printf("   ");};

      for(int j=0;j<11;j++){
        printf("%c ",pboard[i][j]);
      }

/*
      printf(" |  ");

      if(i!=0){printf("%d  ",i);}
      else {printf("   ");};

      for(int j=0;j<11;j++){
        printf("%c ",cpuboard[i][j]);
      }

      printf(" |  ");

      if(i!=0){printf("%d  ",i);}
      else {printf("   ");};

      for(int j=0;j<11;j++){
        printf("%c ",hitchart[i][j]);
      }
*/
      printf("\n");
  }   //board display loop




if(playerturn==true){

playerturn=false;

for(int shots=0;shots<pmaxshot;){




for(;;){

scanf(" %c %c",&inrow,&incol); //nice and reliable <3

/*
buffer=getchar();
inrow=getchar();
incol=getchar();
*/ // OLD SHIT FUCK TRASH ASS SHIT FUCK FUNCTIONS I FUCKING HATE THESE


if((inrow>='1')&&(inrow<='9')&&(incol>='a')&&(incol<='k')){

inrow=inrow-48;
incol=incol-97;
break;
}else{printf("Please tell us valid coordinates Commander!\n");};

}//input reading, converting loop

if(cpuboard[inrow][incol]=='#'){printf("We have already fired on these coordinates Commander!");}
else{
  if(cpuboard[inrow][incol]=='~'){
    printf("We missed commander!\n");
    cpuboard[inrow][incol]='#';
    vcpuboard[inrow][incol]=cpuboard[inrow][incol];
    shots++;

  }else if(cpuboard[inrow][incol]=='!'){
    printf("Direct hit confirmed!\n");
    cpuboard[inrow][incol]='x';
    vcpuboard[inrow][incol]=cpuboard[inrow][incol];
    shots++;
    cpulife--;

    switch (cpulife){

   case 14:
   if(cpumaxshot>1){cpumaxshot--;};
   printf("\nCommander! It seems like one of the enemy ships caught fire and is incapable of firing from the damage!\n");
   break;

   case 11:
   if(cpumaxshot>1){cpumaxshot--;};
   printf("\nWe have disabled another ship's cannons! they are losing ground Commander!\n");
   break;

   case 8:
   if(cpumaxshot>1){cpumaxshot--;};
   printf("\nThey are down to two action capable ships Commander! We can finish this!\n");
   break;

   case 5:
   if(cpumaxshot>1){cpumaxshot--;};
   printf("\nWe almost have them Commander! Victory is within our grasp!\n");
    break;

   case 0:
    printf("\nYou have sunk all hostile ships in the area, good job Commander! With this the enemy line has faltered for the time being. You have protected our waters, but the enemy won't let up this easily. We need to request repairs, and replace our losses. The war goes on.\n");
    end=true;break;break;break;
   }

  }

}

}//for for the volley gamemode

playerturn=false;

}//player's turn logic


if(playerturn==false){
playerturn=true;

  for(int cpushots=0;cpushots<cpumaxshot;){

if(shit==true){
    inrow= (rand() % 9)+1;
    incol= (rand() % 11);
}

if(shit==false){
int maxrow=0;
int maxcol=0;
int max=0;

for(int i=1;i<10;i++){
  for(int j=0;j<11;j++){
    if(hitchart[i][j]>max){
      max=hitchart[i][j];
      maxrow=i;
      maxcol=j;
    }
  }
}
//printf("%d",max);
if(max=='2'){
  inrow= (rand() % 9)+1;
  incol= (rand() % 11);
}else{
inrow=maxrow;
incol=maxcol;
}
}



//hitcheck below.
  if(pboard[inrow][incol]!='#'){
    if(pboard[inrow][incol]=='~'){
      printf("They missed us Commander!\n");
      pboard[inrow][incol]='#';
      cpushots++;
      hitchart[inrow][incol]='0';

    }else if(pboard[inrow][incol]=='!'){
      printf("Direct hit on one of our ships!\n");
      pboard[inrow][incol]='x';
      cpushots++;
      plife--;
      hitchart[inrow][incol]='1';


      if(((inrow-1)>=0)&&(hitchart[inrow-1][incol]!='0')&&(hitchart[inrow-1][incol]!='1')){hitchart[inrow-1][incol]+=1;};
      if(((inrow+1)<=10)&&(hitchart[inrow+1][incol]!='0')&&(hitchart[inrow-1][incol]!='1')){hitchart[inrow+1][incol]+=1;};
      if(((incol-1)>=0)&&(hitchart[inrow][incol-1]!='0')&&(hitchart[inrow-1][incol]!='1')){hitchart[inrow][incol-1]+=1;};
      if(((inrow+1)<=10)&&(hitchart[inrow][incol+1]!='0')&&(hitchart[inrow-1][incol]!='1')){hitchart[inrow][incol+1]+=1;};
      shit=false;



      switch (plife){

      case 14:
      if(pmaxshot>1){pmaxshot--;}
      printf("Commander! A torpedo volley from the enemy has made one of our ships incapable of firing! We might have lost some firepower, but the battle has just begun!\n");
      break;

      case 11:
      if(pmaxshot>1){pmaxshot--;}
      printf("Commander! We are taking substantial damage, an additional boat caught on fire, they are still afloat, but definitely not combat ready!\n");
      break;

      case 8:
      if(pmaxshot>1){pmaxshot--;}
      printf("We are taking heavy casualties sir! I don't know how long we can manage with only two more ships capable of firing! You have to end this fast!\n");
      break;

      case 5:
      if(pmaxshot>1){pmaxshot--;}
      printf("We are down to our last leg Commander! You have to end this or they will get through us! The mainland must be protected at al cost!\n");
      break;

      case 0:
      printf("\nCannon barrage imminent, brace yo.....! \n In your final moments you see the first shot hitting the deck. You hear the deafening noise, and feel each vibration caused by the shelling as you avert your eyes from the scene. As if that would stop the debrie from flying straight at the bridge. It crashes right through the windows claiming the firstmate's life in an instant. You stand there baffled. How could this have come to pass? You have failed the motherland. Now the naval forces will push the broken defensive line back. Every seaknot your nation earned by sweat and blood now gone. The realisation has no time to settle in as the last of the cannon shots thunderously crashes into the bridge, killing you and the remaining officers in an instant.\n");
      end=true;
      break;
    } //life check switch

  }//hitif check

if(end==true){break;};
  }
if(end==true){break;};

}//volley

  playerturn=true;
}//cpu turn




}//main game loop!



return 0;
}//end the whole fucking thing finally.
