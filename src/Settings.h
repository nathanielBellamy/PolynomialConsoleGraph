#ifndef Settings_H
#define Settings_H

class Settings {
	public:
		static char backgroundChar;
		static char originChar;
		static char xAxisChar;
		static char yAxisChar;
		static float xMin;
		static float xMax;
		static float yMin;
		static float yMax;
		static int	displayWidth;
		static int	displayHeight;
    static float epsilon;
		static int xStepCount(Settings settings);
    static float stepWidth(Settings settings);
    static float stepHeight(Settings settings);
};

#endif
