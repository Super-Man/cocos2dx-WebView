//
// Created by gin0606 on 2014/07/29.
//

#ifndef __Cocos2d_Plugin_WebView_H_
#define __Cocos2d_Plugin_WebView_H_

#include "ui/UIWidget.h"

namespace cocos2d {
namespace plugin {
class WebViewImpl;

class WebView : public cocos2d::ui::Widget {
public:
    static WebView *create();

    WebView();
    virtual ~WebView();

    std::function<void(WebView *sender, std::string message)> onJsCallback;
    std::function<bool(WebView *sender, std::string url)> shouldStartLoading;
    std::function<void(WebView *sender, std::string url)> didFinishLoading;
    std::function<void(WebView *sender, std::string url)> didFailLoading;

    void loadUrl(const std::string &url);
    void loadFile(const std::string &fileName);

    void evaluateJS(const std::string &js);

    virtual void draw(cocos2d::Renderer *renderer, cocos2d::Mat4 const &transform, uint32_t flags) override;

    virtual void setVisible(bool visible) override;

private:
    cocos2d::plugin::WebViewImpl *impl;
};
} // namespace cocos2d
} // namespace plugin

#endif //__Cocos2d_Plugin_WebView_H_