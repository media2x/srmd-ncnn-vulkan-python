//
// Created by archiemeng on 12/4/21.
//

#include "srmd_wrapper.h"

SRMDWrapper::SRMDWrapper(int gpuid, bool tta_mode): SRMD(gpuid, tta_mode) {}

int SRMDWrapper::load(const StringType &parampath, const StringType &modelpath) {
#if _WIN32
    return SRMD::load(*parampath.wstr, *modelpath.wstr);
#else
    return SRMD::load(*parampath.str, *modelpath.str);
#endif
}

int SRMDWrapper::process(const Image &inimage, Image &outimage) const {
    int c = inimage.elempack;
    ncnn::Mat inimagemat = ncnn::Mat(inimage.w, inimage.h, (void*) inimage.data, (size_t) c, c);
    ncnn::Mat outimagemat = ncnn::Mat(outimage.w, outimage.h, (void*) outimage.data, (size_t) c, c);
    return SRMD::process(inimagemat, outimagemat);
}

uint32_t get_heap_budget(int gpuid) {
    return ncnn::get_gpu_device(gpuid)->get_heap_budget();
}

int get_gpu_count() {
    return ncnn::get_gpu_count();
}