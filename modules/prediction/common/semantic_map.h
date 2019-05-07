/******************************************************************************
 * Copyright 2019 The Apollo Authors. All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or
 *implied. See the License for the specific language governing
 *permissions and limitations under the License.
 *****************************************************************************/

#pragma once

#include "opencv2/opencv.hpp"
#include "opencv2/highgui/highgui.hpp"

#include "cyber/common/macros.h"
#include "modules/prediction/proto/feature.pb.h"

namespace apollo {
namespace prediction {

class SemanticMap {
 public:
  virtual ~SemanticMap() = default;

  void Init();

  void RunCurrFrame(const FrameEnv& curr_frame_env);

 private:
  void GetTransPoint();

 private:
  cv::Mat base_img_;
  cv::Mat curr_img_;
  double curr_base_x_ = 0.0;
  double curr_base_y_ = 0.0;

  DECLARE_SINGLETON(SemanticMap)
};

}  // namespace prediction
}  // namespace apollo
