/*
 * Application.c
 *
 *  Created on: Oct 31, 2023
 *      Author: Jacob Ramirez
 */

#include <Application.h>

Application Application_construct()
{
    Application app;

    app.firstCall = true;

    return app;
}

void Application_loop(Application* app_p, HAL* hal_p)
{

}
