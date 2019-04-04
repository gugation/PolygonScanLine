#ifndef POLYGONDRAWER_H
#define POLYGONDRAWER_H

class CanvasOpenGL;
#include <vector>
#include "drawer.h"
#include "qcolor.h"
#include "qpoint.h"
#include "qpainter.h"

class PolygonDrawer : public Drawer
{
public:
    PolygonDrawer();
    virtual ~PolygonDrawer();
    void Draw(CanvasOpenGL* canvas, std::vector<QPoint>& vertices, QColor pointsColor);

private:
    void midPointMethod(std::vector<QPoint>& vertices, QPainter& painter);
};

#endif // POLYGONDRAWER_H
