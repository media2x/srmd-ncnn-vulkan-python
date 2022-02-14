#!/usr/bin/env python3
# -*- coding: utf-8 -*-
from PIL import Image
from srmd_ncnn_vulkan_python import Srmd
import time

start_time = time.time()
input_image = Image.open("input.png")
upscaler = Srmd(0)
output_image = upscaler.process(input_image)
output_image.save("output.png")
print(f"Elapsed time: {time.time() - start_time} secs")
