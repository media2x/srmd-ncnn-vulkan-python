#!/usr/bin/env python3
# -*- coding: utf-8 -*-
import logging
from pathlib import Path

from PIL import Image, ImageChops, ImageStat
from srmd_ncnn_vulkan_python import SRMD

tests_path = Path(__file__).parent
images_path = (
        tests_path.parent / "srmd_ncnn_vulkan_python" / "srmd-ncnn-vulkan" / "images"
)
gpu_id = 0


def _calc_image_diff(image0: Image.Image, image1: Image.Image) -> float:
    """
    calculate the percentage of differences between two images

    :param image0 Image.Image: the first frame
    :param image1 Image.Image: the second frame
    :rtype float: the percent difference between the two images
    """
    difference = ImageChops.difference(image0, image1)
    difference_stat = ImageStat.Stat(difference)
    percent_diff = sum(difference_stat.mean) / (len(difference_stat.mean) * 255) * 100
    return percent_diff


def test_default():
    input_image = Image.open(images_path / "0.jpg")
    upscaler = SRMD(gpu_id)
    output_image = upscaler.process(input_image)

    test_image = Image.open(tests_path / "0_default.png")
    percent_diff = _calc_image_diff(test_image, output_image)
    logging.getLogger().info(f"%diff: {percent_diff}")

    test_image.close()
    output_image.close()
    input_image.close()

    assert percent_diff < 0.5
