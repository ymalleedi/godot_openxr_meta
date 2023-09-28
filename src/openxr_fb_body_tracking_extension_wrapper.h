#ifndef OPENXR_FB_BODY_TRACKING_EXTENSION_WRAPPER_H
#define OPENXR_FB_BODY_TRACKING_EXTENSION_WRAPPER_H

#include <map>
#include <openxr/openxr.h>
#include <openxr/fb_body_tracking.h>
#include <godot_cpp/classes/open_xr_extension_wrapper_extension.hpp>
#include <godot_cpp/variant/utility_functions.hpp>
#include <godot_cpp/core/binder_common.hpp>

#include "util.h"

using namespace godot;

class OpenXRFBBodyTrackingJointState : public Object {

    friend class OpenXRFBBodyTrackingExtensionWrapper;
    friend class OpenXRFBBodyTrackingState;

    GDCLASS(OpenXRFBBodyTrackingJointState, Object)

    private:
        // By making constructor inaccessible, this type can not be instantiated via GdScript
        OpenXRFBBodyTrackingJointState();
        bool location_tracked;
        bool location_valid;
        Vector3 location;
        bool orientation_tracked;
        bool orientation_valid;
        Quaternion orientation;
        String joint_name;

    protected:
        static void _bind_methods();

    public:

        bool get_location_tracked() { return location_tracked; }
        bool get_location_valid() { return location_valid; }
        Vector3 get_location() { return location; }

        bool get_orientation_tracked() { return orientation_tracked; }
        bool get_orientation_valid() { return orientation_valid; }
        Quaternion get_orientation() { return orientation; }

        String get_joint_name() { return joint_name; }

};

class OpenXRFBBodyTrackingState : public Object {

    friend class OpenXRFBBodyTrackingExtensionWrapper;

    GDCLASS(OpenXRFBBodyTrackingState, Object)

    private:
        // By making constructor inaccessible, this type can not be instantiated via GdScript
        OpenXRFBBodyTrackingState();
        bool active;
        float confidence;
        OpenXRFBBodyTrackingJointState joints[XR_BODY_JOINT_COUNT_FB] = {};

    protected:
        static void _bind_methods();

    public:
        bool is_active() { return active; }
        float get_confidence() { return confidence; }
        TypedArray<OpenXRFBBodyTrackingJointState> get_joints();
};

class OpenXRFBBodyTrackingExtensionWrapper : public OpenXRExtensionWrapperExtension {
    
    GDCLASS(OpenXRFBBodyTrackingExtensionWrapper, OpenXRExtensionWrapperExtension)

    private:
        bool fb_body_tracking_ext = false;
        //TODO: check if godot hash_map could be used.
        std::map<godot::String, bool *> request_extensions;
        static OpenXRFBBodyTrackingExtensionWrapper *singleton;

        EXT_PROTO_XRRESULT_FUNC3(xrCreateBodyTrackerFB, (XrSession), p_session, (const XrBodyTrackerCreateInfoFB *), p_createInfo, (XrBodyTrackerFB *), p_bodyTracker);
        EXT_PROTO_XRRESULT_FUNC1(xrDestroyBodyTrackerFB, (XrBodyTrackerFB), p_bodyTracker);
        EXT_PROTO_XRRESULT_FUNC3(xrLocateBodyJointsFB, (XrBodyTrackerFB), p_bodyTracker, (const XrBodyJointsLocateInfoFB *), p_locateInfo, (XrBodyJointLocationsFB *), p_locations);

        struct Body_Tracker {
            bool is_initialized = false;
            XrBodyTrackerFB body_tracker_handle = XR_NULL_HANDLE; 
            XrBodyJointLocationFB joint_locations[XR_BODY_JOINT_COUNT_FB];
            XrBodyJointLocationsFB locations;
        };
        Body_Tracker internal_state;
        OpenXRFBBodyTrackingState body_tracking_state;

    protected:
        static void _bind_methods();

    public:
        OpenXRFBBodyTrackingExtensionWrapper();

        static OpenXRFBBodyTrackingExtensionWrapper* get_singleton();

        void _on_instance_created(uint64_t instance) override;

        void _on_instance_destroyed() override;

        void _on_state_ready() override;

        void _on_process() override;

        godot::Dictionary _get_requested_extensions() override;

        OpenXRFBBodyTrackingState *get_body_tracking_state(); //TODO: determine whats needed for returning pointer.

        bool is_body_tracking_supported() {
            return fb_body_tracking_ext;
        }

};

#endif //OPENXR_FB_BODY_TRACKING_EXTENSION_WRAPPER_H