#include "MovementDetection.h"

/*
* process frames - read frames from camera and detect movement
*/
bool MovementDetection::detectMovement(const cv::Mat& frame)
{
    // check if first frame
    if (m_isFirstFrame) {
		m_prevFrame = frame.clone();
        cv::cvtColor(m_prevFrame, m_prevFrame, cv::COLOR_BGR2GRAY);
		m_isFirstFrame = false;
        return false;
	}

    cv::Mat gray, frameDelta, thresh;
    std::vector<std::vector<cv::Point>> cnts;
    
    cv::cvtColor(frame, gray, cv::COLOR_BGR2GRAY);

    // Compute the absolute difference between the current frame and the previous frame
    cv::absdiff(m_prevFrame, gray, frameDelta);
    cv::threshold(frameDelta, thresh, THRESHOLD_LOWER, THRESHOLD_UPPER, cv::THRESH_BINARY);
    cv::dilate(thresh, thresh, cv::Mat(), cv::Point(-1, -1), 2);

    // Find contours in the thresholded image
    cv::findContours(thresh, cnts, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_SIMPLE);
    m_prevFrame = gray.clone(); // update previous frame

    for (size_t i = 0; i < cnts.size(); ++i) {
        if (cv::contourArea(cnts[i]) < THRESHOLD_AREA) {
            continue; // ignore small contours
        }
        return true; // movement detected
    }

    return false; // no movement detected
}