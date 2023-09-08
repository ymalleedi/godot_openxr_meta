#include "openxr_fb_body_tracking_extension_wrapper.h"
#include <godot_cpp/classes/open_xrapi_extension.hpp>


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
        GDEXTENSION_INIT_XR_FUNC(xrLocateBodyJointsFB);
    }
} 

void OpenXRFBBodyTrackingExtensionWrapper::_on_instance_destroyed() {
    if(fb_body_tracking_ext) {
        
    }
}

void OpenXRFBBodyTrackingExtensionWrapper::_on_state_ready() {
    if(fb_body_tracking_ext) {
        body_tracker.is_initialized = false;
        body_tracker.body_tracker_handle = XR_NULL_HANDLE;
        memset(&body_tracker.joint_locations, 0, sizeof(XrBodyJointLocationFB) * XR_BODY_JOINT_COUNT_FB);
        memset(&body_tracker.locations, 0, sizeof(XrBodyJointLocationsFB));
    }
}

void OpenXRFBBodyTrackingExtensionWrapper::_on_process() {
    //TODO: Verify if this works...
    uint64_t xr_time = get_openxr_api()->get_next_frame_time();
    uint64_t xr_play_space = get_openxr_api()->get_play_space();

    //Create the handle
    if(!body_tracker.is_initialized) {
        XrBodyTrackerCreateInfoFB p_createInfo;
            p_createInfo.type = XR_TYPE_BODY_TRACKER_CREATE_INFO_FB;
            p_createInfo.next = nullptr;
            p_createInfo.bodyJointSet = XR_BODY_JOINT_SET_DEFAULT_FB;

        XrResult result = xrCreateBodyTrackerFB( (XrSession) get_openxr_api()->get_session(), &p_createInfo, &body_tracker.body_tracker_handle );
        UtilityFunctions::print("The result of creating Body Tracker Handle is: ", result);
        if (result == XR_SUCCESS) {
            body_tracker.is_initialized = true;
        }
    }
    
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

