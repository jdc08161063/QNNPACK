/*
 * Copyright (c) Facebook, Inc. and its affiliates.
 * All rights reserved.
 *
 * This source code is licensed under the BSD-style license found in the
 * LICENSE file in the root directory of this source tree.
 */

#include <gtest/gtest.h>

#include "convolution-tester.h"

#include <qnnpack/params.h>


TEST(CONVOLUTION, 1x1) {
  ConvolutionTester()
    .inputSize(27, 29)
    .kernelSize(1, 1)
    .groupInputChannels(23)
    .groupOutputChannels(19)
    .iterations(3)
    .test();
}

TEST(CONVOLUTION, 1x1_with_qmin) {
  ConvolutionTester()
    .inputSize(27, 29)
    .kernelSize(1, 1)
    .groupInputChannels(23)
    .groupOutputChannels(19)
    .qmin(128)
    .iterations(3)
    .test();
}

TEST(CONVOLUTION, 1x1_with_qmax) {
  ConvolutionTester()
    .inputSize(27, 29)
    .kernelSize(1, 1)
    .groupInputChannels(23)
    .groupOutputChannels(19)
    .qmax(128)
    .iterations(3)
    .test();
}

TEST(CONVOLUTION, 1x1_with_input_stride) {
  ConvolutionTester()
    .inputSize(27, 29)
    .kernelSize(1, 1)
    .inputPixelStride(28)
    .groupInputChannels(23)
    .groupOutputChannels(19)
    .iterations(3)
    .test();
}

TEST(CONVOLUTION, 1x1_with_output_stride) {
  ConvolutionTester()
    .inputSize(27, 29)
    .kernelSize(1, 1)
    .outputPixelStride(29)
    .groupInputChannels(23)
    .groupOutputChannels(19)
    .iterations(3)
    .test();
}

TEST(CONVOLUTION, 1x1_with_batch) {
  ConvolutionTester()
    .inputSize(13, 14)
    .kernelSize(1, 1)
    .batchSize(3)
    .groupInputChannels(23)
    .groupOutputChannels(19)
    .iterations(3)
    .test();
}

TEST(CONVOLUTION, grouped_1x1) {
  ConvolutionTester()
    .inputSize(24, 25)
    .kernelSize(1, 1)
    .groups(2)
    .groupInputChannels(17)
    .groupOutputChannels(19)
    .iterations(3)
    .test();
}

TEST(CONVOLUTION, xzp_1x1) {
  ASSERT_EQ(qnnp_status_success, qnnp_initialize());
  if (qnnp_params.q8conv_xzp.kthreshold != SIZE_MAX) {
    ConvolutionTester()
      .inputSize(27, 29)
      .kernelSize(1, 1)
      .groupInputChannels(qnnp_params.q8conv_xzp.kthreshold + 1)
      .groupOutputChannels(19)
      .iterations(3)
      .test();
  }
}

TEST(CONVOLUTION, xzp_1x1_with_qmin) {
  ASSERT_EQ(qnnp_status_success, qnnp_initialize());
  if (qnnp_params.q8conv_xzp.kthreshold != SIZE_MAX) {
    ConvolutionTester()
      .inputSize(27, 29)
      .kernelSize(1, 1)
      .groupInputChannels(qnnp_params.q8conv_xzp.kthreshold + 1)
      .groupOutputChannels(19)
      .qmin(128)
      .iterations(3)
      .test();
  }
}

TEST(CONVOLUTION, xzp_1x1_with_qmax) {
  ASSERT_EQ(qnnp_status_success, qnnp_initialize());
  if (qnnp_params.q8conv_xzp.kthreshold != SIZE_MAX) {
    ConvolutionTester()
      .inputSize(27, 29)
      .kernelSize(1, 1)
      .groupInputChannels(qnnp_params.q8conv_xzp.kthreshold + 1)
      .groupOutputChannels(19)
      .qmax(128)
      .iterations(3)
      .test();
  }
}

TEST(CONVOLUTION, xzp_1x1_with_input_stride) {
  ASSERT_EQ(qnnp_status_success, qnnp_initialize());
  if (qnnp_params.q8conv_xzp.kthreshold != SIZE_MAX) {
    ConvolutionTester()
      .inputSize(27, 29)
      .kernelSize(1, 1)
      .inputPixelStride(qnnp_params.q8conv_xzp.kthreshold + 5)
      .groupInputChannels(qnnp_params.q8conv_xzp.kthreshold + 1)
      .groupOutputChannels(19)
      .iterations(3)
      .test();
  }
}

TEST(CONVOLUTION, xzp_1x1_with_output_stride) {
  ASSERT_EQ(qnnp_status_success, qnnp_initialize());
  if (qnnp_params.q8conv_xzp.kthreshold != SIZE_MAX) {
    ConvolutionTester()
      .inputSize(27, 29)
      .kernelSize(1, 1)
      .outputPixelStride(29)
      .groupInputChannels(qnnp_params.q8conv_xzp.kthreshold + 1)
      .groupOutputChannels(19)
      .iterations(3)
      .test();
  }
}

TEST(CONVOLUTION, xzp_1x1_with_batch) {
  ASSERT_EQ(qnnp_status_success, qnnp_initialize());
  if (qnnp_params.q8conv_xzp.kthreshold != SIZE_MAX) {
    ConvolutionTester()
      .inputSize(13, 14)
      .kernelSize(1, 1)
      .batchSize(3)
      .groupInputChannels(qnnp_params.q8conv_xzp.kthreshold + 1)
      .groupOutputChannels(19)
      .iterations(3)
      .test();
  }
}

TEST(CONVOLUTION, grouped_xzp_1x1) {
  ASSERT_EQ(qnnp_status_success, qnnp_initialize());
  if (qnnp_params.q8conv_xzp.kthreshold != SIZE_MAX) {
    ConvolutionTester()
      .inputSize(24, 25)
      .kernelSize(1, 1)
      .groups(2)
      .groupInputChannels(qnnp_params.q8conv_xzp.kthreshold + 1)
      .groupOutputChannels(19)
      .iterations(3)
      .test();
  }
}

TEST(CONVOLUTION, 1x3) {
  ConvolutionTester()
    .inputSize(20, 19)
    .paddingWidth(1)
    .kernelSize(1, 3)
    .groupInputChannels(17)
    .groupOutputChannels(15)
    .iterations(3)
    .test();
}

TEST(CONVOLUTION, grouped_1x3) {
  ConvolutionTester()
    .inputSize(20, 19)
    .paddingWidth(1)
    .kernelSize(1, 3)
    .groups(2)
    .groupInputChannels(17)
    .groupOutputChannels(15)
    .iterations(3)
    .test();
}

TEST(CONVOLUTION, 3x1) {
  ConvolutionTester()
    .inputSize(19, 20)
    .paddingHeight(1)
    .kernelSize(3, 1)
    .groupInputChannels(17)
    .groupOutputChannels(15)
    .iterations(3)
    .test();
}

TEST(CONVOLUTION, grouped_3x1) {
  ConvolutionTester()
    .inputSize(19, 20)
    .paddingHeight(1)
    .kernelSize(3, 1)
    .groups(2)
    .groupInputChannels(17)
    .groupOutputChannels(15)
    .iterations(3)
    .test();
}

TEST(CONVOLUTION, 3x3) {
  ConvolutionTester()
    .inputSize(13, 12)
    .padding(1)
    .kernelSize(3, 3)
    .groupInputChannels(15)
    .groupOutputChannels(17)
    .iterations(3)
    .test();
}

TEST(CONVOLUTION, 3x3_without_padding) {
  ConvolutionTester()
    .inputSize(13, 12)
    .kernelSize(3, 3)
    .groupInputChannels(15)
    .groupOutputChannels(17)
    .iterations(3)
    .test();
}

TEST(CONVOLUTION, 3x3_with_left_padding) {
  ConvolutionTester()
    .inputSize(13, 12)
    .paddingLeft(1)
    .kernelSize(3, 3)
    .groupInputChannels(15)
    .groupOutputChannels(17)
    .iterations(3)
    .test();
}

TEST(CONVOLUTION, 3x3_with_right_padding) {
  ConvolutionTester()
    .inputSize(13, 12)
    .paddingRight(1)
    .kernelSize(3, 3)
    .groupInputChannels(15)
    .groupOutputChannels(17)
    .iterations(3)
    .test();
}

TEST(CONVOLUTION, 3x3_with_top_padding) {
  ConvolutionTester()
    .inputSize(13, 12)
    .paddingTop(1)
    .kernelSize(3, 3)
    .groupInputChannels(15)
    .groupOutputChannels(17)
    .iterations(3)
    .test();
}

TEST(CONVOLUTION, 3x3_with_bottom_padding) {
  ConvolutionTester()
    .inputSize(13, 12)
    .paddingBottom(1)
    .kernelSize(3, 3)
    .groupInputChannels(15)
    .groupOutputChannels(17)
    .iterations(3)
    .test();
}

TEST(CONVOLUTION, 3x3_with_input_stride) {
  ConvolutionTester()
    .inputSize(13, 12)
    .padding(1)
    .kernelSize(3, 3)
    .inputPixelStride(22)
    .groupInputChannels(15)
    .groupOutputChannels(17)
    .iterations(3)
    .test();
}

TEST(CONVOLUTION, 3x3_with_output_stride) {
  ConvolutionTester()
    .inputSize(13, 12)
    .padding(1)
    .kernelSize(3, 3)
    .outputPixelStride(23)
    .groupInputChannels(15)
    .groupOutputChannels(17)
    .iterations(3)
    .test();
}

TEST(CONVOLUTION, 3x3_with_batch) {
  ConvolutionTester()
    .inputSize(10, 9)
    .padding(1)
    .kernelSize(3, 3)
    .batchSize(3)
    .groupInputChannels(15)
    .groupOutputChannels(17)
    .iterations(3)
    .test();
}

TEST(CONVOLUTION, grouped_3x3) {
  ConvolutionTester()
    .inputSize(10, 11)
    .padding(1)
    .kernelSize(3, 3)
    .groups(2)
    .groupInputChannels(14)
    .groupOutputChannels(13)
    .iterations(3)
    .test();
}

TEST(CONVOLUTION, 3x3s2) {
  ConvolutionTester()
    .inputSize(19, 21)
    .padding(1)
    .kernelSize(3, 3)
    .subsampling(2)
    .groupInputChannels(27)
    .groupOutputChannels(19)
    .iterations(3)
    .test();
}

TEST(CONVOLUTION, 3x3s1x2) {
  ConvolutionTester()
    .inputSize(13, 13)
    .padding(1)
    .kernelSize(3, 3)
    .subsampling(1, 2)
    .groupInputChannels(27)
    .groupOutputChannels(19)
    .iterations(3)
    .test();
}

TEST(CONVOLUTION, 3x3s2x1) {
  ConvolutionTester()
    .inputSize(13, 13)
    .padding(1)
    .kernelSize(3, 3)
    .subsampling(2, 1)
    .groupInputChannels(27)
    .groupOutputChannels(19)
    .iterations(3)
    .test();
}

TEST(CONVOLUTION, 3x3d2) {
  ConvolutionTester()
    .inputSize(13, 14)
    .padding(2)
    .kernelSize(3, 3)
    .dilation(2)
    .groupInputChannels(27)
    .groupOutputChannels(19)
    .iterations(3)
    .test();
}

TEST(CONVOLUTION, 3x3d1x2) {
  ConvolutionTester()
    .inputSize(14, 15)
    .padding(1, 2)
    .kernelSize(3, 3)
    .dilation(1, 2)
    .groupInputChannels(27)
    .groupOutputChannels(19)
    .iterations(3)
    .test();
}

TEST(CONVOLUTION, 3x3d2x1) {
  ConvolutionTester()
    .inputSize(15, 14)
    .padding(2, 1)
    .kernelSize(3, 3)
    .dilation(2, 1)
    .groupInputChannels(27)
    .groupOutputChannels(19)
    .iterations(3)
    .test();
}

TEST(CONVOLUTION, depthwise_3x3) {
  ConvolutionTester()
    .inputSize(15, 14)
    .padding(1, 1)
    .kernelSize(3, 3)
    .groups(27)
    .iterations(3)
    .test();
}

TEST(CONVOLUTION, depthwise_3x3s2) {
  ConvolutionTester()
    .inputSize(15, 14)
    .padding(1, 1)
    .kernelSize(3, 3)
    .subsampling(2)
    .groups(27)
    .iterations(3)
    .test();
}

TEST(CONVOLUTION, depthwise_3x3s1x2) {
  ConvolutionTester()
    .inputSize(15, 14)
    .padding(1, 1)
    .kernelSize(3, 3)
    .subsampling(1, 2)
    .groups(27)
    .iterations(3)
    .test();
}

TEST(CONVOLUTION, depthwise_3x3s2x1) {
  ConvolutionTester()
    .inputSize(15, 14)
    .padding(1, 1)
    .kernelSize(3, 3)
    .subsampling(2, 1)
    .groups(27)
    .iterations(3)
    .test();
}

TEST(CONVOLUTION, depthwise_3x3d2) {
  ConvolutionTester()
    .inputSize(15, 14)
    .padding(1, 1)
    .kernelSize(3, 3)
    .dilation(2)
    .groups(27)
    .iterations(3)
    .test();
}

TEST(CONVOLUTION, depthwise_3x3d1x2) {
  ConvolutionTester()
    .inputSize(15, 14)
    .padding(1, 1)
    .kernelSize(3, 3)
    .dilation(1, 2)
    .groups(27)
    .iterations(3)
    .test();
}

TEST(CONVOLUTION, depthwise_3x3d2x1) {
  ConvolutionTester()
    .inputSize(15, 14)
    .padding(1, 1)
    .kernelSize(3, 3)
    .dilation(2, 1)
    .groups(27)
    .iterations(3)
    .test();
}
