#ifndef APPCONTROLLER_H
#define APPCONTROLLER_H

#include "mainwindow.h"
#include "vertexholderdrawer.h"

class AppController : public QObject {
    Q_OBJECT
private:
    enum eAppState {
        DRAWING,
        WAITING,
        EDITING,
    };

    eAppState state = eAppState::WAITING;

    MainWindow* window;

    // UI
    HintBoxDrawer* hintBox;

    // EDIT MODE
    MouseFollower* mouseFollower;

    // POLYGON DATA
    PolygonDrawer* polygonDrawer;
    std::vector<VertexHolderDrawer*> holders;
    std::vector<QPoint*> vertices;

public:
    AppController(MainWindow*);
    ~AppController();

private:
    QPoint* createNewPoint(QPoint);
    void clearAllData();
    void subscribeMouseActions();

    void beginDrawing();
    void beginWaiting();
    void beginEditing();

    void endDrawing();
    void endWaiting();
    void endEditing();

private slots:
    void onKeyReleased(int key);
    void onClearPressed();
};

#endif // APPCONTROLLER_H
