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
		static int	displayWidth;
		static int	displayHeight;
    static double epsilon;
		static int xStepCount(Settings settings);
    static double stepWidth(Settings settings);
    static double stepHeight(Settings settings);
    static bool pieceWise;
};

#endif
