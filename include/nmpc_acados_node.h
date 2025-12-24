#pragma once

// ROS
#include <ros/ros.h>
#include <nav_msgs/Odometry.h>
#include <geometry_msgs/PoseStamped.h>
#include <nav_msgs/Path.h>
#include <tf2/LinearMath/Quaternion.h>
#include <tf2_geometry_msgs/tf2_geometry_msgs.h>
#include <geometry_msgs/Twist.h>
#include <geometry_msgs/Quaternion.h>

// C++
#include <iostream>
#include <vector>
#include <cmath>


// ACADOS
#include "acados/utils/print.h"
#include "acados_c/ocp_nlp_interface.h"
#include "acados_c/external_function_interface.h"
#include "acados/ocp_nlp/ocp_nlp_constraints_bgh.h"
#include "acados/ocp_nlp/ocp_nlp_cost_ls.h"

// blasfeo
#include "blasfeo/include/blasfeo_d_aux.h"
#include "blasfeo/include/blasfeo_d_aux_ext_dep.h"

// Generated C code
#include "jackal_model/jackal_model.h"
#include "acados_solver_jackal.h"

using namespace std;
using std::vector;

struct OptTraj {
    bool   is_solved;
    double x[JACKAL_N+1];
    double y[JACKAL_N+1];
    double theta[JACKAL_N+1];
    double time_solving;
    double cost;
    double v[JACKAL_N] , w[JACKAL_N];
};

struct X0 {
    double x;
    double y;
    double theta;
};

struct Yref {
    double x[JACKAL_N];
    double y[JACKAL_N];
    double theta[JACKAL_N];
    double v[JACKAL_N] , w[JACKAL_N];
};

struct Yref_e {
    double x;
    double y;
    double theta;
};