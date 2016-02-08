#include "MyForm.h"
#include "Markup.h"

#include<string>
#include<stack>
#include<queue>
#include<vector>
#include<map>

using namespace std;
using namespace TextBox;




void main(array<String ^> ^args)
{
	Application::EnableVisualStyles(); Application::SetCompatibleTextRenderingDefault(false);

	MyForm ^ form = gcnew MyForm();
	Application::Run(form);

	Application::Exit();

}