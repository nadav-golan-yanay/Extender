#ifndef EXTENDER_H
#define EXTENDER_H

 class Extender {
  public:
   Extender(int _in1, int _in2, int _en);
   Extender();
   void begin();   //must be called from  void setup()
   void ServoWrite(int num, int value);
   void ESCWrite(int num, int value);
   void L925nWrite(int dir, int value);

  private:
   int in1 = 0; 
   int in2 = 0;
   int en = 0;

 };
#endif
