#include "openxr_fb_body_tracking_extension_wrapper.h"
#include <open_xrapi_extension.hpp>


using namespace godot;

OpenXRFBBodyTrackingExtensionWrapper *OpenXRFBBodyTrackingExtensionWrapper::singleton = nullptr;

OpenXRFBBodyTrackingExtensionWrapper *OpenXRFBBodyTrackingExtensionWrapper::get_singleton() {
    if(singleton == nullptr) {
        singleton = memnew(OpenXRFBBodyTrackingExtensionWrapper());
    }
    return singleton;
} 

OpenXRFBBodyTrackingExtensionWrapper::OpenXRFBBodyTrackingExtensionWrapper() {
    ERR_FAIL_COND_MSG(singleton != nullptr, "An OpenXRFBBodyTrackingExtensionWrapper singleton already exists.");
    request_extensions[XR_FB_BODY_TRACKING_EXTENSION_NAME] = &fb_body_tracking_ext;
    singleton = this;
}

void OpenXRFBBodyTrackingExtensionWrapper::_on_instance_created(uint64_t instance) {
    if(fb_body_tracking_ext) {
        //TODO: What is _V used for?
        GDEXTENSION_INIT_XR_FUNC(xrCreateBodyTrackerFB);
        GDEXTENSION_INIT_XR_FUNC(xrDestroyBodyTrackerFB);
    }
} 

void OpenXRFBBodyTrackingExtensionWrapper::_on_instance_destroyed() {
    if(fb_body_tracking_ext) {
        
    }
}

void OpenXRFBBodyTrackingExtensionWrapper::_on_process() {
    OpenXRAPIExtension gateway = OpenXRAPIExtension();
    //TODO: Verify if this works...
    uint64_t xr_time = gateway.get_next_frame_time();
    uint64_t xr_play_space = gateway.get_play_space();
}

Dictionary OpenXRFBBodyTrackingExtensionWrapper::_get_requested_extensions() {
   godot::Dictionary result;
	for (auto ext: request_extensions) {
		godot::String key = ext.first;
		uint64_t value = reinterpret_cast<uint64_t>(ext.second);
		result[key] = (godot::Variant)value;
	}
	return result;
}

void OpenXRFBBodyTrackingExtensionWrapper::_bind_methods() {
    ClassDB::bind_static_method("OpenXRFBBodyTrackingExtensionWrapper", D_METHOD("get_singleton"), &OpenXRFBBodyTrackingExtensionWrapper::get_singleton);
	ClassDB::bind_method(D_METHOD("is_body_tracking_supported"), &OpenXRFBBodyTrackingExtensionWrapper::is_body_tracking_supported);
}

