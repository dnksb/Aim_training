#include "start_menu.h"
#include <WinUser.h>
#include <Windows.h>
#include <cstdlib>
using namespace Aimtraining;
using namespace System;
using namespace System::Windows::Forms;

int main() {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Aimtraining::Start_menu form;
	Application::Run(% form);

}