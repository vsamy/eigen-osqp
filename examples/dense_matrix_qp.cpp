/*
 * Copyright 2018-2019 CNRS-UM LIRMM, CNRS-AIST JRL
 */

#include <Eigen/Core>
#include <eigen-osqp/CSCMatrix.h>
#include <eigen-osqp/OSQP.h>
#include <iostream>

int main()
{
    int nrVar = 6;
    int nrConstr = 5;
    auto inf = std::numeric_limits<double>::infinity();

    Eigen::MatrixXd Q = Eigen::MatrixXd::Identity(nrVar, nrVar);
    Eigen::MatrixXd A(nrConstr, nrVar);
    A << 1., -1., 1., 0., 3., 1.,
        -1., 0., -3., -4., 5., 6.,
        2., 5., 3., 0., 1., 0.,
        0., 1., 0., 1., 2., -1.,
        -1., 0., 2., 1., 1., 0.;

    Eigen::VectorXd c(nrVar);
    Eigen::VectorXd AL(nrConstr);
    Eigen::VectorXd AU(nrConstr);
    Eigen::VectorXd XL(nrVar);
    Eigen::VectorXd XU(nrVar);
    c << 1., 2., 3., 4., 5., 6.;
    AL << 1., 2., 3., -inf, -inf;
    AU << 1., 2., 3., -1., 2.5;
    XL << -1000., -10000., 0., -1000., -1000., -1000.;
    XU << 10000., 100., 1.5, 100., 100., 1000.;

    Eigen::OSQP qp;

    qp.problem(nrVar, nrConstr);
    bool success = qp.solve(Q, c, A, AL, AU, XL, XU);

    Eigen::VectorXd result = qp.result();

    std::cout << "Problem:"
              << "\n\tminimize 0.5*x'*Q*x + c'*x"
              << "\n\twith     AL <= A <= AU"
              << "\n\t         XL <= x <= XU"
              << "\n\nQ:\n"
              << Q
              << "\nc:\n"
              << c.transpose()
              << "\nA:\n"
              << A
              << "\nAL:\n"
              << AL.transpose()
              << "\nAU:\n"
              << AU.transpose()
              << "\nXL:\n"
              << XL.transpose()
              << "\nXU:\n"
              << XU.transpose()
              << "\n\n\nSolution:\n"
              << result.transpose() << std::endl;

    std::cout << "Press enter to quit" << std::endl;
    std::cin.get();
}
