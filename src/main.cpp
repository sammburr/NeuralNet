#include <iostream>
#include <X11/X11Engine.h>
#include <Colors/color.h>

X11Engine* engine;

int main() {
	
	engine = new X11Engine("Hello World", "H W", WHITE, BLACK);

	int rectWidth	= 30, 
	    rectHeight	= 30,
	    rectPad	= 3;

	RGB rectCol = WHITE;

	while(!engine->shouldClose) {

		engine->pollEvents();
		engine->clear();

		for(int i=0; i<3; i++) {

			for(int j=0; j<3; j++) {


				int x,y;
				engine->pointerCoords(&x, &y);

				
				if(
						x > rectPad + i*rectWidth + i*rectPad && 
						y > rectPad + j*rectHeight + j*rectPad && 
						x < rectPad + i*rectWidth + i*rectPad + rectWidth && 
						y <rectPad + j*rectHeight + j*rectPad +  rectHeight
						)
					rectCol = RED;
				else
					rectCol = WHITE;
			
				engine->drawRect(
						rectPad + i*rectWidth + i*rectPad, 
						rectPad + j*rectHeight + j*rectPad, 
						rectWidth, 
						rectHeight, 
						rectCol
						);

			}

		}


		rectWidth = 
			(engine->windowAttributes.width 
			- (2 * rectPad)
			)/ 3;
		rectHeight = 
			(engine->windowAttributes.height 
			- (2 * rectPad)
			)/ 3;
		
		rectWidth  = std::min(rectWidth, rectHeight);
		rectHeight = std::min(rectWidth, rectHeight);

	}

	delete(engine);
	return 0;

}
