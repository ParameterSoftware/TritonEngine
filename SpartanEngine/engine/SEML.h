#include "Window.h"
#include "VBO.h"


namespace seml
{
	bool Init(); ///< Intialization Function for SEML
	//Window Management
	sewm::Window* CreateNewWindow(int width, int height, const char* title);
	sewm::Window* GetMainWindow();
	//Graphic Management
	int LoadImage(float scale, const char* path);
	seg::VBO* LoadModel(float scale, const char* path);
	int BindModelImage(int model, int image);
	int LoadObject(float scale, const char* path);
	int LoadBillboard(float scale, const char* path);
	double rand();
	double sqrt(double x);

}