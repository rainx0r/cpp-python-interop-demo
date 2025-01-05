#include <iostream>
#include <mujoco/mujoco.h>

using namespace std;

void my_function(mjData *data) {
  double res = data->qpos[0] * 2.0;
  cout << res << endl;
}
