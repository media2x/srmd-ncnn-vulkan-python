%module srmd_ncnn_vulkan_wrapper

%include "cpointer.i"
%include "carrays.i"
%include "std_string.i"
%include "std_wstring.i"
%include "stdint.i"
%include "pybuffer.i"

%pybuffer_mutable_string(unsigned char *d);
%pointer_functions(std::string, str_p);
%pointer_functions(std::wstring, wstr_p);

%{
#include "srmd.h"
#include "srmd_wrapper.h"
%}

class SRMD
{
public:
        SRMD(int gpuid, bool tta_mode = false);
        ~SRMD();

        // realsr parameters
        int scale;
        int noise;
        int tilesize;
        int prepadding;
};
%include "srmd_wrapper.h"