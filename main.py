# pyright: reportAttributeAccessIssue=false
from time import time

import mujoco
import numpy as np
from cpp_python_interop import my_function


def my_function_py(data: mujoco._structs.MjData):
    print(data.qacc[0] * 2)


def main():
    np.set_printoptions(suppress=True)

    model = mujoco.MjModel.from_xml_path("./model.xml")
    data = mujoco.MjData(model)
    mujoco.mj_resetData(model, data)

    HAND_INIT_POS = np.array((0, 0.6, 0.2))
    HAND_INIT_QUAT = np.array([1, 0, 1, 0])
    MOCAP_ID = model.body_mocapid[data.body("mocap").id]

    data.mocap_pos[MOCAP_ID][:] = HAND_INIT_POS
    data.mocap_quat[MOCAP_ID][:] = HAND_INIT_QUAT

    start_time = time()

    for _ in range(1_000_000):
        # simulate
        mujoco.mj_step(model, data)
        my_function(data)

    print("Time taken (s):", time() - start_time)
    print("After 1_000_000 steps:")
    print("- qacc:", data.qacc[:])
    # print("- qvel:", data.qvel[:])
    # print("- qpos:", data.qpos[:])
    print("- time", data.time)


if __name__ == "__main__":
    main()
