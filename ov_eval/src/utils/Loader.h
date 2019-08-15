/*
 * OpenVINS: An Open Platform for Visual-Inertial Research
 * Copyright (C) 2019 Patrick Geneva
 * Copyright (C) 2019 Kevin Eckenhoff
 * Copyright (C) 2019 Guoquan Huang
 * Copyright (C) 2019 OpenVINS Contributors
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */
#ifndef OV_EVAL_LOADER_H
#define OV_EVAL_LOADER_H


#include <string>
#include <iostream>
#include <fstream>

#include <Eigen/Eigen>
#include <boost/filesystem.hpp>

#include <ros/ros.h>


namespace ov_eval {


    /**
     * @brief Has helper functions to load text files from disk and process them.
     */
    class Loader {

    public:

        /**
         * @brief This will load space seperated trajectory into memory
         * @param path_traj Path to the trajectory file that we want to read in.
         * @param times Timesteps in seconds
         * @param poses Pose at every timestep [pos,quat]
         * @param cov_ori Vector of orientation covariances at each timestep (empty if we can't load)
         * @param cov_pos Vector of position covariances at each timestep (empty if we can't load)
         */
        static void load_data(std::string path_traj,
                              std::vector<double> &times, std::vector<Eigen::Matrix<double,7,1>> &poses,
                              std::vector<Eigen::Matrix3d> &cov_ori, std::vector<Eigen::Matrix3d> &cov_pos);

        /**
         * @brief Load a arbitrary sized row of values, used for our simulation
         * @param path Path to our text file to load
         * @param values Each row of values
         */
        static void load_simulation(std::string path, std::vector<Eigen::VectorXd> &values);

        /**
         * @brief Will calculate the total trajectory distance
         * @param poses Pose at every timestep [pos,quat]
         * @return Distance travels (meters)
         */
        static double get_total_length(const std::vector<Eigen::Matrix<double,7,1>> &poses);

    private:

        /**
         * All function in this class should be static.
         * Thus an instance of this class cannot be created.
         */
        Loader() {}

    };



}

#endif //OV_EVAL_LOADER_H
