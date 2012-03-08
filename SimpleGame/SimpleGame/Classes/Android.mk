LOCAL_PATH := $(call my-dir)
include $(CLEAR_VARS)
LOCAL_MODULE := game_logic_static

LOCAL_SRC_FILES := AppDelegate.cpp \
                   HelloWorldScene.cpp \
                   GameOverScene.cpp

LOCAL_C_INCLUDES := $(LOCAL_PATH)/../libs/cocos2dx \
                    $(LOCAL_PATH)/../libs/cocos2dx/platform \
                    $(LOCAL_PATH)/../libs/cocos2dx/include \
                    $(LOCAL_PATH)/../libs/CocosDenshion/include \

LOCAL_STATIC_LIBRARIES := png_static_prebuilt
LOCAL_STATIC_LIBRARIES += xml2_static_prebuilt
LOCAL_STATIC_LIBRARIES += jpeg_static_prebuilt
LOCAL_WHOLE_STATIC_LIBRARIES += cocos2dx_static
                
LOCAL_SHARED_LIBRARIES := cocosdenshion_shared
            
include $(BUILD_STATIC_LIBRARY)

$(call import-module,cocos2dx/platform/third_party/android/modules/libpng)
$(call import-module,cocos2dx/platform/third_party/android/modules/libxml2)
$(call import-module,cocos2dx/platform/third_party/android/modules/libjpeg)