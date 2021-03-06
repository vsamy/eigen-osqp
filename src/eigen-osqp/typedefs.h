/*
 * Copyright 2018-2019 CNRS-UM LIRMM, CNRS-AIST JRL
 */

#pragma once

#include <Eigen/Core>
#include <Eigen/SparseCore>
#include <osqp.h>

// Matrices must be Column-major (default) !!
// The library won't work for Row-major matrices.
using MatrixDense = Eigen::Matrix<c_float, Eigen::Dynamic, Eigen::Dynamic>;
using VectorDense = Eigen::Matrix<c_float, Eigen::Dynamic, 1>;
using MatrixConstRef = Eigen::Ref<const MatrixDense>;
using VectorConstRef = Eigen::Ref<const VectorDense>;
using MatrixSparse = Eigen::SparseMatrix<c_float>;
using MatrixCompressSparseConstRef = Eigen::Ref<const MatrixSparse, Eigen::StandardCompressedFormat>;
