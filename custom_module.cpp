#include <mujoco/mujoco.h>
#include <iostream>

using namespace std;

void my_function(mjData* data) {
    /*cout << data->qpos[0] << endl;*/
    /*cout << data->qpos[2] << endl; */
    /*cout << data->qpos[3] << endl;*/
    double res = data->qpos[0] * 2.0;
    cout << res << endl;
}
