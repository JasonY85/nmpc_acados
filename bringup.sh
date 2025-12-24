#!/bin/bash

# Open multiple terminal windows
gnome-terminal --tab -- bash -c ' \
    source ~/catkin_ws/devel/setup.bash; \
    roslaunch jackal_gazebo empty_world.launch; \
    exec bash'

sleep 10

gnome-terminal --tab -- bash -c ' \
    source ~/catkin_ws/devel/setup.bash; \
    roslaunch nmpc_acados tracking_env.launch; \
    exec bash'

sleep 1

gnome-terminal --tab -- bash -c ' \
    export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:"$HOME/acados/lib"; \
    export ACADOS_SOURCE_DIR="$HOME/acados"; \
    source ~/catkin_ws/devel/setup.bash; \
    roslaunch nmpc_acados set_weight.launch; \
    exec bash'
