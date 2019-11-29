#ifndef STARDUSTOPENXRGRAPHICS_H
#define STARDUSTOPENXRGRAPHICS_H

#include <QSize>
#include <QThread>
#include <QVector3D>
#include <QQuaternion>
#include <QMetaObject>
#include <QQuickItem>
#include <QQuickWindow>
#include <QQuickRenderControl>
#include <QOpenGLContext>
#include <QOpenGLFramebufferObject>
#include <QOffscreenSurface>

#include <QQmlEngine>
#include <QQmlComponent>


#include "stardustopenxr.h"

namespace Stardust {

class OpenXRFrame;

class OpenXRGraphics : public QObject {
    Q_OBJECT

    Q_PROPERTY(OpenXR *openxr MEMBER openxr)

    Q_PROPERTY(QObject *leftEye MEMBER leftEye)
    Q_PROPERTY(QObject *rightEye MEMBER rightEye)

    Q_PROPERTY(QSize leftViewSize MEMBER leftViewSize NOTIFY leftEyeSizeChanged)
    Q_PROPERTY(QSize rightViewSize MEMBER rightViewSize NOTIFY rightEyeSizeChanged)

    Q_PROPERTY(QQuickWindow *window READ getWindow NOTIFY windowChanged)
public:
    explicit OpenXRGraphics(QObject *parent = nullptr);
    ~OpenXRGraphics();

    OpenXR *openxr = nullptr;
    Q_INVOKABLE void preInitialize();
    Q_INVOKABLE void initialize();

    uint displayFPS = 0;

    XrViewConfigurationProperties viewProperties{XR_TYPE_VIEW_CONFIGURATION_PROPERTIES};
    XrViewConfigurationView eyeData[2];

    XrSwapchainCreateInfo swapInfo = {
        XR_TYPE_SWAPCHAIN_CREATE_INFO,                                                      //XrStructureType           type;
        nullptr,                                                                            //const void*               next;
        0,                                                                                  //XrSwapchainCreateFlags    createFlags;
        XR_SWAPCHAIN_USAGE_COLOR_ATTACHMENT_BIT | XR_SWAPCHAIN_USAGE_TRANSFER_DST_BIT,      //XrSwapchainUsageFlags     usageFlags;
        VK_FORMAT_R8G8B8A8_UNORM,                                                           //int64_t                   format;
        1,                                                                                  //uint32_t                  sampleCount;
        1,                                                                                  //uint32_t                  width;
        1,                                                                                  //uint32_t                  height;
        1,                                                                                  //uint32_t                  faceCount;
        1,                                                                                  //uint32_t                  arraySize;
        1                                                                                   //uint32_t                  mipCount;
    };
    XrSwapchain swapchains[2];

    uint32_t swapchainImageCount = 0;
    XrSwapchainImageVulkanKHR swapchainImageTemplate = {
        XR_TYPE_SWAPCHAIN_IMAGE_VULKAN_KHR,
        nullptr,
        VkImage()
    };
    std::vector<XrSwapchainImageVulkanKHR> swapchainImages[2];
    uint32_t swapchainImageIndices[2];

    XrReferenceSpaceCreateInfo refSpaceInfo = {
        XR_TYPE_REFERENCE_SPACE_CREATE_INFO,
        nullptr,
        XR_REFERENCE_SPACE_TYPE_STAGE,
        XrPosef {
            XrQuaternionf {0.0f,0.0f,1.0f,0.0f},
            XrVector3f {0.0f,0.0f,0.0f}
        }
    };
    XrSpace refSpace = XR_NULL_HANDLE;

    XrViewLocateInfo viewLocateInfo = {
        XR_TYPE_VIEW_LOCATE_INFO,
        nullptr
    };
    XrViewState viewState = {
        XR_TYPE_VIEW_STATE,
        nullptr
    };

    QRect eyeRects[2];

    XrCompositionLayerProjectionView stardustLayerViews[2] = {
        XrCompositionLayerProjectionView {
            XR_TYPE_COMPOSITION_LAYER_PROJECTION_VIEW,
            nullptr
        },
        XrCompositionLayerProjectionView {
            XR_TYPE_COMPOSITION_LAYER_PROJECTION_VIEW,
            nullptr
        }
    };

    QOpenGLFramebufferObject *fbo;

    QThread *frameThread = nullptr;
    OpenXRFrame *frame = nullptr;

    std::vector<XrView> views;

    QObject *leftEye;
    QObject *rightEye;

    QSize leftViewSize;
    QSize rightViewSize;

    QSize totalSize;

    QOpenGLContext *glContext;
    QOffscreenSurface *surface;
    QQuickWindow *window;
    QQuickItem *rootObject;
    QQuickRenderControl *quickRenderer;
    QOpenGLFramebufferObject *glFBO;

    QQmlEngine *qmlEngine;
    QQmlComponent *qmlComponent;

    std::vector<VkImage> vulkanImages[2];

    XrFrameWaitInfo frameWaitInfo{XR_TYPE_FRAME_WAIT_INFO};
    XrFrameState frameState{XR_TYPE_FRAME_STATE};

    QQuickWindow *getWindow() const;

    QSize getLeftViewSize() const;
    QSize getRightViewSize() const;

signals:
    void leftEyeSizeChanged();
    void rightEyeSizeChanged();

    void windowChanged();
    void startFrameLoop();
};

}

#endif // STARDUSTOPENXRGRAPHICS_H
