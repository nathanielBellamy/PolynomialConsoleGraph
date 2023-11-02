#ifndef Settings_H
#define Settings_H

class Settings {
	public:
		static char backgroundChar;
		static char originChar;
		static char xAxisChar;
		static char yAxisChar;
		static double xMin;
		static double xMax;
		static double yMin;
		static double yMax;
		static int	displayHeight;
		static int	displayWidth;
		static double stepHeight;
    static double stepWidth;
    static int xStepCount;
    static double epsilon;
    static bool pieceWise;
};

#endif
