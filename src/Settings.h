#ifndef Settings_H
#define Settings_H

struct Settings {
   char backgroundChar;
   char originChar;
   char xAxisChar;
   char yAxisChar;
   double xMin;
   double xMax;
   double yMin;
   double yMax;
   int	displayHeight;
   int	displayWidth;
   double stepHeight;
   double stepWidth;
   int xStepCount;
   double epsilon;
   bool pieceWise;
};

#endif
