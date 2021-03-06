#
# Copyright 2018-2019 CNRS-UM LIRMM, CNRS-AIST JRL
#

set(SOURCES OSQP.cpp CSCMatrix.cpp)
set(HEADERS eigen-osqp/OSQP.h eigen-osqp/CSCMatrix.h eigen-osqp/typedefs.h eigen-osqp/OSQP.hpp eigen-osqp/exportdecl.h)

add_library(${PROJECT_NAME} SHARED ${SOURCES} ${HEADERS})
target_include_directories(${PROJECT_NAME} PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}> $<INSTALL_INTERFACE:include>)
target_compile_definitions(${PROJECT_NAME} PRIVATE EIGEN_OSQP_EXPORTS)
target_link_libraries(${PROJECT_NAME} PUBLIC osqp::osqp)
if(TARGET Eigen3::Eigen)
  target_link_libraries(${PROJECT_NAME} PUBLIC Eigen3::Eigen)
else()
  target_include_directories(${PROJECT_NAME} SYSTEM PUBLIC "${EIGEN3_INCLUDE_DIR}")
endif()
set_target_properties(${PROJECT_NAME} PROPERTIES SOVERSION ${PROJECT_VERSION_MAJOR} VERSION ${PROJECT_VERSION})

set(INSTALL_PATH include/${PROJECT_NAME})
install(FILES ${HEADERS} DESTINATION ${INSTALL_PATH})
install(TARGETS ${PROJECT_NAME}
  EXPORT "${TARGETS_EXPORT_NAME}"
  RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
  LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
  ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
)
