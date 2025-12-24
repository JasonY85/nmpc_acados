cmake_minimum_required(VERSION 3.0.2)
project(nmpc_acados)

add_compile_options(-std=c++17 -O3)

find_package(catkin REQUIRED COMPONENTS
  geometry_msgs
  nav_msgs
  roscpp
  tf2
  tf2_geometry_msgs
)

set(acados_include "$ENV{HOME}/acados/include")
set(acados_lib "$ENV{HOME}/acados/lib")

catkin_package(
  INCLUDE_DIRS include
  LIBRARIES nmpc_acados
  CATKIN_DEPENDS geometry_msgs nav_msgs roscpp tf2
)

# Build

include_directories(
include
/usr/local/include

${catkin_INCLUDE_DIRS}

${acados_include}
${acados_include}/blasfeo/include/
${acados_include}/hpipm/include/
${acados_include}/acados/
${acados_include}/qpOASES_e/

${PROJECT_SOURCE_DIR}/scripts/c_generated_code
)

link_directories(${PROJECT_SOURCE_DIR}/scripts/c_generated_code)
link_directories(/usr/local/lib)

add_executable(nmpc_acados_node src/nmpc_acados_node.cpp)
target_link_libraries(nmpc_acados_node
	${PROJECT_SOURCE_DIR}/scripts/c_generated_code/libacados_ocp_solver_jackal.so
	${acados_lib}/libacados.so
	${catkin_LIBRARIES}
)

add_executable(trajectory_publisher src/trajectory_publisher.cpp)
target_link_libraries(trajectory_publisher ${catkin_LIBRARIES})
add_dependencies(trajectory_publisher ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})

add_executable(odom_publisher src/odom_publisher.cpp)
target_link_libraries(odom_publisher ${catkin_LIBRARIES})
add_dependencies(odom_publisher ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})