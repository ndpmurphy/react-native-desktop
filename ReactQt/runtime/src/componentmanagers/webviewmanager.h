
/**
 * Copyright (c) 2017-present, Status Research and Development GmbH.
 * All rights reserved.
 *
 * This source code is licensed under the BSD-style license found in the
 * LICENSE file in the root directory of this source tree. An additional grant
 * of patent rights can be found in the PATENTS file in the same directory.
 *
 */

#ifndef WEBVIEWMANAGER_H
#define WEBVIEWMANAGER_H

#include "viewmanager.h"

class PropertyHandler;
class WebViewManagerPrivate;
class WebViewManager : public ViewManager {
    Q_OBJECT
    Q_INTERFACES(ModuleInterface)
    Q_DECLARE_PRIVATE(WebViewManager)

public:
    WebViewManager(QObject* parent = 0);
    virtual ~WebViewManager();

    virtual ViewManager* viewManager() override;
    virtual QString moduleName() override;
    virtual bool shouldLayout() const override;

    Q_INVOKABLE void reload();
    Q_INVOKABLE void goBack();
    Q_INVOKABLE void goForward();

Q_SIGNALS:
    void s_reload();
    void s_goBack();
    void s_goForward();

private:
    virtual QString qmlComponentFile() const override;
    virtual void configureView(QQuickItem* view) const override;

private:
    QScopedPointer<WebViewManagerPrivate> d_ptr;
};

#endif // WEBVIEWMANAGER_H
