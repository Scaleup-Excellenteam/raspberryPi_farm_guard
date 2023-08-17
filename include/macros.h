#pragma once

#include <csignal>
#include <iostream>
#include <string>
#include "opencv2/opencv.hpp"

const int cameraIndex = 0;
constexpr int CAMERA_WIDTH = 512;
constexpr int CAMERA_HEIGHT = 288;
constexpr int ESC_KEY = 27;
constexpr int FRAME_SIZE = 224;
constexpr int THRESHOLD_LOWER = 65;
constexpr int THRESHOLD_UPPER = 255;
constexpr int THRESHOLD_AREA = 350;