#ifndef OPENXR_FB_BODY_TRACKING_EXTENSION_WRAPPER_H
#define OPENXR_FB_BODY_TRACKING_EXTENSION_WRAPPER_H

#include <openxr/openxr.h>
#include <openxr/fb_body_tracking.h>
#include <godot_cpp/classes/open_xr_extension_wrapper_extension.hpp>
#include <godot_cpp/variant/utility_functions.hpp>

#include "util.h"

namespace godot {

    class OpenXRFBBodyTrackingExtensionWrapper : public OpenXRExtensionWrapperExtension {
        GDCLASS(OpenXRFBBodyTrackingExtensionWrapper, OpenXRExtensionWrapperExtension)
    }

    public:
        static OpenXRFBBodyTrackingExtensionWrapper* get_singleton();





}



#endif