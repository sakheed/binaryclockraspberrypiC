#include <stdio.h>
#include <unistd.h>
#include <ncurses.h>


#define BLACK 0
#define WHITE 1
#define GREEN 5
#define RED 2
#define BLUE 3


void draw_grid(uint16_t pixels[8][8]) {
    for(int y=0; y<8; y++) {
        move(y,0);
        for(int x=0; x<8; x++) {
            if(pixels[7-x][y]) {
                attron(COLOR_PAIR(pixels[7-x][y]));
                addch('#');
                attroff(COLOR_PAIR(pixels[7-x][y]));
            } else {
                addch(' ');
            }
        }
    }
    refresh();
}

void fill_pixels(uint16_t pixels[8][8], uint16_t color) {
    for(int i=0; i<8; i++) {
        for(int j=0; j<8; j++) {
            pixels[i][j] = color;
        }
    }
}
int open_display(void){
uint16_t pixel[8][8];
initscr();
start_color();
init_pair(BLACK, COLOR_BLACK, COLOR_BLACK);
fill_pixels(pixel,BLACK);
return 1;
}
    

void display_colons(void){
uint16_t pixel[8][8];
initscr();
start_color();
init_pair(WHITE, COLOR_WHITE, COLOR_WHITE);


pixel[6][2]=WHITE;
pixel[6][3]=WHITE;
pixel[5][2]=WHITE;
pixel[5][3]=WHITE;

pixel[3][2]=WHITE;
pixel[3][3]=WHITE;
pixel[2][2]=WHITE;
pixel[2][3]=WHITE;

pixel[6][5]=WHITE;
pixel[6][6]=WHITE;
pixel[5][5]=WHITE;
pixel[5][6]=WHITE;

pixel[3][5]=WHITE;
pixel[3][6]=WHITE;
pixel[2][5]=WHITE;
pixel[2][6]=WHITE;
draw_grid(pixel);

}

void display_hours(int hours){
uint16_t pixel[8][8];
initscr();
start_color();
init_pair(BLUE,COLOR_BLUE,COLOR_BLUE);
if((hours == 1 || hours== 3|| hours==5||hours==7||hours==9||hours==11||hours==13||hours==15||hours==17||hours==19||hours==21||hours==23)){
pixel[7][7]=BLUE;
draw_grid(pixel);
}


if((hours == 2 || hours== 3|| hours==6||hours==7||hours==10||hours==11||hours==14||hours==15||hours==18||hours==19||hours==22||hours==23)){
  pixel[7][6]=BLUE;
   draw_grid(pixel);

}
if((hours == 4 || hours== 5|| hours==6||hours==7||hours==12||hours==13||hours==14||hours==15||hours==20||hours==21||hours==22||hours==23)){
     pixel[7][5]=BLUE;
      draw_grid(pixel);

}

if((hours == 8 || hours== 9|| hours==10||hours==11||hours==12||hours==13||hours==14||hours==15)){
   pixel[7][4]=BLUE;
      draw_grid(pixel);


}
if((hours == 16 || hours== 17|| hours==18||hours==19||hours==20||hours==21||hours==22||hours==23)){
    pixel[7][3]=BLUE;
    draw_grid(pixel);


}


}

void display_minutes(int minutes){
uint16_t pixel[8][8];
  initscr();
  start_color();
  init_pair(GREEN,COLOR_GREEN,COLOR_GREEN);
  if((minutes == 1 || minutes== 3|| minutes==5||minutes==7||minutes==9||minutes==11||minutes==13||minutes==15||minutes==17||minutes==19||minutes==21||minutes==23
  ||minutes==25||minutes==27||minutes==29||minutes==31||minutes==33||minutes==35||minutes==37||minutes==39||minutes==41||minutes==43||minutes==45||minutes==47||
  minutes==49||minutes==51||minutes==53||minutes==55||minutes==57||minutes==59)){
  pixel[4][7]=GREEN;
  draw_grid(pixel);
  }
  if((minutes == 2 || minutes== 3|| minutes==6||minutes==7||minutes==10||minutes==11||minutes==14||minutes==15||minutes==18||minutes==19||minutes==22||minutes==23
     ||minutes==24||minutes==27||minutes==30||minutes==31||minutes==34||minutes==35||minutes==38||minutes==39||minutes==42||minutes==43||minutes==46||minutes==47||
    minutes==50||minutes==51||minutes==54||minutes==55||minutes==58||minutes==59)){
    pixel[4][6]=GREEN;
   draw_grid(pixel);         
  }
  if((minutes == 4 || minutes== 5|| minutes==6||minutes==7||minutes==12||minutes==13||minutes==14||minutes==15||minutes==20||minutes==21||minutes==22||minutes==23
     ||minutes==28||minutes==29||minutes==30||minutes==31||minutes==36||minutes==37||minutes==38||minutes==39||minutes==44||minutes==45||minutes==46||minutes==47||
     minutes==52||minutes==53||minutes==54||minutes==55)){
     pixel[4][5]=GREEN;
     draw_grid(pixel);         
     }
   if((minutes == 8 || minutes== 9|| minutes==10||minutes==11||minutes==12||minutes==13||minutes==14||minutes==15||minutes==20||minutes==21||minutes==22||minutes==23
      ||minutes==28||minutes==29||minutes==30||minutes==31||minutes==40||minutes==41||minutes==42||minutes==43||minutes==44||minutes==45||minutes==46||minutes==47||
      minutes==56||minutes==57||minutes==58||minutes==59)){
      pixel[4][4]=GREEN;
      draw_grid(pixel);         
      }
   if((minutes == 16 || minutes== 17|| minutes==18||minutes==19||minutes==20||minutes==21||minutes==22||minutes==23||minutes==24||minutes==25||minutes==26||minutes==27
      ||minutes==28||minutes==29||minutes==30||minutes==31||minutes==48||minutes==49||minutes==50||minutes==51||minutes==52||minutes==53||minutes==54||minutes==55||
      minutes==56||minutes==57||minutes==58||minutes==59)){
      pixel[4][3]=GREEN;
      draw_grid(pixel);
   }
   if((minutes == 32 || minutes== 33|| minutes==34||minutes==35||minutes==36||minutes==37||minutes==38||minutes==39||minutes==40||minutes==41||minutes==42||minutes==43
      ||minutes==44||minutes==45||minutes==46||minutes==47||minutes==48||minutes==49||minutes==50||minutes==51||minutes==52||minutes==53||minutes==54||minutes==55||
      minutes==56||minutes==57||minutes==58||minutes==59)){
      pixel[4][2]=GREEN;
      draw_grid(pixel);         
      }
      
     }
     
 

void display_seconds(int seconds){
 uint16_t pixel[8][8];
   initscr();
   start_color();
   init_pair(RED,COLOR_RED,COLOR_RED);
  if((seconds == 1 || seconds== 3|| seconds==5||seconds==7||seconds==9||seconds==11||seconds==13||seconds==15||seconds==17||seconds==19||seconds==21||seconds==23
      ||seconds==25||seconds==27||seconds==29||seconds==31||seconds==33||seconds==35||seconds==37||seconds==39||seconds==41||seconds==43||seconds==45||seconds==47||
      seconds==49||seconds==51||seconds==53||seconds==55||seconds==57||seconds==59)){
      pixel[1][7]=RED;
      draw_grid(pixel);
      }
        if((seconds == 2 || seconds== 3|| seconds==6||seconds==7||seconds==10||seconds==11||seconds==14||seconds==15||seconds==18||seconds==19||seconds==22||seconds==23
         ||seconds==24||seconds==27||seconds==30||seconds==31||seconds==34||seconds==35||seconds==38||seconds==39||seconds==42||seconds==43||seconds==46||seconds==47||
       seconds==50||seconds==51||seconds==54||seconds==55||seconds==58||seconds==59)){
        pixel[1][6]=RED;
       draw_grid(pixel);         
          }
       if((seconds == 4 || seconds== 5|| seconds==6||seconds==7||seconds==12||seconds==13||seconds==14||seconds==15||seconds==20||seconds==21||seconds==22||seconds==23
         ||seconds==28||seconds==29||seconds==30||seconds==31||seconds==36||seconds==37||seconds==38||seconds==39||seconds==44||seconds==45||seconds==46||seconds==47||
         seconds==52||seconds==53||seconds==54||seconds==55)){
         pixel[1][5]=RED;
         draw_grid(pixel);         
         }
       if((seconds == 8 || seconds== 9|| seconds==10||seconds==11||seconds==12||seconds==13||seconds==14||seconds==15||seconds==20||seconds==21||seconds==22||seconds==23
          ||seconds==28||seconds==29||seconds==30||seconds==31||seconds==40||seconds==41||seconds==42||seconds==43||seconds==44||seconds==45||seconds==46||seconds==47||
          seconds==56||seconds==57||seconds==58||seconds==59)){
          pixel[1][4]=RED;
        draw_grid(pixel);         
         }
       if((seconds == 16 || seconds== 17|| seconds==18||seconds==19||seconds==20||seconds==21||seconds==22||seconds==23||seconds==24||seconds==25||seconds==26||seconds==27
        ||seconds==28||seconds==29||seconds==30||seconds==31||seconds==48||seconds==49||seconds==50||seconds==51||seconds==52||seconds==53||seconds==54||seconds==55||
        seconds==56||seconds==57||seconds==58||seconds==59)){
        pixel[1][3]=RED;
        draw_grid(pixel);
     }
       if((seconds == 32 || seconds== 33|| seconds==34||seconds==35||seconds==36||seconds==37||seconds==38||seconds==39||seconds==40||seconds==41||seconds==42||seconds==43
           ||seconds==44||seconds==45||seconds==46||seconds==47||seconds==48||seconds==49||seconds==50||seconds==51||seconds==52||seconds==53||seconds==54||seconds==55||
           seconds==56||seconds==57||seconds==58||seconds==59)){
           pixel[1][2]=RED;
           draw_grid(pixel);         
           }
    
    }
    
    void close_display(){
endwin();
}


void display_time(int hours, int minutes, int seconds){
 open_display();
 display_colons();
 display_hours(hours);
 display_minutes(minutes);
 display_seconds(seconds);
}


int check_time(int hours, int minutes, int seconds){
int ret = 0;
if (hours>23){ ret =1;}
if (hours<0){ret =1;}
if (minutes>59){ret =1;}
if (minutes<0){ret =1;}
if (seconds>59){ret =1;}
if (seconds<0){ret =1;}
return ret;
}
