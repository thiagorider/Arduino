// LED RGB LED - Troca Automtica de Cores
//
// Thiago Rider Augusto
// thiago dot rider at gmail dot com
 
int redPin = 9;
int greenPin = 10;
int bluePin = 11;
 
int redIn = 0;
int greenIn = 1;
int blueIn = 2;
 
int redVal;
int greenVal;
int blueVal;
 
void setup()
{
    redVal = 255;
    greenVal = 255;
    blueVal = 255;
    update();
}
 
// Esta função atualiza as saídas dos LEDs.
void update()
{
    analogWrite(redPin, redVal);
    analogWrite(greenPin, greenVal);
    analogWrite(bluePin, blueVal);
}
 
// Esta função atualiza uma das variáveis de cor
 
// tanto para mais ou menos brilho
 
// também atualiza as saídas e aguarda por 10 milissegundos.
 
void color_morph(int* value, int get_brighter)
{
    for (int i = 0; i < 255; i++)
    {
        if (get_brighter)
            (*value)--; // anodo comum
            //  (*value)++; // catodo comum
        else
            (*value)++; // anodo comum
            //  (*value)--; // catodo comum
 
        update();
        delay(10);
    }
}
 
void loop()
{
    // começa em preto - todos desligados
 
    color_morph(&redVal,   1); // transição para vermelho
    color_morph(&greenVal, 1); // transição para amarelo
    color_morph(&redVal,   0); // transição para verde
    color_morph(&blueVal,  1); // transição para ciano
    color_morph(&redVal,   1); // transição para branco
    color_morph(&greenVal, 0); // transição para violeta
    color_morph(&redVal,   0); // transição para azul
    color_morph(&blueVal,  0); // transição para preto - todos desligados
}
