#include <View/CGameView.h>
#include <mUI.h>
using namespace mUI::System::Forms;
#include <Windows.h>

int WINAPI WinMain( __in HINSTANCE hInstance, __in_opt HINSTANCE hPrevInstance, __in LPSTR lpCmdLine, __in int nShowCmd )
{
	mUI::Extra::HgeContext context;
	context.set_Size(Size(800, 600));
	Application::StartHge(context);
	Application::Run(new CGameView());

	return EXIT_SUCCESS;
}
