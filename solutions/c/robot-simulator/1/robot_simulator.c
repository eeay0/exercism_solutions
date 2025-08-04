#include "robot_simulator.h"
#include <string.h>

robot_status_t robot_create(robot_direction_t direction, int x, int y) {
  robot_status_t tmp;
  tmp.direction = direction;
  tmp.position.x = x;
  tmp.position.y = y;
  return tmp;
}
void robot_move(robot_status_t *robot, const char *commands) {
  for (int i = 0; i < (int)strlen(commands); i++) {
    switch (commands[i]) {
    case 'R':
      if (robot->direction == DIRECTION_WEST) {
        robot->direction = DIRECTION_NORTH;
        break;
      }
      robot->direction += 1;
      break;
    case 'L':
      if (robot->direction == DIRECTION_NORTH) {
        robot->direction = DIRECTION_WEST;
        break;
      }
      robot->direction -= 1;
      break;
    case 'A':
      if (robot->direction == DIRECTION_NORTH) {
        robot->position.y += 1;
        break;
      }
      if (robot->direction == DIRECTION_SOUTH) {
        robot->position.y -= 1;
        break;
      }
      if (robot->direction == DIRECTION_EAST) {
        robot->position.x += 1;
        break;
      }
      if (robot->direction == DIRECTION_WEST) {
        robot->position.x -= 1;
        break;
      }
    }
  }
}
