## 1. Prerequisites
* Ubuntu = 20.04 
* ROS noetic
* Jackal simulation **under the same workspace** (Follow instructions below)

```bash
cd ~/catkin_ws/src  # cd into a catkin workspace folder
git clone https://github.com/JasonY85/jackal.git
git clone https://github.com/jackal/jackal_simulator.git
git clone https://github.com/jackal/jackal_desktop.git
```

## 2. nmpc_acados setup

```bash
cd ~/catkin_ws/src  # cd into a catkin workspace folder
git clone https://github.com/JasonY85/nmpc_acados.git -b noetic
cd ~/catkin_ws/src/nmpc_acados
chmod +x setup_acados.sh
./setup_acados.sh
chmod +x create_solver.sh
./create_solver.sh
cd ..
catkin_make
chmod +x bringup.sh
./bringup.sh
```

## 3. Topics
**nmpc_acados_node**

**Publisher** | **Subscriber**            
:-------------------:|:------------------
/cmd_vel  |  /odometry/filtered 
/predicted_path  |  /trajectory
/reference_path  |  

## 4. Note 
These two sets of commands are always done when using Acados (refer to bringup.sh)

Put them inside bashrc for convenience by running **gedit ~/.bashrc** **(optional)**
```
export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:"$HOME/acados/lib"

export ACADOS_SOURCE_DIR="$HOME/acados"
```
