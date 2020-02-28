
#include <screen.h>
#include <keypad.h>
struct nombre{
    int row; //0
    int column; //4
    bool vivo; //8
    int direccion;//1 derecha 2 izquierda 3 arriba 4 abajo //9
};



struct game{
    int score;
    int lives;
    int level;
    int enemies;
    bool pasado;
};
    //
    struct nombre jugador;
    //
    struct game berzerk;
    //
    struct nombre bots[8];
    //
    struct nombre pum[9];
/*
void printScore(){
    int score= berzerk.score;
    int mil=0;
    int cien=0;
    int dies=0;
    set_cursor(1,2);
    puts("SCORE: ");
    while (score>=1000)
    {
        mil++;
        score=score-1000;
    }
    while (score>=100)
    {
        cien++;
        score=score-100;
    }
    while (score>=10)
    {
        dies++;
        score=score-10;
    }
    if(mil==1){
        puts("1");
    }else if(mil==2){
        puts("2");
    }else if(mil==3){
        puts("3");
    }else if(mil==4){
        puts("4");
    }else if(mil==5){
        puts("5");
    }else if(mil==6){
        puts("6");
    }else if(mil==7){
        puts("7");
    }else if(mil==8){
        puts("8");
    }else if(mil==9){
        puts("9");
    }

    if(cien==1){
        puts("1");
    }else if(cien==2){
        puts("2");
    }else if(cien==3){
        puts("3");
    }else if(cien==4){
        puts("4");
    }else if(cien==5){
        puts("5");
    }else if(cien==6){
        puts("6");
    }else if(cien==7){
        puts("7");
    }else if(cien==8){
        puts("8");
    }else if(cien==9){
        puts("9");
    }

    if(dies==1){
        puts("1");
    }else if(dies==2){
        puts("2");
    }else if(dies==3){
        puts("3");
    }else if(dies==4){
        puts("4");
    }else if(dies==5){
        puts("5");
    }else if(dies==6){
        puts("6");
    }else if(dies==7){
        puts("7");
    }else if(dies==8){
        puts("8");
    }else if(dies==9){
        puts("9");
    }
    if(cien!=0 && dies==0){
        puts("0");
    }
    puts("0");
}*/

void letsplay(){
    //inicializar jugador
    jugador.row=2;
    jugador.column=19;
    //inicializar score, vidas, levl1, y enemigo 1
    berzerk.lives=3;
    berzerk.score=0;
    berzerk.level=1;
    berzerk.enemies=1;
    berzerk.pasado=false;
}
void initBala(struct nombre uwu,int u){
    int cual=-1;
    for (int i = 0; i < 9; i++)
    {
        if(!pum[i].vivo){
            cual=i;
            break;
        }
    }
    if(cual!=-1){
        pum[cual].direccion=u;
        if(u==1){
            pum[cual].row=uwu.row-1;
            pum[cual].column=uwu.column;
        }else if(u==2){
            pum[cual].row=uwu.row+1;
            pum[cual].column=uwu.column;
        }else if(u==3){
            pum[cual].row=uwu.row;
            pum[cual].column=uwu.column+1;
        }else if(u==4){
            pum[cual].row=uwu.row;
            pum[cual].column=uwu.column-1;
        }
        pum[cual].vivo=true;
    }
}
void initpum(){
    for (int i = 0; i < 9; i++)
    {
        pum[i].column=0;
        pum[i].direccion=0;
        pum[i].row=0;
        pum[i].vivo=false;
    }
    
}
/*
void initbots(int x){
    for (int i = 0; i <x; i++)
    {   
        if(i==0){
            bots[i].row=10;
            bots[i].column=20;
            bots[i].vivo=true;
        }else if(i==1){
            bots[i].row=20;
            bots[i].column=25;
            bots[i].vivo=true;
        }else if(i==2){
            bots[i].row=50;
            bots[i].column=18;
            bots[i].vivo=true;
        }else if(i==3){
            bots[i].row=30;
            bots[i].column=8;
            bots[i].vivo=true;
        }else if(i==4){
            bots[i].row=40;
            bots[i].column=23;
            bots[i].vivo=true;
        }else if(i==5){
            bots[i].row=60;
            bots[i].column=10;
            bots[i].vivo=true;
        }else if(i==6){
            bots[i].row=70;
            bots[i].column=28;
            bots[i].vivo=true;
        }else if(i==7){
            bots[i].row=50;
            bots[i].column=15;
            bots[i].vivo=true;
        }
    }
}*/
void printBot(){
    for (int i = 0; i < berzerk.level; i++)
    {
        if(bots[i].vivo){
            set_cursor(bots[i].column,bots[i].row);
            set_color(RED,BLACK);
            puts("\x9");
        }
    }
    
}
void actuali(){
    set_color(WHITE,BLACK);

    set_cursor(1,2);
    puts("                   ");
    printScore();
    set_cursor(2,2);
    puts("           ");
    set_cursor(2,2);
    puts("LIVES:");
    for (int i = 0; i < berzerk.lives; i++)
    {
        puts("\x1e");
    }
}
void borrar(int b , int a){
    set_color(BLACK,BLACK);
    set_cursor(a,b);
    puts("\x1");
}
void muerteBot(){
    for (int  i = 0; i < berzerk.level; i++){
        if(bots[i].row == jugador.row && bots[i].column == jugador.column && bots[i].vivo){
            bots[i].vivo= false;
            berzerk.enemies--;
            berzerk.lives--;     
            actuali();     
        }
        for (int j =0 ;j < 9 ;j++)
        {
            if(pum[j].vivo){
                if(bots[i].row == pum[j].row && bots[i].column == pum[j].column && bots[i].vivo){
                    bots[i].vivo= false;
                    berzerk.enemies--;
                    pum[j].vivo=false;
                    borrar(pum[j].row,pum[j].column);
                    berzerk.score=berzerk.score+10;
                    actuali();
                    
                }else if(jugador.row == pum[j].row && jugador.column == pum[j].column){
                    pum[j].vivo=false;
                    berzerk.lives--;
                    actuali();
                }
            }
        }
        for (int k = 0; k < berzerk.level; k++)
        {
            if(k!=i){
                if(bots[i].vivo && bots[k].vivo){
                    if(bots[i].row == bots[k].row && bots[i].column == bots[k].column){
                        bots[i].vivo= false;
                        bots[k].vivo= false;
                        berzerk.enemies=berzerk.enemies-2;
                     
                    }
                }
            }
        }
    }
}
void printInfo(){
    clear_screen();
    set_color(WHITE,BLACK);
    
    //put_char(( ( (((x & 0xf0) >> 4) >= 0 ) && (((x & 0xf0) >> 4) <= 9) )? (48 + ((x & 0xf0) >> 4)) : ('a' + (((x & 0xf0) >> 4) - 10)) ));
    //puts((char*)TO_STR(x));
    printScore();
    set_cursor(2,2);
    puts("LIVES:");
    for (int i = 0; i < berzerk.lives; i++)
    {
        puts("\x1e");
    }
    set_color(BLUE,BLACK);
    for (int i = 0; i < 80; i++)
    {
        set_cursor(3,i);
        puts("\x18");
        set_cursor(29,i);
        puts("\x17");
    }
   for (int i = 4; i < 29; i++)
   {
       set_cursor(i,0);
        puts("\x15");
        set_cursor(i,79);
        puts("\x16");
   }
}
bool ganar(struct nombre per){
    if( per.row==78){
            if(per.column<24 && 19<per.column){
                return true;
                berzerk.score=berzerk.score+10;
            }
    }
        return false;
}
void printGanar(bool w){
    if(w){
        set_color(GREEN,YELLOW);
        for (int i = 20; i < 24; i++){
            set_cursor(i,78);
            //set_cursor()
            puts("\x17");
        }
    }else{
        set_color(GREEN,RED);
        for (int i = 20; i < 24; i++){
            set_cursor(i,78);
            //set_cursor()
            puts("\x17");
        }
    }
    
}
void reset(){
    clear_screen();
    
    for (int i = 10; i < 20; i++)
    {
        delay_ms(10);
        for (int j = 20; j < 60; j++)
        {
            delay_ms(10);
            set_cursor(i,j);
            set_color(YELLOW,BLACK);
            puts("\x1c");
        }
        
    }
     //
    clear_screen();
    berzerk.level++;
    berzerk.pasado=false;
    berzerk.enemies=berzerk.level;
    berzerk.score=berzerk.score+100;

    jugador.row=2;
    jugador.column=19;
    printInfo(berzerk.score,berzerk.lives);
    initbots(berzerk.enemies);
}
void gameover(){
    clear_screen();
    
    for (int i = 10; i < 20; i++)
    {
        delay_ms(10);
        for (int j = 20; j < 60; j++)
        {
            delay_ms(10);
            set_cursor(i,j);
            set_color(RED,BLACK);
            puts("\x1c");
        }
        
    }
    clear_screen();
    set_cursor(12,33);
    set_color(RED,BLACK);
    puts("GAME OVER");
    printScore();
}
void printPlayer(int u){
    set_color(GREEN,BLACK);
    set_cursor(jugador.column,jugador.row);
    switch (u){
    case 1:
        puts("\x7");
        break;
    case 2:
        puts("\x4");
        break;
    case 3:
        puts("\x7");
        break;   
    case 4:
        puts("\x4");
        break;
    default:
        puts("\x3");
        break;
    }
}
void check(){
    muerteBot();
    if(berzerk.enemies==0){
        berzerk.pasado=true;
        if(ganar(jugador)){
            reset();
        }
    }
}
void movebots(){
    for (int i = 0; i < berzerk.level; i++)
    {
        if(bots[i].vivo){
            int xb= bots[i].row;
            int xj= jugador.row;
            int yb= bots[i].column;
            int yj= jugador.column;
            borrar(bots[i].row,bots[i].column);
            if(xj-xb < yj-yb){
                if(xj<xb){
                    bots[i].row--;
                }else if(xj>xb){
                    bots[i].row++;
                }else{
                    if(yj<yb){
                    bots[i].column--;
                    }else if(yj>yb){
                        bots[i].column++;
                    }
                }
            }else if(xj-xb > yj-yb){
                if(yj<yb){
                    bots[i].column--;
                }else if(yj>yb){
                    bots[i].column++;
                }else{
                    if(xj<xb){
                        bots[i].row--;
                    }else if(xj>xb){
                        bots[i].row++;
                    }
                }
            }else{
                bots[i].row--;
            }
            printBot();
        }
    }
}
void actualizarpum(){
    for (int i = 0; i < 9; i++)
    {
        if(pum[i].vivo){
            borrar(pum[i].row,pum[i].column);
            set_color(CYAN,BLACK);
            switch (pum[i].direccion)
            {
            case 1:
                
                if(pum[i].row-1!=0){
                    pum[i].row--;
                    set_cursor(pum[i].column,pum[i].row);
                    puts("\x13");
                }else{
                    pum[i].vivo=false;
                }
                break;
            case 2:
                if(pum[i].row+1!=78){
                    pum[i].row++;
                    set_cursor(pum[i].column,pum[i].row);
                    puts("\x13");
                }else{
                    pum[i].vivo=false;
                }
                break;
            case 3:
                if(pum[i].column+1!=28){
                    pum[i].column++;
                    set_cursor(pum[i].column,pum[i].row);
                    puts("\x14");
                }else{
                    pum[i].vivo=false;
                }
                break;
            case 4:
                if(pum[i].column-1!=4){
                    pum[i].column--;
                    set_cursor(pum[i].column,pum[i].row);
                    puts("\x14");
                }else{
                    pum[i].vivo=false;
                }
                break;
            default:
                break;
            }
        }
    }
    
}
void botspum(){
    for (int i = 0; i < berzerk.level; i++)
    {
        if(bots[i].vivo){
            int xb= bots[i].row;
            int xj= jugador.row;
            int yb= bots[i].column;
            int yj= jugador.column;
            borrar(bots[i].row,bots[i].column);
            if(xj-xb < yj-yb){
                if(xj<xb){
                    //bots[i].row--;
                    initBala(bots[i],1);
                }else if(xj>xb){
                    //bots[i].row++;
                    initBala(bots[i],2);
                }else{
                    if(yj<yb){
                        //bots[i].column--;
                        initBala(bots[i],4);
                    }else if(yj>yb){
                        initBala(bots[i],3);
                        //bots[i].column++;
                    }
                }
            }else if(xj-xb > yj-yb){
                if(yj<yb){
                    //bots[i].column--;
                    initBala(bots[i],4);
                }else if(yj>yb){
                    //bots[i].column++;
                    initBala(bots[i],3);
                }else{
                    if(xj<xb){
                       // bots[i].row--;
                       initBala(bots[i],1);
                    }else if(xj>xb){
                       // bots[i].row++;
                       initBala(bots[i],2);
                    }
                }
            }else{

            }
            printBot();
        }
    }
}
void move(int k, uint8_t space){
    if(k == 1 && space && jugador.row>3){
            borrar(jugador.row ,jugador.column);
            printPlayer(1);
            initBala(jugador,1);
        }else if(k == 1 ){
            borrar(jugador.row ,jugador.column);
            //puts("\x7\x7");
            if(jugador.row>1){
                jugador.row--;
            }
            printPlayer(1);
            if(space && jugador.row>3){
                initBala(jugador,1);
            }
        }else if(k == 2 && space && jugador.row<77){
            borrar(jugador.row ,jugador.column);
            printPlayer(2);
            initBala(jugador,2);
        }else if(k==2){
            borrar(jugador.row,jugador.column);
            //puts("\x4\x4");
            if(jugador.row<78 ){
                jugador.row++;
            }
            printPlayer(2);
            if(space && jugador.row<77){
                initBala(jugador,2);
            }
        }else if(k == 4 && space && jugador.column>5){
            borrar(jugador.row ,jugador.column);
            printPlayer(4);
            initBala(jugador,4);
        }else if(k==4){
            borrar(jugador.row,jugador.column);;
            //puts("\x5\x5");
            if(jugador.column>4){
                jugador.column--;
            }
            printPlayer(4);
            if(space && jugador.column>5){
                initBala(jugador,4);
            }
        }else if(k == 3 && space && jugador.column<27){
            borrar(jugador.row ,jugador.column);
            printPlayer(3);
            initBala(jugador,3);
        }else if(k==3){
            borrar(jugador.row,jugador.column);
            //puts("\x8\x8");
            if(jugador.column<28){
                jugador.column++;
            }
            printPlayer(3);
            if(space && jugador.column<27){
                initBala(jugador,3);
            }
        }else{
            borrar(jugador.row,jugador.column);
            printPlayer(0);
        }
}
void ganargame(){
    clear_screen();
    set_color(WHITE,BLACK);
    set_cursor(15,30);
    puts("YOU WON!!");
    printScore();
}
int main() {
    int count=0;

    // no tocar
    clear_screen();
    set_color(WHITE, BLACK);
    uint8_t f, b;
    get_color(&f, &b);
    set_color(f, b);
    keypad_init();
    //

    //funcionces que uso
    letsplay();
    initbots(berzerk.level);
    printInfo(berzerk.score,berzerk.lives);
    initpum();
    //
    while (berzerk.lives!=0 && berzerk.level!=9) {
        //count para que se muevan
        count++;
        if(count==10){
            movebots();
        }else if(count==20){
            count=0;
            botspum();
        }
        //
        actualizarpum();
        printBot();
        printGanar(berzerk.pasado);
        check();
        //
        //keypad entries
        uint8_t k = keypad_getkey();
        uint8_t space= *BTN_STATE_REG_ADDR >> 7 & 1;
        //
        delay_ms(100);
        move(k,space);
        if (k != 0) {
          set_cursor(23, 15);
            //puts("Key press");
        }
    }
    if(berzerk.lives!=0){
        ganargame();
    }else{
        gameover();
    }
    return 0;
}
