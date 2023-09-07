#ifndef OPENXR_FB_BODY_TRACKING_EXTENSION_WRAPPER_H
#define OPENXR_FB_BODY_TRACKING_EXTENSION_WRAPPER_H

#include <map>
#include <openxr/openxr.h>
#include <openxr/fb_body_tracking.h>
#include <godot_cpp/classes/open_xr_extension_wrapper_extension.hpp>
#include <godot_cpp/variant/utility_functions.hpp>

#include "util.h"


namespace godot {

    class OpenXRFBBodyTrackingExtensionWrapper : public OpenXRExtensionWrapperExtension {
        GDCLASS(OpenXRFBBodyTrackingExtensionWrapper, OpenXRExtensionWrapperExtension)

        private:
            bool fb_body_tracking_ext = false;
            //TODO: check if godot hash_map coudl be used.
            std::map<godot::String, bool *> request_extensions;
            static OpenXRFBBodyTrackingExtensionWrapper *singleton;

            EXT_PROTO_XRRESULT_FUNC3(xrCreateBodyTrackerFB, (XrSession), p_session, (const XrBodyTrackerCreateInfoFB *), p_createInfo, (XrBodyTrackerFB *), p_bodyTracker);
            EXT_PROTO_XRRESULT_FUNC1(xrDestroyBodyTrackerFB, (XRBodyTrackerFB), p_bodyTracker);

        protected:
            static void _bind_methods();

        public:

            struct Body_Tracker {
                bool is_initialized = false;
                XrBodyTrackerFB body_tracker = XR_NULL_HANDLE; // Body tracking handle
                XrBodyJointLocationFB jointLocations[XR_BODY_JOINT_COUNT_FB];
                XrBodyJointLocationsFB locations;
            }

            OpenXRFBBodyTrackingExtensionWrapper();

            static OpenXRFBBodyTrackingExtensionWrapper* get_singleton();

            void _on_instance_created(uint64_t instance) override;

            void _on_instance_destroyed() override;

            void _on_process() override;

            godot::Dictionary _get_requested_extensions() override;
            

            bool is_body_tracking_supported() {
                return fb_body_tracking_ext;
            }

    };

}

#endif