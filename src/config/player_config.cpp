#include <graphics_config.h>
#include <player_config.h>

namespace playerConfig{
    double X_ACCEL = 0.002;
    double FLY_ACCEL = 0.003;
    double MAX_DX = 1;
    double MAX_DY = 1;
    double MAX_DDX = 0.1;
    double MAX_DDY = 0.1;
    double JUMP_SPEED = -1;
    int INITIAL_X = graphicsConfig::WINDOW_WIDTH/4; 
    int INITIAL_Y = graphicsConfig::WINDOW_HEIGHT;
}