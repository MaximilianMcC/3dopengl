#include "Window.hpp"

void Window::Init(std::string title, int width, int height)
{
	// Create the physical GLFW window
	{
		// Get errors
		glfwSetErrorCallback(Window::PrintWindowErrorCallback);

		glfwInit();
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_COMPAT_PROFILE);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);

		// Have the window initially hidden whilst we do setup
		glfwWindowHint(GLFW_VISIBLE, GLFW_FALSE);

		// Make an 'unpopulated' window
		//? can't use 0 as a window size
		window = glfwCreateWindow(1, 1, "LOADING", NULL, NULL);
		if (window == NULL)
		{
			std::cout << "Couldn't initialise window\n";
			glfwTerminate();
			std::exit(-1);
		}
		
		// Select the window
		glfwMakeContextCurrent(window);
		
		// Initialise the extension wrangler
		glewInit();

		// Set the clear colour
		//? This is like a dark grey kinda thing rn
		glClearColor(0.2f, 0.2f, 0.2f, 1.0f);

		// Let us resize the window
		glfwSetWindowSizeCallback(window, Window::WindowResizeCallback);
	}

	// Set the titlebar stats
	SetWidth((float)width);
	SetHeight((float)height);
	SetTitle(title);

	// Centre the window
	// TODO: Put this somewhere else
	{
		// TODO: Define on different lines
		// TODO: See if there is a cpp version of C#'s _
		// TODO: Make a monitor class that also tells you what monitor your on incase you're not using primary
		// Get how large the users screen is
		int x, y, monitorWidth, monitorHeight;
		glfwGetMonitorWorkarea(glfwGetPrimaryMonitor(), &x, &y, &monitorWidth, &monitorHeight);

		// Calculate the centre of it
		float centerX = (monitorWidth - GetWidth()) / 2.0f;
		float centerY = (monitorHeight - GetHeight()) / 2.0f;

		// Put the window in the centre of the screen
		SetPosition(centerX, centerY);
	}

	// Window setup finished. Show it
	windowInitialized = true;
	glfwShowWindow(window);

	// Set up the other stuff
	{
		Graphics::Init();
		Input::Init();
	}

	// Window setup is actually finished
	windowRunning = true;
}

void Window::Update()
{
	// Check for if the window is even open
	if (windowRunning == false) return;

	// Get time and calculate delta time
	time = (float)glfwGetTime();
	deltaTime = time - lastFrameTime;
	lastFrameTime = time;

	// Do window stuff
	glfwPollEvents();

	// Check for if we need to close the window
	if (glfwWindowShouldClose(window) == GLFW_TRUE)
	{		
		windowRunning = false;
	}

	// Do like non window windodey stuff
	Input::Capture();

	// Check for wireframe toggle
	if (Input::KeyPressed(GLFW_KEY_2)) Graphics::SetWireframeModeEnabled(!Graphics::WireframeModeEnabled());
}

void Window::Close()
{
	windowRunning = false;
}

void Window::CleanUp()
{
	// Don't clean up twice
	if (windowInitialized == false) return;

	if (window)
	{
		glfwDestroyWindow(window);
		window == nullptr;
	}

	glfwTerminate();

	windowInitialized = false;
	windowRunning = false;
}

void Window::WindowResizeCallback(GLFWwindow* window, int newWidth, int newHeight)
{
	SetWidth(newWidth);
	SetHeight(newHeight);
}

void Window::PrintWindowErrorCallback(int error, const char *description)
{
	fprintf(stderr, "GLFW Error %d: %s\n", error, description);
}
