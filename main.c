#include <stdio.h>
#include<math.h>
#include<time.h>
#include <stdlib.h>
#define PI 3
#define SQUARE 1
#define RECTANGULAR 2
#define CIRCULAR 3
#define short_edge 5 // for RECTANGULAR
#define kırmızı 0
#define sarı 1
#define mavi 2
#define siyah 3
#define beyaz 4
double CreateBody(int shape){
  double lenght1,lenght2;
  if(shape==1){
    printf("/lenght/:");
    scanf("%lf",&lenght1);
    return lenght1*lenght1;
  }
  else if(shape==2){
    printf("/lenght1/:");
    scanf("%lf",&lenght1);
    printf("/lenght2/:");
    scanf("%lf",&lenght2);
    return lenght1*lenght2;
  }
  if(shape==3){
    printf("/Radius/:");
    scanf("%lf",&lenght1);
    return PI*lenght1*lenght1;
  }
  else{
    return -1;
  }
}
int SetColor(int color){
  if(color>=0 && color<=1000){
    return color%5 ;
  }
  else{
    return 1;
  }
}
int SetAtackPower(int lower_bound , int upper_bound){
  int random=0;
  srand(time(NULL));
  random=(lower_bound)+rand()%(upper_bound-lower_bound);
  return random;
}
double LoadMoves(int shape, double body_size)
{
  double move;
  if(shape==1){
    move=4*sqrt(body_size);
    return move;
  }
  if(shape==2){
    move=body_size/short_edge; // move = b
    move=2*(move+short_edge);
    return move ;
  }
  if(shape==3){
    move=body_size/PI;
    move=2*sqrt(move);
    move=PI*move;
    return move;
  }
}
void ShowPokemon(int shape, double body_size, int color,double move_length, int attack_power){
  int radius;
  int i=0;
  int k=0;
  int satir_sayisi=1;
  int m=0;
  int l=0;
  int n=1;
  printf("\n");
  if(shape==SQUARE){
    for(i=0 ; i<move_length/4 ; i++){
      for(k=0;k<move_length/4;k++){
        printf("X");
    }
        printf("\n");
    }
  printf("Name : SQUARE Pokemon\n");
  printf("Size : %lf\n",body_size);
  switch(color){
      case kırmızı :
      printf("Color : kırmızı\n");
      break ;    
      case sarı : 
      printf("Color : sarı\n");
      break ;
      case mavi :
       printf("Color : mavi\n");
        break;
      case siyah :
      printf("Color : siyah\n");
      break;
    case beyaz : 
      printf("Color : beyaz\n");
      break;
    }printf("Move : %lf\n",move_length);


  printf("Attack Power : %d\n",attack_power);
  }
  else if(shape==RECTANGULAR){
      for(i=0  ;  i<short_edge  ;  i++){
          for(k=0  ;  k < (int) body_size/short_edge  ;  k++){
              printf("X");
          }
          printf("\n");
      }
      printf("Name : Rectengular Pokemon\n");
      printf("Size : %lf\n",body_size);
      switch(color){
      case kırmızı :
      printf("Color : kırmızı\n");
      break ;    
      case sarı : 
      printf("Color : sarı\n");
      break ;
      case mavi :
       printf("Color : mavi\n");
        break;
      case siyah :
      printf("Color : siyah\n");
      break;
      case beyaz : 
      printf("Color : beyaz\n");
      break;
    }
      printf("Move : %lf\n",move_length);
      printf("Attack Power : %d\n",attack_power);
        }
  if(shape==CIRCULAR){
    int space_between_x = 4;  
    i=body_size/PI ;
    i=sqrt(i); // i=radius
    radius = i ;
    int z=2;
    int m = radius - 1 ; // formula for tab
    if(radius % 2 == 1 ){  // odd numbers tekse numaralar
      for(i=radius ; i>0 ; i--){
        if(i>radius/2){
          for(k=0 ; k < m - 2*l ; k++){
            printf("\t");
          }
          printf("X");
          if(satir_sayisi!=1){
            for(k=0;k<space_between_x;k++){
              printf("\t");
            }
            printf("X");
            //printf("S :%d\n ",space_between_x);
            if(i-1>radius/2){
            space_between_x +=4 ;
            }
          }
        }
        else{
          // printf("S :%d\n ",space_between_x);
           space_between_x -=4 ;  
          for(k=0;k<z;k++){
            printf("\t");
          }
          z=z+2;
            printf("X");
          if(satir_sayisi!=radius){
           
            for(k=0;k<space_between_x;k++){
              printf("\t");
            }
            printf("X");  
          }
        }
        l++;
        printf("\n");   
        satir_sayisi++;
      }
    }
    z=2;
    m=radius-1 ;
    space_between_x = 2 ;
    satir_sayisi =1 ;
    // Even Number 
    if(radius%2== 0){
      for(i=radius+1;i>0;i--){ // for new line
        if(i>radius/2){ // for upside
          for(k=0 ; k<m ; k++){ // for printing tab
            printf("\t"); // before x
          }
          printf("X");
          if(i==radius+1){ // en üstten bir alttaki satırda içeri dogru 1 boşluk(tap)var
            m -=1 ;
          }
          else{
            if(radius<=3){
              z=1;
            }
            m -=2; // update numbers of tab
            for(k=0 ; k<space_between_x ; k++){
              printf("\t"); // between x
            }
            if(i-1>radius/2){
              space_between_x +=4 ; // update space between x numbers
            }
            printf("X");
          }
        }
        else{
          space_between_x -=4;
          for(k=0;k<z;k++){
            printf("\t");
          }
          printf("X");
          if(satir_sayisi!=radius){
            z +=2;
          }
          if(satir_sayisi==radius)
            z +=1;
          if(i!=1){
            for(k=0;k<space_between_x;k++){
              printf("\t");
            }
            printf("X");
          }

        }
         printf("\n");
         satir_sayisi ++;
      }
       
    }  
    printf("Name : CIRCULAR Pokemon\n");
    printf("Size : %lf\n",body_size);
    switch(color){
      case kırmızı :
      printf("Color : kırmızı\n");
      break ;    
      case sarı : 
      printf("Color : sarı\n");
      break ;
      case mavi :
       printf("Color : mavi\n");
        break;
    case siyah :
      printf("Color : siyah\n");
      break;
    case beyaz : 
      printf("Color : beyaz\n");
      break;
    }
    printf("Move : %lf\n",move_length);
    printf("Attack Power : %d\n",attack_power);
    }
} 
int main(void) {
  int shape , color , attack_power ;
  double size_of_body , move_lenght;
  shape = RECTANGULAR; // CIRCULAR/SQUARE/RECTANGULAR
  size_of_body=CreateBody(shape);
  color = 798 ;
  color = SetColor(color);
  move_lenght = LoadMoves(shape,size_of_body);
  attack_power = SetAtackPower(0,150);
  ShowPokemon(shape,size_of_body,color,move_lenght,attack_power);
  return 0;
}
