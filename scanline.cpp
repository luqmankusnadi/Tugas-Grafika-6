#include "scanline.h"

void produceLines(Polygon2 &polygon) {
  int i;
  vector<Line> vl;
  int ymin_global = 2000;
  int ymax_global = -1;
  
  vector<Point2> points = polygon.vertices;
  for (i = 0; i < points.size(); i++) {
    if (points[i].y > points[(i+1)%points.size()].y) {
      Line line;
      line.phigh.y = (int)points[i].y;
      line.phigh.x = (int)points[i].x;
      line.plow.y = (int)points[(i+1)%points.size()].y;
      line.plow.x = (int)points[(i+1)%points.size()].x;
      vl.push_back(line);
    }
    else if (points[i].y < points[(i+1)%points.size()].y) {
      Line line;
      line.plow.y = (int)points[i].y;
      line.plow.x = (int)points[i].x;
      line.phigh.y = (int)points[(i+1)%points.size()].y;
      line.phigh.x = (int)points[(i+1)%points.size()].x;
      vl.push_back(line);
    }
    if ((int)points[i].y > ymax_global) 
      ymax_global = (int)points[i].y;
    if ((int)points[i].y < ymin_global)
      ymin_global = (int)points[i].y;
  }
  polygon.ymin = ymin_global;
  polygon.ymax = ymax_global;
  polygon.lines = vl;
}


int isIntersect(Line line, int y) {
  if (y == line.plow.y) {
    return 2;
  }
  else if (((y > line.plow.y) && (y < line.phigh.y)) || (y == line.phigh.y)) {
    return 1;
  }
  else 
    return 0;
}

void sortTipot(vector<Point> &tipot) {
	int i, j;
	Point temp;
	for (i = 1; i < tipot.size(); i++) {
		for (j = 0; j < tipot.size() -1; j++) {
			if (tipot[j].x > tipot[j+1].x) {
				temp = tipot[j];
				tipot[j] = tipot[j+1];
				tipot[j+1] = temp;
			}
		}
	}
}

void fill(vector<Line> &vl, int ymax, int ymin, Color32 color) {
  int y, i, x, j;
  vector<Point> tipot;
  for (y = ymin; y <= ymax; y++) {
  	tipot.clear();
    for (j = 0; j < vl.size(); j++) {
      if (isIntersect(vl[j], y) == 2) {
      	vl[j].dx = abs(vl[j].phigh.x-vl[j].plow.x);
      	vl[j].dy = abs(vl[j].phigh.y-vl[j].plow.y);
      	vl[j].sx = vl[j].plow.x < vl[j].phigh.x ? 1 : -1;
      	vl[j].sy = vl[j].plow.y < vl[j].phigh.y ? 1 : -1;
      	vl[j].err = (vl[j].dx > vl[j].dy ? vl[j].dx : -1 * vl[j].dy)/2;
      	vl[j].curpoint = vl[j].plow;

      	tipot.push_back(vl[j].plow);
      }
      else if (isIntersect(vl[j], y) == 1) {
      	vl[j].e2 = vl[j].err;
      	if (vl[j].e2 > -1*vl[j].dx) { vl[j].err -= vl[j].dy; vl[j].curpoint.x += vl[j].sx; }
      	if (vl[j].e2 < vl[j].dy) { vl[j].err += vl[j].dx; vl[j].curpoint.y += vl[j].sy; }

      	tipot.push_back(vl[j].curpoint);
      }
    }
    sortTipot(tipot);
    for (i = 0; i < tipot.size()-1; i += 2) {
    	for (x = tipot[i].x; x <= tipot[i+1].x; x++) {
    		SetPixel(x, y, color);
    	}
    }
  }
}
