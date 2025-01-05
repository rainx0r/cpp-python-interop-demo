#include <mujoco/mujoco.h>
#include <iostream>

using namespace std;

void my_function(mjData* data) {
    cout << data->qpos[0] << "\n";
    cout << data->qpos[2] << "\n";
    cout << data->qpos[3] << "\n";
}
