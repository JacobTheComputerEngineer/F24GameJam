/*
 * Application.h
 */

#ifndef APPLICATION_H_
#define APPLICATION_H_

#include <HAL/HAL.h>

enum _GameState { Place, your, states, here };
typedef enum _GameState GameState;

struct _Application
{
    bool firstCall;
    GameState gameState;
};
typedef struct _Application Application;

// Called only a single time - inside of main(), where the application is constructed
Application Application_construct();

// Called once per super-loop of the main application.
void Application_loop(Application* app, HAL* hal);



#endif /* APPLICATION_H_ */
