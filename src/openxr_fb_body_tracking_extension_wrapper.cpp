#include "openxr_fb_body_tracking_extension_wrapper.h"
#include <godot_cpp/classes/open_xrapi_extension.hpp>

using namespace godot;

const char *joint_names[] = {
    "XR_BODY_JOINT_ROOT_FB",
    "XR_BODY_JOINT_HIPS_FB",
    "XR_BODY_JOINT_SPINE_LOWER_FB",
    "XR_BODY_JOINT_SPINE_MIDDLE_FB",
    "XR_BODY_JOINT_SPINE_UPPER_FB",
    "XR_BODY_JOINT_CHEST_FB",
    "XR_BODY_JOINT_NECK_FB",
    "XR_BODY_JOINT_HEAD_FB",
    "XR_BODY_JOINT_LEFT_SHOULDER_FB",
    "XR_BODY_JOINT_LEFT_SCAPULA_FB",
    "XR_BODY_JOINT_LEFT_ARM_UPPER_FB",
    "XR_BODY_JOINT_LEFT_ARM_LOWER_FB",
    "XR_BODY_JOINT_LEFT_HAND_WRIST_TWIST_FB",
    "XR_BODY_JOINT_RIGHT_SHOULDER_FB",
    "XR_BODY_JOINT_RIGHT_SCAPULA_FB",
    "XR_BODY_JOINT_RIGHT_ARM_UPPER_FB",
    "XR_BODY_JOINT_RIGHT_ARM_LOWER_FB",
    "XR_BODY_JOINT_RIGHT_HAND_WRIST_TWIST_FB",
    "XR_BODY_JOINT_LEFT_HAND_PALM_FB",
    "XR_BODY_JOINT_LEFT_HAND_WRIST_FB",
    "XR_BODY_JOINT_LEFT_HAND_THUMB_METACARPAL_FB",
    "XR_BODY_JOINT_LEFT_HAND_THUMB_PROXIMAL_FB",
    "XR_BODY_JOINT_LEFT_HAND_THUMB_DISTAL_FB",
    "XR_BODY_JOINT_LEFT_HAND_THUMB_TIP_FB",
    "XR_BODY_JOINT_LEFT_HAND_INDEX_METACARPAL_FB",
    "XR_BODY_JOINT_LEFT_HAND_INDEX_PROXIMAL_FB",
    "XR_BODY_JOINT_LEFT_HAND_INDEX_INTERMEDIATE_FB",
    "XR_BODY_JOINT_LEFT_HAND_INDEX_DISTAL_FB",
    "XR_BODY_JOINT_LEFT_HAND_INDEX_TIP_FB",
    "XR_BODY_JOINT_LEFT_HAND_MIDDLE_METACARPAL_FB",
    "XR_BODY_JOINT_LEFT_HAND_MIDDLE_PROXIMAL_FB",
    "XR_BODY_JOINT_LEFT_HAND_MIDDLE_INTERMEDIATE_FB",
    "XR_BODY_JOINT_LEFT_HAND_MIDDLE_DISTAL_FB",
    "XR_BODY_JOINT_LEFT_HAND_MIDDLE_TIP_FB",
    "XR_BODY_JOINT_LEFT_HAND_RING_METACARPAL_FB",
    "XR_BODY_JOINT_LEFT_HAND_RING_PROXIMAL_FB",
    "XR_BODY_JOINT_LEFT_HAND_RING_INTERMEDIATE_FB",
    "XR_BODY_JOINT_LEFT_HAND_RING_DISTAL_FB",
    "XR_BODY_JOINT_LEFT_HAND_RING_TIP_FB",
    "XR_BODY_JOINT_LEFT_HAND_LITTLE_METACARPAL_FB",
    "XR_BODY_JOINT_LEFT_HAND_LITTLE_PROXIMAL_FB",
    "XR_BODY_JOINT_LEFT_HAND_LITTLE_INTERMEDIATE_FB",
    "XR_BODY_JOINT_LEFT_HAND_LITTLE_DISTAL_FB",
    "XR_BODY_JOINT_LEFT_HAND_LITTLE_TIP_FB",
    "XR_BODY_JOINT_RIGHT_HAND_PALM_FB",
    "XR_BODY_JOINT_RIGHT_HAND_WRIST_FB",
    "XR_BODY_JOINT_RIGHT_HAND_THUMB_METACARPAL_FB",
    "XR_BODY_JOINT_RIGHT_HAND_THUMB_PROXIMAL_FB",
    "XR_BODY_JOINT_RIGHT_HAND_THUMB_DISTAL_FB",
    "XR_BODY_JOINT_RIGHT_HAND_THUMB_TIP_FB",
    "XR_BODY_JOINT_RIGHT_HAND_INDEX_METACARPAL_FB",
    "XR_BODY_JOINT_RIGHT_HAND_INDEX_PROXIMAL_FB",
    "XR_BODY_JOINT_RIGHT_HAND_INDEX_INTERMEDIATE_FB",
    "XR_BODY_JOINT_RIGHT_HAND_INDEX_DISTAL_FB",
    "XR_BODY_JOINT_RIGHT_HAND_INDEX_TIP_FB",
    "XR_BODY_JOINT_RIGHT_HAND_MIDDLE_METACARPAL_FB",
    "XR_BODY_JOINT_RIGHT_HAND_MIDDLE_PROXIMAL_FB",
    "XR_BODY_JOINT_RIGHT_HAND_MIDDLE_INTERMEDIATE_FB",
    "XR_BODY_JOINT_RIGHT_HAND_MIDDLE_DISTAL_FB",
    "XR_BODY_JOINT_RIGHT_HAND_MIDDLE_TIP_FB",
    "XR_BODY_JOINT_RIGHT_HAND_RING_METACARPAL_FB",
    "XR_BODY_JOINT_RIGHT_HAND_RING_PROXIMAL_FB",
    "XR_BODY_JOINT_RIGHT_HAND_RING_INTERMEDIATE_FB",
    "XR_BODY_JOINT_RIGHT_HAND_RING_DISTAL_FB",
    "XR_BODY_JOINT_RIGHT_HAND_RING_TIP_FB",
    "XR_BODY_JOINT_RIGHT_HAND_LITTLE_METACARPAL_FB",
    "XR_BODY_JOINT_RIGHT_HAND_LITTLE_PROXIMAL_FB",
    "XR_BODY_JOINT_RIGHT_HAND_LITTLE_INTERMEDIATE_FB",
    "XR_BODY_JOINT_RIGHT_HAND_LITTLE_DISTAL_FB",
    "XR_BODY_JOINT_RIGHT_HAND_LITTLE_TIP_FB"
};

OpenXRFBBodyTrackingJointState::OpenXRFBBodyTrackingJointState() {
    _post_initialize(this);
}

void OpenXRFBBodyTrackingJointState::_bind_methods() {
    ClassDB::bind_method(D_METHOD("get_location_tracked"), &OpenXRFBBodyTrackingJointState::get_location_tracked);
    ClassDB::bind_method(D_METHOD("get_location_valid"), &OpenXRFBBodyTrackingJointState::get_location_valid);
    ClassDB::bind_method(D_METHOD("get_location"), &OpenXRFBBodyTrackingJointState::get_location);
    ClassDB::bind_method(D_METHOD("get_orientation_tracked"), &OpenXRFBBodyTrackingJointState::get_orientation_tracked);
    ClassDB::bind_method(D_METHOD("get_orientation_valid"), &OpenXRFBBodyTrackingJointState::get_orientation_valid);
    ClassDB::bind_method(D_METHOD("get_orientation"), &OpenXRFBBodyTrackingJointState::get_orientation);
    ClassDB::bind_method(D_METHOD("get_joint_name"), &OpenXRFBBodyTrackingJointState::get_joint_name);
}

OpenXRFBBodyTrackingState::OpenXRFBBodyTrackingState() {
    _post_initialize(this);
    for (int i = 0; i < XR_BODY_JOINT_COUNT_FB; i++) {
        joints[i].joint_name = String(joint_names[i]);
    }

}

// TODO: Cache return value.
TypedArray<OpenXRFBBodyTrackingJointState> OpenXRFBBodyTrackingState::get_joints() {
    TypedArray<OpenXRFBBodyTrackingJointState> ret;
    ret.resize(XR_BODY_JOINT_COUNT_FB);

    for (int i = 0; i < XR_BODY_JOINT_COUNT_FB; i++) {
        ret[i] = &joints[i];
    }

    return ret;
}

void OpenXRFBBodyTrackingState::_bind_methods() {
    ClassDB::bind_method(D_METHOD("is_active"), &OpenXRFBBodyTrackingState::is_active);
    ClassDB::bind_method(D_METHOD("get_confidence"), &OpenXRFBBodyTrackingState::get_confidence);
    ClassDB::bind_method(D_METHOD("get_joints"), &OpenXRFBBodyTrackingState::get_joints);
}

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
        internal_state.is_initialized = false;
        internal_state.body_tracker_handle = XR_NULL_HANDLE;
        memset(&internal_state.joint_locations, 0, sizeof(XrBodyJointLocationFB) * XR_BODY_JOINT_COUNT_FB);
        memset(&internal_state.locations, 0, sizeof(XrBodyJointLocationsFB));
    }
}

void OpenXRFBBodyTrackingExtensionWrapper::_on_process() {
    uint64_t xr_time = get_openxr_api()->get_next_frame_time();
    uint64_t xr_play_space = get_openxr_api()->get_play_space();

    //Create the handle
    if(!internal_state.is_initialized) {
        XrBodyTrackerCreateInfoFB p_createInfo;
            p_createInfo.type = XR_TYPE_BODY_TRACKER_CREATE_INFO_FB;
            p_createInfo.next = nullptr;
            p_createInfo.bodyJointSet = XR_BODY_JOINT_SET_DEFAULT_FB;

        XrResult result = xrCreateBodyTrackerFB( (XrSession) get_openxr_api()->get_session(), &p_createInfo, &internal_state.body_tracker_handle );

        if (result == XR_SUCCESS) {
            internal_state.is_initialized = true;
            internal_state.locations.jointLocations = internal_state.joint_locations;
            internal_state.locations.next = nullptr;
            internal_state.locations.type = XR_TYPE_BODY_JOINT_LOCATIONS_FB;
            internal_state.locations.jointCount = XR_BODY_JOINT_COUNT_FB;
        }
    }

    if(internal_state.is_initialized) {
        XrBodyJointsLocateInfoFB p_locateInfo;
            p_locateInfo.type = XR_TYPE_BODY_JOINTS_LOCATE_INFO_FB;
            p_locateInfo.next = nullptr;
            p_locateInfo.baseSpace = (XrSpace)xr_play_space;
            p_locateInfo.time = xr_time;

        XrResult result = xrLocateBodyJointsFB(internal_state.body_tracker_handle, &p_locateInfo, &internal_state.locations);
        
        if( result == XR_SUCCESS) {
            body_tracking_state.active = internal_state.locations.isActive;
            body_tracking_state.confidence = internal_state.locations.confidence;

            for(int i = 0; i < XR_BODY_JOINT_COUNT_FB; i++) {
                body_tracking_state.joints[i].location_tracked = internal_state.joint_locations[i].locationFlags & XR_SPACE_LOCATION_POSITION_TRACKED_BIT;
                body_tracking_state.joints[i].location_valid = internal_state.joint_locations[i].locationFlags & XR_SPACE_LOCATION_ORIENTATION_VALID_BIT;
                body_tracking_state.joints[i].location = Vector3(internal_state.joint_locations[i].pose.position.x, internal_state.joint_locations[i].pose.position.y, internal_state.joint_locations[i].pose.position.z);

                body_tracking_state.joints[i].orientation_tracked = internal_state.joint_locations[i].locationFlags & XR_SPACE_LOCATION_ORIENTATION_TRACKED_BIT;
                body_tracking_state.joints[i].orientation_valid = internal_state.joint_locations[i].locationFlags & XR_SPACE_LOCATION_ORIENTATION_VALID_BIT;
                body_tracking_state.joints[i].orientation = Quaternion(internal_state.joint_locations[i].pose.orientation.x, internal_state.joint_locations[i].pose.orientation.y, internal_state.joint_locations[i].pose.orientation.z, internal_state.joint_locations[i].pose.orientation.w);
            }   
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
    ClassDB::bind_method(D_METHOD("get_body_tracking_state"), &OpenXRFBBodyTrackingExtensionWrapper::get_body_tracking_state);
}

OpenXRFBBodyTrackingState *OpenXRFBBodyTrackingExtensionWrapper::get_body_tracking_state() {
    return &body_tracking_state;
}
