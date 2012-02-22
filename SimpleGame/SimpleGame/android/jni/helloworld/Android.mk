LOCAL_PATH := $(call my-dir)
include $(CLEAR_VARS)
LOCAL_MODULE := game_static
LOCAL_MODULE_FILENAME := libgame

LOCAL_SRC_FILES := main.cpp

LOCAL_C_INCLUDES := $(LOCAL_PATH)/../../../libs/cocos2dx \
                    $(LOCAL_PATH)/../../../libs/cocos2dx/platform \
                    $(LOCAL_PATH)/../../../libs/cocos2dx/include \
                    $(LOCAL_PATH)/../../../Classes

LOCAL_LDLIBS := -L$(call host-path, $(LOCAL_PATH)/../../libs/$(TARGET_ARCH_ABI)) \
                -lcocos2d -llog -lgame_logic


LOCAL_STATIC_LIBRARIES := png_static_prebuilt
LOCAL_STATIC_LIBRARIES += xml2_static_prebuilt
LOCAL_STATIC_LIBRARIES += jpeg_static_prebuilt

# define the macro to compile through support/zip_support/ioapi.c                
LOCAL_CFLAGS := -DUSE_FILE32API -DGL_GLEXT_PROTOTYPES=1

include $(BUILD_SHARED_LIBRARY)

$(call import-add-path,$(LOCAL_PATH)/..)
$(call import-module,cocos2dx/platform/third_party/android/modules/libpng)
$(call import-module,cocos2dx/platform/third_party/android/modules/libxml2)
$(call import-module,cocos2dx/platform/third_party/android/modules/libjpeg)

