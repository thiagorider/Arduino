int redpin=9;      //Pin 9
int greenpin=10;    //Pin 10
int bluepin=11;      //Pin 11
int var=0;
int var1=0;


void setup()
{
}

void loop()
{
  for(var=250;var<255;var++)
  {
  analogWrite(redpin,var);  //RED
  analogWrite(greenpin,0);
  delay(500);
  analogWrite(redpin,0);    //GREEN
  analogWrite(greenpin,var);
  delay(500);
  analogWrite(greenpin,0);   //BLUE
  analogWrite(bluepin,var);
  delay(500);
  analogWrite(bluepin,0);
  delay(500);
  }
  
  for(var1=250;var1<255;var1++)
  {
  analogWrite(redpin,var1);   //YELLOW
  analogWrite(greenpin,var1);
  delay(500);
  analogWrite(redpin,0);
  delay(500);
  analogWrite(greenpin,var1);  //CYAN
  analogWrite(bluepin,var1);
  delay(500);
  analogWrite(greenpin,0);
  delay(500);
  analogWrite(bluepin,var1);    //MAGENTA
  analogWrite(redpin,var1);
  delay(500);
  analogWrite(bluepin,0);
  delay(500);
  analogWrite(bluepin,var1);
  analogWrite(redpin,var1);
  analogWrite(greenpin,var1);
  }
  
}
