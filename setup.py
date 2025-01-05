import pathlib

import mujoco
from setuptools import setup

setup(
    cmake_source_dir=".",
    cmake_args=[f"-DMUJOCO_HEADER_DIR:STRING={pathlib.Path(mujoco.HEADERS_DIR).parent}"],
)

