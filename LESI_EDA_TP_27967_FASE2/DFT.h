#pragma once

#include"Global.h"

int GetClosestVerticeAdjUnvisited(GR* graph, int v);

bool DepthFirstTraversal(GR* graph, int origin);

bool DepthFirstSearch(GR* graph, int origin, int destiny);

void ResetVisitedNodes(GR* graph);

int CountPaths(GR* graph, int origin, int destiny, int pathCount);