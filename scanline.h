#ifndef SCANLINE_H
#define SCANLINE_H

#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include "point.h"
#include "point2.h"
#include "framebuffer.h"
#include "color32.h"
#include "line.h"

using namespace std;

// typedef struct {
//   Point plow; // plow adalah point dengan y minimum
//   Point phigh; // plow adalah point dengan y maximum
//   int dx;
//   int dy;
//   int sx;
//   int sy;
//   int err;
//   int e2;
//   Point curpoint;
// } Line;

void produceLines(Polygon2 &polygon);
int isIntersect(Line, int);
void sortTipot(vector<Point> &tipot);
void fill(vector<Line> &vl, int ymax, int ymin, Color32 color);

#endif
