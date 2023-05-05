
#ifndef X11ENGINE_h
#define X11ENGINE_h

#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <X11/Xos.h>
#include <stdlib.h>

class X11Engine {

	public:
		XEvent			event;
		bool			shouldClose;
		XWindowAttributes	windowAttributes;

		X11Engine(
				const char* windowTitle, 
				const char* shortWindowTitle,
			       	unsigned long borderColor,
				unsigned long backgroundColor	
				) {

			this->windowTitle	= windowTitle;
			this->shortWindowTitle	= shortWindowTitle;
			this->borderColor	= borderColor;
			this->backgroundColor 	= backgroundColor;

			init_x();


		}
	
		~X11Engine() {
		
			close_x();

		};

		void clear() {

			draw_x();

		}

		void pollEvents() {

			XNextEvent(dis, &event);
			if(event.type == DestroyNotify)
				shouldClose = true;

			XGetWindowAttributes(
				dis,
				win,
				&windowAttributes
				);

		}

		void drawRect(
				int x, 
				int y, 
				unsigned int width, 
				unsigned int height, 
				unsigned long color
				) {

			XSetForeground(dis, gc, color);
			XFillRectangle(
					dis, 
					win, 
					gc, 
					x, 
					y, 
					width, 
					height
					);

		}

		void pointerCoords(
				int* x_return,
				int* y_return
				) {

    			Window root, child;
    			int root_x, root_y, win_x, win_y;
    			unsigned int mask;

			XQueryPointer(
					dis, 
					win, 
					&root, 
					&child, 
					&root_x, 
					&root_y, 
					x_return, 
					y_return, 
					&mask
					);

		}

	private:
		Display*	dis;
		int	 	screen;
		Window	 	win;
		GC	 	gc;		


		const char*		windowTitle;
		const char*		shortWindowTitle;
		unsigned long	 	borderColor;
		unsigned long 		backgroundColor;

		void init_x() {

			dis 	= XOpenDisplay((char *)0);
			screen 	= DefaultScreen(dis);	

			win	= XCreateSimpleWindow(
					dis, 
					DefaultRootWindow(dis), 
					0, 
					0, 
					300, 
					300, 
					5, 
					borderColor, 
					backgroundColor);

			XSetStandardProperties(
					dis,
				       	win, 
					windowTitle, 
					shortWindowTitle, 
					None, 
					NULL, 
					0, 
					NULL);

			XSelectInput(
					dis, 
					win, 
					ExposureMask | 
					ButtonPressMask | 
					KeyPressMask | 
					StructureNotifyMask |
					PointerMotionMask
					);

			gc	= XCreateGC(dis, win, 0, 0);
			XClearWindow(dis, win);
			XMapWindow(dis, win);
			

		}

		void close_x() {

			XFreeGC(dis, gc);
			XCloseDisplay(dis);
			exit(0);

		}

		void draw_x() {

			XClearWindow(dis, win);

		}

};

#endif

