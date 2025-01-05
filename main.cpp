#include <mujoco/mujoco.h>
#include <iostream>
#include "custom_module.cpp"

using namespace std;

mjModel* m = NULL;
mjData* d = NULL;

int main(int argc, const char** argv) {
    char error[1000] = "Could not load binary model";
    m = mj_loadXML("./model.xml", 0, error, 1000); 
    if (!m) {
        mju_error("Load model error: %s", error);
    }
    d = mj_makeData(m);
    mj_resetData(m, d);

    double HAND_INIT_POS[3] = {0.0, 0.6, 0.2};
    double HAND_INIT_QUAT[4] = {1.0, 0.0, 1.0, 0.0};

    int mocap_body_id = mj_name2id(m, mjOBJ_BODY, "mocap");
    int mocap_id = m->body_mocapid[mocap_body_id];
    for(int i = 0; i < 3; ++i) {
        d->mocap_pos[mocap_id * 3 + i] = HAND_INIT_POS[i];
    }
    for(int i = 0; i < 4; ++i) {
        d->mocap_quat[mocap_id * 4 + i] = HAND_INIT_QUAT[i];
    }

    mj_step(m, d);

    cout << "After 1 step:" << "\n";
    cout << "- qacc: [";
    for(int i = 0; i < 9; ++i) {
        cout << d->qacc[i] << " ";
    }
    cout << "]" << "\n";
    cout << "- time " << d->time << "\n"; 

    my_function(d);

    mj_deleteData(d);
    mj_deleteModel(m);

    return 0;
}
